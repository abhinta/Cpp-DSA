/*
LCA of Binary Tree
Send Feedback
Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.
Input format :
Line 1 :  Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)
Output Format :
LCA
Constraints :
1 <= N <= 1000
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
Sample Output 1:
10
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78
Sample Output 3:
-1
*/

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root == NULL)
        return -1;
    if(root->data == a || root->data == b)
        return root->data;
        /*return (root->data == a?a:b);*/
    int leftAns = getLCA(root->left, a, b);
    int rightAns = getLCA(root->right, a, b);
    if(leftAns == -1 || rightAns == -1)
        return leftAns + rightAns + 1;
    else
        return root->data;
    /*
    if(leftAns == -1)
        return rightAns;
    else if(rightAns == -1)
        return leftAns;
    else
        return root->data;
    */
}

// more conditions
int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    // Write your code here
	if(root==NULL)
        return -1;
    if(root->data==val1 || root->data==val2)
        return root->data;
    int left = lcaBinaryTree(root->left,val1,val2);
    int right = lcaBinaryTree(root->right,val1,val2);
    
    if(left==-1 && right==-1)
        return -1;
    
    if(left==-1 || right==-1)//both val1,val2 are in same subtree
        return right+(left+1);//say left goves ans=-1 then return value must be right
    
    else{//both val1,val2 are in different subtree wrt root
        return root->data;
    }   
}
