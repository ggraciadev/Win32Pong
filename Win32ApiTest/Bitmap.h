#pragma once
#include "ISerializable.h"

class Bitmap : public ISerializable
{
    virtual void Load(PCWSTR filename) {}
    virtual void Save(PCWSTR filename) {}
};