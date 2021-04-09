#include <iostream>
using namespace std;

#define STRING_LENGTH 10

int strLen(char s[]);
void strCopy(char copiedString[], char userString[]);
int strCmp(char copiedString[], char userString[]);
bool isLetter(char userString[]);  // Большая буква латинского алфавита
bool isWord(char userString[]);    // Большие буквы латинского алфавита
int strToInt(char userString[]);   // Цифры 

int main()
{   
    char copiedString[STRING_LENGTH];
    char userString[STRING_LENGTH];
    
    cout << "Enter your string: ";
    cin >> userString;
	// cin >> copiedString;
	
	// cout << strCmp(copiedString, userString) << endl;
	
    // cout << strLen(userString) << endl;
    
    // strCopy(copiedString,userString);
    
    // cout << copiedString << endl;

    // cout << strCmp(copiedString, userString) << endl;

    // isLetter(userString) ? cout << "Your string is a letter" : cout << "Your string isn't a letter";
	
    // isWord(userString) ? cout << "Your string is a word" : cout << "Your string isn't a word";

    cout << strToInt(userString);

    return 0;
}

int strLen(char userString[])
{   
    int count = 0;
    for(int i = 0; userString[i] !='\0'; ++i) {
        count++;
    }
    return count;
}

void strCopy(char copiedString[], char userString[])
{	
	copiedString[STRING_LENGTH] = {0};
	
	for(int i = 0; userString[i] !='\0'; ++i) {
		copiedString[i] = userString[i];
	}
}

int strCmp(char copiedString[], char userString[])
{
    for(int i = 0; userString[i] !='\0'; i++) {
		if(copiedString[i] > userString[i])
            return 1; 
        else if(copiedString[i] < userString[i])
            return -1;
        return 0;          
	}
}
bool isLetter(char userString[])
{   
    if(userString[0] >= 'A' and userString[0] <='Z') {
        return true;
    }
    return false;
}

bool isWord(char userString[])
{
    bool compare = true;
    
    for(int i = 0; userString[i] != '\0'; ++i) {
        if(userString[i] >= 'A' and userString[i] <= 'Z') {
        	compare = false;
		}
    }
    return compare;
}

int strToInt(char userString[])
{   
    int result = 0;
    for(int i = 0; userString[i] != '\0'; ++i) {
        result += userString[i] - '0';
        result *=10;
    }
    result /=10;
    
    return result;
}
