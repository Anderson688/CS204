#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

struct node
{
	string data;
	node* left = NULL;
	node* right = NULL;
};

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
        if(post[i] >= "0" && post[i] <= "9")
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
    stringstream intstrm(a);
    int i = 0;
    intstrm >> i;
    return i;
}

int eval(node* root)
{
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
    return pow(l, r);
}

vector<string> strng2vect(string s)
{
    vector<string> in;
    for(int i = 0; i < s.size(); i++)
    {
        int refr;
        string temp = "";
        if((s[i] > 47 && s[i] < 58) || (s[i] == '-' && s[i-1] == '('))
        {
            refr = i;
            i++;
            while(s[i] > 47 && s[i] < 58)
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
        string s;
        cin >> s;
        vector<string> in = strng2vect(s);
        vector<string> post = in2post(in);
        node *root = build(post);
        cout << eval(root);
    return 0;
}
