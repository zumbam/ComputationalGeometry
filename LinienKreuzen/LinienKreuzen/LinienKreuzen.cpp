// LinienKreuzen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Strecke.h"
using namespace std;





int main()
{
	//irgendwas stimmt da nicht
	Strecke strecke1 =Strecke(1.0f,0.0f,0.0f,1.0f);
	Strecke strecke2 = Strecke(0, 0, 1, 1);
	if (strecke1%strecke2)
	{
		cout << "Schneiden sich!" << endl;
	}
	else
	{
		cout << "Schneiden sich nicht!" << endl;
	}



	int i;
	cin >> i;
    return 0;
}

