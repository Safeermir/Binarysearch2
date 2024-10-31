//Write a program to apply binary search in array sorted in decreasing order.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> v;
    cout<<"Enter the "<<n<<" elements of the array (In sorted order(Decreasing)): ";
    for(int i=0;i<n;i++){ // Taking input from user 
        int x;     
        cin>>x;
        v.push_back(x);
    }
    int target;
    cout<<"Enter the element to be search: ";
    cin>>target;
     int hi=n-1;// Initializing two pointers
     int lo=0;
     bool flag=false;
     int idx=-1;
     while(lo<=hi){
        int mid=(lo+hi)/2;
        if(v[mid]==target) {     // Finding the target 
            flag=true;
            idx=mid;
            break;
        }
        else if (v[mid]<target) hi=mid-1;
        else  lo=mid+1;
     }
     if(flag==true){
        cout<<" Element is Present at index : "<<idx;;
     }
     else cout<<" Element is Not Present in the Array..?";
     return 0;

}