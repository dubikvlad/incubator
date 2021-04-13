/*
    1. ПЛЮС-МИНУС. Замените в строке каждую четную цифру плюсами, а нечетную – минусами в количестве равном значению цифры.
*/

#include <iostream>
using namespace std;

#define N 256

void strCopy(char copiedString[], char userString[]);
void displayNewString();


char userString[N] = "6w3e12";
char tempString[N];
int pointer = 0;

int main()
{   
    for(int i = 0; userString[i] != '\0'; i++) {
        if(userString[i] >= '0' and userString[i] <= '9') {
            if((userString[i] % 2) == 0) {
                for(int j = 0; j < userString[i] - '0'; j++) {
                    tempString[pointer] = '+';
                    tempString[pointer + 1] = '\0';
                    pointer++;
                }
            }
            else {
               for(int j = 0; j < userString[i] - '0'; j++) {
                    tempString[pointer] = '-';
                    tempString[pointer + 1] = '\0';
                    pointer++;
                } 
            }
        }
        else {
            tempString[pointer] = userString[i];
            tempString[pointer + 1] = '\0';
            pointer ++;
        }
	}
    
    strCopy(userString, tempString);
    displayNewString();

    return 0;
}

void strCopy(char copiedString[], char userString[])
{	
	copiedString[N] = {0};
	
	for(int i = 0; userString[i] !='\0'; ++i) {
		copiedString[i] = userString[i];
	}
}

void displayNewString()
{
    for(int i = 0; userString[i] != '\0'; i++) {
        cout << userString[i];
    }
}