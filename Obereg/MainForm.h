#pragma once
#include "ViewClass.h"
#include <windows.h>

//public ref class Globals
//{
//public:
//	static String^ path = gcnew String("");
//}
namespace Obereg {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ViewClass;

	//текущее положение игрков
	int positionMass[9][9] = {  {0,0,0,1,1,1,0,0,0},
								{0,0,0,0,1,0,0,0,0},
								{0,0,0,0,2,0,0,0,0},
								{1,0,0,0,2,0,0,0,1},
								{1,1,2,2,3,2,2,1,1},
								{1,0,0,0,2,0,0,0,1},
								{0,0,0,0,2,0,0,0,0},
								{0,0,0,0,1,0,0,0,0},
								{0,0,0,1,1,1,0,0,0} };
	int rowIndexCur=0, columnIndexCur=0;
	//кто сейчас ходит
	boolean  isNapad = false;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		
	public:
		
		//переменные хранения картинок фишек

			static String^ pathEmpty;
			static String^ pathKnaz;
			static String ^ pathZach;
	private: System::Windows::Forms::Label^ label6;
	public:
	private: System::Windows::Forms::Label^ StepLable;
		   static String^ pathNApad;/// объявление строковой переменной*/
			
		
	public:
		MainForm(void)
		{

			
			InitializeComponent();
			ChangePicture(openFileDialog);

			//отрисовываем игровое поле 
			Bitmap^ bmp = gcnew Bitmap(pathEmpty);
			for (int i = 0; i < 9; i++) {
				dataGridView->Rows->Add();
				for (int j = 0; j < 9; j++) {
					dataGridView->Rows[i]->Cells[j]->Value = bmp;
				}
			}
			DrawTable(dataGridView);
			
			//System::Windows::Forms::MessageBox();
			 //отрисовываем стартовую позицию
			DrawStartPosition(dataGridView,  pathEmpty, pathKnaz, pathZach, pathNApad, positionMass);

		}

		//загружаем картинки фишек
		void ChangePicture(OpenFileDialog^ openFileDialog) {

			openFileDialog->ShowDialog();//открываем диалоговое окно
			pathEmpty = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла

			openFileDialog->ShowDialog();//открываем диалоговое окно
			pathKnaz = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла
			KnazButton->BackgroundImage = gcnew Bitmap(pathKnaz);

			openFileDialog->ShowDialog();//открываем диалоговое окно
			pathZach = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла
			ZaсhButton->BackgroundImage = gcnew Bitmap(pathZach);

			openFileDialog->ShowDialog();//открываем диалоговое окно
			pathNApad = openFileDialog->FileName;//используем переменную для хранения имени выбранного файла
			NapadButton->BackgroundImage = gcnew Bitmap(pathNApad);


		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView;

	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ KnazButton;
	private: System::Windows::Forms::Button^ ZaсhButton;
	private: System::Windows::Forms::Button^ NapadButton;



	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column1;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column2;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column3;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column4;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column5;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column6;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column7;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column8;
	private: System::Windows::Forms::DataGridViewImageColumn^ Column9;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;


	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->KnazButton = (gcnew System::Windows::Forms::Button());
			this->ZaсhButton = (gcnew System::Windows::Forms::Button());
			this->NapadButton = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->StepLable = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->ColumnHeadersVisible = false;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9
			});
			this->dataGridView->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Beige;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->GridColor = System::Drawing::Color::DarkGray;
			this->dataGridView->Location = System::Drawing::Point(10, 24);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView->Size = System::Drawing::Size(275, 203);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView_CellClick);
			this->dataGridView->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"";
			this->Column1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Column1.Image")));
			this->Column1->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"";
			this->Column2->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"";
			this->Column3->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"";
			this->Column4->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"";
			this->Column5->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"";
			this->Column6->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"";
			this->Column7->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"";
			this->Column8->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"";
			this->Column9->ImageLayout = System::Windows::Forms::DataGridViewImageCellLayout::Zoom;
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column9->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->KnazButton);
			this->groupBox1->Controls->Add(this->ZaсhButton);
			this->groupBox1->Controls->Add(this->NapadButton);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Gadugi", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(293, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(151, 228);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Условные обозначения";
			// 
			// KnazButton
			// 
			this->KnazButton->BackColor = System::Drawing::Color::Transparent;
			this->KnazButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"KnazButton.BackgroundImage")));
			this->KnazButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->KnazButton->FlatAppearance->BorderSize = 0;
			this->KnazButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->KnazButton->Location = System::Drawing::Point(6, 40);
			this->KnazButton->Name = L"KnazButton";
			this->KnazButton->Size = System::Drawing::Size(38, 29);
			this->KnazButton->TabIndex = 9;
			this->KnazButton->UseVisualStyleBackColor = false;
			// 
			// ZaсhButton
			// 
			this->ZaсhButton->BackColor = System::Drawing::Color::Transparent;
			this->ZaсhButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ZaсhButton.BackgroundImage")));
			this->ZaсhButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ZaсhButton->FlatAppearance->BorderSize = 0;
			this->ZaсhButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ZaсhButton->Location = System::Drawing::Point(6, 74);
			this->ZaсhButton->Name = L"ZaсhButton";
			this->ZaсhButton->Size = System::Drawing::Size(38, 29);
			this->ZaсhButton->TabIndex = 8;
			this->ZaсhButton->UseVisualStyleBackColor = false;
			// 
			// NapadButton
			// 
			this->NapadButton->BackColor = System::Drawing::Color::Transparent;
			this->NapadButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NapadButton.BackgroundImage")));
			this->NapadButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->NapadButton->FlatAppearance->BorderSize = 0;
			this->NapadButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NapadButton->Location = System::Drawing::Point(6, 107);
			this->NapadButton->Name = L"NapadButton";
			this->NapadButton->Size = System::Drawing::Size(38, 29);
			this->NapadButton->TabIndex = 7;
			this->NapadButton->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSeaGreen;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(11, 187);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 30);
			this->button3->TabIndex = 6;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Crimson;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(11, 151);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 30);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(47, 192);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(47, 16);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Выход";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(47, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 16);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Трон";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(42, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Нападающий";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Защитник";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Князь";
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"(*.png)|*.png";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gadugi", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 5);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 16);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Ход:";
			// 
			// StepLable
			// 
			this->StepLable->AutoSize = true;
			this->StepLable->Font = (gcnew System::Drawing::Font(L"Gadugi", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StepLable->Location = System::Drawing::Point(46, 5);
			this->StepLable->Name = L"StepLable";
			this->StepLable->Size = System::Drawing::Size(92, 16);
			this->StepLable->TabIndex = 3;
			this->StepLable->Text = L"защищающий";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(448, 231);
			this->Controls->Add(this->StepLable);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximumSize = System::Drawing::Size(464, 334);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		//Ход игрока на доступные ячейки 
private: System::Void dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int rowIndexCurN = dataGridView->CurrentCell->RowIndex; 
	int columnIndexCurN = dataGridView->CurrentCell->ColumnIndex;
	//проверями что выбрана новая ячейка
	if (rowIndexCurN == rowIndexCur && columnIndexCurN == columnIndexCur) {
	}else if (dataGridView->Rows[rowIndexCurN]->Cells[columnIndexCurN]->Style->BackColor == System::Drawing::Color::PaleGoldenrod) {
		int igr = positionMass[rowIndexCur][columnIndexCur]; // текущая позиция
		positionMass[rowIndexCurN][columnIndexCurN] = igr;//новыя позиция куда идти 
		positionMass[rowIndexCur][columnIndexCur] = 0;
		//отрисовываем новое положиние
		DrawTable(dataGridView);
		DrawStartPosition(dataGridView, pathEmpty, pathKnaz, pathZach, pathNApad, positionMass);
		
		//выводим чей ход теперь
		if (isNapad) {
			isNapad = false;
			StepLable->Text = "защищающий";

		}
		else {
			isNapad = true;
			StepLable->Text = "нападающий";


		}

	}

}
	   //подсвечиваем доступные ходы
private: System::Void dataGridView_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	//System::Windows::Forms::DataGridView^ Obereg::MainForm::
	DrawTable(dataGridView);
	 rowIndexCur = dataGridView->CurrentCell->RowIndex; // Получаем индекс текущей  строки выбранной ячейки 
	 columnIndexCur = dataGridView->CurrentCell->ColumnIndex;
	 boolean checkStep = false;
	 //проверям игрок выбрал своб фишку? 
	 if (isNapad && positionMass[rowIndexCur][columnIndexCur] == 1) {
		 checkStep = true;
	 }
	 else if (!isNapad && positionMass[rowIndexCur][columnIndexCur] != 1) {
		 checkStep = true;

	 }else checkStep = false;

	if (positionMass[rowIndexCur][columnIndexCur]==0) {
	}
	else if (checkStep) {
		//если выбрал свою
		dataGridView->Rows[rowIndexCur]->Cells[columnIndexCur]->Style->BackColor = System::Drawing::Color::PaleGoldenrod;
		//переменные определяющие направление закраса
		boolean isZakrachV = true;
		boolean isZakrachN = true;
		boolean isZakrachP = true;
		boolean isZakrachL = true;

		int k = 9;
		//если князь то перемежение доступно только на 3 ячейки
		if (positionMass[rowIndexCur][columnIndexCur] == 3) {
			k = 3;
		}
		for (int i = 1; i < k; i++)
		{
			//проверяем что доступные ячейки пусты и подсвечиваем их во всех направляених
			if (rowIndexCur + i < 9) {
				if (positionMass[rowIndexCur + i][columnIndexCur] == 0 && isZakrachV) {
					dataGridView->Rows[rowIndexCur + i]->Cells[columnIndexCur]->Style->BackColor = System::Drawing::Color::PaleGoldenrod;

				}
				else {
					isZakrachV = false;
				}
			}
			if (0 <= rowIndexCur - i){
				if (positionMass[rowIndexCur - i][columnIndexCur] == 0 && isZakrachN) {
					dataGridView->Rows[rowIndexCur - i]->Cells[columnIndexCur]->Style->BackColor = System::Drawing::Color::PaleGoldenrod;

				}
				else {
					isZakrachN = false;
				}
			} 
			if (columnIndexCur + i < 9) {
				if (positionMass[rowIndexCur][columnIndexCur + i] == 0 && isZakrachP) {
					dataGridView->Rows[rowIndexCur]->Cells[columnIndexCur + i]->Style->BackColor = System::Drawing::Color::PaleGoldenrod;

				}
				else {
					isZakrachP = false;
				}
			}
			if(0 <= columnIndexCur - i){
				if (positionMass[rowIndexCur][columnIndexCur - i] == 0 && isZakrachL) {
					dataGridView->Rows[rowIndexCur]->Cells[columnIndexCur - i]->Style->BackColor = System::Drawing::Color::PaleGoldenrod;

				}
				else {
					isZakrachL = false;
				}
			}
		}
		//прорисовываем выходы и трон князя 
		if (positionMass[rowIndexCur][columnIndexCur] != 3) {
			dataGridView->Rows[0]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
			dataGridView->Rows[0]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
			dataGridView->Rows[8]->Cells[8]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
			dataGridView->Rows[8]->Cells[0]->Style->BackColor = System::Drawing::Color::LightSeaGreen;
			dataGridView->Rows[4]->Cells[4]->Style->BackColor = System::Drawing::Color::Crimson;
		}
	
	}
}
}
	;};

