#include <iostream>
using namespace std;

template <class T1, class T2> // class로 선언 가능, 두 개 이상 선언 가능
void ShowData(double num) { // 기본 자료형 선언 가능
    cout<<(T1)num<<", "<<(T2)num<<endl; // 형 변환, T2(num) 의 형태도 가능
}

int main(void) {
    ShowData<char, int>(65); // 콤마로 구분
}