#include<bits/stdc++.h>
using namespace std;


struct et 
{ 
    string value; 
    et* left, *right; 
}; 

int prec(string c) 
{ 
    if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
} 


bool isOperator(string str) 
{ 
    if (str.length()==1 && (str == "+" || str == "-" || 
            str == "*" || str == "/" || 
            str == "^") )
        return true; 
    return false; 
} 

et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  

vector<string> postfix(vector<string> s) 
{ 
    std::stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns; 
    for(int i = 0; i < l; i++) 
    { 
         
        if(!isOperator(s[i]) && s[i]!="" && s[i]!="(" && s[i]!=")") 
         ns.push_back(s[i]); 
        
  
       
        else if(s[i] == "(")   
        st.push("("); 
          
       
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 

              if(c!="" && c!="(" && c!=")")ns.push_back(c);
               
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop();  
            } 
        } 
          
        
        else{ 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                if(s[i]=="^"&&st.top()=="^") break;
                string c = st.top(); 
                st.pop(); 
                if(c!="" && c!="(" && c!=")")ns.push_back(c); 
                
            } 
            st.push(s[i]); 
        } 
  
    } 
  
    while(st.top() != "N") 
    { 
                string c = st.top(); 
                st.pop(); 
              if(c!="" && c!="(" && c!=")") ns.push_back(c); 
    } 
      
    return ns;
  
} 


et* constructtree(vector<string> postfix) 
{ 
    stack<et *> str; 
    et *t, *t1, *t2; 
  
   
    for (int i=0; i<postfix.size(); i++) 
    { 
       
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            str.push(t); 
        } 
        else 
        { 
            t = newNode(postfix[i]); 
  
          
            t1 = str.top();
            str.pop();      
            t2 = str.top(); 
            str.pop(); 
  
          
            t->right = t1; 
            t->left = t2; 
  
          
            str.push(t); 
        } 
    } 
  
    
    t = str.top(); 
    str.pop(); 
  
    return t; 
} 
int eval(et * root){
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL){
        return stoi(root->value);
    }
    int left_val=eval(root->left);
    int right_val=eval(root->right);
    if(root->value=="+") return left_val+right_val;
    else if(root->value=="-") return left_val-right_val;
    else if(root->value=="*") return left_val*right_val;
    else if(root->value=="/") return left_val/right_val;
    else return pow(left_val,right_val);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l;
        cin>>l;
     while(l--)
        {
         string s;
    cin>>s;
    vector<string> str;
    string temp="";
    
    for(int i=0; i<s.length();i++)
    {
        
        if(s[i]>=48 && s[i]<=57)
        {
          temp+=s[i];
        }
        else
        {
            if(temp=="" && s[i]=='-')
                {temp+=s[i]; continue;}
             if(temp!="")str.push_back(temp); 
            temp=""; temp+=s[i]; 
              if(temp!="")str.push_back(temp);
            temp="";
        }

    }
    
    str.push_back(temp);
    
     vector<string> postexp=postfix(str);
  
    

    struct et* root=constructtree(postexp);
    int eval_value = eval(root);
    cout<<eval_value<<endl;
    }
    }
return 0;
}
