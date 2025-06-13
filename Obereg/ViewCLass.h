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
	
	//отрисовка поля 
	void DrawTable(DataGridView^ dataGridView) {
		
		for (int i = 0; i < 9; i++) {
			for (int j= 0; j < 9; j++) {
				dataGridView->Rows[i]->Cells[j]->Style->BackColor = System::Drawing::Color::White;

			}
			dataGridView->Rows[0]->Cells[0]->Style->BackColor = System::Drawing::Color::White;

		}
		//прорисовываем выходы и  трон князя
		dataGridView->Rows[0]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[8]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[8]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[0]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
		dataGridView->Rows[4]->Cells[4]->Style->BackColor = System::Drawing::Color::Crimson;
	};
	 //отрисовка полодения играков на поле 
	//1-нападающий
		//2-защитник
		//3-князь
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
				//каждой фишке присваиваем свою картинку 
			}
		}

	}

	bool AreYouWin(int igr, int row, int col, int positionMass[9][9], int NapCount) {
		if (igr == 3){
			if ((row == 0 && col == 0) || (row == 0 && col == 8)
				|| (row == 8 && col == 0) || (row == 8 && col == 8)) {
				return true;
			}
			
		}
		if (igr == 1) {
			if (row == 0 && col == 2) {
				if (positionMass[0][1] == 3) {
					return true;
				}else if (positionMass[0][1] == 2) {
					positionMass[0][1] = 0;
				}
				
			}
			if (row == 2 && col == 0 ) {
				if (positionMass[1][0] == 3) {
					return true;
				}
				else if (positionMass[1][0] == 2) {
					positionMass[1][0] = 0;
				}
			}
			if (row == 0 && col == 6  ){
				if (positionMass[0][7] == 3) {
					return true;
				}
				else if (positionMass[0][7] == 2) {
					positionMass[0][7] = 0;
				}
			}
			if (row == 2 && col == 8 ){
				if (positionMass[1][8] == 3) {
					return true;
				}
				else if (positionMass[1][8] == 2) {
					positionMass[1][8] = 0;
				}
			}
			if (row == 6 && col == 0 ){
				if (positionMass[7][0] == 3) {
					return true;
				}
				else if (positionMass[7][0] == 2) {
					positionMass[7][0] = 0;
				}
			}
			if (row == 8 && col == 2 ){
				if (positionMass[8][1] == 3) {
					return true;
				}
				else if (positionMass[8][1] == 2) {
					positionMass[8][1] = 0;
				}
			}
			if (row == 8 && col == 6 ){
				if (positionMass[8][7] == 3) {
					return true;
				}
				else if (positionMass[8][7] == 2) {
					positionMass[8][7] = 0;
				}
			}
			if (row == 6 && col == 8 ){
				if (positionMass[7][8] == 3) {
					return true;
				}
				else if (positionMass[7][8] == 2) {
					positionMass[7][8] = 0;
				}
			}
			if (row == 4 && col == 2) {
				if (positionMass[4][3] == 3) {
					return true;
				}
				else if (positionMass[4][3] == 2) {
					positionMass[4][3] = 0;
				}
			}
			if (row == 2 && col == 4) {
				if (positionMass[3][4] == 3) {
					return true;
				}
				else if (positionMass[3][4] == 2) {
					positionMass[3][4] = 0;
				}
			}
			if (row == 4 && col == 6) {
				if (positionMass[4][5] == 3) {
					return true;
				}
				else if (positionMass[4][5] == 2) {
					positionMass[4][5] = 0;
				}
			}
			if (row == 6 && col == 4) {
				if (positionMass[5][4] == 3) {
					return true;
				}
				else if (positionMass[5][4] == 2) {
					positionMass[5][4] = 0;
				}
			}

			if (positionMass[4][3] == 1 && positionMass[3][4] == 1 && 
				positionMass[4][5] == 1 && positionMass[5][4] == 1 && positionMass[4][4] == 3 ) {
				return true;

			} 
			if (row + 2 < 9) {
				if (positionMass[row][col] == 1 && positionMass[row + 2][col] == 1 ) {
					if (positionMass[row + 1][col] == 3) {
						return true;
					}
					if (positionMass[row + 1][col] == 2 ) {
						positionMass[row + 1][col] = 0;
					} 
				}
			}
			if (row - 2 >= 0) {
				if (positionMass[row][col] == 1 && positionMass[row - 2][col] == 1 ) {
					
					if (positionMass[row - 1][col] == 3) {
						return true;
					}
					if (positionMass[row - 1][col] == 2) {
						positionMass[row - 1][col] = 0;
					}
				}
			}
			if (col + 2 < 9) {
				if (positionMass[row][col] == 1 && positionMass[row][col + 2] == 1 ) {
					
					if (positionMass[row][col + 1] == 3) {
						return true;
					}
					if (positionMass[row][col + 1] == 2) {
						positionMass[row][col + 1] = 0;
					}
				}
			}
			if (col - 2 >= 0) {
				if (positionMass[row][col] == 1 && positionMass[row][col - 2] == 1) {
					if (positionMass[row][col - 1] == 3) {
						return true;		  
					}						  
					if (positionMass[row][col - 1] == 2) {
						positionMass[row][col - 1] = 0;
					}
				}
			}
		
		}

		if (igr == 2 || igr == 3) {
			if (row == 0 && col == 2) {
				if (positionMass[0][1] == 1) {
					positionMass[0][1] = 0;
					NapCount--;
				}

			}
			if (row == 2 && col == 0) {
				if (positionMass[1][0] == 1) {
					positionMass[1][0] = 0;
					NapCount--;

				}
			}
			if (row == 0 && col == 6) {
				 if (positionMass[0][7] == 1) {
					positionMass[0][7] = 0;
					NapCount--;

				}
			}
			if (row == 2 && col == 8) {
				if (positionMass[1][8] == 1) {
					positionMass[1][8] = 0;
					NapCount--;

				}
			}
			if (row == 6 && col == 0) {
				 if (positionMass[7][0] == 1) {
					positionMass[7][0] = 0;
					NapCount--;

				}
			}
			if (row == 8 && col == 2) {
				if (positionMass[8][1] == 1) {
					positionMass[8][1] = 0;
					NapCount--;

				}
			}
			if (row == 8 && col == 6) {
				 if (positionMass[8][7] == 1) {
					positionMass[8][7] = 0;
					NapCount--;

				}
			}
			if (row == 6 && col == 8) {
				 if (positionMass[7][8] == 1) {
					positionMass[7][8] = 0;
					NapCount--;

				}
			}
			if (row == 4 && col == 2) {
				if (positionMass[4][3] == 1) {
					positionMass[4][3] = 0;
					NapCount--;

				}
			}
			if (row == 2 && col == 4) {
				 if (positionMass[3][4] == 1) {
					positionMass[3][4] = 0;
					NapCount--;

				}
			}
			if (row == 4 && col == 6) {
				if (positionMass[4][5] == 1) {
					positionMass[4][5] = 0;
					NapCount--;

				}
			}
			if (row == 6 && col == 4) {
				if (positionMass[5][4] == 1) {
					positionMass[5][4] = 0;
					NapCount--;

				}
			}

			if (row + 2 < 9) {
				if (positionMass[row][col] == 2 && positionMass[row + 2][col] == 2 && positionMass[row + 1][col] == 1) {
					positionMass[row + 1][col] = 0;
					NapCount--;
				}
			}
			 if (row - 2 >= 0) {
				if (positionMass[row][col] == 2 && positionMass[row - 2][col] == 2 && positionMass[row - 1][col] == 1) {
					positionMass[row - 1][col] = 0;
					NapCount--;
				}
			}
			 if (col + 2 < 9) {
				if (positionMass[row][col] == 2 && positionMass[row][col+2] == 2 && positionMass[row][col+1] == 1) {
					positionMass[row][col + 1] = 0;
					NapCount--;
				}
			}
			 if (col - 2 >= 0) {
				if (positionMass[row][col] == 2 && positionMass[row][col-2] == 2 && positionMass[row][col-1] == 1) {
					positionMass[row][col - 1] = 0;
					NapCount--;
				}
			}
		}
		if (NapCount <= 0) {
			return true;

		}
		return false;

	}
}

