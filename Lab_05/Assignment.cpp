#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <utility>
#include <string.h>

using namespace std;

struct node
{
	string data;
	node* left = NULL;
	node* right = NULL;
};

int call = 0;
vector< pair<string, int> > assign;

vector<string> in2post(vector<string> in)
{
	stack<string> s;
	vector<string> post;
	for(int i = 0; i < in.size(); i++)
	{
	    if(in[i] == "(")
        {
            s.push(in[i]);
            continue;
        }
        if(in[i] == ")")
        {
            while(s.top() != "(")
            {
                post.push_back(s.top());
                s.pop();
            }
            s.pop();
            continue;
        }
		if(in[i] == "+" || in[i] == "-")
		{
			while(!(s.empty() || s.top() == "("))
			{
				post.push_back(s.top());
				s.pop();
			}
			s.push(in[i]);
			continue;
		}
		if(in[i] == "*" || in[i] == "/")
		{
            if(!s.empty())
			{
                while(!(s.top() == "+" || s.top() == "-" || s.top() == "("))
                {
                    post.push_back(s.top());
                    s.pop();
                    if(s.empty())
                        break;
                }
            }
			s.push(in[i]);
			continue;
		}
		if(in[i] == "^")
		{
			s.push(in[i]);
			continue;
		}
		post.push_back(in[i]);
	}
	while(!s.empty())
	{
        post.push_back(s.top());
        s.pop();
	}
	return post;
}

node *build(vector<string> post)
{
    stack<node *> s;
    node *root = NULL;
    for(int i = 0; i < post.size(); i++)
    {
        if(!(post[i] == "+" || post[i] == "-" || post[i] == "*" || post[i] == "/" || post[i] == "^"))
        {
            root = new node;
            root->data = post[i];
            s.push(root);
            continue;
        }
        root = new node;
        root->data = post[i];
        root->right = s.top();
        s.pop();
        root->left = s.top();
        s.pop();
        s.push(root);
    }
    return root;
}

int toint(string a)
{
    if(a[0] >= '0' && a[0] <= '9')
    {
      	stringstream intstrm(a);
      	int i = 0;
      	intstrm >> i;
      	return i;
    }
    int temp = 0;
    for(int i = assign.size()-1; i >= 0; i--)
    {
        if(assign[i].first == a)
        {
            temp++;
            return assign[i].second;
        }
    }
    if(temp == 0)
    {
        cout << "Can't be evaluated" << endl;
        call = 1;
        return 0;
    }
}

int eval(node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return toint(root->data);
    int l = eval(root->left);
    int r = eval(root->right);
    if(root->data == "+")
        return l+r;
    if(root->data == "-")
        return l-r;
    if(root->data == "*")
        return l*r;
    if(root->data == "/")
        return l/r;
    return (int)(pow(l, r) + 0.5);
}

vector<string> strng2vect(string s)
{
    vector<string> in;
    for(int i = 0; i < s.size(); i++)
    {
        int refr;
        string temp = "";
        if((s[i] > 47 && s[i] < 58) || (s[i] == '-' && s[i-1] == '(') || (s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
        {
            refr = i;
            i++;
            while((s[i] > 47 && s[i] < 58) || (s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
                i++;
            for(int j = refr; j < i; j++)
                temp += s[j];
            in.push_back(temp);
            i--;
            continue;
        }
        if(s[i] == '+')
            in.push_back("+");
        if(s[i] == '-')
            in.push_back("-");
        if(s[i] == '*')
            in.push_back("*");
        if(s[i] == '/')
            in.push_back("/");
        if(s[i] == '^')
            in.push_back("^");
        if(s[i] == '(')
            in.push_back("(");
        if(s[i] == ')')
            in.push_back(")");
    }
    return in;
}

int main()
{
    int t,l;
    cin >> t;
    while(t--)
    {
        cin >> l;
        while(l--)
        {
            string s;
            cin >> s;
            int pos = 0, flag = 0;
            for(pos; pos < s.size(); pos++)
            {
                if(s[pos] == '=')
                {
                    flag++;
                    break;
                }
            }
            if(flag)
            {
                vector<string> in = strng2vect(s.substr(pos+1));
                vector<string> post = in2post(in);
                node *root = build(post);
                int x = eval(root);
                if(call == 0)
                    assign.push_back(make_pair(s.substr(0,pos), x));
            }
            else
            {
                vector<string> in = strng2vect(s);
                vector<string> post = in2post(in);
                node *root = build(post);
                int x = eval(root);
                if(call == 0)
                    cout << x << endl;
            }
            call = 0;
        }
        assign.clear();
    }
    return 0;
}
