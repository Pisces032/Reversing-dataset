#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXVALUE 32767 //极大值相当于无穷大
#define NODENUM 24 //叶子结点数
typedef struct
{
	int data; //数据域
	int weight; //结点的权值
	int parent, lch, rch; //双亲与孩子的下标
}htNode,*huffmanTree;
int initHuffmanTree(huffmanTree& HT);
//初始化哈夫曼树
void creatHuffmanTree(huffmanTree& HT, int n);
//构建哈夫曼树
int ans1[]={2270,917,446,217,106,51,20,15,17,229,114,16,11,471,233,116,14,13,
238,118,12,7,1353,557,248,123,6,24,309,137,67,3,5,172,84,4,1,796,383,186,89,
2,8,197,97,48,23,10,21,413,203,101,22,9,210,104,19,18};
/
*先序遍历*
/
int index;
int check_flag(huffmanTree HT,int i)
{
//使用前序遍历检查哈夫曼树的各个结点
//当遍历到叶子节点时，检查叶子结点的data
	if(i<=24)
	{
		if(HT[i].data!=ans1[index++])
		return 0;
	}
//当遍历到非叶子结点时
	if(i>24)
	{
//检查结点的权重
		if(HT[i].weight!=ans1[index++])
		return 0;
//如果左孩子是叶子结点，检查左孩子的权重（根据哈夫曼树的性质，我们可以求出右节点的权重）
		if(HT[HT[i].lch].data<=24 && HT[HT[i].lch].data>0)
		{
			if(HT[HT[i].lch].weight!=ans1[index++])
			return 0;
		}
	}
	if(HT[i].lch>0)
	{
//遍历
		if(check_flag(HT,HT[i].lch)&&check_flag(HT,HT[i].rch))
		return 1;
	}
	else
		return 1;
//根据密文内容我们可以还原出哈夫曼树，根据叶子结点的weight和data还原出flag
}
int main()
{
	huffmanTree HT ;
	initHuffmanTree(HT); //初始哈夫曼树，weight即flag，data对应下标
	creatHuffmanTree(HT,NODENUM); //创建哈夫曼树
	index=0;
	if(check_flag(HT,47) && index==58) //检查哈夫曼树
		printf("yes");
}
int initHuffmanTree(huffmanTree& HT)
{
	HT = (htNode*)malloc(sizeof(htNode) * (2 * NODENUM));
//给HT分配2 * NODENUM个htNOde大小的htNode类型的数组
	for (int i = 1; i <= 2 * NODENUM - 1; i++)
//下标从1开始到2 * NODENUM
	{
		HT[i].parent = HT[i].lch = HT[i].rch = -1;
//双亲和孩子的值都置为-1
	}
//这个来接收上面的回车
	printf("please input flag:\n");
	for (int i = 1; i <= NODENUM; i++)
	{
		char a = getchar();
		HT[i].data = i;
		HT[i].weight=a;
	}
	return 1;
}
void creatHuffmanTree(huffmanTree& HT, int n)
{
	if (n <= 1)
//如果结点数小于等于1，不创建
		return;
	int min1, min2;
//定义两个数，来存储每次选取最小两个结点的权值
	int rnode, lnode;
//定义两个下标值，来存储每次选取最小两个结点的下标
	for (int i = n + 1; i <= 2 * n -1; i++)
//要生成n-1个结点，所以要操作n—1次且从下标为n+1开始存储
	{
		int min1 = MAXVALUE; int lnode = -1;
//让最小值初始化为极大值，这样叶子结点的最大值再大也不会超过这个值了
		int min2 = MAXVALUE; int rnode = -1;
		for (int j = 1; j <= i - 1; j++)
//因为起先是在前n个中选择最小的两个结点的权值，但新生成一个后就得在前n+1个中选择最小的两
个结点的权值
		{
//假设n = 10 总结点数就得为19，那我们就只要比较18次就可以得出结果了，记住比较的次数比生
成的总结点数少1
			if (HT[j].weight < min1 && HT[j].parent == -1)
//这个小于就使得当出现相同的权值时优先考虑先出现的值，可以假设下
			{
				min2 = min1; rnode = lnode;
//碰到比min1小的，那min1的值就给第二小的min2，下标也给它
				min1 = HT[j].weight; lnode = j;
//然后最小的给min1，下标同理
			}
			else if (HT[j].weight < min2 && HT[j].parent == -1)
//这是第二小的判断
			{
				min2 = HT[j].weight;
				rnode = j;
			}
		}		
		HT[lnode].parent = HT[rnode].parent = i;
//最小两个结点的parent变为生成结点的下标
		HT[i].lch = lnode; HT[i].rch = rnode;
//生成结点的左孩子为最小的min1的下标，右孩子同理
		HT[i].weight = HT[lnode].weight + HT[rnode].weight;
//生成结点的权值等于最小结点的权值相加
	}
}
