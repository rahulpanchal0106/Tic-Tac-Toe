#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class game{
    public:
        void update(vector<char>& board){
            init(board);
        }

        int move_decoder(int move){

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

            cout<<map[move]<<"______"<<endl<<endl;
            
            if(map.find(move)!=map.end()) return map[move];

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
        '*','*','*',
        '*','*','*',
        '*','*','*'
    };

    game game;
    player1 player1;
    player2 player2;

    cout<<endl;
    game.init(board);

    for(int i=0; i<9; i++){
        if((i+1)%2!=0){

            //p1's turn
            cout<<"Player 1's turn: ";
            cin>>p1_move;
            cout<<endl;

            p1_move=game.move_decoder(p1_move);
            if(p1_move==-1) {
                cout<<"Invalid Spot!"<<endl;
                i--;
            }

            player1.update(board,p1_move);

        }else{

            //p2's turn
            cout<<"Player 2's turn: ";
            cin>>p2_move;
            cout<<endl;

            p2_move=game.move_decoder(p2_move);
            if(p2_move==-1) {
                cout<<"Invalid Spot!"<<endl;
                i--;
            }

            player2.update(board,p2_move);
        }

        game.update(board);
        
    }

    return 0;
}