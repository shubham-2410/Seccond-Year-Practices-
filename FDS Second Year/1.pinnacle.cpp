#include<iostream>
using namespace std;
#include<stdlib.h>
struct node{
    int prn;
    string name;
    node *next;
};
class pinnacle{
    node *head;
    public:
        pinnacle(){
            head=NULL;
        }
    void Insert(){
        cout<<"\n1.For President \n2.For Member\n3.For Secratary\n";
        int c , i=1 , n;
        cout<<"\nEnter your choice : ";
        cin>>c;
        node *newnode= new node();
        cout<<"Enter prn : ";
        cin>>newnode->prn;
        cout<<"Enter Name : ";
        cin>>newnode->name;
        node *temp=head;
        switch(c){
            case 1:
                if(head==NULL){
                    head=newnode;
                    newnode->next=NULL;
                }
                else{
                    newnode->next=head;
                    head=newnode;
                }
                break;
            case 2:
                cout<<"Enter position at which member to be inserted between president and secratary: ";
                cin>>n;
                while(i<n-1){
                    temp=temp->next;
                    i++;
                }
                newnode->next=temp->next;
                temp->next=newnode;
                break;
            case 3:
                while (temp->next!=NULL)
                {
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next=newnode;
                break;                
        }
    }
    void Delete(){
        int c , n, i=1;
        cout<<"\n1.To delete President\n2.To delete Member\n3.To delete Secratary\n";
        cout<<"Enter your choice : ";
        cin>>c;
        node *temp=head;
        node *curr;
        switch(c){
            case 1:
                head=head->next;
                curr=temp;
                free(curr);
                break;
            case 2:
                cout<<"Enter position at which member to be delete between president and secratary: ";
                cin>>n;
                while(i<n-2){
                    temp=temp->next;
                    i++;
                }
                curr=temp->next;
                temp->next=curr->next;
                free(curr);
                break;
            case 3:
                while ((temp->next)->next!=NULL)
                {
                    temp=temp->next;
                }
                curr=temp->next;
                temp->next=curr->next;
                free(curr);
                break;                
        }
    }
    void display(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->name<<'('<<temp->prn<<") ->";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    pinnacle p;
    int c , ch , m;
    cout<<"\n1.To Insert\n2.To delete\n3.To display\n";
    do{ 
        cout<<"\nEnter your choice for main functions  : ";
        cin>>c;
        switch(c){
            case 1:
                cout<<"Inserting .....";
                do{
                    p.Insert();
                    cout<<"Do you want to continue inserting (1/0): ";
                    cin>>m;
                } while (m==1);
                break;
            case 2: 
                cout<<"\nDeleting .....\n";
                do{
                    p.Delete();
                    cout<<"Do you want to continue Deleting (1/0): ";
                    cin>>m;
                } while (m==1);
                break;
            case 3:
                p.display();
                break;
            default:
                return 0;
        }
        p.display();
        cout<<"\nDo you want to continue performing functions (1/0) : ";
        cin>>ch;
    }while(ch==1);
    return 0;
}