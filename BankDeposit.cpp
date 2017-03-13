//
// Created by Jakub Patoleta on 11.03.2017.
//

#include <math.h>
#include "BankDeposit.h"

float BankDeposit::estimateEarnings() {
    return estimateEarnings(duration_);
}

float BankDeposit::estimateEarnings(int duration) {
    float earnings;
    earnings = static_cast<float>(balance_*(pow((1 + rate_), (duration/capitalizationTime_))));
    return earnings;
}

void BankDeposit::changeCurrency(const Currency *currency) {
        balance_ = Utility::roundTo2Places(balance_ / (currency->rate() / currency_->rate()));
        currency_ = currency;
        std::cout << *currency_;
        std::cout << currency->shortcut() << std::endl;

}

/*!
 * Function which write bankDeposit balance and interest rate through the stream
 * @param o - choosen stream
 * @param b - instance of bankDeposit
 * @return stream
 */
std::ostream& operator<<(std::ostream& o, BankDeposit& b) {
    o << "Balance: " << b.balance_ << " " << b.currency_->shortcut() << std::endl;
    o << "Interest rate: " << b.rate_ * 100 << "%" << std::endl;
    return o;
}

// 2 miejsca po przecinku +
// jesli przewalutowanie = 0 -> 0.01
// dodac konto -> kilka lokat
// stan konta +
// waluta +
// dodawanie pieniedzy
// wydawanie pieniedzy
// wplaty na lokate
// sprawdzanie stanu konta +
// zakldanie nowej lokaty
// inicjalizowanie walut na poczatku uruchomiania programu +
// lokata wieksza/mniejsza (zyskiem)
// lokaty rozne -> nie takie same
// ostream overload +
// testowanie reczne
// asserts()
// dodanie dokumentacji w potrzebnych miejscach
