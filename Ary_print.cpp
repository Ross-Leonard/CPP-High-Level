#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


struct Node
{
	char val;
	Node* rchild, * lchild;
};
Node* head;
void ptrAgain(Node* p)
{
	if (p == NULL)
		return;
	ptrAgain(p->lchild);
	cout << p->val;
	ptrAgain(p->rchild);
}
void ptr(Node* p)
{
	if (p == NULL)
	{
		return;
	}
	ptr(p->lchild);
	ptr(p->rchild);
	cout << "\n-";
	ptrAgain(p);
}

Node* myNewNode()
{
	Node* temp;
	temp = new Node;
	temp->val = 0;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

void insert(Node* r, int v)
{
	Node* prev;
	prev = NULL;

	if (r->val == v)
	{

	}
	while (r != NULL)
	{
		//cout << " r->val = " << r->val;
		prev = r;
		if (v < r->val)
			r = r->lchild;
		else
			r = r->rchild;
	}
	r = myNewNode();
	r->val = v;
	//r->count = 1;
	if (prev == NULL)
	{
		head = r;
		//cout << " head= " << head;
	}
	if (prev != NULL)
	{
		if (v < prev->val)
		{
			prev->lchild = r;
		}
		else
		{
			prev->rchild = r;
		}
	}
}

int main()
{
	
	char ary[15] = { 'A','B','C','D','E','F','G','H','I','J','K','L' };
	for (int i = 0; i < 15; i++)
	{
		insert(head, ary[i]);
	}
	ptr(head);

	cout << "\n-";

	system("pause");
	return 0;

}