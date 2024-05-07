// Mailslot Sender

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define MAILSLOT_NAME _T("\\\\.\\mailslot\\test")

int _tmain(void)
{
	HANDLE mailSlot;
	TCHAR message[64];
	DWORD size;

	mailSlot =
		CreateFile(MAILSLOT_NAME, GENERIC_WRITE, FILE_SHARE_READ,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	for (;;)
	{
		_tscanf_s(_T("%s"), message, sizeof(TCHAR) * 64);

		WriteFile(mailSlot, message,
			sizeof(TCHAR) * _tcslen(message), &size, NULL);

		if (!_tcscmp(message, _T("exit")))
			break;
	}

	CloseHandle(mailSlot);

	return 0;
}
