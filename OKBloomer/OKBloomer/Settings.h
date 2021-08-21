#pragma once

inline bool fps_cmd = false;
inline bool fps_ide = true;

inline const char* kApplicationName = "OKBloomer";
inline const char* kVisualiserWindowName = "OKBloomer - Debug Visualiser";

const auto imageType = CV_8UC4;

inline const int luminanceThresh = 220; //0,255

inline const int kernelDim = 160; //45;

inline const bool preventVisualiserWindowInScreenshot = true;
//inline const bool preventVisualiserWindowInScreenshot = false;

inline const int downscaler = 2;



//Activision
inline const int downsamples = 13;


