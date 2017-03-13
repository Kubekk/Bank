//
// Created by Jakub Patoleta on 11.03.2017.
//

#include <cmath>
#include "BankDeposit.h"

float BankDeposit::estimateEarnings() {
    return estimateEarnings(duration_);
}

float BankDeposit::estimateEarnings(int duration) {
    float earnings;
    earnings = static_cast<float>(balance_*(pow((1 + rate_), (capitalizationTime_/duration))));
    return earnings;
}

void BankDeposit::changeCurrency(const Currency &currency) {
    if(balance_ == 0.0f)
}
// 2 miejsca po przecinku
// jesli przewalutowanie = 0 -> 0.01
// dodac konto -> kilka lokat
// stan konta
// waluta
// dodawanie pieniedzy
// wydawanie pieniedzy
// wplaty na lokate
// sprawdzanie stanu konta
// zakldanie nowej lokaty
// inicjalizowanie walut na poczatku uruchomiania programu
// lokata wieksza/mniejsza (zyskiem)
// lokaty rozne -> nie takie same
// ostream overload
// testowanie reczne
// asserts()
// dodanie dokumentacji w potrzebnych miejscach
