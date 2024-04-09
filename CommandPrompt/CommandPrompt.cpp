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

int _tmain(void)
{
	_wsetlocale(LC_ALL, L"korean");

	_tprintf(_T("명령 프롬프트 프로젝트 ( %zd 바이트 시스템 / 문자 크기 %zd )\n\n"), sizeof(SIZE_T), sizeof(TCHAR));
	
	TCHAR str[] = _T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789가나다라마바사아자차카타파하!@#$%^&*() \t\n,./+-<>;");
	TCHAR dest[10];

	_tprintf(_T("%d\n"), ___tcscpy_s(NULL, 0, NULL));

	dest[0] = _T('a');
	_tprintf(_T("%s / %d\n"), dest, ___tcscpy_s(dest, 0, NULL));

	dest[0] = _T('a');
	_tprintf(_T("%s / %d\n"), dest, ___tcscpy_s(dest, 0, str));

	dest[0] = _T('a');
	_tprintf(_T("%s / %d\n"), dest, ___tcscpy_s(dest, _countof(dest), str));

	dest[0] = _T('a');
	_tcscpy_s(dest, _countof(dest), _T("aA가\t!"));
	_tprintf(_T("%s\n"), dest);

	dest[0] = _T('a');
	___tcscpy_s(dest, _countof(dest), _T("aA가\t!"));
	_tprintf(_T("%s\n"), dest);

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
