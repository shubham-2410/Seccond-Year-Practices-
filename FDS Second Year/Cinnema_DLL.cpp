#include<bits/stdc++.h>
using namespace std;

struct node{
    string pin ;
    int no;
    node *prev , *next;
};

class Cinema{
    private :
        node *head , *temp;
        int count;
    public:
        Cinema(){
            cout<<"Main Menu\n";
            head=NULL;
            count=0;
            node *newnode=new node();
            head=newnode;
            newnode->no=1;
            newnode->prev=NULL;
            newnode->pin="_";
            newnode->next=head;
            temp=head;
            for(int i=2 ;i<=70;i++){
                node *newnode=new node();
                temp->next=newnode;
                newnode->no=i;
                newnode->prev=temp;
                newnode->pin="_";
                newnode->next=head;
                temp=newnode;
            }
        }

        void Display(){
            temp=head;
            int i=1;
            while(temp->next!=head){
                if(temp->pin=="_"){
                    if(i<10){
                        cout<<'0';
                    }
                    cout<<temp->no<<":[_] "<<' ';
                }
                else{
                    if(i<10){
                        cout<<'0';
                    }
                    cout<<temp->no<<":[B] "<<' ';
                }
                temp=temp->next;
                i++;
                if((i-1)%7==0)
                    cout<<endl;
            }
            if(temp->pin=="_")
                cout<<temp->no<<":[_] "<<' ';
            else
                cout<<temp->no<<":[B] "<<' ';    
        }

        void Insert(){
            cout<<"\nEnter seat number : ";
            int s;
            cin>>s;
            temp=head;
            while(temp->no!=s){
                temp=temp->next;
            }
            if(temp->pin=="_"){
                cout<<"Enter your pin : ";
                int p;
                cin>>p;
                temp->pin=p;
                count++;
            }
            else{
                cout<<"!! Seat is already taken !!\n";
            }
        }

        void Cancel(){
            cout<<"\nEnter seat number : ";
            int s;
            cin>>s;
            temp=head;
            while(temp->no!=s){
                temp=temp->next;
            }
            cout<<"Enter your pin : ";
            string p;
            cin>>p;
            if(temp->pin==p){
                temp->pin="[_]";
                cout<<"Seat cancelled successfully !! \n";
                count--;
            }
            else{
                cout<<"Wrong PIN ! Try Again \n";
            }
        }

        void Count(){
            cout<<"Current Status \n";
            cout<<"Booked Seats : "<<count<<endl;
            cout<<"Seats yet to Book  :"<<70-count<<endl;
        }
};

int main(){
    Cinema q;
    cout<<"1.Book Seat\n2.Cancel Seat\n3.Display\n4.Status\n5.Exit";
    int ch ;
    char c;
    while(true){
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                do{
                    q.Insert();
                    cout<<"Do you want to book more seat (y/n) ";
                    cin>>c;
    		    }while(c=='y');
                break;
            case 2:
                q.Cancel();
                break;
            case 3:
                q.Display();
                break;
            case 4:
                q.Count();
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}