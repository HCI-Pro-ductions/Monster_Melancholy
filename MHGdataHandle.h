#include <mongoc/mongoc.h>
#include "sha256.h"
#include <random>
using namespace std;
ifstream dataget;//("MMGameFiles/MMGameData.txt")
ofstream datastore;//("MMGameFiles/MMGameData.txt")
int seed1, seed2;
long long DHdata[60]={0};
map <string,int> DHmap, DHIDmap;
map <string,int> ::iterator mapit;
map <int, string> DHItemID;
map <int, string> ::iterator mapit2;
string DHpetname="", DHcode="";
bool eventChristmas=false;
int repeat = 0;
namespace MHGdataHandle{
    string stringE(string toEncrypt) {
        return toEncrypt;
    }
    string stringD(string toDecrypt) {
        return toDecrypt;
    }


    int decrypt(int data, int DataID, bool checkSeedMismatch){
        return data;
    }

    int encrypt(int data){
        return data;
    }

    string getHashedPassword(const char *prompt){

        SHA256 sha256;
        const char BACKSPACE=8;
        const char RETURN=13;
        string password;
        unsigned char c=0;
        cout<<prompt;

        DWORD con_mode;
        DWORD dwRead;
        HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode( hIn, &con_mode );
        SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

        while(ReadConsoleA( hIn, &c, 1, &dwRead, NULL) && c !=RETURN){
            if(c==BACKSPACE){
                if(password.length()!=0){
                    cout <<"\b \b";
                    password.resize(password.length()-1);
                }
            }
            else{
                password+=c;
                cout <<'*';
            }
        }
        cout<<"\n";
        password = sha256(password);
        return password;
    }

    void static customError(int error){
        switch(error){
            case 4: cout << "Fatal Error! Unable to store data! Please report bug as 'Error4'." << "\n"; break;
        }
        system("color 0C");
        cout<<'\a';
        while(true){Sleep(1000);}
    }

    void static DHtextc(int x, HANDLE hConsole){
        SetConsoleTextAttribute(hConsole, x); // 1=white, 7=white, 8=grey, 9=dark blue, 10=light green, 11=aqua, 12=red, 13=magenta, 14=gold, 15=brightest white
    }

    bool encryptionNeeded(const char *val){
        if(( strcmp(val,"seed1") ) == 0) return false;
        if(( strcmp(val,"seed2") ) == 0) return false;
        if(( strcmp(val,"version") ) == 0) return false;
        if(( strcmp(val,"prevt") ) == 0) return false;
        if(( strcmp(val,"total") ) == 0) return false;
        else return true;
    }

    const char *uri_string ="";//key in your own uri string for mongodb
    mongoc_uri_t *uri;
    mongoc_client_t *client;
    mongoc_database_t *database;
    mongoc_collection_t *rawDataCollection, *verificationCollection, *leaderboardCollection, *redeemCollection, *eventCollection, *onlineCollection;
    bson_t *command, reply;
    bson_error_t error;
    char *str;
    mongoc_cursor_t *cursor;
    const bson_t *doc;
    bson_t *query, *opts;

    bool phraseURI(){
        uri = mongoc_uri_new_with_error(uri_string, &error);
        if (!uri) {
            fprintf(stderr,"failed to parse URI: %s\n""error message: %s\n",uri_string,error.message);
            return false;
        }
        return true;
    }

    bool createClient(){
        client = mongoc_client_new_from_uri(uri);
        if (!client) {
            fprintf(stderr,"failed to creat client: %s\n""error message: %s\n",uri_string,error.message);
            return false;
        }
        mongoc_client_set_appname(client, "connect-MHGClient");
        return true;
    }

    void static handleDatabase(){
        database = mongoc_client_get_database(client, "MHG");
        rawDataCollection = mongoc_client_get_collection(client, "MHG", "rawData");
        verificationCollection = mongoc_client_get_collection(client, "MHG", "verification");
        leaderboardCollection = mongoc_client_get_collection(client, "MHG", "leaderboard");
        redeemCollection = mongoc_client_get_collection(client, "MHG", "redeem");
        eventCollection = mongoc_client_get_collection(client, "MHG", "event");
        onlineCollection = mongoc_client_get_collection(client, "MHG", "online");
    }

    bool pingDatabase(){
        bool retval;
        command = BCON_NEW ("ping", BCON_INT32(1));
        retval = mongoc_client_command_simple(client, "admin", command, NULL, &reply, &error);
        if (!retval){
            fprintf(stderr, "%s\n", error.message);
            return false;
        }
        str = bson_as_json(&reply, NULL);
        cout<<"Server Connection: "<<str<<"\n";
        return true;
    }

    bool scanForUser(const char *name){
        bson_iter_t iter, val;
        query = bson_new();
        opts = bson_new();
        cursor = mongoc_collection_find_with_opts(verificationCollection, query, NULL, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){

            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val) ){
                if( strcmp(name, stringD(bson_iter_utf8(&val, nullptr) ).c_str() ) == 0 ) return true;
            }
        }
        return false;
    }
    void static addNewUser(string name, const char *hashPass){
        bson_t *insert = bson_new();
        BSON_APPEND_UTF8(insert, "username", stringE(name).c_str() );
        BSON_APPEND_UTF8(insert, "password", hashPass);
        if (!mongoc_collection_insert_one(verificationCollection, insert, NULL, NULL, &error))
            fprintf(stderr, "%s\n", error.message);

    }

    bool verifyUser(const char *name, const char *hashPass){
        bson_iter_t iter, val;
        query = bson_new();
        cursor = mongoc_collection_find_with_opts(verificationCollection, query, NULL, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){

            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val) ){
                if( strcmp(name, stringD(bson_iter_utf8(&val, nullptr) ).c_str() ) == 0 ) {
                    bson_iter_find_descendant(&iter, "password", &val);
                    if (strcmp(hashPass, bson_iter_utf8(&val, nullptr)) == 0) return true;
                }
            }
        }
        return false;
    }

    void static addToDatabase(const char *petname, const char *username){
        int x;
        const char *y;
        bson_t *insert = bson_new();
        for(mapit = DHmap.begin(); mapit != DHmap.end(); mapit++){
            x = mapit->second;
            y = mapit->first.c_str();
            if( encryptionNeeded(y) ) x = encrypt(x);
            BSON_APPEND_INT64(insert, y, x);
        }
        BSON_APPEND_UTF8(insert, "username", username);
        BSON_APPEND_UTF8(insert, "petname", petname);
        if (!mongoc_collection_insert_one(rawDataCollection, insert, NULL, NULL, &error)){
            fprintf(stderr, "%s\n", error.message);
        }
    }

    void static updateDatabase(const char *petname, const char *username){
        int x;
        const char *y;
        bson_t *insert = bson_new();
        bson_t child;
        BSON_APPEND_DOCUMENT_BEGIN (insert, "$set", &child);
        for(mapit = DHmap.begin(); mapit != DHmap.end(); mapit++){
            x = mapit->second;
            y = mapit->first.c_str();
            if( encryptionNeeded(y) ) x = encrypt(x);
            BSON_APPEND_INT64(&child, y, x);
        }
        BSON_APPEND_UTF8(&child, "username", username);
        BSON_APPEND_UTF8(&child, "petname", petname);
        bson_append_document_end (insert, &child);
        bson_iter_t iter, val;
        query = bson_new(); //empty query to query all data in collection
        cursor = mongoc_collection_find_with_opts(rawDataCollection, query, opts, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ) {
            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val)) {
                if (strcmp(username, bson_iter_utf8(&val, nullptr)) == 0) {//if username found
                    if (bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "_id", &val)) {
                        BSON_APPEND_OID(query, "_id", bson_iter_oid(&val));
                        if (!mongoc_collection_update_one(rawDataCollection, query, insert, NULL, NULL, &error))
                            fprintf(stderr, "%s\n", error.message);
                        return;
                    }
                }
            }
        }
        //if cannot find
        addToDatabase(petname, username);
    }

    void static readDatabase(const char *username){
        query = bson_new(); //empty query to query all data in collection
        cursor = mongoc_collection_find_with_opts(rawDataCollection, query, opts, NULL);
        bson_iter_t iter, val;
        mapit = DHmap.begin();
        while ( mongoc_cursor_next(cursor, &doc) ) {
            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val)) {
                if (strcmp(username, bson_iter_utf8(&val, nullptr)) == 0) {//if username found
                    bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "seed1", &val); seed1 = bson_iter_int64(&val);
                    bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "seed2", &val); seed2 = bson_iter_int64(&val);
                    for(mapit = DHmap.begin(); mapit!=DHmap.end(); mapit++){
                        bson_iter_init(&iter, doc);
                        bson_iter_find_descendant(&iter, mapit->first.c_str(), &val);
                        int x = bson_iter_int64(&val);
                        if ( encryptionNeeded(mapit->first.c_str()) ) DHmap[mapit->first] = decrypt( x, DHIDmap[mapit->first], false);
                        else DHmap[mapit->first] = x;
                    }
                }
            }
        }
        //for(mapit = DHmap.begin(); mapit!=DHmap.end(); mapit++) cout<<mapit->first<<":"<<mapit->second<<"\n";
    }

    void static updateLeaderboard(const char *name, int lvl){
        bson_t *update = bson_new(), *insert = bson_new();
        bson_iter_t iter, val;
        query = bson_new(); //empty query to query all data in collection
        cursor = mongoc_collection_find_with_opts(leaderboardCollection, query, opts, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){ //attempt to find existing document with player's username

            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val) ){
                if( strcmp(name , bson_iter_utf8(&val, nullptr) ) == 0 ) { //if username found
                    if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "_id", &val) ){
                        query = BCON_NEW ("_id", BCON_OID(bson_iter_oid(&val)) );
                        update = BCON_NEW ("$set","{", "username", BCON_UTF8(name), "lvl", BCON_INT64(lvl),"}");
                        if (!mongoc_collection_update_one (leaderboardCollection, query, update, NULL, NULL, &error))
                            fprintf (stderr, "%s\n", error.message);
                        return;
                    }
                }
            }
        }
        //if cannot find existing document with player's username
        BSON_APPEND_UTF8(insert, "username", name);
        BSON_APPEND_INT64(insert, "lvl", lvl);
        if (!mongoc_collection_insert_one(leaderboardCollection, insert, NULL, NULL, &error))
            fprintf(stderr, "%s\n", error.message);
    }

    multimap< int, string, greater<int> > loadLeaderboard(){
        string user;
        int level;
        multimap< int, string, greater<int> > lmap;
        bson_iter_t iter, val;
        query = bson_new();
        opts = bson_new();
        cursor = mongoc_collection_find_with_opts(leaderboardCollection, query, NULL, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){
            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val) ){
                user = bson_iter_utf8(&val,nullptr);
            }
            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "lvl", &val) ){
                level = bson_iter_int64(&val);
            }
            lmap.insert(pair<int, string>(level, user));
        }
        return lmap;
    }

    void static displayLeaderboard(multimap<int, string, greater<int> > mmap, string name, HANDLE hConsole){
        multimap< int, string, greater<int> > ::iterator it;
        int cnt=1;
        cout<<"[Leaderboard]"<<"\n";
        cout<<"   Username                Level"<<"\n";//16 spaces (username is len of 8, hence 24-8=16
        for(it=mmap.begin(); it!=mmap.end(); it++){
            if(cnt == 1) DHtextc(14, hConsole);//gold
            if(cnt == 2) DHtextc(15, hConsole);//bright white
            if(cnt == 3) DHtextc(2, hConsole);//dark green
            cout<<cnt<<". ";
            cout << it->second;
            for(int i=0; i<(24- it->second.size() ); i++) cout<<" ";
            cout<< it->first;
            if(strcmp(name.c_str(), it->second.c_str()) == 0) cout<<" (You)";
            cout<<"\n";
            SetConsoleTextAttribute(hConsole, 10);//green
            cnt++;
        }
    }

    struct redeem{
        bool valid = true;
        string type="";
        int amt = 0;
    };

    redeem static redeemCode(const char *code, const char *name, HWND hwnd){
        redeem rtn;
        string username="";
        mongoc_cursor_t *cursor2;
        bson_t *insert = bson_new(), *query2 = bson_new();
        const bson_t *doc2;
        bson_iter_t iter, iter2, child, val;
        query = bson_new(); //empty query to query all data in collection
        cursor = mongoc_collection_find_with_opts(redeemCollection, query, opts, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){

            bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "code", &val);
            if( strcmp( code, bson_iter_utf8(&val, nullptr) ) == 0 ){//if code is correct

                //read usernmae field into function varible; and type and amount field into redeem struct
                bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "username", &val);
                username +=  bson_iter_utf8(&val, nullptr);
                bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "type", &val);
                rtn.type +=  bson_iter_utf8(&val, nullptr);
                bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "amount", &val);
                rtn.amt =  bson_iter_int64(&val);
                bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "_id", &val);
                query2 = BCON_NEW ("_id", BCON_OID(bson_iter_oid(&val)) );

                bson_t *subdoc = bson_new();
                if (bson_iter_init_find (&iter2, doc, "redeemed") &&
                    BSON_ITER_HOLDS_DOCUMENT (&iter2) && bson_iter_recurse (&iter2, &child)) {
                    while (bson_iter_next (&child)) {
                        BSON_APPEND_UTF8(subdoc, bson_iter_key(&child), "redeemed");
                    }
                }

                bson_iter_init(&iter, doc);
                bson_iter_find_descendant(&iter, "username", &val);
                const char *x = bson_iter_utf8(&val, nullptr);
                if(strcmp( name, x ) == 0 || strcmp( "all", x) == 0){//check if username can redeem code
                    //check if username already redeemed before
                    string key = "redeemed.";
                    key += name;
                    if(bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, key.c_str(), &val) ){
                            rtn.valid = false;
                        DHtextc(12, hwnd); cout<<"You already redeemed this code before!\n"; DHtextc(10, hwnd);
                            return rtn;
                    }
                    //player can redeem code, so update the list of people who already redeemed
                    bson_t *childdoc = bson_new();
                    bson_t *insert2 = bson_new();
                    BSON_APPEND_UTF8(subdoc, name, "redeemed");
                    BSON_APPEND_DOCUMENT_BEGIN (insert2, "$set", childdoc);
                    BSON_APPEND_UTF8(childdoc, "code", code);
                    BSON_APPEND_UTF8(childdoc, "username", username.c_str());
                    BSON_APPEND_UTF8(childdoc, "type", (rtn.type).c_str());
                    BSON_APPEND_INT64(childdoc, "amount", rtn.amt);
                    BSON_APPEND_DOCUMENT(childdoc, "redeemed", subdoc);
                    bson_append_document_end (insert2, childdoc);

                    if (!mongoc_collection_update_one (redeemCollection, query2, insert2, NULL, NULL, &error))
                        fprintf (stderr, "%s\n", error.message);

                    return rtn;
                }
                else{ //if username cannot redeem (its not "all")
                    DHtextc(12, hwnd); cout<<"You cannot redeem this code (this code is not for you)\n"; DHtextc(10, hwnd);
                    rtn.valid = false;
                    return rtn;
                }
            }
            else{ //if not the code that is looking for
                continue;
            }

        }
        //if cannot find code
        DHtextc(12, hwnd); cout<<"No such code exists\n";  DHtextc(10, hwnd);
        rtn.valid=false;
        return rtn;
    }

    void static checkForEvents(){
        bson_iter_t iter, val;
        query = bson_new();
        opts = bson_new();
        cursor = mongoc_collection_find_with_opts(eventCollection, query, NULL, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){
            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "Christmas", &val) ){
                if( bson_iter_bool(&val) ) {
                    eventChristmas = true;
                }
            }
        }
    }

    void static displayOnlinePlayers(){
        bson_iter_t iter, val;
        query = bson_new();
        opts = bson_new();
        cursor = mongoc_collection_find_with_opts(onlineCollection, query, NULL, NULL);
        cout<<"[Online Players]\n";
        while ( mongoc_cursor_next(cursor, &doc) ){
            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "time", &val) ){
                 if( bson_iter_int64(&val)+300 >= time(nullptr)){//online player found
                     bson_iter_init(&iter, doc); bson_iter_find_descendant(&iter, "username", &val);
                     cout<<bson_iter_utf8(&val, nullptr)<<"\n";
                 }
            }
        }
        cout<<"\n";
    }

    void static updateOnlineStatus(const char *name){
        bson_t *update = bson_new(), *insert = bson_new();
        bson_iter_t iter, val;
        query = bson_new(); //empty query to query all data in collection
        cursor = mongoc_collection_find_with_opts(onlineCollection, query, opts, NULL);
        while ( mongoc_cursor_next(cursor, &doc) ){ //attempt to find existing document with player's username

            if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "username", &val) ){
                if( strcmp(name , bson_iter_utf8(&val, nullptr) ) == 0 ) { //if username found
                    if ( bson_iter_init(&iter, doc) && bson_iter_find_descendant(&iter, "_id", &val) ){
                        query = BCON_NEW ("_id", BCON_OID(bson_iter_oid(&val)) );
                        update = BCON_NEW ("$set","{", "username", BCON_UTF8(name), "time", BCON_INT64(time(nullptr)),"}");
                        if (!mongoc_collection_update_one (onlineCollection, query, update, NULL, NULL, &error))
                            fprintf (stderr, "%s\n", error.message);
                        return;
                    }
                }
            }
        }
        //if cannot find existing document with player's username
        BSON_APPEND_UTF8(insert, "username", name);
        BSON_APPEND_INT64(insert, "time", time(nullptr));
        if (!mongoc_collection_insert_one(onlineCollection, insert, NULL, NULL, &error))
            fprintf(stderr, "%s\n", error.message);
    }

    void static pushLoadedMap(map <string,int> x, map <string,int> y, map <int, string> z){
        for(mapit = x.begin(); mapit != x.end(); mapit++){
            DHmap[ mapit->first ] = mapit->second;
        }
        for(mapit = y.begin(); mapit != y.end(); mapit++){
            DHIDmap[ mapit->first ] = mapit->second;
        }
        for(mapit2 = z.begin(); mapit2 != z.end(); mapit2++){
            DHItemID[ mapit2->first ] = mapit2->second;
        }
    }
    void static pushLoadedArray(int x[60]){
        for(int i=0; i<60; i++){
            DHdata[i]=x[i];
        }
    }
    void static pushTexts(string x){
        DHpetname = x;
    }
}
