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
        if (year < 1850) throw "���-�� �� �������...";
        else if (year > 2022) throw "�� ��� �� ��������";
        else if (year < 0) throw "�� ����� ������������� �����!";
        else return year;
    }


};

#endif /* User_h */