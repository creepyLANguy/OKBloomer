#pragma once
#include "Settings.h"

inline void InitialiseDeviceContextStuffs(const int bitmap_width, const int bitmap_height)
{
  SetProcessDPIAware();

  hwindowDC = GetDC(hwnd);

  hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

  SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

  //Create a bitmap
  hbwindow = CreateCompatibleBitmap(hwindowDC, bitmap_width, bitmap_height);
  bi.biSize = sizeof(BITMAPINFOHEADER);
  bi.biWidth = bitmap_width;
  bi.biHeight = -bitmap_height;  //makes it draw upside down or not
  bi.biPlanes = 1;
  bi.biBitCount = 32;
  bi.biCompression = BI_RGB;
  bi.biSizeImage = 0;
  bi.biXPelsPerMeter = 0;
  bi.biYPelsPerMeter = 0;
  bi.biClrUsed = 0;
  bi.biClrImportant = 0;
}


inline void Setup()
{
  SetConsoleTitleA(kApplicationName);

  RECT rect;
  GetClientRect(hwnd, &rect);
  bitmap_width = (rect.right - rect.left) / downscaler;
  bitmap_height = (rect.bottom - rect.top) / downscaler;

  InitialiseDeviceContextStuffs(bitmap_width, bitmap_height);

  srcMat = Mat(bitmap_height, bitmap_width, imageType);

  simpleRect = {
    rect.left,
    rect.top,
    rect.right - rect.left,
    rect.bottom - rect.top
  };

  namedWindow(kVisualiserWindowName, WINDOW_NORMAL);

  if (preventVisualiserWindowInScreenshot)
  {
    const HWND handle_visualiser = FindWindowA("Main HighGUI class", kVisualiserWindowName);
    SetWindowDisplayAffinity(handle_visualiser, WDA_MONITOR);
  }
}


inline void CleanUpDeviceContextStuffs()
{
  DeleteObject(hbwindow);
  DeleteDC(hwindowCompatibleDC);
  ReleaseDC(hwnd, hwindowDC);
}
