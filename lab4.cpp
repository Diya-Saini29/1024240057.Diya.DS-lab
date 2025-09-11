#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
class Queue_int{
    public:
    int max_size;   
    int curr_size=0;
    int *arr;      
    int front; 
    int rear;       
    Queue_int(int x) {
        max_size = x;
        arr = new int[max_size];
        front = -1;
        rear=-1;
    }
    bool isEmpty(){
        return (curr_size==0);
    }
    bool isFull(){
        return (curr_size==max_size);
    }
    void enqueue(int n){
        if(!isFull()){
            if(rear==-1 && front==-1){
                rear=0;
                front=0;
            }
            else{
                rear++;
            }
            arr[rear]=n;
            curr_size++;
        }
    }
    int peek(){
        if(!isEmpty()){
            //cout<<arr[front];
            return arr[front];
        }
    }
    void dequeue(){
        if(!isEmpty()){
            front=front+1;
            curr_size--;
        }
        else{
            cout<<"queue is empty.";
        }
    }
    int size(){
        return rear-front+1;
    }
    void display(){
        if(!isEmpty()){
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};
class Queue_char{
    public:
    int max_size;   
    int curr_size=0;
    char *arr;      
    int front; 
    int rear;       
    Queue_char(int x) {
        max_size = x;
        arr = new char[max_size];
        front = -1;
        rear=-1;
    }
    bool isEmpty(){
        return (front==-1 || front>rear);
    }
    bool isFull(){
        return (rear==max_size-1);
    }
    void enqueue(int n){
        if(!isFull()){
            if(rear==-1 && front==-1){
                rear=0;
                front=0;
            }
            else{
                rear++;
            }
            arr[rear]=n;
        }
    }
    int peek(){
        if(!isEmpty()){
            //cout<<arr[front];
            return arr[front];
        }
    }
    void dequeue(){
        if(!isEmpty()){
            front=front+1;
        }
        else{
            cout<<"Stack is empty.";
        }
    }
    void display(){
        if(!isEmpty()){
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};
//QUESTION 1
/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek()*/
/*int main(){
    Queue_int s(10);
    s.enqueue(3);
    s.peek();
    cout<<endl;
    s.enqueue(8);
    s.enqueue(19);
    s.dequeue();
    s.display();
    cout<<endl;
    s.enqueue(66);
    s.peek();
    cout<<endl;
    s.enqueue(10);
    s.peek();
    cout<<endl;
    s.dequeue();
    s.enqueue(24);
    s.display();
    return 0;
}*/
class queue_circle{
    public:
    int max_size;   
    int curr_size=0;
    int *arr;      
    int front; 
    int rear;       
    queue_circle(int x) {
        max_size = x;
        arr = new int[max_size];
        front = -1;
        rear=-1;
    }
    bool isEmpty(){
        return (front==-1 || curr_size==0);
    }
    bool isFull(){
        return (curr_size==max_size);
    }
    void enqueue(int n){
        if(!isFull()){
            curr_size++;
            if(rear==-1 && front==-1){
                rear=0;
                front=0;
            }
            else{
                rear=(rear+1)%max_size;
            }
            arr[rear]=n;
        }
    }
    int peek(){
        if(!isEmpty()){
            cout<<arr[front];
            return arr[front];
        }
    }
    void dequeue(){
        if(rear==front){
            rear=-1;
            front=-1;
        }
        if (!isEmpty()) {
        curr_size--;
        if(curr_size==0){
            front=rear=-1;
        }else{
            front=(front+1)%max_size;
        }
    } else {
        cout << "queue is empty.\n";
    }
    }
    void display(){
        if (!isEmpty()) {
             int i=front;
             while(true) {
                    cout<<arr[i]<< " ";
                    if(i==rear)break;
                    i=(i+1)%max_size;
                }
            cout<<endl;
        } 
        else{
             cout<<"Queue is empty.\n";
        }
    }
};
//QUESTION 2
/*int main(){
    queue_circle q(3);
    q.enqueue(1);
    q.peek();
    cout<<endl;
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout<<endl;
    q.dequeue();
    q.peek();
    cout<<endl; 
    q.enqueue(100);
    q.display();
    return 0;
}*/
class c_queue{
    public:
    int max_size;   
    int *arr;      
    int front;
    int rear;        
    c_queue(int x) {
        max_size = x;
        arr = new int[max_size];
        front= -1;
        rear=-1;
    }
    bool isfull(){
        return front==(rear+1)%max_size;
    }
    bool isempty(){
        return (front==-1);
    }
    void enqueue(int n){
        if(isempty()){
            front=0;
            rear=0;
            arr[rear]=n;
        }
        else{
            rear=(rear+1)%max_size;
            arr[rear]=n;
        }
    }
    void dequeue(){
        if(rear==front){
            rear=-1;
            front=-1;
        }
        if(!isempty()){
            front=(front+1)%max_size;
        }
    }
    int peek(){
        if(!isempty()){
            cout<<arr[front];
        }
    }
    void disp(){
        int i=front;
        while(true){
            cout<<arr[i]<<" ";
            if(i>rear)break;
            i++;
        }
    }
};
class create_deque{
    public:
    int max_size;   
    int *arr;      
    int front;
    int rear;        
    create_deque(int x){
        max_size = x;
        arr = new int[max_size];
        front= -1;
        rear=-1;
    }
    bool isfull(){
        return front==(rear+1)%max_size;
    }
    bool isempty(){
        return front==-1;
    }
    void insert_rear(int n){
        if(isfull()){
            cout<<"queue is full.";
        }
        else if(isempty()){
            front=0;
            rear=0;
            arr[rear]=n;
        }
        else{
            rear=(rear+1)%max_size;
            arr[rear]=n;
        }
    }
    void insert_front(int n){
        if(isfull()){
            cout<<"queue is full.";
        }
        else if(front==0){
            front=max_size-1;
            arr[front]=n;
        }
        else if(front ==-1 && rear==-1){
            front=rear=0;
            arr[front]=n;
        }
        else{
            front--;
            arr[front]=n;
        }
    }
    void delete_front(){
        if(rear==front){
            rear=-1;
            front=-1;
        }
        else if(!isempty()){
            front=(front+1)%max_size;
        }
    }
    void delete_rear(){
        if(isempty()){
            cout<<"queue is empty";
        }
        else if(front == rear){ 
            front = rear = -1;
        }
        else if(rear==0){
            rear=max_size-1;
        }
        else{
            rear--;
        }
    }
    void display(){
        if(isempty()){
            cout<<"queue is empty.";
        }
        else{
            int i=front;
            while(true){
                cout<<arr[i]<<" ";
                if(i==rear)break;
                i=(i+1)%max_size;
            }
            cout<<"\n";
        }
    }
};
/*int main(){
    create_deque dq(5);

    dq.insert_rear(10);
    dq.insert_rear(20);
    dq.insert_front(5);
    dq.display();   // 5 10 20

    dq.delete_front();
    dq.display();   // 10 20

    dq.delete_rear();
    dq.display(); 
    return 0;
}*/
//QUESTION 3:
/*Write a program interleave the first half of the queue
 with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9*/
/*int main(){
    Queue_int q1(10);
    Queue_int q2(10);
    int arr[]={4,7,11,20,5,9};
    int n=6;
    for(int i=0;i<n/2;i++){
        q1.enqueue(arr[i]);
    }
    for(int i=0;i<n/2;i++){
        q2.enqueue(arr[i+n/2]);
    }
    int i=0;
    while(!q1.isEmpty()){
        arr[i]=q1.peek();
        q1.dequeue();
        i++;
        arr[i]=q2.peek();
        q2.dequeue();
        i++;
    }
    display(arr,n);
    return 0;
}*/
//QUESTION 4:
/*Write a program to find first non-repeating character
 in a string using Queue. Sample I/P: a a
b c Sample O/P: a -1 b b
*/
/*int main(){
    char arr[]={'A','A','B','C'};
    int n=4;
    Queue_char q(10);
    int freq[90]={0};
    for(int i=0;i<n;i++){
        freq[int(arr[i])]++; 
        q.enqueue(arr[i]); 
        while(!q.isEmpty() && freq[int(q.peek())]>1){
            q.dequeue();
        }
        if(q.isEmpty()){
            cout<<-1<<" ";
        }
        else{
            cout<<char(q.peek())<<" ";
        }
        
    }
    return 0;
}*/
//QUESTION 5:
/* Write a program to implement a stack using
(a) Two queues and (b) One Queue.*/
//PART [b]:
class stack_queue1{
    public:
    int max_size;   
    int *arr;      
    int front;
    int rear;        
    stack_queue1(int x){
        max_size = x;
        arr = new int[max_size];
        front= -1;
        rear=-1;
    }
    bool isfull(){
        return rear==max_size-1;
    }
    bool isempty(){
        return front==-1;
    }
    void insert_rear(int n){
        if(isfull()){
            cout<<"queue is full.";
        }
        else if(isempty()){
            front=0;
            rear=0;
            arr[rear]=n;
        }
        else{
            rear++;
            arr[rear]=n;
        }
    }
    void delete_rear(){
        if(isempty()){
            cout<<"queue is empty";
        }
        else if(rear==0){
            front=rear=-1;
        }
        else{
            rear--;
        }
    }
    int show_rear(){
        if(!isempty()){
            cout<<arr[rear];
            return arr[rear];
        }
    }
    void display(){
        if(isempty()){
            cout<<"queue is empty.";
        }
        else{
            int i=rear;
            while(i>=front){
                cout<<arr[i]<<" ";
                i--;
            }
            cout<<"\n";
        }
    }
};
/*int main(){
    stack_queue1 s(5);
    s.insert_rear(10);
    s.show_rear();
    cout<<endl;
    s.insert_rear(20);
    s.display();
    cout<<endl;
    s.delete_rear();
    s.show_rear();
    cout<<endl;
    s.insert_rear(30);
    s.show_rear();
    cout<<endl;
    s.insert_rear(40);
    s.delete_rear();
    s.display();
    return 0;
}*/
//PART[a]
class stack_queue2 {
    Queue_int q1, q2;
public:
    stack_queue2(int size=10) : q1(size), q2(size) {}
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        Queue_int temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() {
        if (!q1.isEmpty())
            q1.dequeue();
        else
            cout << "Stack empty!" << endl;
    }
    int top() {
        if (!q1.isEmpty())
            return q1.peek();
        return -1;
    }
    void display() {
        q1.display();
    }
};
/*int main() {
    stack_queue2 s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<endl;
    cout <<s.top() << endl;
    s.pop();
    cout <<s.top() << endl;
    return 0;
}*/
//ADITIONAL QUESTIONS:
//QUESTION2 :
/*Given a queue with random elements, we need to sort it. 
We are not allowed to use extra space. The
operations allowed on queue are:
1. enqueue() : Adds an item to rear of queue.
2. dequeue() : Removes an item from front of q
3. isEmpty() : Checks if a queue is empty*/
/*int main(){
    int arr[]={11,5,4,21};
    int n=4;
    Queue_int q(10);
    for(int i=0;i<n;i++){
        q.enqueue(arr[i]);
    }
    q.display();
    cout<<endl;
    for(int i=0;i<n;i++){
        int mini=INT16_MAX;
        for (int j=0; j<n; j++){
            int x=q.peek();
            q.dequeue();
            if(j < n-i) mini = min(mini,x);
            q.enqueue(x);
}
        for(int k=0;k<n;k++){
            int y=q.peek();
            q.dequeue();
            if(y==mini)continue;
            else{
                q.enqueue(y);
            }
        }
        q.enqueue(mini);
    }
    q.display();
    return 0;
}*/
class Stack_int{
    public:
    int max_size;   
    int *arr;      
    int top;        
    Stack_int(int x) {
        max_size = x;
        arr = new int[max_size];
        top = -1;
    }
    bool isEmpty(){
        bool flag=false;
        if(top==-1)flag=true;
        return flag;
    }
    bool isFull(){
        bool flag=false;
        if(top==max_size-1)flag=true;
        return flag;
    }
    void push(int n){
        if(!isFull()){
            top=top+1;
            arr[top]=n;
        }
    }
    int peek(){
        if(!isEmpty()){
            //cout<<arr[top];
            return arr[top];
        }
    }
    void pop(){
        if(!isEmpty()){
            top=top-1;
        }
        else{
            cout<<"Stack is empty.";
        }
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
    int getmin(){
        int ans=INT16_MAX;
        for(int i=0;i<=top;i++){
            ans=min(arr[i],ans);
        }
        return ans;
    }
};
//QUESTION 3:
/*Given a Queue consisting of first n natural numbers 
(in random order). The task is to check whether
the given Queue elements can be arranged in increasing order 
in another Queue using a stack. The
operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in the another Queue.*/
/*int main(){
    int arr[]= { 5, 1, 2, 3, 4 }  ;
    int n=5;
    Queue_int q1(10);
    Queue_int q2(10);
    for(int i=0;i<n;i++){
        q1.enqueue(arr[i]);
    }
    Stack_int s(10);
    int exp=1;
    for(int i=0;i<n;i++){
        if(arr[i]==exp){
            q2.enqueue(q1.peek());
            q1.dequeue();
            exp++;
        }
        else{
            s.push(q1.peek());
            q1.dequeue();
        }
    }
    bool possible=true;
    while(!s.isEmpty()){
        int prev=s.peek();
        q2.enqueue(prev);
        s.pop();
        if(!s.isEmpty() && prev-s.peek()==1){
            possible=false;
            break;
        }
    }
    if(possible){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}*/

//QUESTION 4:
/*Number of Students Unable to Eat Lunch*/
/*int main(){
    int arr[]={1,1,0,0};
    int brr[]={0,1,0,1};
    int n=4;
    Queue_int q1(20); //student
    Queue_int q2(20); //sandwich 
    for(int i=0;i<n;i++){
        q1.enqueue(arr[i]);
        q2.enqueue(brr[i]);
    }
    int count=0;
    int rotation=0;
    while(!q2.isEmpty() && !q2.isEmpty()){
        if(q1.peek()==q2.peek()){
            count++;
            q1.dequeue();
            q2.dequeue();
            rotation=0;
        }
        else{
            q1.enqueue(q1.peek());
            q1.dequeue();
            rotation++;
        }
        if(rotation==q1.size())break;
    }
    cout<<n-count;
    return 0;
}*/

//QUESTION 1
/*Given a function n, write a function that generates and
 prints all binary numbers with decimal
values from 1 to n.*/
#include <queue>
int main(){
    int n=5;
    queue<string> q;
    q.push("1");
    int count=0;
    while(count<n){
        string s1=(q.front());
        q.pop();
        cout<<s1<<endl;
        string s2=s1;
        s1.append("0");
        q.push(s1);
        s2.append(s2);
        q.push(s2);
        count++;
    }
}