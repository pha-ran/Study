// Directory

#include <stdio.h>
#include <windows.h>
#include <tchar.h>

int _tmain(void)
{
	TCHAR CurrentDirectory[MAX_PATH];
	TCHAR SystemDirectory[MAX_PATH];
	TCHAR WindowsDirectory[MAX_PATH];

	GetCurrentDirectory(MAX_PATH, CurrentDirectory);
	_tprintf(_T("%s\n"), CurrentDirectory);

	SetCurrentDirectory(_T("C:\\Users"));

	GetCurrentDirectory(MAX_PATH, CurrentDirectory);
	GetSystemDirectory(SystemDirectory, MAX_PATH);
	GetWindowsDirectory(WindowsDirectory, MAX_PATH);

	_tprintf(_T("%s\n"), CurrentDirectory);
	_tprintf(_T("%s\n"), SystemDirectory);
	_tprintf(_T("%s\n"), WindowsDirectory);

	return 0;
}