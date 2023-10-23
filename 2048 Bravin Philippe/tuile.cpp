#include "tuile.h"
#include <iostream>

using namespace std;

Tuile::Tuile() {
	t_pos_X = -1;
	t_pos_Y = -1;
}

void Tuile::Test() {
	cout << t_pos_X;
}

Tuile::~Tuile() {
}