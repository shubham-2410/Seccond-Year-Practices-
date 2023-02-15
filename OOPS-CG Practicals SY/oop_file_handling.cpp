#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

    ofstream output("sample.txt");
    string str;
    cout<<"Enter your name : ";
    cin>>str;
    output<<"Name : "<<str<<endl;
    cout<<"Enter your Roll no. : ";
    cin>>str;
    output<<"Roll No. : "<<str<<endl;
    cout<<"Enter your division : ";
    cin>>str;
    output<<"Div. : "<<str<<endl;
    output.close();

    ifstream input;
    input.open("sample.txt");
    string s;
    while(!input.eof()){
        getline(input,s);
        cout<<s;
        cout<<endl;
    }
    return 0;
}