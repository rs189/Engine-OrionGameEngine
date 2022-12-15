/*
    File: IObject.h

    Copyright (C) 2019-2020 rs189. All rights reserved
*/

#pragma once

#include <IInterfaces.h>
#include <Includes.h>

#include "physics/IPhysics.h"

class IInterfaces;

class IPhysics;

class IObject
{
public:
    // * Those are calls allocated for class initialization and running
    // ---------------------------------------------

    // Activates IObject initalization process
    void Start(IInterfaces* interfaces);

    // Activates IObject shutdown process
    void Stop();

    // Processing a single frame of IObject
    void Run(float dt);

    // * Those are calls that are accessible by everyone 
    // ---------------------------------------------

    //! Transform components
    void SetScale(Vector scale);
    Vector GetScale();

    void SetRotation(Vector rotation);
    Vector GetRotation();

    void SetPosition(Vector position);
    Vector GetPosition();

    //! Physics system
    void CreatePhysics();
    IPhysics* GetPhysics();

    struct EData
    {
        const char* m_ModelName;
    };

    EData m_Data;

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
    wiECS::Entity m_Entity;
public:
    Vector m_Position;
    Vector m_Rotation;
    Vector m_Scale;
public:
    IPhysics* m_Physics;
};