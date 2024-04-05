/**
 * @file option.cpp
 * @brief Implementation of option methods.
 * 
 * @author Lutz
*/

#include <vector>
#include "option.hpp"

double EuropeanOption::crr(const BinomialModel& model) {
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

double CallOption::payoff(double price) {
    return (price > strike) ? price - strike : 0.0;
}

double PutOption::payoff(double price) {
    return (price < strike) ? strike - price : 0.0;
}