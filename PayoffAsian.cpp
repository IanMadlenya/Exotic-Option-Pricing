#include "PayoffAsian.h"
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

double average(vector<double> &vec){
	unsigned long n = vec.size();

	if(n==0)
		return 0;

	double sum =0.0;
	for (int i = 0; i < vec.size(); ++i){
		sum+=vec[i];
	}

	return sum/(double)n;
}



PayoffAsianCall::PayoffAsianCall(double strike):PayoffCall(strike){}

double PayoffAsianCall::operator()(vector<double> &vec){
	double aver = average(vec);
	return max((aver-strike_),0.0);
}

PayoffAsianPut::PayoffAsianPut(double strike):PayoffPut(strike){}

double PayoffAsianPut::operator()(vector<double> &vec){
	double aver = average(vec);
	return max((strike_-aver),0.0);
}
