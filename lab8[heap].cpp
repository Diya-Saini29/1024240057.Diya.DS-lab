#include<iostream>
#include <string.h>
#include<bits/stdc++.h>
#include <algorithm>
#include<vector>
#include <cmath>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void build_max_heap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heap_sort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void min_heap(int arr[],int n,int i){
    int small=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]<arr[small]){
        small=left;
    }
    if(right<n && arr[right]<arr[small]){
        small=right;
    }
    if(small!=i){
        swap(arr[i],arr[small]);
        min_heap(arr,n,small);
    }
}
void bulit_priority(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        min_heap(arr,n,i);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[10]={2,1,3,4,5};
    int n=5;
    build_max_heap(arr,n);
    print(arr,n);
    heap_sort(arr,n);
    print(arr,n);
    return 0;
}