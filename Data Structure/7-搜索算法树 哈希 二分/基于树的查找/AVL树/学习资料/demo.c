#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

//AVL树数据结构定义
typedef int ElementType;//AVL数节点包含数据类型

//树节点
typedef struct AVLNode{
	ElementType element;//节点包含的数据元素
	AVLNode *left;//节点左子树
	AVLNode *right;//节点右子树
	int height;//节点所在的高度
}*AVLTree;

//AVL tree类封装
class CAVLTree{
private:
	//供内部调用的函数
	int getHeight(AVLTree);//求得树的高度

	void setHeight(AVLTree,int);//设置节点的高度值

	//单旋转：向右旋转
	AVLTree SingleRightRotate(AVLTree);
	//单旋转：向左旋转
	AVLTree SingleLeftRotate(AVLTree);
	//双旋转：左右
	AVLTree DoubleRightRotate(AVLTree);
	//双旋转：右左
	AVLTree DoubleLeftRotate(AVLTree);

public:
	//默认构造函数
	CAVLTree();
	//析构函数
	~CAVLTree();
	//创建AVL树
	void createAVLTree(ElementType *data,int n);
	//插入节点
	AVLTree insertNode(AVLTree T,ElementType val);
	//删除树中元素值等于某值的节点
	AVLTree deleteNode(AVLTree T,const ElementType val);
	//搜寻元素值等于某值的节点
	AVLTree searchNode(AVLTree,ElementType);
	//前序遍历输出树
	void preOrder(AVLTree T);
	//得到树中的元素值最大的节点
	AVLTree getMaxNode(AVLTree);
	//得到树中的元素值最小的那个节点
	AVLTree getMinNode(AVLTree);

	AVLTree T;
};

#endif // AVLTREE_H_INCLUDED

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

CAVLTree::CAVLTree()
{
	T = NULL;
}

CAVLTree::~CAVLTree()
{
	//if(T)
	//{
	//	if(NULL == T->left && NULL == T->right)
	//		delete T;
	//	else{
	//		delete T->left;
	//		delete T->right;
	//	}
	//}
	deleteTree(T);
}

//依据各元素的数据值，创建AVL树
void CAVLTree::createAVLTree(ElementType *data,int n)
{
	if (T)
	{
		cout << "The AVL Tree has been created" << endl;

		return;
	}

	if(!n)//元素序列为空
	{
		T = NULL;
		return;
	}

	for(int i = 0;i < n;++i)
	{
		T = insertNode(T,*(data + i));
	}

	return;
}

AVLTree CAVLTree::insertNode(AVLTree T,ElementType val)
{
	AVLNode *pNewNode = new AVLNode;
	pNewNode->element = val;
	pNewNode->left = NULL;
	pNewNode->right = NULL;
	pNewNode->height = 1;//新节点一定被插入在空节点的位置

	if(NULL == T)
	{
		T = pNewNode;
		return T;
	}

	//需要插入节点的树非空
	//插入的元素已经存在于树中，不符合要求
	if (val == T->element)
	{
		cout << "元素中有重复，构建AVL树失败！" << endl;
		return T;
	}
	//要插入的值小于根节点的值，将其插入左子树中
	if(val < T->element)
	{
		//将其插入根节点的左子树中
		T->left = insertNode(T->left,val);
		//判断平衡条件是否仍然满足
		if(getHeight(T->left) - getHeight(T->right) > 1)
		{
			//分两种情况进行旋转操作
			//插入点位于T的左子结点的左子树
			if(val < T->left->element)
				//实施单旋转-右旋转
				T = SingleRightRotate(T);
			else
				//插入点位于T的左子结点的右子树，实施双右旋转
				T = DoubleRightRotate(T);
		}
	}
	//要插入的值大于根节点的值，将其插入右子树中
	if(val > T->element)
	{
		T->right = insertNode(T->right,val);
		//判断平衡条件是否仍然满足
		if(getHeight(T->right) - getHeight(T->left) > 1)
		{
			//节点插入到T的右子节点的右子树中
			if(val > T->right->element)
				//实施单旋转-左旋转
				T = SingleLeftRotate(T);
			else
				//节点插入到T的右子节点的左子树上
				//实施双旋转-左旋转
				T = DoubleLeftRotate(T);
		}
	}

	//更新节点的height值
	setHeight(T,max(getHeight(T->left),getHeight(T->right)) + 1);

	return T;
}

AVLTree CAVLTree::deleteNode(AVLTree T,const ElementType val)
{
	if (!T)
	{
		cout << "The tree is NULL, delete failed" << endl;
		return T;
	}

	AVLTree searchedNode = searchNode(T,val);
	//没有找到相应的节点，删除失败
	if (!searchedNode)
	{
		cout << "Cann't find the node to delete " << val << endl;
		return T;
	} 
	
	//找到了需要删除的节点
	//需要删除的节点就是当前子树的根节点
	if (val == T->element)
	{
		//左右子树都非空
		if (T->left && T->right)
		{
			//在高度更大的那个子树上进行删除操作
			if (getHeight(T->left) > getHeight(T->right))
			{
				//左子树高度大，删除左子树中元素值最大的那个节点，同时将其值赋值给根节点
				T->element = getMaxNode(T->left)->element;
				T->left = deleteNode(T->left,T->element);
			}
			else{
				//删除右子树中元素值最小的那个节点，同时将其值赋值给根节点
				T->element = getMinNode(T->right)->element;
				T->right = deleteNode(T->right,T->element);
			}
		}
		else{
			//左右子树中有一个不为空，那个直接用需要被删除的节点的子节点替换之即可
			AVLTree oldNode = T;
			T = (T->left ? T->left : T->right);
			delete oldNode;//释放节点所占的空间
			oldNode = NULL;
		}
	}
	else if (val < T->element)//要删除的节点在左子树中
	{
		//在左子树中进行递归删除
		T->left = deleteNode(T->left,val);
		//判断是否仍然满足平衡条件
		if (getHeight(T->right) - getHeight(T->left) > 1)
		{
			if (T->right->left > T->right->right)
			{
				//左双旋转
				T = DoubleLeftRotate(T);
			}
			else//进行左单旋转
				T = SingleLeftRotate(T);
		}
		else
			//满足平衡条件，需要更新高度信息
			T->height = max(getHeight(T->left),getHeight(T->right)) + 1;
	}
	else//需要删除的节点在右子树中
	{
		T->right = deleteNode(T->right,val);
		//判断是否满足平衡条件
		if (getHeight(T->left) - getHeight(T->right) > 1)
		{
			if(getHeight(T->left->right) > getHeight(T->left->left))
				//右双旋转
				T = DoubleRightRotate(T);
			else
				//右单旋转
				T = SingleRightRotate(T);
		}
		else
			//只需调整高度即可
			T->height = max(getHeight(T->left),getHeight(T->right)) + 1;
	}

	return T;
}

AVLTree CAVLTree::searchNode(AVLTree T,ElementType val)
{
	if (!T)
	{
		return NULL;
	}

	//搜索到
	if (val == T->element)
	{
		return T;
	}
	else if (val < T->element)
	{
		//在左子树中搜索
		return searchNode(T->left,val);
	}
	else
	{
		//在右子树中搜索
		return searchNode(T->right,val);
	}
}

void CAVLTree::preOrder(AVLTree T)
{
	if(!T)
		cout << "NULL ";
	else
	{
		cout << T->element << " ";
		preOrder(T->left);
		preOrder(T->right);
	}
}

AVLTree CAVLTree::getMaxNode(AVLTree T)
{
	if (!T)//树为空
	{
		return NULL;
	}

	AVLTree tempNode = T;
	//向右搜寻直至右子节点为NULL
	while(tempNode->right)
	{
		tempNode = tempNode->right;
	}

	return tempNode;
}

AVLTree CAVLTree::getMinNode(AVLTree T)
{
	if (!T)//树为空
	{
		return NULL;
	}

	AVLTree tempNode = T;
	//向左搜寻直至左子结点为NULL
	while(tempNode->left)
	{
		tempNode = tempNode->left;
	}

	return tempNode;
}

int CAVLTree::getHeight(AVLTree T)
{
	return (T == NULL) ? 0 : (T->height);
}

void CAVLTree::setHeight(AVLTree T,int height)
{
	T->height = height;
}

//左左外侧插入导致的不平衡，采用单旋转-右旋转进行修正
//参数解释：
//T：指向因某种操作失去平衡的最小子树根节点
AVLTree CAVLTree::SingleRightRotate(AVLTree T)
{
	AVLTree xPNode = T;
	AVLTree yPNode = T->left;
	
	xPNode->left = yPNode->right;//更改原根节点的左子树
	yPNode->right = xPNode;//更改原根节点左孩子的右子树

	//更新进行了旋转操作的节点的高度
	xPNode->height = max(getHeight(xPNode->left),getHeight(xPNode->right)) + 1;
	yPNode->height = max(getHeight(yPNode->left),getHeight(yPNode->right)) + 1;

	//原根节点的左孩子节点成为新的根节点
	return yPNode;
}

//右右外侧插入导致的不平衡，采用单旋转-左旋转进行修正
//参数解释：
//T：指向因某种操作失去平衡的最小子树根节点
AVLTree CAVLTree::SingleLeftRotate(AVLTree T)
{
	AVLTree xPNode = T;
	AVLTree yPNode = T->right;

	xPNode->right = yPNode->left;//更改原根节点的右孩子
	yPNode->left = xPNode;//提升原根节点的右孩子节点为新的根节点

	//更新执行了旋转操作的节点的高度信息
	xPNode->height = max(getHeight(xPNode->left),getHeight(xPNode->right)) + 1;
	yPNode->height = max(getHeight(yPNode->left),getHeight(yPNode->right)) + 1;

	//返回新的根节点
	return yPNode;
}

//插入点位于T的左子结点的右子树
AVLTree CAVLTree::DoubleRightRotate(AVLTree T)
{
	//双旋转可以通过两次单旋转实现
	//第一次单旋转
	assert(T->left != NULL);
	//对其左子树进行一次单旋转-左旋转
	T->left = SingleLeftRotate(T->left);
	//第二次单旋转
	//对新产生的树进行一次单旋转-右旋转
	return SingleRightRotate(T);
}

//插入点位于T的右子节点的左子树
AVLTree CAVLTree::DoubleLeftRotate(AVLTree T)
{
	//双旋转可以通过两次单旋转实现
	//第一次单旋转
	assert(T->right != NULL);
	//对其右子树进行一次单旋转-右旋转
	T->right = SingleRightRotate(T->right);
	//第二次单旋转
	//对新产生的树进行一次单旋转-左旋转
	return SingleLeftRotate(T);
}


void CAVLTree::deleteTree(AVLTree t)
{
	if(NULL == t)
		return;

	deleteTree(t->left);
	deleteTree(t->right);
	delete t;
	t = NULL;
}

//平衡二叉树搜索树（AVL tree-Adelson-Velskii-Landis tree）编程实现
//作者：江南烟雨
//时间：2012-12-10

#include "AVLTree.h"
#include <iostream>

using namespace std;

int main()
{
	const int NumElements = 5;
	cout << "AVL树各项操作编程实现：" << endl;
	int a[NumElements] ={18,14,20,12,16};
	CAVLTree *CAVLTreeObj1 = new CAVLTree();
	CAVLTreeObj1->createAVLTree(a,NumElements);
	cout << "AVL Tree先序遍历结果：" << endl;
	CAVLTreeObj1->preOrder(CAVLTreeObj1->T);
	cout << endl;

	int insertedVal1 = 15;
	CAVLTreeObj1->T = CAVLTreeObj1->insertNode(CAVLTreeObj1->T,insertedVal1);
	cout << "向AVL树中插入元素  " << insertedVal1 << "之后的先序遍历结果：" << endl;
	CAVLTreeObj1->preOrder(CAVLTreeObj1->T);
	cout << endl;

	int insertedVal2 = 16;
	CAVLTreeObj1->T = CAVLTreeObj1->insertNode(CAVLTreeObj1->T,insertedVal2);
	cout << "向AVL树中插入元素  " << insertedVal2 << "之后的先序遍历结果：" << endl;
	CAVLTreeObj1->preOrder(CAVLTreeObj1->T);
	cout << endl;

	int minVal = CAVLTreeObj1->getMinNode(CAVLTreeObj1->T)->element;
	cout << "树中最小的元素是：" << minVal << endl;

	int maxVal = CAVLTreeObj1->getMaxNode(CAVLTreeObj1->T)->element;
	cout << "树中最大的元素是：" << maxVal << endl;

	const int deletedVal1 = 11;
	CAVLTreeObj1->T = CAVLTreeObj1->deleteNode(CAVLTreeObj1->T,deletedVal1);
	cout << "删除元素值为 " << deletedVal1 << "的节点之后的树先序遍历结果：" << endl;
	CAVLTreeObj1->preOrder(CAVLTreeObj1->T);
	cout << endl;

	const int deletedVal2 = 20;
	CAVLTreeObj1->T = CAVLTreeObj1->deleteNode(CAVLTreeObj1->T,deletedVal2);
	cout << "删除元素值为 " << deletedVal2 << "的节点之后的树先序遍历结果：" << endl;
	CAVLTreeObj1->preOrder(CAVLTreeObj1->T);
	cout << endl;

	const int deletedVal3 = 18;
	CAVLTreeObj1->T = CAVLTreeObj1->deleteNode(CAVLTreeObj1->T,deletedVal3);
	cout << "删除元素值为 " << deletedVal3 << "的节点之后的树先序遍历结果：" << endl;
	CAVLTreeObj1->preOrder(CAVLTreeObj1->T);
	cout << endl;

	const int searchedVal1 = 12;
	AVLTree searchedPNode = CAVLTreeObj1->searchNode(CAVLTreeObj1->T,searchedVal1);
	if(!searchedPNode)
		cout << "cannot find such node whose elemen equals " << searchedVal1 << endl;
	else
		cout << "search success element " << searchedVal1 << endl;

	const int searchedVal2 = 13;
	searchedPNode = CAVLTreeObj1->searchNode(CAVLTreeObj1->T,searchedVal2);
	if(!searchedPNode)
		cout << "cannot find such node whose elemen equals " << searchedVal2 << endl;
	else
		cout << "search success element " << searchedVal2 << endl;

	return 0;
}

Position Delete(ElementType X, AvlTree T)
{
    Position TmpCell;

    if(T == NULL)
    {
        printf("Element not found!!\n");
        return NULL;
    }
    else if(T->Element > X) //往左边查找元素X
        T->Left = Delete(X, T->Left);
    else if(T->Element < X) //往右边查找元素X
        T->Right = Delete(X, T->Right);
    else if(T->Left && T->Right) //元素找到了并且左右子树都不为空
    {
        //将要删除的节点用右子树中的最小节点代替
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        //递归删除该最小节点
        T->Right = Delete(T->Element, T->Right);
    }
    else //元素找到了并且左右子树有一个为空
    {
        TmpCell = T;
        if(T->Left == NULL)
            T = T->Right;   //此处是为了让T的父节点指向T的右子树(由于函数最后返回了T)
        else if(T->Right == NULL)
            T = T->Left;

        free(TmpCell); //释放节点
    }

    if(T != NULL)
    {
        //删除完节点之后要更新高度
        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
        //在节点T处失去平衡
        if((Height(T->Left) - Height(T->Right) >= 2) || (Height(T->Right) - Height(T->Left) >= 2))
        {
            T = Fix(T);
            //修复完成后更新节点高度
            T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
        }
    }

    return T;   //千万不能忘记
}