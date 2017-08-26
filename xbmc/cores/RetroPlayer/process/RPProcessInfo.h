/*
 *      Copyright (C) 2017 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "cores/IPlayer.h"
#include "threads/CriticalSection.h"

#include "libavutil/pixfmt.h"

#include <string>

class CDataCacheCore;

namespace KODI
{
namespace RETRO
{
  class CRPProcessInfo
  {
  public:
    static CRPProcessInfo* CreateInstance();

    virtual ~CRPProcessInfo() = default;

    void SetDataCache(CDataCacheCore *cache);
    void ResetInfo();

    // player video
    void SetVideoPixelFormat(AVPixelFormat pixFormat);
    void SetVideoDimensions(int width, int height);
    void SetVideoFps(float fps);

    // player audio info
    void SetAudioChannels(const std::string &channels);
    void SetAudioSampleRate(int sampleRate);
    void SetAudioBitsPerSample(int bitsPerSample);

    // player states
    void SetSpeed(float speed);
    void SetPlayTimes(time_t start, int64_t current, int64_t min, int64_t max);

  protected:
    CRPProcessInfo() = default;

    CDataCacheCore *m_dataCache = nullptr;
  };

}
}
