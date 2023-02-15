#include <iostream>
using namespace std;
#include<stdlib.h>
struct node
{
    int data;
    node *next;
};
class Pinaccle
{
public:
    node *head;
    node *temp;
    int count;
    Pinaccle()
    {
        head = NULL;
        count=0;
    }
    void Insert()
    {
        node *newadd = new node();
        int ch ,i = 1;
        cout<<"1.Insert at Beginning\n2.Insert at any position\n3.Insert at End .";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the data : ";
            cin >> newadd->data;
            if (head == NULL)
            {
                head = newadd;
                newadd->next = NULL;
                temp = head;
                count++;
            }
            else
            {
                newadd->next = head;
                head = newadd;
                count++;
            }
            break;
        case 2:
            int n;
            temp = head;
            cout << "Enter the data : ";
            cin >> newadd->data;
            cout << "Enter the position where node to be inserted : ";
            cin >> n;
             while (i < n - 1)
            {
                temp = temp->next;
                i++;
            }
            newadd->next = temp->next;
            temp->next = newadd;
            count++;
            break;
        case 3:
            cout << "Enter the data : ";
            cin >> newadd->data;
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newadd;
            newadd->next = NULL;
            count++;
            break;
        }
    }
    void Display()
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
    void Delete();
    void Reverse();
    void Concatination(Pinaccle m);
};

void Pinaccle:: Delete(){
	node *temp2=head;
	temp=head;
	int ind , i=1;	
	cout<<"\n1.Delete from Beginning \n2.Delete between list \n3.Delete End \n";
	int ch;
	cout<<"Enter your choice ";
	cin>>ch;
	switch(ch){
		case 1:
			head=temp->next;
			temp=temp->next;
			free(temp2);
			count--;
			break;
		case 2:
			cout<<"\nEnter the index of Node to be deleted: ";
			cin>>ind;
			if(ind==1){
				head=temp->next;
				temp=temp->next;
				free(temp2);
				count--;
			}
			else{
				while(i<ind-1){
					temp=temp->next;
					i++;
				}
				temp2=temp->next;
				temp->next=temp2->next;
				free(temp2);
				count--;	
			} 
			break;
		case 3:
			while((temp->next)->next!=NULL){
				temp=temp->next;
			}
			temp2=temp->next;
			temp->next=NULL;
			free(temp2);
			count--;
			break;
		default:
			cout<<"\nWrong Input\n";
			break;
		}	
}	

void Pinaccle::Reverse(){
	node *prev=NULL ,*nextt=NULL;
	temp=head;
	while(temp!=NULL){
		nextt=temp->next;
		temp->next=prev;
		prev=temp;
		temp=nextt;
	}
	head=prev;
}

void Pinaccle::Concatination(Pinaccle m){
	temp=head;
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=m.head;
}

int main()
{
    Pinaccle p ,q;
    char c;
    int n;
    cout<<"1.Inserting a Linked List \n2.Deleting a Node \n3.Reversing a Linked list\n4.Concatination of Linked List\n5.Exit\n";
    while(true){
    	cout<<"\nChoose function to be performed :";
    	cin>>n;
    	switch(n){
    		case 1:
    			do{
    				p.Insert();
    				p.Display();
    				cout<<"\nDo you want to insert new node(y/n) : ";
        			cin>>c;
    			}while(c=='y');
    			break;
    		case 2:
    			p.Delete();  
    			p.Display();
    			break;
    		case 3:
    			p.Reverse();
    			p.Display();
    			break;
    		case 4:
    			cout<<"\nFor concatinating we need to new Linked List \n ";
    			do{
    				q.Insert();
    				q.Display();
    				cout<<"\nDo you want to insert new node(y/n) : ";
        			cin>>c;
    			}while(c=='y');
    			break;
    			q.Display();
    			q.Concatination(p);
    			q.Display();
    		case 5:
    			return 0;
    		}
	}  
return 0;
}