/*
    1. НОК. Найдите наименьшее общее кратное двух натуральных чисел.
*/

#include<iostream>
using namespace std;

int main()
{
    int a, b, NOD, NOK;

    cout << "Enter first number ";
    cin >> a;

    cout << "Enter second number ";
    cin >> b;

    for(int i = a; i > 0; i--){
        if (a % i == 0 && b % i == 0) {
            NOD = i;
            break;
        }
    }

    NOK = a * b / NOD;

    cout << "NOK numbers " << a << " and " << b << " = " << NOK;

    return 0;
}
