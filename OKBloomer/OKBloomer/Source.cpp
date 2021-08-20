#include "Globals.h"
#include "Setup.hpp"
#include "Framerate.hpp"
#include "Utils.hpp"
#include "AllFilters.h"

int main(const int argc, char** argv)
{
  Setup();

  while(keepRunning)
  {
    GrabScreen(srcMat, simpleRect, bitmap_width, bitmap_height);

    //ApplyBloom_Altamish(srcMat);
    ApplyBloom_Activision(srcMat);    

    UpdateDebugTimer();

    ShowMat(srcMat, kVisualiserWindowName);
  }

  CleanUpDeviceContextStuffs();
  return 0;
}
