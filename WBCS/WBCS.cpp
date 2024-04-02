// WBCS 기반

#include <stdio.h>
#include <string.h>
#include <locale.h>

int wmain(int argc, wchar_t* argv[])
{
	_wsetlocale(LC_ALL, L"korean");

	wchar_t str[] = L"ABC가나다";

	wprintf(L"배열 크기 %d \n", sizeof(str));
	wprintf(L"문자열 길이 %d \n", wcslen(str));

	for (int i = 0; i < 6; i++)
		fputwc(str[i], stdout);

	wprintf(L"\n");

	return 0;
}

// 실행 결과
// 배열 크기 14
// 문자열 길이 6
// ABC가나다