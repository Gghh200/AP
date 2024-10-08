#include <iostream>
using namespace std;
int main(){
	void beanmachine();
	beanmachine();
	#ifdef _DEBUG
		_onexit(_CrtDumpMemoryLeaks);
	#endif
	return 0;
}
void beanmachine() {
	int BallNum;
	int LevelsNum;
	void distribution(int LevelsNum, int* buckits, int BallNum);
	int* buckitsCount(int BallNum, int LevelsNum, int* buckits);
	srand((unsigned)time(0));
	cout << "Enter number of balls: ";
	cin >> BallNum;
	cout << "Enter numebr of levels: ";
	cin >> LevelsNum;
	int* buckits = (int*)malloc(sizeof(int) * (LevelsNum + 1));
	for (int i = 0; i < LevelsNum + 1; i++) {
		buckits[i] = 0;
	}
	buckits = buckitsCount(BallNum, LevelsNum, buckits);
	distribution(LevelsNum, buckits, BallNum);
	free(buckits);
	buckits = nullptr;
}

int* buckitsCount(int BallNum, int LevelsNum, int* buckits) {
	int Count = 0;
	for (int i = 0; i < BallNum; i++)
	{
		for (int j = 0; j < LevelsNum; j++) {
			int random = (rand() % 2) + 1;
			if (random == 1) {
				Count = Count + 1;
			}
		}
		buckits[Count] = buckits[Count] + 1;
		Count = 0;
	}
	return buckits;
}

void distribution(int LevelsNum, int* buckits, int BallNum) {
	for (int i = 0; i < LevelsNum + 1; i++) {
		cout << buckits[i] << " ";
		for (float j = 0; j < (double) buckits[i] / BallNum * 100; j++) {
			cout << "X";
		}
		cout << "\n";
	}
}