#include<bits/stdc++.h>
using namespace std; 

typedef struct node{
    int data;
    struct node* ptr;
}node;

node* XOR (node *a, node *b)  
{  
    return (node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  

node* insert_front(node* head, int x)
{
  node *temp= new node();
  temp->data=x;
  temp->ptr=head;
  if(head!=NULL){
      head->ptr = XOR(head->ptr,temp);
  }
  head = temp;
  return temp;
}


node* insert_rear(node* head, int x){
    node *new_node= new node();
    new_node->data = x;
    if(head==NULL){
        new_node->ptr = NULL;
        return new_node;
    }
    node *cur = head, *prev = NULL;
    node *next;
    while(cur){
        next = XOR(prev, cur->ptr);
        prev = cur;
        cur = next;
    }
    prev->ptr = XOR(prev->ptr, new_node);
    new_node->ptr = prev;
    return head;
}

node* delete_front(node* head){
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return head;
    }
    if(head->ptr==NULL){
        return NULL;
    }
    node* temp = head->ptr;
    temp->ptr = XOR(temp->ptr, head);
    return temp;
}


node* delete_rear(node* head){
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return head;
    }
    if(head->ptr==NULL){
        return NULL;
    }
    node *cur = head, *prev = NULL;
    node *next;
    while(cur->ptr!=prev){
        next = XOR(prev, cur->ptr);
        prev = cur;
        cur = next;
    }
    prev->ptr = XOR(prev->ptr, cur);
    return head;
}


 void display(node* head)
 {
  node *temp=head;
  node *prev=NULL;
  node *next;
  cout<<"The Linked List is: "<<endl;
  while(temp)
   {
    cout<<temp->data<<" ";
    next = XOR(temp->ptr, prev);
    prev = temp;
    temp = next;
   }
 }


int main(){ 
    node* head = NULL;
    int option, t;
    do{
        cout<<"\n\n1)Insert front\n2)Insert rear\n3)Delete front\n4)Delete rear\n5)Display\n6)Exit\nEnter an option: ";
        cin>>option;
        switch(option){
            case 1: cout<<"Inserting elements at front. Enter elements(-1 to exit)\n";
                    cin>>t;
                    while(t!=-1){
                        head = insert_front(head, t);
                        cin>>t;
                    }
                   break;
            case 2:cout<<"Inserting elements at rear. Enter elements(-1 to exit)\n";
                    cin>>t;
                    while(t!=-1){
                        head = insert_rear(head, t);
                        cin>>t;
                    }
                   break;
            case 3:head = delete_front(head);
                    break;
            case 4:head = delete_rear(head);
                    break;
            case 5:display(head);
                   break;
            case 6: break;
            default: cout<<"Enter valid option\n";
        }
    }while(option!=6);
    return 0;
}
