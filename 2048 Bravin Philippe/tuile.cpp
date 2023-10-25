#include "tuile.h"
#include <iostream>
#include <stdlib.h>  

using namespace std;

Tile::Tile() 
{

	// Génération Aléatoire de la valeur entre 2 et 4
	int tab[10] = { 2,2,2,2,2,2,2,2,2,4 };
	int i = rand() % 10;
	t_value = tab[i];
}

Tile::Tile(int value) 
{
	t_value = value;
}

int Tile::Get_Value()
{
	return (t_value);
}


Tile::~Tile() 
{
}