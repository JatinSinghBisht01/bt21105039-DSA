#include<bits/stdc++.h>
using namespace std;
 
class node{
 
    public:
    int data;
    node* next;
 
    node(int val){
        data=val;
        next=NULL;
    }
};
 
void insertAtHead(node* &head, int val){
    node* newnode=new node(val);
 
    if(head==NULL){
        newnode->next=newnode; 
        head=newnode;
        return;
    }
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;
}
 
void insertAtTail(node* &head, int val){
 
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
 
    node* newnode = new node(val);
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
 
    temp->next=newnode;
    newnode->next=head;
}
 
void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
 
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
 
    delete todelete;
}
 
void deletion(node* &head, int pos){
 
    if(pos==1){
        deleteAtHead(head);
        return;
    }
      node* temp=head;
      int count=1;
 
      while(count!=pos-1){
          temp=temp->next;
          count++;
      }
 
      node* todelete=temp->next;
      temp->next=temp->next->next;
 
      delete todelete;
}
 
void display(node* head){
 
 
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
}
 
 
int main(){
 
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,1);
    display(head);

}

/*
									                   Bt21105039 - ECE
										       Jatin Singh Bisht

ASSIGNMENT-02
			     (Circular Linked List)
Q1. While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element?
Ans. Since tailnode(last element) of a circularlinked list stores the address of headnode(first element), therefore while traversing the linkedlist using while or for loop if currentnodes points to the headnode this means we have reached the first element.
//code
current=head->next;
//condition using while loop
while(current!=head){ current=current->next; }
//Condition using for loop
for(; current!=head; current=current->next){ }

Q2. What are the practical applications of a circular linked list? 
Ans. Applications:
•	Implementation of Advanced data structures like Fibonacci Heap.
•	The browser cache allows us to hit the BACK button.
•	Undo functionality in Photoshop or Word.
•	Circular linked list used Most recent list (MRU LIST)
•	Round Robin scheduling technique in games.
•	To repeat the playlist during audio video streaming.
•	Multiple running applications can be placed in a circular linked list on an operating system. The OS keeps on iterating over these applications.


*/
