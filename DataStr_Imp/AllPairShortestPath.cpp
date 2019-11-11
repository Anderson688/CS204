// C++ Program for implementation of All Pair Shortest Path problem using Floyd Warshall's Algorithm

#include <bits/stdc++.h>

using namespace std;

#define N 4
#define INF 99999

int dist[N][N];

void floydWarshall(int graph[][N])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dist[i][j] = graph[i][j];
	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main()
{
	int graph[N][N] = { {  0,   5, INF,  10},
						{INF,   0,   3, INF},
						{INF, INF,   0,   1},
						{INF, INF, INF,   0}
					  };
	floydWarshall(graph);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(dist[i][j] == INF)
				cout << "INF" << "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
	return 0;
}
