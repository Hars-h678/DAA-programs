// Given a sorted array of positive integers containing few duplicate
// elements, design an algorithm and implement it using a program to find
// whether the given key element is present in the array or not. If present,
// then also find the number of copies of given key. (Time Complexity =
// O(log n))
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int occurence(vector<int>&arr,int key){
    int n = arr.size();
    int count=-1;
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==key){ 
            cout<<"element found";
            count++;
            break;
    }
        else if(arr[mid]>key) hi=mid-1;
        else lo=mid+1;
    }
   if(count==-1) return -1;
   lo=0;
   hi=n-1;
   int lb=0;
   while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==key){ 
            lb=mid;
            hi=mid-1;
    }
        else lo=mid+1;
    }
    lo=0;
   hi=n-1;
   int ub=0;
   while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==key){ 
            ub=mid;
            lo=mid+1;
    }
        else hi=mid-1;
    }
    return ub-lb+1;
}
int main(){
    int n ;
    cout<<"enter the size of an array : ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int key;
    cout<<"enter the element to check ";
    cin>>key;
    cout<<"<----(-1) represent that element is not present------>"<<endl;
    cout<<"occurence of present element "<<occurence(arr,key);
}