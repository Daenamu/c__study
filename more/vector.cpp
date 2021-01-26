#include <iostream>
#include <vector>

using namespace std;

/*
    [선언]
    vector<int> v;                       // int타입 벡터 생성
    vector<int> v = { 1, 2, 3 };         // int형 백터 생성 후 1, 2, 3 으로 초기화
    vector<int> v[10];                   // int타입 벡터 배열(크기 : 10) 생성
    vector<int> v[] = {{1, 2}, {3, 4}};  // int형 백터 배열 생성(행은 가변이지만 열은 고정)
    vector<vector<int>> v;               // 2차원 백터 생성(행과 열 모두 가변)
    vector<int> v(5);                    // 5개의 원소를 0으로 초기화
    vector<int> v(5, 3);                 // 5개의 원소를 3으로 초기화
    vector<int> v2(v);                   // 벡터 v를 복사하여 벡터v2 생성

    [구조]
    v.front()   // 첫 번째 원소
    v.back()    // 마지막 원소

    v.beign()   // 첫 번째 위치
    v.end()     // 마지막의 다음 위치
    v.rbegin()  // 역순의 첫 번째 위치
    v.rend()    // 역순의 마지막의 다음 위치

    v[index]    // index 위치의 원소
    v.at(index)

    v.size();   // vector의 원소 갯수
    v.capacity; // vector의 물리적 크기

    [값 추가]
    v.push_back(10);  // 마지막 위치에 숫자 10 추가
    v.insert(2,10);   // index 2의 위치에 숫자 10 추가
    v.insert(2,3,4)   // 2번째 위치에 3개의 4값을 추가

    [값 삭제]
    v.pop_back();                        // 마지막에 넣은 값 제거
    v.erase(vec.begin()+10);             // index 10의 값을 제거
    v.erase(vec.begin(), vec.begin()+5); // index 0~5의 값을 제거
    v.clear();    
*/

int main()
{
  // 1~5의 숫자를 Vector에 저장
  vector<int> v1;
  for (int i = 1; i <= 5; i++)
    v1.push_back(i);

  // Iterator로 Vector의 아이템을 출력
  for (auto i = v1.begin(); i != v1.end(); ++i)
    cout << *i << " ";

  // 반대 방향으로 아이템을 출력
  cout << "\n";
  for (auto ir = v1.rbegin(); ir != v1.rend(); ++ir)
    cout << *ir << " ";

  // 배열처럼 Vector[index] 으로 아이템 출력
  cout << "\n";
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << " ";

  // Vector.at(index)로 아이템 출력
  cout << "\n";
  for (int i = 0; i < v1.size(); i++)
    cout << v1.at(i) << " ";

  return 0;
}