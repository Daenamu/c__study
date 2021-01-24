#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout<<"Base Constructor"<<endl;
    }
    void SimpleFunc() {
        cout<<"BaseOne"<<endl;
    }
};

class MiddleDerivedOne : virtual public Base { // Base 클래스를 다중 상속 할 때, LastDerived 객체에 Base를 한 번만 상속하도록 함.
public:
    MiddleDerivedOne() : Base() {
        cout<<"MiddleDerivedOne Constructor"<<endl;
    }
    void MiddleFuncOne() {
        SimpleFunc();
        cout<<"MiddleDerivedOne"<<endl;
    }
};

class MiddleDerivedTwo : virtual public Base {
public:
    MiddleDerivedTwo() : Base() {
        cout<<"MiddleDerivedTwo Constructor"<<endl;
    }
    void MiddleFuncTwo() {
        SimpleFunc();
        cout<<"MiddleDerivedTwo"<<endl;
    }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo { // 다중 상속
public:
    LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo() {
        cout<<"LastDerived Constructor"<<endl;
    }
    void ComplexFunc() {
        MiddleFuncOne();
        MiddleFuncTwo();
        SimpleFunc(); // virtual 이 없으면 base 객체가 2개라 애매성이 생김.
    }
};

int main(void) {
    cout<<"객체 생성 전 ....."<<endl;
    LastDerived ldr;
    cout<<"객체 생성 후 ....."<<endl;
    ldr.ComplexFunc();

    return 0;
}