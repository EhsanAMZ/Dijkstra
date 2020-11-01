#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("Input_File.txt");

int N;					// Number of nodes
int a, b, w;			// How to interpret input: node a to node b with distance w
int AM[100][100];		// Adjacency matrix
int Dis[100];			// Distance array
int Visited[100];		// Visited nodes, initially set to zero

int Dijkstra_Algorithm(int x)
{
	Visited[x] = 1;
	// Update connected nodes to x
	for (int i = 1; i <= N; i++)
	{
		if ((Visited[i] == 0) && (AM[x][i] != -1))
		{
			if ((Dis[x] + AM[x][i] < Dis[i]) || (Dis[i] == -1))
			{
				Dis[i] = Dis[x] + AM[x][i];
			}
		}
	}

	// Select new node
	int smaller = -1, sw = -1;
	for (int i = 0; i <= N; i++)
	{
		if ((Visited[i] == 0) && (Dis[i] >= 0) && ((sw > Dis[i]) || (sw == -1)))
		{
			sw = Dis[i];
			smaller = i;
		}
	}
	if (smaller != -1)
	{
		Dijkstra_Algorithm(smaller);
		return 0;
	}
	return 0;
}


int main()
{
	// Load data
	fin >> N;

	// Initializing adjacency matrix
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			AM[i][j] = -1;			// This is just initialization. However, in general, -1 represent no connection between two nodes. 
		}
	}

	// Initializing distance array
	for (int i = 0; i <= N; i++)
	{
		Dis[i] = -1;				// This is just initialization and -1 represents infinity distance.
	}

	// Initializing root
	Dis[1] = 0;

	while (!fin.eof())
	{
		fin >> a >> b >> w;
		AM[a][b] = w;
		AM[b][a] = w;
	}

	Dijkstra_Algorithm(1);			// Loading the Dijkstra Algorithm with node 1 as root.

	// Output 
	for (int i = 1; i <= N; i++)
	{
		cout << Dis[i] << endl;
	}

}