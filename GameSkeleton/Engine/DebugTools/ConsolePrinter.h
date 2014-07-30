#pragma once
#include <glm\glm.hpp>
#include <Qt\qstring.h>
#include <iostream>

using glm::vec3;
using glm::vec2;
using glm::vec4;
using glm::mat4;

using std::cout;
using std::endl;

class __declspec(dllexport) ConsolePrinter
{
private:
	ConsolePrinter(){}
	ConsolePrinter(ConsolePrinter const&);
	ConsolePrinter& operator = (ConsolePrinter const&);
	static ConsolePrinter* theInstance;

public:
	static ConsolePrinter& getInstance();
	void print(float f, char* label);
	void print(float f, QString label);
	void print(vec3 v, QString label);
	void print(vec3 v, char* label);
	void print(vec2 v, char* label);
	void print(vec4 v, char* label);
	void print(mat4 m, char* label);
	void print(bool b, char* label);
	void print(QString qstr, char* label);
	void print(QString qstr);
	void print(char* text);

};

