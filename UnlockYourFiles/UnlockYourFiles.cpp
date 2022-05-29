// UnlockYourFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>

/*asc_403000*/
const CHAR Message[] = "**********                                                                                                   \nAttention!                                                                                                   \n**********                                                                                                   \n                                                                                                             \nYour documents, photos, and other important files have been encrypted with a strong algorithm.               \n                                                                                                             \nDon't try and change file extensions! It can be dangerous for the encrypted information!                     \n                                                                                                             \nThe only way to recover (decrypt) your files is to run this decryptor with the unique private key.           \nAttention! Only we can recover your files! If someone tell you that he can do this, kindly ask him to proof! \n                                                                                                             \nBelow you will see a big base64 blob, you will need to email us and copy this blob to us.                    \nYou must pay all but 1 BTC to 48 hours for recover it. After 48 hours we will leaked all your data!          \n                                                                                                             \nKD4wXzApPiBJdCdzIGRhbmdlcm91cyB0byBhZGQrcm9yIGFsb25lISBUYWtlIHRoaXMgPCgwXzA8KQo=                             \n                                                                                                             \nEnter the decryption key and press Enter: ";
#define MESSAGE_LENGTH 1802
#define BLOCK_SIZE 8

const CHAR Arrow[] = " -> ";
#define ARROW_LENGTH 4

const CHAR FailedError[] = " failed: error code ";
#define FAILED_ERROR_LENGTH 20

const CHAR FilesDirectory[] = "\nMake sure the Files directory is present and all files are closed and writable\n";
#define FILES_DIRECTORY_LENGTH 80

const CHAR NumberOfFiles[] = "Number of files decoded: ";
#define NUMBER_OF_FILES_LENGTH 25

HANDLE hConsoleInput;
HANDLE hConsoleOutput;

CHAR PathName[] = "Files";
CHAR FileName[] = "*.encrypted";

CHAR* sub_401070(unsigned int a1, CHAR* a2)
{
    if (a1 >= 0xA)
        a2 = (CHAR*)sub_401070(a1 / 0xA, a2);
    *a2 = a1 % 0xA + 48;
    a2[1] = 0;
    return a2 + 1;
}

// sub_4010C0 : Ransom_HandleError
void Ransom_HandleError(const CHAR* lpBuffer)
{
    DWORD LastError; // eax
    DWORD v2; // eax
    DWORD v3; // eax
    char Buffer[12]; // [esp+0h] [ebp-Ch] BYREF

    LastError = GetLastError();
    sub_401070(LastError, Buffer);
    v2 = strlen(lpBuffer);
    WriteConsoleA(hConsoleOutput, lpBuffer, v2, NULL, NULL);
    WriteConsoleA(hConsoleOutput, FailedError, FAILED_ERROR_LENGTH, NULL, NULL);
    v3 = strlen(Buffer);
    WriteConsoleA(hConsoleOutput, Buffer, v3, NULL, NULL);
    WriteConsoleA(hConsoleOutput, FilesDirectory, FILES_DIRECTORY_LENGTH, NULL, NULL);
    ExitProcess(1u);
}

int sub_401030(CHAR* a1, CHAR* a2)
{
    int i;

    for (i = 0; ; ++i)
    {
        a1[i] = a2[i];
        if (!a2[i])
            break;
    }
    return i;
}

char sub_4011F0(CHAR* a1, CHAR* a2)
{
    int i; // ecx
    CHAR result; // al

    for (i = 0; (char)i < 8; i++)
    {
        result = _rotl(a2[i] ^ a1[i], i) - i;
        a1[i] = result;
    }
    return result;
}

VOID sub_401220(CHAR* lpFileName, CHAR* a2, CHAR* a3)
{
    CHAR Buffer[8]; // [esp+0h] [ebp-18h] BYREF
    DWORD NumberOfBytesWritten; // [esp+8h] [ebp-10h] BYREF
    HANDLE hFile; // [esp+Ch] [ebp-Ch]
    HANDLE hObject; // [esp+10h] [ebp-8h]
    DWORD NumberOfBytesRead; // [esp+14h] [ebp-4h] BYREF
    
    hFile = CreateFileA(lpFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        Ransom_HandleError(lpFileName);
    hObject = CreateFileA(a2, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hObject == INVALID_HANDLE_VALUE)
        Ransom_HandleError(a2);
    while (1)
    {
        if (!ReadFile(hFile, Buffer, BLOCK_SIZE, &NumberOfBytesRead, NULL))
            Ransom_HandleError(lpFileName);
        if (!NumberOfBytesRead)
            break;
        sub_4011F0(Buffer, a3);
        if (!WriteFile(hObject, Buffer, NumberOfBytesRead, &NumberOfBytesWritten, NULL))
            Ransom_HandleError(a2);
    }
    CloseHandle(hObject);
    CloseHandle(hFile);
    NumberOfBytesRead = strlen(lpFileName);
    a2[NumberOfBytesRead - 10] = 10;
    WriteConsoleA(hConsoleOutput, lpFileName, NumberOfBytesRead, NULL, NULL);
    WriteConsoleA(hConsoleOutput, Arrow, ARROW_LENGTH, NULL, NULL);
    WriteConsoleA(hConsoleOutput, a2, NumberOfBytesRead - 9, NULL, NULL);
}

VOID sub_401160(unsigned int a1)
{
    DWORD v1; // eax
    char Buffer[12]; // [esp+0h] [ebp-10h] BYREF
    DWORD nNumberOfCharsToWrite; // [esp+Ch] [ebp-4h]

    sub_401070(a1, Buffer);
    WriteConsoleA(hConsoleOutput, NumberOfFiles, NUMBER_OF_FILES_LENGTH, NULL, NULL);
    v1 = strlen(Buffer);
    WriteConsoleA(hConsoleOutput, Buffer, v1, NULL, NULL);
    if (a1)
        nNumberOfCharsToWrite = 1;
    else
        nNumberOfCharsToWrite = 80;
    WriteConsoleA(hConsoleOutput, FilesDirectory, nNumberOfCharsToWrite, NULL, NULL);
}

// sub_401370 : Ransom_DecryptFiles
BOOL Ransom_DecryptFiles(CHAR Key[8]) {
    struct _WIN32_FIND_DATAA FindFileData; // [esp+0h] [ebp-190h] BYREF
    CHAR v3[64]; // [esp+140h] [ebp-50h] BYREF
    int v4; // [esp+180h] [ebp-10h]
    HANDLE hFindFile; // [esp+188h] [ebp-8h]
    int v6; // [esp+18Ch] [ebp-4h]

    v6 = 0;
    if (!SetCurrentDirectoryA(PathName))
        Ransom_HandleError("SetCurrentDirectory(\"Files\")");
    hFindFile = FindFirstFileA(FileName, &FindFileData);
    if (hFindFile == INVALID_HANDLE_VALUE)
        Ransom_HandleError("FindFirstFile");
    do
    {
        v4 = sub_401030(v3, FindFileData.cFileName);
        FindFileData.cAlternateFileName[v4 + 6] = 0;
        sub_401220(FindFileData.cFileName, v3, Key);
        ++v6;
    } while (FindNextFileA(hFindFile, &FindFileData));
    if (GetLastError() != ERROR_NO_MORE_FILES)
        Ransom_HandleError("FindNextFile");
    sub_401160(v6);
    return v6 != 0;
}

// start @ 00401460 : main
int main()
{
    UINT uExitCode;
    CHAR Key[9];
    DWORD NumberOfCharsRead;

    //Fill Key Buffer with Zeros
    ZeroMemory(&Key, sizeof(Key));
    //Obtain Standard Input Handle
    hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    //Obtain Standard Output Handle
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    //Customize the colors of the Console
    SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_GREEN | FOREGROUND_RED
        | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
    //Write the message to the Console
    WriteConsoleA(hConsoleOutput, Message, MESSAGE_LENGTH, NULL, NULL);
    //Read the Key from the Console. The key has a length of 8 caracters
    ReadConsoleA(hConsoleInput, Key, 8, &NumberOfCharsRead, NULL);
    //Decrypt all the files
    uExitCode = Ransom_DecryptFiles(Key);
    //Exit the process
    ExitProcess(uExitCode);
}
