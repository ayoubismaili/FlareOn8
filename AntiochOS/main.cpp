#include <stdio.h>
#include <stdlib.h>

unsigned char buf_4040C0[38] = {
    0x00, 0xCA, 0xE5, 0xFF, 0xE2, 0xE4, 0xE8, 0xE3, 0xC4, 0xD8, 0xA7, 0xAB,
    0xFD, 0xEE, 0xF9, 0xF8, 0xE2, 0xE4, 0xE5, 0xAB, 0xBA, 0xA5, 0xB8, 0xB9,
    0xAB, 0xA3, 0xE9, 0xFE, 0xE2, 0xE7, 0xEF, 0xAB, 0xBA, 0xB2, 0xBC, 0xBE,
    0xA2, 0x81
};

__int64 __fastcall sub_4019F0(unsigned int a1, __int64 a2, __int64 a3)
{
    return (int)sub_401980(1LL, a1, a2, a3);
}

void __fastcall sub_4012E0(_BYTE* a1)
{
    *a1 = 84;
    a1[1] = 121;
    a1[2] = 112;
    a1[3] = 101;
    a1[4] = 32;
    a1[5] = 104;
    a1[6] = 101;
    a1[7] = 108;
    a1[8] = 112;
    a1[9] = 32;
    a1[10] = 102;
    a1[11] = 111;
    a1[12] = 114;
    a1[13] = 32;
    a1[14] = 104;
    a1[15] = 101;
    a1[16] = 108;
    a1[17] = 112;
    a1[18] = 10;
    a1[19] = 0;
}

__int64 __fastcall sub_401A10(unsigned int a1, __int64 a2, __int64 a3)
{
    return (int)sub_401980(0LL, a1, a2, a3);
}

void __fastcall sub_401340(_BYTE* a1)
{
    *a1 = 113;
    a1[1] = 117;
    a1[2] = 105;
    a1[3] = 116;
    a1[4] = 10;
    a1[5] = 0;
}

__int64 __fastcall sub_401AB0(__int64 a1, __int64 a2, __int64 a3)
{
    __int64 v3; // rax
    char v4; // cl

    if (!a3)
        return 0LL;
    v3 = 0LL;
    while (1)
    {
        v4 = *(_BYTE*)(a1 + v3);
        if (v4 != *(_BYTE*)(a2 + v3))
            break;
        if (v4)
        {
            if (a3 != ++v3)
                continue;
        }
        return 0LL;
    }
    return 1LL;
}

void __fastcall sub_401360(_BYTE* a1)
{
    *a1 = 104;
    a1[1] = 101;
    a1[2] = 108;
    a1[3] = 112;
    a1[4] = 10;
    a1[5] = 0;
}

void __fastcall sub_401380(_BYTE* a1)
{
    *a1 = 99;
    a1[1] = 111;
    a1[2] = 110;
    a1[3] = 115;
    a1[4] = 117;
    a1[5] = 108;
    a1[6] = 116;
    a1[7] = 10;
    a1[8] = 0;
}

void __fastcall sub_4013B0(_BYTE* a1)
{
    *a1 = 97;
    a1[1] = 112;
    a1[2] = 112;
    a1[3] = 114;
    a1[4] = 111;
    a1[5] = 97;
    a1[6] = 99;
    a1[7] = 104;
    a1[8] = 10;
    a1[9] = 0;
}

__int64 sub_401640()
{
    __int64 v0; // rbx
    __int64 v1; // rax
    __int64 v2; // rsi
    int v3; // eax
    int* v4; // rdx
    int v5; // ecx
    __int64 v6; // rax
    int v7; // r8d
    char* v8; // rax
    char v9; // al
    __int64 v10; // rax
    char v12; // [rsp+Fh] [rbp-B9h] BYREF
    char v13[32]; // [rsp+10h] [rbp-B8h] BYREF
    char v14[152]; // [rsp+30h] [rbp-98h] BYREF

    v0 = 0LL;
    v12 = 10;
    v1 = sub_401260();
    sub_4019F0(1u, v1, 37LL);
    sub_401A50(1LL);
    sub_401120(v13);
    sub_4019F0(1u, (__int64)v13, 19LL);
    v2 = sub_401A10(0, (__int64)v14, 128LL);
    v3 = sub_401B50(v14, v2);
    v4 = (int*)&unk_40200C;
    v5 = -1248619095;
    while (v5 != v3)
    {
        v0 = (unsigned int)(v0 + 1);
        if ((_DWORD)v0 == 30)
            return sub_4019F0(1u, (__int64)"...AAARGH\n\n", 11LL);
        v5 = *v4;
        v4 += 3;
    }
    sub_401180(v13, v2, v4);
    sub_4019F0(1u, (__int64)v13, 20LL);
    if (sub_401A10(0, (__int64)v14, 128LL) > 1)
    {
        sub_4011E0(v13);
        sub_4019F0(1u, (__int64)v13, 29LL);
        v6 = sub_401A10(0, (__int64)v14, 128LL);
        v7 = sub_401B50(v14, v6);
        v8 = (char*)&unk_402000 + 12 * v0;
        if (*((_DWORD*)v8 + 1) == v7)
        {
            v9 = v8[8];
            if (v9 > 0)
            {
                sub_401AF0((unsigned int)v9, v14);
                v10 = sub_4012A0();
                sub_4019F0(1u, v10, 20LL);
                sub_4019F0(1u, (__int64)v14, strlen(v14));
                return sub_4019F0(1u, (__int64)&v12, 1LL);
            }
        }
    }
    return sub_4019F0(1u, (__int64)"...AAARGH\n\n", 11LL);
}

__int64 sub_401460()
{
    int v0; // r14d
    __int64 v1; // rsi
    signed int v2; // eax
    unsigned int v3; // r13d
    char* v4; // rax
    __int64* v5; // rdx
    __int64 i; // rax
    char v7; // dl
    __int64 v9; // [rsp+8h] [rbp-2030h] BYREF
    __int64 v10[512]; // [rsp+10h] [rbp-2028h] BYREF
    unsigned __int8 v11[4096]; // [rsp+1010h] [rbp-1028h] BYREF
    char v12; // [rsp+2010h] [rbp-28h] BYREF

    v0 = 97;
    v9 = 0x7461642E2ELL;
    memset(v11, 0, sizeof(v11));
    v1 = sub_4010E0();
    sub_4019F0(1u, v1, 31LL);
    sub_401A50(2LL);
    do
    {
        while (1)
        {
            LOBYTE(v9) = v0;
            v2 = sub_4019D0(&v9);
            v3 = v2;
            if (v2 >= 0)
                break;
            if ((_BYTE)++v0 == 123)
                goto LABEL_7;
        }
        sub_401A10(v2, (__int64)v10, 4096LL);
        sub_401A30(v3);
        v4 = (char*)v11;
        v5 = v10;
        do
        {
            *v4++ ^= *(_BYTE*)v5;
            v5 = (__int64*)((char*)v5 + 1);
        } while (v4 != &v12);
        ++v0;
    } while ((_BYTE)v0 != 123);
LABEL_7:
    if (!(_BYTE)xmmword_404100)
    {
        xmmword_404100 = (__int128)_mm_load_si128((const __m128i*) & xmmword_402240);
        xmmword_404110 = xmmword_404100;
        xmmword_404120 = xmmword_404100;
        xmmword_404130 = xmmword_404100;
        xmmword_404140 = xmmword_404100;
        xmmword_404150 = xmmword_404100;
        xmmword_404160 = xmmword_404100;
        xmmword_404170 = xmmword_404100;
        xmmword_404180 = xmmword_404100;
        xmmword_404190 = xmmword_404100;
        xmmword_4041A0 = xmmword_404100;
        xmmword_4041B0 = xmmword_404100;
        xmmword_4041C0 = xmmword_404100;
        xmmword_4041D0 = xmmword_404100;
        xmmword_4041E0 = xmmword_404100;
        xmmword_4041F0 = xmmword_404100;
        sub_401000(&xmmword_404100);
    }
    for (i = 0LL; i != 4096; ++i)
    {
        v7 = 10;
        if ((i & 0xF) != 15)
            v7 = *((_BYTE*)&xmmword_404100 + v11[i]);
        v11[i] = v7;
    }
    return sub_4019F0(1u, (__int64)v11, 4096LL);
}

__int64 sub_401420()
{
    __int64 v0; // rax

    v0 = sub_4010A0();
    sub_4019F0(1u, v0, 42LL);
    return sub_4019F0(1u, (__int64)"...AAARGH\n\n", 11LL);
}

__int64 __fastcall sub_401A90(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
    return sub_401980(60LL, a1, a3, a4);
}

unsigned char *sub_4013E0()
{
  unsigned char v0; // dl
  unsigned char *i; // rax

  v0 = buf_4040C0[0];
  if (!buf_4040C0[0])
  {
    for ( i = buf_4040C0; ; v0 = *i )
    {
      *i++ = v0 ^ 0x8B;
      if ( i == buf_4040C0 + 38 )
        break;
    }
  }
  return &buf_4040C0[1];
}

int main()
{
  __int64 v0; // rax
  _BYTE v2[32]; // [rsp+0h] [rbp-B8h] BYREF
  __int16 v3[76]; // [rsp+20h] [rbp-98h] BYREF

  v0 = sub_4013E0();
  sub_4019F0(1LL, v0, 37LL);
  sub_4012E0(v3);
  sub_4019F0(1LL, v3, 19LL);
  while ( 1 )
  {
    v3[0] = 8254;
    sub_4019F0(1LL, v3, 2LL);
    if ( !sub_401A10(0LL, v3, 128LL) )
      break;
    sub_401340(v2);
    if ( !(unsigned int)sub_401AB0(v3, v2, 5LL) )
      break;
    sub_401360(v2);
    if ( (unsigned int)sub_401AB0(v3, v2, 5LL) )
    {
      sub_401380(v2);
      if ( (unsigned int)sub_401AB0(v3, v2, 8LL) )
      {
        sub_4013B0(v2);
        if ( !(unsigned int)sub_401AB0(v3, v2, 9LL) )
          sub_401640();
      }
      else
      {
        sub_401460();
      }
    }
    else
    {
      sub_401420();
    }
  }
  return sub_401A90(0LL);
}
