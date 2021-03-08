/*
    4. УГАДАЙ ЧИСЛО. Разработайте игру: компьютер загадывает число
     и выдает подсказки ("больше-меньше") пользователю.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{   
    srand( time( 0 ) );
    int random = rand(),
        userNum;

    cout << "Enter your number to find random ";
    cin >> userNum;    
    //cout << random << endl;

    while(userNum != random){
        if(userNum > random){
            cout << "Our number less than your, try again ";
            cin >> userNum;
        }else if(userNum < random){
            cout << "Our number more than your, try again ";
            cin >> userNum;
        }       
    }
    if(userNum == random){
        cout << "Yes, it is";
    }else
        cout << "Error";
    
    return 0;
}
