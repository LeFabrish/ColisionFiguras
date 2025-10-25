#pragma once
#include "ControladorFiguras.h"
#include "Figura.h"
namespace ColisionFiguras {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmFiguras
	/// </summary>
	public ref class FrmFiguras : public System::Windows::Forms::Form
	{
	public:
		FrmFiguras(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			control = new ControladorFiguras;
			g = pnlDibujo->CreateGraphics();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmFiguras()
		{
			if (components)
			{
				delete components;
			}
			delete control;
		}
	private: System::Windows::Forms::Panel^ pnlDibujo;
	protected:

	protected:
	private: System::Windows::Forms::Label^ lblInstruccion;
	private: System::Windows::Forms::Button^ btnDibujar;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		ControladorFiguras* control;
	private: System::Windows::Forms::Timer^ timer1;
		   Graphics^ g;
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->pnlDibujo = (gcnew System::Windows::Forms::Panel());
			   this->lblInstruccion = (gcnew System::Windows::Forms::Label());
			   this->btnDibujar = (gcnew System::Windows::Forms::Button());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // pnlDibujo
			   // 
			   this->pnlDibujo->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->pnlDibujo->Location = System::Drawing::Point(37, 111);
			   this->pnlDibujo->Name = L"pnlDibujo";
			   this->pnlDibujo->Size = System::Drawing::Size(535, 412);
			   this->pnlDibujo->TabIndex = 0;
			   this->pnlDibujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmFiguras::pnlDibujo_Paint);
			   // 
			   // lblInstruccion
			   // 
			   this->lblInstruccion->AutoSize = true;
			   this->lblInstruccion->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblInstruccion->Location = System::Drawing::Point(0, 28);
			   this->lblInstruccion->Name = L"lblInstruccion";
			   this->lblInstruccion->Size = System::Drawing::Size(598, 63);
			   this->lblInstruccion->TabIndex = 1;
			   this->lblInstruccion->Text = L"Circulos se dibujar automaticamente y los triangulos se activaran \r\nprimero por e"
				   L"l evento click de boton \r\nsegundo por presionar la barra espacionadora (usa IA o"
				   L" pdf)";
			   // 
			   // btnDibujar
			   // 
			   this->btnDibujar->BackColor = System::Drawing::SystemColors::MenuHighlight;
			   this->btnDibujar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnDibujar->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->btnDibujar->Location = System::Drawing::Point(578, 111);
			   this->btnDibujar->Name = L"btnDibujar";
			   this->btnDibujar->Size = System::Drawing::Size(38, 412);
			   this->btnDibujar->TabIndex = 0;
			   this->btnDibujar->Text = L"T";
			   this->btnDibujar->UseVisualStyleBackColor = false;
			   this->btnDibujar->Click += gcnew System::EventHandler(this, &FrmFiguras::btnDibujar_Click);
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 50;
			   this->timer1->Tick += gcnew System::EventHandler(this, &FrmFiguras::timerMovimiento_Tick);
			   // 
			   // FrmFiguras
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(628, 552);
			   this->Controls->Add(this->btnDibujar);
			   this->Controls->Add(this->lblInstruccion);
			   this->Controls->Add(this->pnlDibujo);
			   this->Name = L"FrmFiguras";
			   this->Text = L"FrmFiguras"; 
			   this->KeyPreview = true;
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmFiguras::FrmFiguras_KeyDown);
			   this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FrmFiguras::FrmFiguras_KeyPress);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmFiguras::FrmFiguras_KeyUp);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void btnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
		//// Dibujar triangulo codigo antigup
		//int lado = 50;
		//int x = rand() % (pnlDibujo->Width - (lado));
		//int y = rand() % (pnlDibujo->Height - (lado));

		//Triangulo* t = new Triangulo(x,y);
		//control->agregarFigura(t);
	}
private: System::Void timerMovimiento_Tick(System::Object^ sender, System::EventArgs^ e) {
		control->moverFiguras(pnlDibujo->Width, pnlDibujo->Height);
		pnlDibujo ->Invalidate(); // redibuja
	}


	private: System::Void pnlDibujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Random^ r = gcnew Random;
		if (r->Next(1000) % 50 == 0) {
			int diametro = 30;

			// Evita que el círculo se salga del panel
			int x = rand() % (pnlDibujo->Width - (diametro));
			int y = rand() % (pnlDibujo->Height - (diametro));

			Circulo* c = new Circulo(x, y);
			control->agregarFigura(c);
		}
		control->dibujarFiguras(e->Graphics);
	}
private: System::Void FrmFiguras_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	// Dibujar triangulo codigo nuevo
	switch (e->KeyCode)
	{
	case Keys::Space:
		int lado = 50;
		int x = rand() % (pnlDibujo->Width - (lado));
		int y = rand() % (pnlDibujo->Height - (lado));
		Triangulo* t = new Triangulo(x, y);
		control->agregarFigura(t);
		break;
	}
}
private: System::Void FrmFiguras_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
}
private: System::Void FrmFiguras_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
}
};
}
