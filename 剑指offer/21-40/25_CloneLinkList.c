/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
这是一道很不错的例题 难点在于复制随机指针
对于原链表的每个节点复制一下，粘贴在其后，也就是插入在原节点之后，只是对节点的数据复制，
有一个和它相同数据的就节点插入在其后。这是第一步。

第二步：拷贝随机指针，可以通过原节点找到随机指针指向的那个节点，
不妨叫做randomNode，而这个randomNode的next节点就是镜像节点的随机指针的指向啊。完成指向关系即可达到拷贝随机指针。

第三步：拆开原节点和镜像节点，这个不难，通过改变这个长链表里各节点的next指针指向即可完成。
见博客:https://blog.csdn.net/Yvken_Zh/article/details/80643453
*/
RandomListNode* Clone(RandomListNode* pHead)
{
    // 第一步先给原链表的每个节点后面复制一个镜像 实际上是复制了节点的值 随机指针没法复制
  if(pHead == NULL) {
    return NULL;
  }
  RandomListNode *pMove = pHead;

// 复制链表中的每一个节点 插入在其后
  while(pMove != NULL) {
    RandomListNode *copyNode = (RandomListNode *)malloc(sizeof(RandomListNode));
    copyNode->label = pMove->label;
    copyNode->next = pMove->next;
    pMove->next = copyNode;
    pMove = copyNode->next;
  }

// 第二步是复制指向随机指针 可以利用链表中原节点的指向随机节点 后一个镜像节点完成复制
  pMove = pHead;
  while(pMove != NULL) {
    RandomListNode *copyNode = pMove->next;
    if(pMove->random != NULL) {
    	copyNode->random = pMove->random->next;
    }
    pMove = copyNode->next;
  }

  // 拆分镜像节点和原链表节点 主要是改变链表中各个节点指向关系
  RandomListNode *resultHead = pHead->next;
  pMove = pHead;
  RandomListNode *temp;

  // 链表中第一个节点的链接关系就是原链表 代表原链表的头结点
  //  第二个节点代表复制的链表的头结点
  while(pMove->next != NULL) {
    temp = pMove->next;
    pMove->next = temp->next;
    pMove = temp;
  }

  return resultHead;
}
