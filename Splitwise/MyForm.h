#pragma once

namespace Splitwise {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:

        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        System::ComponentModel::Container^ components;
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
        System::Windows::Forms::Button^ button1;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
            this->flowLayoutPanel1->Location = System::Drawing::Point(47, 199);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(732, 221);
            this->flowLayoutPanel1->TabIndex = 0;
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(114)));
            this->button1->Location = System::Drawing::Point(778, 485);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(96, 36);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Add";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // MyForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(900, 600);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->flowLayoutPanel1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            int textBoxCount = 0;
            TextBox^ newTextBox1 = gcnew TextBox();
            TextBox^ newTextBox2 = gcnew TextBox();

            newTextBox1->Name = "NameTextBox" + textBoxCount++;
            newTextBox1->Location = Drawing::Point(20, 20 + textBoxCount * 30);
            newTextBox1->Name = "name";

            newTextBox2->Name = "AmountTextBox" + textBoxCount++;
            newTextBox2->Location = Drawing::Point(20, 50 + textBoxCount * 30);
            newTextBox2->Name = "amount";

            // Parent the TextBox controls to the FlowLayoutPanel
            flowLayoutPanel1->Controls->Add(newTextBox1);
            flowLayoutPanel1->Controls->Add(newTextBox2);
        }
        void TextBox_Paint(Object^ sender, PaintEventArgs^ e)
        {
            TextBox^ textBox = (TextBox^)sender;

            String^ backgroundText = "";
            if (textBox->Name == "Name")
            {
                backgroundText = "Enter name here";
            }
            else if (textBox->Name == "Amount")
            {
                backgroundText = "Enter amount here";
            }

            // Check if the TextBox is empty and doesn't have focus
            if (String::IsNullOrEmpty(textBox->Text) && !textBox->Focused)
            {
                SolidBrush^ brush = gcnew SolidBrush(Color::Gray);
                // Draw the background text
                e->Graphics->DrawString(backgroundText, textBox->Font, brush, PointF(1, 1));
                delete brush;
            }
        }
    };
}
