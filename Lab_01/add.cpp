#include <bits/stdc++.h>
using namespace std;
void reverse(string str)
{
   for (int i=str.length()-1; i>=0; i--)
      cout << str[i];
      cout<<"\n";
}
void sum(string a,string b){
   int carry=0;
      if(a.length()>b.length()){
swap(a,b);
}
string c="";
int m=a.length();
int n=b.length();
int div=n-m;
for(int i=m-1;i>=0;i--){
int add;
add=((a[i]-'0')+(b[i+div]-'0')+carry);
c.push_back(add%10+'0');
carry=add/10;
}
for(int i=n-m-1;i>=0;i--){
int add;
add=((b[i]-'0')+carry);
c.push_back(add%10+'0');
carry=add/10;

}
if(carry)
c.push_back(carry+'0');
 reverse(c);

}
int main(){
    int t;
    cin>>t;
    while(t--){
string x;
string y;
cin>>x;
cin>>y;
sum(x,y);
}

return 0;
}
