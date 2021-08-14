#pragma once

using namespace std;

inline auto zeroHour = GetTickCount64();
inline unsigned int frameCount = 0;

inline void PrintFramerate()
{
  const string str = "FPS:" + to_string(frameCount) + "\r\n";
  if (fps_cmd)
  {
    cout << str.c_str() << endl;
  }
  if (fps_ide)
  {
    OutputDebugStringA(str.c_str());
  }
}


inline void UpdateDebugTimer()
{
  ++frameCount;

  const auto now = GetTickCount64();

  if (now - zeroHour >= 1000)
  {
    PrintFramerate();
    frameCount = 0;
    zeroHour = now;
  }
}
