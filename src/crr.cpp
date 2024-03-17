#include <cmath>
#include <vector>

#include "crr.hpp"

BinomialModel::BinomialModel(double s, double u, double d, double r):
    spot(s), uptick(u), downtick(d), rate(r) {}

double BinomialModel::martingal_prob() const {
    return (rate - downtick) / (uptick - downtick); 
}
        
double BinomialModel::price(int horizon, int n_upticks) const {
    double up = n_upticks * std::log(1 + uptick);
    double down = (horizon - n_upticks) * std::log(1 + downtick);
    return spot * std::exp(up + down);
}

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