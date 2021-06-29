#include "Search_Engine.h"

namespace XMLConverter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for XML_converter
	/// </summary>
	public ref class XML_converter : public System::Windows::Forms::Form
	{
	public:
		XML_converter(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		String^ file_path_entry;
		static std::string GetOutputFileName();
		std::string GetOutputFileType();
		static System::Windows::Forms::TextBox^ output_name_box;
		static System::Windows::Forms::CheckBox^ txt_check_box;
		static System::Windows::Forms::CheckBox^ csv_check_box;
		static System::Windows::Forms::ProgressBar^ progress_bar;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~XML_converter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ open_xml_file_dialog;
	private: System::Windows::Forms::Button^ convert_button;
	private: System::Windows::Forms::Label^ input_label;
	private: System::Windows::Forms::Label^ output_label;
	private: System::Windows::Forms::TextBox^ input_name;
	private: System::Windows::Forms::Button^ open_dialog_button;
	private: System::ComponentModel::IContainer^ components;

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
			this->open_xml_file_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->convert_button = (gcnew System::Windows::Forms::Button());
			this->input_label = (gcnew System::Windows::Forms::Label());
			this->output_label = (gcnew System::Windows::Forms::Label());
			this->output_name_box = (gcnew System::Windows::Forms::TextBox());
			this->progress_bar = (gcnew System::Windows::Forms::ProgressBar());
			this->input_name = (gcnew System::Windows::Forms::TextBox());
			this->open_dialog_button = (gcnew System::Windows::Forms::Button());
			this->txt_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->csv_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// open_xml_file_dialog
			// 
			this->open_xml_file_dialog->RestoreDirectory = true;
			this->open_xml_file_dialog->Title = L"Select XML File";
			this->open_xml_file_dialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &XML_converter::openFileDialog1_FileOk);
			// 
			// convert_button
			// 
			this->convert_button->Location = System::Drawing::Point(420, 100);
			this->convert_button->Name = L"convert_button";
			this->convert_button->Size = System::Drawing::Size(145, 40);
			this->convert_button->TabIndex = 0;
			this->convert_button->Text = L"Convert";
			this->convert_button->UseVisualStyleBackColor = true;
			this->convert_button->Click += gcnew System::EventHandler(this, &XML_converter::convert_button_Click);
			// 
			// input_label
			// 
			this->input_label->AutoSize = true;
			this->input_label->BackColor = System::Drawing::Color::Transparent;
			this->input_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->input_label->Location = System::Drawing::Point(13, 15);
			this->input_label->Name = L"input_label";
			this->input_label->Size = System::Drawing::Size(115, 20);
			this->input_label->TabIndex = 1;
			this->input_label->Text = L"Select XML file";
			// 
			// output_label
			// 
			this->output_label->AutoSize = true;
			this->output_label->BackColor = System::Drawing::Color::Transparent;
			this->output_label->Location = System::Drawing::Point(13, 61);
			this->output_label->Name = L"output_label";
			this->output_label->Size = System::Drawing::Size(130, 20);
			this->output_label->TabIndex = 2;
			this->output_label->Text = L"Output file name:";
			// 
			// output_name_box
			// 
			this->output_name_box->Location = System::Drawing::Point(150, 59);
			this->output_name_box->Name = L"output_name_box";
			this->output_name_box->Size = System::Drawing::Size(270, 26);
			this->output_name_box->TabIndex = 3;
			// 
			// progress_bar
			// 
			this->progress_bar->Location = System::Drawing::Point(17, 110);
			this->progress_bar->Name = L"progress_bar";
			this->progress_bar->Size = System::Drawing::Size(378, 21);
			this->progress_bar->TabIndex = 5;
			this->progress_bar->Visible = false;
			// 
			// input_name
			// 
			this->input_name->Location = System::Drawing::Point(150, 13);
			this->input_name->Name = L"input_name";
			this->input_name->Size = System::Drawing::Size(270, 26);
			this->input_name->TabIndex = 6;
			// 
			// open_dialog_button
			// 
			this->open_dialog_button->Location = System::Drawing::Point(450, 13);
			this->open_dialog_button->Name = L"open_dialog_button";
			this->open_dialog_button->Size = System::Drawing::Size(80, 28);
			this->open_dialog_button->TabIndex = 7;
			this->open_dialog_button->Text = L"Open";
			this->open_dialog_button->UseVisualStyleBackColor = true;
			this->open_dialog_button->Click += gcnew System::EventHandler(this, &XML_converter::open_dialog_button_Click);
			// 
			// txt_check_box
			// 
			this->txt_check_box->AutoSize = true;
			this->txt_check_box->Location = System::Drawing::Point(445, 61);
			this->txt_check_box->Name = L"txt_check_box";
			this->txt_check_box->Size = System::Drawing::Size(56, 24);
			this->txt_check_box->TabIndex = 8;
			this->txt_check_box->Text = L".txt";
			this->txt_check_box->UseVisualStyleBackColor = true;
			this->txt_check_box->CheckedChanged += gcnew System::EventHandler(this, &XML_converter::txt_check_box_CheckedChanged);
			// 
			// csv_check_box
			// 
			this->csv_check_box->AutoSize = true;
			this->csv_check_box->Checked = true;
			this->csv_check_box->CheckState = System::Windows::Forms::CheckState::Checked;
			this->csv_check_box->Location = System::Drawing::Point(507, 61);
			this->csv_check_box->Name = L"csv_check_box";
			this->csv_check_box->Size = System::Drawing::Size(62, 24);
			this->csv_check_box->TabIndex = 9;
			this->csv_check_box->Text = L".csv";
			this->csv_check_box->UseVisualStyleBackColor = true;
			this->csv_check_box->CheckedChanged += gcnew System::EventHandler(this, &XML_converter::csv_check_box_CheckedChanged);
			// 
			// XML_converter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(575, 147);
			this->Controls->Add(this->csv_check_box);
			this->Controls->Add(this->txt_check_box);
			this->Controls->Add(this->open_dialog_button);
			this->Controls->Add(this->input_name);
			this->Controls->Add(this->progress_bar);
			this->Controls->Add(this->output_name_box);
			this->Controls->Add(this->output_label);
			this->Controls->Add(this->input_label);
			this->Controls->Add(this->convert_button);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"XML_converter";
			this->Text = L"XML_converter";
			this->Load += gcnew System::EventHandler(this, &XML_converter::XML_converter_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void XML_converter_Load(System::Object^ sender, System::EventArgs^ e) { }
		
		private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { }
		
		private: System::Void open_dialog_button_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			open_xml_file_dialog->Filter = "XML files (*.xml) | *.xml";
			open_xml_file_dialog->ShowDialog();
			String^ file_path = open_xml_file_dialog->FileName;
			file_path_entry = file_path;

			String^ substring = file_path;
			unsigned int last_pos = substring->LastIndexOf("\\");
			substring = substring->Substring(last_pos + 1);
			input_name->Text = substring;
		}

		static std::string MarshalString(String^ windows_file_path, std::string& file_path)
		{
			const char* kPtoC = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(windows_file_path)).ToPointer();
			file_path = kPtoC;
			Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)kPtoC));

			return file_path;
		}
		
		private: System::Void convert_button_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			progress_bar->Increment(-100);
			progress_bar->Visible = true;

			if (output_name_box->Text == "")
				output_name_box->Text = "XML Converter - default output";

			std::string pth = "";
			if (file_path_entry != nullptr)
			{
				std::string file_content = SearchEngine::SearchEngine::GetFileContent(MarshalString(file_path_entry, pth));
				SearchEngine::SearchEngine::SearchThroughFile(file_content);
			}
			else 
				return;
		}
		private: System::Void txt_check_box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			if (txt_check_box->Checked == true)
				csv_check_box->Checked = false;
		}
		private: System::Void csv_check_box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			if (csv_check_box->Checked == true)
				txt_check_box->Checked = false;
		}
};
}
