#include "tab.h"
#include <iostream>
#include <stdlib.h>

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
		t_tab[X][Y]->Change_Pos(X, Y);
	}
	
}
void Tab::Move_Tiles()
{

}
void Tab::Merge_Tiles()
{

}
void Tab::Delete_Tiles()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (t_valueTab[i][j] != 0) {
				delete(t_tab[i][j]);
				t_valueTab[i][j] = 0;
			}
		}
	}
}
void Tab::Delete_Tile(int pos_X,int pos_Y)
{
	delete(t_tab[pos_X][pos_Y]);
	t_tab[pos_X][pos_Y] = 0;
}
Tab::~Tab()
{
	Delete_Tiles();
}
