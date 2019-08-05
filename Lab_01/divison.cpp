#include<bits/stdc++.h>

using namespace std;
string sub(string str1,string str2)
{
    char a='0';
    long int x=0,y;
    if(str1.size()<str2.size())
    {
        swap(str1,str2);
        cout<<"-";
    }
    if(str1.size()==str2.size())
    {
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]>str2[i])
                break;
            if(str1[i]<str2[i])
            {
                swap(str1,str2);
                cout<<"-";
                break;
            }
        }
    }
    while(str2.size()<str1.size())
        str2.insert(0,"0",1);
    string str="";
    for(long int i=str1.size()-1;i>=0;i--)
    {
        y=(int)(str1[i]-'0')-(int)(str2[i]-'0')+x;
        x=0;
        if(y<0)
        {
            x=-1;
            y+=10;
        }
        str.push_back((char)(y+(int)a));
    }
    reverse (str.begin(),str.end());
    str.erase(0,str.find_first_not_of('0'));
    if(str=="")
        str="0";
    return str;
}

int small(string str1,string str2)
{
    long int i;
    if(str1.size()>str2.size())
        return 1;
    else
    {
        if(str1.size()<str2.size())
            return 0;
        else
        {
            for(i=0;i<str2.size();i++)
            {
                if(str1[i]>str2[i])
                    return 1;
                if(str2[i]>str1[i])
                    return 0;
            }
            return 2;
        }
    }
}

int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        string str="";
        long int a=str1.length();
        long  int b=str2.length();
        if(small(str1,str2)==0)
        {
            cout<<0<<" "<<str1<<endl;
            return 0;
        }
        if(small(str1,str2)==2)
        {
            cout<<1<<" "<<0<<endl;
            return 0;
        }
        string x="";
        long int j=b-1,k=0;
        for(int i=0;i<b;i++)
            x.push_back(str1[i]);
        while(j<a)
        {
            k=0;
            while(small(x,str2)!=0)
            {
                x=sub(x,str2);
                k++;
            }
            j++;
            if(j<a)
                x.push_back(str1[j]);
            x.erase(0,x.find_first_not_of('0'));
            if(x=="")
                x="0";
            str.push_back(k+'0');
        }
        str.erase(0,str.find_first_not_of('0'));
        cout<<str<<endl<<x<<endl;
    }

    return 0;
}
