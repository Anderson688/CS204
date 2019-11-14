#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    string str;
    Node* nxt;
};
Node hTable[555557];

int hIndex(string str)
{
    int index=0,n=str.length();
    for(int i=0;i<n;i++)
    {
        index+=(((str[i]-'a')*(i+1)*(n-i))/2);
        index=index%555557;
    }
    return index;
}

bool chk(string str)
{
    string strTemp=str;
    reverse(strTemp.begin(),strTemp.end());
    if(str==strTemp)return false;
    else
    {
        int n=hIndex(str);
        Node* tmp=hTable[n].nxt;
        while(tmp)
        {
            if(strTemp==tmp->str)
            {
                return true;
            }
            tmp=tmp->nxt;
        }
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->str=str;
        newNode->nxt=hTable[n].nxt;
        hTable[n].nxt=newNode;
        return false;
    }
    
}

void insertStr(string str)
{
    int n=hIndex(str);
}

int main()
{
    for(int i=0;i<555557;i++)hTable[i].nxt=NULL;
    int n,i=0;
    cin>>n;
    while(i<n)
    {
        string str;
        cin>>str;
        if(chk(str))
        {
            cout<<"YES"<<endl;
            break;
        }
        i++;
    }
    if(n==i)cout<<"NO"<<endl;
    return 0;
}
