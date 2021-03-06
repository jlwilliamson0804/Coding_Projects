#pragma once
#include<string>
#include<iostream>

using namespace std;

class athletes
{
public:

	athletes();
	athletes(string contestantName, double contestantNumber, double Dive, double Gym,
		double Box, double Skate, double Pose, double Total);
	~athletes();

	string getContestantName();
	void setContestantName(string newcontestantName);

	double getContestantNumber() const;
	void setContestantNumber(double newcontestantNumber);

	double getDiveScore() const;
	void setDiveScore(double newDive);

	double getGymScore() const;
	void setGymScore(double newGym);

	double getBoxScore() const;
	void setBoxScore(double newBox);

	double getSkateScore() const;
	void setSkateScore(double newSkate);

	double getPoseScore() const;
	void setPoseScore(double newPose);

	double getTotal() const;
	void setTotal(double newTotal);

private:
	
	string contestantName;
	double contestantNumber, Dive, Gym, Box, Skate, Pose, Total;

};
