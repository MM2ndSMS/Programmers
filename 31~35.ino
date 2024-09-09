31.  수열과 구간 쿼리 4
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // arr 자체를 수정하고, 그 결과를 반환할 것이므로 arr를 그대로 사용.
    
    // 각 쿼리 처리
    for (size_t q = 0; q < queries_rows; q++) {
        int s = queries[q][0];  // 시작 인덱스
        int e = queries[q][1];  // 끝 인덱스
        int k = queries[q][2];  // k의 배수인지 확인할 값

        // s에서 e까지 반복하며 i가 k의 배수인 경우 처리
        for (int i = s; i <= e; i++) {
            if (i % k == 0) {
                arr[i] += 1;
            }
        }
    }

    // arr을 반환 (입력 배열을 수정했으므로, 새로운 배열을 반환하지 않아도 됨)
    return arr;
}

32.  배열 만들기 2
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int l, int r) 
{
    int* answer = (int*)malloc(sizeof(int) * 1000000);
    int point = 0, check = 0;
    int idx = 0, temp;
    
    for (int i = l; i <= r; i++) 
    {
        temp = i;
        point = 0, check = 0;
        
        while (temp > 0) 
        {
            if (temp % 10 == 0 || temp % 10 == 5)
                check++;
            point++;
            temp /= 10;
        }
        
        if (check == point) 
        {
            answer[idx++] = i;
        }
    }
    
    if (idx == 0)
        answer[idx] = -1;
    
    return answer;
}

33. 카운트 업
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int start_num, int end_num) 
{
    int* answer = (int*)malloc((end_num - start_num + 1) * sizeof(int));
    int idx = 0;
        
    for (int i = start_num; i <= end_num; i++) 
        answer[idx++] = i;
    
    return answer;
}

34. 콜라츠 수열 만들기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) 
{
    int* answer = (int*)malloc(sizeof(int) * 1000);
    int idx = 0;
    
    while (1) 
    {
        answer[idx++] = n;
        
        if (n == 1)
            break;
        
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }
    
    return answer;
}

35. 배열 만들기
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len) 
{
    int* stk = (int*)malloc(sizeof(int) * 100000);
    int i = 0;
    int idx = 0;
    
    while (i < arr_len) 
    {
        if (idx == 0)
            stk[idx++] = arr[i++];
        else 
        {
            if (stk[idx - 1] < arr[i])
                stk[idx++] = arr[i++];
            else 
            {
                stk[idx - 1] = 0;
                idx--;
            }
        }
    }
    
    return stk;
}
