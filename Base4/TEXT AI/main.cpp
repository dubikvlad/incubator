#include <iostream>
#include <iomanip>

using namespace std;

#define N 3
#define ENG_LETTERS "AaBCcEeHKkMmOoPpTXxYy"
#define RUS_LETTERS "АаВСсЕеНКкМмОоРрТХхУу"
#define NEED_SYMBOLS_TO_MAKE_LOWERCASE 32

double antiPlagiarism(string text, string fragment);

int calcNumberOfWordsInString(string str1);
bool isDigit(char c);
bool isSeparator(char character);
bool isEngLetter(char c);

string symbolProcessing(string str1);
string toLowerCase(string str1);
string replaceEngLetters(string str1);

void extractWordsFromStringIntoArray(string source, string *destination);
int calcNumberOfMatchingShingles(string fragment[], int wordsInFragment, string text[], int wordsInText);
double calcPercentageOfCoincidenceShinglesFromTotalNumber(int hitCounter, int totalWords);


int main() {
    string text = "Здраствуйте набор слов, который сейчас пришел в глову, запятая, здесь в слове aнглийская буква";
    string fragment = "здесь в слове не английская буква";

    cout << "The fragment matches the original text by " << setprecision(4) << antiPlagiarism(text, fragment) << '%'
         << endl;

    return 0;
}

double antiPlagiarism(string text, string fragment) {
    int hitCounter = 0, 
        numberOfWordsInFragment = 0, 
        numberOfWordsInText = 0;

    fragment = symbolProcessing(fragment);
    text = symbolProcessing(text);

    fragment = replaceEngLetters(fragment);
    text = replaceEngLetters(text);

    fragment = toLowerCase(fragment);
    text = toLowerCase(text);

    numberOfWordsInFragment = calcNumberOfWordsInString(fragment);
    numberOfWordsInText = calcNumberOfWordsInString(text);

    string wordsFromFragment[numberOfWordsInFragment];
    string wordsFromText[numberOfWordsInText];

    extractWordsFromStringIntoArray(fragment, wordsFromFragment);
    extractWordsFromStringIntoArray(text, wordsFromText);

    hitCounter = calcNumberOfMatchingShingles(wordsFromFragment, numberOfWordsInFragment, wordsFromText,
                                              numberOfWordsInText);

    return calcPercentageOfCoincidenceShinglesFromTotalNumber(hitCounter, numberOfWordsInFragment);
}

bool isDigit(char c) {
    return c >= '0' and c <= '9';
}

int calcNumberOfWordsInString(string str1) {
    int counter = 0;
    bool flag = false;

    for (int i = 0; str1[i]; ++i) {
        if (str1[i] != ' ' and !flag) {
            flag = true;
        } else if (str1[i] == ' ' and flag or str1[i + 1] == '\0' and flag) {
            flag = false;
            counter++;
        }
    }
    return counter;
}

bool isSeparator(char character) {
    char separators[] = " .,-:;!?()+=/*";

    for (int i = 0; separators[i]; ++i) {
        if (character == separators[i]) {
            return true;
        }
    }
    return false;
}

string symbolProcessing(string str1) {
    for (int i = 0; str1[i]; ++i) {
        if (isDigit(str1[i]) or isSeparator(str1[i])) {
            str1[i] = ' ';
        } else {}
    }
    return str1;
}

string toLowerCase(string str1) {
    string s = "";

    for(int i = 0; str1[i]; i++) {
        if(str1[i] >= 'А' and str1[i] <= 'Я') {
            s += str1[i] + NEED_SYMBOLS_TO_MAKE_LOWERCASE; 
        }
        if(str1[i] == 'Ё') {
            s += 'ё';
        }
    }
    return s;  
}

string replaceEngLetters(string str1)
{
    string engLetters = ENG_LETTERS;
    string rusLetters = RUS_LETTERS;
    string s = "";
    int i, j;    

    for (i = 0; str1[i]; i++) {
        if (isEngLetter(str1[i])) {
            for (j = 0; str1[j]; j++) {
                if (str1[i] == engLetters[j]) {
                    s += rusLetters[j];
                }
            }
        }
    }
    return s;
}

bool isEngLetter(char c)
{
    return ('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z');
}

void extractWordsFromStringIntoArray(string source, string *destination) {
    int wordCounter = 0;

    for (int i = 0; source[i]; i++) {
        if (!isSeparator(source[i]) and isSeparator(source[i + 1])) {
            destination[wordCounter] += source[i];
            wordCounter++;
        } else if (!isSeparator(source[i]) and !isSeparator(source[i + 1])) {
            destination[wordCounter] += source[i];
        } else {}
    }

}

int calcNumberOfMatchingShingles(string fragment[], int wordsInFragment, string text[], int wordsInText) {
    int counter = 0, numberOfMatchedShingles = 0;

    for (int i = 0; i < wordsInFragment - N + 1; ++i) {
        for (int j = 0; j < wordsInText - N + 1; ++j) {
            for (int k = 0; k < N; ++k) {
                if (fragment[i + k] == text[j + k]) {
                    numberOfMatchedShingles++;
                }
            }
            if (numberOfMatchedShingles == N) {
                counter++;
            }
            numberOfMatchedShingles = 0;
        }
    }
    return counter;
}

double calcPercentageOfCoincidenceShinglesFromTotalNumber(int hitCounter, int totalWords) {
    int totalNumberOfShingles = totalWords - N + 1;
    return ((double) hitCounter / totalNumberOfShingles) * 100;
}
