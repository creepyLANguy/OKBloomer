#pragma once
#include "RGBOperations.hpp"

inline void ApplyBloom(Mat& mat)
{
  FilterByLuminanceThresh(mat);

  Blur(mat);

  //AL.
  //Apply Gaussian blur to specified setting
  //Add image back to src ( additively?) 

  //cvtColor(src, dst, COLOR_BGR2GRAY);
}

