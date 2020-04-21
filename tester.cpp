#include "tester.h"
#include "print_ts.h"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

bool stop;
std::vector<std::thread> threads;

void run(std::string str, WHICH_PRINT wp, int numTimesToPrint,
		int millisecond_delay) {
	for (int i = 0; i < numTimesToPrint; i++) {

		if (stop == true) {
			cout<<USER_CHOSE_TO_CANCEL<<endl;
			return;
		}

		switch (wp) {

		case P1:
			PRINT1(str);
			break;
		case P2:
			PRINT2(str, str);
			break;
		case P3:
			PRINT3(str, str, str);
			break;
		case P4:
			PRINT4(str, str, str, str);
			break;
		case P5:
			PRINT5(str, str, str, str, str);
			break;
		}
		cout<<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
	}
}

void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay) {

	for (int i = 0; i < numThreads; ++i) {
		threads.push_back(
				std::thread(run, s, wp, numTimesToPrint, millisecond_delay));
	}
}

void setCancelThreads(bool bCancel) {
	stop = bCancel;
}

void joinThreads() {
	std::vector<std::thread>::iterator itr;
	for (itr = threads.begin(); itr != threads.end(); ++itr)
		itr->join();
}

