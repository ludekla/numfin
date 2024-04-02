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


#endif 