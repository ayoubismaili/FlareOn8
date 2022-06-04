//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

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

//byte_404000
//.Right. Off you go. #
unsigned char RightOffYouGo[21] = {
	0x00, 0xEC, 0xD7, 0xD9, 0xD6, 0xCA, 0x90, 0x9E, 0xF1, 0xD8, 0xD8, 0x9E,
	0xC7, 0xD1, 0xCB, 0x9E, 0xD9, 0xD1, 0x90, 0x9E, 0x9D
};

//byte_404060
//.Consult the Book of Armaments!
unsigned char ConsultBookOfArmaments[32] = {
	0x00, 0xF1, 0xDD, 0xDC, 0xC1, 0xC7, 0xDE, 0xC6, 0x92, 0xC6, 0xDA, 0xD7,
	0x92, 0xF0, 0xDD, 0xDD, 0xD9, 0x92, 0xDD, 0xD4, 0x92, 0xF3, 0xC0, 0xDF,
	0xD3, 0xDF, 0xD7, 0xDC, 0xC6, 0xC1, 0x93, 0xB8
};

//
//.Available commands:  help: print this help
unsigned char AvailableCommandsHelp[43] = {
	0x00, 0xD4, 0xE3, 0xF4, 0xFC, 0xF9, 0xF4, 0xF7, 0xF9, 0xF0, 0xB5, 0xF6,
	0xFA, 0xF8, 0xF8, 0xF4, 0xFB, 0xF1, 0xE6, 0xAF, 0x9F, 0xFD, 0xF0, 0xF9,
	0xE5, 0xAF, 0xB5, 0xE5, 0xE7, 0xFC, 0xFB, 0xE1, 0xB5, 0xE1, 0xFD, 0xFC,
	0xE6, 0xB5, 0xFD, 0xF0, 0xF9, 0xE5, 0x9F
};

//dword_402260 : Crc32_Table
unsigned char Crc32_Table[1024] = {
	0x00, 0x00, 0x00, 0x00, 0x96, 0x30, 0x07, 0x77, 0x2C, 0x61, 0x0E, 0xEE,
	0xBA, 0x51, 0x09, 0x99, 0x19, 0xC4, 0x6D, 0x07, 0x8F, 0xF4, 0x6A, 0x70,
	0x35, 0xA5, 0x63, 0xE9, 0xA3, 0x95, 0x64, 0x9E, 0x32, 0x88, 0xDB, 0x0E,
	0xA4, 0xB8, 0xDC, 0x79, 0x1E, 0xE9, 0xD5, 0xE0, 0x88, 0xD9, 0xD2, 0x97,
	0x2B, 0x4C, 0xB6, 0x09, 0xBD, 0x7C, 0xB1, 0x7E, 0x07, 0x2D, 0xB8, 0xE7,
	0x91, 0x1D, 0xBF, 0x90, 0x64, 0x10, 0xB7, 0x1D, 0xF2, 0x20, 0xB0, 0x6A,
	0x48, 0x71, 0xB9, 0xF3, 0xDE, 0x41, 0xBE, 0x84, 0x7D, 0xD4, 0xDA, 0x1A,
	0xEB, 0xE4, 0xDD, 0x6D, 0x51, 0xB5, 0xD4, 0xF4, 0xC7, 0x85, 0xD3, 0x83,
	0x56, 0x98, 0x6C, 0x13, 0xC0, 0xA8, 0x6B, 0x64, 0x7A, 0xF9, 0x62, 0xFD,
	0xEC, 0xC9, 0x65, 0x8A, 0x4F, 0x5C, 0x01, 0x14, 0xD9, 0x6C, 0x06, 0x63,
	0x63, 0x3D, 0x0F, 0xFA, 0xF5, 0x0D, 0x08, 0x8D, 0xC8, 0x20, 0x6E, 0x3B,
	0x5E, 0x10, 0x69, 0x4C, 0xE4, 0x41, 0x60, 0xD5, 0x72, 0x71, 0x67, 0xA2,
	0xD1, 0xE4, 0x03, 0x3C, 0x47, 0xD4, 0x04, 0x4B, 0xFD, 0x85, 0x0D, 0xD2,
	0x6B, 0xB5, 0x0A, 0xA5, 0xFA, 0xA8, 0xB5, 0x35, 0x6C, 0x98, 0xB2, 0x42,
	0xD6, 0xC9, 0xBB, 0xDB, 0x40, 0xF9, 0xBC, 0xAC, 0xE3, 0x6C, 0xD8, 0x32,
	0x75, 0x5C, 0xDF, 0x45, 0xCF, 0x0D, 0xD6, 0xDC, 0x59, 0x3D, 0xD1, 0xAB,
	0xAC, 0x30, 0xD9, 0x26, 0x3A, 0x00, 0xDE, 0x51, 0x80, 0x51, 0xD7, 0xC8,
	0x16, 0x61, 0xD0, 0xBF, 0xB5, 0xF4, 0xB4, 0x21, 0x23, 0xC4, 0xB3, 0x56,
	0x99, 0x95, 0xBA, 0xCF, 0x0F, 0xA5, 0xBD, 0xB8, 0x9E, 0xB8, 0x02, 0x28,
	0x08, 0x88, 0x05, 0x5F, 0xB2, 0xD9, 0x0C, 0xC6, 0x24, 0xE9, 0x0B, 0xB1,
	0x87, 0x7C, 0x6F, 0x2F, 0x11, 0x4C, 0x68, 0x58, 0xAB, 0x1D, 0x61, 0xC1,
	0x3D, 0x2D, 0x66, 0xB6, 0x90, 0x41, 0xDC, 0x76, 0x06, 0x71, 0xDB, 0x01,
	0xBC, 0x20, 0xD2, 0x98, 0x2A, 0x10, 0xD5, 0xEF, 0x89, 0x85, 0xB1, 0x71,
	0x1F, 0xB5, 0xB6, 0x06, 0xA5, 0xE4, 0xBF, 0x9F, 0x33, 0xD4, 0xB8, 0xE8,
	0xA2, 0xC9, 0x07, 0x78, 0x34, 0xF9, 0x00, 0x0F, 0x8E, 0xA8, 0x09, 0x96,
	0x18, 0x98, 0x0E, 0xE1, 0xBB, 0x0D, 0x6A, 0x7F, 0x2D, 0x3D, 0x6D, 0x08,
	0x97, 0x6C, 0x64, 0x91, 0x01, 0x5C, 0x63, 0xE6, 0xF4, 0x51, 0x6B, 0x6B,
	0x62, 0x61, 0x6C, 0x1C, 0xD8, 0x30, 0x65, 0x85, 0x4E, 0x00, 0x62, 0xF2,
	0xED, 0x95, 0x06, 0x6C, 0x7B, 0xA5, 0x01, 0x1B, 0xC1, 0xF4, 0x08, 0x82,
	0x57, 0xC4, 0x0F, 0xF5, 0xC6, 0xD9, 0xB0, 0x65, 0x50, 0xE9, 0xB7, 0x12,
	0xEA, 0xB8, 0xBE, 0x8B, 0x7C, 0x88, 0xB9, 0xFC, 0xDF, 0x1D, 0xDD, 0x62,
	0x49, 0x2D, 0xDA, 0x15, 0xF3, 0x7C, 0xD3, 0x8C, 0x65, 0x4C, 0xD4, 0xFB,
	0x58, 0x61, 0xB2, 0x4D, 0xCE, 0x51, 0xB5, 0x3A, 0x74, 0x00, 0xBC, 0xA3,
	0xE2, 0x30, 0xBB, 0xD4, 0x41, 0xA5, 0xDF, 0x4A, 0xD7, 0x95, 0xD8, 0x3D,
	0x6D, 0xC4, 0xD1, 0xA4, 0xFB, 0xF4, 0xD6, 0xD3, 0x6A, 0xE9, 0x69, 0x43,
	0xFC, 0xD9, 0x6E, 0x34, 0x46, 0x88, 0x67, 0xAD, 0xD0, 0xB8, 0x60, 0xDA,
	0x73, 0x2D, 0x04, 0x44, 0xE5, 0x1D, 0x03, 0x33, 0x5F, 0x4C, 0x0A, 0xAA,
	0xC9, 0x7C, 0x0D, 0xDD, 0x3C, 0x71, 0x05, 0x50, 0xAA, 0x41, 0x02, 0x27,
	0x10, 0x10, 0x0B, 0xBE, 0x86, 0x20, 0x0C, 0xC9, 0x25, 0xB5, 0x68, 0x57,
	0xB3, 0x85, 0x6F, 0x20, 0x09, 0xD4, 0x66, 0xB9, 0x9F, 0xE4, 0x61, 0xCE,
	0x0E, 0xF9, 0xDE, 0x5E, 0x98, 0xC9, 0xD9, 0x29, 0x22, 0x98, 0xD0, 0xB0,
	0xB4, 0xA8, 0xD7, 0xC7, 0x17, 0x3D, 0xB3, 0x59, 0x81, 0x0D, 0xB4, 0x2E,
	0x3B, 0x5C, 0xBD, 0xB7, 0xAD, 0x6C, 0xBA, 0xC0, 0x20, 0x83, 0xB8, 0xED,
	0xB6, 0xB3, 0xBF, 0x9A, 0x0C, 0xE2, 0xB6, 0x03, 0x9A, 0xD2, 0xB1, 0x74,
	0x39, 0x47, 0xD5, 0xEA, 0xAF, 0x77, 0xD2, 0x9D, 0x15, 0x26, 0xDB, 0x04,
	0x83, 0x16, 0xDC, 0x73, 0x12, 0x0B, 0x63, 0xE3, 0x84, 0x3B, 0x64, 0x94,
	0x3E, 0x6A, 0x6D, 0x0D, 0xA8, 0x5A, 0x6A, 0x7A, 0x0B, 0xCF, 0x0E, 0xE4,
	0x9D, 0xFF, 0x09, 0x93, 0x27, 0xAE, 0x00, 0x0A, 0xB1, 0x9E, 0x07, 0x7D,
	0x44, 0x93, 0x0F, 0xF0, 0xD2, 0xA3, 0x08, 0x87, 0x68, 0xF2, 0x01, 0x1E,
	0xFE, 0xC2, 0x06, 0x69, 0x5D, 0x57, 0x62, 0xF7, 0xCB, 0x67, 0x65, 0x80,
	0x71, 0x36, 0x6C, 0x19, 0xE7, 0x06, 0x6B, 0x6E, 0x76, 0x1B, 0xD4, 0xFE,
	0xE0, 0x2B, 0xD3, 0x89, 0x5A, 0x7A, 0xDA, 0x10, 0xCC, 0x4A, 0xDD, 0x67,
	0x6F, 0xDF, 0xB9, 0xF9, 0xF9, 0xEF, 0xBE, 0x8E, 0x43, 0xBE, 0xB7, 0x17,
	0xD5, 0x8E, 0xB0, 0x60, 0xE8, 0xA3, 0xD6, 0xD6, 0x7E, 0x93, 0xD1, 0xA1,
	0xC4, 0xC2, 0xD8, 0x38, 0x52, 0xF2, 0xDF, 0x4F, 0xF1, 0x67, 0xBB, 0xD1,
	0x67, 0x57, 0xBC, 0xA6, 0xDD, 0x06, 0xB5, 0x3F, 0x4B, 0x36, 0xB2, 0x48,
	0xDA, 0x2B, 0x0D, 0xD8, 0x4C, 0x1B, 0x0A, 0xAF, 0xF6, 0x4A, 0x03, 0x36,
	0x60, 0x7A, 0x04, 0x41, 0xC3, 0xEF, 0x60, 0xDF, 0x55, 0xDF, 0x67, 0xA8,
	0xEF, 0x8E, 0x6E, 0x31, 0x79, 0xBE, 0x69, 0x46, 0x8C, 0xB3, 0x61, 0xCB,
	0x1A, 0x83, 0x66, 0xBC, 0xA0, 0xD2, 0x6F, 0x25, 0x36, 0xE2, 0x68, 0x52,
	0x95, 0x77, 0x0C, 0xCC, 0x03, 0x47, 0x0B, 0xBB, 0xB9, 0x16, 0x02, 0x22,
	0x2F, 0x26, 0x05, 0x55, 0xBE, 0x3B, 0xBA, 0xC5, 0x28, 0x0B, 0xBD, 0xB2,
	0x92, 0x5A, 0xB4, 0x2B, 0x04, 0x6A, 0xB3, 0x5C, 0xA7, 0xFF, 0xD7, 0xC2,
	0x31, 0xCF, 0xD0, 0xB5, 0x8B, 0x9E, 0xD9, 0x2C, 0x1D, 0xAE, 0xDE, 0x5B,
	0xB0, 0xC2, 0x64, 0x9B, 0x26, 0xF2, 0x63, 0xEC, 0x9C, 0xA3, 0x6A, 0x75,
	0x0A, 0x93, 0x6D, 0x02, 0xA9, 0x06, 0x09, 0x9C, 0x3F, 0x36, 0x0E, 0xEB,
	0x85, 0x67, 0x07, 0x72, 0x13, 0x57, 0x00, 0x05, 0x82, 0x4A, 0xBF, 0x95,
	0x14, 0x7A, 0xB8, 0xE2, 0xAE, 0x2B, 0xB1, 0x7B, 0x38, 0x1B, 0xB6, 0x0C,
	0x9B, 0x8E, 0xD2, 0x92, 0x0D, 0xBE, 0xD5, 0xE5, 0xB7, 0xEF, 0xDC, 0x7C,
	0x21, 0xDF, 0xDB, 0x0B, 0xD4, 0xD2, 0xD3, 0x86, 0x42, 0xE2, 0xD4, 0xF1,
	0xF8, 0xB3, 0xDD, 0x68, 0x6E, 0x83, 0xDA, 0x1F, 0xCD, 0x16, 0xBE, 0x81,
	0x5B, 0x26, 0xB9, 0xF6, 0xE1, 0x77, 0xB0, 0x6F, 0x77, 0x47, 0xB7, 0x18,
	0xE6, 0x5A, 0x08, 0x88, 0x70, 0x6A, 0x0F, 0xFF, 0xCA, 0x3B, 0x06, 0x66,
	0x5C, 0x0B, 0x01, 0x11, 0xFF, 0x9E, 0x65, 0x8F, 0x69, 0xAE, 0x62, 0xF8,
	0xD3, 0xFF, 0x6B, 0x61, 0x45, 0xCF, 0x6C, 0x16, 0x78, 0xE2, 0x0A, 0xA0,
	0xEE, 0xD2, 0x0D, 0xD7, 0x54, 0x83, 0x04, 0x4E, 0xC2, 0xB3, 0x03, 0x39,
	0x61, 0x26, 0x67, 0xA7, 0xF7, 0x16, 0x60, 0xD0, 0x4D, 0x47, 0x69, 0x49,
	0xDB, 0x77, 0x6E, 0x3E, 0x4A, 0x6A, 0xD1, 0xAE, 0xDC, 0x5A, 0xD6, 0xD9,
	0x66, 0x0B, 0xDF, 0x40, 0xF0, 0x3B, 0xD8, 0x37, 0x53, 0xAE, 0xBC, 0xA9,
	0xC5, 0x9E, 0xBB, 0xDE, 0x7F, 0xCF, 0xB2, 0x47, 0xE9, 0xFF, 0xB5, 0x30,
	0x1C, 0xF2, 0xBD, 0xBD, 0x8A, 0xC2, 0xBA, 0xCA, 0x30, 0x93, 0xB3, 0x53,
	0xA6, 0xA3, 0xB4, 0x24, 0x05, 0x36, 0xD0, 0xBA, 0x93, 0x06, 0xD7, 0xCD,
	0x29, 0x57, 0xDE, 0x54, 0xBF, 0x67, 0xD9, 0x23, 0x2E, 0x7A, 0x66, 0xB3,
	0xB8, 0x4A, 0x61, 0xC4, 0x02, 0x1B, 0x68, 0x5D, 0x94, 0x2B, 0x6F, 0x2A,
	0x37, 0xBE, 0x0B, 0xB4, 0xA1, 0x8E, 0x0C, 0xC3, 0x1B, 0xDF, 0x05, 0x5A,
	0x8D, 0xEF, 0x02, 0x2D
};


//unk_402000
unsigned char AntiOS_Records[360] = {
	0xA9, 0x95, 0x93, 0xB5, 0x29, 0xAB, 0xB5, 0x1B, 0x0E, 0x00, 0x00, 0x00, /* Bridge Keeper */
//unk_40200C
	0x4B, 0xD0, 0xFD, 0x5E, 0xC8, 0x68, 0x84, 0x3F, 0x12, 0x00, 0x00, 0x00, /* Sir Lancelot */
	0xD0, 0x85, 0xED, 0xEC, 0x48, 0x3D, 0xD2, 0x82, 0x02, 0x00, 0x00, 0x00, /* Sir Bors */
	0x14, 0x92, 0x54, 0xD8, 0xE5, 0x2E, 0x47, 0x00, 0x1D, 0x00, 0x00, 0x00, /* Black Knight */
	0x4D, 0x02, 0x2F, 0x2C, 0xAA, 0x60, 0xA0, 0xC9, 0x0C, 0x00, 0x00, 0x00, /* Chicken of Bristol */
	0x32, 0x52, 0x8A, 0x01, 0x35, 0xD2, 0x24, 0x00, 0x0D, 0x00, 0x00, 0x00, /* Roger the Shrubber */
	0x33, 0x8A, 0xB8, 0x72, 0x13, 0x66, 0x57, 0x81, 0x14, 0x00, 0x00, 0x00, /* Rabbit of Caerbannog */
	0xE2, 0x04, 0x44, 0x67, 0x29, 0xE1, 0x69, 0x51, 0x0B, 0x00, 0x00, 0x00, /* Trojan Rabbit */
	0xB5, 0x73, 0x7A, 0x30, 0x3E, 0xE1, 0x60, 0xE5, 0x1C, 0x00, 0x00, 0x00, /* Dinky */
	0x04, 0x87, 0x46, 0x13, 0xA9, 0xE4, 0x58, 0x23, 0x15, 0x00, 0x00, 0x00, /* Sir Not-Appearing-in-this-Film */
	0x1B, 0x47, 0xF6, 0x94, 0x53, 0x1A, 0x34, 0xD6, 0x05, 0x00, 0x00, 0x00, /* Brother Maynard */
	0x75, 0xCF, 0xA1, 0xED, 0xE5, 0x91, 0xFA, 0xBA, 0x18, 0x00, 0x00, 0x00, /* Inspector End Of Film */
	0x4D, 0x12, 0xAC, 0xBB, 0x1D, 0x64, 0x97, 0xA6, 0x19, 0x00, 0x00, 0x00, /* Sir Ector */
	0xC3, 0xE4, 0x07, 0xF7, 0x43, 0x56, 0x18, 0xEF, 0x07, 0x00, 0x00, 0x00, /* Sir Robin */
	0x6F, 0x59, 0x02, 0xD7, 0x15, 0x89, 0xC2, 0x79, 0x0A, 0x00, 0x00, 0x00, /* Green Knight */
	0x48, 0x08, 0xA1, 0x86, 0xDC, 0x8F, 0x10, 0x59, 0x01, 0x00, 0x00, 0x00, /* Miss Islington */
	0x1C, 0x53, 0x40, 0xD6, 0xE8, 0xE1, 0x3D, 0xEF, 0x13, 0x00, 0x00, 0x00, /* Lady of the Lake */
	0xB3, 0x5D, 0x66, 0x7B, 0xB0, 0x03, 0xA9, 0xA3, 0x03, 0x00, 0x00, 0x00, /* Tim the Enchanter */
	0xCC, 0x21, 0x13, 0xAB, 0xD7, 0xEA, 0xED, 0xEE, 0x04, 0x00, 0x00, 0x00, /* Dragon of Angnor */
	0xD8, 0x66, 0x60, 0x4F, 0x07, 0x3D, 0x8A, 0x9C, 0x11, 0x00, 0x00, 0x00, /* A Famous Historian */
	0xCA, 0x47, 0x60, 0x25, 0x9E, 0xBE, 0x85, 0x40, 0x09, 0x00, 0x00, 0x00, /* Squire Concorde */
	0xD3, 0x1E, 0xC9, 0x3F, 0xC9, 0x49, 0x95, 0x37, 0x08, 0x00, 0x00, 0x00, /* Zoot */
	0xE4, 0xAF, 0x24, 0xA4, 0x47, 0x13, 0x87, 0xEF, 0x1B, 0x00, 0x00, 0x00, /* Dennis the Peasant */
	0xDA, 0x01, 0x09, 0x55, 0x6B, 0xEC, 0xFC, 0x01, 0x10, 0x00, 0x00, 0x00, /* Legendary Black Beast of Argh */
	0x2D, 0x9E, 0xA2, 0x10, 0xAA, 0x56, 0x60, 0xE7, 0x16, 0x00, 0x00, 0x00, /* Prince Herbert */
	0x5F, 0xC8, 0xCB, 0x56, 0x68, 0x1A, 0x6F, 0x35, 0x0F, 0x00, 0x00, 0x00, /* Sir Gawain */
	0xA6, 0xE3, 0xDF, 0x80, 0x36, 0xB5, 0x0A, 0x9D, 0x1E, 0x00, 0x00, 0x00, /* Sir Gallahad */
	0xE1, 0xD4, 0x57, 0xE6, 0x30, 0xFD, 0xE9, 0xB4, 0x17, 0x00, 0x00, 0x00, /* King Arthur */
	0xD4, 0xE1, 0xA1, 0x2B, 0x18, 0xD9, 0x66, 0xBE, 0x1A, 0x00, 0x00, 0x00, /* Squire Patsy */
	0x9B, 0x08, 0x33, 0x7D, 0x85, 0xF5, 0xC1, 0x67, 0x06, 0x00, 0x00, 0x00  /* Sir Bedevere */
};

#define VERSION_STRING_LENGTH   37
#define TYPE_HELP_STRING_LENGTH 19
#define APPROACH_STRING_LENGTH  9
#define CONSULT_STRING_LENGTH   8
#define HELP_STRING_LENGTH      5
#define QUIT_STRING_LENGTH      5
#define PROMPT_STRING_LENGTH    2

#define READ_BUFFER_LENGTH      128

#define MAX_ANTIOS_RECORDS      30

typedef struct _ANTIOS_RECORD
{
	unsigned int nameCrc;
	unsigned int colorCrc;
	unsigned int next;
} ANTIOS_RECORD, *PANTIOS_RECORD;

#define SIZEOF_ANTIOS_RECORD sizeof(ANTIOS_RECORD)

// xmmword_404100
unsigned char AntiOS_AsciiBlock[256];

// xmmword_402240
unsigned char AntiOS_AsciiInit[16] = {
	0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E,
	0x2E, 0x2E, 0x2E, 0x2E
};

#define ANTIOS_ASCII_ART_LENGTH 4096

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

// sub_4012A0 : Anti_GetRightOffYouGo
void* Anti_GetRightOffYouGo()
{
	unsigned char val;
	unsigned char* ptr;

	//The first byte of the string indicates if the string was already decrypted
	val = RightOffYouGo[0];
	if (!RightOffYouGo[0])
	{
		//Decrypt the string
		for (ptr = RightOffYouGo; ptr < (RightOffYouGo + 21); val = *ptr)
		{
			*ptr++ = val ^ 0xBE;
		}
	}
	//Return the string but skip the first byte
	return &RightOffYouGo[1];
}

// sub_4010E0 : Anti_GetConsultBookOfArmaments
void* Anti_GetConsultBookOfArmaments()
{
	unsigned char val;
	unsigned char* ptr;

	//The first byte of the string indicates if the string was already decrypted
	val = ConsultBookOfArmaments[0];
	if (!ConsultBookOfArmaments[0])
	{
		//Decrypt the string
		for (ptr = ConsultBookOfArmaments; ptr < (ConsultBookOfArmaments + 32); val = *ptr)
		{
			*ptr++ = val ^ 0xB2;
		}
	}
	//Return the string but skip the first byte
	return &ConsultBookOfArmaments[1];
}

// sub_4010A0 : Anti_GetAvailableCommandsHelp
void* Anti_GetAvailableCommandsHelp()
{
	unsigned char val;
	unsigned char* ptr;

	//The first byte of the string indicates if the string was already decrypted
	val = AvailableCommandsHelp[0];
	if (!AvailableCommandsHelp[0])
	{
		//Decrypt the string
		for (ptr = AvailableCommandsHelp; ptr < (AvailableCommandsHelp + 43); val = *ptr)
		{
			*ptr++ = val ^ 0x95;
		}
	}
	//Return the string but skip the first byte
	return &AvailableCommandsHelp[1];
}

// sub_4012E0 : Anti_GetTypeHelpMessage
void Anti_GetTypeHelpMessage(char* Output)
{
	strcpy(Output, "Type help for help\n");
}

// sub_401340 : Anti_GetQuitString
void Anti_GetQuitString(char* Output)
{
	strcpy(Output, "quit\n");
}

// sub_401360 : Anti_GetHelpString
void Anti_GetHelpString(char* Output)
{
	strcpy(Output, "help\n");
}

// sub_401380 : Anti_GetConsultString
void Anti_GetConsultString(char* Output)
{
	strcpy(Output, "consult\n");
}

// sub_4013B0 : Anti_GetApproachString
void Anti_GetApproachString(char* Output)
{
	strcpy(Output, "approach\n");
}

// sub_401120 : Anti_GetWhatIsYourNameString
void Anti_GetWhatIsYourNameString(char* Output)
{
	strcpy(Output, "What is your name? ");
}

// sub_401180 : Anti_GetWhatIsYourQuestString
void Anti_GetWhatIsYourQuestString(char* Output)
{
	strcpy(Output, "What is your quest? ");
}

// sub_4011E0 : Anti_GetWhatIsYourFavoriteColorString
void Anti_GetWhatIsYourFavoriteColorString(char* Output)
{
	strcpy(Output, "What is your favorite color? ");
}

// sub_401980 : Anti_Syscall
int Anti_Syscall(int a1, void* a2, void* a3, void* a4)
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

// sub_4019F0 : Anti_Write <=> write
//int Anti_Write(int fd, const void* buf, size_t count)
//{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_write = 1
//	return Anti_Syscall(1, (void*)fd, (void*)buf, (void*)count);
//}

// sub_401A10 : Anti_Read <=> read
//int Anti_Read(int fd, const void* buf, size_t count)
//{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_read = 0
//	return Anti_Syscall(0, (void*)fd, (void*)buf, (void*)count);
//}

// sub_401A90 : Anti_Exit <=> _exit
//int Anti_Exit(int error_code)
//{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_exit = 60
//	return Anti_Syscall(60, (void*)error_code, (void*)0, (void*)0);
//}

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

// sub_401A50 : Anti_Select <=> select
int Anti_Select(int value)
{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_select = 23
	return Anti_Syscall(23, 0, 0, 0);
}

// sub_401B50 : Anti_Crc32
unsigned int Anti_Crc32(unsigned char* Data, int Length)
{
	unsigned char* end;
	unsigned int result;
	unsigned char val;
	unsigned int* crc32_tab = (unsigned int*) Crc32_Table;

	if (Length <= 0)
		return 0;
	end = &Data[Length];
	result = 0xFFFFFFFF;
	do
	{
		val = *Data++;
		result = crc32_tab[(unsigned char)(result ^ val)] ^ (result >> 8);
	} while (end != Data);
	return ~result;
}

// sub_401AF0 : Anti_IntToStr
unsigned char* Anti_IntToStr(unsigned int Value, unsigned char* Output)
{
	unsigned char* result;

	if (Value > 9)
		Output = Anti_IntToStr(Value / 10, Output);
	Output[1] = 0;
	result = Output + 1;
	Output[0] = Value % 10 + '0';
	return result;
}

// sub_4019D0 : Anti_Open <=> open
//int Anti_Open(const char* FileName, int Flags, int Mode)
//{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_open = 2
//	return Anti_Syscall(2, (void*)FileName, (void*)Flags, (void*)Mode);
//}

// sub_401A30 : Anti_Close <=> close
//int Anti_Close(unsigned int fd)
//{
	//https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	//https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
	//sys_close = 3
//	return Anti_Syscall(3, (void*)fd, (void*)0, (void*)0);
//}

// sub_401000 : Anti_GetAsciiArtCharset
void Anti_GetAsciiArtCharset(void* Output)
{
	memcpy(Output, "V',`)(//\\\\\\||||||||||||_______________", 38);
}

// sub_401640 : Anti_Approach
void Anti_Approach()
{
	unsigned long recordIndex;
	void* approachGorgeStr;
	int dataLength1;
	unsigned int inputNameCrc;
	unsigned int* recordPtr;
	unsigned int nameCrc;
	int dataLength2;
	unsigned int colorCrc;
	unsigned char* recordPtr2;
	//char v9;
	void* rightOffYouGoStr;
	char newLine;
	char data1[32];
	char data2[152];
	ANTIOS_RECORD *record;

	recordIndex = 0;
	newLine = '\n';
	//Obtain ApproachGorge string
	approachGorgeStr = Anti_GetApproachGorge();
	//Write to the Console
	write(STDOUT_FILENO, approachGorgeStr, 37);
	Anti_Select(1);
	//Obtain WhatIsYourName string
	Anti_GetWhatIsYourNameString(data1);
	//Write to the Console
	write(STDOUT_FILENO, data1, 19);
	//Read name from the Console
	dataLength1 = read(STDIN_FILENO, data2, 128);
	//Calculate Crc32 of the name
	inputNameCrc = Anti_Crc32((unsigned char*)data2, dataLength1);
	//Obtain a pointer to the 2nd record
	recordPtr = (unsigned int*)&AntiOS_Records[SIZEOF_ANTIOS_RECORD * 1];
	//Compare with precalculated Crc32 value
	nameCrc = 0xB59395A9;
	while (nameCrc != inputNameCrc)
	{
		recordIndex++;
		if (recordIndex == MAX_ANTIOS_RECORDS) {
			write(STDOUT_FILENO, "...AAARGH\n\n", 11);
			return;
		}
		nameCrc = *recordPtr;
		recordPtr += 3;
	}
	//Obtain WhatIsYourQuest string
	Anti_GetWhatIsYourQuestString(data1);
	//Write string to the Console
	write(STDOUT_FILENO, data1, 20);
	if (read(STDIN_FILENO, data2, 128) > 1)
	{
		//Obtain WhatIsYourFavoriteColor string
		Anti_GetWhatIsYourFavoriteColorString(data1);
		//Write string to the Console
		write(STDOUT_FILENO, data1, 29);
		//Read color string from the Console
		dataLength2 = read(STDIN_FILENO, data2, 128);
		//Calculate Crc32 of the color
		colorCrc = Anti_Crc32((unsigned char*)data2, dataLength2);
		//Obtain the pointer to the record
		recordPtr2 = &AntiOS_Records[SIZEOF_ANTIOS_RECORD * recordIndex];
		//Cast pointer to a Structure Pointer
		record = (ANTIOS_RECORD*)recordPtr2;
		//Compare Crc32 of record color with Crc32 input color
		if (record->colorCrc == colorCrc) /* This check is not needed and can be changed to always true */
		{
			//Check if the next index is greater than 0
			if (record->next > 0)
			{
				//Convert index to the next record to string
				Anti_IntToStr(record->next, (unsigned char*)data2);
				//Obtain RightOffYouGo string
				rightOffYouGoStr = Anti_GetRightOffYouGo();
				//Write message to the Console
				write(STDOUT_FILENO, rightOffYouGoStr, 20);
				//Write the next index to the Console
				write(STDOUT_FILENO, data2, strlen(data2));
				//Write new line to the Console
				write(STDOUT_FILENO, &newLine, 1);
				return;
			}
		}
	}
	//Write failure message to the Console
	write(STDOUT_FILENO, "...AAARGH\n\n", 11);
}

// sub_401460 : Anti_Consult
void Anti_Consult()
{
	int fileNameChar;
	void* consultBookOfArmamentsStr;
	int fd;
	unsigned char* incrementalPtr;
	unsigned char* filePtr;
	int i;
	unsigned char artChar;
	unsigned char fileName[8];
	unsigned char fileData[ANTIOS_ASCII_ART_LENGTH];
	unsigned char incrementalData[ANTIOS_ASCII_ART_LENGTH];

	//Initialize first file name character
	fileNameChar = 'a';
	//Copy file name
	strcpy((char*)fileName, "..dat");
	//Zero incremental data
	memset(incrementalData, 0, sizeof(incrementalData));
	//Obtain ConsultBookOfArmaments string
	consultBookOfArmamentsStr = Anti_GetConsultBookOfArmaments();
	//Write message to the Console
	write(STDOUT_FILENO, consultBookOfArmamentsStr, 31);
	Anti_Select(2);
	do
	{
		//File open loop
		while (1)
		{
			//Set the file name character
			fileName[0] = fileNameChar;
			//Try to open file
			fd = open((const char*) fileName, 0, 0); /* ?? TO CONFIRM */
			//Break if the file descriptor is valid
			if (fd >= 0)
				break;
			//Exit loops if all files was handled
			if (++fileNameChar == ('z' + 1))
				goto NO_MORE_FILES;
		}
		//Read data from file
		read(fd, fileData, ANTIOS_ASCII_ART_LENGTH);
		//Close the file
		close(fd);
		//Initialize incremental pointer
		incrementalPtr = incrementalData;
		//Initialize file pointer
		filePtr = fileData;
		//Xor file data with incremental data
		do
		{
			*incrementalPtr++ ^= *filePtr++;
		} while (incrementalPtr != &incrementalData[ANTIOS_ASCII_ART_LENGTH]);
		++fileNameChar;
	} while (fileNameChar != ('z' + 1));

NO_MORE_FILES:
	//One time initialization of AsciiBlock
	if (!AntiOS_AsciiBlock[0])
	{
		for (int j = 0; j < (16 * 16); j += 16)
		{
			//Initialize AsciiBlock
			memcpy(&AntiOS_AsciiBlock[j], AntiOS_AsciiInit, 16);
		}
		//Overwrite part of AsciiBlock data with Art Charset
		Anti_GetAsciiArtCharset(AntiOS_AsciiBlock);
	}
	for (i = 0; i != ANTIOS_ASCII_ART_LENGTH; ++i)
	{
		//Set default char to new line
		artChar = '\n';
		//Otherwise, obtain character from AsciiBlock through mapping
		if ((i & 15) != 15)
			artChar = AntiOS_AsciiBlock[incrementalData[i]];
		//Put the character in the incremental data
		incrementalData[i] = artChar;
	}
	//Write the final incremental data which represent the Ascii Art
	write(STDOUT_FILENO, incrementalData, ANTIOS_ASCII_ART_LENGTH);
}

// sub_401420 : Anti_Help
void Anti_Help()
{
	void* availableCommandsHelpStr;

	//Obtain AvailableCommandsHelp
	availableCommandsHelpStr = Anti_GetAvailableCommandsHelp();
	//Write message to the Console
	write(STDOUT_FILENO, availableCommandsHelpStr, 42);
	//Write failure message to the Console
	write(STDOUT_FILENO, "...AAARGH\n\n", 11);
}

int main()
{
	unsigned char* version;
	char command[32];
	char data[152];

	//Obtain version
	version = Anti_GetVersion();
	//Write version to the Console
	write(STDOUT_FILENO, version, VERSION_STRING_LENGTH);
	//Obtain Type Help message
	Anti_GetTypeHelpMessage(data);
	//Write Type Help message to the Console
	write(STDOUT_FILENO, data, TYPE_HELP_STRING_LENGTH);
	//Command loop
	while (1)
	{
		//Fill buffer with prompt string
		data[0] = '>';
		data[1] = ' ';
		//Write prompt string to the console
		write(STDOUT_FILENO, data, PROMPT_STRING_LENGTH);
		//Read command from the Console
		if (!read(STDIN_FILENO, data, READ_BUFFER_LENGTH))
			break;
		//Obtain quit string
		Anti_GetQuitString(command);
		//Check if command is quit
		if (!Anti_StrCmp((unsigned char*)data, (unsigned char*)command, QUIT_STRING_LENGTH))
			break;
		//Obtain help string
		Anti_GetHelpString(command);
		//Check if command is NOT help
		if (Anti_StrCmp((unsigned char*)data, (unsigned char*)command, HELP_STRING_LENGTH))
		{
			//Obtain consult string
			Anti_GetConsultString(command);
			//Check if command is NOT consult
			if (Anti_StrCmp((unsigned char*)data, (unsigned char*)command, CONSULT_STRING_LENGTH))
			{
				//Obtain approach string
				Anti_GetApproachString(command);
				//Check if command is approach
				if (!Anti_StrCmp((unsigned char*)data, (unsigned char*)command, APPROACH_STRING_LENGTH))
					//Execute approach command
					Anti_Approach();
			}
			else
			{
				//Execute consult command
				Anti_Consult();
			}
		}
		else
		{
			//Execute help command
			Anti_Help();
		}
	}
	_exit(0);
	return 0;
}
