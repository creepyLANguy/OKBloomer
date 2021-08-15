#pragma once

#include <opencv2/opencv.hpp>
#include <Windows.h>

#define WIN32_LEAN_AND_MEAN

using namespace std;
using namespace cv;

inline Mat srcMat;

inline int bitmap_width;
inline int bitmap_height;
inline Rect simpleRect;

inline bool keepRunning = true;

inline vector <MONITORINFOEX> displays;
inline HWND hwnd = GetDesktopWindow();
inline HDC hwindowDC = nullptr;
inline HDC hwindowCompatibleDC = nullptr;
inline HBITMAP hbwindow = nullptr;
inline BITMAPINFOHEADER bi;
