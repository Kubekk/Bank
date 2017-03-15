//
// Created by Jakub Patoleta on 12.03.2017.
//

#include "Currency.h"

bool Currency::operator<(const Currency &currency) {
    return (*this).rate_ < currency.rate_;
}

bool Currency::operator>(const Currency &currency) {
    return (*this).rate_ > currency.rate_;
}

Currency& Currency::operator=(Currency &currency) {
    return currency;
}


std::ostream& operator<<(std::ostream &o, Currency &c) {
    o << "Name of currency: " << c.name_ << std::endl;
    return o;
}

std::ostream& operator<<(std::ostream &o, const Currency &c) {
    o << "Name of currency: " << c.name_ << std::endl;
    return o;
}