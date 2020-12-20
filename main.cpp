#include <iostream>
#include "ups.hpp"
#include <windows.h>

using std::cout;
using std::endl;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    ups ippon1;

    ups ippon2("IPPON", ups::Euro, 3, 400, 10);

    cout << ippon2 << endl;

    return 0;
}
