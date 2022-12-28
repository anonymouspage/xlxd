//
//  cdvframepacket.h
//  xlxd
//
//  Created by Jean-Luc Deltombe (LX3JL) on 01/11/2015.
//  Copyright © 2015 Jean-Luc Deltombe (LX3JL). All rights reserved.
//
// ----------------------------------------------------------------------------
//    This file is part of xlxd.
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

#ifndef cdvframepacket_h
#define cdvframepacket_h

#include "cpacket.h"

////////////////////////////////////////////////////////////////////////////////////////
// defines

#define AMBE_SIZE       9
#define DVDATA_SIZE     3

#define AMBEPLUS_SIZE   9
#define DVSYNC_SIZE     7

// typedef & structures

struct __attribute__ ((__packed__))dstar_dvframe
{
    uint8_t	AMBE[AMBE_SIZE];
    uint8_t	DVDATA[DVDATA_SIZE];
};

////////////////////////////////////////////////////////////////////////////////////////
// class

class CDvFramePacket : public CPacket
{
friend class CCodecStream;
public:
    // constructor
    CDvFramePacket();
    CDvFramePacket(const struct dstar_dvframe *, uint16_t, uint8_t);
    CDvFramePacket(const uint8_t *, const uint8_t *, uint16_t, uint8_t, uint8_t);
    CDvFramePacket(const uint8_t *, uint16_t, uint8_t, uint8_t, uint8_t);
    CDvFramePacket(const uint8_t *, uint16_t, uint8_t, uint8_t, uint16_t);
    CDvFramePacket(uint16_t, uint8_t, const uint8_t *, const uint8_t *, uint8_t, uint8_t, const uint8_t *, const uint8_t *);
    CDvFramePacket(const CDvFramePacket &);
    
    // destructor
    virtual ~CDvFramePacket() {};
    
    // virtual duplication
    CPacket *Duplicate(void) const;
    
    // identity
    bool IsDvFrame(void) const              { return true; }
    bool HaveTranscodableAmbe(void) const   { return true; }
    
    // get
    const uint8_t *GetAmbe(uint8_t) const;
    const uint8_t *GetAmbe(void) const        { return m_uiAmbe; }
    const uint8_t *GetAmbePlus(void) const    { return m_uiAmbePlus; }
    const uint8_t *GetDvData(void) const      { return m_uiDvData; }
    const uint8_t *GetDvSync(void) const      { return m_uiDvSync; }
    
    // set
    void SetDvData(uint8_t *);
    void SetAmbe(uint8_t, uint8_t *);

    // operators
    bool operator ==(const CDvFramePacket &) const;

protected:
    // get
    uint8_t *GetAmbeData(void)                { return m_uiAmbe; }
    uint8_t *GetAmbePlusData(void)            { return m_uiAmbePlus; }
    
protected:
    // data (dstar)
    uint8_t       m_uiAmbe[AMBE_SIZE];
    uint8_t       m_uiDvData[DVDATA_SIZE];
    // data (dmr)
    uint8_t       m_uiAmbePlus[AMBEPLUS_SIZE];
    uint8_t       m_uiDvSync[DVSYNC_SIZE];
};


////////////////////////////////////////////////////////////////////////////////////////
#endif /* cdvframepacket_h */
