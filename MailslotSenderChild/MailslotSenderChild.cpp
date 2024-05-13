// Mailslot Sender Child

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE mailSlot = (HANDLE)_tstoll(argv[1]);
	TCHAR message[64];
	DWORD size;

	for (;;)
	{
		_tscanf_s(_T("%s"), message, sizeof(TCHAR) * 64);

		WriteFile(
			mailSlot, message,
			sizeof(TCHAR) * _tcslen(message), &size, NULL
		);

		if (!_tcscmp(message, _T("exit")))
			break;
	}

	CloseHandle(mailSlot);

	return 0;
}