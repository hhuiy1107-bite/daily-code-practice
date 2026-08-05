#define  _CRT_SECURE_NO_WARNINGS 1


//中序遍历

//int TreeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void MidOrder(struct TreeNode* root, int* a, int* i)
//{
//    if (root == NULL)
//        return;
//
//    MidOrder(root->left, a, i);
//    a[(*i)++] = root->val;
//    MidOrder(root->right, a, i);
//}
//
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//
//    *returnSize = TreeSize(root);
//    int* re = (int*)malloc(sizeof(int) * (*returnSize));
//    int i = 0;
//    MidOrder(root, re, &i);
//
//    return re;
//}








//另一棵子树

//bool isSameTree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    if (root == NULL && subRoot == NULL)
//        return true;
//
//    if (root == NULL || subRoot == NULL)
//        return false;
//
//    if (root->val != subRoot->val)
//        return false;
//
//    return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
//}
//
//bool _isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    if (root == NULL)
//        return false;
//
//    if (root->val == subRoot->val && isSameTree(root, subRoot))
//    {
//        return true;
//    }
//
//    return _isSubtree(root->left, subRoot)
//        || _isSubtree(root->right, subRoot);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//
//    return _isSubtree(root, subRoot);
//
//}










//二叉树的遍历创建



//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode
//{
//    char val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//}TreeNode;
//
//
//TreeNode* CreatTree(char* a, int* pi)
//{
//    if (a[*pi] == '#')
//    {
//        (*pi)++;
//        return NULL;
//    }
//
//    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//
//    root->val = a[(*pi)++];
//    root->left = CreatTree(a, pi);
//    root->right = CreatTree(a, pi);
//
//    return root;
//}
//
//
//void MidOrder(TreeNode* root)
//{
//    if (root == NULL)
//        return;
//    MidOrder(root->left);
//    printf("%c ", root->val);
//    MidOrder(root->right);
//}
//
//
//int main() {
//    char arr[100];
//    scanf("%s", arr);
//    int i = 0;
//    TreeNode* root = CreatTree(arr, &i);
//    MidOrder(root);
//    return 0;
//}