using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kattis
{
    //Created by Seth Kitchen on February 23 2018
    //Edited and Commented by Seth Kitchen
    //Math-Simple time difference problem. Take the difference between the given times and normalize them.

    //Completed in 0.02 s on Kattis
    class Natrij
    {
        //Every C# Program starts in the Main
        static void Main(string[] args)
        {
            int h1, m1, s1, h2, m2, s2; //First hour, first minute, first second, second hour, second minute, second second
            string[] split = Console.ReadLine().Split(':');//Grab the first line of input split at the colons so we just get numbers
            h1 = int.Parse(split[0]);
            m1 = int.Parse(split[1]);
            s1 = int.Parse(split[2]);
            split = Console.ReadLine().Split(':'); //Grab the second line of input split at colon so we just get numbers
            h2 = int.Parse(split[0]);
            m2 = int.Parse(split[1]);
            s2 = int.Parse(split[2]); 

            int s = s2 - s1; //Get the difference in seconds
            int m = m2 - m1; //Get the difference in minutes
            int h = h2 - h1; //Get the difference in hours

            //Normalize the hours minutes and seconds
            if (s < 0)  //Obviously we can't have negative seconds so we need to pull from the minutes 
            {
                s += 60; // for every minute we have can have 60 seconds instead
                m -= 1; //if we pull from minutes we need to update it's value
            }
            if (m < 0) //Obviously we can't have negative minutes so we need to pull from the the hours
            {
                m += 60; //for every hour we can have 60 minutes instead
                h -= 1; //if we pull from hours we need to update it's value
            }
            if (h < 0) //Obviously we can't have negative hours so we need to go back a day
            {
                h += 24; //Going back a day is the same as adding 24 hours
            }

            if (h + m + s == 0) //00:00:00 should be printed 24:00:00
            {
                h += 24;
            }

            //Write the answer to the standard output (console window).
            Console.WriteLine((h < 10 ? "0" : "") + h + ":" + (m < 10 ? "0" : "") + m + ":" + (s < 10 ? "0" : "") + s);
        }
    }
}
