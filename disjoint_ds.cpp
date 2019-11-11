/*
                      *********************************** DIS-JOINT SET UNION FIND ****************************
    Given n people (numbered 0 to n-1) and next you are given some pair of people (u) who are friends of each other.
    Rule:: If 1 and 2 are friends and 2 and 3 are friends, implies 1 and 3 to be friends
    You are given some queries(q) of pair of people,
                       For each query,
                                        print YES if they are friends
                                        else print NO.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


 lli n;
 unordered_map<lli,lli> parent;
 unordered_map<lli,lli> Rank;

void makeset(){
    for(lli i=0;i<n;i++){
        parent[i]=i;
    }
}

lli find(lli i){                            
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
    return parent[i];
}


void Union(lli i,lli j){                    //union by rank
    lli irep=find(i),irank,jrank;
    lli jrep=find(j);
    if(irep==jrep){
        return;
    }else{
         irank = Rank[irep];
         jrank = Rank[jrep];
        if(irank>jrank){
            parent[jrep]=irep;
        }else if(jrank>irank){
            parent[irep]=jrep;
        }else{
            parent[jrep]=irep;
            Rank[irep]++;
        }
    }
}


int main() {
   
    cin >> n;
   
    makeset();                   //initializing each number as a set i.e. making all as representatives
    lli u;
    cin >>u;                     // number of unions
    while(u--){
        lli a,b;
        cin >>a>>b;
        Union(a,b);              //union by rank
    }
    lli q;
    cin >>q;                     // No. of Queries
    while(q--){
        lli e,r;
        cin >>e>>r;
        if(find(e)==find(r)){    // if representatives same then same group
            cout << "YES\n";
        }else{
            cout <<"NO\n";
        }
    }


	return 0;
}
© 2019 GitHub, Inc.
