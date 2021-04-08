//КРЕСТИКИ-НОЛИКИ. Запрограммируйте и сыграйте с компьютером в игру "Крестики-нолики".
#include <iostream>
using namespace std;

#define SPACE ' '

char arr[3][3] = {                        
    {SPACE, SPACE, SPACE},
    {SPACE, SPACE, SPACE},
    {SPACE, SPACE, SPACE}
};

void computerTurn();                 
void playerTurn();                   
void displayPlayingField();                   
char checkWin();                        // win or not?
char checkColumn();                     
char checkString();
char checkDiagonal();                        
void cleanDisplay();

int main()
{
    char done;

    cout << "        Tic-Tac-Toe" << endl << endl;
    cout << "        [   X0X   ]" << endl;
    cout << "        [   0X0   ]" << endl;
    cout << "        [   X0X   ]" << endl << endl;
    cout << "This is your playing field" << endl << endl;

    done = SPACE;

    do {
        displayPlayingField(); 
        playerTurn(); 

        done = checkWin(); 
        
        if (done != SPACE) 
            break; 
        
        computerTurn(); 
        done = checkWin(); 
    } 
    while(done == SPACE);

    if(done == 'X') 
        cout << "You won!" << endl;
    else 
        cout << "You lose." << endl;

    displayPlayingField(); 
    return 0;
}


void playerTurn()
{
    int x, y;

    cout << "Enter coordinates for your X." << endl;
    cout << "Row: ";
    cin >> x;
    cout << "Column: ";
    cin >> y;

    x--; 
    y--;

    if (x<0 || y<0 || x>2 || y>2 || arr[x][y] != SPACE) {
        cout << "Invalid move, try again." << endl;
        playerTurn();
    }
    else 
        arr[x][y] = 'X';
}


void computerTurn()
{   
    int i;
    char *p;
    p = (char *) arr;

    for (int i = 0; *p != SPACE && i < 9; ++i) 
            p++;
    if(i == 9) {
        cout << "Draw" << endl;
        exit(0); 
    }
    else 
        *p = 'O';
        cleanDisplay();
}


void displayPlayingField()
{   
    for(int i = 0; i < 3; i++){
        printf(" %c | %c | %c", arr[i][0], arr[i][1], arr[i][2]);
        
        if(i !=2) 
            cout << "\n - | - | - \n";
    }
    cout << endl;
}


char checkWin()
{   
    checkColumn();
    checkString();
    checkDiagonal();   
}

void cleanDisplay()
{
    system("cls");
}

char checkColumn()
{   
    char *p;

    for(int i = 0; i < 3; i++) { 
        p = &arr[0][i];
        if(*p == *(p+3) && *(p+3) == *(p+6)) return *p;
    }

}

char checkString()
{
    char *p;

    for(int i = 0; i < 3; i++) { 
        p = &arr[i][0];
        if (*p == *(p+1) && *(p+1) == *(p+2)) return *p;
    }
}

char checkDiagonal()
{
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] )
        return arr[0][0];
    else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return arr[0][2];
    else
        return SPACE;
}
