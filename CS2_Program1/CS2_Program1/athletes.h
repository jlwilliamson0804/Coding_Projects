#pragma once
#include<string>

class athletes
{
public:

	athletes();
	athletes(string contestantName, double scores, double total);
	~athletes();

	string getContestantName();
	void setContestantName();

	double getScores();
	void setScores();

	double getTotal();
	void setTotal();


};

