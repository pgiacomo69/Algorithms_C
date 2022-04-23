#include <iostream>
#include "MatrixMultiplier.cpp"
#include "Matrix.h"
#include <memory>

int main() {
    int n=2048;
    std::cout << "Hello, World!" << std::endl;
    auto* a=new Matrix<int>(n, n,"A");;
    a->reset(true);
    auto* b=new Matrix<int>(n, n,"B");
    b->reset(true);
    // Matrix<int>* c=a->Multiply(b,"C");
    Matrix<int> c =*a + *b;
    a->printStats();
    delete a;
    delete b;
    delete c;



    return 0;
}
