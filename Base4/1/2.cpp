/*
     2. КОНИ. Вводим 4 целых числа. это координаты двух коней на шахматной доске. Бьют ли они друг друга?
*/
#include <iostream>
using namespace std;

int main(){
    int x1 = 0,
        y1 = 0,
        x2 = 0,
        y2 = 0;
    
    cout << "Enter x for 1st knight \n";
    cin >> x1;
    cout << "Enter y for 1st knight \n";
    cin >> y1;
    
    while(x1 <= 0 || x1 > 8 || y1 <= 0 || y1 > 8){
		cout << "Wrong coordinates for 1st knight \n";
		cout << "Enter x for 1st knight \n";
    	cin >> x1;
		cout << "Enter y for 1st knight \n";
    	cin >> y1;
	}
	
    cout << "Enter x for 2nd knight \n";
    cin >> x2;
    cout << "Enter y for 2nd knight \n";
    cin >> y2;
	
	while(x2 <= 0 || x2 > 8 || y2 <= 0 || y2 > 8){
		cout << "Wrong coordinates for 2nd knight \n";
		cout << "Enter x for 2nd knight \n";
    	cin >> x2;
    	cout << "Enter y for 2nd knight \n";
    	cin >> y2;
	}
	
	if(x1 == x2 && y1 == y2){
		cout << "Error! Knights have the same position";
		return -1;
	}
		
    if ((x1 + 2 == x2 && y1 - 1 == y2) ||
    	(x1 + 2 == x2 && y1 + 1 == y2) ||
        (x1 + 1 == x2 && y1 - 2 == y2) ||
        (x1 - 1 == x2 && y1 - 2 == y2) ||
        (x1 - 2 == x2 && y1 - 1 == y2) ||
        (x1 - 2 == x2 && y1 + 1 == y2) ||
        (x1 - 1 == x2 && y1 + 2 == y2) ||
        (x1 + 1 == x2 && y1 + 2 == y2))
    {
        cout << "Knights beats each other";
    }else{
        cout << "Knights don't beats each other";
    }
    
    return 0;
}
