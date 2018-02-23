using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kattis
{
    //Created by Seth Kitchen on February 23 2018
    //Edited and Commented by Seth Kitchen
    //String Analysis-Simple two boolean problem. Keep Track if they names are increasing or if they are decreasing.
    //If both booleans are false at the end, then print neither.

    //Solves in 0.02 s on Kattis
    class LineThemUp
    {
        /*
        //Every C# Program starts in the Main
        static void Main(string[] args)
        {
            int n; //Number of names
            n=int.Parse(Console.ReadLine()); //Read in the number of names that need to analyzed from standard input (keyboard) and immediately convert it from string to integer.
            string last; //The last name said. Stored for comparison in the next step.
            last = Console.ReadLine(); //Read in the first name from standard input (keyboard). The comparisons will start in the second name read in, so the first name basically needs to be stored to compare against the second name when it is read in.
            bool inc = true; //with nothing to compare to the input is currently increasing
            bool dec = true; //with nothing to comparte to the input is currently decreasing
            for (int i = 1; i < n; ++i) //Loop n times. Basically loop until there is no more input.
            {
                string s; //The present name said. Stored for comparison against the last name said.
                s=Console.ReadLine(); //Read in the present name said from standard input (keyboard).
                if (string.Compare(last,s) < 0) //Compare function compares ASCIIs to determine which string comes first. Less than zero means the present name said is larger than the last name said (increasing)
                {
                    dec = false; //Since there was an increase, the input is definitely not decreasing.
                }
                else if (string.Compare(last, s) > 0) //Greater than zero means the present name is smaller than the last name said (decreasing).
                {
                    inc = false; //Since there was a decrease, the input is definitely not increasing.
                }
                last = s; //the last word said is now the present word said. Will need to compare it against the next word said.
                          //Equal to 0 means they are equal in which case no change in whether the input is increasing or decreasing..basically just skip that input.
            }
            //We can do if-else if-else because input cannot be both increasing and decreasing.
            if (inc) //If increasing has not changed through the whole loop, the input must have increased the whole time.
            {
                Console.WriteLine("INCREASING"); //Write the answer to the standard output (console window).
            }
            else if (dec) // If decreasing has not changed through the whole loop, the input must have decreased the whole time.
            {
                Console.WriteLine("DECREASING"); //Write the answer to the standard output (console window).
            }
            else //If both inc and dec have changed through the loop, the input must have been inconsistent.
            {
                Console.WriteLine("NEITHER"); //Write the answer to the standard output (console window).
            }
        }*/
    }
}
