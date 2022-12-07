#include <iostream>
#define _USE_MATH_DEFINES  // ����������� �������������� ��������
#include <math.h>		   // ����������� �������������� ��������

using namespace std;	   // ������������ ��� std

namespace kib {                           // ����������� ������������ ���
	double period_l(float l) {            // �������, ������������ ������
		const double g = 9.80665;		  // ��������� ���������� �������
		return 2 * M_PI * sqrt(l / g);	  // ������� ������� ��������
	}
}