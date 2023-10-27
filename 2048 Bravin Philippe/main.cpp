#include <string>
#include <iostream>

#include "tuile.h"
#include "tab.h"
#include "test.h"

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main()
{
	Merge_Prio();
	Double_Merge();
	//No_Move();
	test4();

    srand(time(NULL));
    Tab* tab = new Tab();
	tab->Create_Tiles();
	tab->Create_Tiles();
    tab->Print_Tab();
	bool badKey = true;
	while (badKey)
	{
		tab->Loose();
		if (tab->Win()){
			cout << "ggwp ez clap winner winner chicken dinner";
			badKey = false;
			break;
		}
		if (tab->Loose()){
			cout << "tu pues, t'as perdu au 2048";
			badKey = false;
			break;
		}
		int c = 0;
		int move;
		switch ((c = _getch()))
		{
		case KEY_UP:
			move = tab->Move_Tiles_Up();
			tab->Reset_Bool();
			if (move > 0) {
				tab->Create_Tiles(); 
				tab->Print_Tab();
			}
			break;
		case KEY_DOWN:
			move = tab->Move_Tiles_Down();
			tab->Reset_Bool();
			if (move > 0) { 
				tab->Create_Tiles(); 
				tab->Print_Tab();
			}
			break;
		case KEY_RIGHT:
			move = tab->Move_Tiles_Right();
			tab->Reset_Bool();
			if (move > 0) { 
				tab->Create_Tiles(); 
				tab->Print_Tab();
			}
			break;
		case KEY_LEFT:
			move = tab->Move_Tiles_Left();
			tab->Reset_Bool();
			if (move > 0) { 
				tab->Create_Tiles(); 
				tab->Print_Tab();
			}
			break;
		default:
			badKey = true;
			break;
		}
	}

    delete tab;
    return 0;
}