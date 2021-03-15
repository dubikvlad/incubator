//2. ЕДИНИЦЫ. Найдите все натуральные числа до m, двоичная запись которых состоит из единиц

#include <iostream>
#include <cmath>
using namespace std;

int units(int n);
int toBinary(int);

int main() 
{   
    int number,
        binaryNumber;

    cout << "Enter positive number: ";
    cin >> number;

    while(number < 0){
        cout << "Error! \n Enter positive number: ";
        cin >> number; 
    }

    toBinary(number);
    

    return 0;
}

int toBinary(int number)
{   
    int binaryNumber;
    for(int i = 0 ; number > 0; i++)
    {
        binaryNumber += (number % 2) * pow(10.0 , i);
        number /= 2;
    }
    units(binaryNumber);
}

int units(int n)
{   
    int result = 0,        
        numberLength = 0;
    
    cout << "The numbers, that have only '1' in binary till your number are: \n";

    for(int i = 1; i < n; i = i * 10 + 1)
    {   
        int bin = i;

        cout << i << endl;

        for(int j = bin ; j > 0 ; j /= 10){
            numberLength++;
        }

        for(int j = 0; j < numberLength; j++){
            result += (bin % 10) * pow(2 , j);
            bin /= 10;
        }         
        
        cout << result << endl; 

        result = 0; 
        numberLength = 0;                   
    }
}

