#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
    int* arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr) {} // 복사 생성자 막기. 저장소의 복사는 불필요
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {} // 대입 생성자 막기.
public:
    BoundCheckIntArray(int len): arrlen(len) {
        arr = new int[len];
    }
    ~BoundCheckIntArray() {
        delete[] arr;
    }
    int& operator[] (int idx) { // 배열 연산자
        if (idx < 0 || idx >= arrlen) { // C++은 경계검사를 하지 않으므로 사용자가 직접 정의해야함
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[] (int idx) const { // const 오버로딩, 배열을 조회할 땐 const로 하기 때문, 수정을 막기 위해 int형 반환
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

void ShowAllData(const BoundCheckIntArray& ref) {
    int len = ref.GetArrLen();
    for (int idx = 0; idx < len; idx++) {
        cout<<ref[idx]<<endl; // const 인 객체는 const 함수만 호출.
    }
}

int main(void) {
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 11; 
    }
    ShowAllData(arr);
    return 0;
}