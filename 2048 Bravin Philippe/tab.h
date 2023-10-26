#pragma once
#include "tuile.h"
#include <string>

class Tab : Tile
{
private:
	Tile* t_tab[4][4];
	int t_valueTab[4][4];

public:

	Tab();
	void Print_Tab();
	void Create_Tiles(int pos_X = -1, int pos_Y = -1, int value = 2);
	void Move_Tiles_Left();
	void Move_Tiles_Right();
	void Move_Tiles_Up();
	void Move_Tiles_Down();
	void Merge_Tiles(int direction,int value, int pos_X, int pos_Y);
	void Reset_Bool();
	void Delete_Tiles();
	void Delete_Tile(int pos_X,int pos_Y);
	bool Win();
	bool Loose();

	~Tab();
};