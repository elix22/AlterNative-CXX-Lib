#pragma once
#include "Object.h"
#include "String.h"

namespace System {
	class Console : public Object
	{
	public:

		static void Write(char* txt);
		static void Write(char txt);
		static void Write(int i);
		static void Write(bool i);
		static void Write(String* s);
		static void Write(float f);

		static void WriteLine(char* txt);
		static void WriteLine(char txt);
		static void WriteLine(int i);
		static void WriteLine(bool i);
		static void WriteLine(float i);
		static void WriteLine(double i);
		static void WriteLine(Object* i);
		static void WriteLine(Array<char>* c);
		static void WriteLine(String* s);
		static void WriteLine();

		static String* ReadLine();
	};
}