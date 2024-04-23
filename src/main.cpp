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

void help() {
    cout << "Usage: bin/crr [OPTION] [EX] [CALL] [PUT]" << endl;
    cout << "Mandatory arguments:" << endl;
    cout << "EX:     expiry, positive int for last time step (2 - 300)" << endl;
    cout << "CALL:   strike price of the call" << endl;
    cout << "PUT:    strike price of the put" << endl;
    cout << "Option:" << endl;
    cout << "-t      show price tree and stopping policy tree" << endl;
    cout << "        (has no effect when EX > 10)" << endl;
}

int main(int args, char **argv) {
    cout << "Hello Snell pricer!" << endl;
    
    int pos;
    bool display = false;
    if (args == 5 && string(argv[1]).compare("-t") == 0) {
        pos = 2;
        display = true;
    } else if (args == 4 && string(argv[1]).compare("-t") != 0) {
        pos = 1;
    } else {
        help();
        return 0;
    }

    // Fetch option data from the command line.
    int expiry = atoi(argv[pos++]);
    double call_strike = atof(argv[pos++]);
    double put_strike = atof(argv[pos]);
       
    // Set binomial market data. 
    double spot = 100.0;
    double utick = 0.01;
    double dtick = -0.01;
    double rate = 0.005;

    BinomialModel bm(spot, utick, dtick, rate);

    if (expiry > 10) {
        display = false;
    }

    CallOption call(expiry, call_strike);
    PutOption put(expiry, put_strike);
    DigitalCall dcall(expiry, call_strike);
    DigitalPut dput(expiry, put_strike);

    // Spread Options
    double lo = (call_strike < put_strike) ? call_strike : put_strike;
    double hi = (call_strike < put_strike) ? put_strike : call_strike;
    DoubleDigit doud(expiry, lo, hi);
    BullSpread bull(expiry, lo, hi);
    BearSpread bear(expiry, lo, hi);

    cout << "Forward price:   " << bm.forward_price(expiry) << endl;
    cout << "Call Option:     " << call.crr(bm) << endl;
    cout << "Put: Option:     " << put.crr(bm) << endl;
    cout << "Digital Call:    " << dcall.crr(bm) << endl;
    cout << "Digital Put:     " << dput.crr(bm) << endl;
    cout << "Double Digital:  " << doud.crr(bm) << endl;
    cout << "Bull Spread:     " << bull.crr(bm) << endl;
    cout << "Bear Spread:     " << bear.crr(bm) << endl;
    cout << "American Put:    " << put.snell(bm, display) << endl;

    return 0;
}