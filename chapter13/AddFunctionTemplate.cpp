#include <iostream>
using namespace std;

template <typename T> // 함수 템플릿 선언
T Add(T num1, T num2) { 
    return num1 + num2;
}

int main(void) {
    cout<<Add<int>(15, 20)<<endl; // 컴파일 할 때 int Add<int>(int num1, int num2) 식으로 만들어짐. 호출 할 때마다 만드는거 x
    cout<<Add<double>(3.2, 3.2)<<endl;
    cout<<Add(3.2, 3.2)<<endl; // 컴파일러가 알아서 결정
}