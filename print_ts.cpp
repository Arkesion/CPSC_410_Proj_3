#include "print_ts.h"
#include <mutex>
#include <iostream>

using namespace std;

mutex m;

void PRINT1(std::string &txt) {
	lock_guard<mutex> lock(m);
	cout<<txt;
}

void PRINT2(std::string &txt, std::string &txt1) {
	lock_guard<mutex> lock(m);
	cout<<txt<<txt1;
}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
	lock_guard<mutex> lock(m);
	cout<<txt<<txt1<<txt2;
}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3) {
	lock_guard<mutex> lock(m);
	cout<<txt<<txt1<<txt2<<txt3;
}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4) {
	lock_guard<mutex> lock(m);
	cout<<txt<<txt1<<txt2<<txt3<<txt4;
}
