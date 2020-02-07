/*
Given a binary tree where every node has a unique value, and a target key k, find the closest leaf node to target k in the tree.
A node is called a leaf if it has no children.
In the following examples, the input tree is represented in flattened form row by row. The actual roottree given will be a TreeNode object.

root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is closest to the node with value 2.
Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.
*/

#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;

// The problem is transformed into finding the shortest path from the starting node to any leaf node in an undirected / equal-weighted graph.

//TO-DO CODE

int main(){

    return 0;
}