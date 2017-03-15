//
// Created by Jakub Patoleta on 15.03.2017.
//

#pragma once

class UserInput {

    UserInput() {}

public:
    static UserInput& getInstance() {
        static UserInput instance;
        return instance;
    }

    void showMainMenu();
};
