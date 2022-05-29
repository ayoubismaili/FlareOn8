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
#define ONLY_NEWLINE_LENGTH    1

const CHAR NumberOfFiles[] = "Number of files decoded: ";
#define NUMBER_OF_FILES_LENGTH 25

HANDLE hConsoleInput;
HANDLE hConsoleOutput;

CHAR PathName[] = "Files";
CHAR FileName[] = "*.encrypted";

#define SOURCE_FILE_EXTENSION_LENGTH 10
#define SOURCE_FILE_EXTENSION_LENGTH_NO_DOT (SOURCE_FILE_EXTENSION_LENGTH-1)

#define ROTL_BYTE(value,c) (((value)<<(c)) | ((value)>>(8-(c))))

// sub_401070 : Ransom_IntToStr
CHAR* Ransom_IntToStr(INT Value, CHAR* Destination)
{
    if (Value >= 10)
        Destination = (CHAR*)Ransom_IntToStr(Value / 10, Destination);
    //Convert a digit to ASCII value
    Destination[0] = Value % 10 + '0';
    Destination[1] = 0;
    return Destination + 1;
}

// sub_4010C0 : Ransom_HandleError
void Ransom_HandleError(const CHAR* ErrorMessage)
{
    DWORD LastError;
    DWORD ErrorMessageLength;
    DWORD LastErrorLength;
    CHAR LastErrorBuffer[12];

    //Get last error
    LastError = GetLastError();
    //Convert last error value to string
    Ransom_IntToStr(LastError, LastErrorBuffer);
    //Get string length of error message
    ErrorMessageLength = strlen(ErrorMessage);
    //Write error message to the Console
    WriteConsoleA(hConsoleOutput, ErrorMessage, ErrorMessageLength, NULL, NULL);
    //Write failed error message to the Console
    WriteConsoleA(hConsoleOutput, FailedError, FAILED_ERROR_LENGTH, NULL, NULL);
    //Get string length of last error
    LastErrorLength = strlen(LastErrorBuffer);
    //Write last error string to the Console
    WriteConsoleA(hConsoleOutput, LastErrorBuffer, LastErrorLength, NULL, NULL);
    //Write files directory message to the Console
    WriteConsoleA(hConsoleOutput, FilesDirectory, FILES_DIRECTORY_LENGTH, NULL, NULL);
    //Exit the process
    ExitProcess(1);
}

// sub_401030: Ransom_StrCpy
int Ransom_StrCpy(CHAR* Destination, CHAR* Source)
{
    int i;

    //Copy string
    for (i = 0; ; ++i)
    {
        Destination[i] = Source[i];
        if (!Source[i])
            break;
    }
    return i;
}

// sub_4011F0 : Ransom_DecryptDataBlock
VOID Ransom_DecryptDataBlock(UCHAR* DataBlock, UCHAR* Key)
{
    UINT i;
    UCHAR Value;

    //Decrypt one block of data
    for (i = 0; i < 8; i++)
    {
        Value = ROTL_BYTE(Key[i] ^ DataBlock[i], i) - i;
        DataBlock[i] = Value;
    }
}

// sub_401220 : Ransom_DecryptFile
VOID Ransom_DecryptFile(CHAR* Source, CHAR* Destination, UCHAR* Key)
{
    UCHAR DataBlock[8];
    DWORD NumberOfBytesWritten;
    HANDLE hSourceFile;
    HANDLE hDestinationFile;
    DWORD NumberOfBytesRead;
    
    //Open source file (encrypted file)
    hSourceFile = CreateFileA(Source, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hSourceFile == INVALID_HANDLE_VALUE)
        Ransom_HandleError(Source);
    //Open destination file (target file)
    hDestinationFile = CreateFileA(Destination, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hDestinationFile == INVALID_HANDLE_VALUE)
        Ransom_HandleError(Destination);
    //Decryption loop
    while (1)
    {
        //Read one block of data from source file
        if (!ReadFile(hSourceFile, DataBlock, BLOCK_SIZE, &NumberOfBytesRead, NULL))
            Ransom_HandleError(Source);
        //Check if there is more data
        if (!NumberOfBytesRead)
            break;
        //Decrypt one block of data
        Ransom_DecryptDataBlock(DataBlock, Key);
        //Write one block of data to destination file
        if (!WriteFile(hDestinationFile, DataBlock, NumberOfBytesRead, &NumberOfBytesWritten, NULL))
            Ransom_HandleError(Destination);
    }
    //Close destination file
    CloseHandle(hDestinationFile);
    //Close source file
    CloseHandle(hSourceFile);
    //Get source file name length
    NumberOfBytesRead = strlen(Source);
    //Modify destination file name
    Destination[NumberOfBytesRead - SOURCE_FILE_EXTENSION_LENGTH] = '\n';
    //Write source file name to the Console
    WriteConsoleA(hConsoleOutput, Source, NumberOfBytesRead, NULL, NULL);
    //Write arrow to the Console
    WriteConsoleA(hConsoleOutput, Arrow, ARROW_LENGTH, NULL, NULL);
    //Write modified destination file name to the Console
    WriteConsoleA(hConsoleOutput, Destination, NumberOfBytesRead - SOURCE_FILE_EXTENSION_LENGTH_NO_DOT, NULL, NULL);
}

// sub_401160 : Ransom_PrintTotal
VOID Ransom_PrintTotal(INT TotalFiles)
{
    DWORD NumberLength;
    char NumberBuffer[12];
    DWORD nNumberOfCharsToWrite;
    
    //Convert total files to String
    Ransom_IntToStr(TotalFiles, NumberBuffer);
    //Write string to Console
    WriteConsoleA(hConsoleOutput, NumberOfFiles, NUMBER_OF_FILES_LENGTH, NULL, NULL);
    //Count number of caracters in number buffer
    NumberLength = strlen(NumberBuffer);
    //Write total files to the Console
    WriteConsoleA(hConsoleOutput, NumberBuffer, NumberLength, NULL, NULL);
    //Print new line only if the total files is non-zero, otherwise print the complete message
    if (TotalFiles)
        nNumberOfCharsToWrite = ONLY_NEWLINE_LENGTH;
    else
        nNumberOfCharsToWrite = FILES_DIRECTORY_LENGTH;
    //Write string to the Console
    WriteConsoleA(hConsoleOutput, FilesDirectory, nNumberOfCharsToWrite, NULL, NULL);
}

// sub_401370 : Ransom_DecryptFiles
BOOL Ransom_DecryptFiles(UCHAR* Key) {
    struct _WIN32_FIND_DATAA FindFileData;
    CHAR cFileName[64];
    INT FileNameLength;
    HANDLE hFindFile;
    INT TotalFiles;

    TotalFiles = 0;
    //Change current directory to the Files directory
    if (!SetCurrentDirectoryA(PathName))
        Ransom_HandleError("SetCurrentDirectory(\"Files\")");
    //Get the first encrypted file having the extension .encrypted
    hFindFile = FindFirstFileA(FileName, &FindFileData);
    //Check if we got invalid handle
    if (hFindFile == INVALID_HANDLE_VALUE)
        Ransom_HandleError("FindFirstFile");
    do
    {
        //Copy file name to the local buffer and return the length of the file name
        FileNameLength = Ransom_StrCpy(cFileName, FindFileData.cFileName);
        //Remove extension from destination file
        cFileName[FileNameLength - SOURCE_FILE_EXTENSION_LENGTH] = 0;
        //Decrypt one file to the new file name using the specified key
        Ransom_DecryptFile(FindFileData.cFileName, cFileName, Key);
        //Increment file total
        ++TotalFiles;
    } while (FindNextFileA(hFindFile, &FindFileData));
    //Check if we don't have anymore files
    if (GetLastError() != ERROR_NO_MORE_FILES)
        Ransom_HandleError("FindNextFile");
    //Print the total of the files
    Ransom_PrintTotal(TotalFiles);
    //Return a boolean value indicating if at least one file was decrypted
    return TotalFiles != 0;
}

// start @ 00401460 : main
int main()
{
    UINT uExitCode;
    UCHAR Key[9];
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
