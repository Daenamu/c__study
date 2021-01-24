#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_

#include <iostream>
using namespace std;

template <typename T>
class Point {
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0);
    void ShowPosition() const;

    friend Point<int> operator+(const Point<int>&, const Point<int>&); // 특정 템플릿 객체를 인자로 받을 수 있음.
    friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <typename T>
void Point<T>::ShowPosition() const {
    cout<<'['<<xpos<<", "<<ypos<<endl;
}

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2) { // 일반함수
    return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

ostream& operator<<(ostream& os, const Point<int>& pos) {
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

#endif