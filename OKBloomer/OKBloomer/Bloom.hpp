#pragma once
#include "RGBOperations.hpp"

inline void ApplyBloom(Mat& mat)
{
  Mat scratch = mat.clone();

  FilterByLuminanceThresh(scratch);

  Blur(scratch);

  AddImages(mat, scratch);
}

