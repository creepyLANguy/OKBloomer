#pragma once

#include "RGBOperations.hpp"

inline void ApplyBloom_Altamish(Mat& mat)
{
  Mat scratch = mat.clone();

  FilterByLuminanceThresh(scratch);

  Blur(scratch);

  AddImages(mat, scratch);
}
