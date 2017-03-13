//
// Created by Jakub Patoleta on 12.03.2017.
//

#pragma once

#include <iostream>
#include <string>

class Currency {
    const std::string name;
    const std::string shortcut;
    float rate_;

public:
    Currency(std::string name, std::string shortcut, float rate): rate_(rate), shortcut(shortcut), name(name) {};

    /*!
     *
     * setting rate of the currency
     * @param rate
     */
    inline void rate(float rate) {
        rate_ = rate;
    }

    bool operator==(const Currency &currency) {
        return (currency.rate_ == rate_ && name == currency.name && shortcut == currency.shortcut);
    }

};
