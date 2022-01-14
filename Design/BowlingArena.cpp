#include <bits/stdc++.h>
using namespace std;

struct roundScore{
    char chance1;
    char chance2;
};

int totalPlayers;
int totalRounds = 5;

void calculateScore(vector<vector<roundScore>> &scoreBoard, vector<vector<int>> &individualScores, int round, int playerNum, int score1, int score2){
    
    cout << "Round: " << round << " Player: " << playerNum << endl;
    if(score1 == 10){
        scoreBoard[playerNum][round].chance1 = 'X';
        scoreBoard[playerNum][round].chance2 = ' ';
        individualScores[playerNum][round] = 20;
    }
    else if(score1+score2 == 10){
        scoreBoard[playerNum][round].chance1 = '0'+score1;
        scoreBoard[playerNum][round].chance2 = '/';
        individualScores[playerNum][round] = 15;
    }
    else{
        scoreBoard[playerNum][round].chance1 = '0'+score1;
        scoreBoard[playerNum][round].chance2 = '0'+score2;
        individualScores[playerNum][round] = (score1+score2);
    }

}

void playAnExtraRound(vector<vector<roundScore>> &scoreBoard, vector<vector<int>> &individualScores, int playerNum){
    cout << "Enter chance1 score for bonus round: ";
    int c1, c2;
    cin >> c1;
    cout << "Enter chance2 score for bonus round: ";
    cin >> c2;
    calculateScore(scoreBoard, individualScores, 5, playerNum, c1, c2);
        
}

void printScoreBoard(vector<vector<roundScore>> &scoreBoard, vector<vector<int>> &individualScores, int round){
    for(int i=0; i<totalPlayers; i++){
        cout << "P" << (i+1) << ": ";
        for(int j=0; j<=round; j++){
            cout << " { " << scoreBoard[i][j].chance1 << "," << scoreBoard[i][j].chance2 << " } ";
        }
        cout << " -> " ;
        int playerScore=0;
        for(int j=0; j<=round; j++){
            cout << individualScores[i][j] << "  ";
            playerScore+=individualScores[i][j];
        }
        cout << " -> "  << playerScore << endl;

    }
}

int findTheWinner(vector<vector<int>> &individualScores){
    int curMaxPlayerScore=INT_MIN;
    int winnerIndex=0;
    for(int i=0; i<totalPlayers; i++){
        int playerScore=0;
        for(int j=0; j<6; j++){
            playerScore+=individualScores[i][j];
        }
        cout << "Score for Player" << (i+1) << " : " << playerScore << endl;
        if(playerScore > curMaxPlayerScore){
            curMaxPlayerScore = playerScore;
            winnerIndex = i+1;
        }
    }
    return winnerIndex;
}

int main(){
    cout << "***** Welcome to bowling lobby.! *****" << endl;
    cout << "Enter number of players: " ;
    int playerCount;
    cin >> playerCount;
    while(1){
        if(playerCount <= 0){
            cout << "Entered invalid player count. Enter again: ";
            cin >> playerCount;
            cout << endl;
        }
        else{
            cout << "Your game begins.!" << endl;
            break;
        }
    }
    totalPlayers = playerCount;
    vector<vector<roundScore>> scoreBoard(totalPlayers, vector<roundScore>(6));
    vector<vector<int>> individualScores(totalPlayers, vector<int>(6, 0));

    for(int i=0; i<5; i++){
        cout << endl << endl;
        cout << "Round " << i+1 << endl;
        for(int j=0; j<totalPlayers; j++){
            int c1, c2;
            cout << "Enter chance 1 score for player" << j+1 << " : ";
            cin >> c1;
            if(c1 == 10){
                calculateScore(scoreBoard, individualScores, i, j, c1, 0);
                cout << "*********************************************************" << endl;
                cout << "Player " << j+1 << " Score chance1: " << c1 << " pins" << endl;
                cout << "*********************************************************" << endl;
                if(i==4){
                    playAnExtraRound(scoreBoard, individualScores, j);
                }
                continue;
                
            }
            cout << "Enter chance 2 score for player" << j+1 << " : ";
            cin >> c2;
            calculateScore(scoreBoard, individualScores, i, j, c1, c2);
            cout << "*********************************************************" << endl;
            cout << "Player " << j+1 << " Score chance1: " << c1 << " pins" << " chance2: " << c2 << endl;
            cout << "*********************************************************" << endl;
            if(c1+c2==10 && i==4)
               playAnExtraRound(scoreBoard, individualScores, j); 

        }

        printScoreBoard(scoreBoard, individualScores, i);
    }

    printScoreBoard(scoreBoard, individualScores, 5);
    int winner = findTheWinner(individualScores);
    cout << endl << endl;
    cout << "Hurray.!!!! Winner is: " << winner << endl;
    cout << "Thanks for playing.!" << endl;

}