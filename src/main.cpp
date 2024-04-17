/** 
 * @file main.cpp
 * @brief Binary application file.
 * @author Lutz
*/
#include <iostream>

#include "option.hpp"
#include "binmarket.hpp"
#include "lattice.hpp"

using namespace std;

int main(int args, char **argv) {
    cout << "Hello Snell pricer!" << endl;

    if (args != 5) {
        cout << "usage: bin/crr [EXPIRY] [CALL STRIKE] [PUT STRIKE] [0|1]" << endl;
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
    int display = atoi(argv[4]);

    if (expiry > 10) {
        display = 0;
    }

    CallOption call(expiry, call_strike);
    PutOption put(expiry, put_strike);

    cout << "European Call: " << call.crr(bm) << endl;
    cout << "European Put:  " << put.crr(bm) << endl;

    cout << "American Call: " << call.snell(bm, display) << endl;
    cout << "American Put:  " << put.snell(bm, display) << endl;

    return 0;
}