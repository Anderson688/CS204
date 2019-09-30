// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define llu long long int 
using namespace std; 

struct Point { 

	llu x, y; 

	bool operator<(Point p) 
	{ 
		return x < p.x || (x == p.x && y < p.y); 
	} 
}; 

// Cross product of two vectors OA and OB 
// returns positive for counter clockwise 
// turn and negative for clockwise turn 
llu cross_product(Point O, Point A, Point B) 
{ 
	return (A.x - O.x) * (B.y - O.y) 
		- (A.y - O.y) * (B.x - O.x); 
} 

// Returns a list of points on the convex hull 
// in counter-clockwise order 
vector<Point> convex_hull(vector<Point> A) 
{ 
	int n = A.size(), k = 0; 

	if (n <= 3) 
		return A; 

	vector<Point> ans(2 * n); 

	// Sort points lexicographically 
	sort(A.begin(), A.end()); 

	// Build lower hull 
	for (int i = 0; i < n; ++i) { 

		// If the point at K-1 position is not a part 
		// of hull as vector from ans[k-2] to ans[k-1] 
		// and ans[k-2] to A[i] has a clockwise turn 
		while (k >= 2 && cross_product(ans[k - 2], 
						ans[k - 1], A[i]) <= 0) 
			k--; 
		ans[k++] = A[i]; 
	} 

	// Build upper hull 
	for (size_t i = n - 1, t = k + 1; i > 0; --i) { 

		// If the point at K-1 position is not a part 
		// of hull as vector from ans[k-2] to ans[k-1] 
		// and ans[k-2] to A[i] has a clockwise turn 
		while (k >= t && cross_product(ans[k - 2], 
						ans[k - 1], A[i - 1]) <= 0) 
			k--; 
		ans[k++] = A[i - 1]; 
	} 

	// Resize the array to desired size 
	ans.resize(k - 1); 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int T;
	cin >> T;
	vector<Point> points; 
	int x, y;
	// Add points 
	for(int i = 0; i < T; i++)
	{
		cin >> x >> y;
		points.push_back({x, y});
	}

	// Find the convex hull 
	vector<Point> ans = convex_hull(points); 

	// Print the convex hull 
	cout << ans.size() << endl << ans[0].x << " " << ans[0].y << endl;
	for (int i = ans.size()-1; i > 0; i--) 
		cout << ans[i].x << " "
			<< ans[i].y << endl; 

	return 0; 
} 
