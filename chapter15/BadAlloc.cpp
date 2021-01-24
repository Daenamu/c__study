#include <iostream>
#include <new> // bad_alloc 예외 클래스
using namespace std;

int main(void) {
    int num = 0;

    try {
        while (1) {
            num++;
            cout<<num<<"번째 할당 시도"<<endl;
            new int[10000][10000];
        }
    }
    catch (bad_alloc &bad) {
        cout<<bad.what()<<endl;
        cout<<"더 이상 할당 불가!"<<endl;
    }
    catch (...) { // 모든 예외 처리
        cout<<"원인 모를 오류 발생"<<endl;
    }
    return 0;
}