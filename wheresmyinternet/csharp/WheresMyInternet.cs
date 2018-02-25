using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kattis
{
    //Created by Seth Kitchen 2/24/18
    //Edited and Commented by Seth Kitchen
    //Data Structures: Use a Union Find to Determine if Houses are Connected to House 1

    //Completed in 0.69 s on Kattis
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
 /*
    public class UnionFind
    {
        List<int> id = new List<int>();
        int cnt;
        List<int> sz=new List<int>();

	    // Create an empty union find data structure with N isolated sets. IE the number of houses
	    public UnionFind(int N)
        {
            cnt = N;
            for(int i=0; i<N; i++)
            {
                id.Add(-1);
                sz.Add(-1);
            }
            for (int i = 0; i < N; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }

        // Return the representative of component corresponding to object p.
        public int find(int p)
        {
            int root = p;
            while (root != id[root])
                root = id[root];
            while (p != root)
            {
                int newp = id[p];
                id[p] = root;
                p = newp;
            }
            return root;
        }

        // Replace sets containing x and y with their union.
        public void merge(int x, int y)
        {
            int i = find(x);
            int j = find(y);
            if (i == j) return;

            // make smaller root point to larger one
            if (sz[i] < sz[j])
            {
                id[i] = j;
                sz[j] += sz[i];
            }
            else
            {
                id[j] = i;
                sz[i] += sz[j];
            }
            cnt--;
        }

        // Are objects x and y in the same set?
        public bool connected(int x, int y)
        {
            return find(x) == find(y);
        }

        // Return the number of disjoint sets.
        public int count()
        {
            return cnt;
        }
    };

    class WheresMyInternet
    {
        //Every C# Program starts in the Main
        static void Main(string[] args)
        {
            int N; // Number of Houses in town
            int M; // Number of Network Cables Already Deployed
            //a and b are connected
            int a; // Temp variable for house number one
            int b; // Temp variable for house number two
            int tokenHouseWeKnowIsConnected = 1; // To be connected to the internet, houses need to be connected to this node. It will be compared to at the end.
            string[] split = Console.ReadLine().Split(' ');// Read in N and M from Standard Input (keyboard) spliting at the space between them
            N = int.Parse(split[0]); //convert N from string to int
            M = int.Parse(split[1]); //convert M from string to int
            UnionFind unionFind=new UnionFind(N+1); //Create the connectiveness data structure with 1 extra element since the input data is 1 based instead of 0 based (0 won't be used).
            for (int i = 0; i < M; i++) //For each input
            {
                split = Console.ReadLine().Split(' '); //Read them from the standard input (keyboard)
                a = int.Parse(split[0]); //convert a from string to int
                b = int.Parse(split[1]); //convert b from string to int
                unionFind.merge(a, b); //Make them connected in the connectiveness data structure.
            }
            bool areAllConnected = true; //Originally we assume all nodes are connected until we find one
            for (int i = 1; i <= N; i++) //Loop through all the houses
            {
                if (!unionFind.connected(tokenHouseWeKnowIsConnected, i)) //If a house is NOT connected to the internet
                {
                    Console.WriteLine(i); // Write it to the standard output (console)
                    areAllConnected = false; //And we know that at least one of the houses is not connected to the internet.
                }
            }
            if (areAllConnected) //If after looping through all the houses and the boolean has not changed
            {
                Console.WriteLine("Connected"); //This will be the only thing printed to the standard output (console).
            }
        }
    }*/
}
