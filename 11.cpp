#include <iostream>
#include <math.h>

class rotation {
	int size;
	int array[1000][1000]; // row//column 순서.
	int start, end;
	int temp1, temp2, temp3, temp4;

public:
	rotation(int n1);
	void print();
	
	
	void right_row(int row); //가로
	void left_row(int row);	
	void up_col(int col);   //세로
	void down_col(int col);
	void vertex(bool a);
	
	void right_rotating(int rep);
	void left_rotating(int rep);
	void save();
};

rotation::rotation(int n1) {
	size = n1;
	int p = 1;
	start = 0;//배열 크기 줄어들때 가작 작은 인덱스
	end = size-1;//배열 크기 줄어들 때 가장 큰 인덱스
	temp1, temp2, temp3, temp4 = 0;
	for (int i = 0; i < size; i++) {//배열 채워넣음.
		for (int k = 0; k < size; k++) {
			array[i][k] = p;
			p++;
		}
	}
}
void rotation::print() {
	for (int i = 0; i < size;i++) {
		for (int k = 0; k < size; k++) {
			std::cout << array[i][k]<<" ";
		}
		printf("\n");
	}
	printf("\n\n");
}
void rotation::right_row(int row) {

	for (int i = end; i > start;i--) {
		array[row][i] = array[row][i-1];
	}
}
void rotation::left_row(int row) {
	for (int i = start; i < end; i++) {
		array[row][i] = array[row][i+1];
	}
}
void rotation::up_col(int col) {
	for (int i = start; i < end; i++) {
		array[i][col] = array[i+1][col];
	}
}

void rotation::down_col(int col) {
	for (int i = end; i > start; i--) {
		array[i][col] = array[i-1][col];

	}
}

void rotation::save() {
	temp1 = array[start][start];
	temp2 = array[start][end];
	temp3 = array[end][start];
	temp4 = array[end][end];
}

void rotation::vertex(bool a) {
	if (a == true) {
		array[start][start +1] = temp1;
		array[start + 1][end] = temp2;
		array[end - 1][start] = temp3;
		array[end][end - 1] = temp4;
	}
	
 
	else {
		array[start + 1][start] = temp1;
		array[start][end - 1] = temp2;
		array[end][start + 1] = temp3;
		array[end - 1][end] = temp4;
	}
}

void rotation::right_rotating(int rep) {//홀, 짝 나눠서.
	if (size % 2 == 1) {
		for (int i = 0; i < rep; i++) {
			for (start; end - start != 0; start++) {
				save();
				right_row(start);
				down_col(end);
				left_row(end);
				up_col(start);
				vertex(true);
				end -= 1;
			}
			start = 0;
			end = size - 1;
		}
	}
	else {
			for (int i = 0; i < rep; i++) {
				
				if (end -start!=1) {
					for (start; end - start > 1; start++) {
						save();
						right_row(start);
						down_col(end);
						left_row(end);
						up_col(start);
						vertex(true);
						end -= 1;
					}
				}
				save();
				vertex(true);
				
			}
			start = 0;
			end = size - 1;
	}
}

void rotation::left_rotating(int rep) {
	if (size % 2 == 1) {
		for (int i = 0; i < rep; i++) {
			for (start; end - start != 0; start++) {
				save();
				left_row(start);
				down_col(start);
				right_row(end);
				up_col(end);
				vertex(false);
				end -= 1;
			}
			start = 0;
			end = size - 1;
		}
	}
	else {
		for (int i = 0; i < rep; i++) {
				if (end - start != 1) {
					for (start; end - start > 1; start++) {
						save();
						left_row(start);
						down_col(start);
						right_row(end);
						up_col(end);
						vertex(false);
						end -= 1;
					}
				}
				save();
				vertex(false);

			}
			start = 0;
			end = size - 1;
		}
}

int main() {
	int index;
	int rep;
	std::cout << "인덱스 설정: " << std::endl;
	std::cin >> index;
	std::cout << "반복 횟수 설정: " << std::endl;
	std::cin >> rep;
	rotation test(index);
	test.print();
	test.right_rotating(rep);
	test.print();
	
	return 0;
}
