#include "calculator.h"

void Calculator::Init() {
    addCount = minCount = mulCount = divCount = 0;
}

double Calculator::Add(double x, double y) {
    addCount += 1;
    return x + y;
}

double Calculator::Min(double x, double y) {
    minCount += 1;
    return x - y;
}

double Calculator::Mul(double x, double y) {
    mulCount += 1;
    return x * y;
}

double Calculator::Div(double x, double y) {
    divCount += 1;
    if (y == 0) return 0;
    else return x / y;
}

