#include <iostream>
#include <cmath>

class Vector {
	int top;
	int* array;

public:
	Vector(int n);
	void push_back(int value);
	void pop_back();
	void size();
};

Vector::Vector(int n) {
	int top = 0;
	array = new int[n*n*6];
 
}

void Vector::push_back(int value) {
	int n;
	n = sqrt((_msize(array) / 6));
	if (top == n) {
		std::cout << "더이상 넣을 수 없습니다." << std::endl;
	}

	else {
		array[top] = value;
		top++;
	}

}
void Vector::pop_back() {
	if (top == 0) {
		std::cout << "더이상 출력할 수 없습니다." << std::endl;
	}
	else {
		std::cout <<"출력:"<< array[top-1] << " ";
		top--;
	}
}

void Vector::size() {
	std::cout << "현재까지 저장된 array의 값 개수: " << top << std::endl;
}

int main() {



	Vector v1(8);

	v1.push_back(1);
	v1.push_back(2);
	v1.pop_back();
	v1.push_back(3);
	v1.pop_back();
	v1.size();
	
}

//sizeof 연산자를 쓰면 안됨. 왜냐하면 int포인터는 64비트 운영체제에서 8의 크기를 갖음.
//동적으로 할당된 변수들은 heap영역에 저장되는데 _msize함수는 heap 영역에 할당된 메모리의 크기를 읽어옴.
