//Created by Jonathon Knorn on Jan 16 2013
//Edited and Commented by Seth Kitchen
//String Analysis-Simple two boolean problem. Keep Track if they names are increasing or if they are decreasing.
//If both booleans are false at the end, then print neither.

//Solves in 0.00 s on Kattis

#include <iostream> //External Library for getting inputs from standard in (keyboard) and writing to standard out (console window)
#include <string> //strings of characters are not implemented natively in c++ so import the external library to use them

using namespace std; //Keeps us from having to append std:: to iostream calls (these functions where put in a grouping with the name std

int main()
{
	int n; //Number of names
	cin >> n; //Read in the number of names that need to analyzed from standard input (keyboard).
	string last; //The last name said. Stored for comparison in the next step.
	cin >> last; //Read in the first name from standard input (keyboard). The comparisons will start in the second name read in, so the first name basically needs to be stored to compare against the second name when it is read in.
	bool inc = true; //with nothing to compare to the input is currently increasing
	bool dec = true; //with nothing to comparte to the input is currently decreasing
	for (int i = 1; i < n; ++i) //Loop n times. Basically loop until there is no more input.
	{
		string s; //The present name said. Stored for comparison against the last name said.
		cin >> s; //Read in the present name said from standard input (keyboard).
		if (last.compare(s) < 0) //Compare function compares ASCIIs to determine which string comes first. Less than zero means the present name said is larger than the last name said (increasing)
		{
			dec = false; //Since there was an increase, the input is definitely not decreasing.
		}
		else if (last.compare(s) > 0) //Greater than zero means the present name is smaller than the last name said (decreasing).
		{
			inc = false; //Since there was a decrease, the input is definitely not increasing.
		}
		last = s; //the last word said is now the present word said. Will need to compare it against the next word said.
		//Equal to 0 means they are equal in which case no change in whether the input is increasing or decreasing..basically just skip that input.
	}
	//We can do if-else if-else because input cannot be both increasing and decreasing.
	if (inc) //If increasing has not changed through the whole loop, the input must have increased the whole time.
	{
		cout << "INCREASING" << endl; //Write the answer to the standard output (console window).
	}
	else if (dec) // If decreasing has not changed through the whole loop, the input must have decreased the whole time.
	{
		cout << "DECREASING" << endl; //Write the answer to the standard output (console window).
	}
	else //If both inc and dec have changed through the loop, the input must have been inconsistent.
	{
		cout << "NEITHER" << endl; //Write the answer to the standard output (console window).
	}
	return 0; //No Errors.
}