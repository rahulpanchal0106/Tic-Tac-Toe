#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#define empty '.'

using namespace std;

class game{
    public:
        void update(vector<char>& board){
            init(board);
        }

        int move_decoder(int move, vector<char> &board){

            unordered_map <int,int> map={
                {00,0},
                {01,1},
                {02,2},
                {10,3},
                {11,4},
                {12,5},
                {20,6},
                {21,7},
                {22,8}
            };
            
            auto it = map.find(move);
            if(it != map.end() && board[map[move]]==empty) return map[move];

            return -1;
        }

        void init(vector<char> board){
            cout<<"  ";
            for(int i=0; i<3; i++){
                cout<<i<<" ";
            }
            cout<<endl;
            cout<<0<<" ";
            for(int i=0; i<3; i++){
                cout<<board[i]<<" ";
            }
            cout<<endl;
            cout<<1<<" ";
            for(int i=3; i<6; i++){
                cout<<board[i]<<" ";
            }
            cout<<endl;
            cout<<2<<" ";
            for(int i=6; i<9; i++){
                cout<<board[i]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }

        bool check_win(char player,vector<char> &board){
            int winning_combos[8][3]={
                {0,3,6},
                {1,4,7},
                {2,5,8},
                {0,1,2},
                {3,4,5},
                {6,7,8},
                {0,4,8},
                {2,4,6}
            };

            for(int i=0; i<9; i++){
                int a=winning_combos[i][0];
                int b=winning_combos[i][1];
                int c=winning_combos[i][2];

                if(board[a]==player && board[b]==player && board[c]==player){
                    return true;
                }
            }
            return false;
        }

        
};

class player1{
    public:
        vector<char> update(vector<char> &board, int move){
            board[move]='O';
            return board;
        }
};

class player2{
    public:
        vector<char> update(vector<char> &board, int move){
            board[move]='X';
            return board;
        }
};

int main(){
    int total_moves=9;
    int used_moves=0;
    int p1_move, p2_move;

    vector<char> board = {
        '.','.','.',
        '.','.','.',
        '.','.','.'
    };

    game game;
    player1 player1;
    player2 player2;

    cout<<endl;
    system("cls");
    game.init(board);

    for(int i=0; i<9; i++){
        if((i+1)%2!=0){

            //p1's turn
            cout<<"Player 1's turn (O): ";
            cin>>p1_move;
            cout<<endl;

            p1_move=game.move_decoder(p1_move,board);

            system("cls");
            
            if(p1_move==-1) {
                cout<<"Invalid Spot!"<<endl<<endl;
                i--;
            }
            player1.update(board,p1_move);
            
            if(game.check_win('O',board)){
                cout<<"Player 1 Wins!!"<<endl<<endl;
                game.update(board);
                return 0;
            }


        }else{

            //p2's turn
            cout<<"Player 2's turn (X): ";
            cin>>p2_move;
            cout<<endl;

            p2_move=game.move_decoder(p2_move,board);
            system("cls");
            if(p2_move==-1) {
                cout<<"Invalid Spot!"<<endl<<endl;
                i--;
            }
            player2.update(board,p2_move);

            if(game.check_win('X',board)){
                cout<<"Player 2 Wins!!"<<endl<<endl;
                game.update(board);
                return 0;
            }
            
        }

        game.update(board);
    }

    cout<<"It's a draw -_-"<<endl;
    return 0;
}