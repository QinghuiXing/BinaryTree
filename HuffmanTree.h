#pragma once
#define _HUFFMANTREE_
#ifdef _HUFFMANTREE_
typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, *HmTree;
typedef  char ** HuffmanCode;

void HuffmanCoding(HmTree &HT, HuffmanCode &HC, int * w, int n);
void Select(HmTree &HT, int m, int &s1, int &s2);
void LoadHuffmanTree(HmTree &HT, HuffmanCode &HC, int * &w, char *&ch, int &n, char* weightsfilename);
void SaveHuffmanTree(HmTree &HT, char* HuffTreefilename, int n);
void Encode(HuffmanCode &HC, char *ToBeTran, char *CodedFile);
void Decode(HmTree &HT, char*CodedFile, char* PlainFile, int n);
void EncodeStdin(HuffmanCode &HC);
void DecodeStdout(HmTree &HT, char* tobedecode, int n);

#endif // _HUFFMANTREE_
