#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
unordered_map <lli,lli> parent;
unordered_map <lli,lli> Rank;
lli v,e;
void make(){
    for(lli i=1;i<=v;i++){
        parent[i]=i;
        Rank[i]=0;
    }
}
lli find(lli a){
    if(parent[a]!=a){
        parent[a]=find(parent[a]);
    }
    return parent[a];
}
void Union(lli a,lli b){
    if(find(a)==find(b)) return;
    lli i=find(a);
    lli j=find(b);
    if(Rank[i]>Rank[j]){
        parent[j]=i;
    }else{
        parent[i]=j;
    }
    if(Rank[i]==Rank[j]){
        Rank[j]++;
    }
}
int main() {
   cin >>v>>e;
   vector<pair<lli,pair<lli,lli>>>edges;
   for(lli i=0;i<e;i++){
       lli x,y,z;
       cin >> x>>y>>z;
       pair <lli,lli> ed;
       ed = make_pair(x,y);
       edges.push_back(make_pair(z,ed));
   }
   sort(edges.begin(),edges.end(), greater<>());
   make();
   lli prod=1;
   for(lli i=0;i<e;i++){
       lli a=edges[i].second.first;
       lli b=edges[i].second.second;
       lli w=edges[i].first;
       if(find(a)!=find(b)){
           Union(a,b);
           prod=prod*(w%mod);
           prod%=mod;
       }
   }
  cout << prod<<endl;
	return 0;
}
