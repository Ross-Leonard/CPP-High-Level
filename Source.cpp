//John Ross Leonard
//CS 372
//General List Program


#include <iostream>
#include<iomanip>

using namespace std;
const int CAP = 20;
typedef int ET;

class List
{
private:
	ET aryList[CAP][2];
	int mySize;
	int pos;

public:
	List();
	List(List& aryList);
	void clear();
	void first();
	void prev();
	void next();
	void last();
	void replace(int, int);
	void setPos(int);
	void erase();
	void insertAfter(int, int);
	void insertBefore(int, int);
	int size();
	bool empty();
	int getXElement();
	int getYElement();
	int getPos();

	List operator= (List& aryListB);
	friend List operator + (List& ListA, List& ListB);
};
ostream& operator <<(ostream& outs, List& aryList);
List operator + (List& ListA, List& ListB);
bool operator == (List aryList1, List aryList2);


List::List()
{
	this->clear();
};
List::List(List& aryListB)
{
	this->clear();
	int orig_pos = aryListB.getPos();
	aryListB.first();
	for (int i = 0; i < aryListB.size(); aryListB.next(), i++)
	{
		this->aryList[i][0] = aryListB.getXElement();
		this->aryList[i][1] = aryListB.getYElement();
		this->mySize++;
	}
	this->pos = orig_pos;
	aryListB.setPos(orig_pos);
}
void List::clear()
{
	mySize = 0;
	pos = 0;
	int i;
	for (i = 0; i < CAP; i++)
	{
		aryList[i][0] = 0;
		aryList[i][1] = 0;
	}
}
void List::first()
{
	pos = 0;
}
void List::prev()
{
	if (pos > 0)
		pos--;
}
void List::next()
{
	if (pos < (mySize - 1))
		pos++;
}
void List::last()
{
	if (mySize > 0)
		pos = (mySize - 1);
	else
		pos = 0;
}
void List::replace(int a, int b)
{
	aryList[pos][0] = a;
	aryList[pos][1] = b;
}
void List::setPos(int newPos)
{
	if (newPos >= 0 && newPos < mySize)
		pos = newPos;
}
void List::erase()
{
	if (mySize > 0)
	{
		for (int i = pos; i < mySize - 1; i++)
		{
			aryList[i][0] = aryList[i + 1][0];
			aryList[i][1] = aryList[i + 1][1];
		}
		aryList[mySize - 1][0] = 0;
		aryList[mySize - 1][1] = 0;
		mySize -= 1;
	}
}
void List::insertAfter(int a, int b)
{
	if (pos >= CAP - 1)
		cout << "No insert made" << endl;
	else
	{
		for (int i = mySize; i > pos; i--)
		{
			
			aryList[i][0] = aryList[i + 1][0];			
			aryList[i][1] = aryList[i + 1][1];
		}
		if (mySize == 0)
		{			
			aryList[pos][0] = a;			
			aryList[pos][1] = b;
		}
		else
		{			
			aryList[pos + 1][0] = a;			
			aryList[pos + 1][b] = b;
			pos++;
		}
		mySize++;
	}
}
void List::insertBefore(int a, int b)
{
	if (pos == CAP - 1)
	{
		aryList[pos][0] = a;
		aryList[pos][1] = b;
	}
	else
	{
		for (int i = mySize; i >= pos && i != 0; i--)
		{
			aryList[i][0] = aryList[i + 1][0];
			aryList[i][1] = aryList[i + 1][1];
		}
		aryList[pos][0] = a;
		aryList[pos][1] = b;
		if (mySize < CAP)
			mySize++;
	}
}

int List::size()
{
	return mySize;
}
bool List::empty()
{
	return (size() == 0);
}
int List::getXElement()
{
	if (size() <= 0)
		return 0;
	else
		return aryList[pos][0];
}
int List::getYElement()
{
	if (size() <= 0)
		return 0;
	else
		return aryList[pos][1];
}
int List::getPos()
{
	return pos;
}
ostream& operator <<(ostream& outs, List& aryList)
{
	int orig_pos = aryList.getPos();
	aryList.first();
	outs << "[";
	for (int i = 0; i < aryList.size(); aryList.next(), i++)
	{
		outs  << aryList.getXElement() << " " << aryList.getYElement()<<", ";
	}	
		outs << "]";
	
	aryList.setPos(orig_pos);
	return outs;
}
List operator+(List& ListA, List& ListB)
{
	cout << "+ operator ";
	List ListC(ListA);
	int orig_pos = ListB.getPos();
	ListC.first();
	ListB.first();

	for (int i = 0; i < ListB.size(); ListB.next(), ListC.next(), i++)
	{
		ListC.replace(ListB.getXElement() + ListC.getXElement(), ListB.getYElement() + ListC.getYElement());
		cout << "+ operator ";
	}
	ListB.setPos(orig_pos);
	cout << "+ operator ";
	return ListC;
}
bool operator == (List aryList1, List aryList2)
{
	if (aryList1.size() == aryList2.size())
	{
		int orig_pos1 = aryList1.getPos();
		int orig_pos2 = aryList2.getPos();
		aryList1.first();
		aryList2.first();

		for (int i = 0; i < aryList1.size(); i++, aryList1.next(), aryList2.next())
		{
			if (aryList1.getXElement() != aryList2.getXElement() && aryList1.getYElement() != aryList2.getYElement())
			{
				aryList1.setPos(orig_pos1);
				aryList2.setPos(orig_pos2);
				return false;
			}
		}
		aryList1.setPos(orig_pos1);
		aryList2.setPos(orig_pos2);
		return true;
	}
	return false;
}
bool operator != (List aryList1, List aryList2)
{
	if (aryList1 == aryList2)
		return false;
	else
		return true;
}
List List::operator = (List& aryListB)
{
	int orig_pos = aryListB.getPos();
	aryListB.first();
	first();
	mySize = 0;

	for (int i = 0; i < aryListB.size(); aryListB.next(), this->next(), i++)
	{
		this->aryList[i][0] = aryListB.getXElement();
		this->aryList[i][1] = aryListB.getYElement();
		this->mySize++;
	}
	pos = orig_pos;
	aryListB.setPos(orig_pos);
	return aryListB;
}

int main()
{
	List a, b;  int endit;

	for (int i = 1; i <= 10; i++)
		a.insertAfter(i, i * 2);
	cout << "List a : " << endl;
	cout << "  " << a << endl;
	cout << "Number of elements in a - " << a.size() << endl;

	for (int i = 1; i <= 10; i++)
		b.insertBefore(i, i * 2);
	cout << "List b : " << endl;
	cout << "  " << b << endl;
	cout << "Number of elements in b - " << b.size() << endl;

	if (a == b)
		cout << "a == b:  List a & b are equal" << endl;
	else
		cout << "a == b:  List a & b are Not equal" << endl;

	a.first();
	b.first();
	cout << "First elmenet in list a " << a.getXElement() << "," << a.getYElement() << endl;
	cout << "First elmenet in list b " << b.getXElement() << "," << b.getYElement() << endl;
	a.last();
	b.last();
	cout << "Last elmenet in list a " << a.getXElement() << "," << a.getYElement() << endl;
	cout << "Last elmenet in list b " << b.getXElement() << "," << b.getYElement() << endl;

	cout << endl << endl << " Start of new stuff" << endl;

	b.erase();
	cout << "b.erase(): Print Empty List b:  " << b << endl;

	if (a != b)
		cout << "a != b:  List a & b are not equal" << endl;
	else
		cout << "a != b:  List a & b are equal" << endl;

	for (int i = 1; i <= 10; i++)
		b.insertBefore(i, -i * 2);
	cout << "List b with neg y's" << endl;
	cout << "List b: " << b << endl;

	a.setPos(5);
	b.first();
	for (int i = 1; i < 4; i++)
	{
		a.erase();
		b.replace(i, i * 3);
		b.next();
	}

	cout << "Modified Object 'a' (erase 3) " << endl;
	cout << "List a: " << a << endl;
	cout << "Modified Object 'b' (replace 3)" << endl;
	cout << "List b: " << b << endl;

	List c(b);
	cout << "Copy Constructor c(b)" << endl;
	cout << "List b : " << b << endl;
	cout << "List c : " << c << endl;

	List e;
	e = c;
	cout << "Object 'c' assigned to Object 'e':" << endl;
	cout << "List c : " << c << endl;
	cout << "List e : " << e << endl;

	List d;
	d = a;

	d.first();
	endit = d.size() / 2;
	for (int i = 1; i < endit; d.next(), i++)
	{
		d.insertBefore(d.getXElement() * 2, d.getYElement() * 2);
		d.next();
	}
	cout << "Results after some inserts at front of d " << endl;
	cout << "List d : " << d << endl;

	a.first();
	endit = a.size();
	for (int i = 1; i < endit; a.next(), i++)
	{
		a.replace(a.getPos() - a.getXElement(), a.getPos() - a.getYElement());
		a.next();
	}
	cout << "Results after adding pos & flipping signs on list a" << endl;
	cout << "List a : " << a << endl;

	List alist(b);
	alist.clear();
	for (int i = 1; i <= 5; i++)
		alist.insertAfter(i, i * 5);
	alist.first();
	cout << "New List alist with positions printed above: " << endl;
	for (int i = 1; i <= 5; i++) {
		cout << setw(8) << alist.getPos();
		alist.next();
	}
	cout << endl;
	alist.first();
	for (int i = 1; i <= 5; i++) {
		cout << setw(6) << alist.getXElement() << "," << alist.getYElement();
		alist.next();
	}
	cout << endl;

	cout << endl << "  check out boundary conditions" << endl;
	List sq;
	cout << "number of elements in empty sq list = " << sq.size() << endl;
	cout << " print empty list sq: " << sq << endl;
	sq.first();
	sq.erase(); sq.erase();
	cout << "First elmenet in list a " << a.getXElement() << "," << a.getYElement() << endl;
	sq.setPos(5);
	cout << "empty sq values " << sq << endl;
	sq.insertBefore(333, 444);
	cout << "sq list: " << sq << endl;
	sq.next(); sq.next();
	cout << "sq.getElement() = " << sq.getXElement() << "," << sq.getYElement() << endl;
	cout << "sq list = " << sq << endl;
	sq.prev(); sq.prev();
	cout << "sq.getElement() = " << sq.getXElement() << "," << sq.getYElement() << endl;
	cout << "sq list = " << sq << endl;

	system("pause");
	return 0;
}