/**
 * @file binmarket.cpp
 * @brief Implementation code for the Binomial Market model.
 * 
 * @author Lutz
*/
#include <cmath>
#include <vector>

#include "binmarket.hpp"

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