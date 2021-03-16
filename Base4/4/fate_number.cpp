#include <iostream>
using namespace std;

void calculeteFateNumber(int);
int enterNumbers(int);

int main()
{   
    calculeteFateNumber(enterNumbers(int a, int b, int c));

    return 0;
}

void calculeteFateNumber(int day, int month, int year)
{
    cout << day + month + year;
}

int enterNumbers()
{   
    int day, month, year;

    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    return (day, month, year);
}
