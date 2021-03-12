//    1. НОК. Найдите наименьшее общее кратное двух натуральных чисел.


#include<iostream>
using namespace std;

int main()
{
    int a, b, NOD, NOK;

    cout << "Enter first number ";
    cin >> a;
    cout << "Enter second number ";
    cin >> b;

    while(a < 0 or b < 0){
        cout << "Error! Numbers couldn't be less than 0 \n";
        cout << "Enter first number ";
        cin >> a;
        cout << "Enter second number ";
        cin >> b;
    }
    if(a == 0){
        NOK = b;
    }
	else if(b == 0){
		NOK = a;
    }    
    else{
        for(int i = a; i > 0; i--){
            if (a % i == 0 && b % i == 0) {
                NOD = i;
                break;                
            }
        }
        NOK = a * b / NOD;
    }       

    cout << "NOK numbers " << a << " and " << b << " = " << NOK;

    return 0;
}
