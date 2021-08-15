#pragma once

struct Lumi
{
  float r = 0.33f;
  float g = 0.50f;
  float b = 0.17f;
};
Lumi lumi;

inline void FilterByLuminanceThresh(Mat& mat, const int thresh)
{
  auto* pixelPtr = static_cast<uint8_t*>(mat.data);
  const int cn = mat.channels();

  for (int x = 0; x < mat.cols; ++x)
  {
    for (int y = 0; y < mat.rows; ++y)
    {
      const int lumiTotal =
        lumi.r * pixelPtr[y * mat.cols * cn + x * cn + 2] +
        lumi.g * pixelPtr[y * mat.cols * cn + x * cn + 1] +
        lumi.b * pixelPtr[y * mat.cols * cn + x * cn + 0];

      if (lumiTotal < thresh)
      {
        pixelPtr[y * mat.cols * cn + x * cn + 2] = 0;
        pixelPtr[y * mat.cols * cn + x * cn + 1] = 0;
        pixelPtr[y * mat.cols * cn + x * cn + 0] = 0;
      }
    }
  }
}
