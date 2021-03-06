/*
Joseph Williamson
4103
mini project 2
fall 2019
This program runs an infinite loop to get info from the user
to add, subtract, createprocess, or end the loop
*/

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<string>
using namespace std;

void _tmain()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	WCHAR command[35] = L"notepad.exe";
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	string sign;
	int x = 1;
	int y = 0;

	while (true)
	{
		cin >> sign;

		if (sign == "+")
		{
			cin >> x;
			cin >> y;
			cout << x + y << endl;
		}
		if (sign == "-")
		{
			cin >> x;
			cin >> y;
			cout << x - y << endl;
		}

		if (sign == "%")
			return;

		if (sign == "notepad.exe")
		{
			// Start the child process.
			if (!CreateProcess(
				NULL, // No module name (use command line)
				(LPTSTR)command, // Command line
				NULL, // Process handle not inheritable
				NULL, // Thread handle not inheritable
				FALSE, // Set handle inheritance to FALSE
				0, // No creation flags
				NULL, // Use parent's environment block
				NULL, // Use parent's starting directory
				&si, // Pointer to STARTUPINFO structure
				&pi) // Pointer to PROCESS_INFORMATION structure
				)
			{
				printf("CreateProcess failed \n");
			}
			
		}
	}
	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);
	// Close process and thread handles.
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return;
}