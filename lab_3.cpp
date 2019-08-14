#include<bits/stdc++.h> 
using namespace std; 
  

bool check(string expr) 
{ 
    stack<char> str; 
    char x;

    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{'||expr[i]=='<') 
        { 
             
            str.push(expr[i]); 
            continue; 
        }
         
        else if(expr[i]=='|'){
          if(str.empty()){
            str.push(expr[i]);
            continue;}
          x =str.top();        
            if(x!='|'){
            str.push(expr[i]);
            continue;}
             else if(x=='|'){
             str.pop();
             continue;
           }
              
         }
     
        if (str.empty()) 
           return false; 
  
        switch (expr[i]) 
        { 
        case ')':
  
            x = str.top(); 
            str.pop(); 
            if (x=='{' || x=='['||x=='<'||expr[i]=='|') 
                return false; 
            break; 
  
        case '}': 
  
           
            x = str.top(); 
            str.pop(); 
            if (x=='(' || x=='['||x=='<'||expr[i]=='|') 
                return false; 
            break; 
  
        case ']': 
  
            
            x = str.top(); 
            str.pop(); 
            if (x =='(' || x == '{'||x=='<'||expr[i]=='|') 
                return false; 
            break; 
       case '>': 
  
            
            x = str.top(); 
            str.pop(); 
            if (x =='(' || x == '{'||x=='['||expr[i]=='|') 
                return false; 
            break; 
        } 
    
          
    } 
  
   
    return (str.empty()); 
} 
  

int main() 
{ 
int t;
cin>>t;
int arr[t];
for(int i=0;i<t;i++){
    string expr;
  cin>>expr; 
   arr[i]=(int)check(expr); 
}
for(int i=0;i<t;i++){
   if(arr[i]==1)
cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
return 0;
} 
