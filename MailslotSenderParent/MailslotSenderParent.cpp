// Mailslot Sender Parent

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define MAILSLOT_NAME _T("\\\\.\\mailslot\\test")

int _tmain(void)
{
	HANDLE mailSlot;
	TCHAR message[64];
	DWORD size;

	SECURITY_ATTRIBUTES sa;

	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	mailSlot = CreateFile(
		MAILSLOT_NAME, GENERIC_WRITE, FILE_SHARE_READ,
		&sa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
	);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	SecureZeroMemory(&si, sizeof(si));
	SecureZeroMemory(&pi, sizeof(pi));

	si.cb = sizeof(si);

	TCHAR commandLine[64];
	_stprintf_s(
		commandLine, sizeof(TCHAR) * 64,
		_T("MailslotSenderChild.exe %lld"), mailSlot
	);

	CreateProcess(
		NULL, commandLine, NULL, NULL,
		TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi
	);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

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