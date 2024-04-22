/**
 * @file option.hpp
 * @brief Header for option classes.
 * 
 * Option classes hold option parameters and have payoff methods. 
 * 
 * @author Lutz
*/

#ifndef _OPTION_HPP_
#define _OPTION_HPP_

#include "binmarket.hpp"

/**
 * @class Option
 * @brief Abstract Option class.
 * 
 * Options have a fixed expiry step.
*/
class Option {
private:
    int expiry;  /*!< Expiry step when option expires. */
public:
    /**
     * @fn set_expiry
     * @brief Setter for expiry member.
     * @param n value of expiry
    */
    void set_expiry(int n) { expiry = n; }
    /**
     * @fn payoff
     * @brief Method to be implemented by all options.
     * @param price Current price at which to evaluate the option.
    */
    virtual double payoff(double price) = 0;
    /**
     * @fn crr
     * @brief Pricer function. 
     * 
     * Implementation of CRR algorithm.Vector
     * 
     * @param model BinomialModel object with market data.
    */
    double crr(const BinomialModel& model);
    /**
     * @fn snell
     * @brief Pricer function. 
     * 
     * Implementation of Snell algorithm.
     * 
     * @param model BinomialModel object with market data.
    */
    double snell(const BinomialModel& model, bool display);
};

/**
 * @class CallOption
 * @brief Holds additional option parameter and has payoff function. 
 * 
 * Class inherits the CRR pricing function and the expiry variable.
*/
class CallOption : public Option {
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
class PutOption : public Option {
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
     * Member function implementing the put's payoff function.
     * 
     * @param price Price of the underlying.
    */
    double payoff(double price);
};

/**
 * @class DigitalCall
 * @brief Holds additional option parameter and has payoff function. 
 * 
 * Class inherits the CRR pricing function and the expiry variable.
*/
class DigitalCall : public Option {
private:
    double strike; /*!< Strike price of the digital call option. */
public:
    /**
     * Constructor.
     * 
     * @param n Expiry of the digital call option.
     * @param k Strike price of the digital call option.
    */
    DigitalCall(int n, double k): strike(k) { set_expiry(n); }
    /**
     * Member function implementing the digital call's payoff function.
     * 
     * @param price Price of the underlying.
    */
    double payoff(double price);
};

/**
 * @class DigitalPut
 * @brief Holds additional option parameter and has payoff function. 
 * 
 * Class inherits the CRR pricing function and the expiry variable.
*/
class DigitalPut : public Option {
private:
    double strike; /*!< Strike price of the digital put option. */
public:
    /**
     * Constructor.
     * 
     * @param n Expiry of the put option.
     * @param k Strike price of the digital put option.
    */
    DigitalPut(int n, double k): strike(k) { set_expiry(n); }
    /**
     * Member function implementing the digital put's payoff function.
     * 
     * @param price Price of the underlying.
    */
    double payoff(double price);
};

/**
 * @class SpreadOption
 * @brief Abstract Spread Option class.
 * 
 * Spread Options have a fixed expiry step.
*/
class SpreadOption : public Option {
protected:
    double lo; /*!< Lower strike price. */
    double hi; /*!< Upper strike price. */
public:
    /**
     * Constructor.
     * 
     * @param n Expiry of the put option.
     * @param low Lower strike price of the spread option.
     * @param high Upper strike price of the spread option.
    */
    SpreadOption(int n, double low, double high): lo(low), hi(high) { set_expiry(n); }
};

/**
 * @class DoubleDigit
 * @brief Double-Digit Option class.
*/
class DoubleDigit : public SpreadOption {
public:
    /**
     * Constructor.
     * 
     * @param n Expiry of the put option.
     * @param low Lower strike price of the spread option.
     * @param high Upper strike price of the spread option.
    */
    DoubleDigit(int n, double low, double high): SpreadOption(n, low, high) {}
    /**
     * @fn payoff
     * @brief Method to be implemented by all options.
     * @param price Current price at which to evaluate the option.
    */
    virtual double payoff(double price);
};

/**
 * @class BullSpread
 * @brief Bull Spread Option class.
*/
class BullSpread : public SpreadOption {
public:
    /**
     * Constructor.
     * 
     * @param n Expiry of the put option.
     * @param low Lower strike price of the spread option.
     * @param high Upper strike price of the spread option.
    */
    BullSpread(int n, double low, double high): SpreadOption(n, low, high) {}
    /**
     * @fn payoff
     * @brief Method to be implemented by all options.
     * @param price Current price at which to evaluate the option.
    */
    virtual double payoff(double price);
};

/**
 * @class BearSpread
 * @brief Bear Spread Option class.
*/
class BearSpread : public SpreadOption {
public:
    /**
     * Constructor.
     * 
     * @param n Expiry of the put option.
     * @param low Lower strike price of the spread option.
     * @param high Upper strike price of the spread option.
    */
    BearSpread(int n, double low, double high): SpreadOption(n, low, high) {}
    /**
     * @fn payoff
     * @brief Method to be implemented by all options.
     * @param price Current price at which to evaluate the option.
    */
    virtual double payoff(double price);
};



#endif /* _OPTION_HPP_ */