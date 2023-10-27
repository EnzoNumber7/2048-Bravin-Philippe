#include "tab.h"
#include <iostream>
#include <stdlib.h>
#include <string>

#include <typeinfo>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define CYN   "\x1B[36m"
#define MAG   "\x1B[35m"
#define RESET "\x1B[0m"

using namespace std;

// ---------- CONSTRUCTEUR ---------- //
Tab::Tab()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			t_valueTab[i][j] = 0;
			t_tab[i][j] = NULL;
		}
	}
}
Tab::Tab(string line1, string line2, string line3, string line4)
{
	string temp;
	int index = 0;
	for (int j = 0; j < line1.length(); j++) {
		if (line1[j] != '-') {
			temp += line1[j];
		}
		else if (line1[j] == '-') {
			t_valueTab[0][index] = stoi(temp);
			t_tab[0][index] = new Tile(stoi(temp));
			temp = '0';
			index += 1;
		}
	}
	temp = '0';
	index = 0;
	for (int j = 0; j < line2.length(); j++) {
		if (line2[j] != '-') {
			temp += line2[j];
		}
		else if (line2[j] == '-') {
			t_valueTab[1][index] = stoi(temp);
			t_tab[1][index] = new Tile(stoi(temp));
			temp = '0';
			index += 1;
		}
	}
	index = 0;
	temp = '0';
	for (int j = 0; j < line3.length(); j++) {
		if (line3[j] != '-') {
			temp += line3[j];
		}
		else if (line3[j] == '-') {
			t_valueTab[2][index] = stoi(temp);
			t_tab[2][index] = new Tile(stoi(temp));
			temp = '0';
			index += 1;
		}
	}
	index = 0;
	temp = '0';
	for (int j = 0; j < line4.length(); j++) {
		if (line4[j] != '-') {
			temp += line4[j];
		}
		else if (line4[j] == '-') {
			t_valueTab[3][index] = stoi(temp);
			t_tab[3][index] = new Tile(stoi(temp));
			temp = '0';
			index += 1;
		}
	}
}

// ---------- METHODE ---------- //

void Tab::Print_Tab()

{
	system("cls");
	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4 ; j++) {
			if (t_valueTab[i][j] == 0) { cout << "|    |";}
			else if (t_valueTab[i][j] < 10) { cout << "|   " <<CYN<< t_valueTab[i][j]<<RESET << "|";}
			else if (t_valueTab[i][j] < 100) { cout << "|  " <<GRN<< t_valueTab[i][j]<<RESET << "|";}
			else if(t_valueTab[i][j] < 1000) { cout << "| " <<RED<< t_valueTab[i][j]<<RESET << "|"; }
			else{ cout << "|" <<MAG<< t_valueTab[i][j]<<RESET << "|"; }
		}
		cout << endl;
	}
	cout << endl;
}
void Tab::Create_Tiles(int pos_X,int pos_Y,int value)
{
	
	if (pos_X == -1 and pos_Y == -1) {
		int X = rand() % 4;
		int Y = rand() % 4;
		if (t_valueTab[X][Y] != NULL) {
			Create_Tiles();
		}
		else
		{
			
			t_tab[X][Y] = new Tile();
			t_valueTab[X][Y] = t_tab[X][Y]->Get_Value();
		}
	}
	else {
		if (pos_X < 4 and pos_Y < 4 and pos_X >= 0 and pos_Y >= 0) {
			t_valueTab[pos_X][pos_Y] = value;
			t_tab[pos_X][pos_Y] = new Tile(value);
		}
		
	}

	
}
int Tab::Move_Tiles_Left()
{
	int nb_move = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (t_valueTab[i][j + 1]!=0) {
				if (t_valueTab[i][j] == 0){
					t_tab[i][j] = t_tab[i][j + 1];
					t_tab[i][j + 1] = NULL;
					t_valueTab[i][j] = t_valueTab[i][j + 1];
					t_valueTab[i][j + 1] = 0;
					nb_move += 1;
					return Move_Tiles_Left() + nb_move;
				}
				else if (t_valueTab[i][j] == t_valueTab[i][j + 1] and t_tab[i][j]->Get_Merge() == false and t_tab[i][j + 1]->Get_Merge() == false){
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(4, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
}

int Tab::Move_Tiles_Right()
{
	int nb_move = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 1; j--) {
			if (t_valueTab[i][j - 1] != 0 ) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i][j - 1];
					t_tab[i][j - 1] = NULL;
					t_valueTab[i][j] = t_valueTab[i][j - 1];
					t_valueTab[i][j - 1] = 0;

					nb_move += 1;
					return Move_Tiles_Right() + nb_move;
				}
				else if (t_valueTab[i][j] == t_valueTab[i][j - 1] and t_tab[i][j]->Get_Merge() == false and t_tab[i][j - 1]->Get_Merge() == false) {
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(6, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
}

int Tab::Move_Tiles_Up()
{
	int nb_move = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i + 1][j] != 0) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i + 1][j];
					t_tab[i + 1][j] = NULL;
					t_valueTab[i][j] = t_valueTab[i + 1][j];
					t_valueTab[i + 1][j] = 0;

					nb_move += 1;
					return Move_Tiles_Up() + nb_move;
				}
				else if (t_valueTab[i + 1][j] == t_valueTab[i][j] and t_tab[i][j]->Get_Merge() == false and t_tab[i + 1][j]->Get_Merge() == false) {
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(8, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
}

int Tab::Move_Tiles_Down()
{
	int nb_move = 0;
	for (int i = 3; i >= 1; i--) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i - 1][j] != 0 ) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i - 1][j];
					t_tab[i - 1][j] = NULL;
					t_valueTab[i][j] = t_valueTab[i - 1][j];
					t_valueTab[i - 1][j] = 0;

					nb_move += 1;
					return Move_Tiles_Down() + nb_move;
				}
				else if (t_valueTab[i - 1][j] == t_valueTab[i][j] and t_tab[i][j]->Get_Merge() == false and t_tab[i - 1][j]->Get_Merge() == false) {
					nb_move += 1;
					t_tab[i][j]->Change_Bool(true);
					Merge_Tiles(2, t_valueTab[i][j], i, j);
				}
			}
		}
	}
	return nb_move;
} 

void Tab::Merge_Tiles(int direction, int value, int pos_X, int pos_Y)
{
	if (direction == 4) {
		Delete_Tile(pos_X, pos_Y + 1);
		t_tab[pos_X][pos_Y]->Change_Value(value*2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	else if (direction == 8) {
		Delete_Tile(pos_X + 1, pos_Y);
		t_tab[pos_X][pos_Y]->Change_Value(value * 2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	else if (direction == 6) {
		Delete_Tile(pos_X, pos_Y - 1);
		t_tab[pos_X][pos_Y]->Change_Value(value * 2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
	else if (direction == 2) {
		Delete_Tile(pos_X - 1, pos_Y);
		t_tab[pos_X][pos_Y]->Change_Value(value * 2);
		t_valueTab[pos_X][pos_Y] = value * 2;
	}
}
void Tab::Reset_Bool()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (t_valueTab[i][j] != 0) {
				t_tab[i][j]->Change_Bool(false);
			}
		}
	}
}


bool Tab::Win()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] == 2048) {
				return (true);
			}
		}
	}
	return(false);
}
bool Tab::Loose()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i>0 and i<3 and j>0 and j<3){
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i > 0 and i < 3 and j>0) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1]) {
					return (false);
				}
			}
			else if (i > 0 and i < 3 and j<3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i > 0 and j > 0 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i < 3 and j >0 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i > 0 and j>0) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1]) {
					return (false);
				}
			}
			else if (i < 3 and j>0) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j - 1]) {
					return (false);
				}
			}
			else if (i > 0 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i - 1][j] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
			else if (i < 3 and j < 3) {
				if (t_valueTab[i][j] == 0 or t_valueTab[i][j] == t_valueTab[i + 1][j] or t_valueTab[i][j] == t_valueTab[i][j + 1]) {
					return (false);
				}
			}
		}
	}
	return (true);
}

void Tab::Delete_Tile(int pos_X, int pos_Y)
{
	delete(t_tab[pos_X][pos_Y]);
	t_valueTab[pos_X][pos_Y] = 0;
}

// ---------- TEST ---------- //

bool Tab::CompareTab(Tab* resultTab)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (resultTab->t_valueTab[i][j] != t_valueTab[i][j]) {
				return false;
			}
		}
	}
	return true;
}

// ---------- DESTRUCTEUR ---------- //

void Tab::Delete_Tiles()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] != 0) {
				delete(t_tab[i][j]);
			}
		}
	}
}

Tab::~Tab()
{
	Delete_Tiles();
}
