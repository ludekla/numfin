// Cox-Ross-Rubinstein pricer
#ifndef CRR_HPP
#define CRR_HPP

// Binomial Model
class BinomialModel {
private:
    double spot;
    double uptick; 
    double downtick;
    double rate;
public:
    BinomialModel(double s, double u, double d, double r);
    double martingal_prob() const;
    double price(int horizon, int step) const;
    double get_rate() const { return rate; }
};

// abstract class
class EuropeanOption {
private:
    int expiry;
public:
    void set_expiry(int n) { expiry = n; }
    virtual double payoff(double price) = 0;
    double crr(const BinomialModel& model);
};

class CallOption : public EuropeanOption {
    private:
        double strike;
    public:
        CallOption(int n, double k): strike(k) { set_expiry(n); }
        void set_strike(double k) { strike = k; }
        double payoff(double price);
};

class PutOption : public EuropeanOption {
    private:
        double strike;
    public:
        PutOption(int n, double k): strike(k) { set_expiry(n); }
        void set_strike(double k) { strike = k; }
        double payoff(double price);
};

#endif 