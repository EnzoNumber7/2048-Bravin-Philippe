#include <string>
#include <iostream>

#include "tuile.h"
#include "tab.h"

void test1();
void test2();

void test1() {

	"0002"
	"0002"
	"0000"
	"0000"

	Tab* test1 = new Tab();
	test1->Create_Tiles(0, 0, 2);
	test1->Create_Tiles(0, 1, 2);
	test1->Create_Tiles(0, 2, 2);
	test1->Create_Tiles(0, 3, 2);
	test1->Print_Tab();
	test1->Move_Tiles_Left();
	test1->Print_Tab();

	delete test1;
}

void test2() {
	Tab* test2 = new Tab();
	test2->Create_Tiles(0, 3, 2);
	test2->Create_Tiles(0, 1, 2);
	test2->Create_Tiles(0, 2, 2);
	test2->Print_Tab();
	test2->Move_Tiles_Left();
	test2->Print_Tab();

	delete test2;
}