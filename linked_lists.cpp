#include<bits/stdc++.h>
using namespace std;

typedef struct node
 {
  int data;
  struct node *next;
 }node;
node *head=NULL;

void insert_rear(int x)
 {
  node *temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=x;
  temp->next=0;
   if(head==0)
    head=temp;
   else
    {
     node *temp1=head;
     while((temp1->next)!=0)
      {
        temp1=temp1->next;
      }
    temp1->next=temp;
    }
 }


 void solve(int k){
    int count = 1;
    node* temp = head;
    node* start = head;
    node* t;
    node* previ;
    int flag = 0;
    while(temp){
        if(count == k || (temp->next==NULL && count > 1)){
            if(flag==0){
                head = temp;
                flag = 1;
            }
            else 
                previ->next = temp;
            node* n2 = temp->next;
            node* current = start; 
            node *prev = temp->next, *next = NULL; 
            while(current!=temp){ 
                next = current->next; 
                current->next = prev; 
                prev = current;
                current = next;
            }
            current->next = prev; 
            previ = start;
            temp = start->next;
            start = start->next;
            count = 1;
        }
        else{
            count++;
            t = temp;
            temp = temp->next;
        }    
    }
 }


void display()
 {
  node *temp=head;
  while(temp->next)
   {
    cout<<temp->data<<" -> ";
    temp=temp->next;
   }
   cout<<temp->data<<endl;
 }
 
 
int main()
{
    int option;
    cout<<"Enter elements to linked list(-1 to exit):"<<endl;
    cin>>option;
    while(option!=-1){
        insert_rear(option);
        cin>>option;
    }
    cout<<"The linked list is:  ";
    display();
    int k;
    cin>>k;
    solve(k);
    display();
    return 0;
}