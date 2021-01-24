#include <iostream>
using namespace std;

class Temporary {
private:
    int num;
public:
    Temporary(int n) : num(n) {
        cout<<"create obj: "<<num<<endl;
    }
    ~Temporary() {
        cout<<"destroy obj: "<<num<<endl;
    } 
    void ShowTempInfo() {
        cout<<"my num is "<<num<<endl;
    }
};

int main(void) {
    Temporary(100); // 임시 객체 선언, 다음 행으로 넘어가면 소멸.
    
    Temporary(200).ShowTempInfo(); // 참조자 형식으로 반환됨.
    const Temporary &ref = Temporary(300); // 참조자로 받으면 소멸 안됨.
}