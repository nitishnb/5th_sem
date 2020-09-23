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
        cout<<"\n\n1)Insert front\n2)Insert rear\n3)Display\n4)Exit\nEnter an option: ";
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
            case 3:display(head);
                   break;
            case 4: break;
            default: cout<<"Enter valid option\n";
        }
    }while(option!=4);
    return 0;
}
