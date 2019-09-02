#include <iostream>

using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;

  int amount[n]={ };
  int count =-1;
  while(q--){
      int t=0;
     cin>>t;
     if(t==1){
         int u,a;
         cin>>u>>a;
         amount[u-1]+=a;
         if(count==-1||amount[u-1]>amount[count]){
             count=u-1;
         }
     }
   
     if(t==2){
         if(count==-1){
             cout<<"No data avialable."<<endl;
             continue;
         }
         cout<<count+1<<endl;
     }
  }

  
    return 0;
}
