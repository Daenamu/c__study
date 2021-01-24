#include <iostream>

inline int SQUARE(int x) { // 매크로 함수와 같음.
    return x*x;
}

template <typename T> // 제너럴 함수
inline T SQUARE_TWO(T x) {
    return x*x;
} 

int main(void) {
    std::cout<<SQUARE(5)<<std::endl;
    std::cout<<SQUARE_TWO(5.5)<<std::endl;
}