#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;
using namespace System;
using namespace System::IO;


//Puts picture Max count
#define MAX_TASK 100
//Trig object Max count-1
#define Trig_num 100 
//Picture,image process and display
class Picture :public Mat
{
	private:
		string Name;
		int ID;
		string Path;
		int position_x;
		int position_y;

		//Class picture Include Mat object entity
		Mat image;

		//Picure border
		int pic_boarder_x[2][2];
		int pic_boarder_y[2][2];

	public:
		//Picture Constructor 
		Picture(){};
		~Picture(){};

		//Create Picture information,and provide position
		Picture(string Name1, int ID1, string Path1, int position_x1, int position_y1)
		{
			this->Name = Name1;
			this->ID = ID1;
			this->Path = Path1;
			this->position_x = position_x1;
			this->position_y = position_y1;
		}
		//Load Picture
		int Picture_Load()
		{
			//ID check
			if (this->ID > MAX_TASK - 2)
			{
				//ID too Large
				return -2;
			}

			//File check
			FILE *f1;
			f1 = fopen((this->Path).c_str(), "r");
			if (!f1)
			{
				//File too Large
				return -1;
			}
			fclose(f1);
			//Init Picture
			Mat pic = imread(this->Path);
			this->image = pic;
			
			//Calculate picture boarder
			pic_boarder_x[0][0] = this->position_x;
			pic_boarder_y[0][0] = this->position_y;

			pic_boarder_x[0][1] = this->position_x + pic.cols;
			pic_boarder_y[0][1] = this->position_y;

			pic_boarder_x[1][0] = this->position_x;
			pic_boarder_y[1][0] = this->position_y + pic.rows;

			pic_boarder_x[1][1] = this->position_x + pic.cols;
			pic_boarder_y[1][1] = this->position_y + pic.rows;

			//bondary check 
			
			return 0;
		}

		//Add Position information
		int Add_Position(int position_x1, int position_y1)
		{
			this->position_x = position_x1;
			this->position_y = position_y1;
			return 0;
		}

		//Get Picture Positive
		int Pos_X()
		{
			return position_x;
		}
		int Pos_Y()
		{
			return position_y;
		}
		//Get image
		Mat Get_image()
		{
			return image;
		}
		//friend class
		friend class TASK;
		friend class DScreen;
		friend class webcam;
};
class TASK
{
	public:
		//Picture Array
		Picture *table_1[MAX_TASK];
		int table_id[MAX_TASK];
	public:
		TASK(){};
		~TASK(){};
		//TASK Init
		int TASK_Init()
		{
			for (int i = 0; i < MAX_TASK - 1; i++)
			{
				table_id[i] = 0;
			}
			return 0;
		}
		//Create Picture information into display table
		int TASK_Create(Picture *P1)
		{
			
			this->table_1[P1->ID] = P1;
			this->table_id[P1->ID] = 1;
			return 0;
		}
		//Delete Picture information into display table
		int TASK_Delete(Picture *P1)
		{
			this->table_id[P1->ID] = 0;
			return 0;
		}

		//friend class
		friend class DScreen;
};
class DScreen : public Mat
{
	
	public:
		DScreen(){};
		~DScreen(){};
		/****************************************************************/
		/*Name:image_puts                                               */
		/*Input:Mat Pic_In, string Max_in, int position_x, int position */
		/*Pic_In:Source Picture;                                        */
		/*Pic_Out:Output mixing Picture;  	                            */
		/*Size_x is x position;									        */
		/*Size_y is y position;								            */
		/*Return 0 is normal exit				                        */
		/*Return -1 is Max_in is Src Error                              */
		/****************************************************************/
		int Image_puts(Mat Pic_In, Picture *P1)
		{
			Mat logo = P1->image;
			//Max_in
			if (!logo.data)return -1;
			//Mat Temp
			Mat ImageROT;
			//Mask
			Mat mask = logo;
			//Setting area
			ImageROT = Pic_In(Rect(P1->position_x, P1->position_y, logo.cols, logo.rows));
			//Copy retrun Picture
			logo.copyTo(ImageROT, mask);
			return 0;
		}
		//bug:foggy
		int Image_Rotation(Picture *P1,int angle1)
		{
		
			Mat Source = P1->image;
			//Source Picture
			//Build there point rotation
			Mat result = zeros(Source.rows, Source.cols, Source.type());

			//Setting Rotation center¡Bangle and resize
			cv::Point2f center = cv::Point2f(result.cols / 2.0, result.rows / 2.0);
			//rotate
			double angle = angle1;
			//magnification
			double scale = 1;
			//Rotation Matix 
			Mat rot_mat = getRotationMatrix2D(center, angle, scale);

			warpAffine(Source, result, rot_mat, Source.size());

			P1->image = result;
			return 0;
		}
		int Image_Mov(Picture *P1, int x, int y)
		{
			P1->position_x += x;
			P1->position_y += y;
			return 0;
		}
		
};

//webcam class
class webcam
{
	private:
		//Trig Range
		int Trig_X[Trig_num];
		int Trig_Y[Trig_num];
		int Trig_regX[Trig_num];
		int Trig_regY[Trig_num];
		
		//camera
		VideoCapture capture;

		//Origin Picture
		Mat Parent_frame;

	public:
		//webcam(){};
		~webcam(){};
		webcam(VideoCapture Ocapture, int WIDTH, int HEIGHT,int FPS)
		{
			if (WIDTH < 200 || HEIGHT < 200 || FPS < 10)
			{
				WIDTH = 1280; 
				HEIGHT = 720; 
				FPS = 30;
			}
			capture = Ocapture;
			//Setting WebCam Format
			capture.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
			capture.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);
			capture.set(CV_CAP_PROP_FPS, FPS);
		};

		int webcam_Trig_init()
		{ 
			//Origin frame
			capture.read(Parent_frame);

			//Init Trig Array
			for (int i = 0; i < Trig_num; i++)
			{
				this->Trig_X[i] = -1;
				this->Trig_Y[i] = -1;
				this->Trig_regX[i] = -1;
				this->Trig_regY[i] = -1;
			}
			return 0;
		}

		Mat Catch_image()
		{
			static Mat frame;
			capture.read(frame);
			return frame;
		}

		int Trig_Create(int OTrig_X, int OTrig_Y, int OTrig_regX, int OTrig_regY,int prior1)
		{
			if (prior1>Trig_num-1)
			{
				return -1;
			}

			this->Trig_X[prior1] = OTrig_X;
			this->Trig_Y[prior1] = OTrig_Y;
			this->Trig_regX[prior1] = OTrig_regX;
			this->Trig_regY[prior1] = OTrig_regY;
			return 0;
		}

		int Trig_func()
		{
				//update webcam picture
				Mat update_frame;
				Mat imageROI0;
				Mat imageROI1;

				for (int i = 0; i < Trig_num - 1; i++)
				{
					if (this->Trig_X[i] == -1 || this->Trig_Y[i] == -1 || this->Trig_regX[i] == -1 || this->Trig_regY[i] == -1)
					{
						return -1;
					}

					capture.read(update_frame);
					waitKey(30);
					//Parent frame
					imageROI0 = Parent_frame(Rect(Trig_X[i], Trig_Y[i], Trig_regX[i], Trig_regY[i]));
					//Sub frame
					imageROI1 = update_frame(Rect(Trig_X[i], Trig_Y[i], Trig_regX[i], Trig_regY[i]));
					//threshold
					threshold(imageROI1, imageROI0, 80, 255, THRESH_BINARY_INV);
					
					double Sum_pixel = 0;
					for (int i = 0; i < 3; i++)
					{
						//Scalar summary
						Sum_pixel += sum(imageROI0)[i];
					}

					//NON black Percentage
					if (Sum_pixel / ((float)Trig_regX[i] * (float)Trig_regY[i] * 255.0 * 3.0) > 0.2)
					{
						//Call Action Function
						return 2;
					}

				}
				return 0;
		}
};
