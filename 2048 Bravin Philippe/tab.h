#pragma once
#include "tuile.h"

class Tab : Tile
{
private:
	Tile* t_tab[4][4];
	int t_valueTab[4][4];

public:

	Tab();
	void Print_Tab();
	void Create_Tiles();
	void Move_Tiles();
	void Merge_Tiles();
	void Delete_Tiles();
	void Delete_Tile(int pos_X,int pos_Y);

	~Tab();
};