#include <iostream>

namespace mystd {
    using namespace std;

    class ostream { // cout은 ostream의 객체다!
    public:
        ostream& operator<< (char *str) {
            printf("%s", str);
            return *this; // 연속 된 연산자에 대비하여, 자신을 계속 전달하도록 함. ex) cout<<'['<<endl;
        }
        ostream& operator<< (char str) {
            printf("%c", str);
            return *this;
        }
        ostream& operator<< (int num) {
            printf("%d", num);
            return *this;
        }
        ostream& operator<< (double e) {
            printf("%g", e);
            return *this;
        }
        ostream& operator<< (ostream& (*fp)(ostream &ostm)) { // 함수를 인자로 받음
            return fp(*this);
        }
    };

    ostream& endl(ostream &ostm) { // endl 함수 지정
        ostm<<'\n';
        fflush(stdout);
        return ostm;
    }

    ostream cout; // cout 전역 객체 생성
}

int main(void) {
    using mystd::cout;
    using mystd::endl;

    cout<<"Simple String";
    cout<<endl; // 함수를 인자로 전달
    endl(cout); // 다른 방법으로도 가능
}