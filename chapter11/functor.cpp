#include <iostream>
using namespace std;

class SortRule {
public:
    virtual bool operator()(int num1, int num2) const = 0; // ()연산자 오버로딩, 순수 가상합수
};

class AscendingSort : public SortRule {
public:
    bool operator()(int num1, int num2) const {
        if (num1 > num2) {
            return true;
        } 
        else {
            return false;
        }
    }
};

class DescendingSort : public SortRule {
public:
    bool operator()(int num1, int num2) const {
        if (num1 < num2) {
            return true;
        }
        else {
            return false;
        }
    }
};

class DataStorage {
private:
    int* arr;
    int idx;
    const int MAX_LEN;
public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen) {
        arr = new int[MAX_LEN];
    }
    ~DataStorage() {
        delete []arr;
    }
    void AddData(int num) {
        if (MAX_LEN <= idx) {
            cout<<"더 이상 저장이 불가능합니다."<<endl;
            return;
        }
        arr[idx++] = num;
    }
    void ShowAllData() {
        for (int i = 0; i < idx; i++) {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
    void SortData(const SortRule& functor) { // functor로 버블정렬
        for (int i = 0; i < (idx - 1); i++) {
            for (int j = 0; j < (idx - 1) - i; j++) {
                if (functor(arr[j], arr[j + 1])) { // 객체를 함수처럼 사용, 객체 종류에 따라 다른 연산 수행함!
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main(void) {
    DataStorage storage(5);
    storage.AddData(40);
    storage.AddData(30);
    storage.AddData(50);
    storage.AddData(20);
    storage.AddData(10);

    storage.SortData(AscendingSort()); // 클래스 전달
    storage.ShowAllData();

    storage.SortData(DescendingSort());
    storage.ShowAllData();

    return 0;
}