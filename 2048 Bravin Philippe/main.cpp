#include <string>
#include <iostream>

#include "tuile.h"
#include "tab.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Tab* tab = new Tab();

    tab->Create_Tiles();
    tab->Create_Tiles();
    tab->Create_Tiles();


    tab->Print_Tab();

    delete tab;
    return 0;
}