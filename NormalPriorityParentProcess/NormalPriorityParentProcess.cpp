// Normal Priority Parent Process

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(void)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	SecureZeroMemory(&si, sizeof(si));
	SecureZeroMemory(&pi, sizeof(pi));

	si.cb = sizeof(si);

	TCHAR commandLine[] = _T("HighPriorityChildProcess.exe");

	if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return -1;
	}

	while (1)
	{
		for (int i = 0; i < 10000; i++)
		{
			for (int j = 0; j < 10000; j++)
				;
		}

		_tprintf(_T("Parent\n"));
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}