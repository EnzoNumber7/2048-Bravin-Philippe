#include <string>
#include <iostream>
#include "tuile.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    Tuile* t = new Tuile();

    t->Test();

    delete t;

    return 0;
}
