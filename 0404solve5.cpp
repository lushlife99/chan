#include <iostream>

class Sorting {
	int* array;

public:
	Sorting(int n); //생성자
	void sort();   //5의배수 오름차순, 나머지 내림차순. 5의 배수를 갖는 값들이 앞쪽으로 정렬.
	void print();
};

Sorting::Sorting(int n) {
	while (n < 1 || n >10000) { // 예외처리
		std::cout << "배열의 크기를 다시 지정:";
		std::cin >> n;
	}

	array = new int[n];
	
	int k;
	std::cout << "배열 값" << n << "개 지정" << std::endl;
	for (int i = 0; i < n; i++) {                            //배열값 초기화.
		std::cin >> k;
		array[i] = k;
	}

}

void Sorting::sort() {
	int count = 0; //5의배수들의 개수 저장.
	int size = _msize(array) / 4; 
	int* temp5 = new int[size]; //5의 배수들.
	int index5 = 0;
	int* temp = new int[size]; //5의 배수 아닌값들을 저장.
	int index = 0;
	for (int i = 0; i < size; i++) { // 5의 배수 스캔.
		if (array[i] % 5 == 0) {
			temp5[index5] = array[i];
			index5++;
			count++;
		}
		else {
			temp[index] = array[i];
			index++;
		}
	}

	int temp0; // 교환용 변수.
	for (int i = 0; i < count - 1; i++) {//temp5 오름차순
		for (int j = i + 1; j < count; j++) {
			if (temp5[i] > temp5[j]) {
				temp0 = temp5[i];
				temp5[i] = temp5[j];
				temp5[j] = temp0;
			}
		}
	}

	for (int i = 0; i < size - count - 1; i++) {//temp 내림차순
		for (int j = i + 1; j < size - count; j++) {
			if (temp[i] < temp[j]) {
				temp0 = temp[i];
				temp[i] = temp[j];
				temp[j] = temp0;
			}
		}
	}

	for (int i = 0; i < count; i++) { //앞에서부터 5의 배수 복사.
		array[i] = temp5[i];
	}
	for (int i = count; i < size; i++) { // 나머지 복사.
		array[i] = temp[i-count];
	}
	
	delete [] temp5,temp;

}


void Sorting::print() {

	for (int i = 0; i < _msize(array)/4; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	Sorting s1(100000);
	s1.sort();
	s1.print();
}