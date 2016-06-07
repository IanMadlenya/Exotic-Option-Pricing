#ifndef __PayoffPower__
#define __PayoffPower__

#include "Payoff.h"
using namespace std;


class PayoffPowerCall: public PayoffCall{
	public:
		PayoffPowerCall(double strike, int power);
		virtual double operator()(double spot);

		//virtual ~PayoffPowerCall(){};

	protected: 
		int power_;
};

class PayoffPowerPut: public PayoffPut{
	public:
		PayoffPowerPut(double strike, int power);
		virtual double operator()(double spot);

		// virtual ~PayoffPowerPut(){};

	protected: 
		int power_;
};



#endif