// Adder Parent Process

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(void)
{
	DWORD sum1;
	DWORD sum2;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	// sum1
	SecureZeroMemory(&si, sizeof(si));
	SecureZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(si);

	TCHAR commandLine1[] = _T("AdderChildProcess.exe 1 5");
	CreateProcess(NULL, commandLine1, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &sum1);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	// sum2
	SecureZeroMemory(&si, sizeof(si));
	SecureZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(si);

	TCHAR commandLine2[] = _T("AdderChildProcess.exe 6 10");
	CreateProcess(NULL, commandLine2, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &sum2);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	// sum1 + sum2
	_tprintf(_T("%d\n"), sum1 + sum2);

	return 0;
}
