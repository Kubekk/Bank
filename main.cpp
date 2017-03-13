#include <assert.h>
#include "Currency.h"
#include "BankDeposit.h"

/*
 * Jakub Patoleta
 * Project 01
 * Bank deposit project
 */

int main() {

    Currency dollar = Currency("Dollar", "$", 1.1f);
    Currency euro = Currency("Euro", "€", 1.4f);
    Currency zloty = Currency("Zloty", "zl", 0.35f);


    BankDeposit bankDeposit(1000, 0.05f, 90, &dollar, 30);
    std::cout << bankDeposit;
    assert(dollar < euro);
    assert(dollar > zloty);

    std::cout << bankDeposit.estimateEarnings() << std::endl;

    bankDeposit.changeCurrency(&euro);
    std::cout << bankDeposit;

    bankDeposit.changeCurrency(&dollar);
    std::cout << bankDeposit;

    bankDeposit.changeCurrency(&zloty);
    std::cout << bankDeposit;




}