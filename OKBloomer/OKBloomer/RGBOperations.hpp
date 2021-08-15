#pragma once

const float luminanceModifiers[3] = { 0.17f,  0.50f, 0.33f };

inline void FilterByLuminanceThresh(Mat& mat)
{
  auto* pixelPtr = static_cast<uint8_t*>(mat.data);
  const int cn = mat.channels();

  for (int x = 0; x < mat.cols; ++x)
  {
    for (int y = 0; y < mat.rows; ++y)
    {
      float lumiTotal = 0;
      for (int i = 0; i < 3; ++i)
      {
        lumiTotal += luminanceModifiers[i] * pixelPtr[y * mat.cols * cn + x * cn + i];
      }

      if (lumiTotal < luminanceThresh)
      {
        for (int i = 0; i < 3; ++i)
        {
          pixelPtr[y * mat.cols * cn + x * cn + i] = 0;
        }
      }
    }
  }
}


inline void Blur(Mat& mat) {

  const Size kernelSize = Size(kernelDim, kernelDim);

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
      for (int i = 0; i < 3; ++i)
      {
        const int val = basePtr[y * base.cols * cn + x * cn + i] + layerPtr[y * base.cols * cn + x * cn + i];
        basePtr[y * base.cols * cn + x * cn + i] = val > 255 ? 255 : val;
      }
    }
  }
}