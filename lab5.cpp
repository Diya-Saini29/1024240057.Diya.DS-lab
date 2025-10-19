#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;

//CREATION OF SINGLY LL:
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
node* convertarr2list(int arr[],int n){
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<n;i++){
       node* temp=new node(arr[i]);
       mover->next=temp;//links the previously last node to the new node.
       mover=temp; 
    }
    return head;
}
int lengthoflist(node* head){
    int count=0;
    node* temp=head;
    while(temp){
        //cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    return count;
}
int search(node* head,int val){
    node* temp=head;
    while(temp){
        if(temp->data==val)return 1;
        temp=temp->next;
    }
    return 0;
}
node* removehead(node* head){
    if(head==NULL)return head;
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
node* removetail(node* head){
    if(head==NULL || head->next==NULL)return head;
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    /*temp->next is a pointer variable stored inside the second-to-last node.
delete temp->next; frees the heap memory of the last node, 
but it doesn’t erase or destroy the pointer value itself that lives inside temp.
After deletion, temp->next is a dangling pointer (it points to freed memory).*/
    delete temp->next;
    temp->next=nullptr;
}
node* remove_index(node* head,int k){
    if(k==1){
        head=removehead(head);
    }
    else{
        int count=0;
        node* temp=head;
        node* prev=nullptr;
        while(temp!=nullptr){
            count++;
            if(count==k){
                prev->next=prev->next->next;
                free(temp);
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
}
node* remove_value(node* head,int k){
    if(head->data==k){
        head=removehead(head);
        return head;
    }
    else{
        node* temp=head;
        node* prev=nullptr;
        while(temp!=nullptr){
            if(temp->data==k){
                prev->next=prev->next->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
node* insert_head(node* head,int value){
    return new node(value,head);
}
node* insert_tail(node*head,int value){
    node* new_node=new node(value);
    node* temp=head;
    while(true){
        if(temp->next==nullptr){
            temp->next=new_node;
            break;
        }
        temp=temp->next;
    }
    return head;
}
node* insert_index(node* head,int value,int k){
    if(head==NULL){
        if(k==1){
            return new node(value);
        }
    }
    if(k==1){
        return insert_head(head,value);
    }
    else{
        int count=0;
        node* temp=head;
        node* prev=nullptr;
        while(temp){
            count++;
            if(count==k){
                node* new_node=new node(value,prev->next);
                prev->next=new_node;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
node* insert_value(node* head,int value,int k){
    if(head==NULL){
        return NULL;
    }
    if(head->data==k){
        return insert_head(head,value);
    }
    else{
        node* temp=head;
        node* prev=nullptr;
        while(temp){
            if(temp->data==k){
                node* new_node=new node(value,prev->next);
                prev->next=new_node;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
/*int main(){
    int arr[]={1,22,3,4};
    node *head=convertarr2list(arr,4);
    node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    head=insert_value(head,55,22);
    temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}*/
//QUESTION 2:
/*Write a program to count the number of occurrences
 of a given key in a singly linked
list and then delete all the occurrences.*/
node* count_update(node* head,int k){
    node* temp=head;
    int count=0;
    while(temp){
        if(temp->data==k){
            count++;
            head=remove_value(head,k);
            temp=head;
        }
        else{
            temp=temp->next;
        }    
    }
    cout<<count<<endl;
    return head;
}
/*int main(){
    int arr[]={1,2,1,2,1,3,1};
    node* head=convertarr2list(arr,7);
    head=count_update(head,1);
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}*/

//QUESTION 3:
/*Write a program to find the middle of a linked list.*/
void middle(node* head,int n){
    node* temp=head;
    int count=0;
    while(temp){
        count++;
        if(count==n/2){
            cout<<temp->data;
        }
        temp=temp->next;
    }
}
/*int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    node* head=convertarr2list(arr,n);
    middle(head,n);
    return 0;
}*/
/*TORTOISE AND HARE ALGO!!*/
/*int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    node* head=convertarr2list(arr,n);
    node* slow=head;
    node* fast=head;
    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
    return 0;
}*/
//QUESTION 4:
/*Write a program to reverse a linked list*/
node* reverseList(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;        
        curr = next;        
    }
    return prev;
} 
/*int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    node* head=convertarr2list(arr,n);
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    head=reverseList(head);
    temp=head;
    cout<<endl;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}*/

//----------------------         ADDTIONAL QUESTIONS     ----------------------------//

//QUESTION 1:
/*Given two linked lists, find the node at which they intersect. 
If the two lists do not intersect, return null.*/
/*int main(){
    int listA[] = {4,1,8,5};
    int listB[] = {5,6,1,8,5};
    int len1=4;
    int len2=5;
    node* head1=convertarr2list(listA,len1);
    node* head2=convertarr2list(listB,len2);
    node* temp2=head2;
    for(int i=0;i<len2-len1;i++){
        temp2=temp2->next;
    }
    node* temp1=head1;
    for(int i=0;i<len1;i++){
        if(temp1->data==temp2->data){
            temp1=temp1->next;
            cout<<"Intersected at "<<temp1->data;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 0;
}*/

//QUESTION 2:
/*Given a linked list and a positive number K, reverse the nodes in groups of K. 
All the remaining nodes after multiples of k should be left as it is.*/
node* findk(node* temp,int k){
    k=k-1;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
/*int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    int k=3;
    int count=0;
    node* head=convertarr2list(arr,n);
    node* temp=head;
    node* next_node=nullptr;
    node* prevtail=nullptr;
    while(temp!=NULL){
        node* k_node=findk(temp,k);
        if(k_node==NULL){
            if (prevtail)prevtail->next=temp;break;
        }
        next_node=k_node->next;
        k_node->next=nullptr;
        node* revhead=reverseList(temp);
        if(head==temp){
            head=revhead;
        }
        else{
            prevtail->next=revhead;
        }
        prevtail=temp;
        temp=next_node;
    }
    node* start=head;
    while(start){
        cout<<start->data<<" ";
        start=start->next;
    }
    return 0;
}*/
/*4. Given a linked list, and an integer k, 
rotate the list to the left by k positions and return
the updated head*/
/*int main(){
    int arr[]={10,20,30,40,50};
    int n=5;
    int k=4;
    k=k%n;
    node* head=convertarr2list(arr,n);
    node* temp=head;
    node* last=head;
    for(int i=0;i<n-1;i++){
        last=last->next;
    }
    for(int i=0;i<k;i++){
        head=head->next;
        last->next=temp;
        last=temp;
        temp->next=nullptr;
        temp=head;
    }
    node* start=head;
    while(start){
        cout<<start->data<<" ";
        start=start->next;
    }
    return 0;
}*/

/*3. Given a linked list, remove the loop if it exists.*/
/*TORTOISE AND HARE ALGO!!*/
/*int main(){
    int arr[]={10,20,30,40,50};
    int n=5;
    node* head=convertarr2list(arr,n);
    node* temp=head;
    node* slow=temp;
    node* fast=temp;
    head->next->next->next->next->next = head->next->next;//looped list manual creation
    bool flag=false;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            flag=true;
            slow=head;
            break;
        }
    }
    if(flag){
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        node* loop_start=fast;
        while(fast->next!=loop_start){
            fast=fast->next;
        }
        fast->next=NULL;
        cout<<"Loop Existed "<<endl;
    }
    else{
        cout<<"No Loop Exist!"<<endl;
    }
    node* start=head;
    while(start){
        cout<<start->data<<" ";
        start=start->next;
    }
    return 0;
}*/
//QUESTION 5:
class node2 {
public:
    int coeff;
    int power;
    node2* next;
    node2(int val1, int val2, node2* nxt=nullptr) {
        coeff = val1;
        power = val2;
        next = nxt;
    }
};

node2* convertarr2list2(int arr[][2], int n) {
    if (n == 0) return nullptr; // safety
    node2* head = new node2(arr[0][0], arr[0][1]);
    node2* mover = head;
    for (int i = 1; i < n; i++) {
        node2* temp = new node2(arr[i][0], arr[i][1]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main() {
    int arr1[][2] = {{5,3}, {4,2}, {2,0}}; // 5x^3 + 4x^2 + 2
    int n1 = 3;
    int arr2[][2] = {{5,1}, {5,0}};        // 5x + 5
    int n2 = 2;

    node2* temp1 = convertarr2list2(arr1, n1);
    node2* temp2 = convertarr2list2(arr2, n2);

    node2* result = nullptr;
    node2* tail = nullptr;//tail is like temp here.

    while (temp1 && temp2) {
        node2* new_node = nullptr;

        if (temp1->power == temp2->power) {
            int sum = temp1->coeff + temp2->coeff;
            if (sum != 0)
                new_node = new node2(sum, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power) { 
            new_node = new node2(temp1->coeff, temp1->power);
            temp1 = temp1->next;
        }
        else {
            new_node = new node2(temp2->coeff, temp2->power);
            temp2 = temp2->next;
        }

        if (new_node) {
            if (!result) result = tail = new_node;
            else {
                tail->next = new_node;
                tail = tail->next;
            }
        }
    }

    while (temp1) {
        node2* new_node = new node2(temp1->coeff, temp1->power);
        if (!result) result = tail = new_node;
        else { tail->next = new_node; tail = tail->next; }
        temp1 = temp1->next;
    }

    while (temp2) {
        node2* new_node = new node2(temp2->coeff, temp2->power);
        if (!result) result = tail = new_node;
        else { tail->next = new_node; tail = tail->next; }
        temp2 = temp2->next;
    }
    while (result) {
        cout << result->coeff << "x^" << result->power;
        if (result->next) cout << " + ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
