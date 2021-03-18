/*1) ЧИСЛО СУДЬБЫ. Цифры полной даты рождения суммируются, пока не получится одна цифра. 
Разработайте функцию и вычислите свое число судьбы)*/

#include <iostream>
using namespace std;

void enterNumbers(int &year, int &month, int &day);
void calculateFateNumber(int d, int m, int y);
int calculateSumOfNumerals(int n);

int main()
{
    int y = 0, m = 0, d = 0;
    
    enterNumbers(y, m, d);
    calculateFateNumber(y, m, d); 

    return 0;
}

void enterNumbers(int &year, int &month, int &day)
{
    cout << "Input year: ";
    cin >> year;
    cout << "Input month: ";
    cin >> month;
    cout << "Input day: ";
    cin >> day;
}

void calculateFateNumber(int d, int m, int y)
{
    cout << "Your fate number is: " << calculateSumOfNumerals(d) + calculateSumOfNumerals(m) + calculateSumOfNumerals(y);
}

int calculateSumOfNumerals(int n)
{
    int result = 0;

    for(int i = n ; i > 0;  i /= 10)
    {    	
        result += i % 10;
    }

    return result;
}
