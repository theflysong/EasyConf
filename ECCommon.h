#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
namespace esc {
	class Recorder {
		std::istream& info_stream;
		std::istream& warn_stream;
		std::istream& error_stream;
		std::istream& fatal_stream;
	public:
		std::istream& info();
		std::istream& warn();
		std::istream& error();
		std::istream& fatal();
		Recoder(std::istream& info_stream = std::cin, std::istream& warn_stream = std::cin, std::istream& error_stream = std::cin, std::istream& fatal_stream = std::cin);
	};
}
