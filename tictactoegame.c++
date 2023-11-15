#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>>initializeboard(){
    return{{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
}
void displayboard(const vector<vector<char>>&board){
    cout << "  1 2 3\n";
    for(int i=0;i<3;++i){
        cout << i+1<<' ';
        for(int j=0;j<3;++j){
            cout<< board[i][j];
            if (j<2) cout<< '|';
        }
        cout<<'\n';
        if(i<2) cout<< "------\n";

    }
    cout<<'\n';
}
bool checkwin(const vector<vector<char>>&board,char player){
    for(int i=0;i<3;++i){
         if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
            }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
}
return false;
}
bool checkdraw(const vector<vector<char>>&board){
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}
int main(){
    char currentplayer='X';
    vector<vector<char>>board=initializeboard();
    bool gamewon=false;
    bool gamedraw=false;


 do{
    displayboard(board);
    cout << "Player " << currentplayer << ", enter your move (row and column): ";
    int row, col;
        cin >> row >> col;
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentplayer;
             gamewon = checkwin(board, currentplayer);
            gamedraw = checkdraw(board);
           currentplayer = switchPlayer(currentplayer);
        }else{
            cout<< "Invalid move.try again. \n";

        }
    

}
while(!gamewon && !gamedraw);
    displayboard(board);
    if(gamewon){
         cout << "Player " << switchPlayer(currentplayer) << " wins!\n";
}else{
    cout<<"It's draw!\n";
}
return 0;
}
    

