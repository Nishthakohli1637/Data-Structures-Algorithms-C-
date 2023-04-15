#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node (int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor for deletion
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};
//function for inserting a node at head
void insertAtHead(Node* &head, int x){
    Node* temp=new Node(x);
    temp->data=x;
    temp->next=head;
    head=temp;
    
}
//function for inserting a node at tail
void insertAtTail(Node* &tail, int x){
    Node* temp=new Node(x);
    // temp->data=x;
    tail->next=temp;
    tail=temp;
}
//function for printing the linked list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//function for insertion at head, we can also combine the codes for insertion at head and tail in this function instead of separately writing them
void insertAtPos(Node* &head, Node* &tail, int pos, int x){
    
    if(pos==1){
        insertAtHead(head, x);
        return;
    }
    Node* temp=new Node(x);
    Node* p=head;
    int cnt=1;
    while(cnt<pos-1){
        p=p->next;
        cnt++;
    }
    if(p->next==NULL){
        insertAtTail(tail, x);
        return;
    }
    temp->data=x;
    temp->next=p->next;
    p->next=temp;
}
//function for deletion of node
void delete_node(Node* &head, int pos){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    }
}
//function for finding maximum in a linked list
int max_node(Node* &head){
    Node* temp=head;
    int maxv=INT_MIN;
    while(temp!=NULL){
        if(temp->data>maxv){
            maxv=temp->data;
        }
        temp=temp->next;
    }
    return maxv;
}
//function for finding minimum in a linked list
int min_node(Node* &head){
    Node* temp=head;
    int minv=INT_MAX;
    while(temp!=NULL){
        if(temp->data<minv){
            minv=temp->data;
        }
        temp=temp->next;
    }
    return minv;
}
//function for searching in linked list
int search(Node* &head, int key){
    Node* p=head;
    while(p!=NULL){
        if(p->data==key){
            return p->data;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
}
int main(){
    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtTail(tail, 2);
     print(head);
    insertAtTail(tail, 1);
    print(head);
    insertAtPos(head, tail, 1, 5);
    print(head);
    insertAtPos(head, tail, 3, 8);
    print(head);
    insertAtPos(head, tail, 6, 3);
    print(head);
    // insertAtPos(head, tail, 4, 6);
    // print(head);
     cout<<"head"<<head->data<<endl;
     cout<<"tail"<<tail->data<<endl;
     delete_node(head, 2);
     print(head);
     cout<<"max_value "<<max_node(head)<<endl;
     cout<<"min_value "<<min_node(head)<<endl;
     int key=9;
     cout<<search(head, key);
}
