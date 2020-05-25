//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include  <stdio.h>
//---------------------------------------------------------------------------
class Tf_main : public TForm
{
__published:	// IDE-managed Components
	TButton *b_send;
	TEdit *e_msg;
	TMemo *m_chat;
	TButton *b_analysis;
	TButton *b_solve;
	TMemo *m_chat2;
	TMemo *answer;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TADOQuery *ADOQuery1;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	TButton *Divide;
	TMemo *memo_array;
	TButton *generate;

	void __fastcall b_sendClick(TObject *Sender);
	void __fastcall e_msgKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall b_analysisClick(TObject *Sender);
	void __fastcall b_solveClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DivideClick(TObject *Sender);
	void __fastcall generateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tf_main(TComponent* Owner);
	enum Tmeasure{tvelocity = 1, tacc = 2, ttime = 3} Emeasure;
	struct TinputData{
			double value;
			Tmeasure measure;
	} inputData[10];
	char **words;
	char **puncts;
	int words_number;

};
//---------------------------------------------------------------------------
extern PACKAGE Tf_main *f_main;
//---------------------------------------------------------------------------
#endif
