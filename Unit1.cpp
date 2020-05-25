//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tf_main *f_main;
//---------------------------------------------------------------------------
__fastcall Tf_main::Tf_main(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tf_main::b_sendClick(TObject *Sender)
{
struct TinputData t;
	 t.value = 1.5;
	 t.measure = tacc;


	TDateTime* myTime = new TDateTime(Now());
	String text = myTime->FormatString("(dd.mm.yyyy")+ " " + myTime->FormatString("hh:mm:ss)") + " Я: " + e_msg->Text;

	m_chat->Lines->Add(text);

	if (e_msg->Text.Pos("ривет"))
	{
		text = "\n" + myTime->FormatString("(dd.mm.yyyy")+ " " + myTime->FormatString("hh:mm:ss)") + "Чат Бот: Привет ";
		m_chat->Lines->Add(text);
	} else if (e_msg->Text.Pos("дела?"))
	{
			text = "\n" + myTime->FormatString("(dd.mm.yyyy")+ " " + myTime->FormatString("hh:mm:ss)") + "Чат Бот: Хорошо ";
			m_chat->Lines->Add(text);
	}
}
//---------------------------------------------------------------------------

void __fastcall Tf_main::e_msgKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == '\r'){
		b_sendClick(Sender);
	}
}
//---------------------------------------------------------------------------


void __fastcall Tf_main::b_analysisClick(TObject *Sender)
{
	int p;
    int dL = 0;
	int i;
	int s;
	bool numFound = false;
	String text = m_chat->Lines->GetText();
	char* measureText[]={"", "км/ч", "км/ч2","ч"};
//text;
	String word;
	do{
		p = text.Pos(" ");
		if(p == 0){
			word = text;
		}
		else{
			word = text.SubString(1, p-1);
			text = text.SubString(p+1, text.Length());
		}

		s=word.Pos(",");
		if(s>0){
			word=word.SubString(1, s-1);
		}
		s=word.Pos(".");
		if(s>0){
		word=word.SubString(1,s-1);
		}

		if (numFound == true) {
			if (word == "км/ч") {
				inputData[dL-1].measure = tvelocity;
			}
			if (word == "км/ч2") {
				inputData[dL-1].measure = tacc;
			}
			if (word == "час" || word == "часа" || word == "часов") {
				inputData[dL-1].measure = ttime;
			}
			numFound=false;
		}
		m_chat->Lines->Add(word);
		try{
			inputData[dL].value = word.ToDouble();
			numFound = true;
			dL++;
			m_chat->Lines->Add("Число");
		}
		catch (const Exception& e)
		{
			if(word=="два"){
				inputData[dL].value=2;
				numFound=true;
				dL=dL+1;
				m_chat->Lines->Add("Число");
				}
			if(word=="час"){
				inputData[dL].value=1;
				inputData[dL].measure=ttime;
				dL=dL+1;
				m_chat->Lines->Add("Число");
			}

		}
   } while(p);

	for(i = 0; i < dL; i++){
		m_chat->Lines->Add(FloatToStr(inputData[i].value)+ " " + measureText[inputData[i].measure]);
	}

}

void __fastcall Tf_main::b_solveClick(TObject *Sender)
{
	String text = m_chat->Lines->GetText();
	int p=text.Pos("Найдите среднюю скорость");
	if(p==0){
		m_chat->Lines->Add("Нет решения");
		return;
	}
	double S, T;
	double v[10], t[10];
	int i, iv=0, it=0;
	double V;
	int dL;

	for(i = 0; i < dL; i++){
		if(inputData[i].measure==tvelocity){
			v[iv]=inputData[i].value;
			iv++;
		}
		if(inputData[i].measure==ttime){
			t[it]=inputData[i].value;
        	it++;
		}

	}
	S=t[0]*v[0]+t[1]*v[1]+t[2]*v[2];
	T=t[0]+t[1]+t[2];
	V=S/T;
	answer->Lines->Add(V);
		if(T==0){
			m_chat->Lines->Add("Error");
		}
		else{
			V=S/T;
			m_chat->Lines->Add(V);
        }

}

//---------------------------------------------------------------------------




void __fastcall Tf_main::Button1Click(TObject *Sender)
{
 ADOQuery1->Close();
ADOQuery1->SQL->Clear();
ADOQuery1->SQL->Add("SELECT * FROM `numbers` where word=:param1");
ADOQuery1->Parameters->ParamByName("param1")->Value = Edit1->Text;
ADOQuery1->Open();
AnsiString str = ADOQuery1->FieldByName("number")->AsString;
Label1->Caption = str;


}
//---------------------------------------------------------------------------


void __fastcall Tf_main::DivideClick(TObject *Sender)
{
  int p;
   int i;
   int l;
   int d;
   int c;
   int q;
   int wordBuf;

   char *measureText[] = {"неизвестная величина","деталей","час"};
	String text = m_chat->Lines->GetText();
	String word;
	String punct = NULL;
	words = (char**) 0;
	words = NULL;
	puncts = NULL;
	words_number = 0;
	char *pc = NULL;
	do{
			p = text.Pos(" ");
			if(p == 0){
				word = text;
				d = word.Pos(".");
				q = word.Pos("?");
				if (d != 0) {
					punct = word.SubString(d,d);
					word = text.SubString(1, d-1);
				}
				 else if (q != 0) {
					punct = word.SubString(q,q);
					word = text.SubString(1, q-1);
				}
			}
			else{
				word = text.SubString(1, p-1);
				text = text.SubString(p+1, text.Length());
				l = word.Length();
				c = word.Pos(",");
				d = word.Pos(".");
				//String punct;
				if (l == c || l == d) {
				punct = word.SubString(word.Length(), word.Length());
				word = word.SubString(1, word.Length()-1);
					}
				}
				pc = (char *)malloc(word.Length() + 1);
						return;

					words_number++;
					if(words == NULL){
						words = (char **)malloc(words_number * sizeof(char *));
					}
					else{
						words = (char **)realloc(words, words_number * sizeof(char *));
					}
				   //strcpy(pc, word.c_str());
					WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, word.c_str(), -1, pc,word.Length()+1 , NULL, NULL);
					words[words_number-1] = pc;
					if (punct != NULL) {
						pc = (char *)malloc(punct.Length() + 1);
						if (pc == NULL) {
							return;
					}
					words_number++;
					if(words == NULL){
						words = (char **)malloc(words_number * sizeof(char *));
					}
					else{
						words = (char **)realloc(words, words_number * sizeof(char *));
					}
				   //strcpy(pc, word.c_str());
					WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, punct.c_str(), -1, pc,punct.Length()+1 , NULL, NULL);
					words[words_number-1] = pc;
					punct = NULL;
					}

		}while(p);

		for(i = 0;i < words_number; i++){
			memo_array->Lines->Add(words[i]);
	}

   }

//---------------------------------------------------------------------------





void __fastcall Tf_main::generateClick(TObject *Sender)
{
//int p;
   //int i;
   //float result;
  // int SC;
   //bool numFound = false;
   //char *measureText[] = {"неизвестная величина","деталей","час"};
	   //	randomize();
	   //	memo_mass->Text= " ";
   //for(i = 0;i < words_number; i++){
	 //	SC=sscanf(words[i],"%f",&result);
  // if(SC>0){
		//memo_mass->Text=memo_mass->Text+ rand()%100 + " ";
	  }else {
		//memo_mass->Text=memo_mass->Text+ words[i] + " ";

		// ADOQuery1->Close();
		//ADOQuery1->SQL->Clear();
		//ADOQuery1->SQL->Add("SELECT * FROM `numbers` where word=:param1");
		//ADOQuery1->Parameters->ParamByName("param1")->Value = Edit1->Text;
	   //	ADOQuery1->Open();
		//AnsiString str = ADOQuery1->FieldByName("number")->AsString;
		//Label1->Caption = str;


}
	  }

   }


//---------------------------------------------------------------------------

