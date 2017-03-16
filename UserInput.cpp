//
// Created by Jakub Patoleta on 15.03.2017.
//

#include <iostream>
#include "UserInput.h"

using std::cin;

int UserInput::readIntegerNumber() {
    int number;
    cin >> number;
    if(checkCinIfFailAndClear())
        number = 0;
    return number;
}

float UserInput::readFloatNumber() {
    float number;
    cin >> number;
    if(checkCinIfFailAndClear())
        number = 0;
    return number;
}

bool UserInput::checkCinIfFailAndClear() {
    if(cin.fail()) {
        cin.clear();
        cin.ignore();
        return true;
    }
    //cin.clear();
    return false;
}

void UserInput::startInteraction(Currency *currencies, int n) {
    this->currencies = currencies;
    currenciesNumber = n;
    do {
        menu.showMainMenu();
        controlMenuOptions();

    }while(end);
}

void UserInput::controlMenuOptions() {
    switch (readIntegerNumber()) {
        case Menu::CREATE_DEPOSIT:
            manageCreateDepositData();
            break;
        case Menu::CHANGE_CURRENCY:
            manageChangeCurrencyData();
            break;
        case Menu::CHANGE_INTEREST_RATE:
            manageChangeInterestRate();
            break;
        case Menu::CHECK_BALANCE:
            manageCheckBalance();
            break;
        case Menu::ESTIMATE_EARNINGS:
            manageEstimateEarnings();
            break;
        case Menu::EXIT:
            end = true;
            break;
        default:
            menu.showAlertNoSuchOption();
    }
}

void UserInput::manageCreateDepositData() {
    std::cout << "Creating new deposit" << std::endl << std::endl;

    deposits.push_back(new BankDeposit(readBalance(), readInterestRate(), readDuration(), readCurrency(), readCapitalizationTime()));
    std::cout << (*deposits[deposits.size() - 1]);

}

void UserInput::manageChangeCurrencyData() {

}

void UserInput::manageChangeInterestRate() {

}

void UserInput::manageCheckBalance() {

}

void UserInput::manageEstimateEarnings() {

}

float UserInput::readBalance() {
    std::cout << "Please type balance which has to be set" << std::endl;
    float number;
    while((number = readFloatNumber()) == 0);
    return number;
}

float UserInput::readInterestRate() {
    std::cout << "Please type interest rate which has to be set" << std::endl;
    float number;
    while((number = readFloatNumber()) == 0);
    return number;
}

const unsigned int UserInput::readDuration() {
    std::cout << "Please type duration of deposit which has to be set" << std::endl;
    int dur;
    while ((dur = readIntegerNumber()) <= 0)
        std::cout << "Duration have to be greater than 0!" << std::endl;
    return static_cast<unsigned> (dur);
}

const Currency& UserInput::readCurrency() {
    menu.showAvaiableCurrencies(currencies, currenciesNumber);
    int currencyId = readIntegerNumber();
    while(currencyId < 0 || currencyId >= currenciesNumber)
        currencyId = readIntegerNumber();
    return currencies[currencyId];
}

const unsigned int UserInput::readCapitalizationTime() {
    std::cout << "Please type capitalization time which has to be set" << std::endl;
    int capTime;
    while ((capTime = readIntegerNumber()) <= 0)
        std::cout << "Capitalization time have to be greater than 0!" << std::endl;
    return static_cast<unsigned>(capTime);
}
