//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <windows.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
 #pragma pack(push,1)

 typedef struct
{
	BYTE indent1[3];
	char OEM[8];
	USHORT BytesInSec;
	BYTE SecInCluster;
	BYTE indent2[10];
	UINT16 SectorsPerTrack;
	UINT16 NumberOfHeads;
	BYTE indent3[12];
	ULONGLONG NumberOfSectors;
	ULONGLONG MFTClusterNumber;
	ULONGLONG CopyMFTClusterNumber;
	UINT MFTSize;
	UINT BuffSize;
	BYTE indent4[3];
	ULONGLONG SerialNumber;
	USHORT Checksum;
} NTFS;
# pragma pack(pop)

#endif
