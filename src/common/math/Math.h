/*
	File: Math.h

	Copyright (C) 2019-2020 rs189. All rights reserved
*/

#pragma once

#include <Includes.h>

class Vector;

class Math
{
public:
	static Vector Clamp(Vector vector)
	{
		Vector angles = vector;
		if (angles.x > 89.0f)
			angles.x = 89.0f;
		if (angles.x < -89.0f)
			angles.x = -89.0f;

		if (angles.y > 360.0f)
			angles.y = 0.0f;
		if (angles.y < -360.0f)
			angles.y = 0.0f;

		return angles;
	}
};