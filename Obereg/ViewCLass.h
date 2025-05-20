#pragma once
#include "MainForm.h"
//#include <iostream>
#include <windows.h>
namespace ViewClass {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Security;

	/*String^ getPath(void) {
		return "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\";
	}*/
	
	int positionMass[9][9] = {	{0,0,0,1,1,1,0,0,0},
								{0,0,0,0,1,0,0,0,0},
								{0,0,0,0,2,0,0,0,0},
								{1,0,0,0,2,0,0,0,1},
								{1,1,2,2,3,2,2,1,1},
								{1,0,0,0,2,0,0,0,1},
								{0,0,0,0,2,0,0,0,0},
								{0,0,0,0,1,0,0,0,0},
								{0,0,0,1,1,1,0,0,0} };

	void DrawTable(DataGridView^ dataGridView) {
		//окно с загрузкой картинок !!!!!! и изменить условные обозначения 
		String^  pathEmpty = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\" + "empty.png";

		Bitmap^ bmp = gcnew Bitmap(pathEmpty);
		for (int i = 0; i < 9; i++) {
			dataGridView->Rows->Add();
			for (int j = 0; j < 9; j++) {
			/*	if (j == 0 ) {
					dataGridView->Rows[i]->Cells[j]->Value = bmp;
				}
				else {
					dataGridView->Rows[i]->Cells[j]->Value = i + "," + j;
					dataGridView->Rows[i]->Cells[j]->Value = "";
				}*/
				dataGridView->Rows[i]->Cells[j]->Value = bmp;
			}
		}
		dataGridView->Rows[0]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[8]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[8]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[0]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[4]->Cells[4]->Style->BackColor = System::Drawing::Color::Crimson;
	};

	void DrawStartPosition(DataGridView^ dataGridView, OpenFileDialog^ openFileDialog) {
		//MessageBoxA(0, "sl.c_str()", "Выбери картинку", MB_ICONERROR | MB_OK);
		String^ pathEmpty;// объявление строковой переменной
		openFileDialog->ShowDialog();//открываем диалоговое окно
		pathEmpty = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла

		String^ pathKnaz;// объявление строковой переменной
		openFileDialog->ShowDialog();//открываем диалоговое окно
		pathKnaz = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла

		String^ pathZach;// объявление строковой переменной
		openFileDialog->ShowDialog();//открываем диалоговое окно
		pathZach = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла

		String^ pathNApad;// объявление строковой переменной
		openFileDialog->ShowDialog();//открываем диалоговое окно
		pathNApad = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла

		String^ path = "";
		/*String^ pathEmpty = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\empty.png";
		String^ pathKnaz = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\YelCircle.png";
		String^ pathZach = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\WhiCircle.png.png";
		String^ pathNApad = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\BlaCircle.png.png";*/


		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (positionMass[i][j] == 1) {
					//dataGridView->Rows[i]->Cells[j]-> Value=image
					path = pathNApad;

				}
				else if (positionMass[i][j] == 2) {
					path = pathZach;
				}
				else if (positionMass[i][j] == 3) {
					path = pathKnaz;
				}
				else {
					path = pathEmpty;
				}
				Bitmap^ bmp = gcnew Bitmap(path);
				dataGridView->Rows[i]->Cells[j]->Value = bmp;
				//dataGridView->Rows[i]->Cells[j]->Value = "";
			}
		}


		////////////////////////////////////////////////////
		

		//String^ fname;// объявление строковой переменной
		//openFileDialog ->ShowDialog();//открываем диалоговое окно
		//fname = openFileDialog ->FileName;//используем переменную для хранения имени выбранного файла
		// 
		// 
		//pct->Image = Image::FromFile(fname);//загружаем файл в элемент PictureBox

		//using (OpenFileDialog openFileDialog = new OpenFileDialog())
		//{
		//	openFileDialog.InitialDirectory = "c:\\";
		//	openFileDialog.Filter = "img files (*.png)|*.img|All files (*.*)|*.*";
		//	openFileDialog.FilterIndex = 2;
		//	openFileDialog.RestoreDirectory = true;

		//	if (openFileDialog.ShowDialog() == DialogResult.OK)
		//	{
		//		//Get the path of specified file
		//		filePath = openFileDialog.FileName;

		//		//Read the contents of the file into a stream
		//		var fileStream = openFileDialog.OpenFile();

		//		using (StreamReader reader = new StreamReader(fileStream))
		//		{
		//			fileContent = reader.ReadToEnd();
		//		}
		//	}
		//}


	}


}

