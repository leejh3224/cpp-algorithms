#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;

    printf("enter the number: ");
    scanf("%d", &n);

    int sum_occur = 0; // 모든 3의 개수
    int count_num = 0; // 3을 포함하는 숫자의 개수

    for (int i = 1; i <= n; i++)
    {
        char temp[10]; // 숫자를 담을 문자열

        sprintf(temp, "%d", i); // 숫자 -> 문자열

        char *ptr = strchr(temp, '3'); // 3을 찾아서 포인터를 돌려줌

        int found = 0; // 특정 숫자에서 3을 찾았나 못찾았나

        while (ptr != NULL)
        {
            found++;
            sum_occur++;

            // 만약 3을 처음 발견했다면
            if (found == 1)
            {
                printf("%d, ", i); // 숫자 출력
                count_num++;       // 3을 포함하는 숫자 개수 증가시면
            }

            ptr = strchr(++ptr, '3'); // 계속해서 검색
        }
    }

    printf("총 %d개의 숫자에서 3이 %d번 나타난다.", count_num, sum_occur);

    return 0;
}