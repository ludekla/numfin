#include <iostream>

#include "nonlin.hpp"

using namespace std;

int main(int args, char * argv[]) {
    cout << "Hello Coupon Bond." << endl;

    // bond payments
    PayVec coupons {{1.0, 200.0}, {2.0, 200.0}, {3.0, 200.0}, {4.0, 200.0}};

    cout << "Payments: " << endl;
    for (int i = 0; i < coupons.size(); i++) {
        cout << coupons[i].time << ": " << coupons[i].amount << endl;
    }

    double principal = 10000.0;
    Bond bond(coupons, principal);

    cout << "Bond price: " << bond.evaluate(0.02) << endl;

    cout << "Yield (NR): " << bond.newtonraph_yield(9992.34, 1e-10) << endl;
    cout << "Yield (BS): " << bond.bisection_yield(9992.34, 1e-10) << endl;

    return 0;
}