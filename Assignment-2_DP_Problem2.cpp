#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long DP[100][100];
long long Function (int height, int width, string bad[50], int n)
    {
    if(height==0 && width==0)    
    {
      DP[height][width]=1;
    return 1;
    }
        char str1[20],str2[20],str3[20],str4[20];
        int n1=sprintf(str1,"%d %d %d %d",width,height,width-1,height);
        int n2=sprintf(str2, "%d %d %d %d",width-1,height, width,height);
        int n3= sprintf(str3, "%d %d %d %d",width,height,width,height-1);
        int n4=sprintf(str4, "%d %d %d %d",width,height-1, width,height);
    int i=0, k1=0,k2=0;
    while (i<n)
       {
        if(bad[i]==str1 || bad[i]==str2)
        k1=1;
        if(bad[i]==str3 || bad[i]==str4)
        k2=1;
           i++;
    }
        if(DP[height-1][width]==0 && height-1>=0 && width>=0)
        DP[height-1][width]=Function(height-1, width, bad,n);
        if(DP[height][width-1]==0 && height>=0 && width-1>=0)
        DP[height][width-1]=Function(height,width-1, bad,n);
    
    if(k1==0 && width-1>=0)
        DP[height][width]=DP[height][width] + DP[height][width-1];
    if(k2==0 && height>0)
        DP[height][width]= DP[height][width]+DP[height-1][width]; 
        return DP[height][width];
}

int main(){
    for(int i=0; i<100; i++)
        {
        for(int j=0; j<100;j++)
            DP[i][j]=0;
    }
   /* int height,width,n;
    string bad[50];
    cin>>height>>width;
    //How many strings do you want to enter?
    cin>>n;
    for(int i=0;i<n;i++)
        {
        getline(cin,bad[i]);
    }
    cout<<Function(height,width,bad,n); */
    string bad[]={"0 0 1 0", "1 2 2 2", "1 1 2 1"};
    int height=2, width=2;
    cout<<Function(height,width,bad,sizeof(bad)/sizeof(bad[0]));
    return 0;
}
