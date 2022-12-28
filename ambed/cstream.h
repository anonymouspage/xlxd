//
//  cstream.h
//  ambed
//
//  Created by Jean-Luc Deltombe (LX3JL) on 15/04/2017.
//  Copyright © 2015 Jean-Luc Deltombe (LX3JL). All rights reserved.
//
// ----------------------------------------------------------------------------
//    This file is part of ambed.
//
//    xlxd is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    xlxd is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#ifndef cstream_h
#define cstream_h

#include "cudpsocket.h"
#include "ccallsign.h"
#include "cvocodecchannel.h"

////////////////////////////////////////////////////////////////////////////////////////
// class

class CStream
{
public:
    // constructors
    CStream();
    CStream(uint16_t, const CCallsign &, const CIp &, uint8_t, uint8_t);
    
    // destructor
    virtual ~CStream();
    
    // initialization
    bool Init(uint16_t);
    void Close(void);
    
    // get
    uint16_t  GetId(void) const           { return m_uiId; }
    uint16_t  GetPort(void) const         { return m_uiPort; }
    uint8_t   GetCodecIn(void) const      { return m_uiCodecIn; }
    uint8_t   GetCodecOut(void) const     { return m_uiCodecOut; }
    
    // activity timer
    bool    IsActive(void) const        { return m_LastActivity.DurationSinceNow() <= STREAM_ACTIVITY_TIMEOUT; }

    // task
    static void Thread(CStream *);
    void Task(void);

protected:
    // packet decoding helpers
    bool IsValidDvFramePacket(const CBuffer &, uint8_t *, uint8_t *);
    
    // packet encodeing helpers
    void EncodeDvFramePacket(CBuffer *, uint8_t, uint8_t *);
    
    
protected:
    // data
    uint16_t          m_uiId;
    CUdpSocket      m_Socket;
    uint16_t          m_uiPort;
    uint8_t           m_uiCodecIn;
    uint8_t           m_uiCodecOut;
    CVocodecChannel *m_VocodecChannel;
    
    // client details
    CCallsign       m_Callsign;
    CIp             m_Ip;
    
    // counters
    int             m_iTotalPackets;
    int             m_iLostPackets;
    
    // activity timer
    CTimePoint      m_LastActivity;
    
    // thread
    bool            m_bStopThread;
    std::thread     *m_pThread;

};

////////////////////////////////////////////////////////////////////////////////////////
#endif /* cstream_h */
