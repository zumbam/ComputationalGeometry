// LinienKreuzen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Strecke.h"
using namespace std;





int main()
{
	Strecke strecke =Strecke(1.0f,0.0f,0.0f,1.0f);
	float Ergebnis = strecke.CCW(1.0f, 1.0f);
	cout << Ergebnis << endl;


	int i;
	cin >> i;
    return 0;
}

