#pragma once
#include <System/Convert.h>
#include <stdint.h>

//#define IntPtr int*

namespace System{
	struct ValueType
	{
	public:
		//ToString
		//GetHashCode
	};


	//********************** Int
	struct Int : ValueType
	{
	public:
		static int Parse(String* text)
		{
			return System::Convert::ToInt32(text);
		}
	};

	struct Int32 : Int
	{};	

	struct IntPtr : ValueType{
		int* pointer;

		operator int*(){
			return pointer;
		}

		operator int(){
			return (int)(intptr_t)pointer;
		}

		IntPtr(int* other){
			pointer = other;
		}

		IntPtr(int other){
			pointer = (int*)(intptr_t)other;
		}
	};

	//********************* Float
	struct Float : ValueType
	{
	public:
		static float Parse(String* text)
		{
			return System::Convert::ToSingle(text);
		}
	};

	//********************* Double
	struct Double : ValueType
	{
	public:
		static double Parse(String* text)
		{
			return System::Convert::ToDouble(text);
		}
	};

	//********************* Long
	struct Long : ValueType
	{
	public:
		static long long Parse(String* text)
		{
			return System::Convert::ToInt64(text);
		}
	};
}

