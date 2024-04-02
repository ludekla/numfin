/**
 * @file option.hpp
 * @brief Header for option classes.
 * 
 * Option classes hold option parameters and have payoff methods. 
 * 
 * @author Lutz
 *
*/

#ifndef _OPTION_HPP_
#define _OPTION_HPP_

#include "binmarket.hpp"

/**
 * @class EuroOption
 * @brief Abstract European Option class.
 * 
 * European options have a fixed expiry step.
*/
class EuropeanOption {
private:
    int expiry;  /*!< Expiry step when option expires. */
public:
    /**
     * Setter for expiry member.
     * @param n value of expiry
    */
    void set_expiry(int n) { expiry = n; }
    /**
     * Member function to be implemented by all options.
    */
    virtual double payoff(double price) = 0;
    /**
     * Pricer member function. Implementation of CRR algorithm.
    */
    double crr(const BinomialModel& model);
};

/**
 * @class CallOption
 * @brief Holds additional option parameter and has payoff function. 
 * 
 * Class inherits the CRR pricing function and the expiry variable.
*/
class CallOption : public EuropeanOption {
    private:
        double strike; /*!< Strike price of the call option. */
    public:
        /**
         * Constructor.
         * 
         * @param n Expiry of the call option.
         * @param k Strike price of the call option.
        */
        CallOption(int n, double k): strike(k) { set_expiry(n); }
         /**
         * Setter for strike price of the option.
         * 
         * @param k Strike price of the underlying.
        */
        void set_strike(double k) { strike = k; }
        /**
         * Member function implementing the call's payoff function.
         * 
         * @param price Price of the underlying.
        */
        double payoff(double price);
};

/**
 * @class PutOption
 * @brief Holds additional option parameter and has payoff function. 
 * 
 * Class inherits the CRR pricing function and the expiry variable.
*/
class PutOption : public EuropeanOption {
    private:
        double strike; /*!< Strike price of the put option. */
    public:
        /**
         * Constructor.
         * 
         * @param n Expiry of the put option.
         * @param k Strike price of the put option.
        */
        PutOption(int n, double k): strike(k) { set_expiry(n); }
        /**
         * Setter for strike price of the option.
         * 
         * @param k Strike price of the underlying.
        */
        void set_strike(double k) { strike = k; }
        /**
         * Member function implementing the put's payoff function.
         * 
         * @param price Price of the underlying.
        */
        double payoff(double price);
};

#endif /* _OPTION_HPP_ */