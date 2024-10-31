//There is an integer array nums sorted in non-decreasing order (not necessarily with
//distinct values).
//Before being passed to your function, nums is rotated at an unknown pivot index k ( 0 <= k
//< nums.length ) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1],
//nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example,
//[0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become
//[4,5,6,6,7,0,1,2,4,4] .
//Given the array nums after the rotation and an integer target , return true if target is in
//nums , or false if it is not in nums .

#include<iostream>
#include<vector>
using namespace std;
 bool search(vector<int>& nums, int target) {
       int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(target==nums[lo])return true;
            if(target==nums[hi])return true;
            else if(nums[lo] == nums[hi]){
                lo++;
                hi--;
            }
            // if mid is right side of the pivot
            else if(nums[mid]>nums[n-1]){
                if(target == nums[mid]){
                    return true;
                    break;
                }
                else if( target>=nums[lo] && target < nums[mid]){
                    //
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            else{ // if mid is mid is left side of the pivot
                if(target == nums[mid]){
                    return true;
                    break;
                }
                // if target lie between mid and hi
                else if(target>nums[mid] && target <= nums[hi]){
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
        }
        return false;
        
    }
int main(){
    vector<int> v={5,6,1,2,3,4}; // assume array is rotated here by 2 steps
    int target=3;
     if(search(v,target)) cout<<"Target found";
     else cout<<"Target not found";
     return 0;

}