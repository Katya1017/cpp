#pragma once


#ifndef User_h
#define User_h
using namespace std;

class User {

private:
    int year;

public:

    User(int year) {
        this->year = year;
    }

    int getYear() {
        if (year < 1850) throw "Что-то не верится...";
        else if (year > 2022) throw "Вы ещё не родились";
        else if (year < 0) throw "Вы ввели отрицательное число!";
        else return year;
    }


};

#endif /* User_h */