#pragma once

using namespace std;		// ������������ ����������� ������������ ��� std
using arr = vector<int>;	// ��������� vector<int> �� arr � ������� using-����������
namespace kib {				// ������������ ����������� ������������ ��� kib

	void random_vec(arr& a, int l, int r);		// ��������� ���������� ������� ���������� ����������
	void output_screen(const arr& a);			// ��������� ������ ��������� ������� a �� ����� ����� ������
	int sum(const arr& a);						// ������� ������������ l ��������� ������� a
	void output_file(const arr& a, string f);	// ��������� ������ ������� a � ���� f
	void input_file(arr& a, string f);			// ��������� ������ ������ �� ����� f � ������ a
}