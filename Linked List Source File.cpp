//John Ross Leonard
//CS 372
//Printing Linked List in reverse


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
	string name;
	Node* linky;
};

Node* head;
Node* cp;

void printlinklist(ofstream& outfile, Node* cp);
Node* MyNewNode();
void insert(Node* cp, string f);
Node* search(Node* c, string targ);
int size(Node* c);
void deleteit(Node* c, int buffsize);
void deleteit2(Node* c, string targ);

Node* MyNewNode()
{
	Node* temp;
	temp = new Node;
	temp->name.clear();
	temp->linky = NULL;
	return temp;
}

void insert(Node* cp, string target)
{
	Node* p;
	Node* t;
	p = NULL;
	t = MyNewNode();
	t->name = target;
	t->linky = cp;
	if (p != NULL)
	{
		p->linky = t;
	}
	else
	{
		head = t;
	}
}

void printlinklist(ofstream& outfile, Node* cp)
{
	if (cp == NULL)
		return;
			
	printlinklist(outfile,cp->linky);
	outfile << cp->name << endl;	
}
Node* search(Node* c, string targ)
{
	while (c != NULL && c->name != targ)
	{
		c = c->linky;
	}
	return c;
}
int size(Node* c)
{
	int count = 0;
	while (c != NULL)
	{
		c = c->linky;
		count++;
	}
	return count;
}
void deleteit(Node* c, int buffsize)
{
	Node* p;
	p = NULL;
	int count = 1;
	while (count < buffsize)
	{
		p = c;
		c = c->linky;
		count++;
	}
	p->linky = c->linky;
	delete c;
}
void deleteit2(Node* c, string targ)
{
	Node* p;
	p = NULL;
	if (c->name == targ)
	{
		c = c->linky;
		head = c;
	}
	else
	{
		while (c != NULL && c->name != targ)
		{
			p = c;
			c = c->linky;
		}
		p->linky = c->linky;
		delete c;
	}
}


int main()
{
	int buffsize = 4;
	int mem, listsize;
	ifstream infile;
	ofstream outfile;
	infile.open("LinkL Var Stream.txt");
	outfile.open("link results.txt");
	string name;

	while (buffsize < 9)
	{
		if (!infile)
		{
			cout << "error opening, shutting down.";
			system("pause");
			return 0;
		}

		mem = 0;
		while (infile >> name)
		{
			if (search(head, name))
			{
				deleteit2(head, name);
				insert(head, name);
			}
			else
			{
				listsize = size(head);
				if (listsize == buffsize)
				{
					deleteit(head, listsize);
					insert(head, name);
					mem++;
				}
				if (listsize < buffsize)
				{
					insert(head, name);
					mem++;
				}
			}
		}

		infile.close();
		outfile << "Buffer Size = " << buffsize << " " << " Memory Accessess = " << mem << " Variables in buffer " << endl;

		printlinklist(outfile, head);
		outfile << endl << endl;
		buffsize++;
	}
	system("pause");
	return 0;
}