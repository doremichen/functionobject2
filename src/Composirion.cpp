//============================================================================
// Name        : Composirion.cpp
// Author      : Adam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Composition.h"
using namespace std;

int f(int a)
{
	return a+1;
}

int g(int b)
{
	return b+1;
}

int h(int c)
{
	return c+1;
}


int main() {

	Composition<int, int> fg(f, g);
	Composition<int, int> fgh(fg, g);

	cout << fg(40) << endl;
	cout << fgh(40) << endl;

//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
