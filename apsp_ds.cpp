#include<bits/stdc++.h>
using namespace std;
#define INF 99999

int main()
{
   int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(i==j)
        arr[i][i]=0;
        else arr[i][j]=10e7;
    }
    int m;
    cin>>m;
    int x,y,w;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        arr[x-1][y-1]=w;
        //arr[y-1][x-1]=w;
    }
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
        }
    }


    for(long long int i=0;i<n;i++)
    {for(long long int j=0;j<n;j++)
    {
     if(arr[i][j]==10e7)
            cout<<"INF"<<' ';
            else
            cout<<arr[i][j]<<' ';
    }cout<<"\n";}
    return 0;
}
