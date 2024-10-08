#include <iostream>
#include "Vector.cpp"
using namespace std;

int main(){
    float* testA = new float(5);
    for(int i = 0; i < 5; i++){
        testA[i] = i;
    }
    MVector* test = new MVector(5);
    MVector* test2 = new MVector(5,testA);
    test->Display();
    test2->Display();
    MVector* test3 = test->Add(test2);
    test3->Display();

    test->~MVector();
    test=nullptr;
    test2->~MVector();
    test2=nullptr;
    test3->~MVector();
    test3=nullptr;
    return 0;
}