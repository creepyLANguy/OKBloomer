#pragma once

inline void GrabScreen(Mat& mat, const Rect& rect, const int bitmap_width, const int bitmap_height)
{
  //Use the previously created device context with the bitmap
  SelectObject(hwindowCompatibleDC, hbwindow);
  //Copy from the window device context to the bitmap device context
  StretchBlt(
    hwindowCompatibleDC, 0, 0, bitmap_width, bitmap_height,
    hwindowDC, rect.x, rect.y, rect.width, rect.height, SRCCOPY);
  //copy from hwindowCompatibleDC to hbwindow
  GetDIBits(hwindowCompatibleDC, hbwindow,
    0, bitmap_height, mat.data, reinterpret_cast<BITMAPINFO*>(&bi), DIB_RGB_COLORS);
}


inline void ShowMat(Mat& mat, const char* windowName)
{
  imshow(windowName, mat);
  waitKeyEx(1);

  keepRunning = getWindowProperty(windowName, WND_PROP_VISIBLE) != 0;
}

inline void ShowMats(vector<Mat>& mats)
{
  int i = 0;
  for (auto mat : mats)
  {
    ++i;
    char b[64] = { 0 };
    _itoa_s(i, b, 10);
    ShowMat(mat, b);
  }
}
  