/** 
 * @file main.cpp
 * @brief Binary application file.
 * @author Lutz
*/
#include <iostream>

#include "option.hpp"

using namespace std;

int main(int args, char **argv) {
    cout << "Hello CRR pricer!" << endl;

    if (args != 4) {
        cout << "usage: bin/crr [EXPIRY] [CALL STRIKE] [PUT STRIKE]" << endl;
        return 0;
    }

    // Set binomial market data. 
    double spot = 100.0;
    double utick = 0.01;
    double dtick = -0.01;
    double rate = 0.005;

    BinomialModel bm(spot, utick, dtick, rate);

    // Fetch option data from the command line.
    int expiry = atoi(argv[1]);
    double call_strike = atof(argv[2]);
    double put_strike = atof(argv[3]);

    CallOption call(expiry, call_strike);
    PutOption put(expiry, put_strike);

    cout << "Call: " << call.crr(bm) << endl;
    cout << "Put:  " << put.crr(bm) << endl;

    return 0;
}