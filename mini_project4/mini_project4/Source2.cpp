#include <iostream>
#include <queue>
#include "time.h"

using namespace std;

int main()
{
	queue <int> FrameArray; //pages in use
	int PageArray[100]; //page numbers
	int PageInUse[100] = { 0 }; //is it in the FrameArray
	int PageReference[100] = { 0 }; //refrefence bit
	int r = 0; //random page number
	int faults = 0;
	int x = 0;

	//FIFO test
	for (int i = 0; i < 10000; i++)
	{
		r = (rand() % 100) + 1;

		if (PageInUse[r] == 0 && FrameArray.size() < 20)
		{
			FrameArray.push(r);
			PageInUse[r] = 1;
		}
		else if (PageInUse[r] == 0 && FrameArray.size() >= 20)
		{
			x = FrameArray.front();
			PageInUse[x] = 0;
			FrameArray.pop();
			FrameArray.push(r);
			faults++;
		}
	}

	cout << faults << endl;

	//2nd chance test
	faults = 0;
	for (int i = 0; i < 10000; i++)
	{
		r = (rand() % 100) + 1;

		if (PageInUse[r] == 0 && FrameArray.size() < 20)
		{
			FrameArray.push(r);
			PageInUse[r] = 1;
		}
		else
		{
			if (PageReference[FrameArray.front()] == 0)
			{
				FrameArray.pop();
				FrameArray.push(r);
				faults++;
			}
			else if (PageReference[FrameArray.front()] == 1)
			{
				PageReference[r] = 0;
				int x = FrameArray.front();
				FrameArray.pop();
				FrameArray.push(x);
				PageInUse[x] = 0;
				faults++;
			}
		}
	}
	cout << endl << faults << " ";

	system("pause");
	return 0;
}