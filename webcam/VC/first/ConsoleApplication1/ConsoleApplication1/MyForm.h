#pragma once
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "MyForm1.h"
#include "../user/core.h"



namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  檔案ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關閉ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  紀錄ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  查看紀錄ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關於ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  關於ToolStripMenuItem1;
	public:
		//Time
		int time = 0;
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關閉ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->紀錄ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->查看紀錄ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關於ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->關於ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->Font = (gcnew System::Drawing::Font(L"PMingLiU", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(346, 407);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(258, 95);
			this->button1->TabIndex = 0;
			this->button1->Text = L"開始";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"PMingLiU", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(375, 186);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 48);
			this->label1->TabIndex = 1;
			this->label1->Text = L"準備開始";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(344, 540);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(269, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"銘傳大學電子工程學系晶片設計與應用實驗室發行";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->檔案ToolStripMenuItem,
					this->紀錄ToolStripMenuItem, this->關於ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(960, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 檔案ToolStripMenuItem
			// 
			this->檔案ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->關閉ToolStripMenuItem });
			this->檔案ToolStripMenuItem->Name = L"檔案ToolStripMenuItem";
			this->檔案ToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->檔案ToolStripMenuItem->Text = L"檔案";
			// 
			// 關閉ToolStripMenuItem
			// 
			this->關閉ToolStripMenuItem->Name = L"關閉ToolStripMenuItem";
			this->關閉ToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->關閉ToolStripMenuItem->Text = L"關閉";
			this->關閉ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::關閉ToolStripMenuItem_Click);
			// 
			// 紀錄ToolStripMenuItem
			// 
			this->紀錄ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->查看紀錄ToolStripMenuItem });
			this->紀錄ToolStripMenuItem->Name = L"紀錄ToolStripMenuItem";
			this->紀錄ToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->紀錄ToolStripMenuItem->Text = L"紀錄";
			// 
			// 查看紀錄ToolStripMenuItem
			// 
			this->查看紀錄ToolStripMenuItem->Name = L"查看紀錄ToolStripMenuItem";
			this->查看紀錄ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->查看紀錄ToolStripMenuItem->Text = L"查看紀錄";
			// 
			// 關於ToolStripMenuItem
			// 
			this->關於ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->關於ToolStripMenuItem1 });
			this->關於ToolStripMenuItem->Name = L"關於ToolStripMenuItem";
			this->關於ToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->關於ToolStripMenuItem->Text = L"關於";
			// 
			// 關於ToolStripMenuItem1
			// 
			this->關於ToolStripMenuItem1->Name = L"關於ToolStripMenuItem1";
			this->關於ToolStripMenuItem1->Size = System::Drawing::Size(100, 22);
			this->關於ToolStripMenuItem1->Text = L"關於";
			this->關於ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::關於ToolStripMenuItem1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		

	}
	
    
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//initial timer object
		timer1->Enabled = true;
		timer1->Interval = 1000;
		//initial time number
		time = 0;
		//
		
		//
		Mat frame;
		Mat frame1;
		Mat frame2;
		//Display
		DScreen *disp = new DScreen;

		//Load TASK,Put on picture into frame  
		TASK *T1 = new TASK;
		T1->TASK_Init();

		//Create Picture
		#define picnum 20+4
		//1 row
		Picture *p1 = new Picture("picture1", 1, "C:\\project\\AR\\image\\base1.png", 0, 0);
		Picture *p2 = new Picture("picture2", 2, "C:\\project\\AR\\image\\base1.png", 200, 0);
		Picture *p3 = new Picture("picture3", 3, "C:\\project\\AR\\image\\base1.png", 400, 0);
		Picture *p4 = new Picture("picture4", 4, "C:\\project\\AR\\image\\base1.png", 600, 0);
		Picture *p5 = new Picture("picture5", 5, "C:\\project\\AR\\image\\base1.png", 800, 0);
		//2 row
		Picture *p6 = new Picture("picture6", 6, "C:\\project\\AR\\image\\base1.png", 800, 150);
		Picture *p7 = new Picture("picture7", 7, "C:\\project\\AR\\image\\base1.png", 600, 150);
		Picture *p8 = new Picture("picture8", 8, "C:\\project\\AR\\image\\base1.png", 400, 150);
		Picture *p9 = new Picture("picture9", 9, "C:\\project\\AR\\image\\base1.png", 200, 150);
		Picture *p10 = new Picture("picture10", 10, "C:\\project\\AR\\image\\base1.png", 0, 150);
		//3 row
		Picture *p11 = new Picture("picture11", 11, "C:\\project\\AR\\image\\base1.png", 0, 300);
		Picture *p12 = new Picture("picture12", 12, "C:\\project\\AR\\image\\base1.png", 200, 300);
		Picture *p13 = new Picture("picture13", 13, "C:\\project\\AR\\image\\base1.png", 400, 300);
		Picture *p14 = new Picture("picture14", 14, "C:\\project\\AR\\image\\base1.png", 600, 300);
		Picture *p15 = new Picture("picture15", 15, "C:\\project\\AR\\image\\base1.png", 800, 300);
		//4 row
		Picture *p16 = new Picture("picture16", 16, "C:\\project\\AR\\image\\base1.png", 800, 450);
		Picture *p17 = new Picture("picture17", 17, "C:\\project\\AR\\image\\base1.png", 600, 450);
		Picture *p18 = new Picture("picture18", 18, "C:\\project\\AR\\image\\base1.png", 400, 450);
		Picture *p19 = new Picture("picture19", 19, "C:\\project\\AR\\image\\base1.png", 200, 450);
		Picture *p20 = new Picture("picture20", 20, "C:\\project\\AR\\image\\base1.png", 0, 450);
		//5 row
		Picture *p21 = new Picture("picture21", 21, "C:\\project\\AR\\image\\base1.png",200, 600);
		Picture *p22=  new Picture("picture22", 22, "C:\\project\\AR\\image\\base1.png",400, 600);
		Picture *p23 = new Picture("picture23", 23, "C:\\project\\AR\\image\\base1.png",600, 600);
		Picture *p24 = new Picture("picture24", 24, "C:\\project\\AR\\image\\base1.png",800, 600);
		//6 row
		Picture *p25 = new Picture("picture25", 25, "C:\\project\\AR\\image\\base1.png",800, 750);
		Picture *p26 = new Picture("picture26", 26, "C:\\project\\AR\\image\\base1.png",600, 750);
		Picture *p27 = new Picture("picture27", 27, "C:\\project\\AR\\image\\base1.png",400, 750);
		Picture *p28 = new Picture("picture28", 28, "C:\\project\\AR\\image\\base1.png",200, 750);
		//Picture Array
		Picture *pic_ary[picnum] =
		{
			p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15, p16, p17, p18, p19, p21, p22, p23, p24, p25, p26, p27, p28
		};

		//Load and inseert TASK
		for (int i = 0; i < picnum; i++)
		{
			if (pic_ary[i]->Picture_Load() != 0)
			{
				MessageBox::Show("Picture" + i + "is error");
				exit(1);
			}
			T1->TASK_Create(pic_ary[i]);
			T1->TASK_Delete(pic_ary[i]);
		}
		T1->TASK_Resotre(pic_ary[0]);
		//Init Camera
		VideoCapture capture(0);
		capture.read(frame);


		webcam *W1 = new webcam(capture, 1280, 720, 30);
		W1->webcam_Trig_init();
		/*for (int i = 0; i < 5; i++)
		{
		//Because trigger begin from element 1
		W1->Trig_Create(pic_ary[i]->Pos_X(), pic_ary[i]->Pos_Y(), 200, 150, i+1);
		}*/

		//Trigger Counter
		unsigned char i = 0;
		W1->Trig_Create(pic_ary[1]->Pos_X(), pic_ary[1]->Pos_Y(), 200, 150, 1);
		//formal 
	#if 0
		while (1)
		{
			//Display Webcam Image
			Mat frames = W1->Catch_image();
			//Display ALL Image
			for (int i = 0; i < MAX_TASK - 1; i++)
			{
				if (T1->table_id[i] == 1)disp->Image_puts(frames, T1->table_1[i]);
			}
			//W1->Trig_Pos_Change(p1->Pos_X(), p1->Pos_Y(), 256, 256, 0);
			disp->Image_Mov(p1, 5, 0);

			if (p1->Pos_X() > 200)
			{
				T1->TASK_Delete(p1);
			}
	
			//Trigger
			if (W1->Trig_func() == 1)
			{
				W1->Trig_hide(1);
				W1->Trig_Restore(2);
				MessageBox::Show("YES");
			}
			else if (W1->Trig_func() == 2)
			{
				MessageBox::Show("YES1");
			}

			waitKey(30);
			namedWindow("AW", WINDOW_NORMAL);
			imshow("AW", frames);
		}

	#else//special 
		while (1)
		{
			//Display Webcam Image
			Mat frames = W1->Catch_image();
			//Display ALL Image
			for (int i = 0; i < MAX_TASK - 1; i++)
			{
				if (T1->table_id[i] == 1)disp->Image_puts(frames, T1->table_1[i]);
			}
			//Color Trigger
			if (W1->Trig_func1() == 1 && i < picnum-4)
			{
				T1->TASK_Resotre(pic_ary[i + 1]);
				T1->TASK_Delete(pic_ary[i]);
				W1->Trig_Create(pic_ary[i + 1]->Pos_X(), pic_ary[i + 1]->Pos_Y(), 200, 150, 1);
				i++;
				
			}
			waitKey(30);
			namedWindow("AW", WINDOW_NORMAL);
			imshow("AW", frames);
			//esc
			if (cvWaitKey(10) == 27 | i>picnum-5)
			{
				//destroy namedWindow
				destroyWindow("AW");
				timer1->Enabled = false;
				break;
			}
		}
	#endif
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		time++;
		int minute = time / 60;
		int second = time % 60;
		label1->Text = Convert::ToString(minute) + "分" + Convert::ToString(second) + "秒";
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void 關閉ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm::Close();
}
private: System::Void 關於ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	//Open MyFrom1
	MyForm1^ MyForms = gcnew MyForm1();
	MyForms->Show();
	
}
};
}
