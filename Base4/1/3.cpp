/*
     [+]. (необязательно) 2->10. Переведите число из двоичной системы в десятичную.
*/   


#include<iostream>
#include <cmath>
using namespace std;

int main() {
    int number,
        result = 0,
        numberLength = 0;
    
    cout << "enter binary number:  ";
    cin >> number;

    while(number < 0){
        cout << "Error! Enter positive number. \n";
        cout << "enter binary number:  ";
        cin >> number;
    }

    for(int i = number ; i > 0 ; i /= 10){
        numberLength++;
    }

    for(int i = 0; i < numberLength; i++){
        result += (number % 10) * pow(2 , i);
        number /= 10;
    }

    cout << "result: " << result;

    return 0;
}
