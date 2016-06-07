#include <algorithm>
#include <math.h>
#include "PayoffPower.h"

using namespace std;


PayoffPowerCall::PayoffPowerCall(double strike, int power):PayoffCall(strike),power_(power){}

double PayoffPowerCall::operator()(double spot){
	return max((pow(spot,power_)-strike_), 0.0);
}

PayoffPowerPut::PayoffPowerPut(double strike, int power):PayoffPut(strike),power_(power){}

double PayoffPowerPut::operator()(double spot){
	return max((strike_-pow(spot,power_)),0.0);
}