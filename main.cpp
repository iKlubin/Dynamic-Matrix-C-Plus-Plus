#include <iostream>

using namespace std;

template <class T> class Matrix
{
private:
	T** m;
	int x, y;
public:
	Matrix(int xP, int yP) : x(xP), y(yP)
	{
		m = new T * [x];
		for (int i = 0; i < x; i++)
		{
			m[i] = new T[y];
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				m[i][j] = 0;
			}
		}
	};
	void random()
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				m[i][j] = rand() % 10;
			}
		}
	}
	auto min()
	{
		auto min = m[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (min > m[i][j])
				{
					min = m[i][j];
				}
			}
		}
		return min;
	}
	auto max()
	{
		auto max = m[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (max < m[i][j])
				{
					max = m[i][j];
				}
			}
		}
		return max;
	}
	void newSize(int xP, int yP)
	{
		if (x >= xP and y >= yP)
		{
			T** temp = new T * [xP];
			for (int i = 0; i < xP; i++)
			{
				temp[i] = new T[yP];
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					temp[i][j] = m[i][j];
				}
			}
			m = new T * [xP];
			for (int i = 0; i < xP; i++)
			{
				m[i] = new T[yP];
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					m[i][j] = temp[i][j];
				}
			}
			for (int i = 0; i < xP; i++)
			{
				delete temp[i];
			}
			delete[] temp;
			x = xP, y = yP;
		}
		else if (x < xP and y < yP)
		{
			T** temp = new T * [x];
			for (int i = 0; i < x; i++)
			{
				temp[i] = new T[y];
			}
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					temp[i][j] = m[i][j];
				}
			}
			m = new T * [xP];
			for (int i = 0; i < xP; i++)
			{
				m[i] = new T[yP];
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					m[i][j] = 0;
				}
			}
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					m[i][j] = temp[i][j];
				}
			}
			for (int i = 0; i < x; i++)
			{
				delete temp[i];
			}
			delete[] temp;
			x = xP, y = yP;
		}
		else if (x <= xP and y >= yP)
		{
			T** temp = new T * [x];
			for (int i = 0; i < x; i++)
			{
				temp[i] = new T[yP];
			}
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					temp[i][j] = m[i][j];
				}
			}
			m = new T * [xP];
			for (int i = 0; i < xP; i++)
			{
				m[i] = new T[yP];
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					m[i][j] = 0;
				}
			}
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					m[i][j] = temp[i][j];
				}
			}
			for (int i = 0; i < x; i++)
			{
				delete temp[i];
			}
			delete[] temp;
			x = xP, y = yP;
		}
		else if (x >= xP and y <= yP)
		{
			T** temp = new T * [xP];
			for (int i = 0; i < xP; i++)
			{
				temp[i] = new T[y];
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < y; j++)
				{
					temp[i][j] = m[i][j];
				}
			}
			m = new T * [xP];
			for (int i = 0; i < xP; i++)
			{
				m[i] = new T[yP];
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < yP; j++)
				{
					m[i][j] = 0;
				}
			}
			for (int i = 0; i < xP; i++)
			{
				for (int j = 0; j < y; j++)
				{
					m[i][j] = temp[i][j];
				}
			}
			for (int i = 0; i < xP; i++)
			{
				delete temp[i];
			}
			delete[] temp;
			x = xP, y = yP;
		}
	}
	void operator+(Matrix& obj)
	{
		for (int i = 0; i < x and i < obj.x; i++)
		{
			for (int j = 0; j < y and i < obj.y; j++)
			{
				m[i][j] += obj.m[i][j];
			}
		}
	}
	void operator-(Matrix& obj)
	{
		for (int i = 0; i < x and i < obj.x; i++)
		{
			for (int j = 0; j < y and i < obj.y; j++)
			{
				m[i][j] -= obj.m[i][j];
			}
		}
	}
	void operator*(Matrix& obj)
	{
		for (int i = 0; i < x and i < obj.x; i++)
		{
			for (int j = 0; j < y and i < obj.y; j++)
			{
				m[i][j] *= obj.m[i][j];
			}
		}
	}
	void operator/(Matrix& obj)
	{
		for (int i = 0; i < x and i < obj.x; i++)
		{
			for (int j = 0; j < y and i < obj.y; j++)
			{
				m[i][j] /= obj.m[i][j];
			}
		}
	}
	auto operator()(int xP, int yP, int n)
	{
		m[xP][yP] = n;
	}
	auto operator[](int index)
	{
		return m[index];
	}
	friend ostream& operator<<(ostream& out, Matrix& obj)
	{
		for (int i = 0; i < obj.x; i++)
		{
			for (int j = 0; j < obj.y; j++)
			{
				out << obj[i][j];
				if (j + 1 != obj.y)
				{
					out << " ";
				}
			}
			out << endl;
		}
		return out;
	}
	~Matrix()
	{
		for (int i = 0; i < x; i++)
		{
			delete m[i];
		}
		delete m;
	};
};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	int x, y, n;
	int choice;
	char arfChoice;
	cout << "Введите размер первой матрицы(x, y): ";
	cin >> x >> y;
	Matrix <int> m1(x, y);
	cout << "Введите размер второй матрицы(x, y): ";
	cin >> x >> y;
	Matrix <int> m2(x, y);
	do
	{
		cout << "Выберите действие(0 - Выход, 1 - Заполнение матрицы, 2 - Заполнение случаными числами, 3 - Вывод матрицы, 4 - Арифметические действия, 5 - Поиск минимального и максимального значения, 6 - Изменение размена матрицы): ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Выберите матрицу(1, 2): ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Введите x, y и значение: ";
				cin >> x >> y >> n;
				m1(x, y, n);
			}
			else
			{
				cout << "Введите x, y и значение: ";
				cin >> x >> y >> n;
				m2(x, y, n);
			}
		}
		else if (choice == 2)
		{
			cout << "Выберите матрицу(1, 2): ";
			cin >> choice;
			if (choice == 1)
			{
				m1.random();
			}
			else
			{
				m2.random();
			}
		}
		else if (choice == 3)
		{
			cout << "Выберите матрицу(1, 2): ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "M1:\n" << m1 << endl;
			}
			else
			{
				cout << "M2:\n" << m2 << endl;
			}
		}
		else if (choice == 4)
		{
			cout << "Введите действие(+, -, *, /): ";
			cin >> arfChoice;
			if (arfChoice == '+')
			{
				m1 + m2;
				cout << m1 << endl;
			}
			else if (arfChoice == '-')
			{
				m1 - m2;
				cout << m1 << endl;
			}
			else if (arfChoice == '*')
			{
				m1 * m2;
				cout << m1 << endl;
			}
			else if (arfChoice == '/')
			{
				m1 / m2;
				cout << m1 << endl;
			}
			else
			{
				cout << "Ошибка!\n";
			}
		}
		else if (choice == 5)
		{
			cout << "Выберите матрицу(1, 2): ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "M1:\nMin: " << m1.min() << "\nMax: " << m1.max() << endl;
			}
			else
			{
				cout << "M2:\nMin: " << m2.min() << "\nMax: " << m2.max() << endl;
			}
		}
		else if (choice == 6)
		{
			cout << "Выберите матрицу(1, 2): ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Введите x и y: ";
				cin >> x >> y;
				m1.newSize(x, y);
			}
			else
			{
				cout << "Введите x и y: ";
				cin >> x >> y;
				m2.newSize(x, y);
			}
		}
		cout << endl;
	} while (choice != 0);
	return 0;
}
