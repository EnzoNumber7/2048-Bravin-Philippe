#include <string>
#include <iostream>

#include "tuile.h"
#include "tab.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    Tuile* t = new Tuile();

    t->Test();

    delete t;

    return 0;
}
