#include <bits/stdc++.h>

using namespace std;

int findset(long long arr[], long long x)
{
	if(x != arr[x])
		arr[x] = findset(arr, arr[x]);
	return arr[x];
}

void union_set(long long arr[], long long ranks[], int a, int b)
{
	int x = findset(arr,a);
	int y = findset(arr,b);
	if(x != y)
    {
		if(ranks[x] < ranks[y])
                swap(x, y);
		arr[y] = x;
		if(ranks[x] == ranks[y])
			ranks[x]++;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector <pair<long long, pair<long long, long long > > > v;
	int x, y;
	long long k;
	for(int i = 0; i < m; i++)
    {
		cin >> x >> y >> k;
		v.push_back({k, {x, y}});
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	long long arr[n+1], ranks[n+1];
	long long cost = 1;
	for(int i = 0; i < n+1; i++)
    {
		arr[i] = i;
		ranks[i] = 0;
	}
	for(int i = 0; i < v.size(); i++)
    {
		int rx = findset(arr, v[i].second.first);
		int ry = findset(arr, v[i].second.second);
		if(rx != ry)
        {
			cost = (cost*v[i].first)%1000000007;
			union_set(arr, ranks, v[i].second.first, v[i].second.second);
		}
	}
	cout << cost << endl;
	return 0;
}
