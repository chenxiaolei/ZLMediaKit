﻿/*
 * MIT License
 *
 * Copyright (c) 2016-2019 xiongziliang <771730766@qq.com>
 *
 * This file is part of ZLMediaKit(https://github.com/xiongziliang/ZLMediaKit).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "Rtmp.h"
#include "Extension/Factory.h"
namespace mediakit{

VideoMete::VideoMete(const VideoTrack::Ptr &video,int datarate ){
    if(video->getVideoWidth() > 0 ){
        _metedata.set("width", video->getVideoWidth());
    }
    if(video->getVideoHeight() > 0 ){
        _metedata.set("height", video->getVideoHeight());
    }
    if(video->getVideoFps() > 0 ){
        _metedata.set("framerate", video->getVideoFps());
    }
    _metedata.set("videodatarate", datarate);
    _codecId = video->getCodecId();
    _metedata.set("videocodecid", Factory::getAmfByCodecId(_codecId));
}

AudioMete::AudioMete(const AudioTrack::Ptr &audio,int datarate){
    _metedata.set("audiodatarate", datarate);
    if(audio->getAudioSampleRate() > 0){
        _metedata.set("audiosamplerate", audio->getAudioSampleRate());
    }
    if(audio->getAudioSampleBit() > 0){
        _metedata.set("audiosamplesize", audio->getAudioSampleBit());
    }
    if(audio->getAudioChannel() > 0){
        _metedata.set("audiochannels", audio->getAudioChannel());
        _metedata.set("stereo", audio->getAudioChannel() > 1);
    }
    _codecId = audio->getCodecId();
    _metedata.set("audiocodecid", Factory::getAmfByCodecId(_codecId));
}

}//namespace mediakit