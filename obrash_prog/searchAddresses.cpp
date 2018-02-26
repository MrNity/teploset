//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "searchAddresses.h"
#include "DataModule.h"
#include "Func.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformSearchAddresses *formSearchAddresses;
//---------------------------------------------------------------------------
__fastcall TformSearchAddresses::TformSearchAddresses(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformSearchAddresses::btnSearchAddressClick(TObject *Sender)
{
	int count;
	if (edtAddress != "") {
		DM->adtRegistControlCard->Filtered = false;
		DM->adtRegistControlCard->Filter = "����� LIKE '%" + edtAddress->Text + "%'";
		DM->adtRegistControlCard->Filtered = true;
		count = DM->adtRegistControlCard->RecordCount;
	}
	else {
		DM->adtRegistControlCard->Filtered = false;
    }
	DM->adtRegistControlCard->Sort = "�����";
	if (count != 0)
		sb->Panels->Items[0]->Text = "������� �������: " + IntToStr(count);
	else
		sb->Panels->Items[0]->Text = "�� ������� �������!";
}
//---------------------------------------------------------------------------
void __fastcall TformSearchAddresses::FormShow(TObject *Sender)
{
	DM->adtRegistControlCard->Sort = "�����";
}
//---------------------------------------------------------------------------
void __fastcall TformSearchAddresses::edtAddressChange(TObject *Sender)
{
	SearchAddress(edtAddress->Text);

	int count = DM->adtRegistControlCard->RecordCount;

	if (count != 0)
		sb->Panels->Items[0]->Text = "������� �������: " + IntToStr(count);
	else
		sb->Panels->Items[0]->Text = "�� ������� �������!";
}
//---------------------------------------------------------------------------
