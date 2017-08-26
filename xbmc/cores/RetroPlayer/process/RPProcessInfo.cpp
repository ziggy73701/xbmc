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

#include "RPProcessInfo.h"
#include "cores/DataCacheCore.h"

extern "C" {
#include "libavutil/pixdesc.h"
}

using namespace KODI;
using namespace RETRO;

CRPProcessInfo* CRPProcessInfo::CreateInstance()
{
  return new CRPProcessInfo();
}

void CRPProcessInfo::SetDataCache(CDataCacheCore *cache)
{
  m_dataCache = cache;;
}

void CRPProcessInfo::ResetInfo()
{
  if (m_dataCache != nullptr)
  {
    m_dataCache->SetVideoDecoderName("", false);
    m_dataCache->SetVideoDeintMethod("");
    m_dataCache->SetVideoPixelFormat("");
    m_dataCache->SetVideoDimensions(0, 0);
    m_dataCache->SetVideoFps(0.0f);
    m_dataCache->SetVideoDAR(1.0f);
    m_dataCache->SetAudioDecoderName("");
    m_dataCache->SetAudioChannels("");
    m_dataCache->SetAudioSampleRate(0);
    m_dataCache->SetAudioBitsPerSample(0);
    m_dataCache->SetRenderClockSync(false);
    m_dataCache->SetStateSeeking(false);
    m_dataCache->SetSpeed(1.0f, 1.0f);
    m_dataCache->SetGuiRender(true); //! @todo
    m_dataCache->SetVideoRender(true); //! @todo
    m_dataCache->SetPlayTimes(0, 0, 0, 0);
  }
}

//******************************************************************************
// video codec
//******************************************************************************
void CRPProcessInfo::SetVideoPixelFormat(AVPixelFormat pixFormat)
{
  const char *videoPixelFormat = av_get_pix_fmt_name(pixFormat);

  if (m_dataCache != nullptr)
    m_dataCache->SetVideoPixelFormat(videoPixelFormat != nullptr ? videoPixelFormat : "");
}

void CRPProcessInfo::SetVideoDimensions(int width, int height)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetVideoDimensions(width, height);
}

void CRPProcessInfo::SetVideoFps(float fps)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetVideoFps(fps);
}

//******************************************************************************
// player audio info
//******************************************************************************
void CRPProcessInfo::SetAudioChannels(const std::string &channels)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetAudioChannels(channels);
}

void CRPProcessInfo::SetAudioSampleRate(int sampleRate)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetAudioSampleRate(sampleRate);
}

void CRPProcessInfo::SetAudioBitsPerSample(int bitsPerSample)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetAudioBitsPerSample(bitsPerSample);
}

//******************************************************************************
// player states
//******************************************************************************
void CRPProcessInfo::SetSpeed(float speed)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetSpeed(1.0f, speed);
}

void CRPProcessInfo::SetPlayTimes(time_t start, int64_t current, int64_t min, int64_t max)
{
  if (m_dataCache != nullptr)
    m_dataCache->SetPlayTimes(start, current, min, max);
}
