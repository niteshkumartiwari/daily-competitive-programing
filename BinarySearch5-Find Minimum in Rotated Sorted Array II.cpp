/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {  //O(n) worst case
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                r--;
        }

        return nums[l];
    }
};

int main() {
    return 0;
}
