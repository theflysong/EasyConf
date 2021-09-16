#pragma once
#include "ECCommon.h"

namespace esc {
	class Token {
	public:
		enum class Type {
			NOP = 0,
			IDENTIFIER,
			NUMBER,
			COMMA,
			COLON,
			STRING,
			LEFT_PAREN,
			RIGHT_PAREN,
			LEFT_BRACE,
			RIGHT_BRACE,
			LEFT_BRACKET,
			RIGHT_BRACKET,
			DOT
		};
	private:
		Type type;
		std::string content;
		int column;
		int line;
	public:
		Token();
		Token(Type type, std::string content, int column = 0, int line = 0);
		Type getType();
		std::string getContent();
		int getColumn();
		int getLine();
	};
	
	class TokenGroup {
		std::vector<Token> tokens;
		int cur_pos;
	public:
		TokenGroup();
		TokenGroup(std::vector<Token> tokens);
		Token current(); //get current token
		Token forward(); //get next token
		Token backward(); //get last token
		Token next(); //get next token and change the position
		Token last(); //get last token and change the position
		void resetToStart();
	};
	
	std::string to_string(Token token);
	std::string to_string(Token::Type token);
	class Lexan {
		std::string code;
		int pos;
		Token _BinNumber(Recorder recorder);
		Token _OctNumber(Recorder recorder);
		Token _DecNumber(Recorder recorder);
		Token _HexNumber(Recorder recorder);
		Token _OctOrHexNumber(Recorder recorder);
		Token _String(Recorder recorder);
		Token _Identifier(Recorder recorder);
	static std::map<char, Token::Type> sign2type;
		Token _Sign(Recorder recorder);
		void info(Recorder recorder, std::string msg);
		void warn(Recorder recorder, std::string msg);
		void error(Recorder recorder, std::string msg);
		void fatal(Recorder recorder, std::string msg);
	public:
		Lexan(std::string code);
		Token generate(Recorder recorder = Recorder());
		TokenGroup generateAll(Recorder recorder = Recorder());
	};
}
