using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
string const tnames[6]={"None", "Sapphire", "Emerald", "Ruby", "Diamond", "Monstronium"};
string const tnames2[6]={"Normal", "Sapphire", "Emerald", "Ruby", "Diamond", "Monstronium"};
int const tcosts[5]={3,5,9,14,23};
int const tcosts2[5]={1,2,3,5,7};
int const tsword[6]={0,15,35,65,100,155};
int const tarmour[6]={0,35,85,160,255,385};
int const tshield[6]={0,5,14,27,38,53};
int const skill2costs[10]={1000, 4500, 9500, 15000, 20000, 26500, 30000, 34000, 41500, 50000};
int const SWdamage[11]={0,2,6,12,20,30,42,56,72,90,110};
#define cWhite 1
namespace MHGtextDisplay{

    void static textc(int x){
        SetConsoleTextAttribute(hConsole, x); // 1=white, 7=white, 8=grey, 9=dark blue, 10=light green, 11=aqua, 12=red, 13=magenta, 14=gold, 15=brightest white
    }

    string static numd(int x){
        string str1="", ReturnStr="";

        if(x<10000) return to_string(x);

        if(x>=10000&&x<=99999){
            str1=to_string(x);
            for(int i=0;i<2;i++) ReturnStr += str1[i];
            ReturnStr += '.';
            ReturnStr += str1[2];
            ReturnStr += 'k';
            return ReturnStr;
        }
        if(x>=100000&&x<=999999){
            str1=to_string(x);
            for(int i=0;i<3;i++) ReturnStr += str1[i];
            ReturnStr += 'k';
            return ReturnStr;
        }
        if(x>=1000000&&x<=9999999){
            str1=to_string(x);
            ReturnStr += str1[0];
            ReturnStr += '.';
            for(int i=1;i<3;i++) ReturnStr += str1[i];
            ReturnStr += 'M';
            return ReturnStr;
        }

        if(x>=10000000&&x<=29000000){
            str1=to_string(x);
            for(int i=0;i<2;i++) ReturnStr += str1[i];
            ReturnStr += '.';
            ReturnStr += str1[2];
            ReturnStr += 'M';
            return ReturnStr;
        }
        ReturnStr = "ValueOutOfRange";
        return ReturnStr;
    }

    void static mPic(int x){
        switch (x){
            case 0:{
                cout << "     __________     " << "\n";
                cout << "    / _      _ \\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\__\\  /__/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   __   /  " << "\n";
                cout << "       '.__.'    " << "\n" << "\n";
                break;
            }
            case 7:{
                cout << "     __________     " << "\n";
                cout << "    / \\      / \\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\_E\\  /E_/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   __   /  " << "\n";
                cout << "       '.__.'    " << "\n" << "\n";
                break;
            }
            case 1:{
                cout << "      ________      " << "\n";
                cout << "     / ______ \\     " << "\n";
                cout << "    / ________ \\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\_$\\  /$_/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   ()   /  " << "\n";
                cout << "       '.__.'    " << "\n" << "\n";
                break;
            }
            case 8:{
                cout << "      ________      " << "\n";
                cout << "     / ______ \\     " << "\n";
                cout << "    / ________ \\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\$$\\  /$$/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\ $ () $ /  " << "\n";
                cout << "       '.__.'    " << "\n" << "\n";
                break;
            }


            case 2:{
                cout << "      ,,," << "\n";
                cout << R"(       \\\ )" << "\n";
                cout << " .---. ///" << "\n";
                cout << "(:::::)(_)():" << "\n";
                cout << R"( `---' \\\)" << "\n";
                cout << "      ///" << "\n";
                cout << "     '''" << "\n" << "\n";
                break;
            }
            case 9:{
                cout << "      /      \\       " << "\n";
                cout << "    \\  \\  ..  /  /  " << "\n";
                cout << "     '-.`\\()/`.-'   " << "\n";
                cout << "    .--_'(  )'_--.   " << "\n";
                cout << R"(   / /` /`''`\ `\ \  )" << "\n";
                cout << "    |  |  ><  |  |     " << "\n";
                cout << "    \\  \\  XX  /  /   " << "\n";
                cout << "        '.__.'          " << "\n" << "\n";
                break;
            }


            case 3:{
                cout << "      ________      " << "\n";
                cout << "     /        \\     " << "\n";
                cout << "    /__________\\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\_O\\  /O_/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   \\/   /  " << "\n";
                cout << "       ^.__.^    " << "\n" << "\n";
                break;
            }
            case 10:{
                cout << "        ____     " << "\n";
                cout << "       /    \\  " << "\n";
                cout << "      /  -   \\" << "\n";
                cout << "     / -    - \\     " << "\n";
                cout << "    /__________\\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\_6\\  /8_/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   /\\   /  " << "\n";
                cout << "       ^.__.^    " << "\n" << "\n";
                break;
            }

            case 4:{
                cout << "     __________     " << "\n";
                cout << "    / _      _ \\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\_x\\  /x_/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   []   /  " << "\n";
                cout << "       '.__.'    " << "\n" << "\n";
                break;
            }
            case 11:{
                cout << "     __________     " << "\n";
                cout << "    / /      \\ \\   " << "\n";
                cout << "    |___    ___|  " << "\n";
                cout << "    |\\_X\\  /X_/|  " << "\n";
                cout << "    \\    ||    /  " << "\n";
                cout << "     \\   []   /  " << "\n";
                cout << "       '.__.'    " << "\n" << "\n";
                break;
            }

            case 5:{
                cout << " _________         .    . " << "\n";
                cout << "(..       \\_    ,  |\\  /| " << "\n";
                cout << R"( \       O  \  /|  \ \/ / )" << "\n";
                cout << R"(  \______    \/ |   \  /  )" << "\n";
                cout << "     vvvv\\    \\ |   /  |  " << "\n";
                cout << "    \\^^^^  ==   \\_/   |   " << "\n";
                cout << "      `\\_   ===    \\.  |  " << "\n";
                cout << "      / /\\_   \\ /      |  " << "\n";
                cout << "      |/   \\_  \\|      /  " << "\n";
                cout << "             \\________/   " << "\n" << "\n";
                break;
            }
            case 12:{
                cout << " _________         .    . " << "\n";
                cout << "(..      /\\_    ,  |\\  /| " << "\n";
                cout << R"( \       0  \  /|  \ \/ / )" << "\n";
                cout << R"(  \______    \/ |   \  /  )" << "\n";
                cout << "    vvvvv\\    \\ |   /  |  " << "\n";
                cout << "   \\^^^^^  ==   \\_/    |   " << "\n";
                cout << "    ``\\_   ===    \\.   |  " << "\n";
                cout << "      / /\\_   \\ /      |  " << "\n";
                cout << "      |/   \\_  \\|      /  " << "\n";
                cout << "             \\________/   " << "\n" << "\n";
                break;
            }

            case 6:{
                cout << "     _________   " << "\n";
                cout << "    |    |    \\  " << "\n";
                cout << "     \\   /  ^ |  " << "\n";
                cout << "    / \\_/   O  \\ " << "\n";
                cout << "   /            \\ " << "\n";
                cout << "  /    ____      0 " << "\n";
                cout << " /      /  \\___ _/ " << "\n" << "\n";
                break;
            }
            case 13:{
                cout << "     ________   " << "\n";
                cout << "    |    |   \\  " << "\n";
                cout << R"(     \   /  \ \  )" << "\n";
                cout << "    / \\_/   {} \\ " << "\n";
                cout << "   /            \\ " << "\n";
                cout << "  /    ____      0 " << "\n";
                cout << " /      /  \\___ _/ " << "\n" << "\n";
                break;
            }

            case 14:{
                cout << "     ________   " << "\n";
                cout << "    |        |  " << "\n";
                cout << "    | ______ |  " << "\n";
                cout << "    | __  __ |  " << "\n";
                cout << "    | |0|_|0||  " << "\n";
                cout << "    |   | |  |  " << "\n";
                cout << "    |___| |__|  " << "\n";
                cout << "                " << "\n" << "\n";
                break;
            }
            case 15:
                cout<<  "      _______     "<<"\n";
                cout<<R"( /\  /   ==   \  /\     ___)"<<"\n";
                cout<<R"(|0\ |  .    .  |/0|   <|__|>)"<<"\n";
                cout<<R"( \  |    / \   |  /    | |)"<<"\n";
                cout<<R"(    |  {/|_|\} |       / \)"<<"\n";
                cout<<  "    |__________|       |_|"<<"\n" <<"\n";
                break;

            default:{}
        }
    }

    void SleepTillNextSec(){
        int t = time(nullptr);
        while( time(nullptr) - t == 0) Sleep(50); //check if its the next second every 0.05 seconds
    }

    void playerRes(){
        cout<< "Your response: ";
    }

    void static youwin(){
        textc(11);
        cout<<"__  __                 ___       ______         "<<"\n";
        cout<<"_ \\/ /_________  __    __ |     / /__(_)______  "<<"\n";
        cout<<"__  /_  __ \\  / / /    __ | /| / /__  /__  __ \\ "<<"\n";
        cout<<"_  / / /_/ / /_/ /     __ |/ |/ / _  / _  / / / "<<"\n";
        cout<<"/_/  \\____/\\__,_/      ____/|__/  /_/  /_/ /_/  "<<"\n"<<"\n";
    }

    void static youdied(){
        textc(12);
        cout<<"__   __          ___  _        _ "<<"\n";
        cout<<R"(\ \ / /__ _  _  |   \(_)___ __| | )"<<"\n";
        cout<<" \\ V / _ \\ || | | |) | / -_) _` |"<<"\n";
        cout<<R"(  |_|\___/\_,_| |___/|_\___\__,_|)"<<"\n"<<"\n";
    }

    void static tierd(int x, int type){
        switch(x){
            case 0:
                break;
            case 1:
                textc(9);
                break;
            case 2:
                textc(2);
                break;
            case 3:
                textc(12);
                break;
            case 4:
                textc(11);
                break;
            case 5:
                textc(13);
                break;
            default:
                break;
        }
        if(type == 1) cout<<tnames[x];
        if(type == 2) cout<<tnames2[x];
        textc(10);
    }

    void static textd(const char txt[], int speed, int colour) {//colour is 10 for green (deflaut)
        int i = 0;
        textc(colour);
        while (i <= strlen(txt)) {
            cout << txt[i];
            for (int j = 0; j < speed * 5000000; j++) {}
            i++;
        }
    }

    void static monText(int MonID, int atk, string monName){
        int random;
        if(MonID==0 || MonID==7){
            random = rand()%2;
            if(random==0) cout<<monName<<" punched you right in the face, dealing "<< atk << " damage. Ouch!\n";
            if(random==1) cout<<monName<<" wacked you hard, dealing "<< atk << " damage. Ouch!\n";
        }
        if(MonID==1 || MonID==8){
            random = rand()%2;
            if(random==0) cout<<monName<<" knocked your head, dealing "<< atk << " damage. Hope that made you smarter!\n";
            if(random==1) cout<<monName<<" slapped your cheek, dealing "<< atk << " damage. Owie!\n";
        }
        if(MonID==2 || MonID==9){
            random = rand()%2;
            if(random==0) cout<<monName<<" bit you, dealing "<< atk << " damage. Just an ant bite!\n";
            if(random==1) cout<<monName<<" tickled you, dealing "<< atk << " damage. Tickle torture!\n";
        }
        if(MonID==3 || MonID==10){
            random = rand()%2;
            if(random==0) cout<<monName<<" threw a fireball at you, dealing "<< atk << " burn damage. Hot!\n";
            if(random==1) cout<<monName<<" threw a snowball at you, dealing "<< atk << " frostbite damage. Brrrrrrrr cold...\n";
        }
        if(MonID==4 || MonID==11){
            random = rand()%2;
            if(random==0) cout<<monName<<" punched you right in the face, dealing "<< atk << " damage. Ouch!\n";
            if(random==1) cout<<monName<<" wacked you hard, dealing "<< atk << " damage. Ouch!\n";
        }
        if(MonID==5 || MonID==12){
            random = rand()%2;
            if(random==0) cout<<monName<<" closed its jaw on you, dealing "<< atk << " damage. Ouch!\n";
            if(random==1) cout<<monName<<" body-slammed you, dealing "<< atk << " damage. Oof!\n";
        }
        if(MonID==6 || MonID==13){
            random = rand()%2;
            if(random==0) cout<<monName<<" bit you, dealing "<< atk << " damage. You must be yummy!\n";
            if(random==1) cout<<monName<<" scratched you, dealing "<< atk << " damage. How cute!\n";
        }
        if(MonID==14){
            random = rand()%8;
            switch(random) {
                case 0: cout << monName << " kicked you to the moon, dealing " << atk << " damage. Byeeeeeee!\n"; break;
                case 1: cout << monName << " pummeled you, dealing " << atk << " damage. Painful!\n"; break;
                case 2: cout << monName << " flung you 1km high, dealing you " << atk << " fall damage when you hit the ground.\n"; break;
                case 3: cout << monName << " sat on you, dealing " << atk << " squish damage.\n"; break;
                case 4: cout << monName << " headbutted you, dealing " << atk << " hard-head damage.\n"; break;
                case 5: cout << monName << " threw you like a basketball, dealing " << atk << " bounce damage.\n"; break;
                case 6: cout << monName << " gave you an eye-sore by looking at you, dealing " << atk << " stare damage to you.\n"; break;
                case 7: cout << monName << " dripped lava onto you, dealing " << atk << " burn damage. Hot!\n"; break;
            }
        }
        if(MonID==15){
            random = rand()%8;
            cout<<"Ogre placeholder text"<< atk <<"damage \n";
        }
    }

    void static viewProfile(map <string,int> s, string petname, int prefix[110], int xpToLevelUp[110], int php){
        char const coinS = 232;
        textc(10);
        cout<<"\n";
        cout<<"----------------------------------------\n";
        cout<< "[Stats]\n";
        cout<< "Level: "<< s["lvl"] <<"\t"; cout<< "Exp to Next Level: "<< s["xp"] << "/" << xpToLevelUp[s["lvl"]] << "\n";
        cout<< "Total Experience: "<< prefix[s["lvl"]-1] + s["xp"] <<"\n";
        cout<< "Campaign Stage: "<<s["cStage"]<<"\n";
        cout<< "Coins: "<< coinS << " " << numd( s["coins"] )<<"\n";
        cout<<"----------------------------------------\n";
        cout<< "[Combat Stats]\n";
        cout<< "Armour ("; tierd(s["armourtier"],2); cout<<"): Level "<< s["armour"] <<" (HP +"<< s["armour"]*5 + tarmour[s["armourtier"]]<<")\n";
        cout<< "Sword ("; tierd(s["swordtier"],2); cout<<"): Level "<< s["sword"] << " (Damage +" << s["sword"]*2 + tsword[s["swordtier"]]<< ")\n";
        cout<< "Shield ("; tierd(s["shieldtier"],2); cout<<"): Level "<< s["shield"] <<" (Defence +"<< s["shield"]*2 <<")\n";
        cout<< "HP Bonus based on level: "<< "+" << (s["lvl"]/5)*10 << " HP\n";
        cout<< "Damage Bonus based on level: "<< "+" << s["lvl"]*2 << " damage\n";
        cout<< "(Skills)\n";
        cout<< "First Ace: Level "<<s["skill_fa1"]<<" (First attack damage +"<<s["skill_fa1"]*15<<"%)\n";
        cout<< "(Magic)\n";
        cout<< "Blaze Sword: Level "<<s["magic_fsword1"]<<" (Burn damage +"<<s["magic_fsword1"]*25<<")\n";
        if(s["magic_healp2"]>0)cout<< "Heal Pulse: Level "<<s["magic_healp2"]<<" (Heal chance: "<<10+s["magic_healp2"]*2<<"%)\n";
        if(s["magic_healp2"]==0)cout<< "Heal Pulse: Level "<<s["magic_healp2"]<<" (Heal chance: 0%)\n";
        cout<< "Spirit Guide: ("<<petname<<") Level "<<s["pet"]<<"\n";
        cout<<"(Summary)"<<"\n";
        cout<< "Total Base HP: "<< php <<"\t"; cout<< "Total Base Damage: "<< s["sword"]*3+s["lvl"] <<"\n";
        cout<< "Total Base Defence: "<<s["shield"]*2<<"\n";
        cout<< "Wild Monsters Hunted: " << s["mcnt"] <<"\t"; cout<< "Elite Monsters Hunted: " << s["emcnt"] <<"\n";
        cout<< "Dungeons Explored: "<< s["dcnt"]<<"\t"; cout<< "Dungeon Monsters Hunted: " << s["dmcnt"] <<"\n\n";
        cout<< "You are now back Home"<<"\n\n";
    }

    void static displayCredits(){
        cout<<"By HCI Pro-Ductions\n";
        cout<<"Lead Programmer: Alrik\n";
        cout<<"Server Hosting: Xuyuan\n";
        cout<<"Honourable Mentions:\n";
        cout<<"Ogre Text Art: Junjie\n";
        cout<<"Ideas: From The Community\n";
        cout<<"A few of the text art from: https://www.asciiart.eu/\n";
    }

    void static textDisplayInv(map<string,int> r){
        cout<<"\n[Inventory]\n";
        cout<<"<Return Home to store items in Inventory into your Item Chest>\n";
        map<string, int>::iterator it;
        for(it=r.begin(); it!=r.end(); it++){
            cout<<it->first<<": ";
            if(strcmp(it->first.c_str(),"mWood") == 0) cout<<"Maple Wood: "<<it->second;
            else if(strcmp(it->first.c_str(),"oWood") == 0) cout<<"Oak Wood: "<<it->second;
            else if(strcmp(it->first.c_str(),"ironOre") == 0) cout<<"Iron Ore: "<<it->second;
            else if(strcmp(it->first.c_str(),"magicpt") == 0) cout<<"Magic Essence: "<<it->second;
            else if(strcmp(it->first.c_str(),"pyrogems") == 0) cout<<"Pyrogems: "<<it->second;
            else if(strcmp(it->first.c_str(),"mShards") == 0) cout<<"Mysterious Shards: "<<it->second;
            else if(strcmp(it->first.c_str(),"sShards") == 0) cout<<"Shiny Shards: "<<it->second;
            else if(strcmp(it->first.c_str(),"cShards") == 0) cout<<"Crystal Shards: "<<it->second;
            else if(strcmp(it->first.c_str(),"snowballs") == 0) cout<<"Snowballs: "<<it->second;
            cout<<"\n";
        }
        if(r.empty()) cout<<"Inventory is Empty!\n";
        cout<<"\n";
    }

    void static displayChest(map<string, int> s){
        cout<<"[Item Chest]\n";
        cout<<"<Your Item Chest at Home that safely stores all of your items>\n";
        if(s["mWood"]!=0) cout<<"Maple Wood: "<<s["mWood"]<<"\n";
        if(s["oWood"]!=0) cout<<"Oak Wood: "<<s["oWood"]<<"\n";
        if(s["ironOre"]!=0) cout<<"Iron Ore: "<<s["ironOre"]<<"\n";
        if(s["magicpt"]!=0) cout<<"Magic Essence: "<<s["magicpt"]<<"\n";
        if(s["pyrogems"]!=0) cout<<"Pyrogems: "<<s["pyrogems"]<<"\n";
        if(s["mShards"]!=0) cout<< "Mysterious Shards: "<<s["mShards"]<<"\n";
        if(s["sShards"]!=0) cout<< "Shiny Shards: "<<s["sShards"]<<"\n";
        if(s["cShards"]!=0) cout<< "Crystal Shards: "<<s["cShards"]<<"\n";
        if(s["snowballs"]!=0) cout<< "Snowballs: "<<s["snowballs"]<<"\n";
    }

    class Shop{
        char const static coinS = 232;

        public:
            void static equip(map<string,int> s) {
                int coins=s["coins"], lvl=s["lvl"],sword=s["sword"], armour=s["armour"], shield=s["shield"];
                int mWood=s["mWood"], oWood=s["oWood"], ironOre=s["ironOre"];
                bool sword10=false, armour10=false, shield5=false;
                if( (sword+1)%10 == 0) sword10=true; if( (armour+1)%10 == 0) armour10=true; if( (shield+1)%5 == 0) shield5=true;
                cout<<"[Equipment Shop]"<<"\n";
                cout<<"Coins: "<<coinS<<" "<< coins <<"\n"<<"\n";
                cout<<"Materials: "<<mWood<<" Maple Wood  "<<oWood<<" Oak Wood  "<<ironOre<<" Iron Ore\n";
                cout<< "What do you want to upgrade?"<<"\n"<<"\n";
                cout<<"Sword: Level "<< sword <<"-->"<<sword+1/*<<"\t Increase your damage!" */<<"\n";
                cout<<"Damage +"<<sword*2<<" --> +"<<(sword+1)*2<<" (+2)"<<"\n";
                cout<<"Upgrade cost: "<<coinS<<" "<< numd(sword*100);
                if(sword10) cout<<", "<<(sword+1)/2<<" Maple Wood, "<<((sword+1)/10)*3<<" Iron Ore\n";
                cout<< " {Press 1 to upgrade}\n\n";
                cout<<"Armour: Level "<< armour <<"-->"<<armour+1/*<<"\t Increase your HP!" */<<"\n";
                cout<<"HP +"<<armour*5<<" --> +"<<(armour+1)*5<<" (+5)"<<"\n";
                cout<<"Upgrade cost: "<<coinS<<" "<< numd((armour+1)*100);
                if(armour10) cout<<", "<<(armour+1)/2<<" Iron Ore\n";
                cout<< " {Press 2 to upgrade}\n\n";
                if(lvl<5) cout<<"Shield: Locked Min. Exp Level 5 needed."<<"\n"<<"\n";
                if(lvl>=5){
                    cout<<"Shield: Level "<< shield <<"-->"<<shield+1<<"\t Increase your Defence!" <<"\n";
                    cout<<"Defence +"<<shield*2<<" --> +"<<(shield+1)*2<<" (+2)"<<"\n";
                    cout<<"Upgrade cost: "<<coinS<<" "<< numd((shield+1)*750);
                    if(shield5) cout<<", "<<((shield+1)/5)*2<<" Oak Wood, "<<((shield+1)/5)*2<<" Iron Ore\n";
                    cout<< " {Press 3 to upgrade}\n\n";
                }
                cout<<"Press 9 to exit shop"<<"\n"<<"\n";
            }

            void static skill(map<string,int> s){
                int coins=s["coins"], skill_fa1=s["skill_fa1"], skill_2=s["skill_2"], lvl=s["lvl"];
                int skillFB=s["skillFB"], skillSM=s["skillSM"], skillGG=s["skillGG"];
                cout<<"[Skill Training Centre]"<<"\n";
                cout<<"Coins: "<<coinS<<" "<< coins <<"\n"<<"\n";
                cout<< "Which skill do you want to train?"<<"\n"<<"\n";
                if(skill_fa1==0){
                    cout<<"First Ace: Locked"<<"\t Increases the damage of your first attack of each round!" <<"\n";
                    cout<<"Unlock cost: "<<coinS<<" "<<"1000  First hit damage +0% --> +15% (+15%) {Press 1 to unlock}"<<"\n"<<"\n";
                }
                if(skill_fa1>0&&skill_fa1<5){
                    cout<<"First Ace: Level "<<skill_fa1<<"/5"<<"\t Increases the damage of your first attack of each round!" <<"\n";
                    cout<<"Upgrade cost: "<<coinS<<" "<<numd((skill_fa1+1)*(skill_fa1+1)*1000) <<" First hit damage +"<<skill_fa1*15<<"% --> +"
                        <<(skill_fa1+1)*15<<"% (+15%)"<<" {Press 1 to upgrade}"<<"\n"<<"\n";
                }
                if(skill_fa1==5) cout<<"First Ace: Max Level  First hit damage +75%"<<"\t Increases the damage of your first attack of each round!" <<"\n"<<"\n";

                if(skill_2==0 && lvl<15){
                    cout<<"Superior Willpower: Locked"<<"\t Increases damage vs Elite Monsters." <<"\n";
                    cout<<"(Reach Level 15 to be able to unlock this skill)"<<"\n"<<"\n";
                }

                if(skill_2==0 && lvl>=15){
                    cout<<"Superior Willpower: Locked"<<"\t Increases damage vs Elite Monsters." <<"\n";
                    cout<<"Unlock cost: "<<coinS<<" "<<skill2costs[skill_2]<<"  Damage vs Elite +0% --> +2% (+2%) {Press 2 to unlock}"<<"\n"<<"\n";
                }

                if(skill_2>0&&skill_2<10){
                    cout<<"Superior Willpower: Level "<<skill_2<<"/10"<<"\t Increases damage vs Elite Monsters." <<"\n";
                    cout<<"Upgrade cost: "<<coinS<<" "<<numd(skill2costs[skill_2])<<" Damage vs Elite +"<<SWdamage[skill_2]<<"% --> +"
                    <<SWdamage[skill_2+1]<<"% (+"<<(skill_2+1)*2<<"%)"<<" {Press 2 to upgrade}"<<"\n"<<"\n";
                }
                if(skill_2==10) cout<<"Superior Willpower: Max Level  Damage vs Elite +110%"<<"\t Increases damage vs Elite Monsters." <<"\n"<<"\n";

                if(skillFB==0) cout<<"Final Berserk: Locked \t Damage +55% when Health is below 50%\n";
                if(skillFB==1) cout<<"Final Berserk: Locked \t Damage +55% when Health is below 50%\n";
                if(skillSM==0) cout<<"Swift Maneuver: Unlocked \t Dodge Chance +6%\n";
                if(skillSM==1) cout<<"Swift Maneuver: Unlocked \t Dodge Chance +6%\n";
                if(skillGG==0) cout<<"Guardsman's Gambit: Locked \t Lower your shield for the first turn, but deal +120% damage that turn\n";
                if(skillGG==1) cout<<"Guardsman's Gambit: Unlocked \t Lower your shield for the first turn, but deal +120% damage that turn\n";


                cout<<"Press 9 to exit shop"<<"\n"<<"\n";
            }

            void static magic(int coins, int magicpt, int magic_fsword1, int magic_healp2, int pet, string petname){
                cout<<"[Magic Altar]"<<"\n";
                cout<<"Coins: "<<coinS<<" "<< coins <<"\n";
                cout<<"Magic Essence: "<<magicpt<<"\n"<<"\n";
                cout<<"What do you want to buy?"<<"\n"<<"\n";

                if(magic_fsword1==0){
                    cout<<"Blaze Sword: Locked   25% chance to burn opponent each attack, once burnt the monster will take damage every round!" <<"\n";
                    cout<<"Unlock cost: "<<coinS<<" 50.0k {Press 1 to unlock}"<<"\n"<<"\n";
                }
                if(magic_fsword1>0){
                    cout<<"Blaze Sword: Level "<<magic_fsword1<<"\t 25% to burn opponent, burn damage +25 with each upgrade." <<"\n";
                    cout<<"Upgrade cost: "<< magic_fsword1*5 <<" Magic Essence {Press 1 to upgrade}"<<"\n"<<"\n";
                }
                if(magic_healp2==0){
                    cout<<"Heal Pulse: Locked   Chance every round to heal 20% of your max health!" <<"\n";
                    cout<<"Unlock cost: "<<coinS<<" 100k {Press 2 to unlock}"<<"\n"<<"\n";
                }
                if(magic_healp2>0&&magic_healp2<10){
                    cout<<"Heal Pulse: Level "<<magic_healp2<<"/10 \t Chance every round to heal 10% of your max health! +2% chance with each upgrade (12% at level 1)." <<"\n";
                    cout<<"Upgrade cost: "<< 3+magic_healp2*2 <<" Magic Essence {Press 2 to upgrade}"<<"\n"<<"\n";
                }
                if(pet==0){
                    cout<<"Spirit Guide: Unowned   Purchase your very own spirit guide!!!" <<"\n";
                    cout<<"Unlock cost: 10 Magic Essence {Press 7 to rise your Spirit Guide!}"<<"\n"<<"\n";
                }

                if(pet>0){
                    cout<<"Spirit Guide ("<<petname<<"): Level "<<pet<<"\t Feed your Spirit Guide to have a 30% chance to level it up!" <<"\n";
                    cout<<"Feeding cost: "<< pet <<" Magic Essence {Press 7 to feed}"<<"\n";
                    cout<<"Rename Spirit Guide: {Press 8 to rename}"<<"\n";
                    cout<<"Hit Assist (Level " << pet <<"): 15% chance of attacking your foe, doing "<<50+pet*30<<" damage."<<"\n";
                    if(pet<5)cout<<"Loyalty Guard (Unlocks at Level 5)"<<"\n"<<"\n";
                    if(pet>=5)cout<<"Loyalty Guard (Active): 4% chance of completely blocking an enemy attack."<<"\n"<<"\n";
                }

                cout<<"Press 9 to exit shop"<<"\n"<<"\n";
            }

            void static smithUpgradeCost(int type, int tier){
                //type 1 for sword, 2 for armour, 3 for shield
                switch(type){
                    case 1://sword
                        cout << "Upgrade cost: " << tcosts[tier] << " Mysterious Shards" << "\n";
                        cout << "              " << tcosts2[tier]<< " Shiny Shards"<<"\n";
                        cout << "              " << tcosts2[tier]<< " Crystal Shards {Press 1 to Upgrade}"<<"\n";
                        break;
                    case 2://armour
                        cout << "Upgrade cost: " << tcosts[tier] << " Shiny Shards" << "\n";
                        cout << "              " << tcosts2[tier]<< " Mysterious Shards"<<"\n";
                        cout << "              " << tcosts2[tier]<< " Crystal Shards {Press 2 to Upgrade}"<<"\n";
                        break;
                    case 3://shield
                        cout << "Upgrade cost: " << tcosts[tier] << " Crystal Shards" << "\n";
                        cout << "              " << tcosts2[tier]<< " Mysterious Shards"<<"\n";
                        cout << "              " << tcosts2[tier]<< " Shiny Shards {Press 3 to Upgrade}"<<"\n";
                        break;
                }
            }

            void static smith(map<string, int> s) {

                int swordtier=s["swordtier"], armourtier=s["amrourtier"], shieldtier=s["shieldtier"];

                cout << "\n" << "[Smithing Shop]" << "\n";
                cout<<"Mysterious Shards: "<<s["mShards"]<< "\tShiny Shards: "<<s["sShards"]<<"\tCrystal Shards: "<<s["cShards"]<<"\n";
                if (swordtier < 5) {
                    cout << "Sword Prestige Tier: ";
                    tierd(swordtier, 1);
                    cout << "\tNext: ";
                    tierd(swordtier + 1, 1);
                } else {
                    cout << "Sword Prestige Tier: ";
                    tierd(swordtier, 1);
                }
                cout << "\n";

                switch (swordtier) {
                    case 0:
                        cout << "Damage: +" << tsword[swordtier] << " --> +" << tsword[swordtier + 1] << " (+"
                             << tsword[swordtier + 1] - tsword[swordtier] << ")" << "\n";
                        cout << "Current Bonus: None" << "\n";
                        cout << "Next Bonus: Coin Rewards +5%"
                             << "\n";//<<coinbonus<<"% --> +"<<coinbonus+5<<"% (+5%)"<<"\n";
                        smithUpgradeCost(1, swordtier);
                        break;
                    case 1://Sapphire
                        cout << "Damage: +" << tsword[swordtier] << " --> +" << tsword[swordtier + 1] << " (+"
                             << tsword[swordtier + 1] - tsword[swordtier] << ")" << "\n";
                        cout << "Current Bonus: Coin Rewards +5%" << "\n";
                        cout << "Next Bonus: Magic Essence in Daily Reward +1" << "\n";
                        smithUpgradeCost(1, swordtier);
                        break;
                    case 2://Emerald
                        cout << "Damage: +" << tsword[swordtier] << " --> +" << tsword[swordtier + 1] << " (+"
                             << tsword[swordtier + 1] - tsword[swordtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence in Daily Reward +1" << "\n";
                        cout << "Next Bonus: First Ace Damage +100" << "\n";
                        smithUpgradeCost(1, swordtier);
                        break;
                    case 3://Ruby
                        cout << "Damage: +" << tsword[swordtier] << " --> +" << tsword[swordtier + 1] << " (+"
                             << tsword[swordtier + 1] - tsword[swordtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence in Daily Reward +1" << "\n";
                        cout << "                 First Ace Damage +100" << "\n";
                        cout << "Next Bonus: Defence Breach +30" << "\n";
                        smithUpgradeCost(1, swordtier);
                        break;
                    case 4://Diamond
                        cout << "Damage: +" << tsword[swordtier] << " --> +" << tsword[swordtier + 1] << " (+"
                             << tsword[swordtier + 1] - tsword[swordtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence in Daily Reward +1" << "\n";
                        cout << "                 First Ace Damage +100" << "\n";
                        cout << "                 Defence Breach +30" << "\n";
                        cout << "Next Bonus: Unlock Final Berserk Skill!" << "\n";
                        smithUpgradeCost(1, swordtier);
                        break;
                    case 5://Monstronium
                        cout << "Damage: +" << tsword[swordtier] << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence in Daily Reward +1" << "\n";
                        cout << "                 First Ace Damage +100" << "\n";
                        cout << "                 Defence Breach +30" << "\n";
                        cout << "                 Unlocked Final Berserk Skill!" << "\n";
                        break;
                }
                cout << "\n";


                if (armourtier < 5) {
                    cout << "Armour Prestige Tier: ";
                    tierd(armourtier, 1);
                    cout << "\tNext: ";
                    tierd(armourtier + 1, 1);
                } else {
                    cout << "Armour Prestige Tier: ";
                    tierd(armourtier, 1);
                }
                cout << "\n";

                switch (armourtier) {
                    case 0:
                        cout << "HP: +" << tarmour[armourtier] << " --> +" << tarmour[armourtier + 1] << " (+"
                             << tarmour[armourtier + 1] - tarmour[armourtier] << ")" << "\n";
                        cout << "Current Bonus: None" << "\n";
                        cout << "Next Bonus: Coin Rewards +5%"
                             << "\n";
                        smithUpgradeCost(2, armourtier);
                        break;
                    case 1://Sapphire
                        cout << "HP: +" << tarmour[armourtier] << " --> +" << tarmour[armourtier + 1] << " (+"
                             << tarmour[armourtier + 1] - tarmour[armourtier] << ")" << "\n";
                        cout << "Current Bonus: Coin Rewards +5%" << "\n";
                        cout << "Next Bonus: Increased Magic Essence from Elite Monsters" << "\n";
                        smithUpgradeCost(2, armourtier);
                        break;
                    case 2://Emerald
                        cout << "HP: +" << tarmour[armourtier] << " --> +" << tarmour[armourtier + 1] << " (+"
                             << tarmour[armourtier + 1] - tarmour[armourtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Increased Magic Essence from Elite Monsters" << "\n";
                        cout << "Next Bonus: Coin Rewards +15%" << "\n";
                        smithUpgradeCost(2, armourtier);
                        break;
                    case 3://Ruby
                        cout << "HP: +" << tarmour[armourtier] << " --> +" << tarmour[armourtier + 1] << " (+"
                             << tarmour[armourtier + 1] - tarmour[armourtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Increased Magic Essence from Elite Monsters" << "\n";
                        cout << "                 Coin Rewards +15%" << "\n";
                        cout << "Next Bonus: Heal Pulse Heal amount +10%" << "\n";
                        smithUpgradeCost(2, armourtier);
                        break;
                    case 4://Diamond
                        cout << "HP: +" << tarmour[armourtier] << " --> +" << tarmour[armourtier + 1] << " (+"
                             << tarmour[armourtier + 1] - tarmour[armourtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Increased Magic Essence from Elite Monsters" << "\n";
                        cout << "                 Coin Rewards +15%" << "\n";
                        cout << "                 Heal Pulse Heal amount +10%" << "\n";
                        cout << "Next Bonus: Unlock Swift Maneuver Skill!" << "\n";
                        smithUpgradeCost(2, armourtier);
                        break;
                    case 5://Monstronium
                        cout << "HP: +" << tarmour[armourtier] << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Increased Magic Essence from Elite Monsters" << "\n";
                        cout << "                 Coin Rewards +15%" << "\n";
                        cout << "                 Heal Pulse Heal amount +10%" << "\n";
                        cout << "                 Unlocked Swift Maneuver Skill!!" << "\n";
                        break;
                }
                cout << "\n";

                if (shieldtier < 5) {
                    cout << "Shield Prestige Tier: ";
                    tierd(shieldtier, 1);
                    cout << "\tNext: ";
                    tierd(shieldtier + 1, 1);
                } else {
                    cout << "Shield Prestige Tier: ";
                    tierd(shieldtier, 1);
                }
                cout << "\n";

                switch (shieldtier) {
                    case 0:
                        cout << "Toughness: +" << tshield[shieldtier] << " --> +" << tshield[shieldtier + 1] << " (+"
                             << tshield[shieldtier + 1] - tshield[shieldtier] << ")" << "\n";
                        cout << "Current Bonus: None" << "\n";
                        cout << "Next Bonus: Coin Rewards +5%"
                             << "\n";
                        smithUpgradeCost(3, shieldtier);
                        break;
                    case 1://Sapphire
                        cout << "Toughness: +" << tshield[shieldtier] << " --> +" << tshield[shieldtier + 1] << " (+"
                             << tshield[shieldtier + 1] - tshield[shieldtier] << ")" << "\n";
                        cout << "Current Bonus: Coin Rewards +5%" << "\n";
                        cout << "Next Bonus: Magic Essence from Golems +1" << "\n";
                        smithUpgradeCost(3, shieldtier);
                        break;
                    case 2://Emerald
                        cout << "Toughness: +" << tshield[shieldtier] << " --> +" << tshield[shieldtier + 1] << " (+"
                             << tshield[shieldtier + 1] - tshield[shieldtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence from Golems +1" << "\n";
                        cout << "Next Bonus: Resistance +5%" << "\n";
                        smithUpgradeCost(3, shieldtier);
                        break;
                    case 3://Ruby
                        cout << "Toughness: +" << tshield[shieldtier] << " --> +" << tshield[shieldtier + 1] << " (+"
                             << tshield[shieldtier + 1] - tshield[shieldtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence from Golems +1" << "\n";
                        cout << "                 Resistance +5%" << "\n";
                        cout << "Next Bonus: Defence +30" << "\n";
                        smithUpgradeCost(3, shieldtier);
                        break;
                    case 4://Diamond
                        cout << "Toughness: +" << tshield[shieldtier] << " --> +" << tshield[shieldtier + 1] << " (+"
                             << tshield[shieldtier + 1] - tshield[shieldtier] << ")" << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence from Golems +1" << "\n";
                        cout << "                 Resistance +5%" << "\n";
                        cout << "                 Defence +30" << "\n";
                        cout << "Next Bonus: Unlock Guardsman's Gambit!" << "\n";
                        smithUpgradeCost(3, shieldtier);
                        break;
                    case 5://Monstronium
                        cout << "Toughness: +" << tshield[shieldtier] << "\n";
                        cout << "Current Bonuses: Coin Rewards +5%" << "\n";
                        cout << "                 Magic Essence from Golems +1" << "\n";
                        cout << "                 Resistance +5%" << "\n";
                        cout << "                 Defence +30" << "\n";
                        cout << "                 Unlocked Guardsman's Gambit!!" << "\n";
                        break;
                }
                
                cout<<"\n";

                cout << "Press 9 to exit shop" << "\n" << "\n";
            }

            void static create(map<string,int> s){
                cout<<"[Altar of Creation]"<<"\n";
                cout<<"Pyrogems: "<< s["pyrogems"] <<"\n";
                cout<<"By harnessing your power of UltraRed Radiation, create matter using high UR emitting Pyrogems!"<<"\n"<<"\n";
                cout<<"Item Creation I\n";
                cout<<"Cost: 5 Pyrogems {Press 1}\n\n";
                cout<<"Press 9 to exit shop"<<"\n"<<"\n";
            }
        };

    void static monsterEnRes(int pg){
        cout<<"Page: "<<pg<<"/30\n";
        cout<<"< Prev Pg: Press 1\tNext Pg: Press 2 >\n";
        cout<<"<< Prev Pg x10: Press 4\tNext Pg x10: Press 5 >>\n";
    }

        void static displayMonsterEn(int pg){
            cout<<"[Monster Encyclopedia]"<<"\n";
            if(pg==1) cout<<"Learn more about the monsters!"<<"\n";
            cout<<"\n";
            switch(pg) {
                case 1:
                    cout << "Welcome to the Monster Encyclopedia (uncompleted)! (Press 9 to exit)" << "\n" << "\n";
                    cout
                            << "Individual stats of the Monster are rated as 7 differents grades: \n "
                               "Very low, Low, Medium-low, Medium, Medium-high, High, Very high.";
                    cout << " Abilities of the monster are then shown and described." << "\n";
                    break;

                case 2:
                    cout << "(General info)" << "\n"
                         << "There are many ways you can fight monsters: press \"Explore\" to find out the various ways. They would lead you to fight wild monsters, elite monsters, and Golems respectively.";
                    cout << "\n" << "Fighting them awards you with:" << "\n" << "Wild monsters: Coins + Experience"
                         << "\n" << "Elite monsters: Coins + Experience + Magic Essence + Shards" << "\n";
                    cout << "Golems: Coins + Magic Essence" << "\n" << "\n"
                         << "When fighting these monsters, your equipment, skills, experience level and magic are all very important."
                         << "\n";
                    cout << "Elite monsters are similar to their wild counterparts, however, they are much stronger. "
                         << "\n" << "Their strengths are improved dramatically, but their other stats that they do ";
                    cout << "not specialise in are not improved as much, or are even unimproved or made weaker. "
                         << "\n" << "Make use of that to defeat them!" << "\n"
                         << "Now lets learn more about these monsters." << "\n";
                    break;


                case 3:
                    cout << "(Monster info)" << "\n" << "{Zombie}" << "\n" << "Strength: Balanced" << "\n"
                         << "Health: Very low" << "\n" << "Damage: Low" << "\n" << "Ability: None" << "\n";
                    break;


                case 4:
                    cout << "(Monster info)" << "\n" << "{Goblin}" << "\n" << "Strength: Attack" << "\n"
                         << "Health: Very low" << "\n" << "Damage: Medium" << "\n" << "Ability: None" << "\n";
                    break;


                case 5:
                    cout << "(Monster info)" << "\n" << "{Spider}" << "\n" << "Strength: Health" << "\n"
                         << "Health: Medium" << "\n" << "Damage: Low" << "\n" << "Ability: None" << "\n";
                    break;


                case 6:
                    cout << "(Monster info)" << "\n" << "{Evil Wizard}" << "\n" << "Strength: Attack" << "\n"
                         << "Health: Medium-low" << "\n" << "Damage: Medium" << "\n" << "Ability: None" << "\n";
                    break;


                case 7:
                    cout << "(Monster info)" << "\n" << "{Rare Zombie}" << "\n" << "Strength: Balanced" << "\n"
                         << "Health: Low" << "\n" << "Damage: Low" << "\n" << "Ability: None" << "\n";
                    break;


                case 8:
                    cout << "(Monster info)" << "\n" << "{Land-Shark}" << "\n" << "Strength: Health" << "\n"
                         << "Health: Medium-high" << "\n" << "Damage: Medium-low" << "\n" << "Ability: None" << "\n";
                    break;


                case 9:
                    cout << "(Monster info)" << "\n" << "{Rabid Dog}" << "\n" << "Strength: Attack" << "\n"
                         << "Health: Medium-low" << "\n" << "Damage: Medium" << "\n" << "Ability: None" << "\n";
                    break;


                case 10:
                    cout << "(Monster info)" << "\n" << "{Golem}" << "\n" << "Strength: Health" << "\n"
                         << "Health: High" << "\n" << "Damage: Medium" << "\n" << "Ability: Defence Breach" << "\n";
                    break;

                case 11:
                    cout << "(Coins)" << "\n"
                         << "You get a random amount of coins after defeating a monster, depending on your experience level."
                         << "\n";
                    cout
                            << "When you are defeated by a monster (except Golem), you would lose about half the amount of coins you could have gotten if you have defeated it instead."
                            << "\n";
                    cout << "Coins are used to upgrade equipment and unlock magic spells." << "\n";
                    break;

                case 12:
                    cout << "(Reward list)" << "\n"
                         << "Seems hard to tell excatly how many coins a wild or elite monster may yield, but we can estimate which monster yields the best amounts of coins!";
                    cout << "\n" << "Normal: Zombie, Goblin (Weird because he likes gold...)" << "\n"
                         << "Good: Spider, Evil Wizard, Rabid Dog" << "\n" << "Great: Land-shark, Rare Zombie" << "\n";
                    break;


                case 13:
                    cout << "(Magic Essence)" << "\n"
                         << "You can earn Magic Essence from defeating Golems in the Campaign, or have a chance of earning them by defeating elite monsters."
                         << "\n";
                    cout << "Magic Essence can be used to upgrade magic spells, rise Spirit Guides and feed them."
                         << "\n";
                    break;

                case 14:
                    cout << "(Experience)" << "\n" << "You can earn experience from defeating wild and elite monsters."
                         << "\n";
                    cout << "Use them to level up and get stronger! However, the monsters get stronger too!" << "\n";
                    break;
                case 15:
                    cout << "(Dungeons)" << "\n" << "You can earn nice rewards from exploring dungeons. However, you are limited to 5 attempts per day."
                         << "\n";
                    cout << "An empty dungeon space (-) may not actually be empty and can house Monsters/Treasure!" << "\n";
                    break;
                case 16:
                    cout<<"More Monster Info releasing on the next update!\n";
                    break;
            }
            cout << "\n";
            monsterEnRes(pg);
            cout<<"\n";
        }

    }

