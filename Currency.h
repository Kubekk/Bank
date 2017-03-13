//
// Created by Jakub Patoleta on 12.03.2017.
//

#pragma once

#include <iostream>
#include <string>

class Currency {
    const std::string name_;
    const std::string shortcut_;
    float rate_;

public:
    Currency(std::string name, std::string shortcut, float rate): rate_(rate), shortcut_(shortcut), name_(name) {};

    /*!
     *
     * setting rate of the currency
     * @param rate
     */
    inline void rate(float rate) {
        rate_ = rate;
    }

    inline float rate() const {
        return rate_;
    }

    inline std::string shortcut() const {
        return shortcut_;
    }

    bool operator==(const Currency &currency) {
        return (currency.rate_ == rate_ && name_ == currency.name_ && shortcut_ == currency.shortcut_);
    }

    bool operator<(const Currency &currency);
    bool operator>(const Currency &currency);
    const Currency& operator=(const Currency &currency);
    friend std::ostream& operator<<(std::ostream &o, Currency &c);
    friend std::ostream& operator<<(std::ostream &o, const Currency &c);

};
