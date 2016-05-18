#pragma once
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "MyForm1.h"
#include "../user/core.h"



namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::Media;
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
	private: System::Windows::Forms::Button^  button2;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->Font = (gcnew System::Drawing::Font(L"PMingLiU", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(571, 398);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(258, 95);
			this->button1->TabIndex = 0;
			this->button1->Text = L"正式測驗";
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
			this->查看紀錄ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->查看紀錄ToolStripMenuItem->Text = L"查看紀錄";
			this->查看紀錄ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::查看紀錄ToolStripMenuItem_Click);
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
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"PMingLiU", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(179, 397);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(240, 95);
			this->button2->TabIndex = 4;
			this->button2->Text = L"教學模式";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 576);
			this->Controls->Add(this->button2);
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
		//Play sound
		SoundPlayer^ play=gcnew SoundPlayer;
		play->SoundLocation = "C:\\project\\AR\\bb.wav";
		play->Load();
		play->Play();
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
		//Create Picture
		Picture *p1 = new Picture("picture1", 1, "C:\\project\\AR\\image\\base1.png", 0, 0);
		Picture *p2 = new Picture("picture2", 2, "C:\\project\\AR\\image\\right.png", 0, 0);
		Picture *p3 = new Picture("picture3", 3, "C:\\project\\AR\\image\\left.png", 0, 0);
		//Picture *p4 = new Picture("picture4", 4, "C:\\project\\AR\\image\\bottom.png", 0, 0);
		/*//Picture Array
		Picture *pic_ary[picnum] =
		{
			p1,p2, p3, p4, p5, p6, p7, p8, p9,p10,p11,p12, p13, p14, p15, p16, p17, p18, p19,p20,p21, p22, p23, p24
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
		}*/
		if (p1->Picture_Load() != 0)
		{
			MessageBox::Show("Picture1 is error");
			exit(1);
		}
		if (p2->Picture_Load() != 0)
		{
			MessageBox::Show("Picture2 is error");
			exit(1);
		}
		if (p3->Picture_Load() != 0)
		{
			MessageBox::Show("Picture3 is error");
			exit(1);
		}
		/*if (p4->Picture_Load() != 0)
		{
			MessageBox::Show("Picture4 is error");
			exit(1);
		}*/
		T1->TASK_Create(p1);
		//T1->TASK_Resotre(p1);
		T1->TASK_Create(p2);
		T1->TASK_Create(p3);
		//T1->TASK_Create(p4);

		
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
		W1->Trig_Create(p1->Pos_X(), p1->Pos_Y(), 100, 75, 1);
		//formal 
	#if 0
		while (1)
		{
			//Display Webcam Image
			Mat frames = W1->Catch_image();
		T1->TASK_Create(p2);	//Display ALL Image
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

	#elif 0//special 
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
				W1->Trig_Create(pic_ary[i + 1]->Pos_X(), pic_ary[i + 1]->Pos_Y(), 100, 75, 1);
				i++;
				
			}
			waitKey(30);
			namedWindow("AW", WINDOW_NORMAL);
			imshow("AW", frames);
			//esc
			if (cvWaitKey(10) == 27 | i>picnum-5)
			{
				play->Stop();
				//destroy namedWindow
				destroyWindow("AW");
				timer1->Enabled = false;
				break;
			}
		}
	#else 
		//X Position,Y Position,flag dirction
		int x = 1;
		int y = 1;
		int flag = 0;
		while (1)
		{
			//Display Webcam Image
			Mat frames = W1->Catch_image();
			
				if (T1->table_id[1] == 1)disp->Image_puts(frames, T1->table_1[1]);
				
				//Update Position,Trigger Position
				p1->Add_Position(x, y);
				p2->Add_Position(x, y+75);
				p3->Add_Position(x, y + 75);

				W1->Trig_Create(p1->Pos_X(), p1->Pos_Y(), 100, 75, 1);
				if (!flag)
				{
					//
					if (T1->table_id[2])disp->Image_puts(frames, T1->table_1[2]);
					//Color Trigger => position
					if ((W1->Trig_func1() == 1) && (x < 500))
					{
						x += 100;
					}
					else if ((W1->Trig_func1() == 1) && (x >= 500))
					{
						y = y + 75;
						flag = 1;
					}
				}
				else
				{
					//
					if (T1->table_id[3])disp->Image_puts(frames, T1->table_1[3]);
					//Color Trigger => negative
					if ((W1->Trig_func1() == 1) && (x >= 10))
					{
						x -= 100;
					}
					else if ((W1->Trig_func1() == 1) && (x <= 10))
					{
						y = y + 75;
						flag = 0;
					}
				}
			waitKey(30);
			//mirror
			flip(frames, frames, 1);
			namedWindow("AW", WINDOW_NORMAL);
			imshow("AW", frames);
			//esc
			if (cvWaitKey(10) == 27 | y > 600)
			{
				play->Stop();
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
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
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
	Picture *p1 = new Picture("picture1", 1, "C:\\project\\AR\\image\\base1.png", 0, 0);
	Picture *p2 = new Picture("picture2", 2, "C:\\project\\AR\\image\\right.png", 0, 0);
	Picture *p3 = new Picture("picture3", 3, "C:\\project\\AR\\image\\left.png", 0, 0);
	Picture *p4 = new Picture("picture4", 4, "C:\\project\\AR\\image\\happy01.png",100,300);
	Picture *p5 = new Picture("picture5", 5, "C:\\project\\AR\\image\\happy02.png",100,300);
	Picture *p6 = new Picture("picture6", 6, "C:\\project\\AR\\image\\happy03.png",100,300);
	Picture *p7 = new Picture("picture7", 7, "C:\\project\\AR\\image\\finally.png", 0, 0);
	//
	Picture *P[7] = {
	p1,p2,p3,p4,p5,p6,p7
	};
	for (unsigned char i = 0; i < 7; i++)
	{
		if (P[i]->Picture_Load() != 0)
		{
			MessageBox::Show("Picture is error");
			exit(1);
		}
		T1->TASK_Create(P[i]);
	}
	//mirror
	for (unsigned char i = 3; i < 7; i++)
	{
		P[i]->mirror();
		
	}

	
	//
	T1->TASK_Delete(p5);
	T1->TASK_Delete(p6);
	T1->TASK_Delete(p7);
	//Init Camera
	VideoCapture capture(0);
	capture.read(frame);


	webcam *W1 = new webcam(capture, 1280, 720, 30);
	W1->webcam_Trig_init();
	
	//Trigger Counter
	//signed char i = 0;
	W1->Trig_Create(p1->Pos_X(), p1->Pos_Y(), 100, 75, 1);

	
	//X Position,Y Position,flag dirction
	int x = 1;
	int y = 1;
	int flag = 0;
	//Picture number counter
	unsigned char counter = 0;
	while (1)
	{
		//Display Webcam Image
		Mat frames = W1->Catch_image();
		for (int i = 0; i < 8; i++)
		{
			if (T1->table_id[i] == 1)disp->Image_puts(frames, T1->table_1[i]);
		}
			

		//Update Position,Trigger Position
		p1->Add_Position(x, y);
		p2->Add_Position(x, y + 75);
		p3->Add_Position(x, y + 75);

		W1->Trig_Create(p1->Pos_X(), p1->Pos_Y(), 100, 75, 1);
		//caule picture number 
		if (counter > 0 && counter!=6)
		{
			T1->TASK_Delete(p4);
			T1->TASK_Delete(p6);
			T1->TASK_Create(p5);
		}
		else if (counter == 6)
		{
			T1->TASK_Delete(p5);
			T1->TASK_Create(p6);
		}
		//
		if (!flag)
		{
			T1->TASK_Delete(p3);
			T1->TASK_Create(p2);
			//
			//if (T1->table_id[2])disp->Image_puts(frames, T1->table_1[2]);
			//Color Trigger => position
			if ((W1->Trig_func1() == 1) && (x < 500))
			{
				x += 100;
				counter++;
			}
			else if ((W1->Trig_func1() == 1) && (x >= 500))
			{
				y = y + 75;
				flag = 1;
				counter++;
			}
		}
		else
		{
			T1->TASK_Delete(p2);
			T1->TASK_Create(p3);
			//
			//if (T1->table_id[3])disp->Image_puts(frames, T1->table_1[3]);
			//Color Trigger => negative
			if ((W1->Trig_func1() == 1) && (x >= 10))
			{
				x -= 100;
				counter++;
			}
			else if ((W1->Trig_func1() == 1) && (x <= 10))
			{
				y = y + 75;
				flag = 0;
				counter++;
			}
		}
		waitKey(30);
		//mirror
		flip(frames, frames, 1);
		namedWindow("AW", WINDOW_NORMAL);
		imshow("AW", frames);
		//esc
		if (y > 100)
		{
			while (cvWaitKey(10) != 27 )
			{
				Mat frames = W1->Catch_image();
				T1->TASK_Delete(p1);
				T1->TASK_Delete(p2);
				T1->TASK_Delete(p3);
				T1->TASK_Delete(p4);
				T1->TASK_Delete(p5);
				T1->TASK_Delete(p6);
				for (int i = 0; i < 8; i++)
				{
					if (T1->table_id[i] == 1)disp->Image_puts(frames, T1->table_1[i]);
				}
				T1->TASK_Create(p7);
				waitKey(30);
				//mirror
				flip(frames, frames, 1);
				namedWindow("AW", WINDOW_NORMAL);
				imshow("AW", frames);
			}
			//destroy namedWindow
			destroyWindow("AW");
			break;
		}
		if (cvWaitKey(10) == 27)
		{
			destroyWindow("AW");
			break;
		}
	}
	

}
private: System::Void 查看紀錄ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
