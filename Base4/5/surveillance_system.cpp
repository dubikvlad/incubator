/*
    1.СИСТЕМА НАБЛЮДЕНИЯ. В массиве хранятся значения высот профиля местности с постоянным шагом по горизонтали. 
    Найдите области (точки высот), невидимые для наблюдателя, находящегося в первой точке.
*/

#include <iostream>
using namespace std;

#define LENGTH 10
#define STEP 1

double values[LENGTH], heightDifference, tgAngle;

void enterValues();
void compareViewingAngle();
double printTrueResult(double result);
double printFalseResult(double result);

int main()
{   
    cout << "Enter profile height" << endl;   
    
    enterValues();
	
	cout << "Our heigt is " << values[0] << endl;
    cout << "You can see height " << values[1] << " anyway." << endl;

    heightDifference = values[1] - values[0];
    tgAngle = heightDifference / 1 * STEP; 

    compareViewingAngle();
   
    return 0;
}

void enterValues() {
    int inputValue;

    for(int i = 0; i < LENGTH; i++) {
        cout << "Enter " << i + 1 << " position: ";
        cin >> inputValue;
        values[i] = inputValue; 
    }

    cout << endl;
}

void compareViewingAngle() {

    double currentTgAngle;

    for (int i = 2; i < LENGTH; i++){
        heightDifference = values[i] - values[0];
        currentTgAngle = heightDifference / i * STEP;

        if(currentTgAngle > tgAngle) {
            printTrueResult(values[i]);
            tgAngle = currentTgAngle ;          
            
        }
        else {
            printFalseResult(values[i]);
        }        
    }
}

double printTrueResult(double result) {
    cout << "You can see height: " << result << endl;
}

double printFalseResult(double result) {
    cout << "You can't see height: " << result << endl;
}
