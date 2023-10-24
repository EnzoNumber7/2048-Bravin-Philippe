#pragma once

class Tile
{
private:
	int t_value;
	int t_pos_X;
	int t_pos_Y;

public:

	Tile();
	Tile(int value, int pos_X, int pos_Y);

	int Get_Value();
	int Get_Pos();
	void Change_Pos(int pos_X, int pos_Y);

	~Tile();
};