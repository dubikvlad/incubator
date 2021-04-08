#include <iostream>
#include <cstdlib>
using namespace std;
#define N 7

int arr[N][N][N] = {0}; 
int countForCompare = 0;
int countForResult = 0;

void fillSpace();
void compareY();
void compareX();
void compareZ();
void displayMatrix();

int main()
{
    

    cout<< "Our cube has " << N << " * "  << N << " * "  << N << " sides " << endl;

    fillSpace();
    compareY();
    if(countForResult == 0) 
        compareX(); 
    if(countForResult == 0) 
        compareZ();
    if(countForResult == 0)
        cout << "There is no light" << endl;
        
    displayMatrix();    
}

void fillSpace()
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++){
                arr[i][j][k] = rand() % 2;                
            }
        }
    }
}

void displayMatrix()
{
    for(int i = 0; i < N; i++)      //Display matrix
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                cout << arr[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void compareY()
{
    for(int i = 0; i < N; i++) {                     //compare y
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
               if(arr[i][j][k] == 0) {
                   countForCompare++;
                   if(countForCompare == N){
                        cout << "There are light somewhere" << endl;
                        countForResult++;
                    }   
               }  
            }
            countForCompare = 0;
        }
        if(countForResult != 0)
            break;
    }
}

void compareX()
{
    for(int i = 0; i < N; i++) {                     //compare x
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) { 
                if(arr[i][k][j] == 0) {
                    countForCompare++;
                    if(countForCompare == N){
                        cout << "There are light somewhere" << endl;
                        countForResult++;
                        break;
                    }                        
               }  
            }
            countForCompare = 0;
        }
        if(countForResult != 0)
            break;
    }
}

void compareZ()
{
    for(int i = 0; i < N; i++) {                     //compare z
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) { 
                if(arr[k][j][i] == 0) {
                    countForCompare++;
                    if(countForCompare == N){
                        cout << "There are light somewhere" << endl;
                        countForResult++;
                        break;
                    }  
               }  
            }
            countForCompare = 0;
        }
        if(countForResult != 0)
            break;
    }
}
