#include "tuile.h"
#include "tab.h""
#include "test.h""

#include <iostream>
using namespace std;

void Merge_Prio() {
	cout << "fezfqerfqtgr'qeg";
	Tab* testL = new Tab("2-2-0-4",
						"0-0-0-0",
						"0-0-0-0",
						"0-0-0-0");
	Tab* resultL = new Tab("4-4-0-0",
						   "0-0-0-0",
						   "0-0-0-0",
						   "0-0-0-0");
	testL->Print_Tab();
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 1 Left" << endl;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("4-0-2-2",
						"0-0-0-0",
						"0-0-0-0",
						"0-0-0-0");
	Tab* resultR = new Tab("0-0-4-4",
						  "0-0-0-0",
						  "0-0-0-0",
						  "0-0-0-0");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 1 Right" << endl;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2-0-0-0",
						"2-0-0-0",
						"0-0-0-0",
						"4-0-0-0");
	Tab* resultU = new Tab("4-0-0-0",
						  "4-0-0-0",
						  "0-0-0-0",
						  "0-0-0-0");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 1 Up" << endl;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("4-0-0-0",
						"0-0-0-0",
						"2-0-0-0",
						"2-0-0-0");
	Tab* resultD = new Tab("0-0-0-0",
						  "0-0-0-0",
						  "4-0-0-0",
						  "4-0-0-0");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 1 Down" << endl;
	}
	delete testD;
	delete resultD;
}

void Double_Merge() {
	Tab* testL = new Tab("2-2-2-2",
						 "0-0-0-0",
						 "0-0-0-0",
						 "0-0-0-0");
	Tab* resultL = new Tab("4-4-0-0",
						   "0-0-0-0",
						   "0-0-0-0",
						   "0-0-0-0");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 2 Left" << endl;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("2-2-2-2",
						 "0-0-0-0",
						 "0-0-0-0",
						 "0-0-0-0");
	Tab* resultR = new Tab("0-0-4-4",
						   "0-0-0-0",
						   "0-0-0-0",
						   "0-0-0-0");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 2 Right" << endl;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2-0-0-0",
						 "2-0-0-0",
						 "2-0-0-0",
						 "2-0-0-0");
	Tab* resultU = new Tab("4-0-0-0",
						   "4-0-0-0",
						   "0-0-0-0",
						   "0-0-0-0");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 2 Up" << endl;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("2-0-0-0",
						 "2-0-0-0",
						 "2-0-0-0",
						 "2-0-0-0");
	Tab* resultD = new Tab("0-0-0-0",
						   "0-0-0-0",
						   "4-0-0-0",
						   "4-0-0-0");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 2 Down" << endl;
	}
	delete testD;
	delete resultD;
}

void No_Move() {
	Tab* testL = new Tab("2000",
		"2000",
		"2000",
		"2000");
	Tab* resultL = new Tab("2000",
		"2000",
		"2000",
		"2000");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 3 Left" << endl;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("0002",
		"0002",
		"0002",
		"0002");
	Tab* resultR = new Tab("0002",
		"0002",
		"0002",
		"0002");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 3 Right" << endl;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2222",
		"0000",
		"0000",
		"0000");
	Tab* resultU = new Tab("2222",
		"0000",
		"0000",
		"0000");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 3 Up" << endl;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("0000",
		"0000",
		"0000",
		"2222");
	Tab* resultD = new Tab("0000",
		"0000",
		"0000",
		"2222");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 3 Down" << endl;
	}
	delete testD;
	delete resultD;
}

void test4(){
	Tab* testL = new Tab("0-0-0-0",
		"0-0-0-0",
		"0-0-0-0",
		"4-4-8-16-");
	Tab* resultL = new Tab("0-0-0-0",
		"0-0-0-0",
		"0-0-0-0",
		"0-8-8-16");
	testL->Print_Tab();
	testL->Move_Tiles_Right();
	testL->Print_Tab();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 4" << endl;
	}
	delete testL;
	delete resultL;
}