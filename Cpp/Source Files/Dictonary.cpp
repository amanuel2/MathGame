#include<vector>
#include "../Header Files/Dictonary.h"

#define PLAY_INCOS 011
#define END_MAIN  100
#define NO_STR 101
#define TOTAL 111
#define DUPE_FND 101
#define SMART_DET_ERR 000
#define UNIT_EXIST 110
#define PLAYER_IDENT_ERROR 001
#define WIN_STAGE 1111
#define ERROR_TIME 1101
#ifndef PI
    #define PI 3.14159265358979323846  
#endif    


Dictonary::Dictonary()
{
}

int myRand(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}


string Dictonary::randomArray(const string &opt)
{
    short ran = myRand(0,16);
    if(opt.compare("degree") == 0)
        return ( (arrayPossibledegrees[ran]) );
    else
        return ( (arrayPossibleRandians[ran]) );
}

string Dictonary::radOrDegRAND()
{
    return(radDeg[myRand(0,1)]);
}

string Dictonary::getPossibleArethemtic()
{
    return(possibleArethemtic[myRand(0,2)]);
}


double Dictonary::getComputedValue(string player,int ROUND, string player1Username, string player2Username,short TURN_PARAM)
{
    string unit = this -> radOrDegRAND();
    string arethemtic = this -> getPossibleArethemtic();
    string userAnswer;
    double userAnwserDoub, AIANWSERDOUB;
    bool DUPE_CHECK;
    string tryAgainQuestion;
    //Ex; pi/2
    //STATIC
    string val = randomArray(unit);
    if(val == "")
    {
        cout << "NO_STR ERROR : " << NO_STR << endl;
        cout << "REWRITTING VAL [< DEVELOPMENT USE >]" << endl;
        val = randomArray(unit);
    }
    
    //If Dupe, Returns True;
    DUPE_CHECK = this -> DUPE_CHECK_FUNC(val,unit);
    if(DUPE_CHECK == true)
    {
        cout << "DUPE_FND WARNING : " << DUPE_FND << endl;
        cout << "REWRITTING VAL [< DEVELOPMENT USE >]" << endl;
        val = randomArray(unit);
    }
    
    ASSIGNED_QUESTIONS[unit]=(val);
    timer.Start();
    //AVGtimer.Start();
    
    cout << "\nWhat is the " << arethemtic <<  " Of " <<val << " " << unit << endl;
    std::cin >> userAnswer;
    
    bool tryAgain = this -> smartDetection(userAnswer);
    
    if(tryAgain == false)
    {
         cout << "Want To Try Again? AI Sensed that you Wrote a incomplete Number. (y/n)" << endl;
         std::cin >> tryAgainQuestion;
         if(tryAgainQuestion.compare("y") == 0)
         {
            cout << "\nWhat is the " << arethemtic <<  " Of " <<val << " " << unit << endl; 
            std::cin >> userAnswer;
         }
         else if(tryAgainQuestion.compare("n") == 0)
                goto AICHECK;
         else
            cout << "Typed Incorrect Character. Therfore Continuing... " << endl;
    }
    else if(tryAgain == true){}
    else
    {
        cout << "SMART_DET_ERR .  ERR : " << SMART_DET_ERR << endl;
        cout << "CONTINUING....." << endl;
    }
    
    //VALUE
    AICHECK:if(unit == "radian")
    {
        if(arethemtic.compare("sin") == 0)
        {
            //cout << "The sin of " << val << " " << unit << " Is " << UC.getRadianValue(val,"sin") << endl;
            if(userAnswer.compare(UC.getRadianValue(val,"sin")) == 0)
            {
                 this -> checkUserAnwser("c", ROUND , player);
            }
            else
            {
                 this -> checkUserAnwser("i", ROUND , player);
            }
        }
        
        else if(arethemtic.compare("cos") == 0)
        {
            //cout << "The cos of " << val << " " << unit << " Is " << UC.getRadianValue(val,"cos") << endl;
            if(userAnswer.compare(UC.getRadianValue(val,"cos")) == 0)
            {
                this -> checkUserAnwser("c", ROUND , player);
            }
            else
            {
               this -> checkUserAnwser("i", ROUND , player);
            }
        }
        else
        {
             //cout << "The tan of " << val << " " << unit << " Is " << UC.getRadianValue(val,"tan") << endl;
             if(userAnswer.compare(UC.getRadianValue(val,"tan")) == 0)
             {
                  this -> checkUserAnwser("c", ROUND , player);
             }
             else
             {
                 this -> checkUserAnwser("i", ROUND , player);
             }
        }
       
    }
    
    else if(unit == "degree")
    {
        if(arethemtic.compare("sin") == 0)
        {
            //cout << "The sin of " << val << " " << unit << " Is " << UC.getDegreeValue(val,"sin") << endl;
            if(userAnswer.compare(UC.getDegreeValue(val,"sin")) == 0)
            {
               this -> checkUserAnwser("c", ROUND , player);
            }
            else
            {
                this -> checkUserAnwser("i", ROUND , player);
            }
        }
        
        else if(arethemtic.compare("cos") == 0)
        {
             //cout << "The cos of " << val << " " << unit << " Is " << UC.getDegreeValue(val,"cos") << endl;
            if(userAnswer.compare(UC.getDegreeValue(val,"cos")) == 0)
            {
                this -> checkUserAnwser("c", ROUND , player);
            }
            else
            {
                this -> checkUserAnwser("i", ROUND , player);
            }
        }
        else
        {
             //cout << "The tan of " << val<< " "  << unit << " Is " << UC.getDegreeValue(val,"tan") << endl;
             if(userAnswer.compare(UC.getDegreeValue(val,"tan")) == 0)
             {
                this -> checkUserAnwser("c", ROUND , player);
             }
             else
             {
                this -> checkUserAnwser("i", ROUND , player);
             }
        }
    }
    
    else
    {
        cout << "Internal Error. UNIT_EXIST. ERROR " << UNIT_EXIST << endl;
        exit(1);
    }

    timer.Stop();
    if(TURN_PARAM == 1)
    {
         player1TimingSeconds.push_back(timer.getTimeSeconds());
         player1TimingMilliSeconds.push_back(timer.getTimeMilliSeconds());
         
        //  AVGplayer1TimingSeconds.push_back(timer.getTimeSecondsAvg());
        //  AVGplayer1TimingMilliSeconds.push_back(timer.getTimeMilliSecondsAvg());
    }
    else if(TURN_PARAM == 2)
    {
         player2TimingSeconds.push_back(timer.getTimeSeconds());
         player2TimingMilliSeconds.push_back(timer.getTimeMilliSeconds());
         
        //  AVGplayer2TimingSeconds.push_back(timer.getTimeSecondsAvg());
        //  AVGplayer2TimingMilliSeconds.push_back(timer.getTimeMilliSecondsAvg());
    }
    else
    {
        cout << "ERROR_TIME : " << ERROR_TIME << endl;
        exit(1);
    }
   
    cout << "You Took : " << timer.getTimeSeconds() << " Seconds " << endl;
    if(ROUND >= 3)
    {
        this -> Ending();
    }
}


double Dictonary::Ending()
{
    switch(COMPLETE_END)
    {
        case -1:
            COMPLETE_END = 0;
            break;
        case 0:
            COMPLETE_END = 1;
            break;
        case 1:
            cout << "~~~~~~~ PLAYER 1 STATS ~~~~~~~" << endl;
            cout << "Correct : " << player1Correct.size() << endl;
            cout << "Incorrect : " << player1Incorrect.size() << endl;
            cout << "Average Correct Percentage : " << ((double)player1Correct.size()) / TOTAL << " % " << endl;
            cout << "Total Time Taken(Seconds) : " << this -> totalTime(1,"sec") << "sec" <<endl;
            cout << "Total Time Taken(MilliSeconds) : " << this -> totalTime(1,"millisec") <<  "millisec" <<endl;
            //cout << "AVERAGE TIME TAKEN(SECONDS) : " << this -> avgTime(1,"sec") << "sec" << endl;
            
            cout << "~~~~~~~ PLAYER 2 STATS ~~~~~~~" << endl;
            cout << "Correct : " << player2Correct.size() << endl;
            cout << "Incorrect : " << player2Incorrect.size() << endl;
            cout << "Average Correct Percentage " << ((double)player2Correct.size()) / TOTAL << " % " <<  endl;
            cout << "Total Time Taken : " << this -> totalTime(2, "sec") << "sec" <<endl;
            cout << "Total Time Taken(MilliSeconds) : " << this -> totalTime(2,"millisec") << "millisec" <<endl;
            
            cout << "\n\n ~~~~~~~~~~~~~~~~~~~ FINAL RESULTS ~~~~~~~~~~~~~~~~~~~" << endl;
            cout << STATS("WIN",player1Correct.size(),player1Incorrect.size(),
                        player2Correct.size(),player2Incorrect.size(),-1) << endl;;
            break;
        default:
            cout << "END_MAIN ERROR " << END_MAIN << endl;
    }

}

template <typename T>
std::string to_string(T &value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}

// double Dictonary::avgTime(const int& PLAYER_NUM, const std::string& opt)
// {
//     double avgTime = 0.0;
//     if(PLAYER_NUM == 1)
//     {
//         if(opt == "sec")
//             {
//                  for(string_int_it it=AVGplayer1TimingSeconds.begin(); it!=AVGplayer1TimingSeconds.end(); it++)
//                  {
//                      avgTime = avgTime + (static_cast<double>(*it));
//                  }
//             }
//     }
//     return avgTime;
// }

int Dictonary::totalTime(const int& PLAYER_NUM, const std::string& opt)
{
     int totalReturn = 0;
         if(PLAYER_NUM == 1)
         {
             if(opt == "sec")
             {
                 for(string_int_it it=player1TimingSeconds.begin(); it!=player1TimingSeconds.end(); it++)
                 {
                     totalReturn = totalReturn + (*it);
                 }
             }
             else
             {
                 for(string_int_it it=player1TimingMilliSeconds.begin(); it!=player1TimingMilliSeconds.end(); it++)
                 {
                     totalReturn = totalReturn + (*it);
                 }
             }
            
         }
         else if(PLAYER_NUM == 2)
         {
             if(opt == "sec")
             {
                 for(string_int_it it=player2TimingSeconds.begin(); it!=player2TimingSeconds.end(); it++)
                 {
                     totalReturn = totalReturn + (*it);
                 }
             }
             else
             {
                 for(string_int_it it=player2TimingMilliSeconds.begin(); it!=player2TimingMilliSeconds.end(); it++)
                 {
                     totalReturn = totalReturn + (*it);
                 }
             }
         }
         else
             cout << "PLAYER_IDENT_ERROR<AVERAGE> : " << PLAYER_IDENT_ERROR << endl;
            
         return (totalReturn);    
}

string Dictonary::STATS(const string &opt, int player1SIZE_CORRECT, int PLAYER1SIZE_INCORECT
                        , int PLAYER2SIZE_CORRECT , int PLAYER2SIZE_INCORRECT, int player)
{
    bool win;
    float avgPERC2,avgPERC;
    string returner;
    if(opt == "WIN")
    {
        win = true;
        if(player1SIZE_CORRECT > PLAYER2SIZE_CORRECT)
            returner = "~~~~~~~~~~~~PLAYER 1 HAS WON!!!~~~~~~~~~~~~";
        else if(PLAYER2SIZE_CORRECT > player1SIZE_CORRECT)
            returner = "~~~~~~~~~~~~PLAYER 2 HAS WON!!!~~~~~~~~~~~~";
        else if(PLAYER2SIZE_CORRECT == player1SIZE_CORRECT)
            returner = "~~~~~~~~~~~~IT IS A TIE!!!~~~~~~~~~~~~";
        else
        {
            cout << "WIN_STAGE ERROR " << WIN_STAGE << endl;
            exit(1);
        }
    }
    else if (opt == "AVG")
     {
         switch(player)
         {
             case 1:
                 avgPERC2 = (player1SIZE_CORRECT/(TOTAL));
                 returner =  (player1SIZE_CORRECT) + "/" + TOTAL;
                 cout << (player1SIZE_CORRECT) + "/"  << endl;
                 break;
             case 2:
                 avgPERC = (PLAYER2SIZE_CORRECT/(TOTAL))*100;
                 returner= (PLAYER2SIZE_CORRECT) + "/" + TOTAL;
                 cout << returner << endl;
                 break;
        }
     }

    return returner;
    
}
bool contains_number(std::string &c)
{
    return (
        c.find('0') != std::string::npos ||
        c.find('1') != std::string::npos ||
        c.find('2') != std::string::npos ||
        c.find('3') != std::string::npos ||
        c.find('4') != std::string::npos ||
        c.find('5') != std::string::npos ||
        c.find('6') != std::string::npos ||
        c.find('7') != std::string::npos ||
        c.find('8') != std::string::npos ||
        c.find('9') != std::string::npos
    );
}


bool Dictonary::smartDetection(string USER_ANWSER)
{
    bool returner;
    bool CONTAINS_NUMBER = contains_number(USER_ANWSER);
    if(CONTAINS_NUMBER == false)
    {
        returner = false;
    }
    //     //1 , -1 BUG FIX
    else if(USER_ANWSER == "1" || USER_ANWSER == "-1")
        returner = true;
    //Number Bug Fix
    else if(CONTAINS_NUMBER == true)
        returner = true;
    else if(USER_ANWSER.find("und") != std::string::npos)
        returner = true;
    else if(USER_ANWSER.find("sqrt") == std::string::npos)
    {
        if(CONTAINS_NUMBER == false)
        {
            //Contains a Number
            returner = false;
        }
    }
    else if(USER_ANWSER.find("s") != std::string::npos)
        returner = false;
    else if(USER_ANWSER.find("q") != std::string::npos)
        returner = false;
    else if(USER_ANWSER.find("r") != std::string::npos)
        returner = false;
    else if(USER_ANWSER.find("t") != std::string::npos)
        returner = false;    
    else if(USER_ANWSER.find("sq") != std::string::npos)
        returner = false;    
    else if(USER_ANWSER.find("sqr") != std::string::npos)
        returner = false;
    else if(USER_ANWSER.find("p") != std::string::npos)
        returner = false;    
    else if(USER_ANWSER.find("ie") != std::string::npos)
        returner = false;    
    else if(USER_ANWSER.find("pe") != std::string::npos)
        returner = false;    
    else if(USER_ANWSER.find("pie") != std::string::npos)
        returner = false;    

        
    else
    {
        returner = true;
    }
    
    return returner;
}

//If Dupe, Returns True;
bool Dictonary::DUPE_CHECK_FUNC(string val_dupe_check, string unit_dupe_check)
{
    bool isDupeNest = false;
    //If Dupe, Return True;
    //  ASSIGNED_QUESTIONS[unit]=(val);
    for(string_map_it it=ASSIGNED_QUESTIONS.begin(); it!=ASSIGNED_QUESTIONS.end();it++)
    {
        if((it->first).compare(unit_dupe_check)==0)
        {
            if((it->second).compare(val_dupe_check)==0)
            {
                isDupeNest = true;
            }
        }
    }
    return isDupeNest;
}

double Dictonary::checkUserAnwser(const string &opt, int ROUND, string player)
{
    if(opt.compare("c") == 0)
    {
         if(player.compare("Player One") == 0)
                 {
                     player1Correct.push_back(ROUND);
                 }
                 else if(player.compare("Player Two") == 0)
                 {
                     player2Correct.push_back(ROUND);
                 }
                 else
                 {
                     cout << "Internal Error. PLAYER_INCONSIST. ERROR " << PLAY_INCOS << endl;
                     exit(1);
                 }
    }
    
    else if(opt.compare("i") == 0)
    {
        if(player.compare("Player One") == 0)
        {
              player1Incorrect.push_back(ROUND);
           }
            else if(player.compare("Player Two") == 0)
            {
                player2Incorrect.push_back(ROUND);
            }
            else
            {
                cout << "Internal Error. PLAYER_INCONSIST. ERROR " << PLAY_INCOS << endl;
                exit(1);
            }
    }
}


double Dictonary::conversionPItoREAL(string piNONREAL)
{
    short PIREAL;
    //Conversion "pi/2" to PI/2 MATH FORM
    //"11pi/2" to 11PI/2
    //"3pi/2" to 3PI/2
    if(piNONREAL.find("p"))
    {
        
    }
}





//degreeToRadians
double Dictonary::d2r(double d)
{
    return(d/180) * ((double) PI);
}

Dictonary::~Dictonary()
{
}
