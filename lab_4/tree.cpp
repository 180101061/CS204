#include<bits/stdc++.h>

using namespace std ;
//checking precedence
int pre(char chr) 
{ 
    if(chr == '^') 
    return 3; 
    else if(chr == '*' || chr == '/') 
    return 2; 
    else if(chr == '+' || chr == '-') 
    return 1; 
    else
    return -1; 
} 
//converting infix expression to 
//postfix expression
stack<int> infixToPostfix(string s) 
{ 
    stack<char> str; 
    str.push('N'); 
    
    stack<int> ns; 
    for(int i = 0; i < s.length(); i++) 
    { 
         
        if((s[i] >= '0' && s[i] <= '9')) 
        ns+=s[i]; 
  
        
        else if(s[i] == '(') 
          
        str.push('('); 
           
        else if(s[i] == ')') 
        { 
            while(str.top() != 'A' && str.top() != '(') 
            { 
                char c = str.top(); 
                str.pop(); 
               ns += c; 
            } 
            if(str.top() == '(') 
            { 
                char c = str.top(); 
                str.pop(); 
            } 
        } 
          
        
        else{ 
            while(str.top() != 'A' && pre(s[i]) <= pre(str.top())) 
            { 
                char c = str.top(); 
                str.pop(); 
                ns += c; 
            } 
            str.push(s[i]); 
        } 
  
    }
    while(str.top() != 'A') 
    { 
        char c = str.top(); 
        str.pop(); 
        ns += c; 
    } 
      
    return ns;
  
} 
struct et 
{ 
    int i; 
    et* left, *right, *root; 
};
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
} 
et* newNode(int v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->i = v; 
    return temp; 
};
et* constructTree(stack<int> s) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
 
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=newNode(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=newNode(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
            s.pop();
        }
    }
    return t; 
  
    
} 
int toInt(string s)  
{  
    int num = 0;  
      
     
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
   
    else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
      
    return num;  
} 


int eval(et* root)  
{  
     
    if (!root)  
        return 0;  
  
    
    if (!root->left && !root->right)  
        return root->i;  
  
    
    int l_val = eval(root->left);  
  
    
    int r_val = eval(root->right);  
  
     
    if (root->i=='+')  
        return l_val+r_val;  
  
    if (root->i=='-')  
        return l_val-r_val;  
  
    if (root->i=='*')  
        return l_val*r_val;  

    if(root->i=='/')
        return l_val/r_val;
    return pow(l_val,r_val);  
}  
int main()
{   
    int q;
    cin>>q;
    while(q--)
    {
        int T;
        cin>>T;
        while(T--)
        {
            char s[100000];
            cin>>s;
           
            stack <int> S,s1;
            S=infixToPostfix(s);
            while(!S.empty())
            {
                s1.push(S.top());
                S.pop();
            }
            
           et* p=constructTree(s1);
           
            cout<<eval(p)<<endl;
           
        }
    }
}
