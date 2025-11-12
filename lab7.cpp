#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
//SORTING:
/*1. Write a program to implement following sorting techniques:
a. Selection Sort
b. Insertion Sort
c. Bubble Sort
d. Merge Sort
e. Quick Sort*/
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int small=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[small]){
                small=j;
            }
        }
        swap(arr[i],arr[small]);
    }
    print(arr,n);
}
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key; 
    }
    print(arr, n);
}
void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
    print(arr,n);
}
void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
void merge_sort(int arr[],int low,int high){
    if(low==high || low>high)return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int quick2(int arr[],int low,int high){
    int p=arr[high];
    int i=low-1;
    for(int j=low;j<high-1;j++){
        if(arr[j]<=p){
            i=i+1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quick_sort(int arr[],int low,int high){
    if(low==high || low>high){
        return ;
    }
    int mid=(low+high)/2;
    int pivot=quick2(arr,low,high);
    quick_sort(arr,low,pivot-1);
    quick_sort(arr,pivot+1,high);
}
void count_sort(int arr[],int n){
    int maxi=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    int temp[maxi+1]={0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    /*for(int i=0;i<=maxi;i++){
        int a=temp[i];
        while(a>0){
            cout<<i<<" ";
            a--;
        }
    }*/
    for(int i=1;i<=maxi;i++){
        temp[i]=temp[i]+temp[i-1];
    }
    int final[n]={0};
    for(int i=n-1;i>=0;i--){
        final[temp[arr[i]]-1]=arr[i];
        temp[arr[i]]--;
    }
    print(final,n);
}
void radix_sort(int arr[],int n){
    int maxi=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    int temp[n]={0};
    for(int pos=1;maxi/pos>0;pos*=10){
        int count[10]={0};
        for(int i=0;i<n;i++){
            count[(arr[i]/pos)%10]++;
        }
        for(int i=1;i<10;i++){
            count[i]=count[i]+count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            temp[count[(arr[i]/pos)%10]-1]=arr[i];
            count[(arr[i]/pos)%10]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
    }
    print(arr,n);
}
int main(){
    int arr[]={1,4,3,5,2};
    int n=5;
    selection_sort(arr,n);
}