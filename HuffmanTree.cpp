#include "pch.h"
#include "HuffmanTree.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>


void HuffmanCoding(HmTree & HT, HuffmanCode & HC, int * w, int n)
{
	if (n < 1)return;
	int m = 2 * n - 1;
	HT = (HmTree)malloc((m+1)* sizeof(HTNode));
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	HTNode* p = HT; int i = 1;
	p++;
	int s1, s2;
	for (; i <= n; ++i, ++p, ++w)*p = { *w,0,0,0 };
	for (; i <= m; ++i, ++p)*p = { 0,0,0,0 };
	for (i = n + 1; i <= m;i++) {
		Select(HT,i-1,s1,s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	char* cd = (char*)malloc(n * sizeof(char)), *ch1= (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int f = HT[i].parent;
		for (int c = i; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c)cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		//for (int k1 = start, k2 = n-2; k1 <=n-2; k1++,k2--) {
		//	ch1[k1] = cd[k2];
		//}
		//ch1[n - 1] = '\0';
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}

void Select(HmTree & HT, int m, int &s1, int &s2)
{
	for(int i=1;i<=m;i++)
		if (HT[i].parent == 0) {
			s1 = i;
			break;
		}
	for (int i = 1; i <= m; i++) {
		if (HT[i].weight < HT[s1].weight&&HT[i].parent==0)
			s1 = i;
	}
	for (int i = 1; i <= m; i++)
		if (HT[i].parent == 0 && i != s1) {
			s2 = i;
			break;
		}
	for (int i = 1; i <= m; i++) {
		if (HT[i].weight < HT[s2].weight&&i != s1 && HT[i].parent == 0) {
			s2 = i;
		}
	}
}

void LoadHuffmanTree(HmTree & HT, HuffmanCode & HC, int * &w, char * &ch, int & n, char* weightsfilename)
{
	//char filename[weightsfilename.length + 1] = weightsfilename;
	FILE *f = fopen(weightsfilename, "r+");
	fscanf(f, "%d\n", &n);
	w = (int*)malloc(n * sizeof(int));
	ch = (char*)malloc(n * sizeof(char));
	for (int i = 0; i < n; i++) {
		fscanf(f, "%c ", &ch[i]);
		fscanf(f, "%d\n", &w[i]);
	}
	fclose(f);
}

void SaveHuffmanTree(HmTree & HT, char* HuffTreefilename, int n)
{
	//char filename[HuffTreefilename.length] = HuffTreefilename;
	FILE *wr = fopen(HuffTreefilename, "w+");
	int parent, weight, lchild, rchild;
	for (int i = 1; i <= 2 * n - 1; i++) {
		weight = HT[i].weight;
		parent= HT[i].parent;
		lchild = HT[i].lchild;
		rchild = HT[i].rchild;
		fprintf(wr, "%d %d %d %d\n", weight, parent, lchild, rchild);
	}
	fclose(wr);
}

void Encode(HuffmanCode & HC, char *ToBeTran, char *CodedFile)
{
	FILE *tobetran, *codedfile;
	tobetran = fopen(ToBeTran, "r+");
	codedfile = fopen(CodedFile, "a+");
	char n;
	n = fgetc(tobetran);
	do {
		if (n == ' ')
			fprintf(codedfile, "%s", HC[1]);
		else if (n == '\n')
			fprintf(codedfile, "\n");
		else
			fprintf(codedfile, "%s", HC[n - 'A' + 2]);
		n = fgetc(tobetran);
	} while (n!=-1);
	fclose(tobetran);
	fclose(codedfile);
}

void Decode(HmTree & HT, char * CodedFile, char * PlainFile, int n)
{
	FILE *c = fopen(CodedFile, "r+"), *p = fopen(PlainFile, "a+");
	char huffcodes[5000];
	//char tmpch;
	fscanf(c, "%s", huffcodes);
	fclose(c);
	//tmpch = fgetc(c);
	int i = 0,j=2*n-1, len = strlen(huffcodes);
	//int tmp = int(huffcodes[i]) - 48;
	//if(c==0)
	//	fprintf(p,"%c",)
	if (huffcodes[i] == '0')
		j = HT[2 * n - 1].lchild;
	else
		j = HT[2 * n - 1].rchild;
	while (i <= len) {

		if (HT[j].lchild == 0) {//叶结点
			if (j == 1)// '.'
				fprintf(p, "%c", ' ');
			else // A - Z
				fprintf(p, "%c", char(j - 2 + 'A'));
			i++;
			if (huffcodes[i] == '0')
				j = HT[2 * n - 1].lchild;
			else
				j = HT[2 * n - 1].rchild;
		}
		else {
			i++;
			if (huffcodes[i] == '0')
				j = HT[j].lchild;
			else
				j = HT[j].rchild;
		}
	}
	fclose(p);
/*
		if (tmp == 0) {//左孩子
			if (HT[j].lchild == 0) {//叶结点
				if (j == 1) {// ‘ . ’
					fprintf(p, "%c", '.');
					j = 2 * n - 1;
					i++;
					if (huffcodes[i] == '0')
						j = HT[2 * n - 1].lchild;
					else
						j = HT[2 * n - 1].rchild;
				}
				else { // A - Z
					fprintf(p, "%c", char(j - 2 + 'A'));
					j = 2 * n - 1;
					i++;
					if (huffcodes[i] == '0')
						j = HT[2 * n - 1].lchild;
					else
						j = HT[2 * n - 1].rchild;
				}
			}//if
			else {//非叶节点
				j = HT[j].lchild;//给左孩子结点
			}
		}
		else {//右孩子
			if (HT[j].rchild == 0) {//叶结点
				if (j == 1) {// ‘ . ’
					fprintf(p, "%c", '.');
					j = 2 * n - 1;
					i++;
					if (huffcodes[i] == '0')
						j = HT[2 * n - 1].lchild;
					else
						j = HT[2 * n - 1].rchild;
				}
				else { // A - Z
					fprintf(p, "%c", char(j - 2 + 'A'));
					j = 2 * n - 1;
					i++;
					if (huffcodes[i] == '0')
						j = HT[2 * n - 1].lchild;
					else
						j = HT[2 * n - 1].rchild;
				}
			}//if
			else {//非叶节点
				j = HT[j].rchild;//给右孩子结点
			}
		}//if
		i++;
		tmp = int(huffcodes[i]) - 48;
	}//while
	*/
}

void EncodeStdin(HuffmanCode & HC)
{
	//int len = str.length();
	//int len = strlen(str);
	char n='\0',	str1[100];
	int i = 0;
	rewind(stdin);
	do{ 
		scanf("%c", &n);
		str1[i++] = n;
	} while (n != '\n');

	for (int j = 0; j < i-1; j++) {
		n = str1[j];
		if (n == ' ')
			printf("%s", HC[1]);
		else
			printf("%s", HC[n - 'A' + 2]);
	}

}

void DecodeStdout(HmTree & HT, char * tobedecode, int n)
{
	int i = 0, j = 2 * n - 1, len = strlen(tobedecode);
	
	if (tobedecode[i] == '0')
		j = HT[2 * n - 1].lchild;
	else
		j = HT[2 * n - 1].rchild;
	
	while (i <= len) {
		if (HT[j].lchild == 0) {//叶结点
			if (j == 1)// '.'
				printf("%c", ' ');
			else // A - Z
				printf("%c", char(j - 2 + 'A'));
			i++;
			if (tobedecode[i] == '0')
				j = HT[2 * n - 1].lchild;
			else
				j = HT[2 * n - 1].rchild;
		}
		else {
			i++;
			if (tobedecode[i] == '0')
				j = HT[j].lchild;
			else
				j = HT[j].rchild;
		}
	}
}
