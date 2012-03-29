#include "modeldata.h"

ModelData::ModelData(){
}

ModelData::ModelData(std::vector<double> n_B, std::vector<double> n_A, int n_k, int n_t){
    B = n_B;
    A = n_A;
    k = n_k;
    t = n_t;
}

ModelData::~ModelData(){
}

void ModelData::setB(std::vector<double> n_B){
    B = n_B;
}

std::vector<double> ModelData::getB(){
    return B;
}

void ModelData::setA(std::vector<double> n_A){
    A = n_A;
}

std::vector<double> ModelData::getA(){
    return A;
}

void ModelData::setK(int n_k){
    k = n_k;
}

int ModelData::getK(){
    return k;
}

void ModelData::setT(int n_t){
    t = n_t;
}

int ModelData::getT(){
    return t;
}
