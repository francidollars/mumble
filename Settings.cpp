/* Copyright (C) 2005, Thorvald Natvig <thorvald@natvig.com>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <QSettings>
#include "Settings.h"
#include "Global.h"

Settings::Settings() {
	atTransmit = VAD;
	ptTransmit = PositionVelocity;
	a3dModel = Full;
	bMute = bDeaf = false;
	bTTS = true;
	iQuality = 8;
	iComplexity = 4;
	iMinLoudness = 4000;
	iVoiceHold = 30;
	iJitterBufferSize = 4;
	iDXOutputDelay = 4;
	fDXMinDistance = 5.0;
	fDXMaxDistance = 35.0;
	fDXDoppler = 2.0;
	fDXRollOff = 0.5;
}

void Settings::load() {
	QSettings qs;
	bMute = qs.value("AudioMute", false). toBool();
	bDeaf = qs.value("AudioDeaf", false). toBool();
	bTTS = qs.value("TextToSpeech", bTTS). toBool();
	atTransmit = static_cast<Settings::AudioTransmit>(qs.value("AudioTransmit", Settings::VAD).toInt());
	ptTransmit = static_cast<Settings::PosTransmit>(qs.value("PosTransmit", Settings::PositionVelocity).toInt());
	a3dModel = static_cast<Settings::Audio3D>(qs.value("Audio3D", Settings::Full).toInt());
	iQuality = qs.value("AudioQuality", iQuality).toInt();
	iComplexity = qs.value("AudioComplexity", iComplexity).toInt();
	iMinLoudness = qs.value("AudioMinLoudness", iMinLoudness).toInt();
	iVoiceHold = qs.value("AudioVoiceHold", iVoiceHold).toInt();
	iJitterBufferSize = qs.value("JitterBufferSize", iJitterBufferSize).toInt();
	iDXOutputDelay = qs.value("DXOutputDelay", iDXOutputDelay).toInt();
	qbaDXInput = qs.value("DXInput").toByteArray();
	qbaDXOutput = qs.value("DXOutput").toByteArray();
	fDXMinDistance = qs.value("DXMinDistance", fDXMinDistance).toDouble();
	fDXMaxDistance = qs.value("DXMaxDistance", fDXMaxDistance).toDouble();
	fDXDoppler = qs.value("DXDoppler", fDXDoppler).toDouble();
	fDXRollOff = qs.value("DXRollOff", fDXRollOff).toDouble();
}

void Settings::save() {
	QSettings qs;
	qs.setValue("AudioMute", g.s.bMute);
	qs.setValue("AudioDeaf", g.s.bDeaf);
	qs.setValue("TextToSpeech", g.s.bTTS);
	qs.setValue("PosTransmit", g.s.ptTransmit);
	qs.setValue("AudioTransmit", g.s.atTransmit);
	qs.setValue("AudioQuality", iQuality);
	qs.setValue("AudioComplexity", iComplexity);
	qs.setValue("AudioMinLoudness", iMinLoudness);
	qs.setValue("AudioVoiceHold", iVoiceHold);
	qs.setValue("JitterBufferSize", iJitterBufferSize);
	qs.setValue("DXOutputDelay", iDXOutputDelay);
	qs.setValue("DXInput", qbaDXInput);
	qs.setValue("DXOutput", qbaDXOutput);
	qs.setValue("DXMinDistance", fDXMinDistance);
	qs.setValue("DXMaxDistance", fDXMaxDistance);
	qs.setValue("DXDoppler", fDXDoppler);
	qs.setValue("DXRollOff", fDXRollOff);
}
