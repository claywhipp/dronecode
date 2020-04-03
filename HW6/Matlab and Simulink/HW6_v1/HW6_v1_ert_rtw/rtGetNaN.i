# 1 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.c"
# 24 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.c"
# 1 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.h" 1
# 22 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.h"
# 1 "c:\\programdata\\matlab\\supportpackages\\r2019b\\3p.instrset\\ev3sourcerylite.instrset\\codesourcery\\bin\\../lib/gcc/arm-none-linux-gnueabi/4.4.1/include/stddef.h" 1 3 4
# 149 "c:\\programdata\\matlab\\supportpackages\\r2019b\\3p.instrset\\ev3sourcerylite.instrset\\codesourcery\\bin\\../lib/gcc/arm-none-linux-gnueabi/4.4.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 211 "c:\\programdata\\matlab\\supportpackages\\r2019b\\3p.instrset\\ev3sourcerylite.instrset\\codesourcery\\bin\\../lib/gcc/arm-none-linux-gnueabi/4.4.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 323 "c:\\programdata\\matlab\\supportpackages\\r2019b\\3p.instrset\\ev3sourcerylite.instrset\\codesourcery\\bin\\../lib/gcc/arm-none-linux-gnueabi/4.4.1/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 23 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.h" 2
# 1 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtwtypes.h" 1
# 51 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtwtypes.h"
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef float real32_T;
typedef double real64_T;





typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;






typedef struct {
  real32_T re;
  real32_T im;
} creal32_T;

typedef struct {
  real64_T re;
  real64_T im;
} creal64_T;

typedef struct {
  real_T re;
  real_T im;
} creal_T;



typedef struct {
  int8_T re;
  int8_T im;
} cint8_T;



typedef struct {
  uint8_T re;
  uint8_T im;
} cuint8_T;



typedef struct {
  int16_T re;
  int16_T im;
} cint16_T;



typedef struct {
  uint16_T re;
  uint16_T im;
} cuint16_T;



typedef struct {
  int32_T re;
  int32_T im;
} cint32_T;



typedef struct {
  uint32_T re;
  uint32_T im;
} cuint32_T;
# 152 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtwtypes.h"
typedef void * pointer_T;
# 24 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.h" 2
# 1 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rt_nonfinite.h" 1
# 22 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rt_nonfinite.h"
# 1 "c:\\programdata\\matlab\\supportpackages\\r2019b\\3p.instrset\\ev3sourcerylite.instrset\\codesourcery\\bin\\../lib/gcc/arm-none-linux-gnueabi/4.4.1/include/stddef.h" 1 3 4
# 23 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rt_nonfinite.h" 2


extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;
# 25 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.h" 2

extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
# 25 "C:/Users/cwhipp/Desktop/DRONEL~1/HW/HW6/MATLAB~1/HW6_v1/HW6_v1_ert_rtw/rtGetNaN.c" 2






real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (8U);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}





real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}
