#pragma once
#include "MainForm.h"
//#include <iostream>
#include <windows.h>
namespace Var {}


namespace ViewClass {
	//using namespace Obereg::MainForm;
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Security;
	
	/*String^ getPath(void) {
		return "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\";
	}*/
	

	void DrawTable(DataGridView^ dataGridView) {
		
		for (int i = 0; i < 9; i++) {
			for (int j= 0; j < 9; j++) {
				dataGridView->Rows[i]->Cells[j]->Style->BackColor = System::Drawing::Color::White;

			}
			dataGridView->Rows[0]->Cells[0]->Style->BackColor = System::Drawing::Color::White;

		}
		dataGridView->Rows[0]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[8]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[8]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[0]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[4]->Cells[4]->Style->BackColor = System::Drawing::Color::Crimson;
	};

	void DrawStartPosition(DataGridView^ dataGridView, 
		String^ pathEmpty, String^ pathKnaz, String^ pathZach, String^ pathNApad, 
		int positionMass[9][9]) {

		
		String^ path = "";
		/*String^ pathEmpty = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\empty.png";
		String^ pathKnaz = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\YelCircle.png";
		String^ pathZach = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\WhiCircle.png.png";
		String^ pathNApad = "C:\\Users\\admin\\Desktop\\Политех\\Алгоритмы и структура данных\\Курсач\\Obereg\\x64\\Debug\\BlaCircle.png.png";*/


		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (positionMass[i][j] == 1) {
					//dataGridView->Rows[i]->Cells[j]-> Value=image
					path =pathNApad;

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

	}


}

