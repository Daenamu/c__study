#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[100];
public:
    Employee(const char *name) {
        strcpy(this->name, name); // 동적할당 아님 ㅎㅎ
    }
    void ShowYourName() const {
        cout<<"name: "<<name<<endl;
    }
    virtual int GetPay() const = 0; // virtual: Employee 클래스 포인터를 이용하여 이 함수를 호출할 때, 실제로 가리키는 객체의 함수를 호출한다.
    virtual void ShowSalaryInfo() const = 0; // 0: 순수 가상함수로, Employee 클래스는 추상 클래스가 되어 선언이 불가해진다. 
};

class PermanentWorker : public Employee {
private:
    int salary; // 월 급여
public:
    PermanentWorker(const char* name, int money) : Employee(name), salary(money) {}
    int GetPay() const { // 함수 오버라이딩
        return salary;
    }
    void ShowSalaryInfo() const { // virtual 없음: PermanentWorker 클래스 포인터를 이용하여 이 함수를 호출할 때, 이 함수를 호출한다.
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl; 
    }
};

class SalesWorker : public PermanentWorker {
private:
    int salesResult; // 월 판매 실적
    double bonusRatio; // 상여금 비율
public:
    SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
    void AddSalesResult(int value) {
        salesResult += value;
    }
    int GetPay() const {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio); // 오버라이딩: 부모의 함수 호출
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class TemporaryWorker : public Employee {
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
    void AddWorkTime(int time) {
        workTime += time;
    }
    int GetPay() const {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class EmployeeHandler { // 기능의 처리를 담당하는 클래스, 데이터 관리와 기능은 분리하는게 좋다!
private:
    Employee *empList[50]; // 모든 직원을 Employee 상위 클래스로 다룬다.
    int empNum;
public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++) {
            empList[i]->ShowSalaryInfo(); // 가상함수이기에 객체의 자료형에 따라 출력 할 수 있음
        }
    }
    void ShowTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++) {
            sum += empList[i]->GetPay();
        }
        cout<<"salary sum: "<<sum<<endl;
    }
    ~EmployeeHandler() {
        for(int i = 0; i < empNum; i++) {
            delete empList[i];
        }
    }
};

int main(void) {
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));

    TemporaryWorker *alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker *seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}