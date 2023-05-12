//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <cmath>
#include <string>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const double PI = 3.14159265358979323846;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

bool __fastcall TForm1::CheckForm() {
	if (LabeledEdit1->Text != "" && LabeledEdit2->Text != "" &&
		LabeledEdit3->Text != "" && LabeledEdit4->Text != "" &&
		LabeledEdit5->Text != "" && LabeledEdit6->Text != "" &&
		ComboBox1->ItemIndex != -1) {
			return true;
	} else {
        return false;
	}
}
double __fastcall TForm1::GetFromMaterial() {
	switch(ComboBox1->ItemIndex) {
		case 0: return 2600;
		case 1: return 25;
		case 2: return 450;
		case 3: return 7870;
        default: return 2600;
    }
}
struct Coord {
	double x, y;
};
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (CheckForm()) {
		bool withEnv = CheckBox1->Checked;
        int n = 80;

		double a3 = StrToInt(LabeledEdit1->Text);
		double a4 = StrToInt(LabeledEdit2->Text);
		double a5 = StrToInt(LabeledEdit3->Text);
		double a6 = StrToInt(LabeledEdit4->Text);
		double a7 = GetFromMaterial();
		double a8 = withEnv ? StrToInt(LabeledEdit5->Text) : 0;
		double a9 = withEnv ? StrToInt(LabeledEdit6->Text) : 0;

		double e3 = 0;
		double f3 = a3*cos(a4*PI/180);
		double g3 = a3*sin(a4*PI/180);
		double h3 = (4.5*a9/a6+0.15*a8*sqrt(f3*f3+g3*g3))/(a7*a6);
		double i3 = 0;
		double j3 = 0;

		double e4 = e3 + a5;
		double f4 = j3 < 0 ? 0 : (1-h3*a5)*f3;
		double g4 = (a8/a7-1)*9.81*a5+(1-h3*a5)*g3;
		double h4 = (4.5*a9/a6+0.15*a8*sqrt(f4*f4+g4*g4))/(a7*a6);
		double i4 = i3 + (f4 == 0 ? 0 : f3*a5);
		double j4 = j3 + (f4 == 0 ? 0 : g3*a5);



		while (i4 < 80) {
            Series1->AddXY(i4, j4, "", clBlue);

			e4 = e3 + a5;
			f4 = j3 < 0 ? 0 : (1-h3*a5)*f3;
			g4 = (a8/a7-1)*9.81*a5+(1-h3*a5)*g3;
			h4 = (4.5*a9/a6+0.15*a8*sqrt(f4*f4+g4*g4))/(a7*a6);
			i4 = i3 + (f4 == 0 ? 0 : f3*a5);
			j4 = j3 + (f4 == 0 ? 0 : g3*a5);
        }
	} else {
        ShowMessage("Some form fields are empty!");
    }
}
//---------------------------------------------------------------------------
