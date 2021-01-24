#include <iostream>
using namespace std;

template <typename T = int, int len = 7> // 디폴트 값 지정, 변수 선언도 가능
class SimpleArray {
private:
    T arr[len]; // 템플릿 선언과 동시에 초기화 가능, 다른 값이 오면 서로 다른 자료형이 되버림.
public:
    T& operator[] (int idx) {
        return arr[idx];
    }
    SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref) {
        for (int i = 0; i < len; i++) {
            arr[i] = ref.arr[i];
        }
        return *this;
    }
};

int main(void) {
    SimpleArray<char, 3> carr;
    SimpleArray<> arr;

    return 0;
}