#ifndef __EUROCALL_HPP__
#define __EUROCALL_HPP__

class EuroCall {
private:
    double T;
    double K;
public:
    EuroCall(double t, double k): K(k), T(t) {}
    double d_plus(double spot, double sig, double rate);
    double d_minus(double spot, double sig, double rate);
    double price_by_BS(double spot, double sig, double rate);
    double vega_by_BS(double spot, double sig, double rate);
};

class EuroCallPricer {
private:
    EuroCall ecall;
    double mvalue;
    double spot;
    double rate;
public:
    EuroCallPricer(EuroCall& call, double s, double r): 
        ecall(call), spot(s), rate(r), mvalue(0.0) {}
    double value(double sigma);
    double deriv(double sigma);
    double newtonraph_sigma(double value, double eps);
    double bisection_sigma(double value, double eps);
};


#endif /* __EUROCALL_HPP__ */