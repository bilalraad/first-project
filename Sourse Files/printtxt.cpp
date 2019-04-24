
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> 
#include<sstream>
#include<iomanip>
#include "printtxt.h"
#include"avgngrd.h"
#pragma warning(disable : 4996)//to pass security error of getTime func.
#include <ctime>

using namespace std;
void printtxt::getTime( string &t)
{
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	t = dt;
}
void printtxt::func()
{
     string Time;
	g.open("C:/Users/BILAL/Desktop/soursefile.txt");//to open the file from comp.
	s.open("C:/Users/BILAL/Desktop/printfile.txt");//to creat the file & thier lib. is <fstream>
		if (g.fail()|| s.fail())
			//cheking if the file excist or NOT and if he can make the file 
			//the library of this opreation is <cstdlib>
		{
			cout << "error" << endl;
			exit(0);
		}
		
		b.printstuff();
		s << "name" << setw(12) << "Marks "
			<< setw(25) << "Avarege" << setw(22) << "Total" << setw(22) << "Grade" << endl
			<< string(100, '-') << endl;
		
		while (!g.eof())//if NOT end of file continue the loop
		{
			string name, marks;
			getline(g, a);
			istringstream v(a);
			getline(v, name, ':');//to export names
			getline(v, marks, ':');//to export the marks
			int total ;
			double avg = b.get_avg_and_tot(marks, total);

			cout << setfill(' ') << setw(9) << right << name << "|"; b.getmarks(marks);
			cout << "|" << setw(19) << setprecision(2) << fixed << avg << setw(19)
				 << "|" << total << setw(19) 
				 << "|" << b.getgrade(avg) << endl;

			
			s << setfill(' ') << setw(9) << left << name 
			  << "|" <<setw(23)<< marks <<left
			  << "|" << setprecision(2) << fixed << avg << setw(19) << right
			  << "|" << total << setw(19) << right
			  << "|" << b.getgrade(avg) << endl;
			
			// ""setprecision(2) << fixed"" to convert for ex: 55 to 55.00
			//left or right to set the direction
		}

		cout << endl<<endl;
		getTime(Time);
		s<<endl << "last update since: " << Time;
		g.close();//important for the memory
		s.close();

}









