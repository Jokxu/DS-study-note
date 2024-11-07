#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

//定义二叉链表
typedef struct BiTNode
{
    char data;
    struct BiTNode *lt, *rt;    
}BiTNode;
typedef BiTNode* BiTree;

//中序遍历二叉树(递归版)
void InorderTraverse1(BiTree T)
{
    if(T)
    {
        InorderTraverse1(T->lt);
        cout << T->data;
        InorderTraverse1(T->rt);
    }
}

//中序遍历二叉树(非递归)
void InOrderTraverse2(BiTree T)
{
    stack<BiTree> S;
    BiTree p = T;
    BiTree q;
    while (p || !S.empty())
    {
        if(p)
        {
            S.push(p);
            p = p->lt;
        }
        else
        {
            q = S.top();
            S.pop();
            cout << q->data;
            p = q->rt;
        }
    }
}

//先序遍历创建二叉链表
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lt);
        CreateBiTree(T->rt);
    }
}

//计算二叉树的深度(根据后序遍历)
int Depth(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    else
    {
        int m = Depth(T->lt), n = Depth(T->rt);
        return max(m, n) + 1;
    }
}

//统计结点个数(根据后序遍历)
int NoseCount(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    else
    {
        return NoseCount(T->lt) + NoseCount(T->rt) + 1;
    }
}

//数据 a b c # # d # # e # #

int main()
{
    BiTree tree;
    CreateBiTree(tree);
    InorderTraverse1(tree);
    cout << endl;
    InOrderTraverse2(tree);
    return 0;
}