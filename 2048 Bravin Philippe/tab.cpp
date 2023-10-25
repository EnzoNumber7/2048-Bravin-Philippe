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
			if (t_valueTab[i][j] == 0) { cout << "|0000|";}
			else if (t_valueTab[i][j] < 10) { cout << "|000" << t_valueTab[i][j] << "|";}
			else if (t_valueTab[i][j] < 100) { cout << "|00" << t_valueTab[i][j] << "|";}
			else if(t_valueTab[i][j] < 1000) { cout << "|0" << t_valueTab[i][j] << "|"; }
			else{ cout << "|" << t_valueTab[i][j] << "|"; }
		}
		cout << endl;
	}
	cout << endl;
}
void Tab::Create_Tiles()
{
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
void Tab::Move_Tiles_Left()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (t_valueTab[i][j]!=0){
				if (t_valueTab[i][j-1] == 0){
					t_tab[i][j - 1] = t_tab[i][j];
					t_tab[i][j] = NULL;
					t_valueTab[i][j - 1] = t_valueTab[i][j];
					t_valueTab[i][j] = 0;

					Move_Tiles_Left();
				}
				else if (t_valueTab[i][j - 1] == t_valueTab[i][j]){
					Merge_Tiles(4, t_valueTab[i][j],i,j-1);
				}
			}
		}
	}
}

void Tab::Move_Tiles_Right()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (t_valueTab[i][j] != 0) {
				if (t_valueTab[i][j + 1] == 0) {
					t_tab[i][j + 1] = t_tab[i][j];
					t_tab[i][j] = NULL;
					t_valueTab[i][j + 1] = t_valueTab[i][j];
					t_valueTab[i][j] = 0;

					Move_Tiles_Right();
				}
				else if (t_valueTab[i][j + 1] == t_valueTab[i][j]) {
					Merge_Tiles(4, t_valueTab[i][j], i, j + 1);
				}
			}
		}
	}
}

void Tab::Move_Tiles_Up()
{
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] != 0) {
				if (t_valueTab[i - 1][j] == 0) {
					t_tab[i - 1][j] = t_tab[i][j];
					t_tab[i][j] = NULL;
					t_valueTab[i - 1][j] = t_valueTab[i][j];
					t_valueTab[i][j] = 0;

					Move_Tiles_Up();
				}
				else if (t_valueTab[i - 1][j] == t_valueTab[i][j]) {
					Merge_Tiles(4, t_valueTab[i][j], i - 1, j);
				}
			}
		}
	}
}

void Tab::Move_Tiles_Down()
{

} 
void Tab::Merge_Tiles(int direction, int value, int pos_X, int pos_Y)
{

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
Tab::~Tab()
{
	Delete_Tiles();
}
