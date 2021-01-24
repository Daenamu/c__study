#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref) {
    ref++;
    return ref;
}

int RefRetFuncTwo(int &ref) {
    ref++;
    return ref;
}

void PrintTwoNum(int num1, int num2) {
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
}

int main(void) {
    int num1 = 1;
    int &num2 = RefRetFuncOne(num1);
    int num3;

    num1++;
    num2++;
    cout<<"case1: int num1, int &num2"<<endl;
    /*
    int num1 = 1;
    int &ref = num1;
    ref++;
    int &num2 = ref; // ref는 지역변수이므로 사라짐.
    */
    PrintTwoNum(num1, num2);

    num3 = RefRetFuncOne(num1);
    num1++;
    num3+=100;
    cout<<"case2: int num1, int num2"<<endl;
    /*
    int num1 = 1;
    int &ref = num1;
    ref++;
    int num2 = ref; // 값 복사만 이루어짐.
    */
    PrintTwoNum(num1, num3);

    num3 = RefRetFuncTwo(num1);
    num1++;
    num3+=100;
    cout<<"case3: int num1, int num2 (return int)"<<endl;
    /*
    int num1 = 1;
    int &ref = num1;
    ref++;
    int num2 = ref; // 반환 값이 상수임.
    */
   PrintTwoNum(num1, num3);
    return 0;
}