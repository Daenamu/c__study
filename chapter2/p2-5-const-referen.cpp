#include <iostream>
using namespace std;

int main(void) {
    const int num = 12;
    const int *ptr = &num; // 포인터 참조를 통해 변경할 수 없다
    const int *(&ref) = ptr; // 포인터 참조자, 포인터의 또다른 이름.
    const int &ref2 = 12; // 상수는 const int &를 통해 임시 변수로 저장할 수 있다. --> 함수 인자로 사용 가능

    cout<<"num : "<<num<<endl;
    cout<<"*ptr : "<<*ptr<<endl;
    cout<<"*ref : "<<*ref<<endl;
    cout<<"ref2 : "<<ref2<<endl;

    return 0;
}