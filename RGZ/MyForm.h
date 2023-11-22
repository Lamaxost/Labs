#pragma once
#include <corecrt_math.h>

namespace RGZ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
	private: System::Windows::Forms::Label^ CSideLabel;
	private: System::Windows::Forms::TextBox^ CSideInput;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::Label^ BSideLabel;
	private: System::Windows::Forms::TextBox^ BSideInput;



	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Label^ ASideLabel;
	private: System::Windows::Forms::TextBox^ ASideInput;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;
	private: System::Windows::Forms::Label^ UnitLabel;
	private: System::Windows::Forms::ComboBox^ UnitSelect;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel8;
	private: System::Windows::Forms::Button^ CalculateButton;

	private: System::Windows::Forms::TextBox^ AreaOutput;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ AreaLabel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel9;
	private: System::Windows::Forms::Label^ RoundingLabel;
	private: System::Windows::Forms::TextBox^ RoundingCountInput;











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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->UnitLabel = (gcnew System::Windows::Forms::Label());
			this->UnitSelect = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CSideLabel = (gcnew System::Windows::Forms::Label());
			this->CSideInput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->BSideLabel = (gcnew System::Windows::Forms::Label());
			this->BSideInput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ASideLabel = (gcnew System::Windows::Forms::Label());
			this->ASideInput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->CalculateButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->AreaOutput = (gcnew System::Windows::Forms::TextBox());
			this->AreaLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->RoundingLabel = (gcnew System::Windows::Forms::Label());
			this->RoundingCountInput = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.5654F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 81.4346F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(568, 247);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(562, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Обчислення площи трикутника";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel7, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel6, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel8, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel9, 2, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 48);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.8984F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 63.1016F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(562, 196);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel7->Controls->Add(this->UnitLabel, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->UnitSelect, 1, 0);
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 75);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(181, 118);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// UnitLabel
			// 
			this->UnitLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->UnitLabel->AutoSize = true;
			this->UnitLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UnitLabel->Location = System::Drawing::Point(4, 44);
			this->UnitLabel->Name = L"UnitLabel";
			this->UnitLabel->Size = System::Drawing::Size(81, 30);
			this->UnitLabel->TabIndex = 0;
			this->UnitLabel->Text = L"Одиниці вимірювання";
			this->UnitLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// UnitSelect
			// 
			this->UnitSelect->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->UnitSelect->FormattingEnabled = true;
			this->UnitSelect->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"см", L"м" });
			this->UnitSelect->Location = System::Drawing::Point(93, 48);
			this->UnitSelect->Name = L"UnitSelect";
			this->UnitSelect->Size = System::Drawing::Size(85, 21);
			this->UnitSelect->TabIndex = 1;
			this->UnitSelect->Text = L"см";
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->CSideLabel, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->CSideInput, 0, 1);
			this->tableLayoutPanel6->Location = System::Drawing::Point(377, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(181, 63);
			this->tableLayoutPanel6->TabIndex = 3;
			// 
			// CSideLabel
			// 
			this->CSideLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->CSideLabel->AutoSize = true;
			this->CSideLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CSideLabel->Location = System::Drawing::Point(44, 10);
			this->CSideLabel->Name = L"CSideLabel";
			this->CSideLabel->Size = System::Drawing::Size(93, 21);
			this->CSideLabel->TabIndex = 0;
			this->CSideLabel->Text = L"Сторона c";
			// 
			// CSideInput
			// 
			this->CSideInput->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->CSideInput->Location = System::Drawing::Point(40, 34);
			this->CSideInput->Name = L"CSideInput";
			this->CSideInput->Size = System::Drawing::Size(100, 20);
			this->CSideInput->TabIndex = 1;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Controls->Add(this->BSideLabel, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->BSideInput, 0, 1);
			this->tableLayoutPanel5->Location = System::Drawing::Point(190, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(181, 63);
			this->tableLayoutPanel5->TabIndex = 2;
			// 
			// BSideLabel
			// 
			this->BSideLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->BSideLabel->AutoSize = true;
			this->BSideLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BSideLabel->Location = System::Drawing::Point(43, 10);
			this->BSideLabel->Name = L"BSideLabel";
			this->BSideLabel->Size = System::Drawing::Size(94, 21);
			this->BSideLabel->TabIndex = 0;
			this->BSideLabel->Text = L"Сторона b";
			// 
			// BSideInput
			// 
			this->BSideInput->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->BSideInput->Location = System::Drawing::Point(40, 34);
			this->BSideInput->Name = L"BSideInput";
			this->BSideInput->Size = System::Drawing::Size(100, 20);
			this->BSideInput->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->ASideLabel, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->ASideInput, 0, 1);
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(181, 63);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// ASideLabel
			// 
			this->ASideLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->ASideLabel->AutoSize = true;
			this->ASideLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ASideLabel->Location = System::Drawing::Point(44, 10);
			this->ASideLabel->Name = L"ASideLabel";
			this->ASideLabel->Size = System::Drawing::Size(92, 21);
			this->ASideLabel->TabIndex = 0;
			this->ASideLabel->Text = L"Сторона а";
			// 
			// ASideInput
			// 
			this->ASideInput->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ASideInput->Location = System::Drawing::Point(40, 34);
			this->ASideInput->Name = L"ASideInput";
			this->ASideInput->Size = System::Drawing::Size(100, 20);
			this->ASideInput->TabIndex = 1;
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 1;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->Controls->Add(this->CalculateButton, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel8->Location = System::Drawing::Point(190, 75);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 2;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(181, 118);
			this->tableLayoutPanel8->TabIndex = 1;
			// 
			// CalculateButton
			// 
			this->CalculateButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CalculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CalculateButton->Location = System::Drawing::Point(38, 14);
			this->CalculateButton->Name = L"CalculateButton";
			this->CalculateButton->Size = System::Drawing::Size(105, 31);
			this->CalculateButton->TabIndex = 0;
			this->CalculateButton->Text = L"Обчислити";
			this->CalculateButton->UseVisualStyleBackColor = true;
			this->CalculateButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->AreaOutput, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->AreaLabel, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 62);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(175, 53);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// AreaOutput
			// 
			this->AreaOutput->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AreaOutput->Location = System::Drawing::Point(7, 29);
			this->AreaOutput->Name = L"AreaOutput";
			this->AreaOutput->ReadOnly = true;
			this->AreaOutput->Size = System::Drawing::Size(160, 20);
			this->AreaOutput->TabIndex = 1;
			// 
			// AreaLabel
			// 
			this->AreaLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->AreaLabel->AutoSize = true;
			this->AreaLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AreaLabel->Location = System::Drawing::Point(55, 5);
			this->AreaLabel->Name = L"AreaLabel";
			this->AreaLabel->Size = System::Drawing::Size(64, 21);
			this->AreaLabel->TabIndex = 2;
			this->AreaLabel->Text = L"Площа";
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 2;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel9->Controls->Add(this->RoundingLabel, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->RoundingCountInput, 1, 0);
			this->tableLayoutPanel9->Location = System::Drawing::Point(377, 75);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(182, 118);
			this->tableLayoutPanel9->TabIndex = 4;
			// 
			// RoundingLabel
			// 
			this->RoundingLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RoundingLabel->AutoSize = true;
			this->RoundingLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RoundingLabel->Location = System::Drawing::Point(3, 21);
			this->RoundingLabel->Name = L"RoundingLabel";
			this->RoundingLabel->Size = System::Drawing::Size(85, 76);
			this->RoundingLabel->TabIndex = 0;
			this->RoundingLabel->Text = L"До скількох знаків після коми округлити";
			this->RoundingLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RoundingCountInput
			// 
			this->RoundingCountInput->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->RoundingCountInput->Location = System::Drawing::Point(94, 49);
			this->RoundingCountInput->Name = L"RoundingCountInput";
			this->RoundingCountInput->Size = System::Drawing::Size(85, 20);
			this->RoundingCountInput->TabIndex = 1;
			this->RoundingCountInput->Text = L"5";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 261);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// Checking for input errors
		if (!this->UnitSelect->SelectedItem) {
			MessageBox::Show("Ви не обрали одиниці вимірювання !", "Помилка!");
			return;
		}
		String^ unit = this->UnitSelect->SelectedItem->ToString();
		if (!unit->Equals("м") && !unit->Equals("см")) {
			MessageBox::Show("Неправильно введені одиниці вимірювання", "Помилка!");
			return;
		}
		int roundingCount;
		double a, b, c;

		try {
			a = Convert::ToDouble(ASideInput->Text);
		}
		catch (Exception^ e) {
			MessageBox::Show("Помилкове значення сторони а!", "Помилка!");
			return;
		}
		try {
			b = Convert::ToDouble(BSideInput->Text);
		}
		catch (Exception^ e) {
			MessageBox::Show("Помилкове значення сторони b!", "Помилка!");
			return;
		}
		try {
			c = Convert::ToDouble(CSideInput->Text);
		}
		catch (Exception^ e) {
			MessageBox::Show("Помилкове значення сторони c!", "Помилка!");
			return;
		}
		try {
			roundingCount = Convert::ToInt32(RoundingCountInput->Text);
		}
		catch (Exception^ e) {
			MessageBox::Show("Помилкове значення округлення!", "Помилка!");
			return;
		}

		bool triangleExists = a < b + c && b < c + a && c < b + a;
		if (!triangleExists) {
			MessageBox::Show("Трикутник не існує!", "Помилка!");
			return;
		}


		// convert values to CI system
		if (unit->Equals("см")) {
			a /= 100;
			b /= 100;
			c /= 100;
		}

		// calculating area
		double p = (a + b + c)/2;
		double area = sqrt(p * (p - a) * (p - b) * (p - c));


		// converting area to output units

		if (unit->Equals("см")) {
			area *= 10000;
		}


		//rounding

		area = round(area * pow(10, roundingCount)) / pow(10, roundingCount);


		// displaying area with squared unit
		String^ resultText = area.ToString() + " " + unit+"^2";
		AreaOutput->Text = resultText;
	}
};
}
