11. 문자열 섞기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* str1, const char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = len1 + len2;
    
    char* answer = (char*)malloc(len + 1);
    for (int i = 0; i < len1; i++)
    {
        answer[2 * i] = str1[i];
        answer[2 * i + 1] = str2[i];
    }
    answer[len] = '\0';
    
    return answer;
}

int main()
{
    const char* str1 = "abc";
    const char* str2 = "def";
    char* result = solution(str1, str2);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}

12. 문자 리스트를 문자열로 변환하기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* arr[], size_t arr_len)
{
    size_t total_length = 0;
    for (size_t i = 0; i < arr_len; ++i)
    {
        total_length += strlen(arr[i]);
    }
    char* answer = (char*)malloc(total_length + 1);
    if (answer == NULL)
    {
        return NULL;
    }
    char* p = answer;
    for(size_t i = 0; i < arr_len; ++i)
    {
        p += sprintf(p, "%s", arr[i]);
    }
    return answer;
}
int main()
{
    const char* arr[] = {"Hello", ", ", "world", "!"};
    size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    
    char* result = solution(arr, arr_len);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}

13. 문자열 곱하기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, int k)
{
    size_t len = strlen(my_string);
    char* answer = (char*)malloc(len * k + 1);
    if(answer == NULL)
    {
        return NULL;
    }
    char* p = answer;
    for(int i = 0; i < k; ++i)
    {
        strcpy(p, my_string);
        p += len;
    }
    *p = '\0';
    return answer;
}
int main()
{
    const char* my_string = "abc";
    int k = 3;
    char* result = solution(my_string, k);
    printf("Result: %s\n", result);
    free(result);
    return 0;
}

14.  더 크게 합치기
#include <stdio.h>

int concat(int a, int b)
{
    int temp = b;
    while(temp>0)
    {
        temp /= 10;
        a *= 10;
    }
    return a + b;
}
int solution(int a, int b)
{
    return(concat(a,b)>=concat(b,a)) ? concat(a,b) : concat(b,a);
}
int main()
{
    int a = 12;
    int b = 3;
    printf("Result: %d\n", solution(a,b));
    return 0;
}

15 . 두 수의 연산 값 비교하기
#include <stdio.h>

int concat(int a, int b)
{
    int temp = b;
    while(temp > 0)
    {
        temp /= 10;
        a *=10;
    }
    return a + b;
}

int solution(int a, int b)
{
    int ab = concat(a,b);
    int twice_ab = 2 * a * b;
    if(ab>=twice_ab)
    {
        return ab;
    }
    else
    {
        return twice_ab;
    }
}
int main()
{
    int a = 12;
    int b = 3;
    int result = solution(a,b);
    printf("Result: %d\n", result);
    return 0;
}

16 . n의 배수
#include <stdio.h>
#include <stdbool.h>

int solution(int num, int n)
{
    if(num % n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int num = 10;
    int n = 2;
    printf("solution(%d, %d)", num, n, solution(num, n));
    num = 10;
    n = 3;
        printf("solution(%d, %d)", num, n, solution(num, n));
return 0;
}

17 . 공배수
#include <stdio.h>
#include <stdbool.h>

int solution(int number, int n, int m)
{
    if (number %n == 0 && number %m == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int number = 12;
    int n = 3;
    int m = 4;
    printf("solution(%d, %d, %d)\n", number, n, m, solution(number, n, m));
    number =12;
    n = 3;
    m = 5;
        printf("solution(%d, %d, %d)\n", number, n, m, solution(number, n, m));
    return 0;
}

18 . 홀짝에 따라 다른 값 반환하기
#include <stdio.h>

long long solution(int n)
{
    long long sum = 0;
    if(n % 2 == 1)
    {
        for (int i = 1; i<=n; i += 2)
        {
            sum += i;
        }
    }
    else
    {
        for(int i = 2; i <= n; i += 2)
        {
            sum += (long long)i * i;
        }
    }
return sum;
}
int main()
{
    int n;
    n = 5;
    printf("solution(%d) = %11d\n", n, solution(n));
    n = 6;
        printf("solution(%d) = %11d\n", n, solution(n));
    return 0;
}

19. 조건 문자열
#include <stdio.h>

int solution(const char* ineq, const char* eq, int n, int m)
{
   if(ineq[0] == '>' && eq[0] == '=') return n >= m ? 1 : 0;
   if(ineq[0] == '<' && eq[0] == '=') return n <= m ? 1 : 0;
   if(ineq[0] == '>' && eq[0] == '!') return n > m ? 1 : 0;
   if(ineq[0] == '<' && eq[0] == '!') return n < m ? 1 : 0;
    return 0;
}
int main()
{
    printf("solution(>, =, 5, 3) = %d\n", solution(">", "=", 5, 3));
    printf("solution(<, =, 5, 3) = %d\n", solution("<", "=", 5, 5));
    printf("solution(>, !, 2, 3) = %d\n", solution(">", "=", 2, 3));
    printf("solution(<, !, 1, 2) = %d\n", solution(">", "=", 1, 2));
    return 0;
}

20. flag에 따라 다른 값 반환하기
#include <stdio.h>
#include <stdbool.h>

int solution(int a, int b, bool flag)
{
    return flag ? (a+b) : (a-b);
}
int main()
{
    int a = 5, b = 3;
    bool flag = true;
    printf("solution(%d, %d, %s) = %d\n", a, b, flag ? "true" : "false", solution(a, b, flag));
    a = 5; b = 3; flag = false;
        printf("solution(%d, %d, %s) = %d\n", a, b, flag ? "true" : "false", solution(a, b, flag));
    return 0;
}
