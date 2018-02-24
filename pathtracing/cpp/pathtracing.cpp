//Created by Seth Kitchen 2/23/18
//Edited and Commented by Seth Kitchen
//Graphs: Simple Simulate Directions and print the graph

//Completed in 0.00 s on Kattis

#include <iostream> //External Library for getting inputs from standard in (keyboard) and writing to standard out (console window)
#include <vector> //External Library for using ArrayList (dynamically allocated array)--known as vector in cpp
#include <string> //strings of characters are not implemented natively in c++ so import the external library to use them

using namespace std; //Keeps us from having to append std:: to iostream calls (these functions where put in a grouping with the name std

//Every C++ Program starts in the Main
int main()
{
	vector<string> moves; //To hold the input---each string is a move for Billy to walk
	string move; //Holds a single move for Billy to walk. Useful to hold the input before it is put in the moves vector
	//read in a single move from standard input (keyboard)
	while (cin >> move) //Problem description says input stops at the end of file character. loop putting input into the moves vector
	{	 
		moves.push_back(move); //and shove it into the vector-- adds it to the end of the list
	}

	int row = 500; //Billy's current position y coordinate- Start in the middle at 500 so we don't run out of room in the path array
	int col = 500;  //Billy's current position x coordinate- Start in the middle at 500 so we don't run out of room in the path array
	int maxRow = 500; //Need to keep track of the lowest Billy goes so we know where to draw the border.
	int minRow = 500; //Need to keep track of the highest Billy goes so we know where to draw the border.
	int maxCol = 500; //Need to keep track of the most right Billy goes so we know where to draw the border.
	int minCol = 500; //Need to keep track of the most left Billy goes so we know where to draw the border.

	char path[1001][1001]; //This holds the characters we will draw at the end. We will update characters in here as we traverse each move.
	path[row][col] = 'S'; //Mark Billy's starting location - 500, 500
	for (int i = 0; i < moves.size(); i++) //Loop for each move given in the input and stored in the moves vector
	{
		if (moves[i]=="up") //Read the instructions sequentially, if the instruction from the input was up
		{
			row--; //Billy's current position gets shifted up (1 row higher is a lower coordinate since 0,0 is the top left)
		}
		else if (moves[i] == "down") //Read the instructions sequentially, if the instruction for the input was down
		{
			row++; //Billy's current position gets shifted down (1 row lower is a higher coordinate since 0,0 is the top left)
		}
		else if (moves[i] == "left") //Read the instructions sequentially, if the instruction for the input was left
		{
			col--; //Billy's current position gets shifted left (1 column to the left is a lower coordinate since 0,0 is the top left)
		}
		else //Read the instructions sequentially, if the instruction is not up, down, or left, it MUST be right
		{
			col++; //Billy's current position gets shifted right (1 column to the right is a higher coordinate since 0,0 is the top left)
		}

		if (row > maxRow) //Check if Billy's current y position is lower than ever before
		{
			maxRow = row; //if so, mark his current y position as the lowest point.
		}
		else if (row < minRow) //Check if Billy's current y position is higher than ever before
		{
			minRow = row; //if so, mark his current y position as the highest point.
		}
		if (col > maxCol) //Check if Billy's current x position is more right than ever before
		{
			maxCol = col; //if so, mark his current x position as the most right point.
		}
		else if (col < minCol) //Check if Billy's current x position is more left than ever before
		{
			minCol = col; //if so, mark his current x position as the most left point.
		}

		if (path[row][col] != 'S') //If Billy's current position has not been marked as the start location
		{
			path[row][col] = '*'; //mark it as a trail spot
		}
	}
	path[row][col] = 'E'; //If there are no more moves, Billy's current location is the final location. Mark it as such.
	
	//Fill the rest of the array with spaces since he didn't move there.
	for (int i = minRow; i <= maxRow; i++) //We really only need to fill the spots between the highest and lowest spots Billy went
	{
		for (int j = minCol; j <= maxCol; j++) //We really only need to fill the spots between the most left and most right spots Billy went
		{
			if (path[i][j] != '*' && path[i][j] != 'S' && path[i][j]!='E') //If the spot was not the starting, ending, or trail spot
			{
				path[i][j] = ' '; //Mark it as an open spot
			}
		}
	}

	//Create the border around the walked area
	for (int i = minRow-1; i <= maxRow+1; i++) //We really only need to fill the spots between the highest and lowest spots Billy went
	{
		for (int j = minCol-1; j <= maxCol+1; j++) //We really only need to fill the spots between the most left and most right spots Billy went
		{
			if (path[i][j] != '*' && path[i][j] != 'S' && path[i][j] != 'E' && path[i][j]!=' ') //If the spot was not the starting, ending, trail spot, or open spot
			{
				path[i][j] = '#'; //Mark it as a border spot
			}
		}
	}

	//Output the final picture
	for (int i = minRow - 1; i <= maxRow + 1; i++)
	{
		for (int j = minCol - 1; j <= maxCol + 1; j++)
		{
			cout << path[i][j];
		}
		cout << endl;
	}
}