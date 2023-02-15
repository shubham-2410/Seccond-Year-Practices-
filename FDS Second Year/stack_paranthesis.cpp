#include<iostream>
using namespace std;

class stack{
    int size  , top;
    char *arr;
    public:
        stack(int n){
            size=n;
            arr= new char[size];
            top=-1;
        }

        bool isFull(){
            if(top==size-1)
                return true;
            return false;
        }

        bool isEmpty(){
            if(top==-1)
                return true;
            return false;
        }
        
        void push(char a){
            if(isFull()){
                cout<<"stack Overflow\n";
                return;
            }
            top++;
            arr[top]=a;
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack Underdflow\n";
                return;
            }
            top--;
        }

        int Size(){
            return top+1;
        }

        bool pCheck(string s){
            for(int i=0 ;i<s.length() ;i++){
                if(s[i]!='['&&s[i]!='{'&&s[i]!='('&&s[i]!='}'&&s[i]!=']'&&s[i]!=')'){
                    continue;
                }
                else{
                    if(top==-1 &&(s[i]==']'||s[i]=='}'||s[i]==')'))
                        return false;
                    else if(s[i]=='('||s[i]=='{'||s[i]=='['){
                        push(s[i]);
                    }
                    else if(arr[top]=='('){
                        if(s[i]==')'){
                            pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else if(arr[top]=='{'){
                        if(s[i]=='}'){
                            pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else if(arr[top]=='['){
                        if(s[i]==']'){
                            pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            if(isEmpty())
                return true;
            return false;
        }
};
int main(){
    char ch;
    do
    {
        string str;
        cout<<"Enter an Expression : ";
        cin>>str;
        int a=str.length();
        stack q(a);
        int r =q.pCheck(str);
        if(r==1)
        	cout<<"Valid Equation \n";
        else if(r==0)
        	cout<<"invalid Equation\n"; 
        
        cout<<"Do you want to continue (y/n) : " ;
        cin>>ch;
    } while (ch=='y'||ch=='Y');

    return 0;
}