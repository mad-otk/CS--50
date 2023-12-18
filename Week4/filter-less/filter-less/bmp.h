#include <stdint.h>
#include <Windows.h>
#include <wingdi.h>

#ifndef BMP_H
#define BMP_H

typedef uint8_t  BMP_BYTE;
typedef uint32_t BMP_DWORD;
typedef int32_t  BMP_LONG;
typedef uint16_t BMP_WORD;

// #if !defined(_WIN32) || defined(__GNUC__)
// #pragma pack(push, 1)

typedef struct
{
    BMP_WORD   bfType;
    BMP_DWORD  bfSize;
    BMP_WORD   bfReserved1;
    BMP_WORD   bfReserved2;
    BMP_DWORD  bfOffBits;
} BMP_BITMAPFILEHEADER;

typedef struct
{
    BMP_DWORD  biSize;
    BMP_LONG   biWidth;
    BMP_LONG   biHeight;
    BMP_WORD   biPlanes;
    BMP_WORD   biBitCount;
    BMP_DWORD  biCompression;
    BMP_DWORD  biSizeImage;
    BMP_LONG   biXPelsPerMeter;
    BMP_LONG   biYPelsPerMeter;
    BMP_DWORD  biClrUsed;
    BMP_DWORD  biClrImportant;
} BMP_BITMAPINFOHEADER;

typedef struct
{
    BMP_BYTE  rgbtBlue;
    BMP_BYTE  rgbtGreen;
    BMP_BYTE  rgbtRed;
} BMP_RGBTRIPLE;

// #pragma pack(pop)
// #endif  // !defined(_WIN32) || defined(__GNUC__)

#endif //BMP_H