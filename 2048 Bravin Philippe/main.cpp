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
    tab->Print_Tab();
    tab->Move_Tiles_Left();
    tab->Print_Tab();

    delete tab;
    return 0;
}