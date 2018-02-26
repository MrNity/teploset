//---------------------------------------------------------------------------

#ifndef HandbookH
#define HandbookH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TformHandbook : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *dbgHandbook;
	TLabel *Label1;
	TLabel *lNameHandbook;
	TButton *btnCreateHandbook;
	void __fastcall btnCreateHandbookClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformHandbook(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformHandbook *formHandbook;
//---------------------------------------------------------------------------
#endif
