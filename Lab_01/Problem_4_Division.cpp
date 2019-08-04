#include <iostream>
#include <algorithm>

using namespace std;

string mi(string p,string q)
{
    char a='0';
    long long int x=0,y;
    if(p.size()<q.size())
    {
        swap(p,q);
        cout<<"-";
    }
    if(p.size()==q.size())
    {
        for(int i=0;i<p.size();i++)
        {
            if(p[i]>q[i])
                break;
            if(p[i]<q[i])
            {
                swap(p,q);
                cout<<"-";
                break;
            }
        }
    }
    while(q.size()<p.size())
        q.insert(0,"0",1);
    string r="";
    for(long long int i=p.size()-1;i>=0;i--)
    {
        y=(int)(p[i]-'0')-(int)(q[i]-'0')+x;
        x=0;
        if(y<0)
        {
            x=-1;
            y+=10;
        }
        r.push_back((char)(y+(int)a));
    }
    reverse (r.begin(),r.end());
    r.erase(0,r.find_first_not_of('0'));
    if(r=="")
        r="0";
    return r;
}

int comp(string p,string q)
{
    long long int i;
    if(p.size()>q.size())
        return 1;
    else
    {
        if(p.size()<q.size())
            return 0;
        else
        {
            for(i=0;i<q.size();i++)
            {
                if(p[i]>q[i])
                    return 1;
                if(q[i]>p[i])
                    return 0;
            }
            return 2;
        }
    }
}

int main()
{
    long long int T;
    cin>>T;
    for(long long int y=0;y<T;++y)
    {
        string A,B;
        cin>>A>>B;
        string Q="";
        long long int a=A.length();
        long long int b=B.length();
        if(comp(A,B)==0)
        {
            cout<<0<<" "<<A<<endl;
            return 0;
        }
        if(comp(A,B)==2)
        {
            cout<<1<<" "<<0<<endl;
            return 0;
        }
        string x="";
        long long int j=b-1,k=0;
        for(int i=0;i<b;i++)
            x.push_back(A[i]);
        while(j<a)
        {
            k=0;
            while(comp(x,B)!=0)
            {
                x=mi(x,B);
                k++;
            }
            j++;
            if(j<a)
                x.push_back(A[j]);
            x.erase(0,x.find_first_not_of('0'));
            if(x=="")
                x="0";
            Q.push_back(k+'0');
        }
        Q.erase(0,Q.find_first_not_of('0'));
        cout<<Q<<endl<<x<<endl;
    }
    return 0;
}
