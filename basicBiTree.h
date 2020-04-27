#pragma once

// #ifdef BASIC_BI_TREE
// #define BASIC_BI_TREE

typedef char TElemType;
typedef enum Status{Error, OK};

typedef struct BiTNode {
	TElemType data;
	BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status InitBiTree(BiTree &T);
Status Destory(BiTree &T);
Status CreateBiTree(BiTree &T);
Status DestoryNode(BiTNode* T);
int BiTreeDepth(BiTree T);
Status InsertChild(BiTree T, TElemType p, int LR, TElemType c);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void LevelOrderTraverse(BiTree T);
void PreOrderTraverseNoRecursion(BiTree T);
void InOrderTraverseNoRecursion(BiTree T);
void PostOrderTraverseNoRecursion(BiTree T);
void PrintTree(BiTree T);
void PrintLeaf(BiTree T);
void PrintDegree1(BiTree T);
void PrintDegree2(BiTree T);
void VerseTree(BiTree T);
// #endif // BASIC_BI_TREE
