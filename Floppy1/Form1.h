#pragma once
#include "Floppy.h"
#include "Pipe.h"
#include <cstdlib>
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Floppy floppy = Floppy(50, 206);
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Image^ bgSprite;
		Image^ floppySprite;
		Image^ pipeTopSprite;
		Image^ pipeBottomSprite;

	public:
		Form1(void)
		{
			InitializeComponent();
			bgSprite = Image::FromFile("image\\bg.png");
			floppySprite = Image::FromFile("image\\bird.png");
			Invalidate();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(264, 461);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Floppy";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
		   //Graphics^ graphics = e->Graphics;
		   //graphics->DrawImage(bgSprite, 0, 0, bgSprite->Width, bgSprite->Height);
		   //graphics->DrawImage(floppySprite,floppy.X(),floppy.Y(),floppy.SpriteSize,
		   
	};
}
