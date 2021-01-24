#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:   
    char *name;
public:
    Person(const char* myname) {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    ~Person() {
        delete []name;
    }
    void WhatYourName() const {
        cout<<"My name is "<<name<<endl;
    }
};

class UnivStudent: public Person { // Person을 public으로 상속.
private:
    char *major;
public:
    UnivStudent(const char* myname, const char* mymajor) : Person(myname) { // 생성자 호출, 없으면 Person() 호출함. 부모 생성 -> 자식 생성 순.
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    ~UnivStudent() { // 자식 클래스 소멸 -> 부모 클래스 소멸 순서.
        delete []major; 
    }
    void WhoAreYou() const {
        WhatYourName();  // 상속하더라도 private 변수에는 직접 접근 불가능
        cout<<"My major is "<<major<<endl<<endl;
    }
};

int main(void) {
    UnivStudent st1("Kim", "Mathmatics");
    st1.WhoAreYou();
    // UnivStudent &fref = st1;       // 참조자도 가능. 포인터와 마찬가지로 가상함수 등의 개념이 적용된다.
    // fref.WhoAreYou();
    UnivStudent st2("Hong", "Physics");
    st2.WhoAreYou();
    return 0;
}