#include <iostream>
using namespace std;

int moves = 0;
int iteration = 0;
int row = 3;
int column = 3;
char x_num, o_num;
char matrix[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void drawMatrix(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            ++iteration;
            if(iteration%3==0){
                cout << matrix[i][j] << endl;
            } else{
            cout << matrix[i][j];
            }
        }
    }
}

bool isPositionWinning(char player) {
    return (matrix[0][0]==matrix[0][1] && matrix[0][0]==matrix[0][2] && matrix[0][0]==player) || (matrix[1][0]==matrix[1][1] && matrix[1][0]==matrix[1][2] && matrix[1][0]==player) ||     (matrix[2][0]==matrix[2][1] && matrix[2][0]==matrix[2][2] && matrix[2][0]==player) || (matrix[0][0]==matrix[1][0] && matrix[2][0]==matrix[0][0] && matrix[2][0]==player) || (matrix[0][1]==matrix[1][1] && matrix[1][1]==matrix[2][1] && matrix[1][1]==player) || (matrix[0][2]==matrix[1][2] && matrix[1][2]==matrix[2][2] && matrix[1][2]==player) || (matrix[1][1]==matrix[0][0] && matrix[0][0]==matrix[2][2] && matrix[0][0]==player) || (matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[1][1]==player);
}

char whoWon(){
    if(isPositionWinning('x')) return 'X';
    if(isPositionWinning('o')) return 'O';
    return ' ';
}

void move(char num, char player){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            if(matrix[i][j] == num){
                matrix[i][j] = player;
                break;
            }
        }
    }
}



void validateInput(char num, char player){
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                if(matrix[i][j] == num){
                    return;
                }
            }
        }
        cout << player << " please enter a VALID number: ";
        if(player == 'x'){
            cin >> x_num;
            validateInput(x_num, player);
        }
        else if(player == 'o'){
            cin >> o_num;
            validateInput(o_num, player);
        } else return;
}

int main() {
    while (whoWon() == ' ') {
        drawMatrix();
        cout << "X player enter a number: ";
        cin >> x_num;
        validateInput(x_num, 'x');
        move(x_num, 'x');
        ++moves;
        
        if(moves > 8) break;
        if(whoWon() != ' '){
            drawMatrix();
            cout << "The winner is " << whoWon() << endl;
            return 0;
        };
        
        drawMatrix();
        cout << "O player enter a number: ";
        cin >> o_num;
        validateInput(o_num, 'o');
        move(o_num, 'o');
        ++moves;
    };
    drawMatrix();
    if(whoWon() != ' '){
        cout << "The winner is " << whoWon() << endl;
        return 0;
    };
    cout << "It's a tie" << endl;
    return 0;
}
