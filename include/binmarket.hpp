/**
 * @file binmarket.hpp
 * @brief Binomial market of one underlying.
 * 
 * @author Lutz
*/
#ifndef CRR_HPP
#define CRR_HPP

/**
 * @class BinomialModel
 * @brief Holds market data for the binomial model.
 * 
 * Describes the behaviour of one underlying. 
 */  
class BinomialModel {
private:
    double spot;      /*!< Spot price */
    double uptick;    /*!< Relative uptick. */
    double downtick;  /*!< Relative downtick. */
    double rate;      /*!< Risk-neutral rate. */
public:
    /**
     * Constructor.
     * @param s Spot price.
     * @param u Uptick.
     * @param d Downtick.
     * @param r Risk-neutral rate.
    */
    BinomialModel(double s, double u, double d, double r);
    /**
     * @fn martingal_prob
     * @brief Method that returns the martingale probabilty.
     *  
     * Computes the martingale probabilty for upticks
     * based on the market data, ie the objects parameter values.
     * 
     * @return Martingale probability in interval [0, 1].
    */
    double martingal_prob() const;
    /**
     * @fn price
     * @brief Computes the price of the underlying.
     * 
     * The price is determined by the number of upticks and 
     * the maximum number of upticks for the underlying.
     * 
     * @param horizon Time horizon of the underlying.
     * @param step number of upticks the underlying undergoes.
    */
    double price(int horizon, int step) const;
    /**
     * @fn get_rate
     * @brief Getter function for risk-neutral rate.
     * @return Risk-neutral rate.
    */
    double get_rate() const { return rate; }
};

#endif 