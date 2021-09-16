/*
 * nod.cpp
 *
 *  Created on: 17 сент. 2021 г.
 *      Author: Михаил
 */

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cassert>//для assert
#include <cstdint>//для int64
#include <iomanip>//манипуляторы ввода вывода
#include <cmath>//для матиматических операций
using namespace std;
// целые отрицательные не равные нулю a,b
// lemma a>= b >0 - r остаток НОД (a,b) = нод (r,b)
//НОД(a,b) <= НОД (a-b,b)
//НОД(a,b) >= НОД(a-b,b)
//Алгоритм Евклида:
//если a=0 вернуть b
//если b = 0 вернуть a
//если a>=b вернуть Euclid(a mod b, b)
//если b >= a вернуть Euclid(a, b mod a)
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


