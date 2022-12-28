//
//  cvoicepacket.h
//  ambed
//
//  Created by Jean-Luc Deltombe (LX3JL) on 28/04/2017.
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

#ifndef cvoicepacket_h
#define cvoicepacket_h


#include "cpacket.h"

////////////////////////////////////////////////////////////////////////////////////////
// define

// frame sizes
#define VOICE_SIZEMAX           512

////////////////////////////////////////////////////////////////////////////////////////
// class

class CVoicePacket : public CPacket
{
public:
    // constructors
    CVoicePacket();
    CVoicePacket(const uint8_t *, int);
    CVoicePacket(const CVoicePacket &);
    
    // destructor
    virtual ~CVoicePacket();

    // identity
    bool IsVoice(void) const         { return true; }

    // get
    uint8_t *GetVoice(void)            { return m_uiVoice; }
    int   GetVoiceSize(void) const   { return m_iSize; }
    
    // set
    void   SetVoice(const uint8_t *, int);
    
protected:
    // data
    int     m_iSize;
    uint8_t   m_uiVoice[VOICE_SIZEMAX];
};

////////////////////////////////////////////////////////////////////////////////////////
#endif /* cvoicepacket_h */
