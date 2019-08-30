#include<bits/stdc++.h>
using namespace std;
map<string,int> chart;

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
        try{return stoi(root->value);
        }
        catch(...){
            if(chart.find(root->value)!=chart.end()) return chart[root->value];
            else 
            return INT_MAX;
        }
    }
    int left_val=eval(root->left);
    int right_val=eval(root->right);
    if (left_val==INT_MAX||right_val==INT_MAX)
    return INT_MAX;
    if(root->value=="+") return left_val+right_val;
    else if(root->value=="-") return left_val-right_val;
    else if(root->value=="*") return left_val*right_val;
    else if(root->value=="/") return left_val/right_val;
    else return pow(left_val,right_val);
}
vector<string> makingevaluated(string s)
{
    int t=0;
         int x=0;
         string temp="";
         vector<string> str;
    for(int i=0; i<s.length();i++)
    {
        
        if( (s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) )
        {
            temp+=s[i];
        }
        
        else
        {
            if((temp=="" && s[i]=='-' && i==0) || (temp=="" && s[i]=='-' && s[i-1]!=')' ) ) //check if unary minus is thee
                {
                    str.push_back("("); 
                    str.push_back("0"); 
                    str.push_back("-"); 
                    if(s[i+1]=='(') t+=1;  
                    else x+=1; 
                }
            else{
                  if(temp!="") str.push_back(temp);  
                  
                  while(x>0) { 
                      str.push_back(")"); 
                      x--;
                  }
                  
                  temp=""; temp+=s[i]; 
                  if(temp!="") str.push_back(temp); 
                  
                  if(temp==")") { 
                      if(t--)
                         str.push_back(")"); 
                  }
                   
                  



                }
                temp=""; 

        }

    }
    
    str.push_back(temp);
    if(x>0) str.push_back(")");
    return str;
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
    if(s.find("=") == std::string::npos){
        vector<string> str= makingevaluated(s);
        vector<string> postexp= postfix(str);
        struct et* root = constructtree(postexp);
        int ans = eval(root);
        if(ans != INT_MAX)
        cout<<ans<<endl;
        else cout<<"NOT EVALUATED"<<endl;
    }
    else {
        int k= s.find("=");
        string s1=s.substr(0,k);
        string s2=s.substr(k+1);
        vector<string> str= makingevaluated(s2);
        vector<string> postexp=postfix(str);

        struct et* root=constructtree(postexp);
        int ans = eval(root);
        if(chart.find(s1)!= chart.end() )
         {
          if(ans != INT_MAX)
          chart[s1]=ans;
          else cout<<"NOT EVALUATED"<<endl;
         }
        else
         {
           if(ans != INT_MAX)
           chart.insert(make_pair(s1,ans));
           else cout<<"NOT EVALUATED"<<endl;
         }
    }
  }
  }
  return 0;
}
