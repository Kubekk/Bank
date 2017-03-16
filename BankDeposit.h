//
// Created by Jakub Patoleta on 11.03.2017.
//

#pragma once


#include "Currency.h"
#include "Utility.h"
#include <assert.h>

class BankDeposit {

    float balance_;
    float interestRate_;
    const unsigned duration_;
    const Currency *currency_;
    unsigned capitalizationTime_;

    unsigned getDefaultDuration() const { return 90; }
    unsigned getDefaultCapitalizationTime() const { return 30; }


public:
    BankDeposit(Currency &initCurrency)
            : BankDeposit(0.0f, 0.0f, getDefaultDuration(), initCurrency, getDefaultCapitalizationTime()) {
    }

    BankDeposit(float initBalance, float initInterestRate, unsigned const initDuration,const Currency &initCurrency, unsigned const initCapitalizationTime)
            : interestRate_(initInterestRate), duration_(initDuration), capitalizationTime_(initCapitalizationTime), currency_(&initCurrency) {
            balance_ = Utility::roundTo2Places(initBalance);
    }

    BankDeposit(const BankDeposit &b) : BankDeposit(b.balance_, b.interestRate_, b.duration_, *(b.currency_), b.capitalizationTime_) {}

    ~BankDeposit() {}

    inline float balance() { return balance_; }

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

    /*!
     * Change currency of the bank deposit (change the balance)
     * @param currency - currency to which account has to be changed
     */
    void changeCurrency(const Currency &currency);


    /*!
     * Setting new interest rate
     * @param rate
     * @return true - rate has been changed, false - rate in paramter was negative
     */
    bool changeInterestRate(float interestRate) {
        if(interestRate < 0)
            return false;
        interestRate_ = interestRate;
        return true;
    }

    /*!
     * Checking if both BankDeposit objects are equals
     * same balance, interest rate, duration and currency
     * @param bankDeposit
     * @return - true if equals, false otherwise
     */
    bool operator==(const BankDeposit &bankDeposit) {
        return (balance_ == bankDeposit.balance_ && interestRate_ == bankDeposit.interestRate_
           && bankDeposit.duration_ == duration_ && currency_ == bankDeposit.currency_);
    }

    /*!
    * Function which write bankDeposit balance and interest rate through the stream
    * @param o - choosen stream
    * @param b - instance of bankDeposit
    * @return stream
    */
    friend std::ostream& operator<<(std::ostream& o, BankDeposit& b);


    bool operator<(BankDeposit &b);

};
