/*
    2. НОВОБРАНЦЫ. Новобранцы выстроены в шеренгу. 
    По команде НАЛЕ–ВО! одни из них поворачиваются налево, а другие – направо. 
    Это есть начальное положение шеренги. 
    Далее каждый новобранец действует следующим образом: увидев перед собой лицо соседа, он ровно через секунду поворачивается кругом. 
    В конце концов повороты прекратятся.Тогда сержант подает звуковой сигнал.
*/
#include<iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define NUMBER_OF_SOLDERS 10

char solders[NUMBER_OF_SOLDERS];

void fillLine();
void turnLeft();
void cleanDisplay();
void waitSecond();
void showLine();
bool anyoneSeeEachOther();
void changePosition();

int main() 
{   
    fillLine();
    showLine();    
    turnLeft(); 
    showLine();

    bool yes = true;     

    while(anyoneSeeEachOther() == yes) {
        changePosition();
        showLine();
    }

    return 0;
}

void fillLine() 
{
    for(int i = 0; i < NUMBER_OF_SOLDERS; i++) {
        solders[i] = '<';
    }
}

void turnLeft()
{   
    cleanDisplay();
    cout << "TO THE LEFT!" << endl;   
    
    for(int i = 0; i < NUMBER_OF_SOLDERS; i++) {
    	int random;
        random = rand() % 2;

        if(random == 0) {
            solders[i] = '<';
        }
        else {
            solders[i] = '>';
        }
    }
    waitSecond();
}

void cleanDisplay()
{
    system("cls");
}

void waitSecond()
{	
	Sleep(1000);
}

void showLine()
{
    cout << solders << endl;
}

bool anyoneSeeEachOther()
{   
    bool anyoneSeeEachOther = false;

    for(int i = 0; i < NUMBER_OF_SOLDERS - 1; i++) {
        if(solders[i] == '>' && solders[i + 1] == '<') {            
            anyoneSeeEachOther = true;                   
        }            
	}

    return anyoneSeeEachOther;
}

void changePosition() 
{   
    char symbol1[1] = {};
    char symbol2[1] = {};

    waitSecond(); 

    for(int i = 0; i < NUMBER_OF_SOLDERS - 1; i ++) {
        if(solders[i] == solders[i + 1]) {
            continue;
        }
        else if(solders[i] == '>' && solders[i + 1] == '<'){
        	symbol1[0] = solders[i];
            symbol2[0] = solders[i + 1];
            solders[i] = symbol2[0];
            solders[i + 1] = symbol1[0];
            i++;
		}
		else
			continue;
            
    } 
     
}
