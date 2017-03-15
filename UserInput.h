//
// Created by Jakub Patoleta on 15.03.2017.
//

#pragma once

#include <vector>
#include "BankDeposit.h"
#include "Menu.h"

class UserInput {

    Menu menu;
    bool end;
    std::vector<BankDeposit*> deposits;
    Currency *currencies;
    int currenciesNumber;

    UserInput() {end = false;}

    /*!
     * Checking if last cin was a failure
     * @return true - if there was a failure false - if cin operation has succeed
     */
    bool checkCinIfFailAndClear();
    void controlMenuOptions();




public:
    ~UserInput() {
        for(auto deposit : deposits)
            delete deposit;
    }
    static UserInput& getInstance() {
        static UserInput instance;
        return instance;
    }


    int readIntegerNumber();
    float readFloatNumber();
    void startInteraction(Currency currencies[], int n);

    void manageCreateDepositData();

    void manageChangeCurrencyData();

    void manageChangeInterestRate();

    void manageCheckBalance();

    void manageEstimateEarnings();

    float readBalance();

    float readInterestRate();

    const unsigned int readDuration();

    const Currency &readCurrency();

    const unsigned int readCapitalizationTime();
};
