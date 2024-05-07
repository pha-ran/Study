// Mailslot Receiver

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define MAILSLOT_NAME _T("\\\\.\\mailslot\\test")

int _tmain(void)
{
	HANDLE mailSlot;
	TCHAR message[64];
	DWORD size;

	mailSlot = CreateMailslot(MAILSLOT_NAME, 0, MAILSLOT_WAIT_FOREVER, NULL);

	for (;;)
	{
		ReadFile(mailSlot, message, sizeof(TCHAR) * 64, &size, NULL);

		message[size / sizeof(TCHAR)] = NULL;

		_tprintf(_T("%s\n"), message);

		if (!_tcsncmp(message, _T("exit"), 4))
			break;
	}

	CloseHandle(mailSlot);

	return 0;
}
