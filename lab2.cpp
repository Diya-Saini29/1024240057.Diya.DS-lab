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
//BINARY SEARCH:
int binary_search(int arr[],int n,int start,int end,int target){
    int result=0;
    int mid=(start+end)/2;
    while(start<end){
        if(arr[mid]==target){
            result=mid+1;
        }
        else if(arr[mid]<target){
            mid++;
        }
        else{
            mid--;
        }
        start++;
        end--;
    }
    return result;
}
//QUESTION 1:
/*int main(){
    int n=5;
    int arr[]={0,1,2,4,6};
    int start=0;
    int end=n-1;
    int target=4;
    int answer=binary_search(arr,n,start,end,target);
    cout<<"Value found at : "<<answer;
    return 0;
}*/
//BUBBLE SORT
void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=arr[i];
        bool flag =true;
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            flag=false;
        }
        if(flag==true)break;
    }
}
//QUETION 2:
/*int main(){
    int max_size=10;
    int n=5;
    int arr[]={4,6,2,3,1};
    bubble_sort(arr,n);
    display(arr,n);
    return 0;
}*/
//QUESTION 3:
/*int searching(int arr[],int n){
    int start=0;int end=n;
    int mid=(start+end)/2;
    int missing=0;
    while(mid<=end && mid>=start){
        if(arr[mid]-mid!=1 && arr[mid-1]==mid){
            missing=arr[mid]-1;
            break;
        }
        else{
            if(mid>start)mid--;
        }
    }
    return missing;
}
int main(){
    int arr[10]={1,3,4,5,6};
    int curr_size=5;
    int answer=searching(arr,curr_size);
    cout<<answer;
    return 0;
}*/
//QUESTION 4:
void display_string(char arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//part1
/*void concatenate(char arr[], char brr[], int n,int m){
    for(int i=n;i<n+m;i++){
        arr[i]=brr[i-n];
    }
}
int main(){
    char arr[10]={'c','a','t'};
    int n=3;
    char brr[10]={'d','o','g'};
    int m=3;
    concatenate(arr,brr,n,m);
    display(arr,n+m);
    return 0;
}*/
//part 2
/*void reverse_string(char arr[],int cur_size){
    int start=0;
    int last=cur_size-1;
    while(start<last){
        int temp=arr[start];
        arr[start]=arr[last];
        arr[last]=temp;
        start++;
        last--;
    }
}
int main(){
    char arr[10]={'c','a','t'};
    int n=3;
    reverse_string(arr,n);
    display(arr,n);
    return 0;
}*/
//part 3
/*int vowel_delete(char arr[],int n){
    int size=n;
    for(int i=0;i<n;i++){
        if(arr[i]=='a' ||arr[i]=='e' ||arr[i]=='i' ||arr[i]=='o' ||arr[i]=='u' ){
            for(int j=i+1;j<n;j++){
                swap(arr[i],arr[j]);
                size--;
            }
        }
    }
    return size;
}
int main(){
    char arr[10]={'c','a','t'};
    int n=3;
    int size=vowel_delete(arr,n);
    display_string(arr,size);
    return 0;
}*/
//part 4
/*void sort_string(char arr[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n ; j++) {
            if (arr[i] > arr[j]){
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(){
    char arr[10]={'b','a','t','c','h'};
    int n=5;
    sort_string(arr,n);
    display_string(arr,n);
    return 0;
}*/
//part 5
/*void convert_string(char arr[],int n){
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') { 
            arr[i] = arr[i] + 32; 
        }
    }
}
int main(){
    char arr[10]={'B','A','T','C','H'};
    int n=5;
    convert_string(arr,n);
    display_string(arr,n);
    return 0;
}*/
//QUESTION 5
//part1
/*int main(){
    int arr[3][3]={1,0,0,0,1,0,0,0,1};
    int row=3,col=3;
    int store[10]={0};
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==j){
                store[i]=arr[i][j];
            }
        }
    }
    display(store,3);
    return 0;
}*/
//part2
/*int main(){
    int arr[4][4]={4 ,1 ,0 ,0 ,3 ,5 ,2 ,0 ,0 ,6, 7 ,8 ,0 ,0, 9 ,10};
    int row=4,col=4;
    int n=row+(row-1)*2;
    int store[n]={0};
    int start=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i-j==1 || j-i==1 || i==j){
                store[start]=arr[i][j];
                start++;
            }
        }
    }
    display(store,n);
    return 0;
}*/
//part 3
/*int main(){
    int arr[4][4]={1, 0 ,0 ,0 ,2 ,3 ,0 ,0 ,4 ,5, 6, 0, 7, 8, 9, 10};
    int row=4,col=4;
    int n=row*(row+1)/2;
    int store[n]={0};
    int start=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i>=j){
                store[start]=arr[i][j];
                start++;
            }
        }
    }
    display(store,n);
    return 0;
}*/
//part 4
/*int main(){
    int arr[4][4] = {{1, 2, 3, 4},{0, 5, 6, 7},{0, 0, 8, 9},{0, 0, 0, 10}};
    int row=4,col=4;
    int n=row*(row+1)/2;
    int store[n]={0};
    int start=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j>=i){
                store[start]=arr[i][j];
                start++;
            }
        }
    }
    display(store,n);
    return 0;
}*/
//part 5
/*int main(){
    int arr[4][4] = {{1, 2, 3, 4},{2, 5, 6, 7},{3, 6, 8, 9},{4, 7, 9, 10}};
    int row=4,col=4;
    int n=row*col;
    int store[n]={0};
    int start=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            store[start]=arr[i][j];
            start++;
        }
    }
    display(store,n);
    return 0;
}*/
//QUESTION 6
void display_matrix(int matrix[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int count_elements(int arr[5][5],int row ,int col,int no_value){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0)no_value++;
        }
    }
    return no_value;
}
void sparse_create(int arr[5][5],int matrix[][3],int row,int col){
    int no_value=count_elements(arr,5,5,0);
    matrix[0][0] = row;
    matrix[0][1] = col;
    matrix[0][2] = no_value;
    int start=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                matrix[start][0]=i;
                matrix[start][1]=j;
                matrix[start][2]=arr[i][j];
                start++;
            }
        }
    }
}
//part1
void transpose(int matrix[][3],int row){
    for(int i=1;i<=row;i++){
        swap(matrix[i][0],matrix[i][1]);
    }
}
/*int main(){
    int row=5,col=5;
    int arr[5][5] = {
    {0, 0, 3, 0, 0},
    {0, 0, 0, 0, 5},
    {7, 0, 0, 0, 0},
    {0, 9, 0, 0, 0},
    {0, 0, 0, 6, 0}};
    int no_value=0;
    no_value=count_elements(arr,row,col,no_value);
    int matrix[no_value+1][3];
    sparse_create(arr,matrix,row,col);
    transpose(matrix,no_value);
    display_matrix(matrix,no_value+1,3);
    return 0;
}*/
//part2
/*void addition(int matrix1[][3], int matrix2[][3], int ans[][3]) {
    int n1 = matrix1[0][2];
    int n2 = matrix2[0][2]; 
    int i=1, j=1, k=1;
    while(i<=n1 && j<=n2) {
        if(matrix1[i][0] < matrix2[j][0] || 
          (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] < matrix2[j][1])) {
            ans[k][0] = matrix1[i][0];
            ans[k][1] = matrix1[i][1];
            ans[k][2] = matrix1[i][2];
            i++; k++;
        }
        else if(matrix2[j][0] < matrix1[i][0] ||
               (matrix2[j][0] == matrix1[i][0] && matrix2[j][1] < matrix1[i][1])) {
            ans[k][0] = matrix2[j][0];
            ans[k][1] = matrix2[j][1];
            ans[k][2] = matrix2[j][2];
            j++; k++;
        }
        else { 
            ans[k][0] = matrix1[i][0];
            ans[k][1] = matrix1[i][1];
            ans[k][2] = matrix1[i][2] + matrix2[j][2];
            i++; j++; k++;
        }
    }

    while(i<=n1) {
        ans[k][0] = matrix1[i][0];
        ans[k][1] = matrix1[i][1];
        ans[k][2] = matrix1[i][2];
        i++; k++;
    }
    while(j<=n2) {
        ans[k][0] = matrix2[j][0];
        ans[k][1] = matrix2[j][1];
        ans[k][2] = matrix2[j][2];
        j++; k++;
    }
    ans[0][2] = k-1; 
}
int main(){
    int row1=5,col1=5;
    int arr[5][5] = {
    {0, 0, 0, 4, 0},
    {0, 0, 0, 0, 0},
    {5, 0, 0, 0, 7},
    {0, 8, 0, 0, 0},
    {0, 0, 9, 0, 0}};
    int no_value1=0;
    no_value1=count_elements(arr,row1,col1,no_value1);
    int matrix1[no_value1+1][3];
    sparse_create(arr,matrix1,row1,col1);
    int row2=5,col2=5;
    int brr[5][5] = {
    {0, 0, 3, 0, 0},
    {0, 0, 0, 0, 5},
    {7, 0, 0, 0, 0},
    {0, 9, 0, 0, 0},
    {0, 0, 0, 6, 0}};
    int no_value2=0;
    no_value2=count_elements(brr,row2,col2,no_value2);
    int matrix2[no_value2+1][3];
    sparse_create(brr,matrix2,row2,col2);
    int ans[25][3];
    ans[0][0]=row1,ans[0][1]=col1;
    addition(matrix1,matrix2,ans);
    display_matrix(ans,ans[0][2]+1,3);
    return 0;
}*/
//part3
int matrix_multilpy(int matrix1[][3],int matrix2[][3],int ans[][3]){
    int n1=matrix1[0][2];
    int n2=matrix2[0][2];
    int values=1;
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (matrix1[i][1] == matrix2[j][1]) {  
                int row = matrix1[i][0];
                int col = matrix2[j][0];
                int product = matrix1[i][2] * matrix2[j][2];
                int k;
                for ( k = 1; k < values; k++) {
                    if (ans[k][0] == row && ans[k][1] == col) {
                        ans[k][2] += product;
                        break;
                    }
                }
                if (k == values) {
                    ans[values][0] = row;
                    ans[values][1] = col;
                    ans[values][2] = product;
                    values++;
                }
            }
        }
    }
    return values - 1;
}
/*int main(){
    int row1=5,col1=5;
    int arr[5][5] = {
    {0, 0, 0, 4, 0},
    {0, 0, 0, 0, 0},
    {5, 0, 0, 0, 7},
    {0, 8, 0, 0, 0},
    {0, 0, 9, 0, 0}};
    int no_value1=0;
    no_value1=count_elements(arr,row1,col1,no_value1);
    int matrix1[no_value1+1][3];
    sparse_create(arr,matrix1,row1,col1);
    int row2=5,col2=5;
    int brr[5][5] = {
    {0, 0, 3, 0, 0},
    {0, 0, 0, 0, 5},
    {7, 0, 0, 0, 0},
    {0, 9, 0, 0, 0},
    {0, 0, 0, 6, 0}};
    int no_value2=0;
    no_value2=count_elements(brr,row2,col2,no_value2);
    int matrix2[no_value2+1][3];
    sparse_create(brr,matrix2,row2,col2);
    transpose(matrix2,no_value2);
    int ans[25][3];
    ans[0][0] = matrix1[0][0];
    ans[0][1] = matrix2[0][1];
    ans[0][2]=matrix_multilpy(matrix1,matrix2,ans);
    display_matrix(ans,ans[0][2]+1,3);
    return 0;
}*/
//QUESTION 7
/*int main(){
    int arr[]={1,2,4,3,5,8,7};
    int count=0;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(arr[j]<arr[i])count++;
        }
    }
    cout<<count;
    return 0;
}*/
//QUESTION 8
/*int main(){
    int arr[]={3,1,2,4,1,3,5,2,6,4};
    int hash[10]={0};
    for(int i=0;i<10;i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<10;i++){
        if(hash[i]==1)cout<<i+1<<" ";
    }
    return 0;
}*/