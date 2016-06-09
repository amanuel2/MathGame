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
        //Loop 3 Rounds, since there are 3 rounds.
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
    
    
    //Player 1 Username Asking
    cout << "Username of Player1 : ";
    std::cin >> player1UserName;
     //Player 2 Username Asking
    cout << "\b \n Username of Player 2 : ";
    std::cin >> player2UsernName;
    //Begin!
    cout << "\n Alright! " << player1UserName << " Go Ahead and Click Enter to begin the game! " << endl;
    cin.get();
    cin.get();
    cout << "--------------------------------------BEGGINING------------------------------------------" << endl;
}

void MainGame::PlayRound(int i)
{
    //String for containing Username
    string turnStr;
    //String to pass in param
    string callerTurnStr;
    //This is the turn of the person that i will pass in to function
    short TURN_PARAM;
    if(_turn==TURN::PLAYER1)
    {
        //If the turn is PLAYER1
            //Set Values Accordingly
            //turnstr is a 'strict conditon' variable
            turnStr = "Player One";
            callerTurnStr = player1UserName;
            TURN_PARAM = 1;
    }
        
    else
    {
        //If the turn is PLAYER2
            //Set Values Accordingly
            //turnstr is a 'strict conditon' variable
        turnStr = "Player Two";
        callerTurnStr = player2UsernName;
        TURN_PARAM = 2;
    }
        
        
        
    //Telling The Player Username, its thier turn    
    cout <<  "\n\n" << " This is your turn!" << callerTurnStr << endl;
    
    //This is where all the What is sin of that, and timer, and valueStoring Happens. Explained in Dictonary.cpp
    dict.getComputedValue(turnStr,i,player1UserName,player2UsernName,TURN_PARAM);
    
    //Set Turn Accordingly
     if(_turn == TURN::PLAYER1)
         _turn = TURN::PLAYER2;
     else
         _turn = TURN::PLAYER1;
         
    //This was the one line code for above... but no work, 
    //for some reason the Compiler, thinks Turn::PLAYER1 is a
    //bool
   // _turn = TURN::PLAYER1 ? TURN::PLAYER2 : TURN::PLAYER1;
}

MainGame::~MainGame()
{
}
