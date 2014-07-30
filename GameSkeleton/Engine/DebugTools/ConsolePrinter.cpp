#include "ConsolePrinter.h"

ConsolePrinter* ConsolePrinter::theInstance;

ConsolePrinter& ConsolePrinter::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new ConsolePrinter();
	}
	return *theInstance;
}
void ConsolePrinter::print(float f, char* label = "")
{
	cout << label << f << endl;
}
void ConsolePrinter::print(float f, QString label = "")
{
	cout << label.toLocal8Bit().constData() << f << endl;
}
void ConsolePrinter::print(vec3 v, char* label = "")
{
	cout << label << "("<< v.x << "," << v.y << "," << v.z << ")" << endl;
}
void ConsolePrinter::print(vec3 v, QString label = "")
{
	cout << label.toLocal8Bit().constData() << "("<< v.x << "," << v.y << "," << v.z << ")" << endl;
}
void ConsolePrinter::print(vec2 v, char* label = "")
{
	cout << label << "("<< v.x << "," << v.y << ")" << endl;
}
void ConsolePrinter::print(vec4 v, char* label = "")
{
	cout << label << "("<< v.x << "," << v.y << "," << v.z << ","<< v.w << ")" << endl;
}
void ConsolePrinter::print(mat4 m, char* label = "")
{
	if(label!="")
	{
		cout << label << endl;
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			cout << i << j << "[" << m[i][j] <<"],"<< endl;
		}
	}
}
void ConsolePrinter::print(bool b, char* label = "")
{
	cout << label << b << endl;
}
void ConsolePrinter::print(QString qstr, char* label = "")
{
	cout << label << qstr.toLocal8Bit().constData() << endl;
}
void ConsolePrinter::print(char* text)
{
	cout << text << endl;
}
void ConsolePrinter::print(QString qstr)
{
	cout << qstr.toLocal8Bit().constData() << endl;

}