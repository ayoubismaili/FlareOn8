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

//byte_404020
//.Approach the Gorge of Eternal Peril!
unsigned char ApproachGorge[38] = {
	0x00, 0xDC, 0xED, 0xED, 0xEF, 0xF2, 0xFC, 0xFE, 0xF5, 0xBD, 0xE9, 0xF5,
	0xF8, 0xBD, 0xDA, 0xF2, 0xEF, 0xFA, 0xF8, 0xBD, 0xF2, 0xFB, 0xBD, 0xD8,
	0xE9, 0xF8, 0xEF, 0xF3, 0xFC, 0xF1, 0xBD, 0xCD, 0xF8, 0xEF, 0xF4, 0xF1,
	0xBC, 0x97
};


#define VERSION_STRING_LENGTH   37
#define TYPE_HELP_STRING_LENGTH 19
#define APPROACH_STRING_LENGTH  9
#define CONSULT_STRING_LENGTH   8
#define HELP_STRING_LENGTH      5
#define QUIT_STRING_LENGTH      5
#define PROMPT_STRING_LENGTH    2

#define READ_BUFFER_LENGTH      128

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

// sub_401260 : Anti_GetApproachGorge
void* Anti_GetApproachGorge()
{
	unsigned char val;
	unsigned char* ptr;

	//The first byte of the string indicates if the string was already decrypted
	val = ApproachGorge[0];
	if (!ApproachGorge[0])
	{
		//Decrypt the string
		for (ptr = ApproachGorge; ptr < (ApproachGorge + 38); val = *ptr)
		{
			*ptr++ = val ^ 0x9D;
		}
	}
	//Return the string but skip the first byte
	return &ApproachGorge[1];
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

// sub_401340 : Anti_GetQuitString
void Anti_GetQuitString(unsigned char* Output)
{
	Output[0] = 'q'; // 113
	Output[1] = 'u'; // 117
	Output[2] = 'i'; // 105
	Output[3] = 't'; // 116
	Output[4] = '\n'; // 10
	Output[5] = '\0'; // 0
}

// sub_401360 : Anti_GetHelpString
void Anti_GetHelpString(unsigned char* Output)
{
	//help
	Output[0] = 'h'; // 104
	Output[1] = 'e'; // 101
	Output[2] = 'l'; // 108
	Output[3] = 'p'; // 112
	Output[4] = '\n'; // 10
	Output[5] = '\0'; // 0
}

// sub_401380 : Anti_GetConsultString
void Anti_GetConsultString(unsigned char* Output)
{
	//consult
	Output[0] = 'c'; // 99
	Output[1] = 'o'; // 111
	Output[2] = 'n'; // 110
	Output[3] = 's'; // 115
	Output[4] = 'u'; // 117
	Output[5] = 'l'; // 108
	Output[6] = 't'; // 116
	Output[7] = '\n'; // 10
	Output[8] = '\0'; // 0
}

// sub_4013B0 : Anti_GetApproachString
void Anti_GetApproachString(unsigned char* Output)
{
	//approach
	Output[0] = 'a'; // 97
	Output[1] = 'p'; // 112
	Output[2] = 'p'; // 112
	Output[3] = 'r'; // 114
	Output[4] = 'o'; // 111
	Output[5] = 'a'; // 97
	Output[6] = 'c'; // 99
	Output[7] = 'h'; // 104
	Output[8] = '\n'; // 10
	Output[9] = '\0'; // 0
}

// sub_401120 : Anti_GetWhatIsYourNameString
void Anti_GetWhatIsYourNameString(unsigned char* Output)
{
	strcpy(Output, "What is your name? ");
}

// sub_401980 : Anti_Syscall
int Anti_Syscall(int a1, unsigned int a2, unsigned char* a3, int a4)
{
	long result; // rax

	//https://man7.org/linux/man-pages/man2/syscall.2.html
	//Arch/ABI      arg1  arg2  arg3  arg4  arg5  arg6  arg7  Notes
	//x86-64        rdi   rsi   rdx   r10   r8    r9    -
	// 
	// mov     rax, rdi
	// mov     rdi, rsi
	// mov     rsi, rdx
	// mov     rdx, rcx
	// mov     r10, r8
	// mov     r8, r9
	// syscall; LINUX - sys_open
	// retn

	result = a1;
	//__asm { syscall; LINUX - sys_open }
	return result;
}

// sub_4019F0 : Anti_Write
int Anti_Write(int fd, const void* buf, size_t count)
{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_write = 1
	return Anti_Syscall(1, fd, buf, count);
}

// sub_401A10 : Anti_Read
int Anti_Read(int fd, const void* buf, size_t count)
{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_read = 0
	return Anti_Syscall(0, fd, buf, count);
}

// sub_401A90 : Anti_Exit
int Anti_Exit(int error_code)
{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_exit = 60
	return Anti_Syscall(60, error_code, 0, 0);
}

// sub_401AB0 : Anti_StrCmp
char Anti_StrCmp(unsigned char* Source, unsigned char* Destination, int Length)
{
	int i;
	char val;

	if (!Length)
		return 0;
	i = 0;
	while (1)
	{
		val = Source[i];
		if (val != Destination[i])
			break;
		if (val)
		{
			if (Length != ++i)
				continue;
		}
		return 0;
	}
	return 1;
}

// sub_401A50 : Anti_Select
int Anti_Select(int value)
{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_select = 23
	return Anti_Syscall(23, 0, 0, 0);
}

// sub_401640 : Anti_Approach
void sub_401640()
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
	v1 = Anti_GetApproachGorge();
	Anti_Write(stdout, v1, 37);
	Anti_Select(1);
	Anti_GetWhatIsYourNameString(v13);
	Anti_Write(stdout, (__int64)v13, 19LL);
	v2 = sub_401A10(0, (__int64)v14, 128LL);
	v3 = sub_401B50(v14, v2);
	v4 = (int*)&unk_40200C;
	v5 = -1248619095;
	while (v5 != v3)
	{
		v0 = (unsigned int)(v0 + 1);
		if ((_DWORD)val == 30) {
			Anti_Write(stdout, (__int64)"...AAARGH\n\n", 11LL);
			return;
		}
		v5 = *v4;
		v4 += 3;
	}
	sub_401180(v13, v2, v4);
	Anti_Write(stdout, (__int64)v13, 20LL);
	if (sub_401A10(0, (__int64)v14, 128LL) > 1)
	{
		sub_4011E0(v13);
		Anti_Write(stdout, (__int64)v13, 29LL);
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
				Anti_Write(stdout, v10, 20LL);
				Anti_Write(stdout, (__int64)v14, strlen(v14));
				Anti_Write(stdout, (__int64)&v12, 1LL);
				return;
			}
		}
	}
	Anti_Write(stdout, "...AAARGH\n\n", 11);
}

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
	Anti_Write(1u, v0, 42LL);
	return Anti_Write(1u, (__int64)"...AAARGH\n\n", 11LL);
}

int main()
{
	unsigned char* version;
	unsigned char command[32];
	unsigned char data[152];

	//Obtain version
	version = Anti_GetVersion();
	//Write version to the Console
	Anti_Write(stdout, version, VERSION_STRING_LENGTH);
	//Obtain Type Help message
	Anti_GetTypeHelpMessage(data);
	//Write Type Help message to the Console
	Anti_Write(stdout, data, TYPE_HELP_STRING_LENGTH);
	//Command loop
	while (1)
	{
		//Fill buffer with prompt string
		data[0] = '>';
		data[1] = ' ';
		//Write prompt string to the console
		Anti_Write(stdout, data, PROMPT_STRING_LENGTH);
		//Read command from the Console
		if (!Anti_Read(stdin, data, READ_BUFFER_LENGTH))
			break;
		//Obtain quit string
		Anti_GetQuitString(command);
		//Check if command is quit
		if (!Anti_StrCmp(data, command, QUIT_STRING_LENGTH))
			break;
		//Obtain help string
		Anti_GetHelpString(command);
		//Check if command is NOT help
		if (Anti_StrCmp(data, command, HELP_STRING_LENGTH))
		{
			//Obtain consult string
			Anti_GetConsultString(command);
			//Check if command is NOT consult
			if (Anti_StrCmp(data, command, CONSULT_STRING_LENGTH))
			{
				//Obtain approach string
				Anti_GetApproachString(command);
				//Check if command is approach
				if (!Anti_StrCmp(data, command, APPROACH_STRING_LENGTH))
					//Execute approach command
					sub_401640();
			}
			else
			{
				//Execute consult command
				sub_401460();
			}
		}
		else
		{
			//Execute help command
			sub_401420();
		}
	}
	return Anti_Exit(0);
}
