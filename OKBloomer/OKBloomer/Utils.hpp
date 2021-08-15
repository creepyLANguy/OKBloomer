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


inline void ShowMat(Mat& mat)
{
  imshow(kVisualiserWindowName, mat);
  waitKeyEx(1);

  keepRunning = getWindowProperty(kVisualiserWindowName, WND_PROP_VISIBLE) != 0;
}