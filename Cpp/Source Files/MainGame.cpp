#include<vector>
#include "../Header Files/MainGame.h"

#define NUM_ROUNDS 5
#define PI 3.15
  

MainGame::MainGame()
{
    _turn = TURN::PLAYER1;
}

void MainGame::run()
{
    //Main Game Loop
    do
    {
        //Instructions
        DisplayInstructions();
        //NUM-ROUNDS
        for (int i(0); i<=NUM_ROUNDS; i++) 
              this -> PlayRound(i);
        
    } while (false); 
    
}

bool PlayAgain()
{
    //Play Again?
    return false; 
}

//In MainGame.h

void MainGame::DisplayInstructions()
{
    //Instructions
    cout << "----------------------------Instructions ------------------------------------ " << endl;
    cout << "\n This game is called Trigonometric competency skill challenge for unit circle. \n\n" << endl;
    cout << "Two players will compete with each others."<<endl;
    cout << "There will be unlimted rounds and  "<<endl;  
    cout << "ends by pressing the enter key twice. There will be three Rounds  per player." << endl;
    cout << "When it is a players turn, you will be asked to answer to the questions.\n\n" << endl;
    cout << "The application Will Calculate your Average Time and score at end of the game  " << endl;
    cout << "and a player with hige=her total Points is a winner of the game.\n\n" << endl;
    cout << "If you want to enter values in PI, enter 'pi' at the end of the entry and  " << endl;
    cout << "if you want to use square root, just type 'sqrt' Also use 'und' as a " << endl;
    cout << "symbol for 'undefined'. \n" << endl;
     cout << "\n\t\tGood Luck! May the odds be ever in your favor!\n\n\n" << endl;
    cout << "-------------------------------------------------------------------------------- \n" << endl;
    
    
    // cout << "\t\tThis Game is called TRIG FIGHT. Two Users Compete." << endl;
    // cout << "\t\tThere will be Three Rounds Per Player. Each will come up, as I(The AI) Tell you to." << endl;
    // cout << "\t\tThere you will be asked the Sin/Cos/Tan of Degree/Radian of the Unit Circle" << endl;
    // cout << "\tWe Will Calculate your Average Time At End, and Total Points. Total Points will win." << endl;
    // cout << "\t\tNOTE : If you want to do PI to represent radian values" << endl;
    // cout << "\t\tJust type in pi(someNumber). sqrt(someNumber). For undefined just type und" << endl;
    // cout << "\n\t\t\tGood Luck! May the odds be ever in your favor!\n\n\n" << endl;
    cout << "Username of Player1 : ";
    std::cin >> player1UserName;
    cout << "\b \n Username of Player 2 : ";
    std::cin >> player2UsernName;
    cout << "\n Alright! " << player1UserName << " Go Ahead and Click Enter to begin the game! " << endl;
    cin.get();
    cin.get();
    cout << "--------------------------------------BEGGINING------------------------------------------" << endl;
}

void MainGame::PlayRound(int i)
{
    string turnStr;
    string callerTurnStr;
    short TURN_PARAM;
    if(_turn==TURN::PLAYER1)
    {
        turnStr = "Player One";
        callerTurnStr = player1UserName;
        TURN_PARAM = 1;
    }
        
    else
    {
        turnStr = "Player Two";
        callerTurnStr = player2UsernName;
        TURN_PARAM = 2;
    }
        
        
        
        
    cout <<  "\n\n" << " This is your turn!" << callerTurnStr << endl;
    dict.getComputedValue(turnStr,i,player1UserName,player2UsernName,TURN_PARAM);
    
    if(_turn == TURN::PLAYER1)
        _turn = TURN::PLAYER2;
    else
        _turn = TURN::PLAYER1;
    //_turn = TURN::PLAYER1 ? TURN::PLAYER2 : TURN::PLAYER1;
}

MainGame::~MainGame()
{
}
