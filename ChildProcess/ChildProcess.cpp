// Child Process

#include <stdio.h>
#include <windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[])
{
	_tprintf(_T("%s\n"), argv[1]);
	
	TCHAR temp;
	_tscanf_s(_T("%c"), &temp, (unsigned int)sizeof(temp));

	return 0;
}
