#include <bits/stdc++.h>
#include <vector>
using namespace std;
void merge(vector<int>&arr,int i,int j,int k){
    int n=j,m=k+1; // j=mid+1
    int start=i;
    vector<int> temp;
    while (i<n and j<m) {
        if (arr[i]<arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }
    while (i<n) {
        temp.push_back(arr[i++]);
    }
    while (j<m) {
        temp.push_back(arr[j++]);
    }
    for (int i=start; i<=k; i++) {
        arr[i]=temp[i-start];
    }
}
void divide(vector<int>&arr,int i,int j){
    if (i>=j) {
        return;
    }
    int mid=(i+j)/2;
    divide(arr, i, mid);
    divide(arr, mid+1, j);
    merge(arr,i,mid+1,j);
}
int main(){
    vector<int>arr={3,5,2,5,6,2,6,3,8,45,34,23,12};
    int n=arr.size();
    divide(arr, 0, n-1);
    for (auto i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}