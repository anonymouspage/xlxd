//
//  cdvlastframepacket.cpp
//  xlxd
//
//  Created by Jean-Luc Deltombe (LX3JL) on 03/11/2015.
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

#include "main.h"
#include "cdvlastframepacket.h"


////////////////////////////////////////////////////////////////////////////////////////
// constructor

CDvLastFramePacket::CDvLastFramePacket()
{
}

// dstar constructor

CDvLastFramePacket::CDvLastFramePacket(const struct dstar_dvframe *DvFrame, uint16_t sid, uint8_t pid)
    : CDvFramePacket(DvFrame, sid, pid)
{
}

// dmr constructor

CDvLastFramePacket::CDvLastFramePacket(const uint8_t *ambe, const uint8_t *sync, uint16_t sid, uint8_t pid, uint8_t spid)
    : CDvFramePacket(ambe, sync, sid, pid, spid)
{
}

// dstar + dmr constructor

CDvLastFramePacket::CDvLastFramePacket
    (uint16_t sid,
     uint8_t dstarpid, const uint8_t *dstarambe, const uint8_t *dstardvdata,
     uint8_t dmrpid, uint8_t dprspid, const uint8_t *dmrambe, const uint8_t *dmrsync)
    : CDvFramePacket(sid, dstarpid, dstarambe, dstardvdata, dmrpid, dprspid, dmrambe, dmrsync)
{
}

// ysf constructor

CDvLastFramePacket::CDvLastFramePacket(const uint8_t *ambe, uint16_t sid, uint8_t pid, uint8_t spid, uint8_t fid)
    : CDvFramePacket(ambe, sid, pid, spid, fid)
{
}

// imrs constructor

CDvLastFramePacket::CDvLastFramePacket(const uint8_t *ambe, uint16_t sid, uint8_t pid, uint8_t spid, uint16_t fid)
    : CDvFramePacket(ambe, sid, pid, spid, fid)
{
}



// copy constructor
    
CDvLastFramePacket::CDvLastFramePacket(const CDvLastFramePacket &DvFrame)
    : CDvFramePacket(DvFrame)
{
}

////////////////////////////////////////////////////////////////////////////////////////
// virtual duplication

CPacket *CDvLastFramePacket::Duplicate(void) const
{
    return new CDvLastFramePacket(*this);
}

