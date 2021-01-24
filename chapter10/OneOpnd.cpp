#include <iostream>
using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const {
        cout<<'['<<xpos<<" ,"<<ypos<<']'<<endl;
    }
    Point& operator++() { // 단항 연산자 ++, 멤버 함수는 인자 필요 없음
        xpos += 1;
        ypos += 1;
        return *this; // &참조 반환
    }
    const Point operator++(int) { // 후위 증가, int 키워드 넣기
        const Point retobj(xpos, ypos); // 함수 내에서 변경 허용 x
        xpos += 1;
        ypos += 1;
        return retobj; // 값이 증가하기 전 복사본 반환.
    }
    friend Point& operator--(Point &ref); // 전역 함수..? 인자 필요. private 접근 위해 friend 씀
    friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref) {
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}
const Point operator--(Point &ref, int) {
    const Point refobj(ref);
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main(void) {
    Point pos(1, 2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();

    // (pos++)++; 는 컴파일 에러. 반환 객체가 const이기 때문!
    // (pos1++) + pos2 를 하면 pos1의 증가되기 전 값과 합해진다. pos1은 증가된 상태.
}