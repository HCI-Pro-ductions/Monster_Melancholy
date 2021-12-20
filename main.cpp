#include <winsock2.h>
#include <windows.h>
#include <commctrl.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <map>
//#include <stdio.h>
//#include <math.h>
//#include <iomanip>
#include "MHGdataHandle.h"
#include "MHGcombat.h"
#include "MHGguiHandle.h"

using namespace std;

using namespace MHGdataHandle; //from MHGdataHandle.h
using namespace MHGcombat; //from MHGcombat.h, #included header in MHGdataHandle.h
using namespace MHGtextDisplay; //from MHGtextDisplay.h, #included header in MHGcombat.h
using namespace MHGsounds; //from MHGsounds.h, #included header in MHGcombat.h
using namespace MHGguiHandle; //from MHGguiHandle.h

    int version;
	int tpass, prevt=time(nullptr);
	int k, m, t, x=2;
	int page=1;
	int hours, mins, secs;
	int sd16=0,sd17=0,sd18=0,sd19=0,sd20=0,sd21=0,sd22=0,sd23=0,sd24=0,total=0;
	char input[1];
	//float fadamage=0, num=0;
	int sdata[60]={seed1,seed2,version,coins,lvl,xp,cStage,sword,shield,armour,magic_fsword1,magic_healp2,magicpt,pet,skill_fa1,skill_2,mcnt,prevt,mShards,swordtier,armourtier,
	shieldtier,emcnt,dmcnt,sShards,cShards,dcnt,dchance,mWood,oWood,ironOre,pyrogems,equip,skillFB,skillSM,skillGG,magicBB,snowballs,sd16,sd17,sd18,sd19,sd20,sd21,sd22,sd23,sd24,total};
	map <string, int> smap, id_map;
    map <int, string> itemID;
	map <string, int> ::iterator map_it;
	string username="";
    string code="";

void updateTotal(){
	//total excludes seed1, seed2, version, and prevt
	total=coins+lvl+xp+cStage+sword+shield+armour+magic_fsword1+magic_healp2+magicpt+pet+skill_fa1+skill_2+mcnt+mShards+swordtier+armourtier+
	shieldtier+emcnt+dmcnt+sShards+cShards+dcnt+dchance+mWood+oWood+ironOre+pyrogems+equip+skillFB+skillSM+skillGG+magicBB+snowballs+sd16+sd17+sd18+sd19+sd20+sd21+sd22+sd23+sd24;
}

void loadMaps(){
    smap["seed1"]=seed1; smap["seed2"]=seed2; smap["version"]=version; smap["coins"]=coins; smap["lvl"]=lvl; smap["xp"]=xp; smap["cStage"]=cStage; smap["sword"]=sword;
    smap["shield"]=shield; smap["armour"]=armour; smap["magic_fsword1"]=magic_fsword1; smap["magic_healp2"]=magic_healp2; smap["magicpt"]=magicpt; smap["pet"]=pet;
    smap["skill_fa1"]=skill_fa1; smap["skill_2"]=skill_2; smap["mcnt"]=mcnt; smap["prevt"]=prevt; smap["mShards"]=mShards; smap["swordtier"]=swordtier; smap["armourtier"]=armourtier;
    smap["shieldtier"]=shieldtier; smap["emcnt"]=emcnt; smap["dmcnt"]=dmcnt; smap["sShards"]=sShards; smap["cShards"]=cShards; smap["dcnt"]=dcnt; smap["dchance"]=dchance; smap["mWood"]=mWood; smap["oWood"]=oWood;
    smap["ironOre"]=ironOre; smap["pyrogems"]=pyrogems; smap["equip"]=equip; smap["skillFB"]=skillFB; smap["skillSM"]=skillSM; smap["skillGG"]=skillGG; smap["magicBB"]=magicBB; smap["snowballs"]=snowballs; smap["sd16"]=sd16;
    smap["sd17"]=sd17; smap["sd18"]=sd18; smap["sd19"]=sd19; smap["sd20"]=sd20; smap["sd21"]=sd21; smap["sd22"]=sd22; smap["sd23"]=sd23; smap["sd24"]=sd24; smap["total"]=total;

    int i1=0;
    for(map_it = smap.begin(); map_it != smap.end(); map_it++){
        id_map[map_it->first] = i1;
        i1++;
    }
    itemID[0]="seed1"; itemID[1]="seed2"; itemID[2]="version"; itemID[3]="coins"; itemID[4]="lvl"; itemID[5]="xp"; itemID[6]="cStage";
    itemID[7]="sword"; itemID[8]="shield"; itemID[9]="armour"; itemID[10]="magic_fsword1"; itemID[11]="magic_healp2"; itemID[12]="magicpt";
    itemID[13]="pet"; itemID[14]="skill_fa1"; itemID[15]="skill_2"; itemID[16]="mcnt"; itemID[17]="prevt"; itemID[18]="mShards";
    itemID[19]="swordtier"; itemID[20]="armourtier"; itemID[21]="shieldtier"; itemID[22]="emcnt"; itemID[23]="dmcnt"; itemID[24]="sShards"; itemID[25]="cShards";
    itemID[26]="dcnt"; itemID[27]="dchance"; itemID[28]="mWood";  itemID[29]="oWood"; itemID[30]="ironOre"; itemID[31]="pyrogems"; itemID[32]="equip"; itemID[33]="skillFB";
    itemID[34]="skillSM"; itemID[35]="skillGG"; itemID[36]="magicBB"; itemID[37]="snowballs"; itemID[38]="sd16"; itemID[39]="sd17"; itemID[40]="sd18"; itemID[41]="sd19";
    itemID[42]="sd20"; itemID[43]="sd21"; itemID[44]="sd22"; itemID[45]="sd23"; itemID[46]="sd24";
    itemID[47]="total";
}

void updateStoredData(){
	datastore.open("MMGameFiles/MMGameData.txt");
	if (!datastore) { //unable to find/open txt data file
   cout << "Fatal Error! Unable to store data! Please report bug as 'Error4'." << "\n";
   system("color 0C");
   cout<<'\a';
   while(true) Sleep(100);
}
	datastore<<seed1<<" "<<seed2<<" "<<version<<" ";

	int s2data[60]={seed1,seed2,version,coins,lvl,xp,cStage,sword,shield,armour,magic_fsword1,magic_healp2,magicpt,pet,skill_fa1,skill_2,mcnt,prevt,mShards,swordtier,armourtier,
	shieldtier,emcnt,dmcnt,sShards,cShards,dcnt,dchance,mWood,oWood,ironOre,pyrogems,equip,skillFB,skillSM,skillGG,magicBB,snowballs,sd16,sd17,sd18,sd19,sd20,sd21,sd22,sd23,sd24,total};
	for(m=3;m<47;m++){
		if(m!=17) datastore<<encrypt(s2data[m])<<" "; //encryption
		else datastore<<s2data[m]<<" ";
		//cout<<s2data[m]<<"/";
	}
	updateTotal();
	datastore<<total<<" ";
	datastore<<"\n"<<stringE(petname);
    datastore<<"\n"<<stringE(username);
	datastore.close();
	loadMaps();
    pushLoadedMap(smap,id_map,itemID); pushLoadedArray(sdata); pushTexts(petname);
    updateDatabase(petname.c_str(), username.c_str());
	cout<<"Game progress saved!"<<"\n";
}

void del_PABTC(){//PABTC stands for Press any button to continue
	for(int i=0; i<31; i++) cout<<"\b \b";
}

void dungeonResult(char result, HWND hwnd){
    if(result == 'S'){
        displayDungeon(R, C); dungeonRes();
    }
    else if(result == 'F'){
        textc(12); cout<<"NO!!! You would knock yourself onto the wall!!!\n"; textc(10);
        cout<<'\a';
        Sleep(2000);
        displayDungeon(R, C); dungeonRes();
    }
    else if(result == 'M'){
        bInDMfight=true;
        bInDungeon=false;
        fighttype=4;
        mfight();
        mFightRes();
    }
    else if(result == 'T'){
        cout<<"You found "; textc(14); cout<<"treasure"; textc(10); cout<<", ";
        cout<<'\a';
        dungeonTreasure(); cout<<"\n\n"; SleepTillNextSec(); Sleep(1000);
        displayDungeon(R, C); dungeonRes();
    }
    else if(result == 'E'){
        cout<<'\a';
        if(MessageBox(hwnd, "Exit the Dungeon?", "Confirmation Message", MB_YESNO | MB_ICONQUESTION) == IDYES){
            dungeonExit();
            updateStoredData();
            bInDungeon=false;
            bInMainMenu=true;
        }
        else{ displayDungeon(R, C); dungeonRes(); }
    }
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {

		case WM_CREATE:{

		    createMenus(hwnd);

            /*cout<<"   __  __  ____  _   _  _____ _______ ______ _____     _    _ _    _ _   _ _______ ______ _____  \n";
            cout<<" C|  \\/  |/ __ \\| \\ | |/ ____|__   __|  ____|  __ \\   | |  | | |  | | \\ | |__   __|  ____|  __ \\ G\n";
            cout<<" +| \\  / | |  | |  \\| | (___    | |  | |__  | |__) |  | |__| | |  | |  \\| |  | |  | |__  | |__) |A\n";
            cout<<" +| |\\/| | |  | | . ` |\\___ \\   | |  |  __| |  _  /   |  __  | |  | | . ` |  | |  |  __| |  _  / M\n";
            cout<<"  | |  | | |__| | |\\  |____) |  | |  | |____| | \\ \\   | |  | | |__| | |\\  |  | |  | |____| | \\ \\ E\n";
            cout<<"  |_|  |_|\\____/|_| \\_|_____/   |_|  |______|_|  \\_\\  |_|  |_|\\____/|_| \\_|  |_|  |______|_|  \\_\\ by HCI Pro-ductions \n";*/
            /*cout<<"  __  __   _    _    _____\n";
            cout<<"C|  \\/  | | |  | |  / ____|\n";
            cout<<"+| \\  / | | |__| | | |  __\n";
            cout<<"+| |\\/| | |  __  | | | |_ |\n";
            cout<<" | |  | | | |  | | | |__| |\n";
            cout<<" |_|  |_| |_|  |_|  \\_____|by HCI Pro-ductions\n";*/
                /*cout<<" MMMMMMMM               MMMMMMMM HHHHHHHHH     HHHHHHHHH        GGGGGGGGGGGGG \n";
                cout<<" M:::::::M             M:::::::M H:::::::H     H:::::::H     GGG::::::::::::G \n";
                cout<<" M::::::::M           M::::::::M H:::::::H     H:::::::H   GG:::::::::::::::G \n";
                cout<<" M:::::::::M         M:::::::::M HH::::::H     H::::::HH  G:::::GGGGGGGG::::G \n";
                cout<<" M:::Mon::::M       M::::ster::M   H:::::H     H:::::H   G:::::G       GGGGGG \n";
                cout<<" M:::::::::::M     M:::::::::::M   H:::::H     H:::::H  G:::::G               \n";
                cout<<" M:::::::M::::M   M::::M:::::::M   H::::::HHHHH::::::H  G:::::G               \n";
                cout<<" M::::::M M::::M M::::M M::::::M   H:::::::::::::::::H  G:::::G    GGGGGGGGGG \n";
                cout<<" M::::::M  M::::M::::M  M::::::M   H:::::::Hunt::::::H  G:::::G    G::::::::G \n";
                cout<<" M::::::M   M:::::::M   M::::::M   H::::::HHHHH::::::H  G:::::G    GGGGG::::G \n";
                cout<<" M::::::M    M:::::M    M::::::M   H:::::H     H:::::H  G:::::G        G::G:G \n";
                cout<<" M::::::M     MMMMM     M::::::M   H:::::H     H:::::H   G:::::G       G::A:G \n";
                cout<<" M::::::M               M::::::M HH::::::H     H::::::HH  G:::::GGGGGGGG::M:G \n";
                cout<<" M::::::M               M::::::M H:::::::H     H:::er::H   GG:::::::::::::E:G \n";
                cout<<" M::::::M               M::::::M H:::::::H     H:::::::H     GGG::::::GGG:::G \n";
                cout<<" MMMMMMMM               MMMMMMMM HHHHHHHHH     HHHHHHHHH        GGGGGG   GGGG by HCI Pro-ductions\n";*/
                cout<<R"( __  __  ____  _   _  _____ _______ ______ _____    __  __ ______ _               _   _  _____ _    _  ____  _  __     __)"<<"\n";
                cout<<R"(|  \/  |/ __ \| \ | |/ ____|__   __|  ____|  __ \  |  \/  |  ____| |        /\   | \ | |/ ____| |  | |/ __ \| | \ \   / /)"<<"\n";
                cout<<R"(| \  / | |  | |  \| | (___    | |  | |__  | |__) | | \  / | |__  | |       /  \  |  \| | |    | |__| | |  | | |  \ \_/ / )"<<"\n";
                cout<<R"(| |\/| | |  | | . ` |\___ \   | |  |  __| |  _  /  | |\/| |  __| | |      / /\ \ | . ` | |    |  __  | |  | | |   \   /  )"<<"\n";
                cout<<R"(| |  | | |__| | |\  |____) |  | |  | |____| | \ \  | |  | | |____| |____ / ____ \| |\  | |____| |  | | |__| | |____| |   )"<<"\n";
                cout<<R"(|_|  |_|\____/|_| \_|_____/   |_|  |______|_|  \_\ |_|  |_|______|______/_/    \_\_| \_|\_____|_|  |_|\____/|______|_|   by HCI Pro-Ductions)"<<"\n";

                srand( (unsigned)time(NULL) );

	cout << "Loading...\n";
	cout << "Do not click anything just yet!\n" ;

	t = time(0);
	while(time(0)-t<=1){}
	cout << "Tip: Use full screen mode/maximise on this screen (not the Control Panel) to get the best experience!\n";
	//cout << "Tip: See the Download Instructions to learn how to get the best experience!\n";
	t = time(0);
	while(time(0)-t<=1){}

	//loading...
	//-------------------//version input ------------------------------

	//dataget>>seed1>>seed2>>coins>>lvl>>xp>>cStage>>sword>>shield>>armour>>magic_fsword1>>magic_healp2>>magicpt>>pet>>skill_fa1>>skill_2>>mcnt>>prevt>>version;
	//getline(pet_dataget, petname);

	//encryption: (data*seed1)+(seed2-4)
	//decryption: (data-(seed2-4))/seed1 [See MHGdataHandle.h for decrypt function]

    cout<<"Connecting to server...\n";
	mongoc_init();//Required to initialize libmongoc's internals
    if( !phraseURI() ) while(true){};
    if( !createClient() ) while(true){};
    handleDatabase();
    if( !pingDatabase() ) while(true){};



   version=0;//2.0.0
   dataget.open("MMGameFiles/MMGameData.txt");

   dataget>>seed1>>seed2;
   dataget.close();

   //check if its first time playing

   if (seed1>100||seed1<3||seed2>200||seed2<7) {
   cout<<"\n"<<R"(Have you created a MHG account yet? (Type "Y" for yes or "N" for no (without the inverted commas) then press enter to answer))" <<"\n";
   cout << "Your Response: ";
	cin >> input[0];
	cout<<"\n";
	cout<<"----------------------------------------"<<"\n";
	if(input[0]=='N') {
	//reset data

	seed1=3+rand()%98; //3-100
	seed2=7+rand()%194; //7-200
	
    datastore.open("MMGameFiles/MMGameData.txt");
    if (!datastore){
   cout << "Fatal Error! Unable to store data! Please report bug as 'Error4'." << "\n";
   system("color 0C");
   cout<<'\a';
   while(true){}
}
    //cout<<seed1<<" "<<seed2<<" "<<version<<" "<<"\n";
	datastore<<seed1<<" "<<seed2<<" "<<version<<" ";

	int sdata[60]={seed1,seed2,version,coins,lvl,xp,cStage,sword,shield,armour,magic_fsword1,magic_healp2,magicpt,pet,skill_fa1,skill_2,mcnt,prevt,mShards,swordtier,armourtier,
	shieldtier,emcnt,dmcnt,sShards,cShards,dcnt,dchance,mWood,oWood,ironOre,pyrogems,equip,skillFB,skillSM,skillGG,magicBB,snowballs,sd16,sd17,sd18,sd19,sd20,sd21,sd22,sd23,sd24,total};

	for(m=3;m<47;m++){
		if(m!=17) sdata[m]=encrypt(sdata[m]); //encryption
		datastore<<sdata[m]<<" ";
		//cout<<sdata[m]<<" ";
	}
	updateTotal();
	datastore<<total<<" ";
	datastore<<"\n"<<stringE(petname);

	//setup account
	cout<<"Please create an account, and refer to the game documentation for details."<<"\n";

	string newNamestr;
	do{ cout<<"Username>";
	    cin>>newNamestr;
	} while(newNamestr.size()>20);
	for(int i=0; i<newNamestr.size(); i++) username += newNamestr[i];

	while( scanForUser(username.c_str()) ){
	    cout<<"Username already taken!"<<"\n";
        do{ cout<<"Username>";
            cin>>newNamestr;
        } while(newNamestr.size()>20);
        username="";
        for(int i=0; i<newNamestr.size(); i++) username += newNamestr[i];

	}
	    string hashPass = getHashedPassword("Password>");
        addNewUser( username, hashPass.c_str() );
        datastore<<"\n"<<stringE(username);
	    datastore.close();
	    cout<<"\n";
	    cout<<"Account creation success!"<<"\n";

}
	else if(input[0]=='Y'){
        //login to account
        string newNamestr;
        cout<<"Please login into your existing account\n\n";
        do{ cout<<"Username>";
            cin>>newNamestr;
        } while(newNamestr.size()>20);
        for(int i=0; i<newNamestr.size(); i++) username += newNamestr[i];

        while( !scanForUser(username.c_str()) ){
            cout<<"Username not found!"<<"\n";
            do{ cout<<"Username>";
                cin>>newNamestr;
            } while(newNamestr.size()>20);
            username="";
            for(int i=0; i<newNamestr.size(); i++) username += newNamestr[i];
        }
        string hashPass = getHashedPassword("Password>");
        cout<<"Verifying Password..."<<endl<<"\n";
        while( !verifyUser(username.c_str(), hashPass.c_str()) ){
            cout<<"Password Incorrect!"<<"\n";
            hashPass = getHashedPassword("Password>");
            cout<<"Verifying Password..."<<endl<<"\n";
        }
        loadMaps();
        pushLoadedMap(smap,id_map,itemID); pushTexts(petname);
        readDatabase(username.c_str());
        if(true){//for collapsing this block of code in IDEs
            coins=DHmap[itemID[3]]; lvl=DHmap[itemID[4]]; xp=DHmap[itemID[5]]; cStage=DHmap[itemID[6]]; sword=DHmap[itemID[7]];
            shield=DHmap[itemID[8]]; armour=DHmap[itemID[9]]; magic_fsword1=DHmap[itemID[10]]; magic_healp2=DHmap[itemID[11]];
            magicpt=DHmap[itemID[12]]; pet=DHmap[itemID[13]]; skill_fa1=DHmap[itemID[14]]; skill_2=DHmap[itemID[15]]; mcnt=DHmap[itemID[16]];
            prevt=DHmap[itemID[17]]; mShards=DHmap[itemID[18]]; swordtier=DHmap[itemID[19]]; armourtier=DHmap[itemID[20]]; shieldtier=DHmap[itemID[21]];
            emcnt=DHmap[itemID[22]]; dmcnt=DHmap[itemID[23]]; sShards=DHmap[itemID[24]];  cShards=DHmap[itemID[25]]; dcnt=DHmap[itemID[26]];
            dchance=DHmap[itemID[27]]; mWood=DHmap[itemID[28]]; oWood=DHmap[itemID[29]]; ironOre=DHmap[itemID[30]]; pyrogems=DHmap[itemID[31]]; equip=DHmap[itemID[32]];
            skillFB=DHmap[itemID[33]]; skillSM=DHmap[itemID[34]]; skillGG=DHmap[itemID[35]]; magicBB=DHmap[itemID[36]]; snowballs=DHmap[itemID[37]]; sd16=DHmap[itemID[38]];
            sd17=DHmap[itemID[39]]; sd18=DHmap[itemID[40]]; sd19=DHmap[itemID[41]]; sd20=DHmap[itemID[42]]; sd21=DHmap[itemID[43]]; sd22=DHmap[itemID[44]];
            sd23=DHmap[itemID[45]]; sd24=DHmap[itemID[46]];
            total=DHmap[itemID[47]];
        }
        updateStoredData();
        cout<<"Account login success!"<<"\n";
	}
	else{
	    cin.ignore();
	    textc(12);
	    cout<<"Invalid response, rerun the programme to try again."<<"\n";
		while(true){}
	}
}

   dataget.open("MMGameFiles/MMGameData.txt");
   if (!dataget) {
   cout << "Fatal Error! Unable to retrieve data! Please report bug as 'Error3'." << "\n";
   system("color 0C");
   cout<<'\a';
   while(true){}
}
   dataget>>seed1>>seed2>>version;
   for(m=3;m<47;m++){//decryption and read data	into program variables
		dataget>>sdata[m];
		if(m!=17) sdata[m]=decrypt(sdata[m],m,true);
		//cout<<sdata[m]<<" ";
	}
   int check=0;
   dataget>>total;
   for(m=3;m<47;m++){//get the current total value (store into check)
		if(m!=17) check=check+sdata[m];
	}

   if(true){//for collapsing this block of code in IDEs
   coins=sdata[3]; lvl=sdata[4];
   xp=sdata[5]; cStage=sdata[6]; sword=sdata[7]; shield=sdata[8]; armour=sdata[9]; magic_fsword1=sdata[10]; magic_healp2=sdata[11]; magicpt=sdata[12]; pet=sdata[13];
   skill_fa1=sdata[14]; skill_2=sdata[15]; mcnt=sdata[16]; prevt=sdata[17]; mShards=sdata[18]; swordtier=sdata[19]; armourtier=sdata[20]; shieldtier=sdata[21];
   emcnt=sdata[22]; dmcnt=sdata[23]; sShards=sdata[24];  cShards=sdata[25]; dcnt=sdata[26]; dchance=sdata[27]; mWood=sdata[28]; oWood=sdata[29]; ironOre=sdata[30]; pyrogems=sdata[31]; equip=sdata[32]; skillFB=sdata[33];
   skillSM=sdata[34]; skillGG=sdata[35]; magicBB=sdata[36]; snowballs=sdata[37]; sd16=sdata[38]; sd17=sdata[39]; sd18=sdata[40]; sd19=sdata[41]; sd20=sdata[42]; sd21=sdata[43];
   sd22=sdata[44]; sd23=sdata[45]; sd24=sdata[46];
   total=sdata[47];
   }

   dataget.ignore(10,'\n');
   petname=""; username="";
   char cx;
   while(dataget.get(cx) && cx!='\n') petname+=cx;
   //cout<<petname;
   petname = stringD(petname);//a possible defalut encrypted petname is CIPVY99$07i#0',

   while(dataget.get(cx) && cx!='\n') username+=cx;
   //cout<<username<<"\n";
   username = stringD(username);
   //cout<<"decrypted petname:"<<petname<<"\n";
   //cout<<"decrypted username:"<<username<<"\n";

   dataget.close();

if(rand()%2==1){//random seed change (50% chance)

	seed1=3+rand()%98; //3-100
	seed2=7+rand()%194; //7-200
//

    datastore.open("MMGameFiles/MMGameData.txt");
    if (!datastore) {
   cout << "Fatal Error! Unable to store data! Please report bug as 'Error4'." << "\n";
   system("color 0C");
   cout<<'\a';
   while(true){}
}
    cout<<"Seed changing...";
    //cout<<seed1<<" "<<seed2<<"Seed changing "<<version<<" "<<"\n";
    //cout<<"Version 1."<<version<<"\n";
	datastore<<seed1<<" "<<seed2<<" "<<version<<" ";

	int sdata[50]={seed1,seed2,version,coins,lvl,xp,cStage,sword,shield,armour,magic_fsword1,magic_healp2,magicpt,pet,skill_fa1,skill_2,mcnt,prevt,mShards,swordtier,armourtier,
	shieldtier,emcnt,dmcnt,sShards,cShards,dcnt,dchance,mWood,oWood,ironOre,pyrogems,equip,skillFB,skillSM,skillGG,magicBB,snowballs,sd16,sd17,sd18,sd19,sd20,sd21,sd22,sd23,sd24,total};

	for(m=3;m<47;m++){
		if(m!=17)sdata[m]=encrypt(sdata[m]); //encryption
		datastore<<sdata[m]<<" ";
		//cout<<sdata[m]<<" ";
	}
	updateTotal();
	datastore<<total<<" ";
	//cout<<petname<<"-"<<username<<"\n";
	datastore<<"\n"<<stringE(petname);
    datastore<<"\n"<<stringE(username);


	datastore.close();

	//cout<<"\n";
}

	loadMaps();
    pushLoadedMap(smap,id_map,itemID);
    pushLoadedArray(sdata);
    pushTexts(petname);

    cout<<"\n";
    cout<<"You are logging in to the account with username \""<<username<<"\"\n";
    string hashPass = getHashedPassword("Password>");
    cout<<"Verifying Password..."<<endl<<"\n";
    while( !verifyUser(username.c_str(), hashPass.c_str()) ){
        cout<<"Password Incorrect!"<<"\n";
        hashPass = getHashedPassword("Password>");
        cout<<"Verifying Password..."<<endl<<"\n";
    }
    cout<<"Login Success!"<<"\n\n";



    updateDatabase(petname.c_str(), username.c_str());
    //readDatabase(username.c_str());
    updateLeaderboard(username.c_str(), lvl);
    loadLvlUp();

	php=getPlayerHP();

	system("color 0A");

    cout <<'\a';
	cout << "Loading complete!\n";
	cout << "Welcome to Monster Melancholy!\n";

	cout << "To exit the game simply close the Control Panel!\n";
	//cout << "Press h then enter for help, or s for stats, or c for combat stats!\n";
	cout << "Use the Control Panel to play the game!\n";
	cout << "Get started by clicking \"Explore\"!"<<"\n";

            checkForEvents();
            if(eventChristmas){textc(15); cout<<"\nMerry Christmas!!!\n\n"; textc(10);}

			break;
}


        case WM_CTLCOLORSTATIC:{
            SetTextColor( (HDC)wParam, RGB(0,255,0));//green text colour
            SetBkColor( (HDC)wParam, RGB(0,0,0));//black *text* background colour
            return (INT_PTR)hBrushBlack; //black *text space* colour
        }

        case WM_CTLCOLOREDIT:{
            SetTextColor( (HDC)wParam, RGB(0,255,0));//dark green text colour
            SetBkColor( (HDC)wParam, RGB(0,0,0));//black *text* background colour
            return (INT_PTR)hBrushBlack; //black *text space* colour
        }

        case WM_CTLCOLORBTN:{
            SetTextColor( (HDC)wParam, RGB(0,0,0));//black text colour
            SetBkColor( (HDC)wParam, RGB(0,200,0));//green *text* background colour
            SelectObject( (HDC)wParam, (HGDIOBJ)hf);
            return (INT_PTR)hBrushDarkGreen;
        }

        case WM_DRAWITEM: {//owner draw
            ownerDraw(lParam, wParam);
            return TRUE;
        }
        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            SetDCBrushColor(hdc, RGB(0, 200, 0));//dark green
            SetDCPenColor(hdc, RGB(0, 200, 0));
            SelectObject(hdc, GetStockObject(DC_BRUSH) );
            SelectObject(hdc, GetStockObject(DC_PEN) );
            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH)hBrushBlack);
            //RoundRect(hdc, -10, -3, 700, 3, 5, 5);
            EndPaint(hwnd, &ps);
        }


		/* Upon destruction, tell the main thread to stop */
		case WM_COMMAND:{

            updateOnlineStatus(username.c_str());

			switch(LOWORD(wParam)){

			    /*case ID_Test:{
			        char out1[30]="abc";
			        SetWindowText(hStatus,out1);
			        break;
			    }
                case ID_Test2:{
                    char out2[30]="def";
                    SetWindowText(hStatus,out2);
                    break;
                }*/

			    case ID_ProfileMenu1://view profile
			        if(bInMainMenu){
                        textc(10);
                        viewProfile(smap, petname, prefix, xpToLvlUp, getPlayerHP());
			        }
			        else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
			        break; //ID_ProfileMenu1 break

                case ID_ProfileMenu2://leaderboard
                    if(bInMainMenu){
                        textc(10);
                        cout<<"\n";
                        displayLeaderboard(loadLeaderboard(), username, hConsole);
                    }
                    else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    break; //ID_ProfileMenu2 break

                case ID_ProfileMenu3://online players
                    if(bInMainMenu){
                        textc(10);
                        cout<<"\n";
                        displayOnlinePlayers();
                    }
                    else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    break; //ID_ProfileMenu3 break

                case ID_ProfileMenu4://daily reward
                    if(bInMainMenu){
                        tpass=time(0)-prevt;
                        if(tpass>=86400){
                            if(swordtier>=2) cout<<"You have claimed your daily reward! "<<lvl*1000<<" coins and "<<1<<" Magic Essence granted!!!"<<"\n";
                            if(swordtier<2) cout<<"You have claimed your daily reward! "<<lvl*1000<<" coins and "<<0<<" Magic Essence granted!!!"<<"\n";
                            cout<<"Your daily Dungeon attempts have also reset to 5."<<"\n\n";
                            cout<<'\a';

                            dchance=5;
                            coins=coins+lvl*1000;
                            if(swordtier>=2) magicpt++;
                            tpass=0;
                            prevt=time(0);
                            updateStoredData();
                        }
                        else{
                            tpass=time(0)-prevt;
                            hours=23-(tpass/3600);
                            mins=1439-(tpass/60)-(hours*60);
                            secs=86399-tpass-(mins*60)-(hours*3600);

                            if(tpass<=82800)
                                cout<<"You still have "<<hours<<" hours, "<<mins<<" minutes and "<<secs<<" seconds left to your next daily reward!"<<"\n"<<"\n";
                            if(tpass>=82800)
                                cout<<"You still have "<<mins<<" minutes and "<<secs<<" seconds left to your next daily reward!"<<"\n"<<"\n";
                        }
                        cout<<"You are still at Home..."<<"\n"<<"\n";
                    }
                    else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    break; //ID_ProfileMenu4 break

                case ID_ProfileMenu5://monster encyclopedia
                    if(bInMainMenu){
                        page=1;
                        bInMainMenu=false;
                        bInMonEn=true;
                        displayMonsterEn(page);
                        updateGUIstatus();
                    }
                    else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    break; //ID_ProfileMenu5 break

                case ID_ProfileMenu6://redeem code
                    if(bInMainMenu){
                        textc(10);
                        bInMainMenu=false;
                        bInRedeemCode=true;
                        cout<<"\nPlease enter the code into the textbox on the control panel\n";
                        updateGUIstatus();
                    }
                    else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    break; //ID_ProfileMenu6 break

			case ID_MonMenu1:{
			    if(bInMainMenu){
				textc(10);
				fighttype=1;
				bInMainMenu=false;
				bInWMfight=true;
				updateGUIstatus();
				mfight();
				if(randomNo!=100) mFightRes();
				else{
				bInMainMenu=true;
				bInWMfight=false;
				updateGUIstatus();
				}
}
			    else{
			    	MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
			    }
			    break;//ID_MonMenu1 case break
	}

			case ID_MonMenu2:{

			if(bInMainMenu){

				fighttype=2;
				bInMainMenu=false;
				bInEMfight=true;
                updateGUIstatus();
				mfight();
				if(randomNo!=100) mFightRes();
				else{
				bInMainMenu=true;
				bInEMfight=false;
				updateGUIstatus();
				}
}
			else{
				MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
			}
			break;//ID_MonMenu2 case break
}


			case ID_MonMenu3:{

			if(bInMainMenu){

				textc(10);
				fighttype=3;
				bInMainMenu=false;
				bInCMfight=true;
                updateGUIstatus();
				mfight();
				mFightRes();
}
			else{
				MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
			}
			break;//ID_MonMenu3 case break
}

                case ID_MonMenu4:

                    if(bInMainMenu){
                        if(dchance>0){
                            textc(10);
                            fighttype = 4;
                            bInMainMenu = false;
                            bInDungeon = true;
                            updateGUIstatus();
                            generateDungeon();
                            dungeonRes();
                        }
                        else{
                            MessageBox(hwnd, "You have run out of Dungeon attempts for today.", "Cannot Perform Action", MB_ICONINFORMATION);
                        }
                    }
                    else{
                        MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    }
                    break;//ID_MonMenu4 case break



        case ID_ShopMenu1:{ //Equipment Shop

    	    if(bInMainMenu){
    		    textc(10);
    		    Shop::equip(smap);
    		    bInMainMenu=false;
			    bInShopE=true;
                updateGUIstatus();
			    playerRes();
		    }

    	    else{
    	        MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
		    }

	        break;//ID_ShopMenu1 case break

		}



	case ID_ShopMenu2:{//Skills Shop
	    if(bInMainMenu){
		    textc(10);
    	    Shop::skill(smap);
    	    bInMainMenu=false;
		    bInShopS=true;
		    updateGUIstatus();
		    playerRes();
	    }

	    else{
				MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
	    }

        break;//ID_ShopMenu2 case break

}




	case ID_ShopMenu3:{//Magic Altar
	if(bInMainMenu){
		textc(10);
    		Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
    		bInMainMenu=false;
			bInShopM=true;
            updateGUIstatus();
			playerRes();
		}

    	else{
				MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
		}

break;//ID_ShopMenu3 case break

}

            case ID_ShopMenu4://Smithing Shop
                if(bInMainMenu){
		            textc(10);
		            Shop::smith(smap);
    		        bInMainMenu=false;
			        bInShopSM=true;
                    updateGUIstatus();
			        playerRes();
		        }

    	        else{
				MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
		        }
                break;//ID_ShopMenu4 case break

                case ID_ShopMenu5://Pyrogems Shop
                    if(bInMainMenu){
                        textc(10);
                        Shop::create(smap);
                        bInMainMenu=false;
                        bInShopC=true;
                        updateGUIstatus();
                        playerRes();
                    }

                    else{
                        MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    }
                    break;//ID_ShopMenu5 case break


                case ID_ItemMenu1://Inventory
                    if(bInMainMenu||bInDungeon){
                        textc(10);
                        displayInv();
                    }
                    break;//ID_ItemMenu1 case break
                case ID_ItemMenu2://Chest at Home
                    if(bInMainMenu){
                        textc(10);
                        displayChest(smap);
                    }
                    break;//ID_ItemMenu1 case break

			    case ID_CombatMenu1://Toggle shield
			        if(bInMainMenu || bInDungeon){
			            if(shield>0 && equip==0){
			                equip=1; cout<<"\nShield equipped!\n";
			            }
			            else if(shield>0 && equip==0){
			                equip=0; cout<<"\nShield unequipped!\n";
			            }
			            else if(shield==0){
			                cout<<"\nYou do not have a shield yet!\n";
			            }
			        }
			        else MessageBox(hwnd, "Please exit a fight before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
			        break; //ID_CombatMenu1 case break
			    case ID_SettingsMenu1:
			        if(bInMainMenu){
                        textc(10);
                        displayCredits();
                    }
			        else MessageBox(hwnd, "Please return Home before performing this action.", "Cannot Perform Action", MB_ICONINFORMATION);
                    break; //ID_SettingsMenu1 case break

			case ID_BUTTON1:
				//MessageBox(hwnd, "button has been clicked", "Pop-up", MB_ICONINFOMATION);
				if(bInWMfight || bInEMfight || bInCMfight || bInDMfight){//choice: fight
					mfight_choice(1);
					if(fightover){
					    fightover=false;
                        if(bInWMfight || bInEMfight || bInCMfight) bInMainMenu=true;
                        else if(bInDMfight && fightwin){ bInDungeon=true; displayDungeon(R, C); }
                        else if(bInDMfight && !fightwin) bInMainMenu=true;
                        if(bInWMfight) bInWMfight=false;
                        if(bInEMfight) bInEMfight=false;
                        if(bInCMfight) bInCMfight=false;
                        if(bInDMfight) bInDMfight=false;
                        updateStoredData();
					    updateGUIstatus();
                        updateLeaderboard(username.c_str(), lvl);
					}
				}

			    if(bInShopE){//Sword upgrade
		            cout<<"1\n";
		            cout<<"Are you sure you want to upgrade your sword from level "<<sword<<" to "<<"level "<<sword+1;
                    if( (sword+1)%10 != 0) cout<<" with "<<sword*100<<" coins";
		            cout<<"?"<<" You have "<<coins<<" coins."<<"\n";
		            cout<<"Press the Yes/No button"<<"\n"<<"\n";
		            cout<< "Your response: ";
		            bSwordYesNo=true;
		            bInShopE=false;
                }

				if(bInShopS){//First Ace Skill Upgrade
		            cout<<"1\n";
		            if(skill_fa1==0) {
		                cout<<"Are you sure you want to unlock First Ace "<<" with "<<"1000"<<" coins?"<<" You have "<<coins<<" coins."<<"\n";
		                cout<<"Press the Yes/No button"<<"\n"<<"\n";
		                cout<< "Your response: ";
		                is_skillfa1yesno=true;
		                bInShopS=false;
	                }
		            if(skill_fa1>0&&skill_fa1<5){
		                cout<<"Are you sure you want to upgrade First Ace from level "<<skill_fa1<<" to "<<"level "<<skill_fa1+1<< " with ";
		                cout<<(skill_fa1+1)*(skill_fa1+1)*1000<<" coins?"<<" You have "<<coins<<" coins."<<"\n";
		                cout<<"Press the Yes/No button"<<"\n"<<"\n";
		                cout<< "Your response: ";
		                is_skillfa1yesno=true;
		                bInShopS=false;
                    }
		            if(skill_fa1>=5){
			            cout<<"First Ace Skill is already at max level!"<<"\n"<<"\n";
			            Shop::skill(smap);
			            playerRes();
	                }

                }

				if(bInShopM){//Blaze Blade Upgrade
		            cout<<"1\n";
		            if(magic_fsword1==0) cout<<"Are you sure you want to unlock Blaze Blade with 50.0k coins?"<<" You have "<<coins<<" coins."<<"\n";
	                if(magic_fsword1>0) cout<<"Are you sure you want to upgrade Blaze Blade from level "<<magic_fsword1<<" to "<<"level "<<magic_fsword1+1
		            << " with "<<magic_fsword1*5<<" Magic Essence?"<<" You have "<<magicpt<<" Magic Essence."<<"\n";
		            cout<<"Press the Yes/No button"<<"\n"<<"\n";
		            cout<< "Your response: ";
		            is_magicfs1yesno=true;
		            bInShopM=false;
                }

                    if(bInShopSM){//SwordTier upgrade
                        cout<<"1\n";
                        cout<<"Are you sure you want to improve your Sword's Prestige Level from "; tierd(swordtier, 2);
                        cout<<" to "; tierd(swordtier, 2); cout<<" with "<<tcosts[swordtier]<<" Mysterious Shards, "
                        <<tcosts2[swordtier]<<" Shiny Shards, and "<<tcosts2[swordtier]<<" Crystal Shards?\n";
                        cout<<"Press the Yes/No button"<<"\n"<<"\n";
                        cout<< "Your response: ";
                        bSwordTierYesNo=true;
                        bInShopSM=false;
                    }

                    if(bInShopC){//Item Creation
                        cout<<"1\n";
                        cout<<"Are you sure you want to use your UR power, plus 5 Pyrogems, and cast Item Creation I?\n";
                        cout<<"Press the Yes/No button"<<"\n"<<"\n";
                        cout<< "Your response: ";
                        bItemCreateIYesNo=true;
                        bInShopC=false;
                    }

				if(bInMonEn){
				    if(page>1){
				        page--; displayMonsterEn(page);
				    }
				}

		        break;//ID_BUTTON1 case break


			case ID_BUTTON2:{

                if(bInDMfight){//cannot run away
                    cout<<"2\n";
                    textc(12); cout<<"You cannot run from Dungeon Fights!!!\n\n"; textc(10);
                    cout<<'\a';
                    Sleep(2000);
                    mFightRes();
                }

				if(bInWMfight || bInEMfight || bInCMfight){//Monster try to run away
                    mt19937 rdm(time(0)); uniform_int_distribution<int> range100(1, 100); int random = range100(rdm);
                    int HpPercent = tempPhp*100/php;
                    if( (HpPercent+10) >= random) { // run success (chance is 10% + current % health, if >100%, then sure can run away)
                        cout << "2\n"; cout << "\n";
                        cout << "----------------------------------------\n";
                        cout << "You ran away! Back to Home...\n\n";
                        textc(10);
                        php = getPlayerHP();
                        fightover = false; fightwin = false;
                        bInMainMenu = true;
                        if (bInWMfight) bInWMfight = false; if (bInEMfight) bInEMfight = false; if (bInCMfight) bInCMfight = false;
                        updateGUIstatus();
                    }
                    else{ //fail to run, so fight
                        cout << "2\n"; cout << "\n";
                        cout << "----------------------------------------\n";
                        cout<<'\a'; textc(12); cout << "You could not run away... so you stood and fought\n\n"; textc(10);
                        Sleep(1000);
                        //same as button 1 fight choice
                        mfight_choice(1);
                        if(fightover){
                            fightover=false;
                            if(bInWMfight || bInEMfight || bInCMfight) bInMainMenu=true; else if(bInDMfight && fightwin){ bInDungeon=true; displayDungeon(R, C); } else if(bInDMfight && !fightwin) bInMainMenu=true;
                            if(bInWMfight) bInWMfight=false; if(bInEMfight) bInEMfight=false; if(bInCMfight) bInCMfight=false; if(bInDMfight) bInDMfight=false;
                            updateStoredData(); updateGUIstatus(); updateLeaderboard(username.c_str(), lvl);
                        }

                    }
            }
                if(bInDungeon){
                    cout<<"2\n";
                    cout<<"\n";
                    cout<<"----------------------------------------\n";
                    char result;
                    result = dungeonMove(2);
                    dungeonResult(result, hwnd);
                }

            	if(bInShopE){//Armour Upgrade
				cout<<"2\n";
				cout<<"Are you sure you want to upgrade your Armour from level "<<armour<<" to "<<"level "<<armour+1;
				if( (armour+1)%10 != 0) cout<< " with "<<(armour+1)*100<<" coins";
				cout<<"?"<<" You have "<<coins<<" coins."<<"\n";
				cout<<"Press the Yes/No button"<<"\n"<<"\n";
				cout<< "Your response: ";
				bArmourYesNo=true;
				bInShopE=false;
			}
            	if(bInShopS){//Superior Willpower
                    cout<<"2\n";
                    if(lvl<10){
                        cout<<"Your level is too low!"<<"\n"<<"\n";
                        Shop::skill(smap);
                        playerRes();
                    }
                    else if(lvl>=10 && skill_2==0) {
                        cout<<"Are you sure you want to unlock Superior Willpower"<<" with "<<"1000"<<" coins?"<<" You have "<<coins<<" coins."<<"\n";
                        cout<<"Press the Yes/No button"<<"\n"<<"\n";
                        cout<< "Your response: ";
                    }
                    else if(skill_2>0&&skill_2<10){
                        cout<<"Are you sure you want to upgrade Superior Willpower from level "<<skill_2<<" to "<<"level "<<skill_2+1<< " with ";
                        cout<<skill2costs[skill_2]<<" coins?"<<" You have "<<coins<<" coins."<<"\n";
                        cout<<"Press the Yes/No button"<<"\n"<<"\n";
                        cout<< "Your response: ";
                    }
                    else if(skill_2>=10){
                        cout<<"Superior Willpower is already at max level!"<<"\n"<<"\n";
                        Shop::skill(smap);
                        playerRes();
                    }
                    if(lvl>=10 && skill_2<20) bSkill2YesNo=true;
                    if(lvl>=10 && skill_2<20) bInShopS=false;
            	}

				if(bInShopM){//Heal Pulse Upgrade
				cout<<"2\n";
				if(magic_healp2<10){

				if(magic_healp2==0) cout<<"Are you sure you want to unlock Heal Pulse Magic with 100k coins?"<<" You have "<<coins<<" coins."<<"\n";
	        	if(magic_healp2>0) cout<<"Are you sure you want to upgrade Heal Pulse Magic from level "<<magic_healp2<<" to "<<"level "<<magic_healp2+1
				<< " with "<<3+magic_healp2*2<<" Magic Essence?"<<" You have "<<magicpt<<" Magic Essence."<<"\n";
				if(magic_healp2>=10) cout<<"Heal Pulse Magic at is already Max Level!"<<"\n"<<"\n";
				cout<<"Press the Yes/No button"<<"\n"<<"\n";
				cout<< "Your response: ";
				is_magichp2yesno=true;
				bInShopM=false;
			}
				if(magic_healp2>=10) {
				cout<<"Heal Pulse Magic at is already Max Level!"<<"\n"<<"\n";
				Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
				playerRes();
			}
				}
                if(bInShopSM){//ArmourTier upgrade
                    cout<<"2\n";
                    cout<<"Are you sure you want to improve your Armour's Prestige Level from "; tierd(armourtier, 2);
                    cout<<" to "; tierd(armourtier, 2); cout<<" with "<<tcosts[armourtier]<<" Shiny Shards, "
                                                           <<tcosts2[armourtier]<<" Mysterious Shards, and "<<tcosts2[armourtier]<<" Crystal Shards?\n";
                    cout<<"Press the Yes/No button"<<"\n"<<"\n";
                    cout<< "Your response: ";
                    bArmourTierYesNo=true;
                    bInShopSM=false;
                }
                if(bInMonEn){
                    if(page<30){
                        page++; displayMonsterEn(page);
                    }
                }

			break;//ID_BUTTON2 case break
		}
			case ID_BUTTON3:{


		        if(bInShopE){//Shield upgrade

		            if(lvl>=5){
		                cout<<"3\n";
		                cout<<"Are you sure you want to upgrade your Shield from level "<<shield<<" to "<<"level "<<shield+1;
                        if( (shield+1)%5 != 0) cout<<" with "<<(shield+1)*750<<" coins";
                        cout<<"?"<<" You have "<<coins<<" coins."<<"\n";
		                cout<<"Press the Yes/No button"<<"\n"<<"\n";
		                cout<< "Your response: ";
		                is_shieldyesno=true;
		                bInShopE=false;
		            }

		            if(lvl<5){
			            cout<<"Your level is too low!"<<"\n"<<"\n";
			            Shop::equip(smap);
			            playerRes();
		            }

	            }
                if(bInShopSM){//ShieldTier upgrade
                    cout<<"3\n";
                    cout<<"Are you sure you want to improve your Shield's Prestige Level from "; tierd(shieldtier, 2);
                    cout<<" to "; tierd(shieldtier, 2); cout<<" with "<<tcosts[shieldtier]<<" Crystal Shards, "
                                                            <<tcosts2[shieldtier]<<" Mysterious Shards, and "<<tcosts2[shieldtier]<<" Shiny Shards?\n";
                    cout<<"Press the Yes/No button"<<"\n"<<"\n";
                    cout<< "Your response: ";
                    bShieldTierYesNo=true;
                    bInShopSM=false;
                }
			break;//ID_BUTTON3 case break
			}
			case ID_BUTTON4:{

                if(bInDungeon){
                    cout<<"4\n";
                    char result;
                    result = dungeonMove(4);
                    dungeonResult(result, hwnd);
                }
                if(bInMonEn){
                    int cnt=0;
                    while(page>1 && cnt<10){
                        page--; cnt++;
                    }
                    displayMonsterEn(page);
                }
				break;//ID_BUTTON4 case break

			}
			case ID_BUTTON5:{

				//cout<<"5\n";
                if(bInMonEn){
                    int cnt=0;
                    while(page<30 && cnt<10){
                        page++; cnt++;
                    }
                    displayMonsterEn(page);
                }
				break;//ID_BUTTON5 case break

			}
			case ID_BUTTON6:{

                if(bInDungeon){
                    cout<<"6\n";
                    char result;
                    result = dungeonMove(6);
                    dungeonResult(result, hwnd);
                }
				break;//ID_BUTTON6 case break

			}
			case ID_BUTTON7:{

				if(bInShopM){//Spirit Guide Upgrade/Buy
					cout<<"7\n";
					if(pet==0) cout<<"Are you sure you want to rise a Spirit Guide with 10 Magic Essence?"<<" You have "<<magicpt<<" Magic Essence."<<"\n";
	        		if(pet>0) cout<<"Are you sure you want to feed "<<petname<< " with "<< pet <<" Magic Essence?"<<" You have "<<magicpt<<" Magic Essence."<<"\n";
	        		cout<<"Press the Yes/No button"<<"\n"<<"\n";
					cout<< "Your response: ";
					is_petyesno=true;
					bInShopM=false;
				}
				break;//ID_BUTTON7 case break

			}
			case ID_BUTTON8:{

				if(bInShopM){//Spirit Guide Rename
					cout<<"8\n";
					cout<< "Your response: ";
					is_petnaming=true;
					bInShopM=false;
				}

                if(bInDungeon){
                    cout<<"8\n";
                    char result;
                    result = dungeonMove(8);
                    dungeonResult(result, hwnd);
                }

				break;//ID_BUTTON8 case break

			}
			case ID_BUTTON9:{

                if(bInMonEn){
                    bInMonEn=false;
                    bInMainMenu=true;
                    cout<<"\n\nYou closed the Monster Encyclopedia Book...\n\n";
                    updateGUIstatus();
                }

				if(bInShopE){
				    cout<<"9\n";
				    bInShopE=false;
				    bInMainMenu=true;
				    cout<<"\n\nExited Equipment Shop, back to Home...\n\n";
                    updateGUIstatus();
				}

				if(bInShopS){
				    cout<<"9\n";
				    bInShopS=false;
				    bInMainMenu=true;
				    cout<<"\n\nExited Skill Training Centre, back to Home...\n\n";
                    updateGUIstatus();
				}

				if(bInShopM){
				    cout<<"9\n";
				    bInShopM=false;
				    bInMainMenu=true;
				    cout<<"\n\nExited Magic Altar, back to Home...\n\n";
                    updateGUIstatus();
				}

				if(bInShopSM){
				    cout<<"9\n";
				    bInShopSM=false;
				    bInMainMenu=true;
				    cout<<"\n\nExited Smithing Shop, back to Home...\n\n";
                    updateGUIstatus();
				}

                if(bInShopC){
                    cout<<"9\n";
                    bInShopC=false;
                    bInMainMenu=true;
                    cout<<"\n\nExited Altar of Creation, back to Home...\n\n";
                    updateGUIstatus();
                }
				break;//ID_BUTTON9 case break
			}

			case ID_BUTTON10:{//Yes

		        if(bSwordYesNo){
		            bool sword10=( (sword+1)%10 == 0 );
		            if(coins<sword*100){
                        cout<<"Yes"<<"\n";
                        cout<<"\n"<<"You don't have enough coins!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
		            }

		            else if(coins>=sword*100){//enough coins
		                if(sword10){//material upgrade
		                    if(mWood<(sword+1)/2 || ironOre<((sword+1)/10)*3){
                                cout<<"Yes"<<"\n";
                                cout<<"\n"<<"You don't have enough materials!"<<"\n"<<"\n";
                                SleepTillNextSec();
                                Sleep(1000);
		                    }
		                    else{
                                cout<<"Yes"<<"\n";
                                coins-=sword*100;
                                mWood-=(sword+1)/2;
                                ironOre-=((sword+1)/10)*3;
                                sword++;
                                updateStoredData();
                                cout<<"Upgraded Sword from level "<<sword-1<<" to "<<"level "<<sword<<"!"<<"\n";
                                cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
                                cout<<'\a';
                                SleepTillNextSec();
                                Sleep(1000);
		                    }
		                }
		                else{//normal coin only upgrade
		                    cout<<"Yes"<<"\n";
                            coins-=sword*100;
		                    sword+=1;
		                    updateStoredData();
		                    cout<<"Upgraded Sword from level "<<sword-1<<" to "<<"level "<<sword<<"!"<<"\n";
		                    cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
		                    cout<<'\a';
		                    SleepTillNextSec();
		                    Sleep(1000);
		                }

	                }

	                bSwordYesNo=false;
	                bInShopE=true;
	                Shop::equip(smap);
	                playerRes();

	}

		        if(bArmourYesNo){
		            bool armour10=( (armour+1)%10 == 0 );
                    if(coins<armour*100){//not enough coins
                        cout<<"Yes"<<"\n";
                        cout<<"\n"<<"You don't have enough coins!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
                    }

                    else if(coins>=(armour+1)*100){//enough coins
                        if(armour10){//material upgrade
                            if(ironOre<(armour+1)/2){
                                cout<<"Yes"<<"\n";
                                cout<<"\n"<<"You don't have enough materials!"<<"\n"<<"\n";
                                SleepTillNextSec();
                                Sleep(1000);
                            }
                            else{
                                cout<<"Yes"<<"\n";
                                coins-=(armour+1)*100;
                                ironOre-=(armour+1)/2;
                                armour++;
                                updateStoredData();
                                cout<<"Upgraded Armour from level "<<armour-1<<" to "<<"level "<<armour<<"!"<<"\n";
                                php=getPlayerHP();
                                cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
                                cout<<'\a';
                                SleepTillNextSec();
                                Sleep(1000);
                            }
                        }
                        else{//normal coin only upgrade
                                cout<<"Yes"<<"\n";
                                coins-=(armour+1)*100;
                                armour++;
                                updateStoredData();
                                cout<<"Upgraded Armour from level "<<armour-1<<" to "<<"level "<<armour<<"!"<<"\n";
                                php=getPlayerHP();
                                cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
                                cout<<'\a';
                                SleepTillNextSec();
                                Sleep(1000);
                        }

                    }
                    bArmourYesNo=false;
	                bInShopE=true;
	                Shop::equip(smap);
	                playerRes();
	            }

		        if(is_shieldyesno){
                    bool shield5=( (shield+1)%5 == 0 );
                    if(coins<(shield+1)*750){//not enough coins
                        cout<<"Yes"<<"\n";
                        cout<<"\n"<<"You don't have enough coins!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
                    }

                    else if(coins>=(shield+1)*750){//enough coins
                        if(shield5){//material upgrade
                            if( oWood<((shield+1)/5)*2 || ironOre<((shield+1)/5)*2){
                                cout<<"Yes"<<"\n";
                                cout<<"\n"<<"You don't have enough materials!"<<"\n"<<"\n";
                                SleepTillNextSec();
                                Sleep(1000);
                            }
                            else{
                                cout<<"Yes"<<"\n";
                                coins-=(shield+1)*750;
                                oWood-=((shield+1)/5)*2;
                                ironOre-=((shield+1)/5)*2;
                                shield++;
                                updateStoredData();
                                cout<<"Upgraded Shield from level "<<armour-1<<" to "<<"level "<<armour<<"!"<<"\n";
                                cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
                                cout<<'\a';
                                SleepTillNextSec();
                                Sleep(1000);
                            }
                    }
                        else{//normal coin only upgrade
                            cout<<"Yes"<<"\n";
                            coins-=(shield+1)*750;
                            shield++;
                            updateStoredData();
                            cout<<"Upgraded Shield from level "<<shield-1<<" to "<<"level "<<shield<<"!"<<"\n";
                            cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
                            cout<<'\a';
                            SleepTillNextSec();
                            Sleep(1000);
                        }

                }
                    is_shieldyesno=false;
                    bInShopE=true;
                    Shop::equip(smap);
                    playerRes();
		            }


		        if(is_skillfa1yesno){
		            if(coins>=(skill_fa1+1)*(skill_fa1+1)*1000){
		                cout<<"Yes"<<"\n";
		                coins=coins-((skill_fa1+1)*(skill_fa1+1)*1000);
		                skill_fa1=skill_fa1+1;
		                updateStoredData();
                        if(skill_fa1==0) cout<<"Unlocked First Ace Skill!"<<"\n";
		                if(skill_fa1>0&&skill_fa1<5) cout<<"Upgraded First Ace Skill from level "<<skill_fa1-1<<" to level "<<skill_fa1<<"!"<<"\n";
		                cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
		                cout<<'\a';
		                SleepTillNextSec();
		                Sleep(1000);
		            }

	                else{
	    	            cout<<"Yes"<<"\n";
			            cout<<"\n"<<"You don't have enough coins!"<<"\n"<<"\n";
		            }
	                is_skillfa1yesno=false;
	                bInShopS=true;
	                Shop::skill(smap);
	                playerRes();
}

                if(bSkill2YesNo){

                    if(coins>=skill2costs[skill_2]){
                        cout<<"Yes"<<"\n";
                        coins-=skill2costs[skill_2];
                        skill_2++;
                        updateStoredData();
                        if(skill_2==0) cout<<"Unlocked Superior Willpower!"<<"\n";
                        else cout<<"Upgraded Superior Willpower from level "<<skill_2-1<<" to level "<<skill_2<<"!"<<"\n";
                        cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
                        cout<<'\a';
                        SleepTillNextSec();
                        Sleep(1000);
                    }
                    else{
                        cout<<"Yes"<<"\n";
                        cout<<"\n"<<"You don't have enough coins!"<<"\n"<<"\n";
                    }
                    bSkill2YesNo=false;
                    bInShopS=true;
                    Shop::skill(smap);
                    playerRes();
                }

		        if(is_magicfs1yesno){

		if(magic_fsword1>0&&magicpt>=magic_fsword1*5){

		cout<<"Yes"<<"\n";
		magicpt=magicpt-magic_fsword1*5;
		magic_fsword1=magic_fsword1+1;
		updateStoredData();

		cout<<"Upgraded Blaze Blade from level "<<magic_fsword1-1<<" to "<<"level "<<magic_fsword1<<"!"<<"\n";
		cout<<"You have "<<magicpt<<" Magic Essence left."<<"\n"<<"\n";

	}
		else if(magic_fsword1==0&&coins>=50000){
		cout<<"Yes"<<"\n";
		coins=coins-50000;
		magic_fsword1=magic_fsword1+1;
		updateStoredData();

		cout<<"Unlocked Blaze Blade!"<<"\n";
		cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
	}

	    else{
	    	cout<<"Yes"<<"\n";
			if(magic_fsword1==0) cout<<"You don't have enough coins!"<<"\n"<<"\n";
			if(magic_fsword1>0) cout<<"You don't have enough Magic Essence!"<<"\n"<<"\n";
		}

	cout<<'\a';
	SleepTillNextSec();
	Sleep(1000);
	is_magicfs1yesno=false;
	bInShopM=true;
	Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
	playerRes();
}

		        if(is_magichp2yesno){

		if(magic_healp2>0&&magicpt>=3+magic_healp2*2){

		cout<<"Yes"<<"\n";
		magicpt=magicpt-3-magic_healp2*2;
		magic_healp2=magic_healp2+1;
		updateStoredData();

		cout<<"Upgraded Heal Pulse Charm from level "<<magic_healp2-1<<" to "<<"level "<<magic_healp2<<"!"<<"\n";
		cout<<"You have "<<magicpt<<" Magic Essence left."<<"\n"<<"\n";

	}
		else if(magic_healp2==0&&coins>=100000){
		cout<<"Yes"<<"\n";
		coins=coins-100000;
		magic_healp2=magic_healp2+1;
		updateStoredData();

		cout<<"Unlocked Heal Pulse Charm!"<<"\n";
		cout<<"You have "<<coins<<" coins left."<<"\n"<<"\n";
	}

	    else{
	    	cout<<"Yes"<<"\n";
			if(magic_healp2==0) cout<<"You don't have enough coins!"<<"\n"<<"\n";
			if(magic_healp2>0) cout<<"You don't have enough Magic Essence!"<<"\n"<<"\n";
		}

	cout<<'\a';
	SleepTillNextSec();
	Sleep(1000);
	is_magichp2yesno=false;
	bInShopM=true;
	Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
	playerRes();
}

		        if(is_petyesno){
			cout<<"Yes"<<"\n";
			if(pet>0&&magicpt>=pet){

		magicpt-=pet;

        x = rand()%100;
        if(x>=0&&x<=29){
       	pet++;
		cout<<"Success! Upgraded "<<petname<<" from level "<<pet-1<<" to "<<"level "<<pet<<"!"<<"\n";
		cout<<"You have "<<magicpt<<" Magic Essence left."<<"\n"<<"\n";
		sound(1);
	}
		else{
		cout<<petname<<" did not grow..."<<"\n";
		cout<<"You have "<<magicpt<<" Magic Essence left."<<"\n"<<"\n";
		cout<<'\a';
		}
		updateStoredData();
		SleepTillNextSec();
		Sleep(1000);
		is_petyesno=false;
		bInShopM=true;
		Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
		playerRes();
	}
		else if(pet==0&&magicpt>=10){
		magicpt=magicpt-10;
        pet++;
        updateStoredData();
		cout<<"You rose a Spirit Guide!"<<"\n";
		cout<<"You have "<<magicpt<<" Magic Essence left."<<"\n"<<"\n";
		cout<<"----------------------------------------"<<"\n";
		cout<<'\a';
		cout<<"Name your Spirit Guide! (Use the textbox on the control panel, not more than 50 characters)"<<"\n";
		cout<< "Your response: ";
		is_petyesno=false;
		is_petnaming=true;
		}

		else{
	    	cout<<"You don't have enough Magic Essence!"<<"\n"<<"\n";
	    	cout<<'\a';
	    	SleepTillNextSec();
			Sleep(1000);
			is_petyesno=false;
			bInShopM=true;
			Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
			playerRes();
		}

}

		        if(bSwordTierYesNo){
                    cout<<"Yes"<<"\n";
                    if(mShards>=tcosts[swordtier] && sShards>=tcosts2[swordtier] && cShards>=tcosts2[swordtier]){
                        mShards-=tcosts[swordtier]; sShards-=tcosts2[swordtier]; cShards-=tcosts2[swordtier];
                        swordtier++;
                        if(swordtier==5) skillFB=1;
                        cout<<"Prestiged Sword from "; tierd(swordtier-1, 2); cout<<" to "; tierd(swordtier, 2); cout<<"!"<<"\n";
                        Beep(1000,1000); sound(1);
                        updateStoredData();
                        SleepTillNextSec();
                    }
                    else{
                        cout<<"\n"<<"You don't have enough Shards!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
                    }
                    bSwordTierYesNo=false;
                    bInShopSM=true;
                    Shop::smith(smap);
                    playerRes();
                }

                if(bArmourTierYesNo){
                    cout<<"Yes"<<"\n";
                    if(sShards>=tcosts[armourtier] && mShards>=tcosts2[armourtier] && cShards>=tcosts2[armourtier]){
                        sShards-=tcosts[armourtier]; mShards-=tcosts2[armourtier]; cShards-=tcosts2[armourtier];
                        armourtier++;
                        if(armourtier==5) skillSM=1;
                        cout<<"Prestiged Armour from "; tierd(armourtier-1, 2); cout<<" to "; tierd(armourtier, 2); cout<<"!"<<"\n";
                        Beep(1000,1000); sound(1);
                        updateStoredData();
                        SleepTillNextSec();
                    }
                    else{
                        cout<<"\n"<<"You don't have enough Shards!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
                    }
                    bArmourTierYesNo=false;
                    bInShopSM=true;
                    Shop::smith(smap);
                    playerRes();
                }

                if(bShieldTierYesNo){
                    cout<<"Yes"<<"\n";
                    if(cShards>=tcosts[shieldtier] && mShards>=tcosts2[shieldtier] && sShards>=tcosts2[shieldtier]){
                        cShards-=tcosts[shieldtier]; mShards-=tcosts2[shieldtier]; sShards-=tcosts2[shieldtier];
                        shieldtier++;
                        if(shieldtier==5) skillGG=1;
                        cout<<"Prestiged Shield from "; tierd(shieldtier-1, 2); cout<<" to "; tierd(shieldtier, 2); cout<<"!"<<"\n";
                        Beep(1000,1000); sound(1);
                        updateStoredData();
                        SleepTillNextSec();
                    }
                    else{
                        cout<<"\n"<<"You don't have enough Shards!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
                    }
                    bShieldTierYesNo=false;
                    bInShopSM=true;
                    Shop::smith(smap);
                    playerRes();
                }

                if(bItemCreateIYesNo){
                    cout<<"Yes"<<"\n";
                    if(pyrogems>=5){
                        pyrogems-=5;
                        cout<<"And you got...\n";
                        Beep(1000,1000); sound(1);
                        itemCreate(1);
                        updateStoredData();
                        SleepTillNextSec();
                    }
                    else{
                        cout<<"\n"<<"You don't have enough Pyrogems!"<<"\n"<<"\n";
                        SleepTillNextSec();
                        Sleep(1000);
                    }
                    bItemCreateIYesNo=false;
                    bInShopC=true;
                    Shop::create(smap);
                    playerRes();
                }



break;//ID_BUTTON10 case break
}



			case ID_BUTTON11:{//No

				if(bSwordYesNo){
				bSwordYesNo=false;
				bInShopE=true;
				cout<<"No"<<"\n";
				cout<<"Back to shop..."<<"\n"<<"\n";
				Sleep(1000);
				Shop::equip(smap);
				playerRes();
				}
				if(bArmourYesNo){
				bArmourYesNo=false;
				bInShopE=true;
				cout<<"No"<<"\n";
				cout<<"Back to shop..."<<"\n"<<"\n";
				Sleep(1000);
				Shop::equip(smap);
				playerRes();
				}
				if(is_shieldyesno){
				is_shieldyesno=false;
				bInShopE=true;
				cout<<"No"<<"\n";
				cout<<"Back to shop..."<<"\n"<<"\n";
				Sleep(1000);
				Shop::equip(smap);
				playerRes();
				}
				if(is_skillfa1yesno){
				is_skillfa1yesno=false;
				bInShopS=true;
				cout<<"No"<<"\n";
				cout<<"Back to shop..."<<"\n"<<"\n";
				Sleep(1000);
				Shop::skill(smap);
				playerRes();
				}
                if(bSkill2YesNo){
                    bSkill2YesNo=false;
                    bInShopS=true;
                    cout<<"No"<<"\n";
                    cout<<"Back to shop..."<<"\n"<<"\n";
                    Sleep(1000);
                    Shop::skill(smap);
                    playerRes();
                }
				if(is_magicfs1yesno){
				is_magicfs1yesno=false;
				bInShopM=true;
				cout<<"No"<<"\n";
				cout<<"Back to shop..."<<"\n"<<"\n";
				Sleep(1000);
				Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
				playerRes();
				}
				break;//ID_BUTTON11 case break

			}

			case ID_BUTTON12:{//Enter textbox text
			PSTR pMem;
			int nTextLen = GetWindowTextLength(hTextBox);
			pMem = (PSTR)VirtualAlloc((LPVOID)NULL, (DWORD)(nTextLen + 1), MEM_COMMIT, PAGE_READWRITE);
			GetWindowText(hTextBox, pMem, nTextLen + 1);
			if(is_petnaming){
				string text1=pMem;
				petname="";
				for(int i=0; i<50; i++){
					if(i>=nTextLen) break;
					petname+=text1[i];
				}
				updateStoredData();
				cout<<"Petaname entered: "<<pMem<<"\n";
				MessageBox(hwnd, "Pet sucessfully named/renamed", "Text Entered", MB_ICONINFORMATION);
				is_petnaming=false;
				bInShopM=true;
				Shop::magic(coins,magicpt, magic_fsword1, magic_healp2, pet, petname);
				playerRes();
		}
                if(bInRedeemCode){
                    string text1=pMem;
                    code = "";
                    for(int i=0; i<6; i++){
                        if(i>=nTextLen) break;
                        code+=text1[i];
                    }
                    cout<<"Code entered: "<<pMem<<"\n";
                    redeem r = redeemCode(code.c_str(), username.c_str(), hwnd);
                    if(r.valid){
                        MessageBox(hwnd, "Redeem Success", "Text Entered", MB_ICONINFORMATION);
                        textc(14);
                        cout<<"You got "<<r.amt;
                        if(strcmp(r.type.c_str(), "coins") == 0){
                            cout<<" coins!\n"; textc(10);
                            coins += r.amt;
                            updateStoredData();
                        }
                        if(strcmp(r.type.c_str(), "magicpt") == 0){
                            cout<<" Magic Essence!\n"; textc(10);
                            magicpt += r.amt;
                            updateStoredData();
                        }
                        if(strcmp(r.type.c_str(), "pyrogems") == 0){
                            cout<<" Pyrogems!\n"; textc(10);
                            pyrogems += r.amt;
                            updateStoredData();
                        }
                    }
                    else{

                    }
                    bInRedeemCode = false;
                    bInMainMenu = true;
                    updateGUIstatus();
                }
			break;//ID_BUTTON12 case break
			}

	}
			break;

		}


		case WM_DESTROY: {
            pushLoadedMap(smap,id_map,itemID);
            updateDatabase(petname.c_str(), username.c_str());
			PostQuitMessage(0);
			break;
		}
		case WM_CLOSE:{
            if(MessageBox(hwnd, "Do you want to exit the game?", "Confirmation Message", MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
                DestroyWindow(hwnd);
            return 0;
     }

		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}




/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */

	MSG msg; /* A temporary location for all messages */
    LoadMenuA(hInstance, MAKEINTRESOURCEA(3) );


	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);

	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
    HICON hIcon = (HICON)LoadImage(hInstance, "MMGicon.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE); //load icon
    wc.hbrBackground = hBrushBlack;
	wc.lpszClassName = "WindowClass";
    wc.hIcon		 = hIcon;
    wc.hIconSm		 = hIcon;
    //or do SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

    //maximize window
    SetConsoleTitle("Monster Melancholy v2.0.0");
    hwnd = FindWindow(NULL, "Monster Melancholy v2.0.0");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
    SetConsoleScreenBufferSize(hOut, NewSBSize);
    DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
    ShowWindow(hwnd, SW_MAXIMIZE);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	 hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Monster Melancholy Game Control Panel",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,  //x
		CW_USEDEFAULT,  //y
		640,  //width
		480, //height
		NULL,NULL,hInstance,NULL);



    if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    /*
        This is the heart of our program where all input is processed and
        sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
        this loop will not produce unreasonably high CPU usage
    */
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}



