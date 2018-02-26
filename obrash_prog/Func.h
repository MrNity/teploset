#include <Handbook.h>
#include <searchAddresses.h>

void __fastcall CreateHandbook(AnsiString name) {
	DM->adq->Active = false;
	DM->adq->SQL->Clear();
	AnsiString sql;

	String n = name;
	name = StringReplace(name, " ", "_", TReplaceFlags() << rfReplaceAll);

	sql = "create table Справочник_" + name + "(";
	sql += "Код int not null unique, ";
	sql += "Название string(30), ";
	sql += "primary key(Код) );";

	DM->adq->SQL->Add(sql);
	DM->adq->ExecSQL();
	ShowMessage("Справочник "+ n + " создан");
	DM->adq->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall OpenHandbook(String handbook) {
	String hb = handbook;

	handbook = StringReplace(handbook," ","_",TReplaceFlags() << rfReplaceAll);
	DM->adtHandbook->Active = false;
	DM->adtHandbook->TableName = "Справочник_"+handbook;
	DM->adtHandbook->Active = true;

	int w = 282;
	int h;
	h = DM->adtHandbook->RecordCount * 18 + 21;

	formHandbook->lNameHandbook->Caption = "\""+ hb +"\"";

	formHandbook->dbgHandbook->Width = w;
	formHandbook->dbgHandbook->Height = h;

	formHandbook->Width = w+7;
	formHandbook->Height = h+103;

	formHandbook->Show();
}
//---------------------------------------------------------------------------
void __fastcall SearchAddress(AnsiString address){
    DM->adq->Active = false;
	DM->adq->SQL->Clear();
	AnsiString sql;

	AnsiString street, home, apt;

	street = address;
	home = address;

	street.Delete(street.Pos(" "), street.Length() - street.Pos(" ") + 1);

	home.Delete(1, home.Pos(" "));

	apt = home;
	apt.Delete(1, apt.Pos(" "));

	home.Delete(home.Pos(" "), home.Length() - home.Pos(" ") + 1);
	apt.Delete(apt.Pos(" "), apt.Length() - apt.Pos(" ") + 1);

    sql = "select ВХ_номер as 'ВХ.№', Улица, Дом, Квартира, Корреспондент, ";
	sql += "Дата_поступления, Регистрационный_индекс, Получено, Дата_отправки, ";
	sql += "Индекс_документа, Категория_заявителя, Содержание, Исполнитель, ";
	sql += "Котельная, Резолюция, Автор_резолюции as 'Автор резолюции', Контроль, ДК-1, ";
	sql += "ДК-2, ДК-3, Исх_дата as 'Исходная дата', Исх_рег_ном as 'Исходный рег.№', ";
	sql += "Отчет_выполнено as 'Выполнено', Отчет_разъяснено as 'Разъяснено'";
	sql += "from Контрольная_карточка";

	if (address != "") {
		sql += "where Улица LIKE %" + street + "%";
	}
	else {
		sql = "";
	}
	sql += "order by Улица;";

	if (sql != "") {
		DM->adq->SQL->Add(sql);
		DM->adq->Active = true;
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
