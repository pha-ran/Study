/*
	명령 프롬프트 프로젝트
*/

//#undef UNICODE
//#undef _UNICODE

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <locale.h>

#define MAX_STR_LEN 400
#define MAX_TOK_NUM 200

int ___istupper(_TINT c);
int ___istlower(_TINT c);
int ___totupper(_TINT c);
int ___totlower(_TINT c);
int ___tcscpy_s(LPTSTR dest, rsize_t dest_size, LPCTSTR src);
int ___tcscmp(LPCTSTR string1, LPCTSTR string2);
LPTSTR ___tcstok_s(LPTSTR str, LPCTSTR delimiters, TCHAR** context);
LPTSTR ___tcslwr(LPTSTR str);
int commandProcessing(int num);

LPCTSTR titleString = _T("명령 프롬프트 프로젝트 ( %zd 바이트 시스템 / 문자 크기 %zd )\n\n");
LPCTSTR errorString = _T("'%s'은(는) 내부 또는 외부 명령, 실행할 수 있는 프로그램, 또는 배치 파일이 아닙니다.\n");
LPCTSTR seps = _T(" ,\t\n");

TCHAR commandString[MAX_STR_LEN];
TCHAR tokenList[MAX_TOK_NUM][MAX_STR_LEN];

int _tmain(int argc, TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"korean");

	if (argc > 1)
	{
		for (int index = 1; index < argc; ++index)
		{
			___tcscpy_s(tokenList[index - 1], MAX_STR_LEN, argv[index]);
			___tcslwr(tokenList[index - 1]);
		}

		if (!commandProcessing(argc - 1))
			return 0;
	}
	else
	{
		_tprintf(titleString, sizeof(SIZE_T), sizeof(TCHAR));
	}
	
	while (commandProcessing(0));

	return 0;
}

int ___istupper(_TINT c)
{
	if (c >= _T('A') && c <= _T('Z'))
		return 1;

	return 0;
}

int ___istlower(_TINT c)
{
	if (c >= _T('a') && c <= _T('z'))
		return 1;

	return 0;
}

int ___totupper(_TINT c)
{
	if (___istlower(c))
	{
		int temp = _T('a') - _T('A');
		c -= temp;
	}

	return c;
}

int ___totlower(_TINT c)
{
	if (___istupper(c))
	{
		int temp = _T('a') - _T('A');
		c += temp;
	}

	return c;
}

int ___tcscpy_s(LPTSTR dest, rsize_t dest_size, LPCTSTR src)
{
	if (!dest)
		return -1;

	if (!src)
	{
		dest[0] = NULL;
		return -1;
	}

	for (rsize_t index = 0; index < dest_size; ++index)
	{
		dest[index] = src[index];

		if (!dest[index])
			return 0;
	}

	dest[0] = NULL;

	return -1;
}

int ___tcscmp(LPCTSTR string1, LPCTSTR string2)
{
	if (!string1 || !string2)
		return -1;

	while (*string1 == *string2)
	{
		if (*string1 == _T('\0'))
			return 0;

		++string1;
		++string2;
	}

	return -1;
}

LPTSTR ___tcstok_s(LPTSTR str, LPCTSTR delimiters, TCHAR** context)
{
	if (!delimiters || !context)
		return NULL;

	if (str)
		*context = str;

	if (**context == NULL)
		return NULL;

	while (**context)
	{
		int flag = 0;

		for (rsize_t index = 0; delimiters[index] != NULL; index++)
		{
			if (**context == delimiters[index])
			{
				flag = 1;
				break;
			}
		}

		if (flag)
			++(*context);
		else
			break;
	}

	LPTSTR temp = *context;

	while (**context)
	{
		for (rsize_t index = 0; delimiters[index] != NULL; index++)
		{
			if (**context == delimiters[index])
			{
				**context = NULL;
				++(*context);
				return temp;
			}
		}

		++(*context);
	}

	return temp;
}

LPTSTR ___tcslwr(LPTSTR str)
{
	for (int index = 0; str[index] != NULL; index++)
	{
		if (___istupper(str[index]))
			str[index] = ___totlower(str[index]);
	}

	return str;
}

int commandProcessing(int num)
{
	if (!num)
	{
		_tprintf(_T("명령어>"));

		_getts_s(commandString, _countof(commandString));

		TCHAR* context = NULL;
		TCHAR* token = ___tcstok_s(commandString, seps, &context);

		if (!token)
			return -1;

		while (token)
		{
			___tcscpy_s(tokenList[num], MAX_STR_LEN, ___tcslwr(token));
			++num;
			token = ___tcstok_s(NULL, seps, &context);
		}
	}

	if (!___tcscmp(tokenList[0], _T("exit")))
		return 0;
	else if (!___tcscmp(tokenList[0], _T("echo")))
	{
		for (int index = 1; index < num; ++index)
			_tprintf(_T("%s "), tokenList[index]);

		_tprintf(_T("\n\n"));
	}
	else if (!___tcscmp(tokenList[0], _T("start")))
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		SecureZeroMemory(&si, sizeof(si));
		SecureZeroMemory(&pi, sizeof(pi));

		si.cb = sizeof(si);

		TCHAR arg[MAX_STR_LEN + 18] = _T("CommandPrompt.exe");
		int len = 17;

		for (int tIndex = 1; tIndex < num; ++tIndex)
		{
			arg[len] = _T(' ');
			++len;

			for (int sIndex = 0; tokenList[tIndex][sIndex] != _T('\0'); ++sIndex, ++len)
				arg[len] = tokenList[tIndex][sIndex];
		}

		arg[len] = _T('\0');

		if (!CreateProcess(NULL, arg, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
		{
			_tprintf(errorString, tokenList[0]);
			_tprintf(_T("\n"));

			return -1;
		}

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		_tprintf(_T("\n"));

		return 1;
	}
	else
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		SecureZeroMemory(&si, sizeof(si));
		SecureZeroMemory(&pi, sizeof(pi));

		si.cb = sizeof(si);

		TCHAR arg[MAX_STR_LEN];
		___tcscpy_s(arg, MAX_STR_LEN, tokenList[0]);

		for (int index = 1; index < num; ++index)
			_stprintf_s(arg, MAX_STR_LEN, _T("%s %s"), arg, tokenList[index]);

		if (!CreateProcess(NULL, arg, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
			_tprintf(errorString, tokenList[0]);
			_tprintf(_T("\n"));

			return -1;
		}

		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		_tprintf(_T("\n"));

		return 1;
	}
}
