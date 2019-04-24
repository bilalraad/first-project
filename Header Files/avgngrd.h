#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string> 
#include<sstream>
#include<iomanip>


using namespace std;
#ifndef avgngrd_HEADER
#define avgngrd_HEADER
class avgngrd {
	public:
	double get_avg_and_tot(string b,int &tot)
	{
		int t = 0;
			string avg;
		 int x (0); //"x" to calculate the number of grades for each line
		istringstream iss(b);
		while (!iss.eof()) {
		
			getline(iss, avg, ',');//to "cin" the string in the avg without ',' 
			t += atoi(avg.c_str());
			x++;
	//this func. "atoi(avg.c_str())" convert the decleration type "string" to old type or int type
	//its library is <cstdlib>
		}
		tot = t;
		float average = (float)t / x;
		return average;
	}


	void getmarks(const string c)
	{
		int x (0);
		string grd;
		istringstream iss(c);
		cout << setw(10);
		while (!iss.eof()) 
		{
			getline(iss, grd, ',');
			x = atoi(grd.c_str());
			cout << x << " ";
		}

	}

	char getgrade(double c)
	{

		if (c >= 90.0) return 'A';
		else if (c >= 80.0&&c<90.0) return 'B';
		else if (c >= 70.0&&c<80.0) return 'C';
		else if (c >= 60.0&&c<70.0) return 'D';
		else if (c >= 50.0&&c<60.0) return 'E';
		else return 'F';
		
	
	}


	void printstuff()
	{
	
		cout<<setfill(' ') 
			<< "name" << setw(23) 
			<< "Marks " << setw(25) 
			<< "avarege" << setw(27) 
			<< "total" << setw(25) 
			<< "Grade" << endl << string(100, '-') << endl;


	}




}; 
#endif