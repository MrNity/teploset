//---------------------------------------------------------------------------

#ifndef createHandbookH
#define createHandbookH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TformCreateHandbook : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *btnCreateHandbook;
	TEdit *edtNameHandbook;
	void __fastcall btnCreateHandbookClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformCreateHandbook(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformCreateHandbook *formCreateHandbook;
//---------------------------------------------------------------------------
#endif
