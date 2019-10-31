#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector <vector<int> > v, int src , int* color)
{
	bool flag = true;
	for(int i = 0; i < v[src].size(); i++)
	{
		if(color[v[src][i]] == 0)
		{
			color[v[src][i]] = 0-color[src];
			flag = flag & isBipartite(v, i, color);
		}
		else
        {
            if((color[v[src][i]] == 1 && color[src] == 1) || (color[v[src][i]] == -1 && color[src] == -1))
            {
                return false;
            }
        }
	}
    return flag;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	vector <vector<int> > adj(n+m);
	int t = 0;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(c%2 == 1)
		{
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
		}
		else
		{
			adj[n+t].push_back(a-1);
			adj[n+t].push_back(b-1);
			adj[a-1].push_back(n+t);
			adj[b-1].push_back(n+t);
			t++;
		}
	}

	int color[n] = {0};
	bool is_bipartite = true;
	for(int i = 0; i < n+t; i++)
	{
		if(color[i] == 0)
		{
			color[i] = 1;
		    is_bipartite = isBipartite(adj, i, color);
		}
		if(is_bipartite == false)
            break;
	}
	if(is_bipartite == true)
        cout << "NO";
	else
        cout << "YES";
	return 0;
}
