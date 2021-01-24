#include <iostream>
using namespace std;

void Divide(int num1, int num2) {
    if (num2 == 0) {
        throw num2; // 예외 발생 시 try~catch문이 없으면 함수를 호출한 영역으로 넘어가게 됨.
        // 예외 데이터가 main에서도 처리를 못하면 terminate 함수가 호출되며 종료됨.
    }
    cout<<"나눗셈의 몫: "<<num1/num2<<endl;
    cout<<"나눗셈의 나머지: "<<num1%num2<<endl;
}

int main(void) {
    int num1, num2;
    cout<<"두 개의 숫자 입력: ";
    cin>>num1>>num2;

    try {
        Divide(num1, num2);
        cout<<"나눗셈을 마쳤습니다."<<endl;
    }
    catch (int expn) { // 자료형이 불일치 하면 처리되지 않음!
        cout<<"제수는 "<<expn<<"이 될 수 없습니다."<<endl;
        cout<<"프로그램을 다시 실행하세요."<<endl;

        return 0;
    }
}