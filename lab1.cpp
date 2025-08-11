#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
using namespace std;

//QUESTION 1
void display(int arr[],int cur_size){
    cout<<"Array display : "<<endl;
    for(int i=0;i<cur_size;i++){
        cout<<arr[i]<<" ";
    }
}
void create(int arr[],int cur_size){
    cout<<"Array creation"<<endl;
    for(int i=0;i<cur_size;i++){
        cout<<"enter value: ";
        cin>>arr[i];
    }
    display(arr,cur_size);
}
int insert(int arr[],int cur_size,int insert_pos,int insert_value){
    create(arr,cur_size);
    cout<<"Value insertion :"<<endl;
    for(int i=cur_size-1;i>=insert_pos;i--){
        arr[i]=arr[i+1];
    }
    arr[insert_pos-1]=insert_value;
    cur_size++;
    display(arr,cur_size);
    return cur_size;
}
int remove(int arr[],int cur_size,int remove_pos){
    create(arr,cur_size);
    cout<<"Value removal :"<<endl;
    for(int i=remove_pos-1;i<cur_size-1;i++){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    cur_size--;
    display(arr,cur_size);
    return cur_size;
}
void search(int arr[],int cur_size,int search_value){
    cout<<"Value search :"<<endl;
    for(int i=0;i<cur_size;i++){
        if(arr[i]==search_value){
            cout<<"Found "<<search_value<<" at position "<<i+1;
            break;
        }
    }
}
//QUESTION 1
/*int main(){
    int max_size=10,cur_size=5;
    int arr[max_size];
    int insert_pos=3,insert_value=100;
    int remove_pos=2;
    int search_value=3;
    cout<<"In the MENU. Select operation number. ";
    int opr;
    cin>>opr;
    if(opr==1)create(arr,cur_size);
    else if(opr==2)display(arr,cur_size);
    else if(opr==3)cur_size=insert(arr,cur_size,insert_pos,insert_value);
    else if(opr==4)cur_size=remove(arr,cur_size,remove_pos);
    else if(opr==5)search(arr,cur_size,search_value);
    else{cout<<"EXIT";}
    return 0;
}*/
//QUESTION 2
/*int duplicate(int arr[],int maxsize,int cur_size){
    for(int i=0;i<cur_size-1;i++){
        for(int j=i+1;j<cur_size;j++){
            if(arr[i]==arr[j]){
                cur_size=remove(arr,cur_size,j+1);
                j--;
            }
        }
    }
    return cur_size;
}
int main(){
    int maxsize=10;
    int arr[]={3,3,6,3,7};
    int cur_size=5;
    cur_size=duplicate(arr,maxsize,cur_size);
    display(arr,cur_size);
    return 0;
}*/
//QUESTION 3
/* 
output is : 1000
*/
//QUESTION 4(1)
void reverse(int arr[],int cur_size){
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
//QUESTION 4(1)
/*int main(){
    int cur_size=5;
    int arr[10]={1,2,3,4,5};
    reverse(arr,cur_size);
    display(arr,cur_size);
    return 0;
}*/
//QUESTION 4(3)
void transpose(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j>i){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
}
void matrix_display(int arr[][2],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}
/*int main(){
    int row=3,col=3;
    int arr[row][col]={1,2,3,4,5,6,7,8,9};
    transpose(arr,row,col);
    matrix_display(arr,row,col);
    return 0;
}*/
//QUESTION 4(2)
void matrix_multi(int ans[][2],int arr1[][2],int arr2[][2],int row1,int col1,int row2,int col2){
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            ans[i][j]=0;
            for (int k = 0; k < col1; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}
/*int main(){
    int row1=1,col1=2;
    int row2=2,col2=2;
    int arr1[1][2]={0,1};
    int arr2[2][2]={1,0,1,1};
    int ans[1][2]={};
    matrix_multi(ans,arr1,arr2,row1,col1,row2,col2);
    matrix_display(ans,row1,col2);
    return 0;
}*/
//QUESTION 5
/*int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    std::vector<int> ans;
    int sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum=sum+arr[i][j];
        }
        ans.push_back(sum);
        sum=0;
    }
    int sum2=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum2=sum2+arr[j][i];
        }
        ans.push_back(sum2);
        sum2=0;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}*/

