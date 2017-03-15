//
// Created by Jakub Patoleta on 15.03.2017.
//

#include "Menu.h"

void Menu::showMainMenu() {
    cout << "    MENU    " << endl << endl;
    cout << "1. Create new deposit." << endl;
    cout << "2. Check account's balance." << endl;
    cout << "3. Change the interest rate." << endl;
    cout << "4. Estimate the earnings of the deposit." << endl;
    cout << "5. Change the currency of the deposit." << endl;
    cout << "6. Exit." << endl;
}

void Menu::showAlertNoSuchOption() {
    cout << "There is no such option" << endl;
    cout << "Please type one of the numbers from menu" << endl;
}


void Menu::showAvaiableCurrencies(Currency *pCurrency, int n) {
    cout << "Currencies to choose from: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << i << ". " << pCurrency[i-1]  << endl;
    }
}
