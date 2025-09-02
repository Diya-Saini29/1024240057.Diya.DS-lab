#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
using namespace std;
void display(int arr[],int cur_size){
    cout<<"Array display : "<<endl;
    for(int i=0;i<cur_size;i++){
        cout<<arr[i]<<" ";
    }
}
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
class Stack_char{
    public:
    int max_size;   
    char *arr;      
    int top;        
    Stack_char(int x) {
        max_size = x;
        arr = new char[max_size];
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
    void push(char n){
        if(!isFull()){
            top=top+1;
            arr[top]=n;
        }
    }
    char peek(){
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
};
//QUESTION 1:
/*Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().*/
/*int main(){
    Stack_int s(10);
    s.push(3);
    s.peek();
    cout<<endl;
    s.push(8);
    s.push(19);
    s.pop();
    s.display();
    cout<<endl;
    s.push(66);
    s.peek();
    cout<<endl;
    s.push(10);
    s.peek();
    cout<<endl;
    s.pop();
    s.push(24);
    s.display();
    return 0;
}*/
//QUESTION 2:
/*. Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.”
*/
/*int main(){
    Stack s(20);
    for(int i=0;i<13;i++){
        char ch;
        cout<<"enter : "<<endl;
        cin>>ch;
        s.push(ch);
    }
    for(int i=12;i>=0;i--){
        s.peek();
        s.pop();
    }
    return 0;
}*/
//QUESTION 3:
/*Write a program that checks if an expression has balanced parentheses.*/
/*int main(){
    Stack_char s(20);
    int n=6;
    char ch[n]={'(',')','[','{','}',']'};
    int count=0;
    if(n%2!=0)cout<<"not balanced";
    else{
        for(int i=0;i<n;i++){
            s.push(ch[i]);
            if((ch[i]==')' || ch[i]==']' || ch[i]=='}') && !s.isEmpty()){
                char ans=s.peek();
                s.pop();
                if(ans==')' && s.peek()=='('){
                    count++;
                }
                else if(ans==']' && s.peek()=='['){
                    count++;
                }
                else if(ans=='}' && s.peek()=='{'){
                    count++;
                }
                s.pop();
            }
        }
    }
    if(count==n/2)cout<<"yes";
    else{cout<<"no";};
    return 0;
}*/
//QUESTION 4:
/*Write a program to convert an Infix expression into a Postfix expression.
*/
/*int priority(char ch){
    int level=0;
    if(ch=='*' || ch=='/'){
        level=2;
    }
    else if(ch=='+' || ch=='-'){
        level=1;
    }
    else if(ch=='^'){
        level=3;
    }
    return level;
}
void Infixtopostfix(char arr[],int n){
    int i=0;
    Stack_char s(25);
    char ans[n]={};
    int k=0;
    while(i<n){
        if((arr[i]>='A' && arr[i]<='Z') || (arr[i]>='a' && arr[i]<='z')){
            ans[k++]=arr[i];
        }
        else if(arr[i]=='('){
            s.push(arr[i]);
        }
        else if(arr[i]==')'){
            while(s.peek()!='('){
                char a=s.peek();
                s.pop();
                ans[k++]=a;
            }
            s.pop();
        }
        else{
            if(!s.isEmpty() && priority(arr[i])>priority(s.peek())){
                s.push(arr[i]);
            }
            else{
                while(!s.isEmpty() && priority(arr[i])<=priority(s.peek())){
                    ans[k++]=s.peek();
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
        i++;
    }
    while(!s.isEmpty()){
        ans[k++]=s.peek();
        s.pop();
    }
    ans[k] = '\0'; //cout knows how to print C-style strings (char[] terminated with '\0').It starts printing from ans[0], keeps going until it sees '\0', then stops.
    cout<<ans<<endl;
}
int main(){
    int n=7;
    char arr[n]={'(','A','+','B',')','*','C','\0'};
    Infixtopostfix(arr, n);
    return 0;
}*/
//QUESTION 5:
/*Write a program for the evaluation of a Postfix expression*/
/*int evaluate(char arr[], int n) {
    Stack_int s(25);
    for (int i=0;i<n;i++) {
        char c=arr[i];
        if (c>='0' && c<='9') {
            s.push(c - '0');//conversion from char to int. example-->'3' - '0' = 51 - 48 = 3
        }
        else {
            int val2 = s.peek(); s.pop();
            int val1 = s.peek(); s.pop();
            int result = 0;
                if(c=='+')result = val1 + val2;
                else if(c=='-')result = val1 - val2;
                else if(c=='*')result = val1 * val2;
                else if(c=='/')result = val1 / val2;
            s.push(result);
        }
    }
    return s.peek();
}
int main() {
    char arr[] = "23*54*+9-";
    int n=sizeof(arr)-1;
    int result=evaluate(arr, n);
    cout<<"Result = "<<result<<endl;
}
*/
//-----------------ADDITIONAL QUESTIONS------------
//QUESTION 1:
/*Given an array A, find the nearest smaller element for every element A[i] in the array such that the
element has an index smaller than i.*/
/*int main(){
    int arr[]={4,5,2,0,1,8};
    int n=6;
    Stack_int s(25);
    int ans[n]={0};
    for(int i=0;i<n;i++){
        while(!s.isEmpty() && s.peek()>=arr[i]){
            s.pop();
        }
        if(s.isEmpty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.peek();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}*/
//QUESTION 2:
/* Design a stack that supports getMin() in O(1) time and O(1) extra space*/
/*int main(){
    Stack_int s(20);
    s.push(2);
    s.push(3);
    s.peek();
    s.pop();
    int a=s.getmin();
    cout<<a<<endl;
    s.push(1);
    int b=s.getmin();
    cout<<b<<endl;
    return 0;
}*/
//QUESTION 3:
/*Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the
array in order of their appearance in the array. Note: The Next Greater Element for an element x is
the first greater element on the right side of x in the array. Elements for which no greater element
exist, consider the next greater element as -1.*/
/*int main(){
    int arr[]={5,2,7,4,9,1};
    int n=6;
    Stack_int s(25);
    int ans[n]={0};
    for(int i=n-1;i>=0;i--){
        while(!s.isEmpty() && s.peek()<=arr[i]){
            s.pop();
        }
        if(s.isEmpty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.peek();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}*/
//QUESTION 4:
/*Given an array of integers temperatures represents the daily temperatures, return an
array answer such that answer[i] is the number of days you have to wait after the ith day to get a
warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
/*int index(int n,int size,int arr[]){
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            return i;
        }
    }
}
int main(){
    int arr[]={73,74,75,71,69,72,76,73};
    int n=8;
    int ans[8]={0};
    Stack_int s(20);
    for(int i=n-1;i>=0;i--){
        while(!s.isEmpty() && s.peek()<=arr[i]){
            s.pop();
        }
        if(s.isEmpty()){
            ans[i]=0;
        }
        else{
            ans[i]=index(s.peek(),n,arr)-i;
        }
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}*/
//QUESTION 5:
