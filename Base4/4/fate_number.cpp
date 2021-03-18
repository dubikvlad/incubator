#include <iostream>
using namespace std;

void calculeteFateNumber(int day, int month);
int enterNumbers();
int enterDay();
int enterMonth();

int main()
{   
	int day, month, year;

    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;  



    calculeteFateNumber(day, month);

    return 0;
}

void calculeteFateNumber(int day, int month)
{
    cout << day << month;
}


