#include <iostream>
#include "ArrayTemplate.h"
#include "PointTemplate.h"
using namespace std;

int main(void) {
    BoundCheckArray<int> iarr(5); // int형 배열
    for (int i = 0; i < 5; i++) {
        iarr[i] = (i + 1) * 11;
    }
    for (int i = 0; i < 5; i++) {
        cout<<iarr[i]<<endl;
    }

    BoundCheckArray<Point<int>> oarr(2); // Point 객체 배열, 자료형으로 다른 템플릿 자료형도 가능함!
    oarr[0] = Point<int>(1, 2);
    oarr[1] = Point<int>(3, 4);
    for (int i = 0; i < oarr.GetArrLen(); i++) {
        oarr[i].ShowPosition();
    }

    typedef Point<int>* POINT_PTR; // Point 주소 배열
    BoundCheckArray<POINT_PTR> parr(2);
    parr[0] = new Point<int>(1, 2);
    parr[1] = new Point<int>(3, 4);
    for (int i = 0; i < parr.GetArrLen(); i++) {
        parr[i]->ShowPosition();
    }

    delete parr[0];
    delete parr[1];
    
    return 0;
}