#include <vector>
using std::vector;



class MatrixMultiplier {
private:
    vector<vector<int>> matrixA;
    vector<vector<int>> matrixB;
public:
    MatrixMultiplier();
    explicit MatrixMultiplier(int n,int m=0,int p=0);

};

MatrixMultiplier::MatrixMultiplier(int n, int m, int p) :MatrixMultiplier() {

}

MatrixMultiplier::MatrixMultiplier() = default;




