//2. ЕДИНИЦЫ. Найдите все натуральные числа до m, двоичная запись которых состоит из единиц

#include <iostream>
#include <cmath>
using namespace std;

int printResult(int n);
int convertToBinaryNumber(int);
int convertToDecNumber(int);
int printDecNumber(int);

int main() 
{   
    int number;

    cout << "Enter positive number: ";
    cin >> number;

    while(number < 0){
        cout << "Error! \n Enter positive number: ";
        cin >> number; 
    }

    convertToBinaryNumber(number);    

    return 0;
}

int convertToBinaryNumber(int number)
{   
    int binaryNumber;
    for(int i = 0 ; number > 0; i++)
    {
        binaryNumber += (number % 2) * pow(10.0 , i);
        number /= 2;
    }
    printResult(binaryNumber);
}

int printResult(int n)
{   
    cout << "The numbers, that have only '1' in binary till your number are: \n";       

    for(int i = 1; i < n; i = i * 10 + 1)
    {
        convertToDecNumber(i);  

        cout << " this is " << i << " in binary system" << endl;                         
    }
}

int convertToDecNumber(int bin)
{
    int result = 0,        
        numberLength = 0;  

    for(int j = bin ; j > 0 ; j /= 10)
    {
        numberLength++;
    }
    for(int j = 0; j < numberLength; j++)
    {
        result += (bin % 10) * pow(2 , j);
        bin /= 10;
    }         
        
    printDecNumber(result);

    result = 0; 
    numberLength = 0;
}

int printDecNumber(int number)
{
    cout << number;
}