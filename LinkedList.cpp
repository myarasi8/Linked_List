#include <iostream>
#include "LinkedList.h"
//#include "LinkedList2.h"
using namespace std;

LinkedList::LinkedList()
{
	//Node singleNode;
	//singleNode = {.data = 0, .next = NULL};
	//Node *head = NULL;
	head = NULL;
	listSize = 0;

}

LinkedList::~LinkedList()
{

}

int LinkedList::size()
{
	return listSize;

}


bool LinkedList::contains(int x)
//bool LinkedList::contains(int x)
{
	Node *temp = head;
	while (temp->next != NULL)
	{
		if (temp->data == x)
		{
			return true;
		}
		else
		{
			temp = temp->next;
		}
	}
	return false;
}


bool LinkedList::add(int x)
//bool LinkedList::add(int x)
{
	if (head == NULL)
	{
		Node *newNode = new Node;
		head = newNode;
		head->data = x;
		head->next = NULL;
		listSize++;
		return true;
	}
	else
	{
		Node *temp = head;
		while(temp->next != NULL)
		{
			if (temp->data == x)
			{
				return false;
			}
			else
			{
				temp = temp->next;
			}
		}
		Node *newNode = new Node;
		newNode->data = x;
		newNode->next = NULL;
		temp->next = newNode;
		listSize++;
		return true;
	}
	//return false;

}

bool LinkedList::remove(int x)
//bool LinkedList::remove(int x)
{
	Node *prev = head;
	Node *current = head;
	while(current != NULL)
	{
		if (current->data == x)
		{
			//remove value
			if (current == head)
			{
				head = current->next;
				delete current;
				listSize--;
				return true;
			}
			if (current == NULL)
			{
				cout << "Can't remove value" << endl;
			}
			else
			{
				cout << "Deleting: " << current->data << endl;
				prev->next = current->next;
				delete current;
				listSize--;
				return true;
			}
		}
		else
		{
			cout << "Value " << current->data << " does not match " << x << endl;
			prev = current;
			current = current->next;
		}
	}

	return false;

}

void LinkedList::print()
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}











