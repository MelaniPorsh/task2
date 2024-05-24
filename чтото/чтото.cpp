// чтото.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

class someclass
{
public:
	someclass(int*, size_t len);
	~someclass();
	void setLength(int value);
	unsigned int getLength();
	const char* resulCalc();
protected:
	int calkMidleValue();
	int calcSumOfValue();
private:
	int* mas;
	int length;
    string resultString;
	void resize();
};

someclass::someclass(int* arr, size_t len) {
    length = len;
    mas = new int[length];
    for (int i = 0; i < length; i++) {
        mas[i] = arr[i];
    }
}

someclass::~someclass() {
    delete[] mas;
}

void someclass::setLength(int value) 
{
    length = value;
    resize();
}


unsigned int someclass::getLength() {
    return static_cast<unsigned int>(length);
}

const char* someclass::resulCalc() {
    int sum = calcSumOfValue();
    int middle = calkMidleValue();
    stringstream ss;
    ss << "Сумма: " << sum << ", Среднее значение: " << middle;
    resultString = ss.str();
    return resultString.c_str();

}

int someclass::calkMidleValue() 
{
    int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += mas[i];
    }
    return sum / length;
}

int someclass::calcSumOfValue() {
    int sum = 0;
    for (size_t i = 0; i < length; i++) 
    {
        sum += mas[i];
    }
    return sum;
}

void someclass::resize() 
{
    int* newMas = new int[length];
    memcpy(newMas, mas, sizeof(int) * length);
    delete[] mas;
    mas = newMas;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    someclass obj(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "Текущая длина: " << obj.getLength() << endl;
    cout << "Результат: " << endl << obj.resulCalc() << endl;

    obj.setLength(3);
    cout << "Новая длина: " << obj.getLength() << endl;
    cout << "Результат: " << endl << obj.resulCalc() << endl;

    return 0;
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
