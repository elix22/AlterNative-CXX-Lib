#include "Console.h"
#include "String.h"

#include <iostream>

namespace System {

	void Console::Write(char* txt) {
		std::cout << txt;
	}

	void Console::Write(int i) {
		std::cout << i;
	}

	void Console::Write(String* s) {
		std::cout << *s;
	}

	void Console::WriteLine(char* txt) {
		std::cout << txt << std::endl;
	}

	void Console::WriteLine(Array<char>* c) {
		std::cout << c->GetData() << std::endl;
	}

	void Console::WriteLine(int i) {
		std::cout << i << std::endl;
	}

	void Console::WriteLine(float f) {
		std::cout << f << std::endl;
	}

	void Console::WriteLine(double d) {
		std::cout << d << std::endl;
	}

	void Console::WriteLine(Object* o) {
		WriteLine(o->ToString());
	}

	void Console::WriteLine(String* s) {
		std::cout << *s << std::endl;
	}

	String* Console::ReadLine() {
		char* tmp = new char[256];
		std::cin.getline (tmp,256);

		String* s = new String(tmp);
		return s;
	}

}
