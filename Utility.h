//
// Created by Jakub Patoleta on 13.03.2017.
//

#pragma once

#include <cmath>

class Utility {

public:
    /*!
     * Static Utility class's method, rounding down to 2 decimal places
     * @param number - float number to be rounded
     * @return float expressed in two decimal places
     */
    static float roundTo2Places(float number) {
        return static_cast<float>(floor(number * 100) / 100.0f);
    }



};