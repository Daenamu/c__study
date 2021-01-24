#include <iostream>
using namespace std;

class SoSimple {
public:
    static int simObjCnt;            // class 내 static 변수 선언.
    // const static int CONST = 10;  // class 내 static 상수 선언
    // mutable int num2;             // const 함수 내에서 변경을 예외적으로 허용한다. (쓰지 말자)
public:
    SoSimple() {
        simObjCnt++;
    }
    /*
    static void Adder(int n) { // class 내 static 함수 선언. static 변수와 함수만 호출이 가능하다!
        ...
    }
    */
};
int SoSimple::simObjCnt = 0; // static 변수는 전역변수와 같이 할당됨. 초기화

int main(void) {
    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl; // public 이면 어디서든 접근 가능. private면 객체 안에서만 접근 가능.
    SoSimple sim1;
    SoSimple sim2;

    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl; // 혼동을 피하기 위해 클래스 명으로 접근하기!
    cout<<sim1.simObjCnt<<"번째 SoSimple 객체"<<endl;
    cout<<sim2.simObjCnt<<"번째 SoSimple 객체"<<endl;

    return 0;
}