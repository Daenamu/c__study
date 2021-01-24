#include <cmath> // math.h
#include <cstdio>
#include <cstring>

using namespace std; // 표준 함수들이 모두 std에 선언되어있음.

int main(void) {
    char str1[] = "Result";
    char str2[30];

    strcpy(str2, str1); // 표준 함수
    printf("%s: %f \n", str1, sin(0.14));
    printf("%s: %f \n", str2, abs(-1.25)); // c++에서는 표준함수 오버로딩, 실수도 가능.

    return 0;
}