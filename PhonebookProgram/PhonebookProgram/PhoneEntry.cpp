//Joseph Williamson

#include "PhoneEntry.h"
#include<string>

using namespace std;

PhoneEntry::PhoneEntry()
{
	string PersonName = " ";
	string PersonNum = " ";
}


PhoneEntry::~PhoneEntry()
{
}

string PhoneEntry::getPersonName()
{
	return PersonName;
}

void PhoneEntry::setPersonName(string newPersonName)
{
	PersonName = newPersonName;
}

string PhoneEntry::getPersonNum()
{
	return PersonNum;
}

void PhoneEntry::setPersonNum(string newPersonNum)
{
	PersonNum = newPersonNum;
}

void PhoneEntry::swapEntry(PhoneEntry& entryTwo)
{
	string tempName;
	string tempNum;

	tempName = entryTwo.PersonName;
	tempNum = entryTwo.PersonNum;

	entryTwo.PersonName = PersonName;
	entryTwo.PersonNum = PersonNum;
	
	PersonName = tempName;
	PersonNum = tempNum;
}