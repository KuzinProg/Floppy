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
		float gravity;
		bool gameOver;
		void Init()
		{
			gameOver = false;
			gravity = 0.3f;
			floppy = Floppy(50, 206);

		}
		void controll()
		{
			if (!gameOver)
				floppy.jump();
			else
				Init();
			if (!timer1->Enabled)
			{
				timer1->Start();
				timer1->Interval = 10;
				floppy.jump();
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
		   Image^ pipeBottomSprite;

	public:
		Form1(void)
		{
			InitializeComponent();
			bgSprite = Image::FromFile("image\\bg.png");
			floppySprite = Image::FromFile("image\\bird.png");
			Invalidate();
			timer1->Start();
			Init();
		}
		bool checkGameOver()
		{
			if (floppy.Y() > 500)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		void update()
		{
			if (!gameOver)
			{
				floppy.fall(gravity);
				Invalidate();
				if (checkGameOver())
				{
					gameOver = true;
				}
			}
			else
			{
				timer1->Stop();
			}
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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(264, 461);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Floppy";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ graphics = e->Graphics;
		   graphics->DrawImage(bgSprite, 0, 0, bgSprite->Width, bgSprite->Height);
		   graphics->DrawImage(floppySprite, floppy.X(), floppy.Y(), floppy.SpriteSize(),floppy.SpriteSize()) ;

	}   
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		update();
	}
	private: System::Void Form1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		controll();
	}
	};
}
