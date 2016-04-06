#pragma once
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 30);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(1280, 720);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Mat frame;
		Mat frame1;
		Mat frame2;

		//Display
		DScreen *disp = new DScreen;

		//Load TASK,Put on picture into frame  
		TASK *T1 = new TASK;
		T1->TASK_Init();

		//Create Picture
		Picture *p1 = new Picture("picture1", 98, "C:\\project\\AR\\image\\linux.jpg",0,200);
		Picture *p2 = new Picture("picture2", 1, "C:\\project\\AR\\image\\0613.jpg",0,0);

		//Load Picture
		if (p1->Picture_Load()!=0)
		{	
			MessageBox::Show("Picture1 is error");
			exit(0);
		}
		if (p2->Picture_Load()!=0)
		{
			MessageBox::Show("Picture2 is error");
			exit(0);
		}

		//Create Picture into frame
		T1->TASK_Create(p1);
		T1->TASK_Create(p2);

		//Init Camera
		VideoCapture capture(0);

		

		//textBox1->Text = Convert::ToString((p1->pic_boarder_x[0][0]));
		//textBox1->Text += "\n"+Convert::ToString((p1->pic_boarder_y[0][0]));
		//textBox1->Text += "\n"+Convert::ToString((p2->pic_boarder_x[0][1]));
		//textBox1->Text += "\n" + Convert::ToString((p2->pic_boarder_y[0][1]));*/
		//textBox1->Text += "\n" + Convert::ToString((p1->pic_boarder_x[1][0]));
		//textBox1->Text += "\n" + Convert::ToString((p1->pic_boarder_y[1][0]));
		//textBox1->Text += "\n" + Convert::ToString((p1->pic_boarder_x[1][1]));
		//textBox1->Text += "\n" + Convert::ToString((p1->pic_boarder_y[1][1]));
		//textBox1->Text = textBox1->Text+Convert::ToString((p2->image));*/
		//textBox1->Text += "\n";
		capture.read(frame);
		/*
		for (int i = p1->pic_boarder_x[0][0]; i < (p1->pic_boarder_x[0][1] - p1->pic_boarder_x[0][0]) ; i+=2)
		{
			
			textBox1->Text += "\n" + Convert::ToString(frame.at<uchar>(i, p1->pic_boarder_y[0][1]));

		}

		textBox1->Text += ("\n" + "NEXT1");
		
		for (int i = p1->pic_boarder_y[0][0]; i < (p1->pic_boarder_y[1][0] - p1->pic_boarder_y[0][0]); i += 2)
		{

			textBox1->Text += "\n" + Convert::ToString(frame.at<uchar>(p1->pic_boarder_x[0][0], i));

		}

		textBox1->Text += ("\n" + "NEXT2");

		for (int i = p1->pic_boarder_y[0][0]; i < (p1->pic_boarder_y[1][0] - p1->pic_boarder_y[0][0]); i += 2)
		{

			textBox1->Text += "\n" + Convert::ToString(frame.at<uchar>(p1->pic_boarder_x[0][0], i));

		}*/
		webcam *W1 = new webcam(capture,1280,720,30);
		W1->webcam_Trig_init();
		W1->Trig_Create(0, 0, 20, 20, 0);
		
	#if 1
		/*while (1)
		{	
			waitKey(30);
			imshow("AW", W1->Catch_image());
		}*/
		//MessageBox::Show(Convert::ToString(W1->Trig_X[0]));
		while (1)
		{
			if (W1->Trig_func() == 2)
			{
				MessageBox::Show("YES");
			}
			waitKey(30);
		}
		/*
		while (1)
		{
			capture.read(frame2);
			waitKey(30);
			//capture.read(frame);
			//capture.read(frame1);
			//absdiff(frame, frame1, frame1);
			//cvtColor(frame1, frame1, CV_BGR2HSV);
			//inRange(frame1, Scalar(0, 58, 20), Scalar(50, 173, 230), Temp);
			//篩選hsvImg在HSV顏色空間屬於膚色的區域
			Mat imageROI0;
			Mat imageROI1;
			imageROI0 = frame(Rect(0, 0, 600,400));
			imageROI1 = frame2(Rect(0, 0, 600, 400));

			//Trigger test 
			
			threshold(imageROI1, imageROI0, 80, 255, THRESH_BINARY_INV);
			double ss = 0;
			for (int i = 0; i < 3; i++)
			{
				//scalar summary
				ss += sum(imageROI0)[i];
			}
			//NON black Percentage
			if (ss / (600.0 * 400.0 * 255.0 * 3.0) > 0.2)
			{
				MessageBox::Show(Convert::ToString(ss / (800.0 * 480.0 * 255.0 * 3.0)));
			}
			imshow("AW", imageROI0);
			
		}*/
	#else
		while (1)
		{
			//Display Webcam Image
			Mat frames = W1->Catch_image();
			//Display ALL Image
			for (int i = 0; i < MAX_TASK - 1; i++)
			{
				if (T1->table_id[i] == 1)disp->Image_puts(frames, T1->table_1[i]);
			}

			disp->Image_Mov(p1, 5, 0);
			
			if (p1->Pos_X() > 200)
			{
				T1->TASK_Delete(p1);
			}
			disp->Image_Rotation(p1,90);
			disp->Image_Rotation(p2,90);
		
			waitKey(30);
			imshow("AW", frames);
			
		}
	#endif

	}
	
    
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
