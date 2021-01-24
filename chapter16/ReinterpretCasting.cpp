#include <iostream>
using namespace std;

int main(void) {
    // reinterpret_cast 는 포인터와 관련된 모든 유형으로의 변환이 가능
    int num = 0x010203;
    char* ptr = reinterpret_cast<char*>(&num); // 바이트 단위 접근을 위해 형변환

    for (int i = 0; i < sizeof(num); i++) {
        cout<<static_cast<int>(*(ptr+i))<<endl; // 기본 자료형은 static_cast로 변환
    }

    int adr = reinterpret_cast<int>(ptr); // 주소를 정수로 변환
    cout<<"Addr: "<<adr<<endl;
}