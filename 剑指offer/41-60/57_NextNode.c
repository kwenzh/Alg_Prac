/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

// 注意该二叉树还有一个指向父亲的next指针
// 如果该节点的右孩子存在 那他的下一个中序遍历顺序节点 就是该右孩子的左孩子直到一个叶子节点
// 如果右孩子为空的情况下 并且这个节点是一个左孩子 下一个节点就是其父亲节点
// 如果是一个右分支 且没有孩子的情况下 下一个节点就是最上面的父亲节点
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
  if(pNode == NULL) {
    return NULL;
  }

  if(pNode->right != NULL) {
    TreeLinkNode *temp = pNode->right;
    while(temp->left != NULL) {
      temp = temp->left;
    }

    return temp;
  }else {
    if(pNode->next && pNode == pNode->next->left) {
      return pNode->next;
    }else {
      while(pNode->next && pNode == pNode->next->right) {
        pNode = pNode->next;
      }
      if(pNode->next) {
        return pNode->next;
      }
    }

    return NULL;
  }
}
