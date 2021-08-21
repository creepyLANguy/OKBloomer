#pragma once

inline void ApplyBloom_Activision(Mat& mat)
{
  auto scratch = mat.clone();

  FilterByLuminanceThresh(scratch);

  const int inc_w = bitmap_width / (downsamples + 1);
  const int inc_h = bitmap_height / (downsamples + 1);

  vector<Mat> samples;
  for (int i = 1; i <= downsamples; ++i)
  {
    resize(scratch, scratch, Size(bitmap_width - (inc_w * i), bitmap_height - (inc_h * i)));

    samples.push_back(scratch);
  }

  //ShowMats(samples);

  vector<Mat> upscaled;
  for (auto sample : samples)
  {
    resize(sample, sample, Size(bitmap_width, bitmap_height));
    upscaled.push_back(sample);
  }

  ShowMats(upscaled);

  //AL.
  //TODO
  //Combine the images in some HDR friendly way 
}

