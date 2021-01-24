#include <iostream>
using namespace std;

// 하나 이상의 가상함수를 가지면 Polymorphic 클래스이다!
class SoSimple {
public:
    virtual void ShowSimpleInfo() {
        cout<<"SoSimple Base Class"<<endl;
    }
};

class SoComplex : public SoSimple {
public:
    void ShowSimpleInfo() { // 이것도 가상함수
        cout<<"SoComplex derived class"<<endl;
    }
};

int main(void) {
    // dynamic_cast는 기초 함수가 polymorphic 클래스면 기초->유도 형변환이 가능하다
    SoSimple* simPtr = new SoComplex;
    SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
    comPtr->ShowSimpleInfo();

    SoSimple* simPtr2 = new SoSimple;
    SoComplex* comPtr2 = dynamic_cast<SoComplex*>(simPtr2); // 잘못된 경우는 NULL을 반환함

    return 0;
}