#include <bits/stdc++.h>
using namespace std;
int main(){
    long int t;
    cin>>t;
   unsigned int max=0;
    while(t--){
        int n;
        cin>>n;
       string s[n],str[n];
        for(int i=0;i<n;i++){
            cin>>str[i];
            s[i]=str[i];
            if(str[i].size()>max){
                max=str[i].size();
            }
          
        }
        for(int j=0;j<n;j++){
            for(int i=0;s[j].size()<max;i++){
                s[j]+=s[j];
            }
            s[j]=s[j].substr(0,max+1);
        }
         vector <pair <string,string>> vect;
        for (int i=0; i<n; i++) {
            vect.push_back( make_pair(s[i],str[i]));
            
        }
        sort(vect.begin(),vect.end());                 
        for (int i=n-1; i>=0; i--){
            cout << vect[i].second;
            
        }
         cout<<endl;                 
    }
}
