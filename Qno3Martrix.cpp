//You are given an m x n integer matrix matrix with the following two properties:
//Each row is sorted in non-decreasing order.
//The first integer of each row is greater than the last integer of the previous row.
//Given an integer target , return true if target is in matrix or false otherwise.
//You must write a solution in O(log(m * n)) time complexity.
#include<iostream>
#include<vector>
using namespace std;

bool FindElement(vector<int>& v,int target){
    int n=v.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
         int mid=(lo+hi)/2;
        if(v[mid]==target) {     // Finding the target 
        return true;
        }
        else if (v[mid]<target) hi=mid-1;
        else  lo=mid+1;
     
    }
    return false;
}

int main(){
        int rows, cols;

    // Get the number of rows and columns from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Declare a 2D vector (matrix) with the given dimensions
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Taking input from the user for each element
    cout << "Enter the elements of the matrix: "<<endl;;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter the target: " <<endl;
    cin>>target;
    bool found=false;
    for(int i=0;i<matrix.size();i++){
          if(FindElement(matrix[i],target)){
            found=true;
            break;
          }
    }
    if(found==true) cout<<" Elment is Present";// Here we can use return true;
    else cout<<" Element is Not present";  // Here we can use return false; but for better readablity we use presetn or not 

    return 0;
}