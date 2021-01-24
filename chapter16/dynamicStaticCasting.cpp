#include <iostream>
using namespace std;

class Car {
private:
    int fuelGauge;
public:
    Car(int fuel) : fuelGauge(fuel) { }
    void ShowCarState() {
        cout<<"잔여 연료량: "<<fuelGauge<<endl;
    }
};

class Truck : public Car {
private:
    int freightWeight;
public:
    Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) { }
    void ShowTruckState() {
        ShowCarState();
        cout<<"화물의 무게: "<<freightWeight<<endl;
    }
};

int main(void) {
    // dynamic_cast 는 유도 클래스에서 기초 클래스로 형 변환 하는 경우만 가능, 실패 시 NULL 반환. 실행시간에 안정성 검사하도록 코드를 생성함, 느림
    Truck* ptruck1 = new Truck(70, 150);
    Car* pcar1 = dynamic_cast<Car*>(ptruck1);

    // static_cast 는 유도->기초, 기초->유도 둘 다 가능, 웬만하면 제한적으로 사용. 무조건 형 변환이 되도록 코드 생성, 빠름
    Car* pcar2 = new Truck(80, 200);
    Truck* ptruck2 = static_cast<Truck*>(pcar2);

    double result = static_cast<double>(20)/3; // 기본 자료형 형변환에도 사용됨.


    return 0; 
}