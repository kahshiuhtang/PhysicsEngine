#include "utilities.hpp"

void free_array(int *data){
    delete[] data;
    data = nullptr;
}

void free_array(double *data){
    delete[] data;
    data = nullptr;
}