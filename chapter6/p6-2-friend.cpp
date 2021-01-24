#include <iostream>
using namespace std;

class Point; // 원형 선언

class PointOP {
private:
    int opcnt;
public:
    PointOP() : opcnt(0) { }
    Point PointAdd(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
    ~PointOP() {
        cout<<"Operation times: "<<opcnt<<endl;
    }
};

class Point {
private:
    int x;
    int y;
public:
    Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) { }
    friend Point PointOP::PointAdd(const Point&, const Point&); // PointOP의 PointAdd 함수가 Point의 private 변수에 접근이 가능하다!
    friend Point PointOP::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&);
    // 클래스 대상: friend class <className> 형식으로 선언. 위치는 상관 x
    // 위와 같이 클래스의 멤버 함수, 전역함수를 대상으로도 가능.
    // 가급적 안쓰는걸 추천.
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
    opcnt++;
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y); // private 변수에 직접 접근
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
    opcnt++;
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y); 
}

void ShowPointPos(const Point& pos) {
    cout<<"x: "<<pos.x<<", ";
    cout<<"y: "<<pos.y<<endl;
}

int main(void) {
    Point pos1(1, 2);
    Point pos2(2, 4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos2, pos1));

    return 0;
}

