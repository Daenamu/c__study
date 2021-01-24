#include <iostream>
using namespace std;

class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n) {
        cout<<"New Object: "<<this<<endl;
    }
    SoSimple(const SoSimple& copy): num(copy.num) {
        cout<<"New Copy obj: "<<this<<endl;
    }
    ~SoSimple() {
        cout<<"Destroy obj: "<<this<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob) { // 객체 ob 생성 (copy)
    cout<<"Parm ADR: "<<&ob<<endl;
    return ob; // 임시 반환 객체 생성 후 ob 객체 소멸.
}

int main(void) {
    SoSimple obj(7); // 일반 생성자
    SimpleFuncObj(obj); // 객체 ob 생성 및 copy -> 임시 반환 객체 생성 및 copy -> ob 소멸 -> 반환 객체 소멸(다음 행에서)

    cout<<endl;
    SoSimple tempRef = SimpleFuncObj(obj); // ob에 obj를 copy -> 반환 객체에 ob를 copy -> ob 소멸, 반환 객체는 tempRef 에 저장.
    cout<<"Return obj "<<&tempRef<<endl; // 주소 값이 ob와 다르고, 반환 객체와 같다.

    return 0; // obj 와 tempRef 소멸
}