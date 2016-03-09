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

class Picture :public Mat
{
	public:
		string Name;
		int ID;
		string Path;
		int position_x;
		int position_y;

		//Class picture Include Mat object entity
		Mat image;

		//Pibcure border
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

			pic_boarder_x[0][1] = this->position_x;
			pic_boarder_y[0][1] = this->position_y + pic.rows;

			pic_boarder_x[1][0] = this->position_x;
			pic_boarder_y[1][0] = this->position_y + pic.cols;

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

};
class TASK :public Picture
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
};
class DScreen : public TASK, public Picture,public Mat
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
class AR
{
	Picture *frame[2];
	public:
		int Trigger(Mat foreground, Mat background)
		{
			Mat result;
			absdiff(background, foreground, result);

			//return Pocture ID

		}
	

};
