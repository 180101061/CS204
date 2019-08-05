#include<bits/stdc++.h>
using namespace std;
int smaller(string str1, string str2)
{

    int a = str1.length(), b = str2.length();

    if (a < b)
    return 1;
    if (b < a)
    return 0;

    for (int i=0; i<a; i++)
    if (str1[i] < str2[i])
        return 1;
    else if (str1[i] > str2[i])
        return 0;

    return 1;
}
string sub(string str1,string str2)
{int a,b,i,j,carry;
char temp;
string str="";
if(smaller(str1,str2))
    swap(str1,str2);
a=str1.length();
b=str2.length();


reverse(str1.begin(),str1.end());
reverse(str2.begin(),str2.end());
for(i=b;i<a;i++)
str2.push_back('0');
for(i=0;i<a;i++)
{if(str1[i]-str2[i]<0)
{temp=str1[i]+10-str2[i]+'0';
str1[i+1]=str1[i+1]-1;
    str.push_back(temp);
}
else
str.push_back(str1[i]-str2[i]+'0');}

reverse(str.begin(),str.end());
return(str);}
int main(){
    int t;
    cin>>t;
    while(t--){
  string str1,str2;
  cin>>str1;
  cin>>str2;
  cout<<sub(str1,str2)<<endl;
    }
return 0;
}
