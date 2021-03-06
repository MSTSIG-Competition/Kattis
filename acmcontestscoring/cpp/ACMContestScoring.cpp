//Created By Jonathon Knorn
//Comments/Edits by Seth Kitchen
//Really a String Analysis problem that uses a map/dictionary data structure
//Simply store each problem in a dictionary until it is solved keeping a count of the attempts
//when it is solved, multiply the attempts by 20 and add it to the points with the current time.
//Keep a seperate counter for the total problems solved.

//Solves in 0.00s on Kattis

#include <iostream> //External Library for getting inputs from standard in (keyboard) and writing to standard out (console window)
#include <map> //Dictionary data type--known as map in C++
#include <string> //strings of characters are not implemented natively in c++ so import the external library to use them

using namespace std; //Keeps us from having to append std:: to iostream calls (these functions where put in a grouping with the name std

//Every C++ Program starts in the Main
int main()
{
	int t; //Keeps track of the time that each attempt was made.
	int points = 0; //Sum of times when a problem was solved plus 20*attempts for each problem.
	int solved = 0; //Total number of problems solved
	string name, result; //Problem Name (ie "A" or "B" or "C") and whether it was "right" or "wrong"
	map<string, int> m; //Dictionary where key is the name of the problem and the int is the number of attempts*20

	//Execute until a -1 is received from the input
	while (true)
	{
		cin >> t; //Read in the time from standard input (keyboard).
		if (t == -1) // when the data from the keyboard is -1
		{
			break; //Exit the execution loop.
		}
		cin >> name >> result; //Read in the problem name (ie "A") and whether it was "right" or "wrong" from standard input (keyboard).
		if (result.compare("wrong") == 0) // If the attempt was unsuccessful update the dictionary for that problem
		{
			m[name] += 20; // ACM scoring says 20 points per unsuccessful attempt should be added.
		}
		else //Otherwise increment the total number of problems solved counter and add the attempts value and time to the total points
		{
			++solved; //solved=solved+1 , but this is the fastest notation to do the operation
			points += t; //add the time to the total number of points
			points += m[name]; //add the penalty deduction for unsuccessful attempts
		}
	}
	cout << solved << " " << points << endl; //Output the number of solved problems and the score to standard output (console window)
    return 0;
}

