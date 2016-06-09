using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrigKnowledgeApp
{
    class Program
    {
        public static string[] arrTrigTypes = { "Sin","Cos","Tangent"};
        static Random _r = new Random();
        static Random _r2 = new Random();

        public static string[] arrayPossibleangles = { "0","pi/6", "pi/4", "pi/3", "pi/2", "2pi/3", "3pi/4", "5pi/6","pi", "7pi/6", "5pi/4", "4pi/3", "3pi/2", "5pi/3", "7pi/4","11pi/6", "2pi"};
        public static string[] arrayPossibleSinValues = { "0", "1/2", "sqrt(2)/2", "sqrt(3)/2", "1", "sqrt(3)/2", "sqrt(2)/2", "1/2", "0", "-1/2", "-sqrt(2)/2", "-sqrt(3)/2", "-1", "-sqrt(3)/2", "-sqrt(2)/2", "-1/2", "0" };
        public static string[] arrayPossibleCosinValues = { "1", "sqrt(3)/2", "sqrt(2)/2", "1/2", "0", "-1/2", "-sqrt(2)/2", "-sqrt(3)/2", "-1", "-sqrt(3)/2", "-sqrt(2)/2", "-1/2", "0", "1/2", "sqrt(2)/2", "sqrt(3)/2", "1" };
        public static string[] arrayPossibleTangentValues = { "0", "sqrt(3)/3", "1", "sqrt(3)", "und", "-sqrt(3)", "-1", "-sqrt(3)/3", "0", "sqrt(3)/3", "1", "sqrt(3", "und", "-sqrt(3)", "-1", "-sqrt(3)/3", "0" };

        public static List<String> player1Questions;
        public static List<String> player2Questions;

        public static List<String> player1Answers;
        public static List<String> player2Answers;

        public static List<int> player1TrigType;
        public static List<int> player2TrigType;


        public static List<int> player1Angle;
        public static List<int> player2Angle;

        public static int sinNumbers = 17;
        public static int cosNumbers = 17;
        public static int tanNumbers = 17;



        public static int count;

         public static int tType ;
         public static int tType2;
         public static string val;

        static void Main(string[] args)
        {
            player1Angle = new List<int>();
            player2Angle = new List<int>();
            player1Questions = new List<string>();
            player2Questions = new List<string>();
            player1Answers = new List<string>();
            player2Answers = new List<string>();
            player2TrigType = new List<int>();
            player1TrigType = new List<int>();
            Console.WriteLine("----------------------------Instructions ------------------------------------ ");
            Console.WriteLine(" ");
            Console.WriteLine("This game is called Trigonometric competency skill challenge for unit circle. ");
            Console.WriteLine(" ");
            Console.WriteLine(" ");
            Console.Write("Two players will compete with each others.");
            Console.WriteLine("There will be unlimted rounds and  ");
            Console.WriteLine("ends by pressing the enter key twice. There will be three Rounds  per layer.");
            Console.WriteLine("When it is a players turn, you will be asked to answer to the questions.");
            Console.WriteLine(" ");
            Console.WriteLine(" ");
            Console.WriteLine("The application Will Calculate your Average Time and score at end of the game  ");
            Console.WriteLine("and a player with hige=her total Points is a winner of the game.");
            Console.WriteLine(" ");
            Console.WriteLine(" ");
            Console.WriteLine("If you want to enter values in PI, enter PI at the end of the entry and  ");
            Console.WriteLine("if you want to use square roots, just type 'sqrt' Also use 'und' as a ");
            Console.WriteLine("symbol for undefined.' ");
            Console.WriteLine("");
            Console.WriteLine("-------------------------------------------------------------------------------- ");
            Console.WriteLine("");
            count = 0;
            while (true)
            {
                count += 1;
                bool isterminated;
                bool isterminated2;
                isterminated = RunPlayers(1);
                if (isterminated)
                { break; }
                isterminated2 = RunPlayers(2);
                if (isterminated2)
                { break; }
            }
            int result1=0;
            int result2=0;
            Console.WriteLine("----------------------------Questions and Answers ------------------------- ");
            for (int i = 0; i < count - 1; i++)
            {
                Console.WriteLine("Player 1 Question " + (i + 1).ToString() + ": " +  player1Questions[i] + " and answer is " + player1Answers[i] );
                switch (player1TrigType[i])
                {
                    case 0:
                        Console.WriteLine("                     The answer is: " + arrayPossibleSinValues[player1Angle[i]]);
                        if (player1Answers[i] == arrayPossibleSinValues[player1Angle[i]])
                        {
                            result1+=1;
                        }
                        break;
                    case 1:
                        Console.WriteLine("                     The answer is: " + arrayPossibleCosinValues[player1Angle[i]]);
                        if (player1Answers[i] == arrayPossibleCosinValues[player1Angle[i]])
                        {
                            result1+=1;
                        }
                        break;
                    case 2:
                        Console.WriteLine("                     The answer is: " + arrayPossibleTangentValues[player1Angle[i]]);
                        if (player1Answers[i] == arrayPossibleTangentValues[player1Angle[i]])
                        {
                            result1+=1;
                        }
                        break;
                }
            }


            for (int i = 0; i < count - 1; i++)
            {
                Console.WriteLine("Player 2 Question " + (i + 1).ToString() + ": " + player2Questions[i] + " and answer is " + player2Answers[i]);
                switch (player2TrigType[i])
                {
                    case 0:
                        Console.WriteLine("                     The answer is: " + arrayPossibleSinValues[player2Angle[i]]);
                        if (player2Answers[i] == arrayPossibleSinValues[player2Angle[i]])
                        {
                            result2 += 1;
                        }
                        break;
                    case 1:
                        Console.WriteLine("                     The answer is: " + arrayPossibleCosinValues[player2Angle[i]]);
                        if (player2Answers[i] == arrayPossibleCosinValues[player2Angle[i]])
                        {
                            result2 += 1;
                        }
                        break;
                    case 2:
                        Console.WriteLine("                      The answer is: " + arrayPossibleTangentValues[player2Angle[i]]);
                        if (player2Answers[i] == arrayPossibleTangentValues[player2Angle[i]])
                        {
                            result2 += 1;
                        }
                        break;
                }
            }
            
            Console.WriteLine("--------------------------------------------------------------------- ");
            if (result1 > result2) 
            { 
                    Console.WriteLine("Player 1 is a winner" + result1.ToString() + " vs " + result2.ToString());
            }
            else

                if (result1 < result2)
                { 
                    Console.WriteLine("Player 2 is a winner" + result2.ToString() + " vs " + result1.ToString());
                }
                else
                {
                    Console.WriteLine("player 1 and 2 are in tie.");
                }

            Console.WriteLine(result1.ToString());
            Console.WriteLine(result2.ToString());
            Console.ReadLine();

        }
        public static bool RunPlayers(int i)
        {
            tType = _r.Next(0, 2);
            tType2 = _r2.Next(0, 16);
            string question = arrTrigTypes[tType] + " of " + arrayPossibleangles[tType2];
            Console.WriteLine("Player " + i.ToString() + ": Please enter the " + question);

            val = Console.ReadLine();


            if (val == "")
            { return true; }
            if (i == 1)
            {
                player1Angle.Add(tType2);
                player1TrigType.Add(tType);
                player1Questions.Add(question);
                player1Answers.Add(val);

            }
            else
            {
                player2Angle.Add(tType2);
                player2TrigType.Add(tType);
                player2Questions.Add(question);
                player2Answers.Add(val);
            }
            return false;
        }

    }
}
