#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string.h>
using namespace std;

struct node{
    int roll;
    string name;
    string dob;
};

void Insert(vector <node> &v){
    cout<<"Enter the total number of students  : ";
    int n;
    cin>>n;
    for(int i=0 ;i<n;i++){
        node s;
        cout<<"\nEnter  name of  the student (string): ";
        cin>>s.name;
        cout<<"Enter Phone no. of student (integer) : ";
        cin>>s.roll;
        cout<<"Enter DOB of the student (dd/mm/yy) : ";
        cin>>s.dob;
        cout<<"Student "<<v.size()+1<<" data entered successfully \n";
        v.push_back(s);
    }
    cout<<"\nDo you want to insert more students (1/0) : ";
    int m;
    cin>>m;
    if(m==1)
        Insert(v);
}

void display(vector<node> &v){
    cout<<"\nDisplaying Data .......\n";
    for(int i=0 ; i<v.size() ;i++){
        cout<<v[i].roll << " "<<v[i].name<<endl;
    }
}

bool c_str(node &v1, node &v2){
    return(v1.name<v2.name);
}

bool c_int(node &v1 , node &v2){
    return (v1.roll<v2.roll);
}

void Sorting(vector<node>&v){
    cout<<"\n1.Sorting w.r.t name\n2.Sorting w.r.t phone no.\n";
    cout<<"Enter your choice (1/2): ";
    int c;
    cin>>c;
    if(c==1)
        sort(v.begin(), v.end(),c_str);
    else
        sort(v.begin(), v.end(),c_int);
    display(v);
}

void Search(vector<node> &v){
    cout<<"Enter the name of student to be searched : ";
    string key;
    cin>>key;
    vector <node> :: iterator it;
    for(it=v.begin() ; it!=v.end() ;it++){
        if(it->name==key){
            cout<<"Found.....  !\n";
            cout<<it->name<<' '<<it->roll<<endl;
            return;
        }
    }
    cout<<"Student not present!!!\n";
}

int main(){
    vector<node> j;
    int ch , c;
    cout << "\t1: Create a record" << endl;
    cout << "\t2: Display records" << endl;
    cout << "\t3: Search person" << endl;
    cout << "\t4: Sort records" << endl;
    do{
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch){
            case 1:
                Insert(j);
                break;
            case 2:
                display(j);
                break;
            case 3:
                Search(j);
                break;
            case 4:
                 Sorting(j);
                break;
            default:
                cout << "Enter valid choice..." << endl;
                break;
        }
        cout<<"Do you want to continue (1/0) : ";
        cin>>c;
    }while(c==1);
    return 0;
}