//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#include "BsD3D11RenderStateManager.h"
#include "BsD3D11SamplerState.h"
#include "BsD3D11DepthStencilState.h"
#include "BsD3D11RasterizerState.h"
#include "BsD3D11BlendState.h"

namespace bs { namespace ct
{
	SPtr<SamplerStateCore> D3D11RenderStateManager::createSamplerStateInternal(const SAMPLER_STATE_DESC& desc, GpuDeviceFlags deviceMask) const
	{
		SPtr<SamplerStateCore> ret = bs_shared_ptr<D3D11SamplerState>(new (bs_alloc<D3D11SamplerState>()) D3D11SamplerState(desc, deviceMask));
		ret->_setThisPtr(ret);

		return ret;
	}

	SPtr<BlendStateCore> D3D11RenderStateManager::createBlendStateInternal(const BLEND_STATE_DESC& desc, UINT32 id) const
	{
		SPtr<BlendStateCore> ret = bs_shared_ptr<D3D11BlendState>(new (bs_alloc<D3D11BlendState>()) D3D11BlendState(desc, id));
		ret->_setThisPtr(ret);

		return ret;
	}

	SPtr<RasterizerStateCore> D3D11RenderStateManager::createRasterizerStateInternal(const RASTERIZER_STATE_DESC& desc, UINT32 id) const
	{
		SPtr<RasterizerStateCore> ret = bs_shared_ptr<D3D11RasterizerState>(new (bs_alloc<D3D11RasterizerState>()) D3D11RasterizerState(desc, id));
		ret->_setThisPtr(ret);

		return ret;
	}

	SPtr<DepthStencilStateCore> D3D11RenderStateManager::createDepthStencilStateInternal(const DEPTH_STENCIL_STATE_DESC& desc, UINT32 id) const
	{
		SPtr<DepthStencilStateCore> ret = bs_shared_ptr<D3D11DepthStencilState>(new (bs_alloc<D3D11DepthStencilState>()) D3D11DepthStencilState(desc, id));
		ret->_setThisPtr(ret);

		return ret;
	}
}}