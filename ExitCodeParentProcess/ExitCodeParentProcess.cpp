// Exit Code Parent Process

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(void)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD code;

	SecureZeroMemory(&si, sizeof(si));
	SecureZeroMemory(&pi, sizeof(pi));

	si.cb = sizeof(si);

	TCHAR commandLine[] = _T("ExitCodeChildProcess.exe");

	if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		_tprintf(_T("CreateProcess failed (%d).\n"), GetLastError());
		return -1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);

	GetExitCodeProcess(pi.hProcess, &code);

	_tprintf(_T("Get Exit Code : %d\n"), code);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}