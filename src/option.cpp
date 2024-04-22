/**
 * @file option.cpp
 * @brief Implementation of option methods.
 * 
 * @author Lutz
*/

#include <vector>
#include "option.hpp"
#include "lattice.hpp"

double CallOption::payoff(double price) {
    return (price > strike) ? price - strike : 0.0;
}

double PutOption::payoff(double price) {
    return (price < strike) ? strike - price : 0.0;
}

double DigitalCall::payoff(double price) {
    return (price > strike) ? 1.0 : 0.0;
}

double DigitalPut::payoff(double price) {
    return (price < strike) ? 1.0 : 0.0;
}

double DoubleDigit::payoff(double price) {
    if (price < lo) return 0.0;
    else if (price > hi) return 0.0;
    return 1.0;
}

double BullSpread::payoff(double price) {
    if (price < lo) return 0.0;
    else if (price > hi) return hi - lo;
    return price - lo;
}

double BearSpread::payoff(double price) {
    if (price < lo) return hi - lo;
    else if (price > hi) return 0.0;
    return hi - price;
}

double Option::crr(const BinomialModel& model) {
    double q = model.martingal_prob();
    double dc = 1.0/(1.0 + model.get_rate()); // discount
    std::vector<double> prices(expiry + 1);
    for (int i = 0; i <= expiry; i++)
        prices[i] = payoff(model.price(expiry, i));
    int n_steps = expiry - 1;
    for (int j = n_steps; j >= 0; j--) {
        for (int i = 0; i <= n_steps; i++)
            prices[i] = dc * (q*prices[i+1] + (1.0 - q)*prices[i]);
    }
    return prices[0];
}

double Option::snell(const BinomialModel& model, bool display) {
    double q = model.martingal_prob();
    double dc = 1.0 / (1.0 + model.get_rate()); // discount
    Lattice<double> lat(expiry);   // price values
    Lattice<bool> policy(expiry);  // stopping policy tree
    for (int i = 0; i <= expiry; i++) {
        lat.set(expiry, i, payoff(model.price(expiry, i)));
        policy.set(expiry, i, true);
    }
    double val;
    for (int j = expiry - 1; j >= 0; j--) {
        for (int i = 0; i <= j; i++) {
            lat.set(j, i, payoff(model.price(j, i)));
            val = dc * (q * lat.get(j+1, i+1) + (1.0 - q)*lat.get(j+1, i));
            if (val > lat.get(j, i)) {
                lat.set(j, i, val);
                policy.set(j, i, false);
            } else if (lat.get(j, i) == 0.0) {
                policy.set(j, i, false);
            }
        }
    }
    if (display) {
        lat.display("Price Tree:");
        policy.display("Stopping Policy Tree:");
    }
    return lat.get(0, 0);
}