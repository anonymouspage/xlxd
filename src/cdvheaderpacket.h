//
//  cdvheaderpacket.h
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

#ifndef cdvheaderpacket_h
#define cdvheaderpacket_h

#include "ccallsign.h"
#include "cpacket.h"

////////////////////////////////////////////////////////////////////////////////////////
// implementation details

//#define IMPLEMENT_CDVHEADERPACKET_CONST_CHAR_OPERATOR

////////////////////////////////////////////////////////////////////////////////////////
// typedef & structures

struct __attribute__ ((__packed__))dstar_header
{
    // flags
    uint8_t	Flag1;
    uint8_t	Flag2;
    uint8_t	Flag3;
    // callsigns
    uint8_t	RPT2[CALLSIGN_LEN];
    uint8_t	RPT1[CALLSIGN_LEN];
    uint8_t	UR[CALLSIGN_LEN];
    uint8_t	MY[CALLSIGN_LEN];
    uint8_t	SUFFIX[CALLSUFFIX_LEN];
    // crc
    uint16_t  Crc;
};


////////////////////////////////////////////////////////////////////////////////////////
// class

class CDvHeaderPacket : public CPacket
{
public:
    // constructor
    CDvHeaderPacket();
    CDvHeaderPacket(const struct dstar_header *, uint16_t, uint8_t);
    CDvHeaderPacket(uint32_t, const CCallsign &, const CCallsign &, const CCallsign &, uint16_t, uint8_t, uint8_t);
    CDvHeaderPacket(const CCallsign &, const CCallsign &, const CCallsign &, const CCallsign &, uint16_t, uint8_t);
    CDvHeaderPacket(const CDvHeaderPacket &);
    
    // destructor
    virtual ~CDvHeaderPacket(){};

    // virtual duplication
    CPacket *Duplicate(void) const;

    // identity
    bool IsDvHeader(void) const                     { return true; }

    // conversion
    void ConvertToDstarStruct(struct dstar_header *) const;

    // get valid
    bool IsValid(void) const;
    
    // get callsigns
    const CCallsign &GetUrCallsign(void) const      { return m_csUR; }
    const CCallsign &GetRpt1Callsign(void) const    { return m_csRPT1; }
    const CCallsign &GetRpt2Callsign(void) const    { return m_csRPT2; }
    const CCallsign &GetMyCallsign(void) const      { return m_csMY; }
    
    // get modules
    char GetUrModule(void) const                    { return m_csUR.GetModule(); }
    char GetRpt1Module(void) const                  { return m_csRPT1.GetModule(); }
    char GetRpt2Module(void) const                  { return m_csRPT2.GetModule(); }
    char GetMyModule(void) const                    { return m_csMY.GetModule(); }
    
    // set callsigns
    void SetRpt2Callsign(const CCallsign &cs)       { m_csRPT2 = cs; }
    void SetRpt2Module(char c)                      { m_csRPT2.SetModule(c); }
    
    // operators
    bool operator ==(const CDvHeaderPacket &) const;
#ifdef IMPLEMENT_CDVHEADERPACKET_CONST_CHAR_OPERATOR
    operator const char *() const;
#endif

protected:
    // data
    uint8_t       m_uiFlag1;
    uint8_t       m_uiFlag2;
    uint8_t       m_uiFlag3;
    CCallsign   m_csUR;
    CCallsign   m_csRPT1;
    CCallsign   m_csRPT2;
    CCallsign   m_csMY;
    uint16_t      m_uiCrc;
#ifdef IMPLEMENT_CDVHEADERPACKET_CONST_CHAR_OPERATOR
    // buffer
    char		m_sz[256];
#endif
};

////////////////////////////////////////////////////////////////////////////////////////
#endif /* cdvheaderpacket_h */
