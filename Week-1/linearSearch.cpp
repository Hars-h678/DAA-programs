#include<iostream>
#include<vector>
using namespace std;
void search(vector<int>&arr,int key){
    int n = arr.size();\
    bool flag=false;
    int cmp=0;
    for(int i=0;i<n;i++) {
        cmp++;
        if(arr[i]==key) {
        cout<<"element present"<<endl;
        flag=true;
        break;
    }
}
    if(!flag) {
        cout<<"elemnt not present";
        return ;
    }
    cout<<"total comparison: "<<cmp;
}
int main(){
    int n ;
    cout<<"enter the size of vector :";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;
    cout<<"enter the element to search: ";
    cin>>key;
    search(arr,key);
    return 0;
}