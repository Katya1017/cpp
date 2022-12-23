// 3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <iostream>
using namespace std;

void func(int* list, int length) {
    int* last;
    int lst = list[length];
    last = &lst;
    cout << *list << " ";
    int i = 1;
    while (list[i] != lst) {
        cout << list[i] << " ";
        i++;
    }
    cout << "\n \n";
}

float add(float x, float y) {
    return x + y;
}

float sub(float x, float y) {
    return x - y;
}

void (*pointer(float x, float y, char input))() {
    if (input == *"+") cout << add(x, y) << "\n";
    else cout << sub(x, y) << "\n";
    return 0;
}

int main(int argc, const char* argv[]) {
    int list[] = { 2,12,2022 };
    int length = sizeof(list) / sizeof(list[0]);
    func(list, length);

    float (*operation)(float, float);
    operation = add;
    std::cout << operation(2, 10) << "\n";
    operation = sub;
    std::cout << operation(2, 10) << "\n \n";

    void (*test)() = pointer(2, 3, 42);

    int* dm = new int(10);
    cout << dm << " = " << *dm << "\n";
    delete dm;



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
