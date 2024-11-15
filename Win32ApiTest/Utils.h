#pragma once


/**
Releases a pointer and sets to NULL if it is not NULL
*/
template <class T> void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}