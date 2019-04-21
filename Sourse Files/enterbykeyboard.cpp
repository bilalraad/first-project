#include "enterbykeyboard.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> 
#include<sstream>
#include<iomanip>
#include"avgngrd.h"
#include"printtxt.h"
#include<vector>

using namespace std;

enterbykeyboard::enterbykeyboard()
{
}


void enterbykeyboard::by()
{
	printtxt t; string time;
	avgngrd prnt;
	w.open("C:/Users/BILAL/Desktop/test.txt");
	if (w.fail())

	{
		cout << "error" << endl;
		exit(0);
	}
	
	
	int n, x,tot;
	cout << "enter how many marks you want for each : ";
	cin >> n;
	cout << "the the number of student:";
	cin >> x;
	int *p = new int[n];
	string *ptr = new string[x];

	w << "name" << setw(12) << "Marks "
		<< setw(18) << "Avarege" << setw(18) << "Total" << setw(22) << "Grade" << endl
		<< string(100, '-') << endl;
	for (int i = 0; i < x; i++)
	{
		{if (i == 0)
			cout << "first name: ";
		else
			cout << "next name: "; }
		cin.ignore();//to clear the cin stream buffer by using cin.ignore() before cin.getline()
		getline(cin,ptr[i]);
		w << setw(9) << left << ptr[i] << "|";
		tot = 0;
		for (int w = 0; w < n; w++)
		{
			
			if (w == 0)
				cout << "first grade: ";
			else
				cout << "next grade: ";

			  cin >> p[w]; 
			  tot += p[w];
		}//end of nested for loop

		for (int i=0;i<n;i++)
			w << p[i]<<" ";
		double avg = (float)tot / n;
		w << setw(11) << right;
		w << "|" << setw(5) << setprecision(2) << fixed << avg << setw(16)
			<< "|" << left << tot << setw(20)<<right
			<< "|" << prnt.getgrade(avg) << endl;
	}//end of for loop
	cout << endl<<endl;
	t.getTime(time);
	w << endl << "last update since: " << time;
	delete[] p;
	delete[] ptr;
	
}
