#include "Athletes.h"
#include<string>

using namespace std;


athletes::athletes()
{
	string contestantName = " ";
	double contestantNumber = 0;
	double Dive = 0;
	double Gym = 0;
	double Box = 0;
	double Skate = 0;
	double Pose = 0;
	double Total = 0;
}


athletes::~athletes()
{

}

string athletes::getContestantName()
{
	return contestantName;
}

void athletes::setContestantName(string newcontestantName)
{
	contestantName = newcontestantName;
}

double athletes :: getContestantNumber() const
{
	return contestantNumber;
}

void athletes::setContestantNumber(double newcontestantNumber)
{
	contestantNumber = newcontestantNumber;
}

double athletes::getDiveScore() const
{
	return Dive;
}

void athletes::setDiveScore(double newDive)
{
	Dive = newDive;
}

double athletes::getGymScore() const
{
	return Gym;
}
void athletes::setGymScore(double newGym)
{
	Gym = newGym;
}

double athletes :: getBoxScore() const
{
	return Box;
}
void athletes :: setBoxScore(double newBox)
{
	Box = newBox;
}

double athletes :: getSkateScore() const
{
	return Skate;
}
void athletes::setSkateScore(double newSkate)
{
	Skate = newSkate;
}

double athletes::getPoseScore() const
{
	return Pose;
}
void athletes::setPoseScore(double newPose)
{
	Pose = newPose;
}

double athletes::getTotal() const
{
	return Total;
}

void athletes::setTotal(double newTotal)
{
	Total = newTotal;
}

athletes::athletes(string newcontestantName, double newcontestantNumber, double newDive, double newGym,
	double newBox, double newSkate, double newPose, double newTotal)
{
	contestantName = newcontestantName;
	contestantNumber = newcontestantNumber;
	Dive = newDive;
	Gym = newGym;
	Box = newBox;
	Skate = newSkate;
	Pose = newPose;
	Total = newTotal;
}
