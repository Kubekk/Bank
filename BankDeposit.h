//
// Created by Jakub Patoleta on 11.03.2017.
//

#pragma once


#include "Currency.h"
#define DEFAULT_DURATION 30
#define DEFAULT_CAPITALIZATION_TIME 30

class BankDeposit {

    float balance_;
    float rate_;
    unsigned duration_;
    Currency *currency_;
    unsigned capitalizationTime_;


public:
    BankDeposit(const Currency &initCurrency)
            : BankDeposit(0.0f, 0.0f, DEFAULT_DURATION, initCurrency, DEFAULT_CAPITALIZATION_TIME) {
    }
    BankDeposit(float initBalance, float initRate, unsigned const initDuration, const Currency &initCurrency, unsigned const initCapitalizationTime)
            : balance_(initBalance), rate_(initRate), duration_(initDuration), capitalizationTime_(initCapitalizationTime) {
        currency_ = new Currency(initCurrency);
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

    void changeCurrency(const Currency &currency);



    bool operator==(const BankDeposit &bankDeposit) {
        return (balance_ == bankDeposit.balance_ && rate_ == bankDeposit.rate_
           && bankDeposit.duration_ == duration_ && currency_ == bankDeposit.currency_);
    }


};
