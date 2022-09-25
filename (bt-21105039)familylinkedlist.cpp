// bt21105039 - Jatin Singh Bisht - ECE

#include <bits/stdc++.h>                   
using namespace std;

//Node class
class Node{
    public:
    string name;
    int age;
    Node*next; //node storing address of nextnode
    Node*prev; //node storing address of prevnode
    //calling constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; //initialising next as NULL
        prev=NULL; //initialising prev as NULL
    }
};

//inserting data at end of linkedlist
void insertAtEnd(Node* &head,string name,int age){
    //node pointer storing address of headnode
    Node*temp=head;
    //creating a newnode to store family data
    Node*newnode=new Node(name,age);
    //Inserting node in empty list
    if(temp==NULL){
        head=newnode;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){//traversing linkedlist until lastnode is reached.
            temp=temp->next;
        }
        //linking newnode at end of lastexisting node.
        temp->next=newnode;
        newnode->prev=temp; 
    }
}

//inserting data at start of linked list
void insertAtHead(Node*&head,string name,int age){
    //Creating a newNode pointer to store family data 
    Node*newnode=new Node(name,age);
    //Inserting newnode at head
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

//to print family data starting from headnode
void displayFromStart(Node*head){
    Node*temp=head;
    while(temp!=NULL){//traversing until tailnode is reached
        cout<<"(Name:"<<temp->name<<" Age:"<<temp->age<<")"<<endl;
        temp=temp->next;
        }
    cout<<endl;
}

//to print family data startin from tailnode
void displayFromEnd(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next; // traversing until tailnode is reached.
    }
    while(temp!=NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";
        temp=temp->prev; //reverse raversing until headnode is reached.
    }
    cout<<endl;
}

//to delete element at ith index
void deleteIthElement(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//TO DELETE LAST ELEMENT
void DeleteAtEnd(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    //Initialising a node pointer
    Node*head=NULL;
	int familycount;
	cout<<"Enter Family member count";
    cin>>familycount;
    //taking input
	for(int i=1;i<=familycount;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name, Age :";cin>>name>>age;
		
        //adding family data in family linkedlist
		insertAtEnd(head,name,age);
	}
    cout<<endl;
    //Displaying Family details
    cout<<"Famlily Members:"<<endl;
    cout<<endl;
    displayFromStart(head);
}

/*output
    Enter Family member count5
    Enter Family Member 1 Name, Age : Mukesh 45   
    Enter Family Member 2 Name, Age : Neeta 43
    Enter Family Member 3 Name, Age : Pankaj 28
    Enter Family Member 4 Name, Age : Pooja 23
    Enter Family Member 5 Name, Age : Priya 18

    Famlily Members:

    (Name:Mukesh Age:45)
    (Name:Neeta Age:43)
    (Name:Pankaj Age:28)
    (Name:Pooja Age:23)
    (Name:Priya Age:18)
/*
/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on their relationship.(Is it possible?)
Ans. yes it is possible to link family members based on their relationships by taking idea from tree datastructures and using it in linkedlist.
    we can have a childhead pointer which will store the address of headnode of child linkedlist and is connected to its parentnode.

             //generation 1:                                   | grandfather- grandmother|  // storing husband wife in same node
            //generation 2:                         |father-mother| <=> |uncle-aunt|      
           //generation 3:                    |child1|<=>|child2|             |cousin1|<=>|cousin2|    
            
    DFS algortihm will be usefull to access all the family members based on their parent precedence.
    BFS algorithm will be usefull to access all the family members based on familygeneration.
*/