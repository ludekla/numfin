/**
 * @file eurocall.hpp
 * @brief European Call and a Pricer for implied-volatility calculation. 
 * 
 * @author Lutz
*/

#ifndef __EUROCALL_HPP__
#define __EUROCALL_HPP__

/**
 * @class EuroCall
 * @brief Holds maturity and strike price of a European call option.
 * 
 * Includes pricing functionality based on the Black-Scholes solution.
*/
class EuroCall {
private:
    double T;  /*!< Maturity, Expiry */
    double K;  /*!< Strike price */
public:
    /**
     * Constructor
     * @param t Maturity
     * @param k Strike price
    */
    EuroCall(double t, double k): K(k), T(t) {}
    /**
     * @fn d_plus
     * @brief Helper method for computing an intermediate result.  
     * 
     * Computes an intermediate result for the BS formula known as
     * d+ or d1.
     * 
     * @param spot Spot price.
     * @param sig Volatility (sigma) of the model.
     * @param rate Interest rate of the model.
     * 
     * @return Intermediate result as double.
    */
    double d_plus(double spot, double sig, double rate);
    /**
     * @fn d_minus
     * @brief Helper method for computing an intermediate result.  
     * 
     * Computes an intermediate result for the BS formula known as
     * d- or d2.
     * 
     * @param spot Spot price.
     * @param sig Volatility (sigma) of the model.
     * @param rate Interest rate of the model.
     * 
     * @return Intermediate result as double.
    */
    double d_minus(double spot, double sig, double rate);
    /**
     * @fn price_by_BS
     * @brief Method for computing the call price.  
     * 
     * Computes the price of the European call option based on the
     * Black-Scholes formula.
     * 
     * @param spot Spot price.
     * @param sig Volatility (sigma) of the model.
     * @param rate Interest rate of the model.
     * 
     * @return Price as double.
    */
    double price_by_BS(double spot, double sig, double rate);
    /**
     * @fn vega_by_BS
     * @brief Method for computing the vega of the call price.  
     * 
     * Computes the vega of the European call option based on the
     * Black-Scholes formula. The vega is the first derivative of
     * the call price with respect to the price and indicates how
     * sensitive the option price is to changes of the spot price.
     * 
     * @param spot Spot price.
     * @param sig Volatility (sigma) of the model.
     * @param rate Interest rate of the model.
     * 
     * @return Vega value as double.
    */
    double vega_by_BS(double spot, double sig, double rate);
};

/**
 * @class EuroCallPricer
 * @brief Pricer for European call options and implied volatility.
 * 
 * Pricer allows the computation of the implied volatility.
 * 
*/
class EuroCallPricer {
private:
    EuroCall ecall;  /*!< EuroCall object. */
    double mvalue;   /*!< Value of the European call option. */
    double spot;     /*!< Spot price. */
    double rate;     /*!< Iterest rate. */
public:
    /**
     * Constructor
     * @param call Reference to EuroCall object.
     * @param s Spot price.
     * @param r Interest rate.
    */
    EuroCallPricer(EuroCall& call, double s, double r): 
        ecall(call), spot(s), rate(r), mvalue(0.0) {}
    /**
     * @fn value
     * @brief Computes the price of the European call.
     *
     * Computes the price of the European call based on the pricer's
     * given data and the passed volatility.
     *  
     * @param sigma Volatility.
     * 
     * @return Value of the call option (price) as double.
    */
    double value(double sigma);
    /**
     * @fn deriv
     * @brief Derivative of the call price with respect to the volatility.
     *
     * Computes the derivative of the call price by the volatility for a
     * given volatility.
     * 
     * @param sigma Volatility.
     *  
     * @return Value of the derivative as double
    */
    double deriv(double sigma);
    /**
     * @fn newtonraph_sigma
     * @brief Computes the implied volatility by Newton-Raphson.
     *
     * Computes the implied volatility for a given value and precision
     * by the Newton-Raphson method.
     * 
     * @param sigma Volatility.
     *  
     * @return Implied volatility as double.
    */
    double newtonraph_sigma(double value, double eps);
    /**
     * @fn 
     * @brief Computes the implied volatility by the bisection method.
     *
     * Computes the implied volatility for a given value and precision
     * by the bisection method where intervals are halved over and over
     * again.
     *  
     * @return Implied volatility as double.
    */
    double bisection_sigma(double value, double eps);
};


#endif /* __EUROCALL_HPP__ */