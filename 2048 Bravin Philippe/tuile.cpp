#include "tuile.h"
#include <iostream>
#include <stdlib.h>  

using namespace std;

Tile::Tile() 
{
	t_pos_X = -1;
	t_pos_Y = -1;

	// Génération Aléatoire de la valeur entre 2 et 4
	int tab[10] = { 2,2,2,2,2,2,2,2,2,4 };
	int i = rand() % 10;
	t_value = tab[i];
}

Tile::Tile(int value, int pos_X, int pos_Y) 
{
	t_pos_X = pos_X;
	t_pos_Y = pos_Y;
	t_value = value;
}

int Tile::Get_Value()
{
	return (t_value);
}

int Tile::Get_Pos()
{
	return(t_pos_X, t_pos_Y);
}

void Tile::Change_Pos(int pos_X,int pos_Y)
{
	t_pos_X = pos_X;
	t_pos_Y = pos_Y;
}

Tile::~Tile() 
{
}