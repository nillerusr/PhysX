//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2009-2019 NVIDIA Corporation. All rights reserved.


#ifndef PROCESS_RENDER_DEBUG_H
#define PROCESS_RENDER_DEBUG_H

#include "RenderDebugImpl.h"

namespace RENDER_DEBUG
{

#define MAX_LINE_VERTEX 16384
#define MAX_SOLID_VERTEX 16384

PX_PUSH_PACK_DEFAULT


class ProcessRenderDebug
{
public:
	enum DisplayType
	{
		SCREEN_SPACE,
		WORLD_SPACE,
		WORLD_SPACE_NOZ,
		DT_LAST
	};

	virtual void processRenderDebug(const DebugPrimitive **dplist,
									uint32_t pcount,
									RENDER_DEBUG::RenderDebugInterface *iface,
									DisplayType type) = 0;

	virtual void flush(RENDER_DEBUG::RenderDebugInterface *iface,DisplayType type) = 0;

	virtual void flushFrame(RENDER_DEBUG::RenderDebugInterface *iface) = 0;

	virtual void finalizeFrame(void) = 0;

	virtual void release(void) = 0;

	virtual void setViewMatrix(const physx::PxMat44 &view) 
	{
		PX_UNUSED(view);
	}

protected:
	virtual ~ProcessRenderDebug(void) { }

};


ProcessRenderDebug * createProcessRenderDebug(void);


PX_POP_PACK

} // end of namespace

#endif