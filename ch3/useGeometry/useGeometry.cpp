
#include <iostream>
#include "cmath"
using namespace std;
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
using namespace Eigen;

int main()
{
    // 3D旋转矩阵
    Matrix3d rotation_matrix = Matrix3d :: Identity();
    // 旋转向量
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));

    cout.precision(3);
    cout << "rotation matrix=\n" << rotation_vector.matrix() << endl;

    rotation_matrix = rotation_vector.toRotationMatrix();
    cout << "rotation matrix=\n" << rotation_matrix << endl;
    cout << "rotation matrix.transponse=\n" << rotation_matrix.transpose() << endl;

    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation by angle axis = "  << v_rotated.transpose() << endl;

    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0);
    cout << "yaw, pitch, roll = " << euler_angles.transpose()<< endl;


    Isometry3d T = Isometry3d :: Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Vector3d(1, 3, 4));
    cout << "Transform matrix = \n" << T.matrix() << endl;

    Vector3d v_transformed = T * v;
    cout << "v transformed = " << v_transformed.transpose() << endl;

    Quaterniond q = Quaterniond (rotation_vector);
    cout << "quaternion from rotation vector = " << q.coeffs().transpose()
         << endl;   // 请注意coeffs的顺序是(x,y,z,w),w为实部，前三者为虚部

    // 也可以把旋转矩阵赋给它
    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl;

    v_rotated = q * v;
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;

    cout << "should be equal to "  << (q * Quaterniond(0,1,0,0)*q.inverse()).coeffs().transpose() << endl;
    return 0;
}