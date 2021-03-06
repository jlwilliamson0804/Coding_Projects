
//Catherine Stringfellow and Joseph Williamson
//A SortedList is a list of words sorted in alphabetical order, together with a frequency
//count of each word

#ifndef SortedList_h
#define SortedList_h
#include <string>
using namespace std;

class SortedList
{
private:
	//A ListNode is a struct with values
	//word, frequency, and a pointer to
	//a next ListNode if given
	struct ListNode
	{
		//three member data for a node
		string word;
		int frequency;
		ListNode *nextl;

		//constructor for a Listnode
		ListNode(string word1, ListNode *next1 = NULL)
		{
			word = word1;
			frequency = 1;
			nextl = next1;
		}
	};

	//member data for list
	int length;
	ListNode *currentNodePtr;
	ListNode *head;

public:
	SortedList();

	//Make the list empty
	void clearList();

	//Returns: False
	bool isFull() const;

	//Returns: True if the list is empty and false otherwise
	bool isEmpty() const;

	//Returns: the number of words in the list
	int getLength() const;

	//Purpose: Inserts the word in the sorted list in the proper place
	//         current position will be at the word inserted
	//REQUIRES: word is NOT already in the list!!!	
	void insertword(const string & word);

	//Returns: True if word found in sorted list or false otherwise
	//         current position will be at the word if found	
	bool searchword(string & word);

	//Removes the first occurrence of the word from the sorted list 
	//current position will be at the word after the word removed, 
	//otherwise it will be at the end
	void removeword(const string & word);

	//set the current position to the first word in the list if there is one	
	void resetList();

	//Returns: True if current position is at the end of the list	
	bool atEnd();

	//Returns: The word and freq of the word that the current position is at, if current position
	//         is at a word AND  the current position is advanced to the next word
	void retrieveNextword(string & word, int & freq);

	//increments count of current word, if current position is at a word
	void updateFreqword();

	//Destructs the list
	~SortedList();
};

#endif