#ifndef __Payoff__
#define __Payoff__

#include <iostream>


class Payoff{
	public:
		Payoff(){};
		virtual ~Payoff(){};

		virtual double operator()(double spot)=0;

};

class PayoffCall: public Payoff{
	public:
		PayoffCall(double strike);
		virtual ~PayoffCall(){};

		virtual double operator()(double spot);

	protected:
		double strike_;
};

class PayoffPut: public Payoff{
	public:	
		PayoffPut(double strike);
		virtual ~PayoffPut(){};

		virtual double operator()(double spot);

	protected:
		double strike_;

};

#endif