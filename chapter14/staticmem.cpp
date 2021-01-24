#include <iostream>
using namespace std;

template <typename T>
class SimpleStaticMem {
private:
    static T mem;
public:
    void AddMem(T num) {
        mem += num;
    }
    void ShowMem() {
        cout<<mem<<endl;
    }
};

template <typename T>
T SimpleStaticMem<T>::mem = 0; // 템플릿 기반 static 멤버 초기화 문장

template <>
long SimpleStaticMem<long>::mem = 5; // static 멤버 특수화

int main(void) {
    SimpleStaticMem<int> obj1;
    SimpleStaticMem<int> obj2;
}