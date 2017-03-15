//
// Created by Jakub Patoleta on 15.03.2017.
//

#include <iostream>
#include "UserInput.h"

using std::cout;
using std::endl;

void UserInput::showMainMenu() {
    cout << "    MENU    " << endl << endl;
    cout << "1. Create new deposit." << endl;
    cout << "2. Check account's balance." << endl;
    cout << "3. Change the interest rate." << endl;
    cout << "4. Estimate the earnings of the deposit." << endl;
    cout << "5. Change the currency of the deposit." << endl;
    cout << "0. Exit." << endl;
}