//1. СТЕПЕНЬ. Разработайте функцию, которая возводит x в степень n.

#include<iostream>
#include <math.h>
using namespace std;

double pow(int x, int n);

int main() {
    int x, n;

    cout << "Enter integer number: ";
    cin >> x;
    cout << "Enter the power of number(integer number): ";
    cin >> n;

    pow(x, n);        

    return 0;
}

double pow(int x, int n)
{
    double result = 1;

    if(n == 0){
        cout << result;
        return 0;    
    }
    else if(n != 0){
        for(int i = 1; i <= abs(n); i++){
            result *= x;            
        }		
		if(n < 0){
			if(x == 0)
				result = 0;
        	else 
				result = 1 / result;             
    	}	

    cout << "Result = " << result; 
	}else{
		cout << "Error!";
		return -1;
	}
}
