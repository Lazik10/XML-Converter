#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Search_Engine.h"
#include "XML_converter.h"

namespace SearchEngine
{

    struct Product
    {
        std::string product_id;
        std::string product_title;
        std::string product_price;
        std::string product_sale_price;
        std::string product_custom_label;
        std::string product_description;
        std::string product_image_link;
        std::string product_additional_image_link;
        std::string product_link;
        std::string product_availability;
        std::string product_type;
        std::string product_google_category;
        std::string product_condition;
        std::string product_gtin;
        std::string product_brand;
        std::string product_identifier_exists;
        std::string product_custom_label_0;
        std::string product_custom_label_1;
    };

    // To Do: Make it config based
    const unsigned int MAX_ENTRIES = 16;
    std::string product_entities[]
    {
                "id","title","price","custom_label_2","description","image_link",
                "additional_image_link","availability","product_type","google_product_category",
                "condition","gtin","brand","identifier_exists","custom_label_0","custom_label_1"
    };

    SearchEngine::SearchEngine()
    {
        // Constructor
    }

    SearchEngine::~SearchEngine()
    {
        // Destructor
    }

    std::string SearchEngine::GetFileContent(std::string file_name)
    {
        std::ifstream xml_file_input;
        xml_file_input.open(file_name); //open the input file
        if (!xml_file_input.is_open())
            return "Failed to load file";

        //XMLConverter::XML_converter::progress_bar->Visible = false;
        std::stringstream strStream;
        strStream << xml_file_input.rdbuf(); //read the file
        std::string xml_content = strStream.str(); //str holds the content of the file

        return xml_content;
    };

    void SearchEngine::ExportToExcel(std::string file_name, std::string file_content, bool endl)
    {
        std::string output_type;
        if ((XMLConverter::XML_converter::txt_check_box->Checked) == true)
            output_type = ".txt";
        else if ((XMLConverter::XML_converter::csv_check_box->Checked) == true)
            output_type = ".csv";
        std::ofstream xlsx_file_output(file_name + output_type, std::ios::app);
        xlsx_file_output << file_content;

        if (endl == true)
            xlsx_file_output << std::endl;
    };

    void SearchEngine::SearchThroughFile(std::string input)
    {
        std::string file_content = input;
        std::string file_name = XMLConverter::XML_converter::GetOutputFileName();
        std::string new_file_output = "";

        unsigned int first_pos = 0;
        unsigned int last_pos = 0;
        unsigned int entry_pos = file_content.find("<entry>", 0);

        int file_lenght = file_content.length();
        int file_lenght_percentage = file_lenght / 100;

        while (file_content.find("<entry>", entry_pos) != -1)
        {
            entry_pos++;
            entry_pos = file_content.find("<entry>", entry_pos);

            XMLConverter::XML_converter::progress_bar->Increment(entry_pos / file_lenght_percentage);

            for (int i = 0; i < MAX_ENTRIES; i++)
            {
                first_pos = file_content.find("<g:" + product_entities[i] + ">", entry_pos);
                last_pos = file_content.find("</g:" + product_entities[i] + ">", entry_pos);

                if (file_content.find("<g:" + product_entities[i] + ">", first_pos) != -1)
                {
                    std::string product_entity = file_content.substr(first_pos + 4 + product_entities[i].length(),
                        last_pos - first_pos - product_entities[i].length() - 4);

                    new_file_output += product_entity + "@";

                    first_pos++;
                    last_pos++;
                }
                else
                {
                    ExportToExcel(file_name, new_file_output, true);
                    new_file_output = "";
                    break;
                }
            }

            ExportToExcel(file_name, new_file_output, true);
            new_file_output = "";
        }
    }
}