#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(const int &xpos, const int &ypos); // 생성자, 오버로딩 가능, 없으면 디폴트 생성자가 호출.
    int GetX() const; // 멤버 변수의 값을 변경 안하겠다
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

class Rectangle {
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    ~Rectangle() { } // 소멸자, 생성자 내에서 new로 할당한 메모리 공간을 해제할 때 보통 쓴다. 없으면 default 생성자 호출.
    void ShowRecInfo() const;
    Rectangle* GetThisPointer() {
        return this; // 자기 자신의 포인터 반환.
    };
    Rectangle& GetThisReferen() {
        return *this; // 참조자 반환
    };
};

int main(void) {
    // 생성자에 매개변수가 필요 없는 경우 괄호는 꼭 빼야한다! 함수 원형 선언이 되기 때문.
    // 기본 선언이나, new는 생성자 호출함. malloc은 안함.
    Rectangle rec(1, 1, 5, 5); 

    // Rectangle rec[3]; // Rectangle() {} 생성자가 필요. 배열 선언은 생성자 명시 못한다. rec[i].Set 함수로 멤버 변수 일일이 지정.
    // Rectangle *rec[3]; // rec[i] = new Rectangle(x1, y1, x2, y2); 로 선언하게 됨.
    rec.ShowRecInfo();
    return 0;
}

Point::Point(const int &xpos, const int &ypos) {
    if (xpos < 0 || ypos < 0) {
        cout<<"벗어난 범위의 값 전달"<<endl;
    }
    x = xpos;
    y = ypos;
}

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
            :upLeft(x1, y1), lowRight(x2, y2) // 멤버 이니셜라이저, 객체가 아닌 것, const 변수, 참조자도 초기화 가능.
{ 
    // empty
}

int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}

bool Point::SetX(int xpos) {
    if (xpos < 0 || xpos > 100) {
        cout<<"벗어난 범위의 값 전달"<<endl;
        return false;
    }
    this->x = xpos; // 자신의 멤버 변수에 접근.
    return true;
}

bool Point::SetY(int ypos) {
    if (ypos < 0 || ypos > 100) {
        cout<<"벗어난 범위의 값 전달"<<endl;
        return false;
    }
    this->y = ypos;
    return true;
}

void Rectangle::ShowRecInfo() const {
    cout<<"좌 상단: "<<'['<<upLeft.GetX()<<", ";
    cout<<upLeft.GetY()<<']'<<endl;

    cout<<"우 하단: "<<'['<<lowRight.GetX()<<", ";
    cout<<lowRight.GetY()<<']'<<endl;
}