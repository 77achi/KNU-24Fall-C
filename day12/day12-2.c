#include <iostream>


int solution(int n)
{
    int ans = 0;

    while (n > 0) {
        if (n % 2 == 0) {   //n이 짝수일때
            n /= 2;
        }
        else {      //n이 홀수일때
            n--;
            ans++;
            n /= 2;
        }
    }

    return ans;
}