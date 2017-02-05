//
//  LinkedList.h
//  Linked_List_Template
//

#ifndef LinkedList2_h
#define LinkedList2_h

#include <stdio.h>
#include <iostream>
using namespace std;

/* A singly-linked list node */
template <class T>
struct Node
{
    T data;
    //Node *next;
    Node<T> *next;
};

/* A class for a singly-linked list */
template <class T>
class LinkedList
{
public:
  LinkedList();       // Constructor: Inits an empty singly-linked list
  ~LinkedList();      // Destructor: Destroys the singly-linked list 
  int size();         // Returns the size of the singly-linked list
  bool contains(T x);  // Returns true if x is in the list, otherwise returns false
  bool add(T x);    // Adds x if not already in the list and returns true, otherwise returns false
  bool remove(T x); // Removes x if in the list and returns true, otherwise returns false
  void print();       // Prints the content of the singly-linked list

private:
  Node<T> *head;         // Pointer to head of singly-linked list
  int listSize;       // Size of singly-linked list
};
//endif /*LinkedList_h */

template <class T>
LinkedList<T>::LinkedList()
{
  //Node singleNode;
  //singleNode = {.data = 0, .next = NULL};
  //Node *head = NULL;
  head = NULL;
  listSize = 0;

}

template <class T>
LinkedList<T>::~LinkedList()
{

}

template <class T>
int LinkedList<T>::size()
{
  return listSize;

}

template <class T>
bool LinkedList<T>::contains(T x)
//bool LinkedList::contains(int x)
{
  Node<T> *temp = head;
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

template <class T>
bool LinkedList<T>::add(T x)
//bool LinkedList::add(int x)
{
  if (head == NULL)
  {
    Node<T> *newNode = new Node<T>;
    head = newNode;
    head->data = x;
    head->next = NULL;
    listSize++;
    return true;
  }
  else
  {
    Node<T> *temp = head;
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
    Node<T> *newNode = new Node<T>;
    newNode->data = x;
    newNode->next = NULL;
    temp->next = newNode;
    listSize++;
    return true;
  }
  //return false;

}

template <class T>
bool LinkedList<T>::remove(T x)
//bool LinkedList::remove(int x)
{
  Node<T> *prev = head;
  Node<T> *current = head;
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
  listSize--;
  return false;

}

template <class T>
void LinkedList<T>::print()
{
  Node<T> *temp = head;
  while(temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}



/* LinkedList2_h */
#endif 

