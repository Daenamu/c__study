#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class BoundCheckPointArray { // 객체 자체를 저장하는 배열
private:
    Point* arr;
    int arrlen;

    BoundCheckPointArray(const BoundCheckPointArray& arr) { }
    BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }
public:
    BoundCheckPointArray(int len): arrlen(len) {
        arr = new Point[len];
    }
    ~BoundCheckPointArray() {
        delete []arr;
    }
    Point operator[] (int idx) {
        if (idx < 0 || idx >= arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    Point operator[] (int idx) const {
        if (idx < 0 || idx >= arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const {
        return arrlen;
    }
};

typedef Point* POINT_PTR; // 포인터를 저장하는 배열

class BoundCheckPointPtrArray {
private:
    POINT_PTR* arr;
    int arrlen;

    BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
    BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }
public:
    BoundCheckPointPtrArray(int len) : arrlen(len) {
        arr = new POINT_PTR[len];
    }
    ~BoundCheckPointPtrArray() {
        delete []arr;
    }
    POINT_PTR& operator[] (int idx) {
        if (idx < 0 || idx >= arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    POINT_PTR operator[] (int idx) const {
        if (idx < 0 || idx >= arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const {
        return arrlen;
    }
};

int main(void) {
    BoundCheckPointArray arr(3);
    arr[0] = Point(3, 4); // 배열에 Point 클래스의 디폴트 대입 연산자가 호출, 복사 진행.
    arr[1] = Point(5, 6);
    arr[2] = Point(7, 8);

    for (int i = 0; i < arr.GetArrLen(); i++) {
        cout<<arr[i];
    }

    BoundCheckPointPtrArray arr2(3);
    arr2[0] = new Point(3, 4); // 포인터만 복사, deepcopy를 고려할 필요 없음.
    arr2[1] = new Point(5, 6);
    arr2[2] = new Point(7, 8);

    for (int i = 0; i < arr2.GetArrLen(); i++) {
        cout<<*(arr2[i]);
    }

    delete arr2[0];
    delete arr2[1];
    delete arr2[2];

    return 0;
}