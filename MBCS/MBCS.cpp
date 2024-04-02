// MBCS 기반

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "ABC가나다";

    printf("배열 크기 %d \n", sizeof(str));
    printf("문자열 길이 %d \n", strlen(str));

    for (int i = 0; i < 6; i++)
        fputc(str[i], stdout);

    printf("\n");

    for (int i = 0; i < 10; i++)
        fputc(str[i], stdout);

    printf("\n");

    return 0;
}

// 실행 결과
// 배열 크기 10
// 문자열 길이 9
// ABC가
// ABC가나다