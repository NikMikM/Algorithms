//============================================================================
// Name        : Algoritms.cpp
// Author      : Nikitin M.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cassert>//��� assert
#include <cstdint>//��� int64
#include <iomanip>//������������ ����� ������
#include <cmath>//��� �������������� ��������
using namespace std;
template<typename T>
ostream& operator<<(ostream& out,vector<T> v){
	for (auto item : v){
		out << setbase(10) << item << " ";//������� ���������� �����
		//out << item << " ";
	}
	out << endl;
	return out;
}
class Fibonacci {
public:
	static int get(int n){//�������� n-��� ����� ���������
		assert(n>=0);//�������� �� ������������ ����� ������ �����
		vector<int> nums(n+1);//������� ������ ��� ����� ��������� (n+1 �.�. �������� � �������� ����� ���������)
			nums[0] = 0;//������� ����� ���������
			nums[1] = 1;//������ ����� ���������
			for (int i = 2; i < n+1;i++){
				nums[i] = nums[i-1]+nums[i-2];//������ ��������� ����� �����������
			}
			return nums[n];
	}
	static int get_last_digit(int n){//�������� ��������� ����� n-���� ����� ��������
		assert(n>=1);
		int nums[n+1];
		nums[0] = 0;//������� ����� ���������
		nums[1] = 1;//������ ����� ���������
		for (int i = 2; i < n+1;i++){
			nums[i] = (nums[i-1]+nums[i-2])%10;//����������� ��������� ����� �����
		}
		return nums[n];
	}
	 static int get_remainder(int64_t n, int m) {
	    assert(n >= 1);
	    assert(m >= 2);
	    assert(m<pow(10,5));
	    assert(n < pow(10,18));
	   	int64_t nums[n+1];
			nums[0] = 0;//������� ����� ���������
			nums[1] = 1;//������ ����� ���������
	        int period = 0;
			for (int i = 2; i < pow(m,2)+1;i++){
				nums[i] = (nums[i-1]+nums[i-2])%m;//������ ��������� �����
	            if ((nums[i] ==1)&&(nums[i-1]==0)){
	                period = i-1;//������� �������� ������� ������
	                break;
	            }
			 }
			cout <<"period "<< period << endl;//��������� ������ ������
			cout <<"nums[n]  "<< setbase(10) << nums[n] << endl;//������ ������� int64_t �� ����������� ���������
			if (period == 0){//���� ������ �� ������ ������� ������ ������� �� ����� ���������
				n = nums[n];
			}else {
			n = nums[n%period];//���� ������ ������ ���������� ������� �� �������
			}
	    return n ;
	 }
};
int main() {
//fibonacci nums
// F = {0,1 ,F(n-2)+F(n-1))
//Lemma: F>= 2^n/2 ��� n>=6
// F(6), F(7) ����������� (���� ��������), ������������� �������� �� n: F = F(n-2)+ F(n-1) >= 2^(n-2)/2 + 2^(n-1)/2 >= 2^n/2
	int64_t n;
	int m;
	cin >> n >> m;
//	cout << Fibonacci::get(n) << endl;
//	cout << Fibonacci::get_last_digit(n) << endl;
	cout << Fibonacci::get_remainder(n,m) << endl;


	return 0;
}
