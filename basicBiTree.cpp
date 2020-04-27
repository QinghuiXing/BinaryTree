#include "pch.h"
#include "basicBiTree.h"
#include<cstdio>
#include<stdlib.h>
#include<stack>
#include<string>
#include<iostream>
#include<vector>

Status InitBiTree(BiTree & T)
{
	T = (BiTree)malloc(sizeof(BiTNode));
	return OK;
}

Status Destory(BiTree & T)
{
	if (!T)
		return OK;
	Destory(T->lchild);
	Destory(T->rchild);
	DestoryNode(T);
	T = NULL;
	return OK;
}

Status CreateBiTree(BiTree &T)
{
	TElemType ch=' ';
	std::cin >> ch;	
	if (ch == '.')T = NULL;
	else
	{
		//BiTNode *p;
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) return Error;
		//printf("%c", ch);
		T->data = TElemType(ch);
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
		return OK;
}

Status DestoryNode(BiTNode * T)
{
	free(T);
	return OK;
}

int BiTreeDepth(BiTree T)
{
	if (!T)return 0;
	else
	{
		int treedepth = 1;
		int leftdepth = BiTreeDepth(T->lchild);
		int rightdepth = BiTreeDepth(T->rchild);
		return treedepth + (leftdepth > rightdepth ? leftdepth : rightdepth);
	}
}

Status InsertChild(BiTree T, TElemType p, int LR, TElemType c)
{
	if (T->data == p) {
		BiTNode *s = (BiTNode*)malloc(sizeof(BiTNode));
		s->data = c;
		s->lchild = NULL;
		s->rchild = NULL;
		if (LR == 0){
			if (T->lchild)printf("\n此处已有元素\n");
			else
				T->lchild = s;
		}
		else{
			if (T->rchild)printf("\n此处已有元素\n");
			else
			T->rchild = s;
		}
		return OK;
	}
	else {
		if (T->lchild)InsertChild(T->lchild, p, LR, c);
		if (T->rchild)InsertChild(T->rchild, p, LR, c);
		return OK;
	}
	return Error;
}

void PreOrderTraverse(BiTree T)
{
	if (T != NULL) {
		printf("%c", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{
	if (T != NULL) {
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T)
{
	if (T != NULL) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
}

void LevelOrderTraverse(BiTree T)
{
	
}

void PreOrderTraverseNoRecursion(BiTree T)
{

	std::stack<BiTNode*> S;
	BiTree p = T;
	while (p || !S.empty()) {
		if (p) {
			printf("%c", p->data);
			S.push(p);
			p = p->lchild;
		}//if
		else {
			p = S.top();
			S.pop();
			p = p->rchild;
		}//else
	}//while
}

void InOrderTraverseNoRecursion(BiTree T)
{
	std::stack<BiTNode*> S;
	BiTree p = T;
	while (p||!S.empty()) {
		if (p) { S.push(p), p = p->lchild; }
		else {
			p = S.top(); S.pop();
			printf("%c", p->data);
			p = p->rchild;
		}
	}
	
	/*
	while (!p || !S.empty()) {
		if (p) {
			S.push(p);
			p = p->lchild;
		}//if
		else {
			p = S.top();
			S.pop();
			printf("%c", p->data);
			p = p->rchild;
		}//else
	}//while
	*/
}

void PostOrderTraverseNoRecursion(BiTree T)
{
	std::stack<BiTNode*> src;
	std::stack<TElemType>res;
	BiTree p = T;
	src.push(p);
	while (!src.empty()) {
		p = src.top(); src.pop();
		res.push(p->data);
		if (p->lchild)src.push(p->lchild);
		if (p->rchild)src.push(p->rchild);
	}
	int out = 0;
	while (!res.empty()) {
		out = res.top();
		res.pop();
		printf("%c", out);
	}

	/*
	std::stack<BiTNode *> S;
	BiTree p = T;
	BiTNode* lastP = NULL;
	while (!p) {
		S.push(p);
		p = p->lchild;
	}
	while (S.empty()) {
		p = S.top();
		S.pop();
		if (p->rchild == NULL || lastP == p->rchild) {
			printf("%d ", p->data);
			lastP = p;
		}//if
		else {
			S.push(p);
			p = p->rchild;
			while (!p) {
				S.push(p);
				p = p->lchild;
			}
		}
	}
	*/
}

void PrintTree(BiTree T)
{
	std::vector<BiTNode*> S;
	int cur = 0, end = 0;
	S.push_back(T);
	while (cur < S.size()) {
		end = S.size();
		while (cur < end) {
			printf("%c ", S[cur]->data);
			if (S[cur]->lchild)S.push_back(S[cur]->lchild);
			if (S[cur]->rchild)S.push_back(S[cur]->rchild);
			cur++;
		}
		printf("\n");
	}
}


void PrintDegree1(BiTree T)
{
	if ((T->lchild==NULL&&T->rchild!=NULL) || (T->lchild!=NULL&&T->rchild==NULL))
		printf("%c ", T->data);
	if (T->lchild)PrintDegree1(T->lchild);
	if (T->rchild)PrintDegree1(T->rchild);
}

void PrintLeaf(BiTree T)
{
	if (!(T->lchild || T->rchild))
		printf("%c ", T->data);
	if (T->lchild)PrintLeaf(T->lchild);
	if (T->rchild)PrintLeaf(T->rchild);
}

void PrintDegree2(BiTree T)
{
	if (T->lchild&&T->rchild)
		printf("%c ", T->data);
	if (T->lchild)PrintDegree2(T->lchild);
	if (T->rchild)PrintDegree2(T->rchild);
}

void VerseTree(BiTree T)
{
	BiTNode * tmp;
	tmp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = tmp;
	if (T->lchild)VerseTree(T->lchild);
	if (T->rchild)VerseTree(T->rchild);
}
