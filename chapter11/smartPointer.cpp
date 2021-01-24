#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
    void SetPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class SmartPtr { // 객체를 포인터로써 다룸. 자기 스스로 하는 일이 존재
private:
    Point* posptr;
public:
    SmartPtr(Point* ptr) : posptr(ptr) { } // ptr이 new로 할당된 객체라 가정.
    ~SmartPtr() { // 프로그램이 종료될 때 소멸자가 수행되며 자동으로 delete!
        delete posptr; 
    }
    Point& operator*() const { // * 연산자 오버로딩
        return *posptr;
    }
    Point* operator->() const {
        return posptr;
    }
};

int main(void) {
    SmartPtr sptr1(new Point(1, 2));
    SmartPtr sptr2(new Point(3, 4));

    cout<<*sptr1;
    cout<<*sptr2;

    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);

    cout<<*sptr1;
    cout<<*sptr2;

    return 0;
}