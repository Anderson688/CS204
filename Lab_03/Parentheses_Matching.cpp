#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x = 1;
        stack<char> S;
        string s;
    	cin >> s;
    	int len = s.length();
    	if(len%2 == 1)
    	{
        	cout << "NO" << endl;
        	continue;
    	}
    	for(int i = 0; i < len; i++)
    	{
        	if(s[i] == '{' || s[i] == '<' || s[i] == '(' || s[i] == '[')
        	{
            	S.push(s[i]);
            	continue;
        	}
        	if(s[i] == '}')
            {
                if(S.empty())
                {
                    x--;
                    break;
                }
                else
                {
                    if(S.top() == '{')
                    {
                        S.pop();
                        continue;
                    }
                    else
                    {
                        x--;
                        break;
                    }
                }
            }
        	if(s[i] == '>')
            {
                if(S.empty())
                {
                    x--;
                    break;
                }
                else
                {
                    if(S.top() == '<')
                    {
                        S.pop();
                        continue;
                    }
                    else
                    {
                        x--;
                        break;
                    }
                }
            }
            if(s[i] == ')')
            {
                if(S.empty())
                {
                    x--;
                    break;
                }
                else
                {
                    if(S.top() == '(')
                    {
                        S.pop();
                        continue;
                    }
                    else
                    {
                        x--;
                        break;
                    }
                }
            }
            if(s[i] == ']')
            {
                if(S.empty())
                {
                    x--;
                    break;
                }
                else
                {
                    if(S.top() == '[')
                    {
                        S.pop();
                        continue;
                    }
                    else
                    {
                        x--;
                        break;
                    }
                }
            }
        	if(s[i] == '|')
        	{
            	if(S.empty())
                	S.push(s[i]);
            	else
            	{
                	if(S.top() == '|')
                    	S.pop();
                	else
                    	S.push(s[i]);
            	}
            	continue;
        	}
    	}
    	if(S.empty() && x != 0)
        	cout << "YES";
    	else
        	cout << "NO";
        cout << endl;
	}
	return 0;
}
