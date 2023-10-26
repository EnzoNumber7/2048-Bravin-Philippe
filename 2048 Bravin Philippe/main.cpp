#include <string>
#include <iostream>

#include "tuile.h"
#include "tab.h"

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int main()
{
    srand(time(NULL));

    Tab* tab = new Tab();
	tab->Create_Tiles();
	tab->Create_Tiles();
    tab->Print_Tab();
	bool badKey = true;
	while (badKey)
	{
		int c = 0;
		switch ((c = _getch()))
		{
		case KEY_UP:
			tab->Move_Tiles_Up();
			tab->Reset_Bool();
			tab->Create_Tiles();
			tab->Print_Tab();
			break;
		case KEY_DOWN:
			tab->Move_Tiles_Down();
			tab->Reset_Bool();
			tab->Create_Tiles();
			tab->Print_Tab();
			break;
		case KEY_RIGHT:
			tab->Move_Tiles_Right();
			tab->Reset_Bool();
			tab->Create_Tiles();
			tab->Print_Tab();
			break;
		case KEY_LEFT:
			tab->Move_Tiles_Left();
			tab->Reset_Bool();
			tab->Create_Tiles();
			tab->Print_Tab();
			break;
		default:
			badKey = true;
			break;
		}
	}

    delete tab;
    return 0;
}