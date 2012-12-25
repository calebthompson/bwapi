#include <BWAPI.h>
#include "../../svnrev.h"

#include "../../Debug.h"

int BWAPI::BWAPI_getRevision()
{
  return SVN_REV;
}
bool BWAPI::BWAPI_isDebug()
{
  return BUILD_DEBUG == 1;
}

extern "C" __declspec(dllexport) void gameInit(BWAPI::Game* game)
{
  BWAPI::BroodwarPtr = game;
}

