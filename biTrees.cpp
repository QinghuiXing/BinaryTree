#include <iostream>
#include<cstdio>
#include "basicBiTree.h"

int main()
{
	TElemType c = ' ', p = ' ';
	BiTree T;
	int LR = 0;
	int k;
	while (1) {
		printf("二叉树基本操作测试，请输入操作指令号：\n");
		printf("1----初始化二叉树\n");
		printf("2----构造二叉树\n");
		printf("3----求二叉树深度\n");
		printf("4----插入新结点\n");
		printf("5----输出叶子结点\n");
		printf("6----输出度为 1 的结点\n");
		printf("7----输出度为 2 的结点\n");
		printf("8----反转二叉树\n");
		printf("9----销毁二叉树\n");
		printf("10----非递归先序遍历\n");
		printf("11----非递归中序遍历\n");
		printf("12----非递归后序遍历\n");
		printf("13----递归先序遍历\n");
		printf("14----递归中序遍历\n");
		printf("15----递归后序遍历\n");
		printf("16----打印二叉树\n输入命令：");
		std::cin >> k;
		switch (k) {
			case 1: {
				InitBiTree(T);
				printf("初始化完成！\n");
				break;
			}
			case 2: {
				printf("请以先序序列输入二叉树元素，空元素用 . 表示\n");
				CreateBiTree(T);
				printf("构造完成！\n");
				break;
			}
			case 3: {
				printf("二叉树的深度为：\n%d\n", BiTreeDepth(T));
				system("pause");
				break;
			}
			case 4: {
				printf("顺序输入：要插入的结点是左孩子(0)还是右孩子(1)，元素值，其双亲结点元素值\n");
				scanf("%d %c %c", &LR, &p, &c);
				InsertChild(T, c, LR, p);
				printf("插入成功！\n");
				break;
			}
			case 5: {
				printf("叶子节点有:\n");
				PrintLeaf(T);
				printf("\n");
				system("pause");
				break;
			}
			case 6: {
				printf("度为 1 的结点有:\n");
				PrintDegree1(T);
				printf("\n");
				system("pause");
				break;
			}
			case 7: {
				printf("度为2的结点有:\n");
				PrintDegree2(T);
				printf("\n");
				system("pause");
				break;

			}
			case 8: {
				VerseTree(T);
				printf("已反转！\n");
				break;
			}
			case 9: {
				Destory(T);
				printf("已销毁！\n");
				break;
			}
			case 10: {
				printf("非递归先序遍历结果：\n");
				PreOrderTraverseNoRecursion(T);
				printf("\n");
				system("pause");
				break;
			}
			case 11: {
				printf("非递归中序遍历结果：\n");
				InOrderTraverseNoRecursion(T);
				printf("\n");
				system("pause");
				break;
			}
			case 12: {
				printf("非递归后序遍历结果：\n");
				PostOrderTraverseNoRecursion(T);
				printf("\n");
				system("pause");
				break;
			}
			case 13: {
				printf("递归先序遍历结果：\n");
				PreOrderTraverse(T);
				printf("\n");
				system("pause");
				break;
			}
			case 14: {
				printf("递归中序遍历结果：\n");
				InOrderTraverse(T);
				printf("\n");
				system("pause");
				break;
			}
			case 15: {
				printf("递归后序遍历结果：\n");
				PostOrderTraverse(T);
				printf("\n");
				system("pause");
				break;
			}
			case 16: {
				printf("打印结果如下:\n");
				PrintTree(T);
				system("pause");
			}
		}//switch
	}//while
	return 0;
}
