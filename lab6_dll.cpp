#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val,node* next1,node* prev1){
        data=val;
        next=next1;
        prev=prev1;
    }
    node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
node* create(int arr[],int n){
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<n;i++){
        node* new_node=new node(arr[i]);
        mover->next=new_node;
        mover->next->prev=mover;
        mover=new_node;
    }
    return head;
}
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node* delete_head(node* head){
    node* temp=head;
    if(head==NULL){
        cout<<"empty list";
        return NULL;
    } 
    else{
        head=head->next;
        if(head!=NULL){
            head->prev=nullptr;
        }
    }
    delete temp;
    return head;
}
node* delete_tail(node* head){
    node* temp=head;
    if(head==NULL){
        cout<<"list is empty.";
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return head;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        delete temp;
    }
    return head;
}
node* delete_index(node* head, int k, int n) {
    if (head == nullptr) return nullptr;
    if (k == 0) {
        return delete_head(head);
    }
    if (k == n - 1) {
        return delete_tail(head);
    }
    node* temp = head;
    int count = 0;
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) return head;  
    if (temp->prev)
        temp->prev->next = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
    return head;
}
node* insert_head(node* head,int n){
    node* temp=new node(n);
    temp->next=head;
    temp->next->prev=temp;
    return temp;
}
node* insert_tail(node* head,int n){
    node* temp=new node(n);
    node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    curr->next->prev=curr;
    return head;
}
node* insert_value(node* head,int val,int idx){
    node* new_node=new node(val);
    node* temp=head;
    int count=0;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
        if(count==idx)break;
    }
    new_node->next=temp;
    new_node->prev=temp->prev;
    temp->prev->next=new_node;
    temp->prev=new_node;
    return head;
}
node* search(node* head,int val){
    node* temp=head;
    int count=0;
    while(temp->next!=NULL){
        count++;
        if(temp->data==val){
            cout<<temp->data<<endl<<count;
            break;
        }
        temp=temp->next;
    }
}
node* reverse(node* head){
    node* temp=head;
    node* last=NULL;
    while(temp!=NULL){
        temp->prev=temp->next;
        temp->next=last;
        last=temp;
        temp=temp->prev;
    }
    return last;
}
bool palindrome(node* head,int n){
    node* temp=head;
    node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    int count=1;
    while(count<=n/2){
        if(temp->data==temp2->data){
            count++;
        }
        else{
            return false;
        }
        temp=temp->next;
        temp2=temp2->prev;
    }
    return true;
}
bool parity(int x){
    int count=0;
    while(x!=0){
        if(x & 1){
            count++;
        }
        x=x>>1;
    }
    if(count%2==0){
        return true;
    }
    else{
        return false;
    }
}
node* parity_func(node* head,int n){
    node* temp=head;
    int idx=0;
    while(temp!=NULL){
        if(parity(temp->data)){
            head=delete_index(head,idx,n);
            temp=head;
            n--;
            idx=0;
        }
        else{
            temp=temp->next;
            idx++;
        }
    }
    return head;
}
node* reverse_k(node *head, int k) {
    if (head == nullptr) {
        return head;
    }
    node *curr = head;
    node *newHead = nullptr;
    node *tail = nullptr;
    while (curr != nullptr) {
        node *groupHead = curr;
        node *prev = nullptr;
        node *next = nullptr;
        int count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = nullptr;
            if (prev != nullptr) {
                prev->prev = curr;
            }
            prev = curr;
            curr = next;
            count++;
        }
        if (newHead == nullptr) {
            newHead = prev;
        }
        if (tail != nullptr) {
            tail->next = prev;
            prev->prev = tail;
        }
        tail = groupHead;
    }
    return newHead;
}
node* correct(node* head){
    node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->prev!=temp){
            temp->next->prev=temp;
            break;
        }
        temp=temp->next;
    }
    return head;
}
void print_back(node* head){
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
class node2{
    public:
    int data;
    node2* next;
    node2* prev;
    node2* up;
    node2* down;
    node2(int val,node2* nxt=nullptr,node2* prv=nullptr,node2* up1=nullptr,node2* down1=nullptr){
        data=val;
        next=nxt;
        prev=prv;
        up=up1;
        down=down1;
    }
};
node2* create_2d(int arr[3][3],int row,int col){
    node2* nodearray[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            nodearray[i][j] = new node2(arr[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j>0){
                nodearray[i][j]->prev=nodearray[i][j-1];
            }
            if(j<col-1){
                nodearray[i][j]->next=nodearray[i][j+1];
            }
            if(i>0){
                nodearray[i][j]->up=nodearray[i-1][j];
            }
            if(i<row-1){
                nodearray[i][j]->down=nodearray[i+1][j];
            }
        }
    }
    return nodearray[0][0];
}
void print2d(node2* head,int row,int col){
    node2* rowptr=head;
    for(int i=0;i<row;i++){
        node2* colptr=rowptr;
        for(int j=0;j<col;j++){
            cout<<colptr->data<<" ";
            colptr=colptr->next;
        }
        rowptr=rowptr->down;
        cout<<endl;
    }
}
int main(){
    int arr[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    node2* head=create_2d(arr,3,3);
    print2d(head,3,3);
    return 0;
}