#include <iostream>

#include "tuile.h"
#include "tab.h"

using namespace std;

int main()
{
	Tab* test1 = new Tab();
	test1->Create_Tiles(0, 0, 2);
	test1->Create_Tiles(0, 1, 2);
	test1->Create_Tiles(0, 2, 2);
	test1->Create_Tiles(0, 3, 2);
	test1->Print_Tab();
	test1->Move_Tiles_Left();
	test1->Print_Tab();
}