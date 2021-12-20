#define ID_BUTTON1 1
#define ID_BUTTON2 2
#define ID_BUTTON3 3
#define ID_BUTTON4 4
#define ID_BUTTON5 5
#define ID_BUTTON6 6
#define ID_BUTTON7 7
#define ID_BUTTON8 8
#define ID_BUTTON9 9
#define ID_BUTTON10 10
#define ID_BUTTON11 11
#define ID_BUTTON12 12
#define ID_ProfileMenu1 21
#define ID_ProfileMenu2 22
#define ID_ProfileMenu3 23
#define ID_ProfileMenu4 24
#define ID_ProfileMenu5 25
#define ID_ProfileMenu6 26
#define ID_MonMenu1 31
#define ID_MonMenu2 32
#define ID_MonMenu3 33
#define ID_MonMenu4 34
#define ID_ShopMenu1 41
#define ID_ShopMenu2 42
#define ID_ShopMenu3 43
#define ID_ShopMenu4 44
#define ID_ShopMenu5 45
#define ID_ItemMenu1 51
#define ID_ItemMenu2 52
#define ID_CombatMenu1 61
/*#define ID_StatMenu1 51
#define ID_StatMenu2 52
#define ID_DailyRMenu1 61*/
#define ID_SettingsMenu1 71
#define ID_Textbox1 101
#define ID_Test 69
#define ID_Test2 6969
using namespace std;
bool bInShopE=false, bInShopS=false, bInShopM=false, bInShopSM=false, bInShopC=false, bSwordYesNo=false, bArmourYesNo=false, bSkill2YesNo=false,
is_shieldyesno=false, is_skillfa1yesno=false, is_magicfs1yesno=false, is_magichp2yesno=false, is_petyesno=false, is_petnaming=false;
bool bInWMfight=false, bInEMfight=false, bInCMfight=false,  bInDMfight=false, bInDungeon=false, bInMainMenu=true;
bool bInRedeemCode=false;
bool bInMonEn=false;
bool bItemCreateIYesNo=false;
bool bSwordTierYesNo=false, bArmourTierYesNo=false, bShieldTierYesNo=false;
namespace MHGguiHandle{

    HWND hStatus;

    HWND hTextBox;

    HFONT hf;

    HINSTANCE hInst;

    HBRUSH hBrushGreen = CreateSolidBrush(RGB(0, 255, 0));
    HBRUSH hBrushDarkGreen = CreateSolidBrush(RGB(0, 200, 0));
    HBRUSH hBrushBlack = CreateSolidBrush(RGB(0, 0, 0));

    HWND htextNumberKeypad, htextTextBox;
    HWND hBtn1, hBtn2, hBtn3, hBtn4, hBtn5, hBtn6, hBtn7, hBtn8, hBtn9, hBtnEnter;

    HMENU hMenubar = CreateMenu();
    HMENU hProfile = CreateMenu();
    HMENU hMFight = CreateMenu();
    HMENU hShop = CreateMenu();
    HMENU hItems = CreateMenu();
    HMENU hCombat = CreateMenu();
    HMENU hSettings = CreateMenu();

    void static ownerDraw(LPARAM lParam, WPARAM wParam){

            LPDRAWITEMSTRUCT lpDIS = (LPDRAWITEMSTRUCT) lParam;

            SetDCBrushColor(lpDIS->hDC, RGB(0, 200, 0));//dark green
            SetDCPenColor(lpDIS->hDC, RGB(0, 200, 0));//dark green
            SelectObject(lpDIS->hDC, GetStockObject(DC_BRUSH) );
            SelectObject(lpDIS->hDC, GetStockObject(DC_PEN) );

            RoundRect(lpDIS->hDC, 0, 47,700, 53, 0, 0);

            SetDCPenColor(lpDIS->hDC, RGB(0, 0, 0));//black

            if(wParam>=1 && wParam<=12) RoundRect(lpDIS->hDC, lpDIS->rcItem.left, lpDIS->rcItem.top,
                  lpDIS->rcItem.right, lpDIS->rcItem.bottom, 5, 5);

            switch(wParam){
                case ID_BUTTON1: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "1", 1); break;
                case ID_BUTTON2: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "2", 1); break;
                case ID_BUTTON3: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "3", 1); break;
                case ID_BUTTON4: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "4", 1); break;
                case ID_BUTTON5: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "5", 1); break;
                case ID_BUTTON6: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "6", 1); break;
                case ID_BUTTON7: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "7", 1); break;
                case ID_BUTTON8: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "8", 1); break;
                case ID_BUTTON9: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 20, lpDIS->rcItem.top + 15, "9", 1); break;
                case ID_BUTTON10: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 35, lpDIS->rcItem.top + 15, "Yes", 3); break;
                case ID_BUTTON11: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 35, lpDIS->rcItem.top + 15, "No", 2); break;
                case ID_BUTTON12: TextOut(lpDIS->hDC, lpDIS->rcItem.left + 30, lpDIS->rcItem.top + 10, "Enter", 5); break;
            }

    }

    void static createMenus(HWND hwnd){

        htextNumberKeypad = CreateWindow(TEXT("STATIC"),TEXT("Number Keypad:"),WS_VISIBLE | WS_CHILD, 20, 10, 120, 20, hwnd, (HMENU) NULL, NULL, NULL);
        hBtn1 = CreateWindow(TEXT("BUTTON"),TEXT("1"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 20, 40, 50, 50, hwnd, (HMENU) ID_BUTTON1, hInst, NULL);
        hBtn2 = CreateWindow(TEXT("BUTTON"),TEXT("2"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 80, 40, 50, 50, hwnd, (HMENU) ID_BUTTON2, NULL, NULL);
        hBtn3 = CreateWindow(TEXT("BUTTON"),TEXT("3"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 140, 40, 50, 50, hwnd, (HMENU) ID_BUTTON3, NULL, NULL);
        hBtn4 = CreateWindow(TEXT("BUTTON"),TEXT("4"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 20, 100, 50, 50, hwnd, (HMENU) ID_BUTTON4, NULL, NULL);
        hBtn5 = CreateWindow(TEXT("BUTTON"),TEXT("5"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 80, 100, 50, 50, hwnd, (HMENU) ID_BUTTON5, NULL, NULL);
        hBtn6 = CreateWindow(TEXT("BUTTON"),TEXT("6"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 140, 100, 50, 50, hwnd, (HMENU) ID_BUTTON6, NULL, NULL);
        hBtn7 = CreateWindow(TEXT("BUTTON"),TEXT("7"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 20, 160, 50, 50, hwnd, (HMENU) ID_BUTTON7, NULL, NULL);
        hBtn8 = CreateWindow(TEXT("BUTTON"),TEXT("8"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 80, 160, 50, 50, hwnd, (HMENU) ID_BUTTON8, NULL, NULL);
        hBtn9 = CreateWindow(TEXT("BUTTON"),TEXT("9"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 140, 160, 50, 50, hwnd, (HMENU) ID_BUTTON9, NULL, NULL);
        CreateWindow(TEXT("STATIC"),TEXT("Confirmation Buttons:"),WS_VISIBLE | WS_CHILD, 20, 220, 200, 20, hwnd, (HMENU) NULL, NULL, NULL);
        CreateWindow(TEXT("BUTTON"),TEXT("Yes"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 20, 250, 100, 50, hwnd, (HMENU) ID_BUTTON10, NULL, NULL);
        CreateWindow(TEXT("BUTTON"),TEXT("No"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 130, 250, 100, 50, hwnd, (HMENU) ID_BUTTON11, NULL, NULL);
        CreateWindow(TEXT("STATIC"),TEXT("Textbox:"),WS_VISIBLE | WS_CHILD, 20, 310, 75, 20, hwnd, (HMENU) NULL, NULL, NULL);
        hTextBox = CreateWindow(TEXT("EDIT"),TEXT(""),WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 340, 300, 40, hwnd, (HMENU) ID_Textbox1, NULL, NULL);
        hBtnEnter = CreateWindow(TEXT("BUTTON"),TEXT("Enter"),WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON | BS_OWNERDRAW, 330, 340, 100, 40, hwnd, (HMENU) ID_BUTTON12, NULL, NULL);

        //set fonts

        hf = CreateFontA(20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH,
                               NULL);
        //SendMessage(hBtn1, WM_SETFONT, (WPARAM)hf, 0);
        //SendMessage(hBtn1, WM_CTLCOLORBTN, 0, 0);

        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hProfile, "Profile");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMFight, "Explore");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hShop, "Shops");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hItems, "Items");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCombat, "Combat");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hSettings, "Settings");
        AppendMenu(hMenubar, MF_OWNERDRAW|WS_BORDER, (UINT_PTR)NULL, NULL);

        AppendMenu(hProfile, MF_STRING, ID_ProfileMenu1, "View Profile");
        AppendMenu(hProfile, MF_STRING, ID_ProfileMenu2, "Leaderboard");
        AppendMenu(hProfile, MF_STRING, ID_ProfileMenu3, "Online Players");
        AppendMenu(hProfile, MF_STRING, ID_ProfileMenu4, "Claim Daily Reward");
        AppendMenu(hProfile, MF_STRING, ID_ProfileMenu5, "Monster Encyclopedia");
        AppendMenu(hProfile, MF_STRING, ID_ProfileMenu6, "Redeem Code");
        AppendMenu(hMFight, MF_STRING, ID_MonMenu1, "Forest (Wild Monsters)");
        AppendMenu(hMFight, MF_STRING, ID_MonMenu2, "Dark Forest (Elite Monsters)");
        AppendMenu(hMFight, MF_STRING, ID_MonMenu3, "Golem Mountain");
        AppendMenu(hMFight, MF_STRING, ID_MonMenu4, "Dungeon");
        AppendMenu(hShop, MF_STRING, ID_ShopMenu1, "Equipment Shop");
        AppendMenu(hShop, MF_STRING, ID_ShopMenu2, "Skill Training Centre");
        AppendMenu(hShop, MF_STRING, ID_ShopMenu3, "Magic Altar");
        AppendMenu(hShop, MF_STRING, ID_ShopMenu4, "Smithing Shop");
        AppendMenu(hShop, MF_STRING, ID_ShopMenu5, "Altar of Creation");
        AppendMenu(hItems, MF_STRING, ID_ItemMenu1, "Inventory");
        AppendMenu(hItems, MF_STRING, ID_ItemMenu2, "Item Chest");
        AppendMenu(hCombat, MF_STRING, ID_CombatMenu1, "Toggle Shield (Coming Soon)");
        AppendMenu(hSettings, MF_STRING, ID_SettingsMenu1, "Credits");

        //CreateWindowW(L"Button", L"Go",WS_VISIBLE | WS_CHILD | WS_BORDER, 50, 400, 98, 38, hwnd, (HMENU) ID_Test, NULL, NULL);
        CreateWindow(TEXT("STATIC"),TEXT(" Status:"),WS_VISIBLE | WS_CHILD, 300, 10, 120, 20, hwnd, (HMENU) NULL, NULL, NULL);
        hStatus = CreateWindowW(L"Static", L" At Home",WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 40, 200, 25, hwnd, NULL, NULL, NULL);

        MENUINFO mi={0};
        mi.cbSize = sizeof(mi);
        mi.fMask = MIM_BACKGROUND;
        mi.hbrBack = hBrushDarkGreen;
        SetMenuInfo(hMenubar, &mi);
        SetMenu(hwnd, hMenubar);
    }

    void static updateGUIstatus(){
        if(bInMainMenu) SetWindowText(hStatus," At Home");
        if(bInWMfight) SetWindowText(hStatus," In a Forest");
        if(bInEMfight) SetWindowText(hStatus," In the Dark Forest");
        if(bInCMfight) SetWindowText(hStatus," On Mountain Top");
        if(bInDMfight) SetWindowText(hStatus," In Dungeon");
        if(bInShopE) SetWindowText(hStatus," In Equipment Shop");
        if(bInShopS) SetWindowText(hStatus," At Skill Training Centre");
        if(bInShopM) SetWindowText(hStatus," At Magic Altar");
        if(bInShopSM) SetWindowText(hStatus," In Smithing Shop");
        if(bInShopC) SetWindowText(hStatus," At Altar of Creation");
        if(bInRedeemCode) SetWindowText(hStatus," Redeeming Code");
        if(bInMonEn) SetWindowText(hStatus," Reading Monster Encyclopedia");
        /*bInShopE bInShopS=false, bInShopM=false, bInShopSM=false, bSwordYesNo=false, bArmourYesNo=false,
        is_shieldyesno=false, is_skillfa1yesno=false, is_magicfs1yesno=false, is_magichp2yesno=false, is_petyesno=false, is_petnaming=false;
        bool bInMfight=false, bInMainMenu=true;*/
    }

}
