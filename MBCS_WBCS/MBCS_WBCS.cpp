// MBCS 와 WBCS 동시 지원

// [프로젝트] -> [속성] -> [C/C++] -> [전처리기]
// [전처리기 정의] 에 기본적으로 정의
//#define UNICODE
//#define _UNICODE

// MBCS 기반 실행 시 주석 해제 (정의 해제)
//#undef UNICODE
//#undef _UNICODE

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <locale.h>

int _tmain(int argc, TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"korean");

	TCHAR str[] = _T("ABC가나다");
	TCHAR input[50];
	LPTSTR pStr = str;

	_tprintf(_T("배열 크기 %d \n"), sizeof(str));
	_tprintf(_T("문자열 길이 %d \n"), _tcslen(str));

	_tprintf(_T("문자열 입력 > "));
	_tscanf_s(_T("%s"), input, 40);
	_tprintf(_T("%s\n"), input);

	_tcscat_s(input, 50, pStr);
	_tprintf(_T("%s\n"), input);

	return 0;
}

// MBCS 기반 실행 결과 (9 ~ 10 주석 해제)
// 배열 크기 10
// 문자열 길이 9
// 문자열 입력 > [입력문자열]
// [입력문자열]
// [입력문자열]ABC가나다

// WBCS 기반 실행 결과
// 배열 크기 14
// 문자열 길이 6
// 문자열 입력 > [입력문자열]
// [입력문자열]
// [입력문자열]ABC가나다