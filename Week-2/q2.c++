// Given a sorted array of positive integers, design an algorithm
// and implement it using a program to find three indices i, j, k such that
// arrli] + arr[j] = arr[k].
#include<iostream>
#include<vector>
using namespace std;
void check(vector<int>&arr,int key){
   int n =arr.size();
   //use two pointer approach
   int i=0;
   int j=n-1;
   while(i<=j){
    if(arr[i]+arr[j]==key) {
        cout<<i<<" "<<j;
        return;
    }
    else if(arr[i]+arr[j]>key) j--;
    else i++;
   }
}
int main(){
    int n ;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int target;
    cout<<"enter the target";
    cin>>target;
    check(arr,target);
    return 0;
}