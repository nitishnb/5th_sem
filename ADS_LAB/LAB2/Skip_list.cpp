#include <bits/stdc++.h> 
#define MAX_VAL 4
using namespace std; 


typedef struct node{
    int data;
    node** forward;
};

node* insert(node* head, int x){
    node* new_node = new node();
    node* temp = head;
    new_node->data = x;
    srand(time(0));
    int level = (rand() % MAX_VAL)+1;
    new_node->forward = new node*[level];
	for(int i = MAX_VAL-1; i >= 0; i--){ 
		while (temp->forward[i] != NULL && temp->forward[i]->data < x)
			    temp = temp->forward[i];
		if(i < level){
            new_node->forward[i] = temp->forward[i];
            temp->forward[i] = new_node; 
        }
	}
    return head;
}


void display(node* head) { 
	for (int i=MAX_VAL-1;i >= 0;i--){ 
		node *temp = head; 
		cout << "Level " << i+1 << ": "; 
		while (temp != NULL) { 
			cout << temp->data<<" "; 
			temp = temp->forward[i]; 
		} 
		cout << "\n"; 
	} 
}; 


int main(){
    cout<<"Enter Elements for skip-list (-1 to exit): "<<endl;
    int n;
    node* head = new node();
    head->data = -1;
    head->forward = new node*[MAX_VAL];
    for(int i=0;i<MAX_VAL;i++)
        head->forward[i] = NULL;
    cin>>n;
    while(n!=-1){
        head = insert(head, n);
        cout<<"Skip List after insertion of "<<n<<" is:"<<endl;
        display(head);
        cin>>n;
    }
    return 0;
}
