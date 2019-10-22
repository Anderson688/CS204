#include<bits/stdc++.h>
using namespace std;

int colm[10000000];
int k, m, n, c;

int getnum(int a, int b)
{
    return n*a + b;
}

vector<int> adjt[10000000];
bool visit[10000000];
int res, cl, M;

void dfs(int x)
{
    visit[x] = true;
    c++;
    for(auto y : adjt[x])
    {
        if(!visit[y])
            dfs(y);
    }
}

int main()
{
    cin >> n >> m >> c;
    vector<int> input;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int clr;
            cin >> clr;
            colm[getnum(i, j)] = clr;
            input.push_back(getnum(i, j));
        }
    }
    for(auto it : input)
    {
        int x = it/n, y = it%n;
        if(y+1 < n && colm[getnum(x, y+1)] == colm[getnum(x, y)])
        {
            adjt[getnum(x, y+1)].push_back(it);
            adjt[it].push_back(getnum(x, y+1));
        }
        if(x+1 < m && colm[getnum(x+1, y)] == colm[getnum(x, y)])
        {
            adjt[getnum(x+1, y)].push_back(it);
            adjt[it].push_back(getnum(x+1, y));
        }
    }
    for(auto it : input)
    {
        if(!visit[it])
        {
            c = 0;
            dfs(it);
            if(c > res)
            {
                res = c;
                M = colm[it];
            }
        }
    }
    cout << res << " " << M;
    return 0;
}
