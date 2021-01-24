#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2; // operator+ 연산자

    cout<<str1<<endl; // operator<< 연산자
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1 += str2; // operator+= 연산자
    if (str1 == str3) { // operator== 연산자
        cout<<"동일 문자열!"<<endl;
    }
    else {
        cout<<"동일하지 않은 문자열!"<<endl;
    }

    string str4;
    cout<<"문자열 입력: ";
    cin>>str4; // operator>> 연산자
    cout<<"입력한 문자열: "<<str4<<endl;
    
    return 0;
}