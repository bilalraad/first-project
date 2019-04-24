#include "enterbykeyboard.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> 
#include<sstream>
#include<iomanip>
#include"avgngrd.h"
#include"printtxt.h"

using namespace std;

enterbykeyboard::enterbykeyboard()
{
}


void enterbykeyboard::by()
{
	printtxt t; string time;
	avgngrd prnt;int n, x,tot;
	w.open("C:/Users/BILAL/Desktop/Enterdfile.txt");
	if (w.fail())

	{
		cout << "error" << endl;
		exit(0);
	}
	
	
	
	cout << "Enter the the number of students:";
	cin >> x;
	cout << "enter how many marks you want for each : ";
	cin >> n;
	int *mark (new int[n]);
	string *names ( new string[x]);

	  w << "name" << setw(12) << "Marks "
		<< setw(18) << "Avarege" << setw(18) 
	    << "Total" << setw(22) << "Grade" << endl
		<< string(100, '-') << endl;

	for (int i = 0; i < x; i++)
	{
		i == 0 ? cout << "first name: " : cout << "next name: "; 
		cin.ignore(); //to clear the cin stream buffer by using cin.ignore() before cin.getline()
		getline(cin,names[i]);
		w << setw(9) << left << names[i] << "|";
		tot = 0;
		for (int w = 0; w < n; w++)
		{
			w == 0 ? cout << "first mark: " : cout << "next mark: ";
			  cin >> mark[w]; 
			  tot += mark[w];
		}//end of nested for loop

		for (int i = 0; i < n; i++) { w << mark[i] << " "; }
		double avg = (float)tot / n;


	      w << setw(11) << right
		    << "|" << setw(5) << setprecision(2) << fixed << avg << setw(16)
			<< "|" << left << tot << setw(20)<<right
			<< "|" << prnt.getgrade(avg) << endl;
	}//end of for loop
	cout << endl<<endl;
	t.getTime(time);
	w << endl << "last update since: " << time;
	delete[] mark;
	delete[] names;
	
}
