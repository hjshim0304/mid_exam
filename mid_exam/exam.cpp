#include <iostream>
#include <string>

using namespace std;

class Stack {
    int size;
    int* mem;  // 동적 메모리 할당. 스택 공간
    int tos;   // top of stack. -1이면 스택이 비었음
public:
    Stack(int size = 10) {
        this->size = size;
        this->mem = new int[size];
        tos = -1;
    }
    ~Stack() { delete[] mem; } // 배열 반환
    Stack& operator << (int x) {
        if (tos == size - 1) {
            cout << "스택이 가득 찼습니다!" << endl;
            return *this; // 스택이 가득 차면 현재 스택 객체 반환
        }
        tos++;
        mem[tos] = x;
        return *this; // 연속적인 푸시를 위해 스택 객체 자신을 반환
    }

    // 팝 (pop) 연산자 >>
    Stack& operator >> (int& x) {
        if (tos == -1) {
            cout << "스택이 비어 있습니다!" << endl;
            // 스택이 비어있을 경우 x 값을 어떻게 처리할지 결정해야 합니다.
            // 여기서는 변경하지 않고 스택 객체를 반환합니다.
            return *this;
        }
        x = mem[tos];
        tos--;
        return *this; // 연속적인 팝을 위해 스택 객체 자신을 반환
    }
    bool operator ! () {
        return this->tos == -1 ? true : false;
    }
};

int main() {
    Stack stack;
    stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시
    while (true) {
        if (!stack) break; // 스택 empty
        int x;
        stack >> x; // 스택의 탑에 있는 정수 팝
        cout << x << ' ';
    }
    cout << endl;
}