#pragma once

#include "RGBOperations.hpp"

inline void ApplyBloom_Altamish(Mat& mat)
{
  Mat scratch = mat.clone();

  //resize(scratch, scratch, Size(bitmap_width / 6, bitmap_height / 6),0,0,INTER_NEAREST);

  FilterByLuminanceThresh(scratch);

  Blur(scratch);

  //resize(scratch, scratch, Size(bitmap_width, bitmap_height),0,0, INTER_NEAREST);

  AddImages(mat, scratch);
}
