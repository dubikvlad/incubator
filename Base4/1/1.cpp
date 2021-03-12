/*  
    1. МУТАНТЫ. Ночью на Минск напало m мутантов. Каждую ночь они размножаются на p процентов. Каждый день коммунальные службы Минска уничтожают n мутантов. Через сколько суток работники ЖЭСа отпразднуют победу над мутантами?
    2. КОНИ. Вводим 4 целых числа. это координаты двух коней на шахматной доске. Бьют ли они друг друга?
    [+]. (необязательно) 2->10. Переведите число из двоичной системы в десятичную.
*/

#include <iostream>
using namespace std;

int main()

{   
    int m = 0,
        p = 0,
        peopleCanKill = 0,
        days = 0;

    cout << "Enter how much monstrs in Minsk" << endl;
    cin >> m;
    cout << "Enter percent in night" << endl;
    cin >> p;
    cout << "How many monstrs can people destroy" << endl;
    cin >> peopleCanKill;

    if(m < 0)
        cout << "Monsters will never born";
    if(m == peopleCanKill || m < peopleCanKill)
    {
        cout << "peolpe need " << days + 1 << " day(s) to destroy all monsters" << endl;
    }    
    else {
        while (m > 0)
        {
            m -= peopleCanKill - (m - peopleCanKill) * p / 100;
            days ++;
            if (days == 999)
            {
                break;
            }
            
        }
        
    }
    
    if(days == 999){
        cout << "Monsters will win" << endl;
    }else if(days != 0){
        cout << "peolpe need " << days << " day(s) to destroy all monsters" << endl;
    }      

    return 0;
}

