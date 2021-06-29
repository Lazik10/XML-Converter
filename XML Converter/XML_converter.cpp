#include "XML_converter.h"

using namespace XMLConverter;
[STAThreadAttribute]

int main()
{
    XML_converter xml_converter;
    xml_converter.ShowDialog();
    return 0;
}

std::string XML_converter::GetOutputFileName()
{
    std::string output_name_temp = "";
    std::string output_name = MarshalString(output_name_box->Text, output_name_temp);

    if (output_name == "")
        output_name = "XML_Converter_output";

    return output_name;
}

std::string XMLConverter::XML_converter::GetOutputFileType()
{
    std::string output_type;

    if (csv_check_box->Checked == true)
        output_type = ".csv";
    else if (txt_check_box->Checked == true)
        output_type = ".txt";

    return output_type;
}
