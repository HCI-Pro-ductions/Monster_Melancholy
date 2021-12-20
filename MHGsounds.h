using namespace std;
namespace MHGsounds{

    void static sound(int stype) {
        //Beep(1000,1000);
        if(stype==1){ //victory sound (bababa bababam)
            Sleep(200); //for(k=0;k<100000000;k++){};
            cout<<'\a';
            Sleep(200); //for(k=0;k<100000000;k++){};
            cout<<'\a';
            Sleep(200); //for(k=0;k<100000000;k++){};
            cout<<'\a';
            Sleep(200); //for(k=0;k<100000000;k++){};
            cout<<'\a';
        }
        if(stype==2){ //defeat sound (bababam bababam bababam)
            Sleep(400); //for(k=0;k<200000000;k++){};
            cout<<'\a';
            Sleep(400); //for(k=0;k<200000000;k++){};
            cout<<'\a';
            Sleep(400); //for(k=0;k<200000000;k++){};
            cout<<'\a';
        }
        if(stype==3){ //elite Monster sound (ba bababam)
            Sleep(200); //for(k=0;k<100000000;k++){};
            cout<<'\a';
            Sleep(200); //for(k=0;k<100000000;k++){};
            cout<<'\a';
        }



    }
}
