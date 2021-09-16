/*
 * nod.cpp
 *
 *  Created on: 17 ����. 2021 �.
 *      Author: ������
 */

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cassert>//��� assert
#include <cstdint>//��� int64
#include <iomanip>//������������ ����� ������
#include <cmath>//��� �������������� ��������
using namespace std;
// ����� ������������� �� ������ ���� a,b
// lemma a>= b >0 - r ������� ��� (a,b) = ��� (r,b)
//���(a,b) <= ��� (a-b,b)
//���(a,b) >= ���(a-b,b)
//�������� �������:
//���� a=0 ������� b
//���� b = 0 ������� a
//���� a>=b ������� Euclid(a mod b, b)
//���� b >= a ������� Euclid(a, b mod a)
int Euclid( int& a, int& b){
	if (a == 0){
		return b;
	} else if (b == 0){
		return a;
	} else if (a >= b){
		int c = a%b;
		return Euclid(c,b);
	} else if (b >= a){
		int c = b%a;
		return Euclid(a,c);
	}
}
int main(){
	int a,b;
	cin >> a >> b;
	cout << Euclid(a,b);
 	return 0;
}


