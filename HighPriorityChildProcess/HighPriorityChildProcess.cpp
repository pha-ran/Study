// High Priority Child Process

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

int _tmain(void)
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

	while (1)
	{
		for (int i = 0; i < 10000; i++)
		{
			for (int j = 0; j < 10000; j++)
				;
		}

		_tprintf(_T("Child\n"));
	}

	return 0;
}