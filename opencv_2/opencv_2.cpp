// opencv_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>


using namespace cv;
using namespace std;

int main() {
    Mat src = imread("image2.jpg");
    Mat gray, edges, color_dst;
    if (src.empty()) {
        cout << "Error" << endl;
        return -1;
    }
    imshow("Original", src);

    cvtColor(src, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);
    Canny(gray, edges, 50, 200, 3);
    cvtColor(edges, color_dst, COLOR_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(edges, lines, 1, CV_PI / 180, 50, 30, 10);
    for (size_t i = 0; i < lines.size(); i++) {
        line(color_dst, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, LINE_AA);
    }

    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 2, gray.rows / 4, 300, 150);
    for (size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        circle(color_dst, center, radius, Scalar(255, 0, 0), 3, LINE_AA);
    }
    imshow("Lines and Circles", color_dst);
    waitKey(0);

    Mat img = imread("image.jpg");                                //Вторая часть
    Mat hsv, lab, yuv, xyz;

    if (img.empty()) {
        std::cout << "Íĺ óäŕëîńü çŕăđóçčňü čçîáđŕćĺíčĺ " << std::endl;
        return -1;
    }

    imshow("Original", img);

    cvtColor(img, hsv, COLOR_BGR2HSV);
    imshow("HSV", hsv);

    cvtColor(img, lab, COLOR_BGR2Lab);
    imshow("Lab", lab);

    cvtColor(img, yuv, COLOR_BGR2YUV);
    imshow("YUV", yuv);

    cvtColor(img, xyz, COLOR_BGR2XYZ);
    imshow("XYZ", xyz);
    waitKey(0);

    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
