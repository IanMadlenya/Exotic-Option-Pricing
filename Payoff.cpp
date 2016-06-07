#include "Payoff.h"
#include <algorithm>
using namespace std;

PayoffCall::PayoffCall(double strike):strike_(strike){}

double PayoffCall::operator()(double spot){
	return max(spot-strike_, 0.0);
}


PayoffPut::PayoffPut(double strike):strike_(strike){}

double PayoffPut::operator()(double spot){
	return max(strike_-spot,0.0);
}
