#pragma once
#include <fstream>
#include <string>

namespace SearchEngine
{

	class SearchEngine
	{
	public:
		SearchEngine();
		~SearchEngine();

		static std::string GetFileContent(std::string file_name);
		static void SearchThroughFile(std::string file_content);
		static void ExportToExcel(std::string file_name, std::string file_content, bool endl);
	private:

	};

}