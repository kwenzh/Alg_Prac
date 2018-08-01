/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

//判断一个树是不是另一个的子树 当然是递归了 判断A的所有组合的子树是否和Ｂ相同
// 组合就有左子树　右子树　然后就是递归组合了
bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
    if (pRootB == NULL) {
        return true;
    }
    if (pRootA == NULL) {
        return false;
    }
    if (pRootB->val == pRootA->val) {
        return isSubtree(pRootA->left, pRootB->left) && isSubtree(pRootA->right, pRootB->right);
    } else {
        return false;
    }
}

bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB) {
  if (pRootA == NULL || pRootB == NULL) {
    return false;
  }

//整个算法的难点在于这里的递归HasSubtree(pRootA->left, pRootB) ||  HasSubtree(pRootA->right, pRootB);
//递归的查 A树的所有左右子树是否和B树相同
    return isSubtree(pRootA, pRootB) || HasSubtree(pRootA->left, pRootB) ||
        HasSubtree(pRootA->right, pRootB);
}
