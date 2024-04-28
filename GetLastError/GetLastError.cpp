#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(void)
{
	TCHAR CurrentDirectory[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, CurrentDirectory);
	_tprintf(_T("error code %d \n"), GetLastError());

	SetCurrentDirectory(NULL);
	_tprintf(_T("error code %d \n"), GetLastError());

	return 0;
}