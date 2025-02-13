#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct htNode
{
	char data;  //数据域
	int weight; //结点的权值
	struct htNode* parent;  //双亲与孩子的下标
	struct htNode* lch;  
	struct htNode* rch;  
}htNode, * huffmanTree; //哈夫曼树节点

int index = 0;
int flag[24] = { 0 };

void recoverHuffmanTree(huffmanTree* HT, int enc[])
{
	htNode* lch = (htNode*)malloc(sizeof(htNode)); //左子树
	htNode* rch = (htNode*)malloc(sizeof(htNode)); //右子树
	(*HT)->lch = lch;
	(*HT)->rch = rch;
	lch->parent = rch->parent = (*HT);
	lch->lch = lch->rch = rch->lch = rch->rch = NULL;
	int get = enc[index];
	int nextget = enc[index + 1];
	if (get <= 24)
	{
		(*HT)->data = get;
		(*HT)->weight = (*HT)->parent->weight - (*HT)->parent->lch->weight;
		flag[(*HT)->data - 1] = (*HT)->weight;
		index++;
		return;
	}
	else
	{
		if (nextget <= 24)
		{
			(*HT)->weight = get;
			(*HT)->data = nextget;
			flag[(*HT)->data - 1] = (*HT)->weight;
			index += 2;
			return;
		}
		else
		{
			(*HT)->weight = get;
			(*HT)->data = 0;
			index++;
			recoverHuffmanTree(&lch, enc);
			recoverHuffmanTree(&rch, enc);
		}
	}
}

int main()
{
	int enc[] = { 2270,917,446,217,106,51,20,15,17,229,114,16,11,471,233,116,14,
13,238,118,12,7,1353,557,248,123,6,24,309,137,67,3,5,172,84,4,1,796,383,186,89,2,8,197,97,48,23,10,21,413,203,101,22,9,210,104,19,18 };

	huffmanTree HT = (htNode*)malloc(sizeof(htNode));
	recoverHuffmanTree(&HT, enc);
	int i;
	for (i = 0; i < 24; i++)
	{
		printf("%c", flag[i]);
	}
}