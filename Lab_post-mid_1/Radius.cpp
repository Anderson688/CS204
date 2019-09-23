#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

void swap(long long *a, long long *b)
{
	long long temp = *a;
	*a = *b;
	*b = temp;
}

long long partition(long long arr[], long long l, long long r, long long x)
{
	long long i;
	for (i = l; i < r; i++)
		if (arr[i] == x)
            break;
	swap(&arr[i], &arr[r]);
	i = l;
	for(long long j = l; j <= r-1; j++)
	{
		if(arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

long long find_median(long long arr[], long long n)
{
	sort(arr, arr+n);
	return arr[n/2];
}

long long median(long long arr[], long long l, long long r, long long k)
{
		long long n = r-l+1;
		long long i, med[(n+4)/5];
		for (i=0; i<n/5; i++)
			med[i] = find_median(arr + l + i*5, 5);
		if (i*5 < n)
		{
			med[i] = find_median(arr + l + i*5, n%5);
			i++;
		}
		long long med_of_med = (i == 1)? med[i-1]: median(med, 0, i-1, i/2);
		long long position = partition(arr, l, r, med_of_med);
		if (position-l == k-1)
			return arr[position];
		if (position-l > k-1)
			return median(arr, l, position-1, k);
		return median(arr, position+1, r, k-position+l-1);
}

int main()
{
	long long t;
	cin >> t;
	while(t--)
    {
        long long points;
        cin >> points;
        long long x, y, dist[points];
        for(long long i = 0; i < points; i++)
        {
            cin >> x >> y;
            dist[i] = x*x + y*y;
        }
        cout << sqrt(median(dist, 0, points-1, (points+1)/2));
    }
	return 0;
}
