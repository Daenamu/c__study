#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage) : age(myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
    }
    ~Person() {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
    Person& operator=(const Person& ref) { // ob1 = ob2 와 같은 대입 연산자 오버로딩
        delete []name; // 디폴트 대입 연산자는 얕은 복사를 함. 따라서 기존 메모리를 해제 해야함
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
    void ShowPersonInfo() const {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
};

int main(void) {
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1; // 대입 연산자 수행, 디폴트는 얕은 복사만 진행
    // 대입 연산자는 선언과 초기화를 별도로 수행, 이니셜라이저를 이용하면 성능 향상!

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}