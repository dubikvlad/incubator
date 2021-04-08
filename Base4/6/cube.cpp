#include <iostream>
#include <cstdlib>
using namespace std;
#define N 5

int arr[N][N][N] = {0}; 
int countForCompareY = 0;
int countForCompareX = 0;
int countForCompareZ = 0;
int countForResult = 0;


void fillSpace();
void compareSides();
void compareY(int i, int j, int k);
void compareX(int i, int j, int k);
void compareZ(int i, int j, int k);
void displayMatrix();

int main()
{
    

    cout<< "Our cube has " << N << " * "  << N << " * "  << N << " sides " << endl;

    fillSpace();
    compareSides();
    
    if(countForResult != 0)
        cout << "There are light somewhere" << endl;
    
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

void compareSides()
{
    for(int i = 0; i < N; i++) {                     
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
               compareY(i, j, k);
               compareX(i, j ,k);
               compareZ(i, j, k);
            }
            countForCompareY = 0;
            countForCompareX = 0;
            countForCompareZ = 0;
        }
    }
}

void compareY(int i, int j, int k)
{
    if(arr[i][j][k] == 0) {   //compare y
        countForCompareY++;
        if(countForCompareY == N){
            countForResult++;
        }   
    }
}

void compareX(int i, int j, int k)
{
    if(arr[i][k][j] == 0) {  //compare x
        countForCompareX++;
        if(countForCompareX == N){
            countForResult++;
        }                        
    }
}
void compareZ(int i, int j, int k)
{
    if(arr[k][j][i] == 0) {  //compare z
        countForCompareZ++;
        if(countForCompareZ == N){
            countForResult++;
        }  
    }    
}
