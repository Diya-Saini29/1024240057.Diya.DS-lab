#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
//CREATION OF CIRCULAR LL:
class node{
    public:
    int data;
    node* next;
    public:
    node(int val,node* nxt=nullptr){
        data = val;
        next = nxt;
    }
};
node* c_createclist(int arr[],int n){
    if (n == 0) return nullptr;
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<n;i++){
        node* temp=new node(arr[i]);
        prev->next=temp;
        prev=temp;
    }
    prev->next=head;
    node* tail=prev;
    return head;
}
void display(node* head) {
    if (!head) return;
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

bool c_search(node* head,int val){
    node* temp=head;
    while(temp->next!=head){
        if(temp->data==val){
            return true;
            break;
        }
        temp=temp->next;
    }
    return false;
}
node* c_insert_head(node* head,int value){
    node* new_head=new node(value,head);
    if (head == nullptr) {
        new_head->next = new_head; 
        return new_head;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_head;
    return new_head;
}
node* c_insert_tail(node* head,int value){
    node* new_node=new node(value);
    if(head==nullptr){
        new_node->next = new_node;
        return new_node;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
    return head;
}
node* c_insert_value(node* head,int value,int new_value){
    if(head==nullptr){
        cout<<"list is empty.";
        return head;
    }
    if(head->data==value){
        return c_insert_head(head,new_value);
    }
    node* new_node=new node(new_value);
    node* temp=head;
    node* prev=nullptr;
    while(temp->next!=head){
        if(temp->data==value){
            prev->next=new_node;
            new_node->next=temp;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    //delete new_node;
    return head;
}
node* c_delete_head(node* head){
    if (head == nullptr) {
        cout << "List is empty.\n";
        return nullptr;
    }
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    node* temp=head;
    node* new_head=head->next;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_head;
    return new_head;
}
node* c_delete_tail(node*head){
    if (head == nullptr) {
        cout << "List is empty.\n";
        return nullptr;
    }
    node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    node* tail = temp->next;
    temp->next = head;
    delete tail;
    return head;
}
node* c_delete_value(node* head,int value){
    if (head == nullptr) {
        cout << "List is empty.\n";
        return nullptr;
    }
    if(head->data==value){
        return c_delete_head(head);
    }
    else{
        node* temp=head;
        node* prev=nullptr;
        while(temp->next!=head){
            if(temp->data==value){
                prev->next=prev->next->next;
                free(temp);
                return head;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
node* display_cll(node* head){
    node* temp= head;
    int a=temp->data;
    cout<<a<<" ";
    while(true){
        temp=temp->next;
        cout<<temp->data<<" ";
        if(temp->data==a)break;
    }
    return head;
}
void check_cll(node* head){
    node* temp=head;
    int a= temp->data;
    while(true){
        if(temp->data==a){
            cout<<"YES";
            break;
        }
        else if( temp==NULL){
            cout<<"No";
            break;
        }
    }
}
void split_cll(node* head,node*& head1,node*& head2){
    if (!head || head->next == head)
        return;
    node* slow=head;
    node* fast=head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next->next==head){
        fast=fast->next;
    }
    head1=head;
    head2=slow->next;
    slow->next=head1;
    fast->next=head2;
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    node* head=c_createclist(arr,n);
    node* head1=nullptr;
    node* head2=nullptr;
    split_cll(head,head1,head2);
    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;
    return 0;
}