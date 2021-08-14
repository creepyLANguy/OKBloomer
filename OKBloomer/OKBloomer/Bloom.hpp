#pragma once

inline void ApplyBloom(Mat& src, Mat& dst)
{
  //AL.
  cvtColor(src, dst, COLOR_BGR2GRAY);
}
