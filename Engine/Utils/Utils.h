#ifndef UTILS_HH
#define UTILS_HH


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

#define CLAMP(a,x,y) max(min(a,y),x)
#endif