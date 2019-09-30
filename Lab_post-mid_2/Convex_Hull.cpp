#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point
{
	long long int x, y;
	bool operator <(Point p)
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};

long long int cross_product(Point O, Point A, Point B)
{
	return (A.x-O.x)*(B.y-O.y) - (A.y-O.y)*(B.x-O.x);
}

vector<Point> convex_hull(vector<Point> A)
{
	int n = A.size(), k = 0;
	if(n <= 3)
		return A;
	vector<Point> ans(2*n);
    	sort(A.begin(), A.end());
	for(int i = 0; i < n; ++i)
    	{
		while(k >= 2 && cross_product(ans[k-2], ans[k-1], A[i]) <= 0)
			k--;
		ans[k++] = A[i];
	}
	for(size_t i = n-1, t = k+1; i > 0; --i)
	{
        	while(k >= t && cross_product(ans[k-2], ans[k-1], A[i-1]) <= 0)
			k--;
		ans[k++] = A[i-1];
	}
	ans.resize(k-1);
	return ans;
}

int main()
{
	int T;
	cin >> T;
	vector<Point> points;
	int x, y;
	for(int i = 0; i < T; i++)
	{
		cin >> x >> y;
		points.push_back({x, y});
	}
	vector<Point> ans = convex_hull(points);
	if(ans.size() < 3)
    	{
        	cout << 0;
        	return 0;
    	}
    	cout << ans.size() << endl << ans[0].x << " " << ans[0].y << endl;
	for (int i = ans.size()-1; i > 0; i--)
		cout << ans[i].x << " " << ans[i].y << endl;
	return 0;
}
