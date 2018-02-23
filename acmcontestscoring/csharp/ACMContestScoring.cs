using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Created and Comments/Edits by Seth Kitchen
//Really a String Analysis problem that uses a map/dictionary data structure
//Simply store each problem in a dictionary until it is solved keeping a count of the attempts
//when it is solved, multiply the attempts by 20 and add it to the points with the current time.
//Keep a seperate counter for the total problems solved.

//Solves in 0.02s on Kattis
namespace Kattis
{
    class ACMContestScoring
    {
        //Every C# Program starts in the Main
        static void Main(string[] args)
        {
            int t; //Keeps track of the time that each attempt was made.
            int points = 0; //Sum of times when a problem was solved plus 20*attempts for each problem.
            int solved = 0; //Total number of problems solved
            string name, result; //Problem Name (ie "A" or "B" or "C") and whether it was "right" or "wrong"
            Dictionary<string, int> m = new Dictionary<string, int>(); //Dictionary where key is the name of the problem and the int is the number of attempts*20

            //Execute until a -1 is received from the input
            while (true)
            {
                string line = Console.ReadLine(); //Read in the first line from the stand input (keyboard)
                string[] split = line.Split(' '); //Split the input line at the spaces. Store the parts in an array. 
                t = int.Parse(split[0]); //The first part of the array is the time but needs to be converted from string to int
                
                if (t == -1) // when the data from the keyboard is -1
                {
                    break; //Exit the execution loop.
                }

                name = split[1]; //The second part of the array is the problem name (ie "A")
                result = split[2]; //The third part of the array is the problem result (ie "right" or "wrong")

                if (result == "wrong") // If the attempt was unsuccessful update the dictionary for that problem
                {
                    if (m.Keys.ToList().Contains(name))//if there were penalty deductions before
                    {
                        m[name] += 20; // ACM scoring says 20 points per unsuccessful attempt should be added.
                    }
                    else //otherwise this will be the first penalty deduction
                    {
                        m[name] = 20;
                    }
                }
                else //Otherwise increment the total number of problems solved counter and add the attempts value and time to the total points
                {
                    ++solved; //solved=solved+1 , but this is the fastest notation to do the operation
                    points += t; //add the time to the total number of points
                    if (m.Keys.ToList().Contains(name))//if there were penalty deductions
                    {
                        points += m[name]; //add the penalty deduction for unsuccessful attempts
                    }
                }
            }
            Console.WriteLine(solved + " " + points); //Output the number of solved problems and the score to standard output (console window)
        }
    }
}
