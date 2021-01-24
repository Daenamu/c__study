#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char *name;
    int age;
public:
    Person(const char *myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person(const Person &copy) : age(copy.age) // 복사 생성자, 디폴트는 모든 멤버 변수를 그대로 복사함.
    {
        name = new char[strlen(copy.name) + 1]; // 배열은 포인터만 복사 되므로 깊은 복사를 위해선 디폴트 복사 생성자를 재정의해야함.
        strcpy(name, copy.name);
    }
    /*
    explicit Person(const Person &copy) : age(copy.age), name(copy.name) { // Person h2(h1); 과 같은 묵시적 변환 금지!

    }
    */
    void ShowPersonInfo() const {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person() {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
};

int main(void) {
    Person man1("Lee dong woo", 29); // 일반 생성자
    Person man2 = man1; // 복사 생성자
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}