#include "iostream"
#include <chrono>

using namespace std;

#include "opencv4/opencv2/core/core.hpp"
#include <opencv4/opencv2/highgui/highgui.hpp>

int main(int argc, char **argv)
{
    cout << "hello opencv\n" << endl;

    cv::Mat image;
    image = cv::imread(argv[1]);// cv::imread读取图像

    // 判断图像文件是否正确读取
    if (image.data == nullptr)
    {
        cerr << "文件" << argv[1] << "不存在." << endl;
        return 0;
    }

    cout << "photo width is:" << image.cols << "\nheight is:" << image.rows << "\nchannel is:"
    << image.channels() << endl;

    cv::imshow("image", image);
    cv::waitKey(0);

    // 判断image的类型
    if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
        // 图像类型不符合要求
        cout << "请输入一张彩色图或灰度图." << endl;
        return 0;
    }

    // 给算法计时
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

    for(size_t y = 0; y < image.rows; y++)
    {
        auto *row_ptr = image.ptr<unsigned char>(y);

        for (size_t x=0; x < image.cols; x++)
        {
            unsigned char *data_ptr = &row_ptr[x * image.channels()];
            // 输出该像素的每个通道,如果是灰度图就只有一个通道
            for (int c = 0; c!= image.channels(); c++)
            {
                unsigned char data = data_ptr[c];
            }
        }
    }

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "遍历图像用时：" << time_used.count() << "秒。" << endl;

//    cv::Mat image_another = image;
//    image_another(cv::Rect (0,0,100,100)).setTo(0);
//    cv::imshow("image", image);
//    cv::waitKey(0);

    // 使用clone函数来拷贝数据
    cv::Mat image_clone = image.clone();
    image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
    cv::imshow("image", image);
    cv::imshow("image_clone", image_clone);
    cv::waitKey(0);

    // 对于图像还有很多基本的操作,如剪切,旋转,缩放等,限于篇幅就不一一介绍了,请参看OpenCV官方文档查询每个函数的调用方法.
    cv::destroyAllWindows();
    return 0;





}