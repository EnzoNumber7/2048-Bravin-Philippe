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
	// Lancement des tests, si echec alors on arrete le programme
	if (not Merge_Prio()) { return 0; }
	if (not Double_Merge()) { return 0; }
	if (not No_Move()) { return 0; }
	if (not Test_Win()) { return 0; }
	if (not Test_Lose()) { return 0; }

    srand(time(NULL));
    Tab* tab = new Tab();
	tab->Create_Tiles();
	tab->Create_Tiles();
    tab->Print_Tab();
	bool run = true;
	while (run)
	{
		if (tab->Win()){
			cout << "Bravo, vous avez gagner";
			run = false;
			break;
		}
		if (tab->Loose()){
			cout << "Vous avez perdu";
			run = false;
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
			run = true;
			break;
		}
	}

    delete tab;
    return 0;
}