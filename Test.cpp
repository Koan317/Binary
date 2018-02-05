#include <iostream>
#include "Binary.h"
using namespace std;

int main()
{
	Binary a("11111111000000000000000000000000");
	a <<= 2;
	cout << a;
	getchar();
	return 0;
}