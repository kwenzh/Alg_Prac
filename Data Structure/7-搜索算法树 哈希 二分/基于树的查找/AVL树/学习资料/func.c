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

//对失去平衡的节点进行修复的函数
static Position Fix(Position K2)
{
    if(Height(K2->Left) > Height(K2->Right))
    {
        //K2左儿子的左儿子的高度大于K2的左儿子的右儿子的高度, 执行左单旋转, 否则执行左-右双旋转
        if(Height(K2->Left->Left) > Height(K2->Left->Right))
            K2 = SingleRotateWithLeft(K2);
        else if(Height(K2->Left->Left) < Height(K2->Left->Right))
            K2 = DoubleRotateWithLeft(K2);
    }
    else if(Height(K2->Left) < Height(K2->Right))
    {
        //K2右儿子的度右儿子的高大于K2的右儿子的左儿子的高度, 执行右单旋转, 否则执行右-左双旋转
        if(Height(K2->Right->Right) > Height(K2->Right->Left))
            K2 = SingleRotateWithRight(K2);
        else if(Height(K2->Right->Right) < Height(K2->Right->Left))
            K2 = DoubleRotateWithRight(K2);
    }

    return K20;
}