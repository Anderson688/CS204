#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(T;T>0;T--)
    {
        string A,B;
        cin>>A>>B;
        int a,b;
        a=A.size();
        b=B.size();
        if(b>a)
        {
            swap(A,B);
            swap(a,b);
        }
        if(a>=b)
        {
            for(int i=0;i<b;i++)
                A[a-1-i]+=B[b-1-i]-48;
            for(int i=a-1;i>0;i--)
            {
                if(A[i]>57)
                {
                    int c=A[i]-48;
                    A[i-1]+=c/10;
                    A[i]=(c%10)+48;
                }
            }
            if(A[0]>57)
            {
                A[0]=((A[0]-48)%10)+48;
                cout<<"1"<<A<<endl;
            }
            else cout<<A<<endl;
        }
    }
    return 0;
}
