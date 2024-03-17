// Cox-Ross-Rubinstein Pricer
#include <iostream>

#include "crr.hpp"

using namespace std;

int main(int args, char **argv) {
    cout << "Hello World!" << endl;

    if (args != 4) {
        cout << "usage: bin/crr [expiry] [call strike] [put strike]" << endl;
        exit(0);
    }
    int expiry = atoi(argv[1]);
    double call_strike = atof(argv[2]);
    double put_strike = atof(argv[3]);

    // market model
    BinomialModel model(100, 0.01, -0.01, 0.005);
    
    // claim
    CallOption call(expiry, call_strike);
    PutOption put(expiry, put_strike);

    cout << "Call: " << call.crr(model) << endl;
    cout << "Put:  " << put.crr(model) << endl;

    return 0;
}