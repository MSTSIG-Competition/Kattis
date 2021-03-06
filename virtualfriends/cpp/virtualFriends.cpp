//Created by Seth Kitchen 2/24/18
//Edited and Commented by Seth Kitchen
//Data Structures: Use a Union Find to connect friends and print the network size

//Completed in 0.21 s on Kattis

#include <iostream> //External Library for getting inputs from standard in (keyboard) and writing to standard out (console window)
#include <vector> //External Library for using ArrayList (dynamically allocated array)--known as vector in cpp
#include <string> //strings of characters are not implemented natively in c++ so import the external library to use them
#include <map> //Dictionary data type--known as map in C++

using namespace std; //Keeps us from having to append std:: to iostream calls (these functions where put in a grouping with the name std

/* Data Structure that can tell you if nodes are connected, and easily connect more nodes together.
1 2 3 4 5 6 7 8 9
-------------------
|2|2|2|5|5|6|2|2|9|
-------------------

Here nodes 1-9 are represented in an array. The data structure sets one node in a connected set as the representative.
2, 5, 6, and 9 are representatives in this case.

Now if I want to know if 1 is connected to 7, I just look at their representative. If it is the same they are connected.
x[1]==x[7]==2 so they are connected.

Now if I want to connect 5 and 2, I just change x[5] to 2
1 2 3 4 5 6 7 8 9
-------------------
|2|2|2|5|2|6|2|2|9|
-------------------

But wait wouldn't 4 now be unconnected to 5?

No because instead we will only compare the representative if it matches the index. For example if you want to know if 4 and 5 are connected.
x[4]=5 and 4 != 5 so check 5's parent x[5]=2 and 5!=2 so check 2's parent x[2]=2 so 2 is the representative
x[5]=2 and 5 != 2 so check 2's parent x[2]=2 and 2==2 so 2 is the representative
since both representatives are the same they are connected.
*/
class UnionFind {
	int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets. IE the number of houses
	UnionFind(int N)
	{
		cnt = N;
		id = new int[N];
		sz = new int[N];
		for (int i = 0; i<N; i++)
			id[i] = i, sz[i] = 1;
	}

	~UnionFind()
	{
		delete[] id;
		delete[] sz;
	}

	// Return the representative of component corresponding to object p.
	int find(int p) {
		int root = p;
		while (root != id[root])
			root = id[root];
		while (p != root) {
			int newp = id[p];
			id[p] = root;
			p = newp;
		}
		return root;
	}

	// Replace sets containing x and y with their union.
	void merge(int x, int y) {
		int i = find(x);
		int j = find(y);
		if (i == j) return;

		// make smaller root point to larger one
		if (sz[i] < sz[j])
		{
			id[i] = j, sz[j] += sz[i];
		}
		else
		{
			id[j] = i, sz[i] += sz[j];
		}
		cnt--;
	}
	
	//How big is the network that x is in?
	int sizeOfNetwork(int x)
	{
		int i = find(x);
		return sz[i];
	}

	// Are objects x and y in the same set?
	bool connected(int x, int y)
	{
		return find(x) == find(y);
	}

	// Return the number of disjoint sets.
	int count()
	{
		return cnt;
	}
};


//Every C++ Program starts in the Main
int main()
{
	int testCases; // Number of times the program is run
	cin >> testCases; //Read in the number of times the program runs from standard input (keybaord)
	map<string, int> namesToNumber; //UnionFind uses numbers so "Fred" should be changed to 0 and "Barney" to 1 and so on
	int nameCounter = 0; //Need to keep track of how many names have been said so when we map the name it is not a repeated number
	for (int t = 0; t < testCases; t++)
	{
		int F; // Number of friendships formed
		cin >> F; // Read in the number of friendships from Standard Input (keyboard)
		UnionFind unionFind(F+1); //Create the connectiveness data structure with 1 extra element since the input data is 1 based instead of 0 based (0 won't be used).
		for (int i = 0; i < F; i++) //For each input
		{
			string nameOne, nameTwo; //These store the inputed names
			cin >> nameOne >> nameTwo; //Read names from the standard input (keyboard)
			if (namesToNumber.find(nameOne) == namesToNumber.end()) //If our dictionary has not seen the first name before
			{
				namesToNumber.insert(pair<string, int>(nameOne, nameCounter)); //Add the first name to the dictionary and give it the lastest value.
				nameCounter++; //Increment the latest value by one.
			}
			if (namesToNumber.find(nameTwo) == namesToNumber.end()) //If our dictionary has not seen the second name before
			{
				namesToNumber.insert(pair<string, int>(nameTwo, nameCounter)); //Add the second name to the dictionary and give it the latest value.
				nameCounter++; //Increment the latest value by one.
			}
			unionFind.merge(namesToNumber.at(nameOne), namesToNumber.at(nameTwo)); //Make them connected in the connectiveness data structure.
			cout << unionFind.sizeOfNetwork(namesToNumber.at(nameOne)) << endl; //Print the size of their network.
		}
	}
}
