// C++ implementation of FIFO page replacement 
// in Operating Systems.
#include <iostream>
#include <queue>
#include<deque>
#include <ctime>
#include<cstdlib>

using namespace std;
int fifo_test(int page_array[], deque<int> frames);
int second_chance(int page_array[], deque<int> frames);

int main()
{
	int page_array[100]; // pages
	int test[] = { 7,0,1,2,0,3,0,4,2,3,0,3,2 };
	deque<int> frames; // frames
	int page_faults = 0;

	//fills page array with values 0
	for (int i = 1; i < 101; i++)
		page_array[i] = 0;
	
	cout << "FIFO -" << fifo_test(page_array, frames) <<endl;
	cout << "2nd Chance -" << second_chance(page_array, frames) << endl;

	system("pause");
	return 0;
}

int fifo_test(int page_array[], deque<int> frames)
{
	int faults = 0;

	for (int i = 0; i < 10000; i++)//loop 10k times
	{
		int exists = 0; // 0 not there, 1 is there
		int page = (rand() % 100) +1; //rand number lol
		
		for (int j = 0; j < frames.size(); j++)
		{
			if (frames[j] == page)
				exists = 1;
		}
		if (frames.size() < 20 && exists == 0)
			frames.push_back(page);
		else if (frames.size() < 20 && exists == 1)
			page = page;
		else if (frames.size() >= 20 && exists == 0)
		{
			faults++;
			frames.pop_front();
			frames.push_back(page);
		}
		else page = page;
	}

	return faults;
}

int second_chance(int page_array[], deque<int> frames)
{
	int faults = 0;
	bool chance = true;
	int exists = 0; // 0 not there, 1 is there

	for (int i = 0; i < 10000; i++)
	{

		int page = (rand() % 100) + 1; //rand number lol
		page_array[page] = 1;

		for (int j = 0; j < frames.size(); j++)
		{
			if (frames[j] == page)
				exists = 1;
		}
		if (frames.size() < 20 && exists == 0)
			frames.push_back(page);
		else if (frames.size() < 20 && exists == 1)
			page = page;
		else if (frames.size() >= 20 && exists == 0 && page_array[page]==0)
		{
			
		}
		else page = page;
	}
	
	return faults;
}