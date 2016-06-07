#ifndef __PayoffAsian__
#define __PayoffAsian__

#include "Payoff.h"
#include <vector>

using namespace std;



class PayoffAsianCall: public PayoffCall{
	public:
		PayoffAsianCall(double strike);
		virtual ~PayoffAsianCall(){};

		virtual double operator()(vector<double> &spot);
};

class PayoffAsianPut: public PayoffPut{
	public:
		PayoffAsianPut(double strike);
		virtual ~PayoffAsianPut(){};

		virtual double operator()(vector<double> &spot);
};

#endif