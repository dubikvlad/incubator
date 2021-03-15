/*
    3. ЦИФРА. Распечатайте первую цифру из дробной части вещественного положительного числа.
*/

#include<iostream>
#include <math.h>
using namespace std;

int main()
{   
    double number;
    int result;

    cout << "Enter fractional number: " ;
    cin >> number;
    
    result = abs((int)(number * 10) % 10);
    cout << result;  
    
    return 0;
}
