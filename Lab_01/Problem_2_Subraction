#include <iostream>

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
        a=A.length();
        b=B.size();
        if(b>a)
        {
            swap(A,B);
            swap(a,b);
        }
        if(b==a)
        {
            for(int i=0;i<a;i++)
            {
                if(B[i]>A[i])
                {
                    swap(A,B);
                    swap(a,b);
                    break;
                }
            }
        }
        for(int i=0;i<b;i++)
        {
            if(A[a-i-1]<B[b-i-1])
            {
                A[a-i-1]+=10;
                A[a-i-2]-=1;
            }
            A[a-i-1]=A[a-i-1]-B[b-i-1]+48;
        }
        for(int i=a-b-1;i>=0;i--)
        {
            if(A[i]<'0')
            {
                A[i]+=10;
                A[i-1]-=1;
            }
        }
        cout<<A<<endl;
    }
    return 0;
}
