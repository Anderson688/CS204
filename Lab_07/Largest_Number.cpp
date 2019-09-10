#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool comparator(string s_a, string s_b)
{
    string s1 = s_a, s2 = s_b;
    s1.append(s2);
    s2.append(s_a);
    return s1.compare(s2) >= 0;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        string s;
        vector<string> p;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            p.push_back(s);
        }
        sort(p.begin(), p.end(), comparator);
        for(auto t:p)
            cout << t;
        cout << endl;
    }
    return 0;
}
