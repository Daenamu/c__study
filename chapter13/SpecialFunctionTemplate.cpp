#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

template <> // 템플릿 예외
char *Max(char* a, char* b) { // char*형 함수는 별도 제시!
    return strlen(a) > strlen(b) ? a : b;
}

template <>
const char *Max(const char* a, const char* b) {
    return strcmp(a, b) > 0 ? a : b;
}

int main(void) {
    cout<<Max(11, 15)<<endl;
    cout<<Max("Simple", "Best")<<endl; // 문자열은 const char* 형
    
    char str1[] = "Simple";
    char str2[] = "Best";
    cout<<Max(str1, str2)<<endl; // char* 형 전달

    return 0;
}