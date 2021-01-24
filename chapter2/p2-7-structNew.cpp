#include <iostream>
using namespace std;

typedef struct __Point {
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2) {
    Point* result = new Point;
    result->xpos = p1.xpos + p2.xpos;
    result->ypos = p1.ypos + p2.ypos;

    return *result;
}

int main() {
    Point* pptr1 = new Point;
    pptr1->xpos = 3;
    pptr1->ypos = 30;

    Point* pptr2 = new Point;
    pptr2->xpos = 70;
    pptr2->ypos = 7;

    Point &pref = PntAdder(*pptr1, *pptr2);
    cout<<"["<<pref.xpos<<", "<<pref.ypos<<"]"<<endl;

    delete pptr1;
    delete pptr2;
    delete &pref; // 동적할당한 구조체의 주소는 안사라짐. result라는 이름만 사라질 뿐

    return 0;
}