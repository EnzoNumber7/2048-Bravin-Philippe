#include "tuile.h"
#include "tab.h""
#include "test.h""

#include <iostream>
using namespace std;

void Merge_Prio() {
	Tab* testL = new Tab("0222",
						"0000",
						"0000",
						"0000");
	Tab* resultL = new Tab("4200",
						   "0000",
						   "0000",
						   "0000");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 1 Left" << endl;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("2220",
						"0000",
						"0000",
						"0000");
	Tab* resultR = new Tab("0024",
						  "0000",
						  "0000",
						  "0000");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 1 Right" << endl;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("0000",
						"2000",
						"2000",
						"2000");
	Tab* resultU = new Tab("4000",
						  "2000",
						  "0000",
						  "0000");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 1 Up" << endl;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("2000",
						"2000",
						"2000",
						"0000");
	Tab* resultD = new Tab("0000",
						  "0000",
						  "2000",
						  "4000");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 1 Down" << endl;
	}
	delete testD;
	delete resultD;
}

void Double_Merge() {
	Tab* testL = new Tab("2222",
						 "0000",
						 "0000",
						 "0000");
	Tab* resultL = new Tab("4400",
						   "0000",
						   "0000",
						   "0000");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 2 Left" << endl;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("2222",
						 "0000",
						 "0000",
						 "0000");
	Tab* resultR = new Tab("0044",
						   "0000",
						   "0000",
						   "0000");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 2 Right" << endl;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2000",
						 "2000",
						 "2000",
						 "2000");
	Tab* resultU = new Tab("4000",
						   "4000",
						   "0000",
						   "0000");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 2 Up" << endl;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("2000",
						 "2000",
						 "2000",
						 "2000");
	Tab* resultD = new Tab("0000",
						   "0000",
						   "4000",
						   "4000");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 2 Down" << endl;
	}
	delete testD;
	delete resultD;
}
