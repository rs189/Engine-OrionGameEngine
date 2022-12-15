/*
	File: Tier0.h

	Copyright (C) 2019-2020 rs189. All rights reserved
*/

#pragma once

#include <IInterfaces.h>
#include <Includes.h>

#include "../../public/systems/rendering/IRendering.h"
#include "../../public/systems/vr/IVR.h"

class IRendering;
class IVR;

class IInterfaces;

class Tier0
{
public:
	// * Those are calls allocated for class initialization and running
	// ---------------------------------------------

	// Activates Tier0 initialization process
	void Start(IInterfaces* interfaces);

	// Activates Tier0 shutdown process
	void Stop();

	// Processing a single frame of Tier0
	void Run(float dt);

protected:
	IInterfaces* m_Interface;
protected:
	template <class T> void SafeRelease(T** ppT)
	{
		if (*ppT)
		{
			*ppT = nullptr;
		}
	}
public:
	IRendering* m_Rendering;
	IVR* m_VR;
};