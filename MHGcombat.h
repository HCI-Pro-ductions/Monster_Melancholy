#include "MHGsounds.h"
#include "MHGtextDisplay.h"
using namespace std;
using namespace MHGsounds; //from MHGsounds.h
using namespace MHGtextDisplay; //from MHGtextDisplay.h
string const mnames[30]={"Zombie", "Goblin", "Spider", "Evil Wizard", "Rare Zombie", "Land-Shark","Rabid Dog",
                   "Elite Zombie", "Golden Goblin", "Ferocious Spider", "Malicious Wizard", "Super Rare Zombie",
                   "Formidable Land-Shark","Insane Rabid Dog","Golem","Ogre"};
int xpToLvlUp[110];//110 for extra buffer of 10 for 100 values
int prefix[110]={0};
int fighttype=0, cStage=1;
int damage, tdamage, block;
int mhp, php;
int coinBonus=0;
int lvl=1, xp=0, magic_fsword1=0, magic_healp2=0, magicBB=0,skill_fa1=0, skill_2=0, magicpt=0, sword=1, armour=0, shield=0, pet=0;
int coins=0; //long long coins = 0;
int swordtier=0, armourtier=0, shieldtier=0;
int y, z, temp, temp3, temp4, randomNo;
int mcnt=0, emcnt=0, dmcnt=0, dcnt=0, dchance=5;
int mShards=0, sShards=0, cShards=0;
bool fhit=true, burnt=false, fightwin=false, fightover=false, petblock=false;
int MonsterID, tempPhp, tempMhp;
int nextTurnNo=1;
int mWood=0, oWood=0, ironOre=0, pyrogems=0;
int equip=1;
int skillFB=0, skillSM=0, skillGG=0;
int snowballs=0;
char const coinS=232;
string petname="Spirit Guide";
int R, C;
int row=0, col=0;
map<string,int> rewards;
namespace MHGcombat
{
    struct dungeon{
        bool obstacle = false;
        bool entrance = false;
        bool explored = false;
        bool currentLocation = false;
        bool empty = true;
        int monster = 0;
        int treasure = 0;
        bool visibleT = false;
    };

    dungeon D[8][20];

    void static loadLvlUp(){
        //xp required to level up to x+1 (current level is x) is stored in xpToLvlUp[x]
        //example if player is lvl 1, xp needed to level up to next level (level 2) would be in xpToLvlUp[1]
        xpToLvlUp[0]=0;
        xpToLvlUp[1]=50; xpToLvlUp[2]=60; xpToLvlUp[3]=65; xpToLvlUp[4]=70; xpToLvlUp[5]=75;
        xpToLvlUp[6]=80; xpToLvlUp[7]=85; xpToLvlUp[8]=90; xpToLvlUp[9]=100; xpToLvlUp[10]=105;
        xpToLvlUp[11]=115; xpToLvlUp[12]=125; xpToLvlUp[13]=130; xpToLvlUp[14]=140; xpToLvlUp[15]=150;
        xpToLvlUp[16]=160; xpToLvlUp[17]=170; xpToLvlUp[18]=175; xpToLvlUp[19]=200; xpToLvlUp[20]=210;
        xpToLvlUp[21]=220; xpToLvlUp[22]=230; xpToLvlUp[23]=245; xpToLvlUp[24]=255; xpToLvlUp[25]=270;
        xpToLvlUp[26]=280; xpToLvlUp[27]=300; xpToLvlUp[28]=350; xpToLvlUp[29]=450; xpToLvlUp[30]=480;
        xpToLvlUp[31]=500; xpToLvlUp[32]=520; xpToLvlUp[33]=530; xpToLvlUp[34]=555; xpToLvlUp[35]=575;
        xpToLvlUp[36]=585; xpToLvlUp[37]=600; xpToLvlUp[38]=640; xpToLvlUp[39]=700; xpToLvlUp[40]=730;
        xpToLvlUp[41]=750; xpToLvlUp[42]=770; xpToLvlUp[43]=800; xpToLvlUp[44]=820; xpToLvlUp[45]=840;
        xpToLvlUp[46]=850; xpToLvlUp[47]=880; xpToLvlUp[48]=900; xpToLvlUp[49]=1000; xpToLvlUp[50]=1025;
        xpToLvlUp[51]=1050; xpToLvlUp[52]=1060; xpToLvlUp[53]=1070; xpToLvlUp[54]=1080; xpToLvlUp[55]=1090;
        xpToLvlUp[56]=1100; xpToLvlUp[57]=1110; xpToLvlUp[58]=1150; xpToLvlUp[59]=1250; xpToLvlUp[60]=1255;
        xpToLvlUp[61]=1260; xpToLvlUp[62]=1265; xpToLvlUp[63]=1270; xpToLvlUp[64]=1300; xpToLvlUp[65]=1350;
        xpToLvlUp[66]=1400; xpToLvlUp[67]=1425; xpToLvlUp[68]=1440; xpToLvlUp[69]=1500; xpToLvlUp[70]=1510;
        xpToLvlUp[71]=1520; xpToLvlUp[72]=1530; xpToLvlUp[73]=1540; xpToLvlUp[74]=1550; xpToLvlUp[75]=1560;
        xpToLvlUp[76]=1580; xpToLvlUp[77]=1600; xpToLvlUp[78]=1650; xpToLvlUp[79]=1750; xpToLvlUp[80]=1775;
        xpToLvlUp[81]=1800; xpToLvlUp[82]=1825; xpToLvlUp[83]=1850; xpToLvlUp[84]=1875; xpToLvlUp[85]=1900;
        xpToLvlUp[86]=1950; xpToLvlUp[87]=1975; xpToLvlUp[88]=1980; xpToLvlUp[89]=2000; xpToLvlUp[90]=2050;
        xpToLvlUp[91]=2060; xpToLvlUp[92]=2070; xpToLvlUp[93]=2080; xpToLvlUp[94]=2090; xpToLvlUp[95]=2100;
        xpToLvlUp[96]=2200; xpToLvlUp[97]=2300; xpToLvlUp[98]=2400; xpToLvlUp[99]=2500;
        prefix[0]=0;
        for(int i=1; i<100; i++) prefix[i] = prefix[i-1] + xpToLvlUp[i]; //generate prefix sum
    }

    int static getPlayerHP(){
        int x=100;
        x += armour*5;
        x += tarmour[armourtier];
        x += (lvl/2)*10;
        return x;
    }

    int static getPlayerBaseAtk(){
        int x=0;
        x+=sword*2+lvl*2;
        x += tsword[swordtier];
        return x;
    }

    void static getCoinBonus(){
            coinBonus=0;
            if(swordtier>=1) coinBonus+=5;
            if(armourtier>=1) coinBonus+=5;
            if(shieldtier>=1) coinBonus+=5;
            if(armourtier>=3) coinBonus+=15;
    }

    void static levelUp(){
            xp-=xpToLvlUp[lvl];
            lvl++;
            textc(7); cout<< "You leveled up from Level "<<lvl-1<< " to Level "<<lvl<<"!\n\n"; textc(10);
    }

    int static getTotalMCnt(){
        int x;
        x = mcnt + emcnt + dmcnt;
        return x;
    }

    int static getMonsterHP(int MonID){
        int MHP;
        int factor1, factor2, factor3;
        factor1 = 1+ lvl*2/3 + mcnt*1/3;
        factor2 = 1+ lvl*2/3 + emcnt*1/3;
        factor3 = 1+ getTotalMCnt();
        switch(MonID){
            case 0://Zombie
                MHP=80+factor1*10; break;
            case 7://Elite Zombie
                MHP=600+factor2*15; break;
            case 1://Goblin
                MHP=60+factor1*10; break;
            case 8://Golden goblin
                MHP=400+factor2*18; break;
            case 2://Spider
                MHP=200+factor1*25; break;
            case 9://Ferocious Spider
                MHP=3000+factor2*85; break;
            case 3://Evil Wizard
                MHP=150+factor1*20; break;
            case 10://Malicious Wizard
                MHP=400+factor2*25; break;
            case 4://Rare Zombie
                MHP=250+factor1*15; break;
            case 11://Super Rare Zombie
                MHP=1000+factor2*25; break;
            case 5://Land-Shark
                MHP=300+factor1*30; break;
            case 12://Formidable Land-Shark
                MHP=3000+factor2*50; break;
            case 6://Rabid Dog
                MHP=80+factor1*20; break;
            case 13://Insane Rabid Dog
                MHP=800+factor2*20; break;
            case 14://Golem
                MHP=1000+(cStage-1)*100; break;
            case 15://Ogre
                MHP= 100 + (D[row][col].monster+5) * (factor3/2); break;
        }
        return MHP;
    }

    int static getMonsterAtk(int MonID){
        int atk;
        int factor1, factor2, factor3;
        factor1 = 1+ lvl*2/3 + mcnt*1/3;
        factor2 = 1+ lvl*2/3 + emcnt*1/3;
        factor3 = 1+ getTotalMCnt();
        switch(MonID){
            case 0://Zombie
                atk=rand()%(factor1*11); break;
            case 7://Elite Zombie
                atk=rand()%(factor2*16); break;
            case 1://Goblin
                atk=rand()%(factor1*21); break;
            case 8://Golden goblin
                atk=rand()%(factor2*36); break;
            case 2://Spider
                atk=rand()%(factor1*11); break;
            case 9://Ferocious Spider
                atk=rand()%(factor2*5); break;
            case 3://Evil Wizard
                atk=rand()%(factor1*21); break;
            case 10://Malicious Wizard
                atk=rand()%(factor2*31); break;
            case 4://Rare Zombie
                atk=rand()%(factor1*11); break;
            case 11://Super Rare Zombie
                atk=rand()%(factor2*16); break;
            case 5://Land-Shark
                atk=rand()%(factor1*16); break;
            case 12://Formidable Land-Shark
                atk=rand()%(factor2*26); break;
            case 6://Rabid Dog
                atk=rand()%(factor1*21); break;
            case 13://Insane Rabid Dog
                atk=rand()%(factor2*33); break;
            case 14://Golem
                atk=rand()%(cStage*20); break;
            case 15://Ogre
                atk=rand()%D[row][col].monster * (factor3/3); break;
        }
        return atk;
    }

        void mfight(){

            php=getPlayerHP();

            if(fighttype==1){
                cout<<"\n[Fight wild monsters]\n";
                cout<<"Fight wild monsters to earn coins and experience!\n\n";
             }
            if(fighttype==2){
                sound(3);
                textc(14);
                cout<<"\n[Fight elite monsters]\n";
                cout<<"Fight elite monsters to earn coins and experience!\n";
                cout<<"(Recommended experience level 30)\n\n";
             }

            if(fighttype==3){
                cout<<"\n[Golem_fight_cStage]\n";
                cout<<"Fight_Golem_description\n";
            }

            if(fighttype==4){
                cout<<"\n[Dungeon Monster]\n";
            }
            randomNo = rand()%101;

        if(randomNo>=0 && randomNo<=24){//Zombie
            if(fighttype==1) MonsterID=0;
            if(fighttype==2) MonsterID=7;
            mhp=getMonsterHP(MonsterID);
        }
        if(randomNo>=25 && randomNo<=49){//Goblin
            if(fighttype==1) MonsterID=1;
            if(fighttype==2) MonsterID=8;
            mhp=getMonsterHP(MonsterID);

        }
        if(randomNo>=50 && randomNo<=69){//Spider
            if(fighttype==1) MonsterID=2;
            if(fighttype==2) MonsterID=9;
            mhp=getMonsterHP(MonsterID);
        }
        if(randomNo>=70 && randomNo<=79){//Evil Wizard
            if(fighttype==1) MonsterID=3;
            if(fighttype==2) MonsterID=10;
            mhp=getMonsterHP(MonsterID);
        }
        if(randomNo>=80 && randomNo<=84){//Rare Zombie
            if(fighttype==1) MonsterID=4;
            if(fighttype==2) MonsterID=11;
            mhp=getMonsterHP(MonsterID);
        }
        if(randomNo>=85 && randomNo<=89){//Land-Shark
            if(fighttype==1) MonsterID=5;
            if(fighttype==2) MonsterID=12;
            mhp=getMonsterHP(MonsterID);
        }
        if(randomNo>=90 && randomNo<=99){//Rabid Dog (Gavin's idea)
            if(fighttype==1) MonsterID=6;
            if(fighttype==2) MonsterID=13;
            mhp=getMonsterHP(MonsterID);
        }

        if(fighttype==3){//Golem
            MonsterID=14;
            mhp=getMonsterHP(MonsterID);
        }
            if(fighttype==4){//Dungeon
                MonsterID=15;
                mhp=getMonsterHP(MonsterID);
            }

        if(randomNo != 100){
            if(MonsterID!=3 && MonsterID!=7 && MonsterID!=13 && MonsterID!=14)cout<< "A " << mnames[MonsterID] << " appeared!\n\n";
            if(MonsterID==3||MonsterID==7||MonsterID==13)cout<< "An " << mnames[MonsterID] << " appeared!\n\n";
            if(MonsterID==14)cout<< "A Level " << cStage << " Golem appeared!\n\n";
            if(MonsterID==15)cout<< "An " << mnames[MonsterID] << " appeared!\n\n";
            cout<<'\a';
            mPic(MonsterID);
            if(fighttype!=4) tempPhp=php;
            tempMhp=mhp;
            fightover = false; fightwin = false;
            fhit = true;
            burnt = false;
            getCoinBonus();
            nextTurnNo=1;

            /*else{
            	std::cout<< "Invaild Response!\n";
			}*/

        }
        if(randomNo==100 && fighttype<=2 ){
            cout<< "Nothing appeared...wonder if this is good or bad...\n\n";
            cout<< "Congratulations!!!!!!! You found Easter Egg 1!!!!! Go flex to your friends!!!!!\n\n";
        }


    }

        void mFightRes(){
        cout<< "What do you want to do?\n";
        cout<< "Press 1: Fight\tPress 2: Run\tPress 3: Magic (Coming Soon)\n\n";
        playerRes();
    }

    int static getMonsterCoinReward(int MonID){
        int reward=0;
        int factor1, factor2, factor3;
        factor1 = 1+ lvl*2/3 + mcnt*1/3;
        factor2 = 1+ lvl*2/3 + emcnt*1/3;
        factor3 = 1+ getTotalMCnt();

        switch(MonID){
            case 0://Zombie
                reward= rand()%350 + factor1*150; break;
            case 7://Elite Zombie
                reward= rand()%350 + factor2*300; break;
            case 1://Goblin
                reward= rand()%450 + factor1*200; break;
            case 8://Golden goblin
                reward= rand()%4000 + factor2*400; break;
            case 2://Spider
                reward= rand()%500 + factor1*250; break;
            case 9://Ferocious Spider
                reward= rand()%500 + factor2*500; break;
            case 3://Evil Wizard
                reward= rand()%700 + factor1*400; break;
            case 10://Malicious Wizard
                reward= rand()%700 + factor2*800; break;
            case 4://Rare Zombie
                reward= rand()%1000 + factor1*400; break;
            case 11://Super Rare Zombie
                reward= rand()%1000 + factor2*400; break;
            case 5://Land-Shark
                reward= rand()%800 + factor1*450; break;
            case 12://Formidable Land-Shark
                reward= rand()%800 + factor2*700; break;
            case 6://Rabid Dog
                reward= rand()%700 + factor1*350; break;
            case 13://Insane Rabid Dog
                reward= rand()%700 + factor2*600; break;
            case 14://Golem
                reward=cStage*1000; break;
            case 15://Ogre
                reward=rand()%(D[row][col].monster*200) + factor3*25 + dcnt*10; break;
        }
        return reward;
    }

    map<string, int> static getMonsterItemReward(int MonID){
        map<string,int> rtn;
        int random1, random2, random3, random4, random5;
        mt19937 rdm(time(0));
        uniform_int_distribution<int> range4(1, 4);
        uniform_int_distribution<int> range3(1, 3);
        uniform_int_distribution<int> range2(1, 2);


        if(armourtier>=2) random1 = range2(rdm);
        else random1 = range4(rdm);
        random2 = range2(rdm);
        random3 = range4(rdm);

        switch(MonID){
            case 0://Zombie
                break;
            case 7://Elite Zombie
                if(random1 == 1) rtn["magicpt"] = 1; if(random2 == 1) rtn["mShards"] = 1; break;
            case 1://Goblin
                break;
            case 8://Golden goblin
                if(random1 == 1) rtn["magicpt"] = 1; if(random3 == 1) rtn["sShards"] = 1; break; //less chance for shards, because provides more gold
            case 2://Spider
                break;
            case 9://Ferocious Spider
                if(random1 == 1) rtn["magicpt"] = 1; if(random2 == 1) rtn["cShards"] = 1; break;
            case 3://Evil Wizard
                break;
            case 10://Malicious Wizard
                if(random1 == 1) rtn["magicpt"] = 1; if(random2 == 1) rtn["sShards"] = 1; break;
            case 4://Rare Zombie
                break;
            case 11://Super Rare Zombie
                if(random1 == 1) rtn["magicpt"] = 1; if(random2 == 1) rtn["cShards"] = 1; break;
            case 5://Land-Shark
                break;
            case 12://Formidable Land-Shark
                if(random1 == 1) rtn["magicpt"] = 1; if(random2 == 1) rtn["mShards"] = 1; break;
            case 6://Rabid Dog
                break;
            case 13://Insane Rabid Dog
                if(random1 == 1) rtn["magicpt"] = 1; if(random2 == 1) rtn["sShards"] = 1; break;
            case 14://Golem
                rtn["magicpt"] = cStage; break;
            case 15://Ogre
                if(D[row][col].monster>8) rtn["pyrogems"] = 1; break;
        }
        if(fighttype==1 || fighttype==2){
            random4=range3(rdm);
            if(random4==1){
                random5 = range2(rdm);
                if(random5==1){
                    rtn["oWood"] += range2(rdm);
                }
                else{
                    rtn["mWood"] += range2(rdm);
                }
            }
            random4=range3(rdm);
            if(random4==1) rtn["ironOre"]++;
            random4=range3(rdm);
            if(eventChristmas && random4==1) rtn["snowballs"]=1;
        }
        if(fighttype==3) rtn["ironOre"] += 1+ range3(rdm);
        return rtn;
    }

    int static getMonsterExpReward(int MonID) {
        int rtn=0;
        int factor1, factor2, factor3;
        factor1 = 1+ lvl*2/3 + mcnt*1/3;
        factor2 = 1+ lvl*2/3 + emcnt*1/3;
        factor3 = 1+ getTotalMCnt();
        switch (MonID){
            case 0://Zombie
                rtn= 10 + rand()%(factor1*3); break;
            case 7://Elite Zombie
                rtn= 70 + rand()%(factor2*4); break;
            case 1://Goblin
                rtn= 10 + rand()%(factor1*3); break;
            case 8://Golden goblin
                rtn= 70 + rand()%(factor2*4); break;
            case 2://Spider
                rtn= 10 + rand()%(factor1*3); break;
            case 9://Ferocious Spider
                rtn= 70 + rand()%(factor1*4); break;
            case 3://Evil Wizard
                rtn= 10 + rand()%(factor1*3); break;
            case 10://Malicious Wizard
                rtn= 70 + rand()%(factor1*4); break;
            case 4://Rare Zombie
                rtn= 10 + rand()%(factor1*3); break;
            case 11://Super Rare Zombie
                rtn= 70 + rand()%(factor1*4); break;
            case 5://Land-Shark
                rtn= 10 + rand()%(factor1*4); break;
            case 12://Formidable Land-Shark
                rtn= 100 + rand()%(factor1*5); break;
            case 6://Rabid Dog
                rtn= 10 + rand()%(factor1*3); break;
            case 13://Insane Rabid Dog
                rtn= 70 + rand()%(factor1*4); break;
            case 14://Golem
                rtn=0; break;
            case 15:
                rtn=10+D[row][col].monster*2; break;
        }
        return rtn;
    }

    void static addMonsterItemRewards(map<string,int> r){
        map<string, int> ::iterator it;
        for(it=r.begin(); it!=r.end(); it++){
            cout<<"- "<<it->second<<" ";
            if(strcmp(it->first.c_str(),"mWood") == 0){ cout<<"Maple Wood"; mWood+=it->second;}
            else if(strcmp(it->first.c_str(),"oWood") == 0){ cout<<"Oak Wood"; oWood+=it->second;}
            else if(strcmp(it->first.c_str(),"ironOre") == 0){ cout<<"Iron Ore"; ironOre+=it->second;}
            else if(strcmp(it->first.c_str(),"magicpt") == 0){ cout<<"Magic Essence"; magicpt+=it->second;}
            else if(strcmp(it->first.c_str(),"pyrogems") == 0){ cout<<"Pyrogems"; pyrogems+=it->second;}
            else if(strcmp(it->first.c_str(),"mShards") == 0){ cout<<"Mysterious Shards"; mShards+=it->second;}
            else if(strcmp(it->first.c_str(),"sShards") == 0){ cout<<"Shiny Shards"; sShards+=it->second;}
            else if(strcmp(it->first.c_str(),"cShards") == 0){ cout<<"Crystal Shards"; cShards+=it->second;}
            else if(strcmp(it->first.c_str(),"snowballs") == 0){ cout<<"Snowballs"; cShards+=it->second;}
            cout<<"\n";
        }
    }

    void static mFightEnd(){
        if(tempPhp<=0 && tempMhp>=1){//lose
            fightwin=false;
            fightover=true;
            int reward=(getMonsterCoinReward(MonsterID))/2;
            coins-=reward;
            if(coins<0) coins=0;

            //updateStoredData();
            youdied();
            sound(2);
            if(MonsterID>=0&&MonsterID<=13) cout<<"\nYou got killed by "<<mnames[MonsterID]<<"! Its all over! You lost: \n"<<"- "<<coinS<<" "; numd(reward);
            cout<<"\nYou now have "<< numd(coins) <<" coins. \n\nBack to menu...\n\n";
            if(MonsterID==14) cout<<"\nYou got wrecked by Golem! Its all over! Oof! Golem is kind enough not to rob you. \n\nBack to menu...\n\n";
        }

        if(tempMhp<=0&&tempPhp>=1) {//win

            youwin();
            sound(1);
            cout<<"\nSuccess! You slain "<<mnames[MonsterID]<<"!\n";
            fightwin=true;
            fightover=true;

            if(MonsterID>=0 && MonsterID<=6){

                int reward=getMonsterCoinReward(MonsterID);
                int origin=reward;
                reward+=(reward*(coinBonus/100));
                coins+=reward;
                int x = getMonsterExpReward(MonsterID);
                xp+=x;

                cout<<"You gained: \n"<<"- "<<coinS<<" "<<numd(reward);
                if(coinBonus>0) cout<<"(+ "<<coinS<<" "<<numd(reward-origin)<<" bonus included)";
                cout<<"\n";
                addMonsterItemRewards(getMonsterItemReward(MonsterID));
                cout<<"- "<<x<<" experience points"<<"\n";
                if(xp>=xpToLvlUp[lvl]) levelUp();
                mcnt++;
                //updateStoredData();
            }

            if(MonsterID>=7 && MonsterID<=13){

                int reward=getMonsterCoinReward(MonsterID);
                int origin=reward;
                reward+=(reward*(coinBonus/100));
                coins+=reward;
                int x = getMonsterExpReward(MonsterID);
                xp+=x;

                cout<<"You gained: \n"<<"- "<<coinS<<" "<<numd(reward);
                if(coinBonus>0) cout<<"(+ "<<coinS<<" "<<numd(reward-origin)<<" bonus included)";
                cout<<"\n";
                addMonsterItemRewards(getMonsterItemReward(MonsterID));
                cout<<"- "<<x<<" experience points"<<"\n";
                if(xp>=xpToLvlUp[lvl]) levelUp();
                emcnt++;
                //updateStoredData();
            }

            if(MonsterID==14){
                int reward=getMonsterCoinReward(MonsterID);
                int origin=reward;
                reward+=(reward*(coinBonus/100));
                coins+=reward;

                cout<<"You gained: \n"<<"- "<<coinS<<" "<<numd(reward);
                if(coinBonus>0) cout<<"(+ "<<coinS<<" "<<numd(reward-origin)<<" bonus included)";
                cout<<"\n";
                addMonsterItemRewards(getMonsterItemReward(MonsterID));
                cStage++;
                //updateStoredData();
            }

            if(MonsterID==15){
                map<string, int> r = getMonsterItemReward(MonsterID);
                map<string, int> ::iterator it;
                int pyrogemAmt=0;
                for(it=r.begin();it!=r.end();it++){
                    if(strcmp(it->first.c_str(), "pyrogems") == 0){ rewards["pyrogems"]+=it->second; pyrogemAmt+=it->second;}
                }
                int reward=getMonsterCoinReward(MonsterID);
                int origin=reward;
                reward+=(reward*(coinBonus/100));
                int x = getMonsterExpReward(MonsterID);
                xp+=x;

                cout<<"You gained: \n"<<"- "<<coinS<<" "<< numd(reward);
                if(coinBonus>0) cout<<"(+ "<<coinS<<" "<<numd(reward-origin)<<" bonus included)";
                if(pyrogemAmt>0) cout<<"\n- "<<pyrogemAmt<<" Pyrogems";
                cout<<"\n- "<<x<<" experience points"<<"\n"
                <<"Items have been added to your Inventory!\n\n";
                if(xp>=xpToLvlUp[lvl]) levelUp();
                rewards["coins"]+=reward;
                dmcnt++;
            }

        }

        //if(php<=0&&mhp<=0) cout<<"You died at the same time as Monster! Back to menu..."<<"\n";

        php=getPlayerHP();
    }

    void static mfight_choice(int choice){
        //choice: fight
        cout<<choice<<"\n";
        cout<<"\n";
        cout<<"----------------------------------------\n";
        y = rand()%16;
        int damageMulti = 0; //damage multi in percent
        damage=getPlayerBaseAtk();
        tdamage=damage+y;
        if(fhit && skill_fa1 > 0) damageMulti += skill_fa1 * 15;
        if(fhit && swordtier>=3 && skill_fa1>0) tdamage += 100;
        if( skillFB==1 && (tempPhp/php*100)<50 ){ textc(7); cout<<"Final Berserk "; textc(10); cout<<"activated!\n"; damageMulti+=55;}
        if( skillGG==1 && fhit ){ textc(7); cout<<"Guardsman's Gambit "; textc(10); cout<<"activated!\n"; damageMulti+=120;}
        tdamage+= tdamage * damageMulti/100;
        tempMhp=tempMhp-tdamage;

        SleepTillNextSec();
        if(fhit && skill_fa1 > 0){
            textc(7); cout<<"First Ace "; textc(10); cout<<"activated!\n";
        }
        if(swordtier>0){cout<<"You swung your "; tierd(swordtier, 1); cout<<" Sword at " << mnames[MonsterID] << ", dealing "<< tdamage << " damage.\n";}
        else cout<<"You swung your sword at " << mnames[MonsterID] << ", dealing "<< tdamage << " damage.\n";
        if(magic_fsword1>0){
            y = rand()%100;
            if(y>=0 &&y<=24 && !burnt) cout << "You burnt " << mnames[MonsterID] << " with "; textc(12); cout << "Blaze Sword"; textc(10); cout << "!\n";
            if(y>=0&&y<=24) burnt=true;
        }
        if(burnt) tempMhp=tempMhp-magic_fsword1*25;
        if(burnt) cout<<mnames[MonsterID] << " is on fire and took "<<magic_fsword1*25<<" damage.\n";
        if(tempPhp<=0||tempMhp<=0){
            mFightEnd();
            return;
        }
        if(tempPhp<=0||tempMhp<=0){
            mFightEnd();
            return;
        }
        y = rand()%99;
        if(pet>0&&y>=1&&y<=15){
            Sleep(1000);
            tempMhp=tempMhp-50-pet*30;
            cout<<petname<<" scared "<<mnames[MonsterID] << ", dealing "<<50+pet*30<<" damage.\n";
        }
        if(tempPhp<=0||tempMhp<=0){
            mFightEnd();
            return;
        }
        cout<<mnames[MonsterID]<<" is left with "<< tempMhp << "/" << mhp << " HP "<<"("<<tempMhp*100/mhp<<"%)"<<"\n\n";
        //cout<<mnames[MonsterID]<<" is left with "<< mhp << "/" << temp2 << " HP\n\n";

        Sleep(1000);
        z = rand()%99;
        bool dodge=false;
        if(pet>=5&&z>=1&&z<=4){
            cout<<petname<<" blocked "<<mnames[MonsterID] << "'s attack!!!!!!\n\n";
            petblock=true;
        }
        if(skillSM && z>=5&&z<=10){
            cout<<"Swift Maneuver "; textc(10); cout<<"activated!\n";
            cout<<"You dodged the attack!\n\n";
            dodge=true;
        }
        if(!petblock && !dodge){
            y = getMonsterAtk(MonsterID);
            monText(MonsterID, y, mnames[MonsterID]);

            if(MonsterID==14){
                tempPhp-=y;
                if(shield>0) cout<<"You rose your shield, but Golem broke through it!"<<"\n";
            }

            if(MonsterID!=14){
                block=shield*2;
                temp4=y;
                y-=block;
                if(y<0) block=temp4;
                if(y>=0) tempPhp-=y;
                if(shield>0) cout<<"You rose your shield, blocking "<<block<<" damage.\n";
            }
            if(tempPhp<=0||tempMhp<=0){
                mFightEnd();
                return;
            }
            cout<<"You are left with "<< tempPhp << "/" << php << " HP "<<"("<<tempPhp*100/php<<"%)\n\n";
            //cout<<"You are left with "<< php << "/" << temp << " HP\n\n";
        }
        if(petblock) petblock=false;
        z = rand()%100;
        if(magic_healp2>0 && z>=0 && z<=9+magic_healp2*2){
            if(armourtier>=4){ //extra 10% heal for armour prestige
                tempPhp+=php/5;
                if(tempPhp<=php) cout<<"You healed " << php/5 << " HP with "; textc(11); cout<<"Heal Pulse"; textc(10); cout<<"! (+20% HP)\n";
                if(tempPhp>php){
                    temp4=tempPhp-php/5;
                    tempPhp=php;
                    cout<<"You healed " << php-temp4 << " HP with "; textc(11); cout<<"Heal Pulse"; textc(10); cout<<"! (+20% HP)\n";
                }
            }
            else{ //normal heal (no prestige bonus) amount
                tempPhp+=php/10;
                if(tempPhp<=php) cout<<"You healed " << php/10 << " HP with "; textc(11); cout<<"Heal Pulse"; textc(10); cout<<"! (+10% HP)\n";
                if(tempPhp>php){
                    temp4=tempPhp-php/10;
                    tempPhp=php;
                    cout<<"You healed " << php-temp4 << " HP with "; textc(11); cout<<"Heal Pulse"; textc(10); cout<<"! (+10% HP)\n";
                }
            }
            cout<<"You are left with "<< tempPhp << "/" << php << " HP "<<"("<<tempPhp*100/php<<"%)\n\n";
            //cout<<"You are left with "<< php << "/" << temp << " HP\n\n";
        }
        nextTurnNo++;
        fhit=false;
        mFightRes();

    }

    void static dungeonLegend(){
        cout<<"\nCurrent Location: @\tExplored: #\tTreasure: T\nEntrance/Exit: E\tObstacle: X\t Unexplored: -\n";
    }

    void static dungeonDirections(){
        cout<<"Press 2: Up\tPress 4: Left\nPress 6: Right\tPress 8: Down\n";
    }

    void static dungeonRes(){
        cout<<"Your response: ";
    }

    void static displayInv(){
        textDisplayInv(rewards);
    }

    void static dungeonTreasure(){
        mt19937 rdm(time(0));
        uniform_int_distribution<int> range100(1, 100);
        uniform_int_distribution<int> range3(1, 3);
        int rand = range100(rdm);
        if(rand>=1 && rand<=40){//40% coins
            rewards["coins"]+=100*D[row][col].treasure; cout<<coinS<<" "<<100*D[row][col].treasure<<"!";
        }
        else if(rand>=41 && rand<=80){//40% magicpt
            rewards["magicpt"]+=1+D[row][col].treasure/3; cout<<1+D[row][col].treasure/3<<" Magic Essence!";
        }
        else if(rand>=81 && rand<=100){//20% shards
            int random = range3(rdm);
            switch(random){
                case 1: rewards["mShards"]+=1+D[row][col].treasure/6; cout<<1+D[row][col].treasure/6<<" Mysterious Shards"; break;
                case 2: rewards["sShards"]+=1+D[row][col].treasure/6; cout<<1+D[row][col].treasure/6<<" Shiny Shards"; break;
                case 3: rewards["cShards"]+=1+D[row][col].treasure/6; cout<<1+D[row][col].treasure/6<<" Crystal Shards"; break;
            }
        }
        rand = range100(rdm);
        if(rand>=1 && rand<=40){//seperate 50% chance for pyrogems
            rewards["pyrogems"]+=2+D[row][col].treasure/6; cout<<D[row][col].treasure; cout<<"\n"<<2+D[row][col].treasure/6<<" Pyrogems!";
        }
    }

    void static displayDungeon(int r, int c){
        textc(10);
        dungeonLegend();
        cout<<".";
        for(int i=0; i<c+1; i++) cout<<"_";
        cout<<".\n";
        for(int i=0; i<r+1; i++){
            cout<<"|";
            for(int j=0; j<c+1; j++){
                if(D[i][j].currentLocation){
                    cout<<"@";
                }
                else if(D[i][j].entrance){
                    cout<<"E";
                }
                else if(D[i][j].explored){
                    cout<<"#";
                }
                else if(D[i][j].visibleT && D[i][j].treasure>0){
                    cout<<"T";
                }
                else if(D[i][j].empty || D[i][j].monster>0 || D[i][j].treasure>0){
                    cout<<"-";
                }
                else if(D[i][j].obstacle){
                    cout<<"X";
                }
            }
            cout<<"|\n";
        }
        cout<<"|";
        for(int i=0; i<c+1; i++) cout<<"_";
        cout<<"|\n";
        dungeonDirections();
    }

    void static clearDungeon(){
        for(int i=0; i<8; i++){
            for(int j=0; j<20; j++){
                D[i][j].obstacle = false; D[i][j].entrance = false; D[i][j].explored = false;
                D[i][j].currentLocation = false; D[i][j].empty = true;
                D[i][j].monster = 0; D[i][j].treasure = 0;
            }
        }
    }

    void static generateDungeon(){
        mt19937 rdm(time(0));
        uniform_int_distribution<int> rangeRow(4, 7);//5-8 rows
        uniform_int_distribution<int> rangeCol(9, 19);//10-20 columns
        uniform_int_distribution<int> range100(1, 100);
        uniform_int_distribution<int> range10(1, 10);
        uniform_int_distribution<int> range3(1, 3);
        uniform_int_distribution<int> range5(1, 5);
        uniform_int_distribution<int> range3to5(3, 5);
        uniform_int_distribution<int> range2to4(2, 4);
        R = rangeRow(rdm);
        C = rangeCol(rdm);
        uniform_int_distribution<int> rangeR(0, R);
        uniform_int_distribution<int> rangeC(0, C);
        int spaces = (R+1)*(C+1);
        clearDungeon();
        rewards.clear();
        int rand3 = range3(rdm), rand5 = range5(rdm), rand3to5 = range3to5(rdm), rand2to4 = range2to4(rdm);
        for(int i=0; i<rand2to4; i++){//generate 2-4 vertical bars of length 1 or 3
            mt19937 rd(time(0)-i);
            uniform_int_distribution<int> range01(0, 1);
            int r = rangeR(rd);
            int c = rangeC(rd);
            int rand01 = range01(rd);
            D[r][c].obstacle = true; D[r][c].empty = false;
            for(int j=0; j<rand01; j++){
                if( (r+j+1) <= 7){ D[r+j+1][c].obstacle = true; D[r+j+1][c].empty = false; }
                if( (r-j-1) >= 0){ D[r-j-1][c].obstacle = true; D[r-j-1][c].empty = false; }
            }

        }
        rand2to4 = range2to4(rdm);
        for(int i=0; i<rand2to4; i++){//generate 2-4 horizontal bars of length 1 or 3
            mt19937 rd(time(0)-i);
            uniform_int_distribution<int> range01(0, 1);
            int r = rangeR(rd);
            int c = rangeC(rd);
            int rand01 = range01(rd);
            D[r][c].obstacle = true; D[r][c].empty = false;
            for(int j=0; j<rand01; j++){
                if( (c+j+1) <= 19){ D[r][c+j+1].obstacle = true; D[r][c+j+1].empty = false; }
                if( (c-j-1) >= 0){ D[r][c-j-1].obstacle = true; D[r][c-j-1].empty = false; }
            }

        }
        for(int i=0; i<R+1; i++){ // generate monster/treasure at empty spaces
            for(int j=0; j<C+1; j++){
                if(D[i][j].obstacle) continue;
                int rand = range100(rdm);
                if(rand>=1 && rand<=10){//monster 10%
                    D[i][j].empty = false;
                    D[i][j].monster = range10(rdm);
                }
                if(rand>=11 && rand<=15){//treasure 5%
                    D[i][j].empty = false;
                    D[i][j].treasure = range10(rdm);
                }
            }
        }
        int Er, Ec;
        do{
            Er = rangeR(rdm);
            Ec = rangeC(rdm);
        } while( D[Er][Ec].empty == false);//while not empty keep repeating
        D[Er][Ec].entrance = true; D[Er][Ec].currentLocation = true; D[Er][Ec].empty = false;
        int Tr, Tc;
        do{
            Tr = rangeR(rdm);
            Tc = rangeC(rdm);
        } while( D[Tr][Tc].empty == false);//while not empty keep repeating
        D[Tr][Tc].treasure = 10; D[Tr][Tc].visibleT = true; D[Tr][Tc].empty = false;
        row=Er; col=Ec;
        displayDungeon(R, C);
        php=getPlayerHP();
        tempPhp=php;
    }
    char static dungeonMove(int direction){//2-up, 4-left, 6-right, 8-down
        switch(direction){
            case 2://up
                if(row>=1 && !D[row-1][col].obstacle){//if not out of bound or an obstacle
                    D[row][col].currentLocation=false; D[row][col].explored=true; D[row-1][col].currentLocation=true;
                    row--;
                }
                else return 'F';
                break;
            case 4://left
                if(col>=1 && !D[row][col-1].obstacle){//if not out of bound or an obstacle
                    D[row][col].currentLocation=false; D[row][col].explored=true; D[row][col-1].currentLocation=true;
                    col--;
                }
                else return 'F';
                break;
            case 6://right
                if(col<C && !D[row][col+1].obstacle){//if not out of bound or an obstacle
                    D[row][col].currentLocation=false; D[row][col].explored=true; D[row][col+1].currentLocation=true;
                    col++;
                }
                else return 'F';
                break;
            case 8://down
                if(row<R && !D[row+1][col].obstacle){//if not out of bound or an obstacle
                    D[row][col].currentLocation=false; D[row][col].explored=true; D[row+1][col].currentLocation=true;
                    row++;
                }
                else return 'F';
                break;
        }
        if(D[row][col].monster>0 && !D[row][col].explored){
            return 'M';
        }
        else if(D[row][col].treasure>0 && !D[row][col].explored){
            return 'T';
        }
        else if(D[row][col].entrance && D[row][col].explored){
            return 'E';
        }
        else{
            return 'S';
        }

    }

    void static dungeonExit(){
        dcnt++;
        dchance--;
        map<string,int>::iterator it;
        for(it=rewards.begin(); it!=rewards.end(); it++){
            cout<<it->first<<":"<<it->second<<"\n";
            if( strcmp(it->first.c_str(), "coins") == 0 ) coins+=it->second;
            if( strcmp(it->first.c_str(), "magicpt") == 0 ) magicpt+=it->second;
            if( strcmp(it->first.c_str(), "pyrogems") == 0 ) pyrogems+=it->second;
            if( strcmp(it->first.c_str(), "mShards") == 0 ) mShards+=it->second;
            if( strcmp(it->first.c_str(), "sShards") == 0 ) sShards+=it->second;
            if( strcmp(it->first.c_str(), "cShards") == 0 ) cShards+=it->second;

        }
        rewards.clear();
    }

    void static itemCreate(int x){
        mt19937 rdm(time(0));
        uniform_int_distribution<int> range100(1, 100);
        uniform_int_distribution<int> range3(1, 3);
        int rand = range100(rdm);
        map<string,int> r;
        if(rand>=1 && rand<=70){//70% common items
            //each item has a 1 in 3 chance of being created; upon successful creation, number of items is random number from 3-5
            int rand3;
            rand3 = range3(rdm); if(rand3==1)  r["mWood"]+=2+range3(rdm);
            rand3 = range3(rdm); if(rand3==1)  r["oWood"]+=2+range3(rdm);
            rand3 = range3(rdm); if(rand3==1)  r["ironOre"]+=2+range3(rdm);
        }
        if(rand>=71 && rand<=100){//30% rare items
            //each item has a 1 in 3 chance of being created; upon successful creation, number of items is random number from 2-4
            int rand3;
            rand3 = range3(rdm); if(rand3==1)  r["magicpt"]+=1+range3(rdm);
            rand3 = range3(rdm); if(rand3==1)  r["mShards"]+=1+range3(rdm);
            rand3 = range3(rdm); if(rand3==1)  r["sShards"]+=1+range3(rdm);
            rand3 = range3(rdm); if(rand3==1)  r["cShards"]+=1+range3(rdm);
        }
        if(!r.empty()) addMonsterItemRewards(r);
        else cout<<"Nothing!\n";
    }
}

