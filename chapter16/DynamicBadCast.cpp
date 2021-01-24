#include <iostream>
using namespace std;

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
    SoSimple simObj;
    SoSimple& ref = simObj;

    try {
        SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
        comRef.ShowSimpleInfo();
    }
    catch(bad_cast expt) { // dynamic_cast 의 예외처리
        cout<<expt.what()<<endl;
    }

    return 0;
}