#include <iostream>
using namespace std; //std에 선언된 모든 것에 대해 이름 공간 지정의 생략.

bool IsPositive(int num) { // 1byte true or false
    if (num < 0) return false;
    else return true;
}

int main(void) {
    bool isPos;
    int num;
    cout<<"Input number: ";
    cin>>num;

    isPos = IsPositive(num);
    if (isPos) {
        cout<<"Positive number"<<endl;
    }
    else {
        cout<<"Negative number"<<endl;
    }
    return 0;
}