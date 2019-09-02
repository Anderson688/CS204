#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int rchrg[n] = { };
    int t, max = -1;
    cin >> t;
    while(t--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int user_id, recharge;
            cin >> user_id;
            cin >> recharge;
            rchrg[user_id-1] += recharge;
            if(max == -1 || rchrg[user_id-1] > rchrg[max])
                max = user_id-1;
            continue;
        }
        if(type == 2)
        {
            if(max == -1)
                cout << "No data available." << endl;
            else
                cout << max+1 << endl;
        }
    }
    return 0;
}
