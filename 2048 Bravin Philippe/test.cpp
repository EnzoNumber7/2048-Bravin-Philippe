#include "tuile.h"
#include "tab.h""
#include "test.h""

#include <iostream>
using namespace std;

int Merge_Prio() {
	Tab* testL = new Tab("2-2-0-4-",
						"0-0-0-0-",
						"0-0-0-0-",
						"0-0-0-0-");
	Tab* resultL = new Tab("4-4-0-0-",
						   "0-0-0-0-",
						   "0-0-0-0-",
						   "0-0-0-0-");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 1 Left" << endl;
		delete testL;
		delete resultL;
		return 0;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("4-0-2-2-",
						"0-0-0-0-",
						"0-0-0-0-",
						"0-0-0-0-");
	Tab* resultR = new Tab("0-0-4-4-",
						  "0-0-0-0-",
						  "0-0-0-0-",
						  "0-0-0-0-");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 1 Right" << endl;
		delete testR;
		delete resultR;
		return 0;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2-0-0-0-",
						"2-0-0-0-",
						"0-0-0-0-",
						"4-0-0-0-");
	Tab* resultU = new Tab("4-0-0-0-",
						  "4-0-0-0-",
						  "0-0-0-0-",
						  "0-0-0-0-");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 1 Up" << endl;
		delete testU;
		delete resultU;
		return 0;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("4-0-0-0-",
						"0-0-0-0-",
						"2-0-0-0-",
						"2-0-0-0-");
	Tab* resultD = new Tab("0-0-0-0-",
						  "0-0-0-0-",
						  "4-0-0-0-",
						  "4-0-0-0-");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 1 Down" << endl;
		delete testD;
		delete resultD;
		return 0;
	}
	delete testD;
	delete resultD;
	return 1;
}

int Double_Merge() {
	Tab* testL = new Tab("2-2-2-2-",
						 "0-0-0-0-",
						 "0-0-0-0-",
						 "0-0-0-0-");
	Tab* resultL = new Tab("4-4-0-0-",
						   "0-0-0-0-",
						   "0-0-0-0-",
						   "0-0-0-0-");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 2 Left" << endl;
		delete testL;
		delete resultL;
		return 0;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("2-2-2-2-",
						 "0-0-0-0-",
						 "0-0-0-0-",
						 "0-0-0-0-");
	Tab* resultR = new Tab("0-0-4-4-",
						   "0-0-0-0-",
						   "0-0-0-0-",
						   "0-0-0-0-");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 2 Right" << endl;
		delete testR;
		delete resultR;
		return 0;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2-0-0-0-",
						 "2-0-0-0-",
						 "2-0-0-0-",
						 "2-0-0-0-");
	Tab* resultU = new Tab("4-0-0-0-",
						   "4-0-0-0-",
						   "0-0-0-0-",
						   "0-0-0-0-");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 2 Up" << endl;
		delete testU;
		delete resultU;
		return 0;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("2-0-0-0-",
						 "2-0-0-0-",
						 "2-0-0-0-",
						 "2-0-0-0-");
	Tab* resultD = new Tab("0-0-0-0-",
						   "0-0-0-0-",
						   "4-0-0-0-",
						   "4-0-0-0-");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 2 Down" << endl;
		delete testD;
		delete resultD;
		return 0;
	}
	delete testD;
	delete resultD;
	return 1;
}

int No_Move() {
	Tab* testL = new Tab("2-0-0-0-",
						 "2-0-0-0-",
						 "2-0-0-0-",
						 "2-0-0-0-");
	Tab* resultL = new Tab("2-0-0-0-",
						   "2-0-0-0-",
						   "2-0-0-0-",
						   "2-0-0-0-");
	testL->Move_Tiles_Left();
	if (not testL->CompareTab(resultL)) {
		cout << "ERREUR TEST 3 Left" << endl;
		delete testL;
		delete resultL;
		return 0;
	}
	delete testL;
	delete resultL;

	Tab* testR = new Tab("0-0-0-2-",
						 "0-0-0-2-",
						 "0-0-0-2-",
						 "0-0-0-2-");
	Tab* resultR = new Tab("0-0-0-2-",
						   "0-0-0-2-",
						   "0-0-0-2-",
						   "0-0-0-2-");
	testR->Move_Tiles_Right();
	if (not testR->CompareTab(resultR)) {
		cout << "ERREUR TEST 3 Right" << endl;
		delete testR;
		delete resultR;
		return 0;
	}
	delete testR;
	delete resultR;

	Tab* testU = new Tab("2-2-2-2-",
		"0-0-0-0-",
		"0-0-0-0-",
		"0-0-0-0-");
	Tab* resultU = new Tab("2-2-2-2-",
		"0-0-0-0-",
		"0-0-0-0-",
		"0-0-0-0-");
	testU->Move_Tiles_Up();
	if (not testU->CompareTab(resultU)) {
		cout << "ERREUR TEST 3 Up" << endl;
		delete testU;
		delete resultU;
		return 0;
	}
	delete testU;
	delete resultU;

	Tab* testD = new Tab("0-0-0-0-",
		"0-0-0-0-",
		"0-0-0-0-",
		"2-2-2-2-");
	Tab* resultD = new Tab("0-0-0-0-",
		"0-0-0-0-",
		"0-0-0-0-",
		"2-2-2-2-");
	testD->Move_Tiles_Down();
	if (not testD->CompareTab(resultD)) {
		cout << "ERREUR TEST 3 Down" << endl;
		delete testD;
		delete resultD;
		return 0;
	}
	delete testD;
	delete resultD;
	return 1;
}

int Test_Win(){
	Tab* test = new Tab("0-0-0-0-",
						 "0-2048-0-0-",
						 "0-0-0-0-",
						 "0-0-0-0-");
	if (not test->Win()) {
		cout << "ERREUR TEST Win" << endl;
		delete test;
		return 0;
	}
	return 1;
}

int Test_Lose() {
	Tab* test = new Tab("2-2-2-2-",
		"2-2-2-2-",
		"2-2-2-2-",
		"2-2-2-2-");
	if (test->Loose()) {
		cout << "ERREUR TEST not Lose" << endl;
		delete test;
		return 0;
	}
	delete test;

	Tab* testL = new Tab("2-4-8-16-",
		"4-8-16-2-",
		"2-4-8-16-",
		"4-8-16-2-");
	if (not testL->Loose()) {
		cout << "ERREUR TEST Lose" << endl;
		delete testL;
		return 0;
	}
	return 1;
}
