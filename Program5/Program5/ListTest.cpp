#include <iostream>
#include <fstream>
#include "SortedList.h"
using namespace std;

//Purpose: To print the list to console
//Requires: l <SortedList>
//Returns: None
void printList(SortedList & l);

int main()
{
	
	
	SortedList l;
	string word1 = "banana";
	string word2 = "grape";
	string word3 = "apple";
	string word;
	bool found;

	//test constructor and isEmpty
	if (l.isEmpty())
		cout << "List should be empty and is.\n";
	else
		cout << "Error in isEmpty or list constructor.\n";

	//test insert word 
	l.insertword(word1);
	l.insertword(word2);
	l.insertword(word3);
	if (l.getLength() == 3)
	{
		cout << "Three words inserted into the list.\n";
	}
	else
	{
		cout << "Error: Did not insert three words into the list.\n";
	}


	system("pause");
	//test search word
	found = l.searchword(word2);
	if (found)
		cout << word2 << " is found correctly.\n";
	else
		cout << word2 << " is not found correctly, you have a problem in insert or search.\n";

	//print list
	cout << "The list should print 3 words: apple, banana, grape.\n";
	printList(l);

	l.clearList();

	l.insertword("pepe");
	l.insertword("petey");
	l.insertword("selena");
	l.insertword("ajax"); 
	l.insertword("tika");
	cout << "The list should print 5 words: ajax, pepe, petey, selena, tika.\n";
	printList(l);

	l.removeword("pepe");
	cout << "The list should print 4 words: ajax, petey, selena, tika.\n";
	printList(l);

	system("pause");
	return 0;
}

void printList(SortedList & l)
{
	string word;
	int freq;

	l.resetList();
	while (!l.atEnd())
	{
		l.retrieveNextword(word, freq);
		cout << word << "  " << freq << endl;
	}
}
