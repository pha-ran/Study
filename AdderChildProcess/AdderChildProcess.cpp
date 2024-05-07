// Adder Child Process

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(int argc, TCHAR* argv[])
{
	DWORD b = _tstoi(argv[1]);
	DWORD e = _tstoi(argv[2]);
	DWORD sum = 0;

	while (b <= e)
	{
		sum += b;
		++b;
	}

	return sum;
}
