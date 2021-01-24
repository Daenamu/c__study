#include <iostream>
using namespace std;

// 참조자는 가급적 const int * value 형식으로 선언해서 값 변경 안하는게 좋음.

void PlusOne(int &num) {
    num = num + 1;
}

void CodeSwtich(int &num) {
    num = -num;
}

int main(void) {
    int i;

    i = 10;
    cout<<"i: "<<i<<endl;
    PlusOne(i);
    cout<<"i: "<<i<<endl;
    CodeSwtich(i);
    cout<<"i: "<<i<<endl;

    return 0;
}