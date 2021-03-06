// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"             // remove if you aren't using microsoft visual studio
#include<iostream>
#include<process.h>


using namespace std;

struct Node
{
	float prob;
	short index;
	Node* next;
	Node* prev;
};


class symbolList
{
public:
    void addSymbol(float probab, short dex);
	void displayList();
	void sortList(short n);
	bool validateList();
	symbolList();
	~symbolList();


private:
	Node *first, *last, *current, *current1, *after, *temp, *temp1;
	bool flag;
	float sum = 0;

	void swapNodes(/*Node* n1, Node* n2*/);

};


//******************************************************************** constructor of symbolList

symbolList::symbolList()
{
	first = NULL;
	last = NULL;
	flag = false;

}


//********************************************************************* destructor of symbolList

symbolList::~symbolList()
{
	cout << "\n*******************end*********************";
}


//*******************************************************************function to insert a symbol in list

void symbolList::addSymbol(float probab, short dex)
{
	Node* newNode = new Node;
	newNode->prob = probab;
	newNode->index = dex;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (flag)
	{   
		newNode->prev = last;
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
	else
	{
		flag = true;
		first = newNode;
		last = newNode;

	}

}

//*****************************************************************a function to check wheteher the probabilties aer valid

bool symbolList::validateList()
{
	sum = 0;
	current = first;
	while (current)
	{
		sum += current->prob;
		current = current->next;
	}

	if (sum = 1) return true;
	else return false;
}





//***********************************************************************a function to display the list
void symbolList::displayList()
{
	current1 = last;
	while (current1 != NULL)
	{
		cout << "\n probability of symbol x" << current1->index << " is " << current1->prob;
		current1 = current1->prev;
	}

}


//********************************************************************** function to sort the list
void symbolList::sortList(short n)
{
	
	for (short x = 0; x < n; x++)
	{
		current = first;
		for (short y = 0; y < n; y++)
		{ 	
			if (current->next!= NULL)
			{
				after = current->next;
				if (current->prob < after->prob)
				{				
					swapNodes();					
					current = after;	
				}	
				current = current->next;
								
			}
			else break;
		}
	}
}

//********************************************************** function to swap the two adjacent nodes
void symbolList::swapNodes()
{
       	if (current == first) first = after;
    	if (after == last) last = current;
		if (current->prev != NULL)  (current->prev)->next = after;  //1
		if (after->prev)  after->prev->next = current;       //2
		if (after->next) after->next->prev = current;        //4	
		temp = current->prev;                         //5
	    temp1 = after->next;                     //6
	    after->prev = temp;               //7
		current->prev = after;                              //8
		current->next = temp1;               //9
		after->next = current;              //10
}





//************************************************************ function main

int main()
{
	float probability;
	short nos,i;
	symbolList list;
	cout << "\n enter the number of symbols \t";
	cin >> nos;

	for (i = 0; i < nos; i++)
	{
		cout << "enter the probability of x" << (i + 1)<<"\t";
		cin >> probability;
		list.addSymbol(probability, (i + 1));
	}

	if (list.validateList())
	{
		cout << "\nsum of probabilities is equal to 1, data validated";
	}
	else
	{
	    cout << "\nsum of probabilities is not equal to 1, data  not validated, exiting..........";
		exit(EXIT_SUCCESS);
	}

	list.displayList();
	list.sortList(nos);
	cout << "\nsorted list \n";
	list.displayList();

	return 0;
}