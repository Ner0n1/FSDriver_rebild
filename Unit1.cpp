//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	BYTE buff[512];
	NTFS *BootRec = (NTFS*)buff;

	HANDLE handle = CreateFileW(L"\\\\.\\C:",GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
	NULL);

	if (handle == INVALID_HANDLE_VALUE)
	{
		Label1 -> Caption = L"Can't open FS!";
		return void();
	}

    LARGE_INTEGER offset;
	offset.QuadPart = 0;

	unsigned long pos = SetFilePointer(handle,offset.LowPart,&offset.HighPart,
	FILE_BEGIN);

	if (pos != offset.LowPart)
	{
		Label1 -> Caption = L"Error while seting position!";
		return void();
	}

	DWORD toRead = 512;
	DWORD Read;

	bool res = ReadFile(handle,buff,toRead,&Read,NULL);

	if(res == false || Read != toRead)
	{
		Label1 -> Caption = L"Error while reading bytes!";
		return void();
	}

	Memo1 -> Clear();
	Memo1 -> Lines -> Add(L"OEM name " + UnicodeString(BootRec -> OEM));
	Memo1 -> Lines -> Add(L"Byte per sector " +
	UnicodeString(BootRec -> BytesInSec));
	Memo1 -> Lines -> Add(L"Sector per cluster " + UnicodeString(
	BootRec -> SecInCluster));
	Memo1 -> Lines -> Add(L"Sectors per track " +
	UnicodeString(BootRec -> SectorsPerTrack));
	Memo1 -> Lines -> Add(L"Number of heads " +
	UnicodeString(BootRec -> NumberOfHeads));
	Memo1 -> Lines -> Add(L"Number of sectors " +
	UnicodeString(BootRec -> NumberOfSectors));
	Memo1 -> Lines -> Add(L"MFT begin's cluster number " +
	UnicodeString(BootRec -> MFTClusterNumber));
	Memo1 -> Lines -> Add(L"MFT copy begin's cluster number " +
	UnicodeString(BootRec -> CopyMFTClusterNumber));
	Memo1 -> Lines -> Add(L"Size of MFT " + UnicodeString(BootRec -> MFTSize));
	Memo1 -> Lines -> Add(L"Serial number " +
	UnicodeString(BootRec -> SerialNumber));
	Memo1 -> Lines -> Add(L"CheckSum " + UnicodeString(BootRec -> Checksum));

	Label1 -> Caption = L"Reading FS is Success!";
	CloseHandle(handle);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1 -> Clear();
}
//---------------------------------------------------------------------------
