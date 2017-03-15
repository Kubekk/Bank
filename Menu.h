//
// Created by Jakub Patoleta on 15.03.2017.
//

#pragma once

#include <iostream>
#include "Currency.h"

using std::cout;
using std::endl;

class Menu {

public:
    enum States {
        CREATE_DEPOSIT = 1,
        CHECK_BALANCE,
        CHANGE_INTEREST_RATE,
        ESTIMATE_EARNINGS,
        CHANGE_CURRENCY,
        EXIT
    };

    void showMainMenu();

    void showAlertNoSuchOption();

    void showAvaiableCurrencies(Currency *pCurrency, int n);
};