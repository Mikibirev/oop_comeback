#include <iostream>

using namespace std;

namespace kib {
	void filling(int* a, int l, int r) {	// ��������� ���������� �������
		for (int i = 0; i < l; i++)			// ���������� ���������...
			a[i] = rand() % (r + 1);		// ���������� ����������
	}

	void output(int* a, int l) {			// ��������� ������ �������
		for (int i = 0; i < l; i++)			// ������ ������� �������...
			cout << a[i] << " ";			// ������� �� ����� ��������
		cout << endl;
	}

	int sum(int* a, int l) {				// ������� ������������ ���������
		int s = a[0];						// ��������� �������� �����...
		for (int i = 1; i < l; i++)			// ������ �������
			s += a[i];						// ��������� �� ����������
		return s;
	}
}