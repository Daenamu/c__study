#include <iostream>
using namespace std;

class Point {
private:
    int xpos;
    int ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point operator*(int times) { // 객체와 상수의 연산
        Point pos(xpos*times, ypos*times);
        return pos;
    }
    friend Point operator*(int times, Point& ref); // 교환 법칙
};

Point operator*(int times, Point& ref) {
    return ref*times; // 기존 연산자 활용
}

int main(void) {
    Point pos(1, 2);
    Point cpy;

    cpy = 3*pos;
    cpy.ShowPosition();

    cpy = 2*pos*3;
    cpy.ShowPosition();

    return 0;
}
