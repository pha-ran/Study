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

int _tmain(void)
{
	_wsetlocale(LC_ALL, L"korean");

	_tprintf(_T("문자 크기 : %d\n\n"), sizeof(TCHAR));

	TCHAR str[] = _T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789가나다라마바사아자차카타파하!@#$%^&*() \t\n,./+-<>;");

	for (_TINT i = 0; str[i] != NULL; i++)
	{
		_tprintf(_T("%c\n"), str[i]);

		_tprintf(_T("대문자 여부 %d %d\n"), _istupper(str[i]), ___istupper(str[i]));
		_tprintf(_T("소문자 여부 %d %d\n"), _istlower(str[i]), ___istlower(str[i]));

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