#pragma once

#include <vector>
#include <string>
#include <fstream>

// We use a namespace to not clash with other code
namespace blib::io
{

	std::vector<char> read_binary_file(const std::string& filename);
	std::string read_text_file(const std::string& filename);
	bool write_binary_file(const std::vector<char>& data, const std::string& filename);
	bool write_text_file(const std::string& text, const std::string& filename);
	bool exists(const std::string& filename);

	inline std::vector<char> read_binary_file(const std::string& filename)
	{
		std::ifstream stream(filename, std::ios::binary | std::ios::ate);
		if (!stream.is_open())
			return {};

		size_t size = stream.tellg();

		stream.seekg(0);

		std::vector<char> buffer(static_cast<size_t>(size));
		stream.read(buffer.data(), buffer.size());

		return buffer;
	}

	inline std::string read_text_file(const std::string& filename)
	{
		std::ifstream stream(filename, std::ios::ate);
		if (!stream.is_open())
			return {};

		size_t size = stream.tellg();

		stream.seekg(0);

		std::string buffer;
		buffer.reserve(size + 1);
		buffer.resize(size, '\0');
		stream.read(buffer.data(), buffer.size());

		// a const char* retrieved by string::data() or string::c_str() should already contain a null terminating character at the end of the string
		if (buffer.data()[buffer.size() - 1] != '\0')
			buffer.push_back('\0');


		return buffer;
	}

	inline bool write_binary_file(const std::vector<char>& data, const std::string& filename)
	{
		std::fstream file(filename, std::ios::binary | std::ios::out);
		
		if (!file.is_open())
			return false;

		file.write(data.data(), data.size());
		if (file.rdstate() & std::ios::badbit)
			return false;

		return true;
	}

	inline bool write_text_file(const std::string& text, const std::string& filename)
	{
		std::fstream file(filename, std::ios::out);

		if (!file.is_open())
			return false;

		file.write(text.data(), text.size());
		if (file.rdstate() & std::ios::badbit)
			return false;

		return true;
	}

	inline bool exists(const std::string& filename)
	{
		std::ifstream s(filename, std::ios::in);
		return s.is_open();
	}
}
