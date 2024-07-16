#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// Created by HolyChan on 2024. 7. 14..
// 사용 알고리즘: 그리디
//
int main(){

    // 로마숫자 배열
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *string[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // test = 235;
    int input = 235;
    // 입력
    scanf("%d", &input);
    int save = input;

    char *result = (char *)malloc(sizeof(char));
    int result_size = 0;

    // strcat 의 동작방식을 위한 조치
    result[0] = '\0';

    for(int i = 0; i <= 12; i++){

        while(input >= nums[i]){

            // 수 차감
            input -= nums[i];

            // 글자 하나와 글자 두 개를 구분하기 위한 대안
            int string_len = strlen(string[i]);

            // 메모리 확보: realloc -> 조건 만족
            result = (char *)realloc(result, result_size + 1);

            // 문자 이어붙이기
            strcat(result, string[i]);

            result_size += string_len;
        }

    }

    printf("%d = ", save);

    // 출력
    if(save >= 100){
        printf("%d ", save/100 * 100);
        save %= 100;
    }
    if(save != 0) printf("+ ");
    if(save >= 10){
        printf("%d ", save/10 * 10);
        save %= 10;
    }
    if(save != 0) printf("+ ");
    if(save >= 1){
        printf("%d ", save/1);
    }
    printf("= ");

    printf("%s\n", result);
    printf("%d\n", strlen(result));
    printf("%d\n", result_size);
    free(result);


    return 0;
}