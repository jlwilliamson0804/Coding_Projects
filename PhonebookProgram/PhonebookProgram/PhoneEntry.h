//Joseph Williamson

#pragma once
#include<string>
#include<iostream>

using namespace std;

class PhoneEntry
{
public:
	PhoneEntry();
	~PhoneEntry();

	string getPersonName();
	void setPersonName(string newPersonName);

	string getPersonNum();
	void setPersonNum(string newcontestantNumber);

	void swapEntry(PhoneEntry& entryTwo);

private:
	string PersonName;
	string PersonNum;
};
