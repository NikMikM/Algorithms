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
#include <cassert>//для assert
#include <cstdint>//для int64
#include <iomanip>//манипуляторы ввода вывода
#include <cmath>//для матиматических операций
using namespace std;
template<typename T>
ostream& operator<<(ostream& out,vector<T> v){
	for (auto item : v){
		out << setbase(10) << item << " ";//выводим десятичные числа
		//out << item << " ";
	}
	out << endl;
	return out;
}
class Fibonacci {
public:
	static int get(int n){//Получаем n-ное число Фибоначчи
		assert(n>=0);//проверка на правильность ввода номера числа
		vector<int> nums(n+1);//заводим массив для чисел Фибоначчи (n+1 т.к. начинаем с нулевого числа Фибоначчи)
			nums[0] = 0;//Нулевое число Фибоначчи
			nums[1] = 1;//Первое число Фибоначчи
			for (int i = 2; i < n+1;i++){
				nums[i] = nums[i-1]+nums[i-2];//Каждое следующее число вычисляется
			}
			return nums[n];
	}
	static int get_last_digit(int n){//Получаем последнюю цифру n-ного числа фибоначи
		assert(n>=1);
		int nums[n+1];
		nums[0] = 0;//Нулевое число Фибоначчи
		nums[1] = 1;//Первое число Фибоначчи
		for (int i = 2; i < n+1;i++){
			nums[i] = (nums[i-1]+nums[i-2])%10;//Вычисляется последняя цифра числа
		}
		return nums[n];
	}
	 static int get_remainder(int64_t n, int m) {
	    assert(n >= 1);
	    assert(m >= 2);
	    assert(m<pow(10,5));
	    assert(n < pow(10,18));
	   	int64_t nums[n+1];
			nums[0] = 0;//Нулевое число Фибоначчи
			nums[1] = 1;//Первое число Фибоначчи
	        int period = 0;
			for (int i = 2; i < pow(m,2)+1;i++){
				nums[i] = (nums[i-1]+nums[i-2])%m;//Каждое следующее число
	            if ((nums[i] ==1)&&(nums[i-1]==0)){
	                period = i-1;//находим значение периода Пизано
	                break;
	            }
			 }
			cout <<"period "<< period << endl;//найденный период Пизано
			cout <<"nums[n]  "<< setbase(10) << nums[n] << endl;//способ вывести int64_t по десятичному основанию
			if (period == 0){//если период не найден выводим просто остаток от числа Фибоначчи
				n = nums[n];
			}else {
			n = nums[n%period];//если период найден определяем элемент из периода
			}
	    return n ;
	 }
};
int main() {
//fibonacci nums
// F = {0,1 ,F(n-2)+F(n-1))
//Lemma: F>= 2^n/2 для n>=6
// F(6), F(7) выполняется (база индукции), следовательно индукция по n: F = F(n-2)+ F(n-1) >= 2^(n-2)/2 + 2^(n-1)/2 >= 2^n/2
	int64_t n;
	int m;
	cin >> n >> m;
//	cout << Fibonacci::get(n) << endl;
//	cout << Fibonacci::get_last_digit(n) << endl;
	cout << Fibonacci::get_remainder(n,m) << endl;


	return 0;
}
