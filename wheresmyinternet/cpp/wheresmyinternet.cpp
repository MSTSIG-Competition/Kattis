//Created by Seth Kitchen 2/23/18
//Edited and Commented by Seth Kitchen
//Data Structures: Use a Union Find to Determine if Houses are Connected to House 1

//Completed in 0.20 s on Kattis

#include <iostream> //External Library for getting inputs from standard in (keyboard) and writing to standard out (console window)
#include <vector> //External Library for using ArrayList (dynamically allocated array)--known as vector in cpp
#include <string> //strings of characters are not implemented natively in c++ so import the external library to use them

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
	int N; // Number of Houses in town
	int M; // Number of Network Cables Already Deployed
	//a and b are connected
	int a; // Temp variable for house number one
	int b; // Temp variable for house number two
	int tokenHouseWeKnowIsConnected=1; // To be connected to the internet, houses need to be connected to this node. It will be compared to at the end.
	cin >> N >> M; // Read in N and M from Standard Input (keyboard)
	UnionFind unionFind(N+1); //Create the connectiveness data structure with 1 extra element since the input data is 1 based instead of 0 based (0 won't be used).
	for (int i = 0; i < M; i++) //For each input
	{
		cin >> a >> b; //Read them from the standard input (keyboard)
		unionFind.merge(a, b); //Make them connected in the connectiveness data structure.
	}
	bool areAllConnected = true; //Originally we assume all nodes are connected until we find one
	for (int i = 1; i <= N; i++) //Loop through all the houses
	{
		if (!unionFind.connected(tokenHouseWeKnowIsConnected,i)) //If a house is NOT connected to the internet
		{
			cout << i << endl; // Write it to the standard output (console)
			areAllConnected = false; //And we know that at least one of the houses is not connected to the internet.
		}
	}
	if (areAllConnected) //If after looping through all the houses and the boolean has not changed
	{
		cout << "Connected" << endl; //This will be the only thing printed to the standard output (console).
	}
}