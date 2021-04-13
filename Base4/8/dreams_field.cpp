/*
    2. ПОЛЕ ЧУДЕС. Запрограммируйте игру: открываем буквы, угадываем слово, в конце - шутка Якубовича.
*/
#include <iostream>
using namespace std;

#define N 30
void fillHideWord();
bool areEqual(char hideWord[], char secretWord[]);
void changeHideWord();
void cleanDisplay();
void showMessageTrue();
void showMessageFalse();
void isThereSuchLetter();
void showMenu();

char secretWord[N] = "ARRAY";
char hideWord[N];
char yourLetter[2];

int main()
{   
    showMenu();
    fillHideWord();
    cout << hideWord << endl;

    while (!areEqual(secretWord, hideWord))
    {
        cout << "Enter your letter: ";
        cin >> yourLetter;

        cleanDisplay();
        isThereSuchLetter();
        changeHideWord();       

        cout << hideWord << endl;
    }
    cout << "You won invisible jar of cucumbers. =)";

    return 0;
}

void fillHideWord()
{
    for(int i = 0; secretWord[i] != '\0'; i++) {
        hideWord[i] = '*';
    }
}

bool areEqual(char hideWord[], char secretWord[])
{
    bool areEqual = true;

    for(int i = 0; secretWord[i] !='\0'; i++) {
		if(hideWord[i] != secretWord[i]){
            areEqual = false;
            break;  
        }                
	}
    return areEqual;
}

void cleanDisplay()
{
    system("cls");
}

void changeHideWord()
{
    for(int i = 0; secretWord[i] != '\0'; i++) {
        if(secretWord[i] == yourLetter[0]) {
            hideWord[i] = yourLetter[0];
    	}
	}
}

void isThereSuchLetter()
{   
    bool isThereSuchLetter = false;

    for(int i = 0; secretWord[i] != '\0'; i++) {
        if(secretWord[i] == yourLetter[0]) {
            cout << "There is such letter in the word" << endl;
            isThereSuchLetter = true;
            break;
        }
    }
    if(!isThereSuchLetter)
        cout << "There is no such letter in the word" << endl;
}

void showMenu()
{
    cout << "This is game: \"Field of miracles\"" << endl;
    cout << "Guess our word =)" << endl << endl;
}