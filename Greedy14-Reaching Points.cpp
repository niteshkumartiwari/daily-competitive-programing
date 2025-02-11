/*
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True

Note:

sx, sy, tx, ty will all be integers in the range [1, 10^9].
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }

        return (sx == tx && sy <= ty && (ty - sy) % sx == 0) ||
               (sy == ty && sx <= tx && (tx - sx) % sy == 0);
    }
};

int main() {
    return 0;
}

/*
Basic idea:
If we start from sx,sy, it will be hard to find tx, ty.
If we start from tx,ty, we can find only one path to go back to sx, sy.
I cut down one by one at first and I got TLE. So I came up with remainder.

First line:
if 2 target points are still bigger than 2 starting point, we reduce target points.
Second line:
check if we reduce target points to (x, y+kx) or (x+ky, y)

Time complexity
I will say O(logN) where N = max(tx,ty).
*/
