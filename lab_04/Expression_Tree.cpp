#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

struct node
{
	char data;
	node* left = NULL;
	node* right = NULL;
};

string in2post(string in)
{
	stack<char> s;
	string post;
	for(int i = 0; i < in.length(); i++)
	{
		if(in[i] == '+' || in[i] == '-')
		{
			while(!s.empty())
			{
				post.push_back(s.top());
				s.pop();
			}
			s.push(in[i]);
			continue;
		}
		if(in[i] == '*' || in[i] == '/')
		{
            if(!s.empty())
			{
                while(!(s.top() == '+' || s.top() == '-'))
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
		if(in[i] == '^')
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

int toint(char a)
{
    int i = a-48;
    return i;
}

node *build(string post)
{
    stack<node *> s;
    node *temp = NULL, *root = NULL;
    for(int i = 0; i < post.size(); i++)
    {
        if(!(post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^'))
        {
            temp = new node;
            temp->data = post[i];
            s.push(temp);
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

int eval(node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return toint(root->data);
    int l = eval(root->left);
    int r = eval(root->right);
    if(root->data == '+')
        return l+r;
    if(root->data == '-')
        return l-r;
    if(root->data == '*')
        return l*r;
    if(root->data == '/')
        return l/r;
    return pow(l, r);
}

int main()
{
	string s;
	cin >> s;
	s = in2post(s);
    	node *root = build(s);
	cout << eval(root);
	return 0;
}
