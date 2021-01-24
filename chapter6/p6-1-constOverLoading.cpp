#include <iostream>
using namespace std;

class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n) {}
    SoSimple& AddNum(int n) {
        num += n;
        return *this;
    }
    void SimpleFunc() {
        cout<<"SimpleFunc: "<<num<<endl;
    }
    void SimpleFunc() const { // const로 오버로딩 가능. const 객체 대상일 때 이 함수가 호출 됨.
        cout<<"const SimpleFunc: "<<num<<endl;
    }
};

void YourFunc(const SoSimple &obj) { // 임시로 const 객체에 copy
    obj.SimpleFunc(); // const 함수만 실행 가능!!
}

int main(void) {
    SoSimple obj1(2);
    const SoSimple obj2(7); // const 객체 선언. 데이터 변경 불가, const 함수만 실행 가능

    obj1.SimpleFunc();
    obj2.SimpleFunc();

    YourFunc(obj1);
    YourFunc(obj2);

    return 0;
}