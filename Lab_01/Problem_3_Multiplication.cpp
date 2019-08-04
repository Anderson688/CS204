#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(T;T>0;T--)
    {
        string A,B;
        cin>>A>>B;
        int a=A.size();
        int b=B.size();
        if(b>a)
        {
            swap(A,B);
            swap(a,b);
        }
        vector<char> ans;
        ans.push_back('0');
        for(int i=1;i<=a;i++)
            ans.push_back((A[i-1]-48)*(B[b-1]-48));
        for(int i=a;i>=1;i--)
        {
            if(ans.at(i)>9)
            {
                ans.at(i-1)+=(ans.at(i)/10);
                ans.at(i)%=10;
            }
        }
        for(int i=1;i<a+1;i++)
            ans.at(i)+=48;
        if(b>1)
        {
            vector<char> temp;
            for(int i=b-2;i>=0;i--)
            {
                if(i<b-2)
                    temp.clear();
                temp.push_back('0');
                for(int j=1;j<=a;j++)
                    temp.push_back((A[j-1]-48)*(B[i]-48));
                for(int j=a;j>=1;j--)
                {
                    if(temp.at(j)>9)
                    {
                        temp.at(j-1)+=(temp.at(j)/10);
                        temp.at(j)%=10;
                    }
                }
                for(int j=a+1;j<a+b-i;j++)
                    temp.push_back('0');
                for(int j=1;j<a+1;j++)
                    temp.at(j)+=48;
                unsigned int s1,s2;
                s1=ans.size();
                s2=temp.size();
                if(s2>s1)
                {
                    ans.swap(temp);
                    swap(s1,s2);
                }
                for(int j=0;j<s2;j++)
                    ans.at(s1-1-j)+=(temp.at(s2-1-j)-48);
                for(int j=s1-1;j>0;j--)
                {
                    if(ans[j]>57)
                    {
                        int c=ans[j]-48;
                        ans[j-1]+=c/10;
                        ans[j]=(c%10)+48;
                    }
                }
                if(ans[0]>57)
                {
                    ans[0]=((ans[0]-48)%10)+48;
                    ans.insert(ans.begin(),'1');
                }
            }
        }
        if(ans.at(0)!='0')
            cout<<ans.at(0);
        for(unsigned int i=1;i<ans.size();i++)
            cout<<ans.at(i);
        cout<<endl;
    }
    return 0;
}
