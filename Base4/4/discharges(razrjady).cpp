/*2) РАЗРЯДЫ. Разработайте функцию, которая "переворачивает" переданное ей целое число, например: 1234 -> 4321*/

#include <iostream>
using namespace std;

void inputNumber(int &n);
int flipNumber(int n);
void printNumber(int n);

int main()
{   
    int number = 0;
    
    inputNumber(number);
    printNumber(flipNumber(number));

    return 0;
}

void inputNumber(int &n)
{
    cout << "Input number: ";
    cin >> n;
}

int flipNumber(int n)
{
    int number = n,
		result = 0;        ;

    for (int i = n; i > 0; i /= 10)
    {
        result = result * 10 + (number % 10);
        number /= 10;        
    }
    return result;
}

void printNumber(int n)
{
	cout << "Result is: " << n;
}
