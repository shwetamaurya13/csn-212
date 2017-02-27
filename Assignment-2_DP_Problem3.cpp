
#include <iostream>


using namespace std;
int Function(int a[], int n)
    {
    int longestsub[n];
    for (int i=0; i<n; i++)
        {
        int DP[n];
        for(int i=0; i<n;i++)
            DP[i]=1;
        for(int j=i+1; j<n; j++)
            {
            for(int k=j-1; k>=i;k--)
                {
                if(a[j]>a[k] && DP[j]<DP[k]+1)
                    DP[j]=DP[k]+1;
            }
        }
        for(int j=0;j<i;j++)
            {
            for(int k=j-1; k>=0; k--)
                if(a[j]>a[k] && DP[j]<DP[k]+1)
                    DP[j]=DP[k]+1;
            for(int k=n-1;k>=i;k--)
                if(a[j]>a[k] && DP[j]<DP[k]+1)
                    DP[j]=DP[k]+1;
        }
        int max=0;
        for(int k=0; k<n;k++)
            {
            if(DP[k]>max)
                max=DP[k];
        }
        longestsub[i]=max;
    }
    int max=0;
    for(int i=0; i<n; i++)
        {
        if(longestsub[i]>max)
            max=longestsub[i];
    }
    return max;
}

int main(){
    /*------FOR MULTIPLE TEST CASES----
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j=0; j<n; j++)
            cin>>a[j];
        cout<<Function(a,n)<<endl;
    } */
    int a[]={4,8,6,1,5,2};
   cout<<Function(a,6);
    return 0;
}
