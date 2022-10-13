#include "opencv2/opencv.hpp"
#include <iostream>

// ROI가 될 영역의 점들을 roiPoints 로 선언
vector<vector<int>> roiPoints({
    vector<int>({ 240, 280 }),
    vector<int>({400, 280}),
    vector<int>({620, 440}),
    vector<int>({20, 440})
    });

VideoCapture cap("base_camera_dark.avi");

if (!cap.isOpened()) {
    cerr << "Video open failed!" << endl;
    return -1;
}

Mat frame, gray;
Mat mask(frame.rows, frame.cols, CV_8UC1, Scalar(0));
Mat dst(frame.rows, frame.cols, CV_8UC1, Scalar(0));

while (true) {
    cap >> frame;
    if (frame.empty()) break;

    // grayscale 변환
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    // 원본 영상에 ROI 범위를 line으로 그리기
    line(frame, Point(240, 280), Point(400, 280), Scalar(0, 0, 255), 2);
    line(frame, Point(400, 280), Point(620, 440), Scalar(0, 0, 255), 2);
    line(frame, Point(620, 440), Point(20, 440), Scalar(0, 0, 255), 2);
    line(frame, Point(20, 440), Point(240, 280), Scalar(0, 0, 255), 2);

    // ROI 부분 mask 생성
    fillPoly(mask, roiPoints, 255);

    //평균 밝기 구해 적용하기
    int m = mean(gray, mask)[0];
    dst = gray + (128 - m);

    //영상 보이기
    imshow("frame", frame);
    imshow("gray", gray);
    imshow("dst", dst);

    if (waitKey(10) == 27)
        break;
}

cap.release();
destroyAllWindows();