#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row ;
int column;
char token='X';
bool tie=false;
string n1="";
string n2="";
class TicTacToeBoard {
private:
    char space[3][3]; // The board

public:
   
    TicTacToeBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                space[i][j] = ' '; // Initialize each cell with a space otherwise we cannot take value as input
            }
        }
    }
};
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear the terminal screen
}
void printBoard()
{
    
   cout << "   |   |   \n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << space[i][0] << " | " << space[i][1] << " | " << space[i][2] << " \n";
        if (i < 2) {
            cout << "___|___|___\n";
            cout << "   |   |   \n";
        }
    }
    cout << "   |   |   \n";

}



void takeMove() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter a number (1-9): ";
    } else {
        cout << n2 << ", please enter a number (1-9): ";
    }
    cin >> digit;

    switch (digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default: cout << "Invalid input! Please enter a number between 1 and 9.\n"; takeMove(); 
        return;
    }

    if (space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        token = (token == 'X') ? 'O' : 'X';
    } else {
        cout << "This cell is already occupied! Please choose another.\n";
        takeMove();
    }
    clearScreen();
    printBoard();
}
   
bool Logic()
{
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[1][i]==space[2][i])
        return true;
    }
      if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
      {
        return true;
      }
      for(int i=0;i<3;i++)
      {
        for(int j=0;j<3;j++)
        {
            if(space[i][j] !='X' && space[i][j]!='O')
            {
                return false;
            }
        }
      }
      tie=true;
     
      return false;
      
}

int main()
{
    
    cout<<"Enter the name of player 1:\n";
    getline(cin, n1);
    cout<<"Enter the name of player 2:\n";
    getline(cin, n2);
    cout<< n1<<" is player 1 and he/she will play first\n";
    cout<< n2<<" is player 2 and he/she will play second\n";
    
    
   printBoard();
    do
    {
        takeMove();
    } while (!Logic());
    
    
    
    if(token=='X' && tie==false)
    {
        cout<<"Congraculation "<< n2 <<" Wins!!"<<endl;

    }
    else if(token=='O' && tie==false)
    {
        cout<<"Congraculation "<< n1 <<" Wins!!"<<endl;
    }
    else if(tie == true)
    {
        cout<<"It's a draw!"<<endl;
    }
    else
    {
        cout<<"Invalid move"<<endl;
    }
}
