#pragma once
#include <iostream>
#include <stdlib.h>//NULL
#include <string>

/*
TODO:
delete all pointers before setting them to null

*/

template <class T> class LinkedList;

template <class T>
class Node
{
public:
	friend class LinkedList<T>;
	Node()
	{

	}
	Node( Node & n)
	{
		value = n.getValue();
		nextNode = n.getNextNode();
	}
	Node(T _val , Node<T> * _next)
	{
		value = _val;
		nextNode = _next;
	}
	T getValue()
	{
		return value;
	}
	Node<T> * getNextNode()
	{
		return nextNode;
	}
	void setValue(T _val)
	{
		value = _val;
	}

private:
	Node<T> * nextNode;
	T value;
};

template <class T>
class LinkedList
{
public:

	template <class T1>
	friend std::ostream & operator <<(std::ostream& os, LinkedList<T1> &lst);



	LinkedList()
	{
		start = NULL;
	}

	bool isEmpty()
	{
		return start == NULL;
	}

	Node<T> * getStart()
	{
		return start;
	}
	Node <T> * getLast()
	{
		if (isEmpty())
			return start;

		Node <T> *p = start , * q = start->nextNode;
		while (q != NULL)
		{
			p = q;
			q = q->nextNode;
		}
		return p;
	}

	void mergeSort()
	{
		Node <T> * res = mergeSort(start);
		start = res;
	}

	void add(T val, bool addAtFirst = false)
	{

		if (isEmpty() || addAtFirst)
		{
			Node<T> * temp = start;
			start = new Node<T>;
			start->nextNode = temp;
			start->value = val;
		}
		else
		{
			Node<T> * link = getLast();
			Node<T> * temp = link->nextNode;
			link->nextNode = new Node<T>;
			link = link->nextNode;
			link->value = val;
			link->nextNode = temp;
		}
	}

	~LinkedList()
	{

	}

private:
	Node<T> * start;


	Node<T> * getMiddle(Node<T> * head) 
	{
    	if(head == NULL) 
    	{ 
    		return head;
    	}

	    Node<T> * slow, * fast;
	    slow = fast = head;
	    while(fast->nextNode != NULL && fast->nextNode->nextNode != NULL) 
	    {
	        slow = slow->nextNode;
	        fast = fast->nextNode->nextNode;
	    }
	    return slow;
	}

	Node<T> * merge(Node<T> * a, Node<T> * b) 
	{
	    Node<T> * newHead, *curr; 
	    newHead = new Node<T>();
	    curr = newHead;
	    while(a !=NULL && b!= NULL) 
	    {
	        if(a->value <= b->value) 
	        { 
	        	curr->nextNode = a;
	        	a = a->nextNode;
	        }
	        else 
	        { 
	        	curr->nextNode = b;
	        	b = b->nextNode;
	        }
	        curr = curr->nextNode;
	    }
	    curr->nextNode = (a == NULL) ? b : a;
	    return newHead->nextNode;
	    
	}

	Node<T> * mergeSort(Node<T> * head) 
	{
	    if(head == NULL || head->nextNode == NULL) 
	    { 
	    	return head;
	    }
	    Node<T> * middle = getMiddle(head);//get the middle of the list
	    Node<T> * sHalf = middle->nextNode;
	    middle->nextNode = NULL; //split the list into two halfs

	    return merge(mergeSort(head),mergeSort(sHalf));  //recurse on that
	}

};

template <class T>
std::ostream & operator <<(std::ostream& os, LinkedList<T> & lst)
{
	Node<T> * link = lst.start;
	if (lst.isEmpty())
		os << "Empty";
	os << std::endl;
	while (link != 0)
	{
		os << link->getValue() << "\t";
		link = link->getNextNode();
	}
	os << std::endl;
	return os;
}