#include <iostream>
using namespace std;

template <typename T> 
class Point {
private:
    T xpos, ypos;
public:
    Point(T x = 0, T y = 0) : xpos(x), ypos(y) { }
    void ShowPosition() const;
};

template <typename T> // 외부에 정의할 때도 template 선언을 해야함.
void Point<T>::ShowPosition() const { 
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
} 

int main(void) {
    Point<int> pos1(3, 4); // 클래스는 자료형 생략 불가
    pos1.ShowPosition();

    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();

    return 0;
}