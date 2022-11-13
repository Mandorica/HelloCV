#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int ac, char** av) {

    Mat img_1 = imread("images/sample_image.jpg", 0);    //이미지를 grayscale로 불러옴

    Mat img_2 = img_1 * 2;
    Mat img_3 = img_1 / 2;
    Mat img_hist;

    img = cv2.imread('./img/sunset.jpg')

        x = 320; y = 150; w = 50; h = 50        # roi 좌표
        roi = img[y:y + h, x : x + w]         # roi 지정-- - ①

        print(roi.shape)                # roi shape, (50, 50, 3)
        cv2.rectangle(roi, (0, 0), (h - 1, w - 1), (0, 255, 0)) # roi 전체에 사각형 그리기-- - ②
        cv2.imshow("img", img)

    MatND histogram;

    const int* channel_numbers = { 0 };
    float channel_range[] = { 0.0, 255.0 };
    const float* channel_ranges = channel_range;
    int number_bins = 255;

    calcHist(&img_1, 1, channel_numbers, Mat(), histogram, 1, &number_bins, &channel_ranges);

    // plot the histogram
    int hist_w = img_1.cols;
    int hist_h = img_1.rows;
    int bin_w = cvRound((double)hist_w / number_bins);

    Mat hist_img(hist_h, hist_w, CV_8UC1, Scalar::all(0));
    normalize(histogram, histogram, 0, hist_img.rows, NORM_MINMAX, -1, Mat());

    for (int i = 1; i < number_bins; i++)
    {
        line(hist_img, Point(bin_w * (i - 1), hist_h - cvRound(histogram.at<float>(i - 1))), Point(bin_w * (i), hist_h - cvRound(histogram.at<float>(i))), Scalar(255, 0, 0), 1, 8, 0);
    }

    imshow("Origianl", img_1);
    imshow("Histogram", hist_img);
    cout << "밝기평균 : " << (int)mean(img_1)[0] << endl; // 밝기 측정 코드


    //imshow("original", img_1);
    //imshow("img_mul", img_2);
    //imshow("img_div", img_3);

    waitKey(0);


    return 0;
}