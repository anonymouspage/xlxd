//
//  cambepacket.h
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

#ifndef cambepacket_h
#define cambepacket_h

#include "cpacket.h"

////////////////////////////////////////////////////////////////////////////////////////
// define


// frame sizes
#define AMBE_SIZE           9

////////////////////////////////////////////////////////////////////////////////////////
// class

class CAmbePacket : public CPacket
{
public:
    // constructors
    CAmbePacket();
    CAmbePacket(uint8_t, uint8_t, const uint8_t *);
    CAmbePacket(const CAmbePacket &);
    
    // destructor
    virtual ~CAmbePacket();
    
    // identity
    bool IsAmbe(void) const         { return true; }
    
    // get
    uint8_t  GetCodec(void) const     { return m_uiCodec; }
    uint8_t *GetAmbe(void)            { return m_uiAmbe; }
    int   GetAmbeSize(void) const   { return AMBE_SIZE; }
    
    // set
    void   SetCodec(uint8_t c)        { m_uiCodec = c; }
    void   SetAmbe(const uint8_t *);
    
protected:
    // data
    uint8_t   m_uiCodec;
    uint8_t   m_uiAmbe[AMBE_SIZE];
};

////////////////////////////////////////////////////////////////////////////////////////
#endif /* cambepacket_h */
