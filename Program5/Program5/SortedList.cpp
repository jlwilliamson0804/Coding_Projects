#include "SortedList.h"
#include <iostream>

using namespace std;

SortedList::SortedList()
{

}
void SortedList::clearList()
{
	resetList();
	while (!atEnd())
	{
		currentNodePtr = currentNodePtr -> nextl;
		delete head;
		head = currentNodePtr;
	}
	length = 0;
}

bool SortedList::isFull() const
{
	return false;
}

bool SortedList::isEmpty() const
{
	if (head == NULL)
		return true;
	else return false;
}

int SortedList::getLength() const
{
	return length;
}

void SortedList::insertword(const string& word)
{
	resetList();
	
	ListNode *newNode; // Node to be inserted
	newNode = new ListNode(word);
	ListNode *prevNode;
	prevNode = currentNodePtr; // keep track of previous node

	//if list is empty
	if (head == NULL)
	{
		head = newNode;
		currentNodePtr = head;
		length++;
	}

	else if (head->word.compare(word) > 0 && currentNodePtr->nextl != NULL)
	{
		newNode->nextl = head;
		head = newNode;
		length++;
	}
	
	else
	{
		while (currentNodePtr->nextl != NULL && currentNodePtr->word.compare(word) < 0)
		{
			prevNode = currentNodePtr;
			currentNodePtr = currentNodePtr->nextl;
		}

		if (currentNodePtr->word.compare(word) == 0)
		currentNodePtr->frequency++;

		else
			{
				newNode->nextl = currentNodePtr->nextl;
				currentNodePtr->nextl = newNode;
				length++;
			}

	}
}

bool SortedList::searchword(string & word)
{
	bool found = false;
	resetList();

	while (!atEnd() && !found)
	{
		if (word.compare(currentNodePtr->word) == 0)
			found = true;
		else if (word.compare(currentNodePtr->word) == -1)
			found = false;
		else
			currentNodePtr = currentNodePtr->nextl;
	}

	return found;
}

void SortedList::removeword(const string& word)
{
	resetList();
	ListNode *prevNode;
	prevNode = new ListNode(word);

	//if the list is empty, do nothing
	if (isEmpty() == true)
		cout << "list is empty" << endl;
	else
	{
		//Determine if the first node is the one to delete
		if (head->word == word)
		{
			currentNodePtr = currentNodePtr->nextl;
			delete head;
			head = currentNodePtr;
		}

		//else
		else
		{
			//initialize currentNodePtr to head of list
			currentNodePtr = head;

			//skip all nodes whose word member is not equal to word
			while (word.compare(currentNodePtr->word) != 0)
				currentNodePtr = currentNodePtr->nextl;

			//link the previous node to the node after currentNodePtr, then delete currrentNodePtr
			prevNode->nextl = currentNodePtr;
			delete currentNodePtr;
		}
		//decrement length
		length--;
	}
}

void SortedList::resetList()
{
	currentNodePtr = head;
}

void SortedList::retrieveNextword(string & word, int & count)
{
	word = currentNodePtr->word;
	count = currentNodePtr->frequency;

	currentNodePtr = currentNodePtr->nextl;
}

void SortedList::updateFreqword()
{
	currentNodePtr->frequency++;
}

bool SortedList::atEnd()
{
	if (currentNodePtr == NULL)
		return true;

	else
		return false;
}

SortedList::~SortedList()
{
	//clear list and set length to -1
	clearList();
	length = -1;
}
