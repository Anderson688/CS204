#include<bits/stdc++.h>

using namespace std;

bool isBipartite(vector<int> adj[], int v, vector<bool>& visited, vector<int>& color)
{
	visited[v] = true;
	for(int u : adj[v])
	{
		if(!visited[u])
		{
			visited[u] = true;
			color[u] = 1 - color[v];
			if(!isBipartite(adj, u, visited, color))
				return false;	
		}
		else
		{
			if(color[u] == color[v])
				return false;
		}
	}
	return true;	
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	vector<bool> visited(n+1);
	vector<int> color(n+1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(visited[i+1] == false)	
		{
			if(!isBipartite(adj, i+1, visited, color))
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
