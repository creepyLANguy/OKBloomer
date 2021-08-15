#pragma once

struct Lumi
{
  float r = 0.33f;
  float g = 0.50f;
  float b = 0.17f;
};
Lumi lumi;

inline void FilterByLuminanceThresh(Mat& mat)
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

      if (lumiTotal < luminanceThresh)
      {
        pixelPtr[y * mat.cols * cn + x * cn + 2] = 0;
        pixelPtr[y * mat.cols * cn + x * cn + 1] = 0;
        pixelPtr[y * mat.cols * cn + x * cn + 0] = 0;
      }
    }
  }
}

inline void Blur(Mat& mat) {

  const Size kernelSize = Size(kernelDim*2, kernelDim*2);

  //blur(mat, mat, kernelSize);
  boxFilter(mat, mat, -1, kernelSize);
}

inline void AddImages(Mat& base, Mat& layer)
{
  auto* basePtr = static_cast<uint8_t*>(base.data);
  const int cn = base.channels();

  auto* layerPtr = static_cast<uint8_t*>(layer.data);

  for (int x = 0; x < base.cols; ++x)
  {
    for (int y = 0; y < base.rows; ++y)
    {
      const int r = basePtr[y * base.cols * cn + x * cn + 2] + layerPtr[y * base.cols * cn + x * cn + 2];
      const int g = basePtr[y * base.cols * cn + x * cn + 1] + layerPtr[y * base.cols * cn + x * cn + 1];
      const int b = basePtr[y * base.cols * cn + x * cn + 0] + layerPtr[y * base.cols * cn + x * cn + 0];

      basePtr[y * base.cols * cn + x * cn + 2] = r > 255 ? 255 : r;
      basePtr[y * base.cols * cn + x * cn + 1] = g > 255 ? 255 : g;
      basePtr[y * base.cols * cn + x * cn + 0] = b > 255 ? 255 : b;
    }
  }
}