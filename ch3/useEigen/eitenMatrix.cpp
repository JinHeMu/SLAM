#include <iostream>

using namespace std;


#include <ctime>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using namespace Eigen;

#define MATRIX_SIZE 50

int main(int argc, char **argv){
    // 声明一个2*3的矩阵
    Matrix<float, 2, 3> matrix_23;

    Vector3d v_3d;
    // 这是一样的
    Matrix<float, 3, 1>vd_3d;
    Matrix3d matrix_33 = Matrix3d::Zero(); // 初始化为零
    Matrix<double, Dynamic, Dynamic> matrix_dynamic;// 动态大小Matrix
    //更简单的Matrix
    MatrixXd matrix_x;

    // 输入数据
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "matrix 2*3 from 1 to 6:\n" << matrix_23 << endl;
    cout << "print matrix 2*3: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix_23(i,j) << "\t";
            cout << endl;
        }
    }

    //矩阵和向量
    v_3d << 3, 2, 1;
    vd_3d << 4, 5, 6;

    //类型要匹配
    Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << "[1,2,3;4,5,6]*[3,2,1]=" << result.transpose() << endl;

    Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
    cout << "[1,2,3;4,5,6]*[4,5,6]: " << result2.transpose() << endl;

    // 一些矩阵运算
    // 四则运算就不演示了，直接用+-*/即可。
    matrix_33 = Matrix3d :: Random();
    cout << "random matrix: \n" << matrix_33 << endl;
    cout << "transpose: \n" << matrix_33.transpose() << endl;      // 转置
    cout << "sum: " << matrix_33.sum() << endl;            // 各元素和
    cout << "trace: " << matrix_33.trace() << endl;          // 迹
    cout << "times 10: \n" << 10 * matrix_33 << endl;               // 数乘
    cout << "inverse: \n" << matrix_33.inverse() << endl;        // 逆
    cout << "det: " << matrix_33.determinant() << endl;    // 行列式

    Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN
        = MatrixXd :: Random(MATRIX_SIZE, MATRIX_SIZE);
    matrix_NN = matrix_NN * matrix_NN.transpose();
    Matrix<double, MATRIX_SIZE, 1> v_Nd = MatrixXd :: Random(MATRIX_SIZE, 1);

    clock_t time_stt = clock();
    // 直接求
    Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
    cout << "time of normal inverse is "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;

    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time of Qr decompostion is "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;

    // 对于正定矩阵，还可以用cholesky分解来解方程
    time_stt = clock();
    x = matrix_NN.ldlt().solve(v_Nd);
    cout << "time of ldlt decomposition is "
         << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x = " << x.transpose() << endl;


    return 0;
}