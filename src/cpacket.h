//
//  cpacket.h
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

#ifndef cpacket_h
#define cpacket_h

////////////////////////////////////////////////////////////////////////////////////////

// Origin Id

#define ORIGIN_LOCAL    0
#define ORIGIN_PEER     1

////////////////////////////////////////////////////////////////////////////////////////
// class

class CPacket
{
public:
    // constructor
    CPacket();
    CPacket(uint16_t sid, uint8_t dstarpid);
    CPacket(uint16_t sid, uint8_t dmrpid, uint8_t dmrsubpid);
    CPacket(uint16_t sid, uint8_t ysfpid, uint8_t ysfsubpid, uint8_t ysffrid);
    CPacket(uint16_t sid, uint8_t imrspid, uint8_t imrssubid, uint16_t imrsfrid);
    CPacket(uint16_t sid, uint8_t dstarpid, uint8_t dmrpid, uint8_t dmrsubpid, uint8_t ysfpid, uint8_t ysfsubpid, uint8_t ysffrid, uint8_t imrspid, uint8_t imrssubid, uint16_t imrsfrid);
    
    // destructor
    virtual ~CPacket() {};
    
    // virtual duplication
    virtual CPacket *Duplicate(void) const;
    
    // identity
    virtual bool IsDvHeader(void) const             { return false; }
    virtual bool IsDvFrame(void) const              { return false; }
    virtual bool IsLastPacket(void) const           { return false; }
    virtual bool HaveTranscodableAmbe(void) const   { return false; }
    
    // get
    virtual bool IsValid(void) const                { return true; }
    uint16_t GetStreamId(void) const                  { return m_uiStreamId; }
    uint8_t  GetPacketId(void) const                  { return m_uiDstarPacketId; }
    uint8_t  GetDstarPacketId(void) const             { return m_uiDstarPacketId; }
    uint8_t  GetDmrPacketId(void) const               { return m_uiDmrPacketId; }
    uint8_t  GetDmrPacketSubid(void) const            { return m_uiDmrPacketSubid; }
    uint8_t  GetYsfPacketId(void) const               { return m_uiYsfPacketId; }
    uint8_t  GetYsfPacketSubId(void) const            { return m_uiYsfPacketSubId; }
    uint8_t  GetYsfPacketFrameId(void) const          { return m_uiYsfPacketFrameId; }
    uint8_t  GetImrsPacketId(void) const              { return m_uiImrsPacketId; }
    uint16_t GetImrsPacketFrameId(void) const         { return m_uiImrsPacketFrameId; }
    uint8_t  GetImrsPacketSubId(void) const           { return m_uiImrsPacketSubId; }
    uint8_t  GetModuleId(void) const                  { return m_uiModuleId; }
    bool   IsLocalOrigin(void) const                { return (m_uiOriginId == ORIGIN_LOCAL); }
    
    // set
    void UpdatePids(uint32_t);
    void SetModuleId(uint8_t uiId)                    { m_uiModuleId = uiId; }
    void SetLocalOrigin(void)                       { m_uiOriginId = ORIGIN_LOCAL; }
    void SetRemotePeerOrigin(void)                  { m_uiOriginId = ORIGIN_PEER; }
    
protected:
    // common
    uint16_t  m_uiStreamId;
    uint8_t   m_uiModuleId;
    uint8_t   m_uiOriginId;
    // dstar
    uint8_t   m_uiDstarPacketId;
    // dmr
    uint8_t   m_uiDmrPacketId;
    uint8_t   m_uiDmrPacketSubid;
    // ysf
    uint8_t   m_uiYsfPacketId;
    uint8_t   m_uiYsfPacketSubId;
    uint8_t   m_uiYsfPacketFrameId;
    // imrs
    uint8_t   m_uiImrsPacketId;
    uint16_t  m_uiImrsPacketFrameId;
    uint8_t   m_uiImrsPacketSubId;
};



////////////////////////////////////////////////////////////////////////////////////////
#endif /* cpacket_h */
