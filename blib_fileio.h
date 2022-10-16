#pragma once

#include <vector>
#include <string>

// We use a namespace to not clash with other code
namespace blib::io
{
	std::vector<char> read_binary_file(const std::string& filename)
	{
		FILE* file = nullptr;
		fopen_s(&file, filename.c_str(), "r");
		if (!file)
			return {};

		fseek(file, 0, SEEK_END);
		long fileSize = ftell(file);

		fseek(file, 0, 0);

		std::vector<char> buffer(static_cast<size_t>(fileSize));
		size_t return_val = fread_s(buffer.data(), buffer.size() * sizeof(char), sizeof(char), buffer.size(), file);

		fclose(file);

		return buffer;
	}

	std::string read_text_file(const std::string& filename)
	{
		FILE* file = nullptr;
		fopen_s(&file, filename.c_str(), "r");
		if (!file)
			return {};

		fseek(file, 0, SEEK_END);
		long fileSize = ftell(file);

		fseek(file, 0, 0);

		std::string buffer;
		buffer.resize(static_cast<size_t>(fileSize));
		size_t return_val = fread_s(buffer.data(), buffer.size() * sizeof(char), sizeof(char), buffer.size(), file);

		if (buffer[buffer.size() - 1] != '\0')
			buffer.push_back('\0');

		fclose(file);

		return buffer;
	}

	bool write_binary_file(const std::vector<char>& data, const std::string& filename)
	{
		FILE* file = nullptr;
		fopen_s(&file, filename.c_str(), "w+");
		if (!file)
			return false;

		size_t count_written = fwrite(data.data(), sizeof(char), data.size(), file);
		if (count_written != data.size())
		{
			fclose(file);
			return false;
		}

		fclose(file);

		return true;
	}

	bool write_text_file(const std::string& text, const std::string& filename)
	{
		FILE* file = nullptr;
		fopen_s(&file, filename.c_str(), "w+");
		if (!file)
			return false;

		size_t count_written = fwrite(text.data(), sizeof(char), text.size(), file);
		if (count_written != text.size())
		{
			fclose(file);
			return false;
		}

		fclose(file);

		return true;
	}

	bool exists(const std::string& filename)
	{
		bool exists = false;
		FILE* file = nullptr;
		fopen_s(&file, filename.c_str(), "r");

		exists = (file != nullptr) ? true : false;

		if (file)
			fclose(file);

		return exists;
	}
}
