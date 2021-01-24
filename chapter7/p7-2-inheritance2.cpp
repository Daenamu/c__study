#include <iostream>
using namespace std;

class Base {
private:
    int num1;
protected: // 상속한 클래스에게만 접근 가능
    int num2; 
public:
    int num3;

    Base() : num1(1), num2(2), num3(3) {}
};

class Derived: protected Base { }; // protected 보다 접근 범위가 넓은 멤버를 protected로 변경, 보통은 public만 쓴다.

int main(void) {
    Derived drv;
    // cout<<drv.num3<<endl; // protected라서 외부에서 접근 불가능!
    return 0;
}