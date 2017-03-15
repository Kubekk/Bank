//
// Created by Jakub Patoleta on 11.03.2017.
//

#include <math.h>
#include "BankDeposit.h"

float BankDeposit::estimateEarnings() {
    return estimateEarnings(duration_);
}

float BankDeposit::estimateEarnings(int duration) {
    float earnings = static_cast<float>(balance_*(pow((1 + interestRate_), (duration/capitalizationTime_))));
    return earnings;
}

void BankDeposit::changeCurrency(const Currency &currency) {
        balance_ = Utility::roundTo2Places(balance_ / (currency.rate() / currency_->rate()));
        currency_ = &currency;
}

std::ostream& operator<<(std::ostream &o, BankDeposit &b) {
    o << "Balance: " << b.balance_ << " " << b.currency_->shortcut() << std::endl;
    o << "Interest rate: " << b.interestRate_ * 100 << "%" << std::endl;
    return o;
}
