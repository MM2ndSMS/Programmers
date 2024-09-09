### 1.문자열 출력하기
#include <stdio.h>
#define LEN_INPUT 1000001

int main(void) 
{
    char s1[LEN_INPUT];
    
    scanf("%s", s1);
    
    printf("%s\n", s1);

    return 0;
}

### 2.a와 b 출력하기
#include <stdio.h>

int main(void) 
{
    int a;
    int b;
    
    scanf("%d %d", &a, &b);
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}

### 3.문자열 반복해서 출력하기
#include <stdio.h>
#define LEN_INPUT 11

int main(void) 
{
    char s1[LEN_INPUT];
    
    int a, i;
    
    scanf("%s %d", s1, &a);
    
    for(i=1; i<=a; i++)
    {
        printf("%s", s1);
    }
   
    return 0;
}

### 4.대소문자 바꿔서 출력하기
#include <stdio.h>
#include <ctype.h>

#define LEN_INPUT 21

int main(void) 
{
    char s1[LEN_INPUT];
    scanf("%s", s1);
    
    for(int i = 0; s1[i] != '\0'; i++)  // 널 문자를 올바르게 표시
    {
        if (isupper(s1[i]))  // 대문자인지 확인
        {
            s1[i] = tolower(s1[i]);  // 소문자로 변환
        }
        else if (islower(s1[i]))  // 소문자인지 확인
        {
            s1[i] = toupper(s1[i]);  // 대문자로 변환
        }
    }

    printf("%s\n", s1);  // 변환된 문자열을 출력
    
    return 0;
}

###5.특수문자 출력하기
#include <stdio.h>

int main(void) 
{
    printf("!@#$%%^&*(\\\'\"<>?:;");
    
    return 0;
}

###6.덧셈식 출력하기
#include <stdio.h>

int main(void)
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    
    printf("%d + %d = %d", a, b, a + b);
    
    return 0;
}

###7.문자열 붙여서 출력하기
#include <stdio.h>
#define LEN_INPUT1 11
#define LEN_INPUT2 11

int main(void) 
{
    char s1[LEN_INPUT1];
    char s2[LEN_INPUT2];
    scanf("%s %s", s1, s2);

    printf("%s%s", s1, s2);

    return 0;
}

###8.문자열 돌리기
#include <stdio.h>
#include <string.h>

int main() 
{
    char str[11]; 
    scanf("%s", str);
    
    int len = strlen(str); 
    
    for (int i = 0; i < len; i++) 
    {
        printf("%c\n", str[i]); 
    }
    
    return 0;
}

###9.홀짝 구분하기
#include <stdio.h>

int main() 
{
    int n;
    
    scanf("%d", &n);
    
    if (n % 2 == 0)
    {
        printf("%d is even\n", n);
    } 
    else 
    {
        printf("%d is odd\n", n);
    }
    
    return 0;
}

###10.문자열 겹쳐쓰기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, const char* overwrite_string, int s) 
{
    int my_string_len = strlen(my_string);
    int overwrite_string_len = strlen(overwrite_string);
    
    char* answer = (char*)malloc((my_string_len + 1) * sizeof(char));

    strcpy(answer, my_string);

    for (int i = 0; i < overwrite_string_len; i++)
    {
        answer[s + i] = overwrite_string[i];
    }

    return answer;
}

int main()
{
    const char* my_string = "He11oWor1d";
    const char* overwrite_string = "lloWorl";
    int s = 2;
    
    char* result = solution(my_string, overwrite_string, s);
    printf("%s\n", result); 
    
    free(result);
    
    return 0;
}
