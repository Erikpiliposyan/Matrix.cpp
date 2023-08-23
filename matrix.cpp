#include <iostream>
#include <fstream>

std::ofstream f1("./f1.txt");

template<typename T>
class Matrix {
private:

	T** matrix;
	int row;
	int column;

	void init() {
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[column];
		}
	}

public:
	Matrix(int r, int c) {
		if (r < 0 || c < 0)
		{
			std::cout << "Error: Size values can't be less than 0 !" << std::endl;
		}
		else {
			row = r;
			column = c;
			matrix = new T* [row];
			init();
		}
	}

	void print() {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				f1 << matrix[i][j] << ' ';
			}
			f1 << std::endl;
		}
		f1 << std::endl;
	}
};   

int main() {
	f1.clear();
	Matrix<int> mat(3, 3);
	mat.print();
}
