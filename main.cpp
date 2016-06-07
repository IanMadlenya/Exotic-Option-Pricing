#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "Payoff.h"
#include "PayoffAsian.h"
#include "PayoffPower.h"

using namespace std;

bool readFile(const char* filename, vector<double> &vec);


int main(int argc, char const *argv[])
{
	vector<double> AAPL_Aug;
	const char* filename = "./AAPL_close_2015.csv";

	if(!readFile(filename, AAPL_Aug)){
		return -1;
	}

	PayoffAsianCall payoff_asian(105.0);
	cout<<"[Asian Option] Payoff Call: "<<payoff_asian(AAPL_Aug)<<endl;
	
	PayoffPowerCall payoff_power(100.0, 2);
	cout<<"[Power Option] Payoff call: "<<payoff_power(11.0)<<"\n";
	
	return 0;
}

bool readFile(const char* filename, vector<double> &vec){
	int i=0;
	int len_head = 1;

	string header;
	string price;
	string date;

	ifstream infile(filename);

	if(!infile){
		cerr<<"[WARNING] File Cannot Open\n";
		return false; 
	}

	for (int i = 0; i < len_head; ++i){
		getline(infile, header, '\n');
	}

	while(!infile.eof()){
		getline(infile, date, ',');
		getline(infile, price, '\n');

		if(date>=string("2015-08-01") && date<=string("2015-08-31")){
			vec.push_back(atof(price.c_str()));
		}
	}

	infile.close();
	return true;


}