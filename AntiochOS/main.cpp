#include <stdio.h>
#include <stdlib.h>

//buf_4040C0
//.AntiochOS, version 1.32 (build 1975)
unsigned char Version[38] = {
    0x00, 0xCA, 0xE5, 0xFF, 0xE2, 0xE4, 0xE8, 0xE3, 0xC4, 0xD8, 0xA7, 0xAB,
    0xFD, 0xEE, 0xF9, 0xF8, 0xE2, 0xE4, 0xE5, 0xAB, 0xBA, 0xA5, 0xB8, 0xB9,
    0xAB, 0xA3, 0xE9, 0xFE, 0xE2, 0xE7, 0xEF, 0xAB, 0xBA, 0xB2, 0xBC, 0xBE,
    0xA2, 0x81
};

// sub_4013E0 : Anti_GetVersion
unsigned char* Anti_GetVersion()
{
    unsigned char val;
    unsigned char* ptr;

    //The first byte of the string indicates if the string was already decrypted
    val = Version[0];
    if (!Version[0])
    {
        //Decrypt the string
        for (ptr = Version; ptr < (Version + 38); val = *ptr)
        {
            *ptr++ = val ^ 0x8B;
        }
    }
    //Return the string but skip the first byte
    return &Version[1];
}

/*
int sub_401980(int a1, unsigned int a2, unsigned char* a3, int a4)
{
    long result; // rax

    result = a1;
    __asm { syscall; LINUX - sys_open }
    return result;
}
*/

void sub_4019F0(unsigned int a1, unsigned char* a2, int a3)
{
    sub_401980(1, a1, a2, a3);
}

// sub_4012E0 : Anti_GetTypeHelpMessage
void Anti_GetTypeHelpMessage(unsigned char* Output)
{
    //Type help for help
    Output[0] = 'T'; // 84
    Output[1] = 'y'; // 121
    Output[2] = 'p'; // 112
    Output[3] = 'e'; // 101
    Output[4] = ' '; // 32
    Output[5] = 'h'; // 104
    Output[6] = 'e'; // 101
    Output[7] = 'l'; // 108
    Output[8] = 'p'; // 112
    Output[9] = ' '; // 32
    Output[10] = 'f'; // 102
    Output[11] = 'o'; // 111
    Output[12] = 'r'; // 114
    Output[13] = ' '; // 32
    Output[14] = 'h'; // 104
    Output[15] = 'e'; // 101
    Output[16] = 'l'; // 108
    Output[17] = 'p'; // 112
    Output[18] = '\n'; // 10
    Output[19] = '\0'; // 0
}

__int64 __fastcall sub_401A10(unsigned int a1, __int64 a2, __int64 a3)
{
    return (int)sub_401980(0LL, a1, a2, a3);
}

// sub_401340 : Anti_GetQuitString
void Anti_GetQuitString(unsigned char* a1)
{
    a1[0] = 'q'; // 113
    a1[1] = 'u'; // 117
    a1[2] = 'i'; // 105
    a1[3] = 't'; // 116
    a1[4] = '\n'; // 10
    a1[5] = '\0'; // 0
}

// sub_401AB0 : Anti_StrCmp
char Anti_StrCmp(unsigned char* a1, unsigned char* a2, int a3)
{
    long v3; // rax
    char v4; // cl

    if (!a3)
        return 0LL;
    v3 = 0LL;
    while (1)
    {
        v4 = a1[v3];
        if (v4 != a2[v3])
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

void sub_401360(unsigned char* a1)
{
    a1[0] = 104;
    a1[1] = 101;
    a1[2] = 108;
    a1[3] = 112;
    a1[4] = 10;
    a1[5] = 0;
}

void sub_401380(unsigned char* a1)
{
    a1[0] = 99;
    a1[1] = 111;
    a1[2] = 110;
    a1[3] = 115;
    a1[4] = 117;
    a1[5] = 108;
    a1[6] = 116;
    a1[7] = 10;
    a1[8] = 0;
}

void sub_4013B0(unsigned char* a1)
{
    a1[0] = 97;
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

/*
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
*/

/*
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
}*/


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

int main()
{
  unsigned char* v0; // rax
  _BYTE v2[32]; // [rsp+0h] [rbp-B8h] BYREF
  __int16 v3[76]; // [rsp+20h] [rbp-98h] BYREF

  v0 = Anti_GetVersion();
  sub_4019F0(1LL, v0, 37LL);
  Anti_GetTypeHelpMessage(v3);
  sub_4019F0(1LL, v3, 19LL);
  while ( 1 )
  {
    v3[0] = 8254;
    sub_4019F0(1LL, v3, 2LL);
    if ( !sub_401A10(0LL, v3, 128LL) )
      break;
    Anti_GetQuitString(v2);
    if ( !(unsigned int)Anti_StrCmp(v3, v2, 5LL) )
      break;
    sub_401360(v2);
    if ( (unsigned int)Anti_StrCmp(v3, v2, 5LL) )
    {
      sub_401380(v2);
      if ( (unsigned int)Anti_StrCmp(v3, v2, 8LL) )
      {
        sub_4013B0(v2);
        if ( !(unsigned int)Anti_StrCmp(v3, v2, 9LL) )
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
