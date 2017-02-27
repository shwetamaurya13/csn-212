#include<iostream>

using namespace std;

int Function(int a[], int n)
    {
    int DP[n]={1}, aux[n];
    aux[0]=0;
    for (int i=1; i<n; i++)
        {
        for (int j=i-1; j>=0; j--)
            {
            if (a[i]>a[j] && (aux[j]==-1 || aux[j]==0) && DP[i]<DP[j]+1)
                {
                DP[i]=DP[j]+1;
                aux[i]=1;
            }
            else if (a[i]<a[j] && (aux[j]==1 || aux[j]==0) && DP[i]<DP[j]+1)
                {
                DP[i]=DP[j]+1;
                aux[i]=-1;
            }
        }
    }
    int max=0;
    for(int i=0; i<n; i++)
        {
        if(DP[i]>max)
            max=DP[i];
    }
    return max;
}

int main(){
    /*--------FOR GENERAL TEST CASE------
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<Function(a,n); */
    int a[]={374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244};
    cout<<Function(a,50);
    return 0;
}
