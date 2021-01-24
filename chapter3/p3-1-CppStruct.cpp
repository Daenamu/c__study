#include <iostream>
using namespace std;

struct Point { // typedef 정의 없어도 됨.
    int xpos; // default 는 public.
    int ypos;

    void MovePos(int x, int y) { // 구조체 안에 함수 정의 가능, 인라인으로 처리.
        xpos += x; // 구조체 변수 직접 접근 가능
        ypos += y;
    } 

    // void AddPoint(Const Point &pos); // 외부에서 정의 할 경우 원형만 선언.
    void AddPoint(const Point &pos) {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void ShowPosition() {
        cout<<"["<<xpos<<" ,"<<ypos<<"]"<<endl;
    }

    /*
    enum { // enum 자료형도 가능.
        ...
    }
    */
};

/*
namespace POINT_CONST { // 외부에 선언하여 CAR_CONST::val1 식으로 참조할 수도 있다.
    enum {
        ...
    }
}
*/

/*
inline void Point::Addpoint(const Point &pos) { // 함수는 외부로 뺄 수 있다. 구조체에는 원형 선언만 하면 된다. inline은 선택.
    ...
} 
*/

int main(void) {
    Point pos1 = {12, 4}; // 구조체 초기화, struct 선언 필요 x
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();

    pos1.AddPoint(pos2);
    pos1.ShowPosition();

    return 0;
}

