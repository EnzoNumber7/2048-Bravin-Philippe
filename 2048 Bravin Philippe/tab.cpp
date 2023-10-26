#include "tab.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Tab::Tab()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			t_valueTab[i][j] = 0;
		}
	}
}
void Tab::Print_Tab()
{
	for (int i = 0; i < 4 ; i++) {
		for (int j = 0; j < 4 ; j++) {
			if (t_valueTab[i][j] == 0) { cout << "|----|";}
			else if (t_valueTab[i][j] < 10) { cout << "|---" << t_valueTab[i][j] << "|";}
			else if (t_valueTab[i][j] < 100) { cout << "|--" << t_valueTab[i][j] << "|";}
			else if(t_valueTab[i][j] < 1000) { cout << "|-" << t_valueTab[i][j] << "|"; }
			else{ cout << "|" << t_valueTab[i][j] << "|"; }
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
		t_valueTab[pos_X][pos_Y] = value;
		t_tab[pos_X][pos_Y] = new Tile(value);
	}

	
}
void Tab::Move_Tiles_Left()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (t_valueTab[i][j + 1]!=0) {
				if (t_valueTab[i][j] == 0){
					t_tab[i][j] = t_tab[i][j + 1];
					t_tab[i][j + 1] = NULL;
					t_valueTab[i][j] = t_valueTab[i][j + 1];
					t_valueTab[i][j + 1] = 0;

					Move_Tiles_Left();
				}
				else if (t_valueTab[i][j] == t_valueTab[i][j + 1] and t_tab[i][j + 1]->Get_Merge() == false){
					t_tab[i][j + 1]->Change_Bool(true);
					Merge_Tiles(4, t_valueTab[i][j], i, j);
				}
			}
		}
	}
}

void Tab::Move_Tiles_Right()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (t_valueTab[i][j] != 0 ) {
				if (t_valueTab[i][j + 1] == 0) {
					t_tab[i][j + 1] = t_tab[i][j];
					t_tab[i][j] = NULL;
					t_valueTab[i][j + 1] = t_valueTab[i][j];
					t_valueTab[i][j] = 0;

					Move_Tiles_Right();
				}
				else if (t_valueTab[i][j] == t_valueTab[i][j + 1] and t_tab[i][j]->Get_Merge() == false) {
					t_tab[i][j + 1]->Change_Bool(true);
					Merge_Tiles(6, t_valueTab[i][j], i, j + 1);
				}
			}
		}
	}
}

void Tab::Move_Tiles_Up()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i + 1][j] != 0) {
				if (t_valueTab[i][j] == 0) {
					t_tab[i][j] = t_tab[i + 1][j];
					t_tab[i + 1][j] = NULL;
					t_valueTab[i][j] = t_valueTab[i + 1][j];
					t_valueTab[i + 1][j] = 0;

					Move_Tiles_Up();
				}
				else if (t_valueTab[i + 1][j] == t_valueTab[i][j] and t_tab[i + 1][j]->Get_Merge() == false) {
					t_tab[i + 1][j]->Change_Bool(true);
					Merge_Tiles(8, t_valueTab[i][j], i, j);
				}
			}
		}
	}
}

void Tab::Move_Tiles_Down()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] != 0 ) {
				if (t_valueTab[i + 1][j] == 0) {
					t_tab[i + 1][j] = t_tab[i][j];
					t_tab[i][j] = NULL;
					t_valueTab[i + 1][j] = t_valueTab[i][j];
					t_valueTab[i][j] = 0;

					Move_Tiles_Down();
				}
				else if (t_valueTab[i + 1][j] == t_valueTab[i][j] and t_tab[i][j]->Get_Merge() == false) {
					t_tab[i + 1][j]->Change_Bool(true);
					Merge_Tiles(2, t_valueTab[i][j], i + 1, j);
				}
			}
		}
	}

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
void Tab::Delete_Tile(int pos_X,int pos_Y)
{
	delete(t_tab[pos_X][pos_Y]);
	t_valueTab[pos_X][pos_Y] = 0;
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
Tab::~Tab()
{
	Delete_Tiles();
}
