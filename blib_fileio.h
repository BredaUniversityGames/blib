#pragma once

#include <vector>
#include <string>

// We use a namespace to not clash with other code
namespace blib::io
{
	std::vector<char> read_binary_file(const std::string& filename);
	std::string read_text_file(const std::string& filename);
	bool write_binary_file(const std::vector<char>& data, const std::string& filename);
	bool write_text_file(const std::string& text, const std::string& filename);
	bool exists(const std::string& filename);
}
