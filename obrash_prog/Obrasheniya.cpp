//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("mainForm.cpp", formMain);
USEFORM("DataModule.cpp", DM); /* TDataModule: File Type */
USEFORM("InputInformation.cpp", formInputInformation);
USEFORM("Handbook.cpp", formHandbook);
USEFORM("createHandbook.cpp", formCreateHandbook);
USEFORM("searchAddresses.cpp", formSearchAddresses);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TformMain), &formMain);
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TformInputInformation), &formInputInformation);
		Application->CreateForm(__classid(TformHandbook), &formHandbook);
		Application->CreateForm(__classid(TformCreateHandbook), &formCreateHandbook);
		Application->CreateForm(__classid(TformSearchAddresses), &formSearchAddresses);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
