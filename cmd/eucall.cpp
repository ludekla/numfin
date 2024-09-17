#include <iostream>

#include "eurocall.hpp"
#include "nonlin.hpp"

using namespace std;

int main(int args, char * argv[]) {
    cout << "Hello European Call Option." << endl;

    double expiry = 1.0;
    double strike = 100.0;
    EuroCall call(expiry, strike);

    double spot = 100.0;
    double rate = 0.1;
    EuroCallPricer pricer(call, spot, rate);

    double sig = 0.1;
    double price = call.price_by_BS(spot, sig, rate);

    cout << "volatility: " << sig << " --> call price: " << price << endl;

    double ivol_nr = pricer.newtonraph_sigma(price, 1e-6);
    double ivol_bs = pricer.bisection_sigma(price, 1e-6);

 
    cout << "Newton-Raphson implied volatility: " << ivol_nr << endl;
    cout << "Bisection implied volatility: " << ivol_bs << endl;

    return 0;
}