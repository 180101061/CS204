#include <bits/stdc++.h>

using namespace std;
string multiply(string str1, string str2) {
        if(str1.size()==0||str2.size()==0) return "";
        string ret(str1.size()+str2.size()+1,'0');
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        for(int i=0;i<str2.size();i++){
            int y=str2[i]-'0';
            int carry=0;
            for(int j=0;j<str1.size();j++){
                int x=str1[j]-'0';
                int temp=ret[i+j]-'0';
                int cur=x*y+temp+carry;
                ret[i+j]=cur%10+'0';
                carry=cur/10;
            }
            ret[i+str1.size()]=carry+'0';
        }
        reverse(ret.begin(),ret.end());
        int pos=ret.find_first_not_of('0',0);
        if(pos<0||pos>=ret.size())
            pos=ret.size()-1;
        return ret.substr(pos,ret.size()-pos);
    }

int main()
{
    int t;
    cin>>t;
    while(t--){
   string str1,str2;
   cin>>str1>>str2;
   cout<<multiply(str1,str2);
    }
    return 0;
}
