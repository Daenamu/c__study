#include <iostream>
using namespace std;

class Number {
private:
    int num;
public:
    Number(int n = 0) : num(n) { }
    Number& operator=(const Number& ref) { // 인자에 다른 형의 객체가 올 경우, 생성자 호출을 통해 임시 객체를 생성함 --> Number num1 = 30 이 가능!
        num = ref.num;
        return *this;
    }
    operator int () { // 형 변환 연산자의 오버로딩
        return num;
    }
    void ShowNumber() {
        cout<<num<<endl;
    }
};

int main() {
    Number num1;
    num1 = 30; // Number(30) 을 통해 임시 객체를 생성한 후 대입 연산자 수행
    
    Number num2 = num1 + 20; // operator+ 함수가 없으니 num1 형변환 수행.
    num2.ShowNumber();

    return 0;
}