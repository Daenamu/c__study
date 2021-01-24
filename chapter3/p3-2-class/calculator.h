#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
using namespace std;

class Calculator { // struct 대신 class 로 선언.
private:  // default는 private <-> struct는 기본이 public이다
    int addCount, minCount, mulCount, divCount;
public:
    void Init();
    void ShowOpCount();
    double Add(double x, double y);
    double Min(double x, double y);
    double Mul(double x, double y);
    double Div(double x, double y);
};

inline void Calculator::ShowOpCount() { // inline 함수는 헤더파일과 함께 넣어야함. (컴파일 과정에서 삽입되기 때문)
    cout<<"덧셈: "<<addCount<<" 뺄셈: "<<minCount<<" 곱셈: "<<mulCount<<" 나눗셈: "<<divCount<<endl;
}

#endif