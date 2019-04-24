#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> 
#include<sstream>
#include<iomanip>
#include"avgngrd.h"
#include"printtxt.h"
#include "enterbykeyboard.h"


using namespace std;


void main()
{
	string dt;
	int choise;
	printtxt print;
	enterbykeyboard bykeyboard;
	do {
		cout << "PS: Enter 0 to exit" << "\nIf you enter '1' the program will export sourse file"
			<< "\nIf you want to make new list enter '2' : ";
		cin >> choise;

		if (choise == 1) print.func();
		else if (choise == 2) bykeyboard.by();
		else if (choise == 0)  exit(0);
		else cout << "\n\npleas enter either 1 or 2 or 0\n\n\n";
	} while (choise != 1 || choise != 2 || choise != 0);
	
	cout << endl << "The file has been generated in your desktop." << endl << endl;
	print.getTime(dt);
	cout << dt << endl;
	system("pause");
}

 