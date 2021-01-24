#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    friend ostream& operator<<(ostream&, const Point&); // ostream을 수정할 수 없으므로 전역 함수를 통해 오버로딩
};

ostream& operator<<(ostream& os, const Point& pos) {
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

int main(void) {
    Point pos1(1, 3);
    cout<<pos1; // point 클래스의 출력 연산자 오버로딩
}