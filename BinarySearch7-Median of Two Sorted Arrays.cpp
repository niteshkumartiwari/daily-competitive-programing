/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);  // Make sure A2 is the shorter one.

        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;   // Try Cut 2
            int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly

            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];  // Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

            if (L1 > R2)
                lo = mid2 + 1;  // A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1)
                hi = mid2 - 1;  // A2's lower half too big; need to move C2 left.
            else
                return (max(L1, L2) + min(R1, R2)) / 2;  // Otherwise, that's the right cut.
        }
        return -1;
    }
};

int main() {
    return 0;
}
