#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;
void test(){
	while(true){
		cout << "1" << flush;
		sleep(1);
		system("cls");
	}
}

int main() {
    std::thread t1(test);
	int test2;
    cin >> test2;
	while(true){
		cout << test2 << flush;
		sleep(1);
	}
	return 0;
}