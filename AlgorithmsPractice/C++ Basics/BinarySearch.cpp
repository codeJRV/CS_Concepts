#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
if(nums.size() == 0)
    return 0;

  int left = 0, right = nums.size() - 1;int mid;
  while(left <= right){
    // Prevent (left + right) overflow
    mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  if(target > nums[mid])
      return mid+1;
  else
      return mid;
    }
};