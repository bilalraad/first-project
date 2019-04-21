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
	double getavg(string b)
	{
			string avg;
		 int tot=0, x = 0; //"x" to calculate the number of grades for each line
		istringstream iss(b);
		while (!iss.eof()) {
			getline(iss, avg, ',');//to "cin" the string in the avg without ',' 
			tot += atoi(avg.c_str());
			x++;
	//this func. "atoi(avg.c_str())" convert the decleration type "string" to old type or int type
	//its library is <cstdlib>
		}
		float average = (float)tot / x;
		return average;
	}
	void getmarks(string c)
	{
		int x = 0;
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
	int gettot(string c)
	{
		int tot = 0;
		string mark;
		istringstream iss(c);
		cout << setw(10);
		while (!iss.eof())
		{
			getline(iss, mark, ',');
			tot += atoi(mark.c_str());
			
		}
		return tot;
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