#include<iostream>

using namespace std;

int main()
{
	unsigned long long int num,i;
	int t,count=0;
	cin>>t;
	while(t--)
    {
        cin>>num;
        if(num==1)
            cout<<"Not a Prime";
        for(i=2;i*i<num;i++)
        {
            if(num%i==0)
            {
                count++;
                break;
            }
        }
        if(count==0)
            cout<<"Prime";
        else
            cout<<"Not a Prime";
    }
    return 0;
}
