#include<iostream>
using namespace std;

class stack{
    int top ,size;
    char *arr;
    public:
        stack(int n){
            size=n;
            arr=new char[size];
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
                cout<<"stac Overflow\n";
                return;
            }
            top++;
            arr[top]=a;
        }

        void pop(){
            if(isEmpty()){
                cout<<"Queue Underflow\n";
                return;
            }
            top--;
        }

        int Size(){
            return top+1;
        } 

        string Rev(string s){
            string s1="";
            for(int i=0 ;i<s.length();i++){
                push(s[i]);
            }
            while(top!=-1){
                s1=s1+arr[top];
                pop();
            } 
            return s1;
        }
        bool isPalindrome(string s){
            string r_str;
            r_str=Rev(s);
            return (r_str==s);
        }
};

int main(){
    
    int ch;
    do{
        string str,rstr;
        cout<<"Enter string : ";
        cin>>str;

        int n=str.length();
        stack a(n);
        
        rstr=a.Rev(str);
        cout<<"\nOriginal String is "<<str<<endl;
        cout<<"Reverse of string is : "<<rstr<<endl;

        cout<<"\nFor Palindrome ......\n";
        if(a.isPalindrome(str)){
            cout<<"String is Palindrome\n";
        }
        else 
            cout<<"String is Not Palindrome\n";
        
        cout<<"\nDo you want to continue (1/0) : ";
        cin>>ch;
    }while(ch==1);
    return 0;
}