#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>arr;
void binarySearch(int lo,int hi,int key,int count){
    if(lo>hi) {
        cout<<"total comaprioson "<<count<<endl;
        cout<<"elemnt is not found";
        return ;
    }
    int mid=lo+(hi-lo)/2;
    if(arr[mid]==key) {
        cout<<"element is fount"<<endl;
         cout<<"total comaprioson "<<count;
        return;
    }
    if(arr[mid]>key) binarySearch(lo,mid-1,key,count);
    else if(arr[mid]<key) binarySearch(mid+1,hi,key,count);
    count++;
}
int main(){
    int n ;
    cout<<"enter the size of array: ";
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];//
    sort(arr.begin(),arr.end());
    int key;
    cout<<"enter the key: ";
    cin>>key;
    int count=0;
    binarySearch(0,n-1,key,count);
}