//
// Created by Jakub Patoleta on 11.03.2017.
//

#pragma once


#include "Currency.h"
#include "Utility.h"

#define DEFAULT_DURATION 30
#define DEFAULT_CAPITALIZATION_TIME 30

class BankDeposit {

    float balance_;
    float rate_;
    unsigned duration_;
    const Currency *currency_;
    unsigned capitalizationTime_;


public:
    BankDeposit(Currency *initCurrency)
            : BankDeposit(0.0f, 0.0f, DEFAULT_DURATION, initCurrency, DEFAULT_CAPITALIZATION_TIME) {
    }
    BankDeposit(float initBalance, float initRate, unsigned const initDuration, Currency *initCurrency, unsigned const initCapitalizationTime)
            : rate_(initRate), duration_(initDuration), capitalizationTime_(initCapitalizationTime), currency_(initCurrency) {
            balance_ = Utility::roundTo2Places(initBalance);

    }
    virtual ~BankDeposit() {}

    inline float balance() {
        return balance_;
    }
    /*!
     * Calculating earnings, based on balance, rate and capitalizationTime
     * Kn = K0(1+r)^n
     * @return estimatedEarinings (added to base balance) in full time duration
     */
    float estimateEarnings();
    /*!
     * Calculating earnings, based on balance, rate and capitalizationTime
     * Kn = K0(1+r)^n
     * @param duration - time (days) of counting interest
     * @return estimatedEarinings (added to base balance) in typed time duration
     */
    float estimateEarnings(int duration);

    void changeCurrency(const Currency *currency);



    bool operator==(const BankDeposit &bankDeposit) {
        return (balance_ == bankDeposit.balance_ && rate_ == bankDeposit.rate_
           && bankDeposit.duration_ == duration_ && currency_ == bankDeposit.currency_);
    }

    friend std::ostream& operator<<(std::ostream& o, BankDeposit& b);



};
