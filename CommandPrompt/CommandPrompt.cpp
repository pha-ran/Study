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

int _tmain(void)
{
	_wsetlocale(LC_ALL, L"korean");

	_tprintf(_T("명령 프롬프트 프로젝트 ( %zd 바이트 시스템 / 문자 크기 %zd )\n\n"), sizeof(SIZE_T), sizeof(TCHAR));
	
	TCHAR str[] = _T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789가나다라마바사아자차카타파하!@#$%^&*() \t\n,./+-<>;");

	for (int i = 0; str[i] != NULL; i++)
	{
		_tprintf(_T("%c\n"), str[i]);

		_tprintf(_T("대문자 변환 %c %c\n"), _totupper(str[i]), ___totupper(str[i]));
		_tprintf(_T("소문자 변환 %c %c\n"), _totlower(str[i]), ___totlower(str[i]));

		_tprintf(_T("\n"));
	}

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
