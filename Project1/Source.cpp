#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Введите строку" << endl;

    string x;
    cin >> x;

    cout << x.substr(1, 3) << endl;

    size_t y = x.find('a');
    if (y >= x.size()) {
        cout << "Символа a не найдено" << endl;
    }
    else {
        cout << "Индекс первого символа а: " << y << endl;
    }
}