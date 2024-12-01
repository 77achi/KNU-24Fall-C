#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int ch_topp[10001] = { 0, }; //철수
    int do_topp[10001] = { 0, }; //동생
    int ch_num = 0;     //철수의 토핑 개수
    int do_num = 0;     //동생의 토핑 개수

    for (int i = 0; i < topping_len; i++) {     //토핑 종류
        int top = topping[i];
        if (do_topp[top] == 0)
            do_num++;
        do_topp[top]++;
    }

    for (int i = 0; i < topping_len; i++) {
        int top = topping[i];
        if (ch_topp[top] == 0)  //철수의 토핑 종류 추가
            ch_num++;
        ch_topp[top]++;

        //동생의 토핑 종류 제거
        do_topp[top]--;
        if (do_topp[top] == 0)
            do_num--;

        if (ch_num == do_num)   //공평하면 방법 수 증가
            answer++;
    }

    return answer;
}