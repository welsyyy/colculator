// PointerFunction
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void Function()
{
    cout << "Выполняется функция Function!" << endl;
}

float Summa(float A, float B)
{
    return A + B;
}
float Raznost(float A, float B)
{
    return A - B;
}
float Proizvedenie(float A, float B)
{
    return A * B;
}
float Chastnoe(float A, float B)
{
    return A / B;
}

int main()
{
    system("chcp 1251 > NUL");

    /*
    Function(); //вызов функции по её имени с использованием оператора вызова функции ()
    //получение адреса функции через оператор взятия адреса
    cout << "Адрес функции Function: " << &Function << endl;
    //получение адреса функции по её имени(имя функции - указатель, хранящий адрес начала функции в памяти)
    cout << "Адрес функции Function: " << Function << endl;
    //Function = nullptr;  //имя функции - это константный указатель
    //cout << main << endl; (имя функции - указатель, хранящий адрес начала функции в памяти)

    system("cls");

    //объявлем указатель на функцию без параметров и без возвращаемого результата
    void (*ptrFunction)() = nullptr; //нулевой указатель на функцию без параметров и без возвращаемого результата
    ptrFunction = Function; // ptrFunction = &Function;  //передаем адрес функции в указатель

    *ptrFunction; //вызова функции не будет, будет получен адрес функции
    (*ptrFunction)(); //вызов функции через её адрес, полученный путем разыменования указателя ptrFunction
    ptrFunction(); //вызов функции через указатель на неё
    */

    cout << "---Самый высокотехнологичный калькулятор!---" << endl;
    float A = 0.0F, B = 0.0F;
    char Key = '+';

    //нулевой указатель на функции возвращающие float и принемающее 2 аргумента типа float
    float (*calc)(float, float) = nullptr;
    do
    {
        system("cls");
        cout << R"(
Используйте действия по образцу:
Сложение:                    А+В
Вычитание:                   А-В
Умножение:                   А*В
Деление:                     А/В
Степень:                     A^B
Корень:                      A@B
)";
        //множественный ввод
        cin >> A >> Key >> B;
        switch (Key)
        {
        case '+':
            calc = Summa;//присваиваем в указатель адрес функции Summa
            break;
        case '-':
            calc = Raznost;//присваиваем в указатель адрес функции Raznost
            break;
        case '*':
            calc = Proizvedenie;//присваиваем в указатель адрес функции Proizvedenie
            break;
        case '/':
            calc = Chastnoe;//присваиваем в указатель адрес функции Chastnoe
            break;
        case '@':
        default:
            Key = '0'; //обозначение что выбрана некорректная функция
            break;
        }
        if (Key != '0') cout << "Результат равен: " << calc(A, B) << endl;
        else cout << "Некорректное действие!" << endl;
        //вопрос о продолжении вычислений
        cout << "Продолжить вычисления (Y/N)? "; cin >> Key;
    } while (Key == 'Y' || Key == 'y'); //цикл работает пока пользолватель отвечает "Да" на вопрос о продолжении вычислений
    cout << "Выход из программы..." << endl;
    Sleep(1500); //задержка работы программы в 1500 миллисекунд(1.5 секунды)
}
