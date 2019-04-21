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
	cout << "if you enter num. 1 the program will export the file from the drive"
		<< "\n but if you wan to enter new list enter num. 0: ";
	cin >> choise;
	printtxt print;
	enterbykeyboard bykeyboard;
	if (choise == 1)
		print.func();
	else if (choise == 0)
		bykeyboard.by();
	else
		cout << "pleas enter either 1 or 0";

	cout << endl << "test.txt has been generated." << endl << endl;
	print.getTime(dt);
	cout << dt << endl;
	system("pause");
}

 