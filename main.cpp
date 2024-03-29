//#define NDEBUG

#include <assert.h>
#include <vector>
#include "Currency.h"
#include "BankDeposit.h"
#include "UserInput.h"


/*
 * Jakub Patoleta
 * Project 01
 * Bank deposit project
 */

int main() {

    Currency dollar = Currency("Dollar", "$", 1.1f);
    Currency euro = Currency("Euro", "€", 1.4f);
    Currency zloty = Currency("Zloty", "zl", 0.35f);
    Currency currencies[] = {dollar, euro, zloty};

    BankDeposit depositGreater =  BankDeposit(1000, 0.05f, 90, dollar, 30);


    UserInput userInput = UserInput::getInstance();
   // userInput.startInteraction(currencies, 3);




    assert(dollar < euro);
    assert(dollar > zloty);
    assert(dollar == dollar);



    BankDeposit bankDeposit(1000, 0.05f, 90, dollar, 30);
    std::cout << bankDeposit;


    std::cout << bankDeposit.estimateEarnings() << std::endl;

    bankDeposit.changeCurrency(euro);
    std::cout << bankDeposit;

    bankDeposit.changeCurrency(dollar);
    std::cout << bankDeposit;

    bankDeposit.changeCurrency(zloty);
    std::cout << bankDeposit;



    return 0;


}