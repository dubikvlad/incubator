/*
     [+]. (необязательно) 2->10. Переведите число из двоичной системы в десятичную.
*/   


#include<iostream>
#include <cmath>
using namespace std;

int main() {
    int number,
        result = 0,
        numberLength;
    
    cout << "enter binary number:  ";
    cin >> number;

    for(int i = number ; i > 0 ; i/=10){
        numberLength++;
    }

    for(int i = 0; i < numberLength; i++){
        result += (number % 10) * pow(2 , i);
        number /= 10;
    }

    cout << "result: " << result;

    return 0;
}
