#include <iostream>
#include "vector.h"
#include <cmath>
using namespace std;

MVector::MVector(int size){
    vectors = new float[size];
    this->size = size;
    for(int i = 0; i < size; i++){
        vectors[i] = 0;
    }
}
MVector::MVector(int size, float* input){
    vectors = new float[size];
    this->size = size;
    for(int i = 0; i < size; i++){
        vectors[i] = input[i];
    }
}
MVector::~MVector(){
    delete[] vectors;
    vectors=nullptr;
}
void MVector::Display(){
    for(int i = 0; i < size; i++){
        cout << vectors[i];
    }
    cout << "\n";
}
MVector* MVector::Add(MVector* vec2){
    MVector* NewVec = new MVector(size);
    if(size == vec2->GetSize()){
        for(int i = 0; i < size; i++){
            NewVec->GetVectors()[i] = vectors[i] + vec2->GetVectors()[i];
        }
        return NewVec;
    }else{
        MVector* NewVec = new MVector(0);
        return NewVec;
    }
}
int MVector::GetSize(){
    return size;
}
float* MVector::GetVectors(){
    return vectors;
}
float MVector::Magnitude(){
    float temp = 0;
    for(int i = 0; i < size; i++){
        temp = temp + pow(vectors[i], 2);
    }
    temp = sqrt(temp);
    return temp;
}
MVector* MVector::Normalize(){
    MVector* NewVec = new MVector(size);
    for(int i = 0; i < size; i++){
        NewVec[i] = vectors[i] / Magnitude();
    }
    return NewVec;
}