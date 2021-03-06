#pragma once
#include <vector>
#include "Collections/Generic/IteratorCXX.h"
#include <iostream>

using namespace std;
using namespace System::Collections::Generic;
namespace System{
	namespace __Internal__ {
		template<typename T>
		class Array_T_Base : public Object{
		private:
			TypeDecl(T)* data;
		public:
			int Length;
			Array_T_Base()
			{
				this->Length = 0;
			}

			Array_T_Base(int Length)
			{
				data = new TypeDecl(T)[Length];
				this->Length = Length;
			}

			Array_T_Base(T* elements, int Length)
			{
				data = new T[Length];
				for(int i = 0; i < Length; i++)
				{
					data[i] = *(elements + i);
				}
				this->Length = Length;
			}

			void SetData(int index, TypeDecl(T) element)
			{
				data[index] = element;
			}

			TypeDecl(T) GetData(int index)
			{
				return data[index];
			}

			operator T*()
			{
				return data;
			}

			TypeDecl(T) operator[](int index)
			{
				//if(index < 0 || index >= Length)
					//throw exception();//Message
				return data[index];
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* begin()
			{			
				return data->begin();				
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* begin() const
			{
				return data->begin();
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* end()
			{			
				return data->end();
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* end() const
			{
				return data->end();
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* rbegin()
			{			
				return data->rbegin();
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* rbegin() const
			{
				return data->rbegin();
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* rend()
			{			
				return data->rend();
			}

			System::Collections::Generic::iteratorcxx<TypeArg(T)>* rend() const
			{
				return data->rend();
			}
		};


		template< typename T, bool>
		class Array{
		};

		template<typename T>
		class Array<T, true> : public Array_T_Base<T>{
		public:
			Array() : Array_T_Base<T>(){}
			Array(int Length) : Array_T_Base<T>(Length){}
			Array(T* elements, int Length) : Array_T_Base<T>(elements, Length){}
		};

		template<typename T>
		class Array<T, false> : public Array_T_Base<Object*>{
		public:
			inline Array() : Array_T_Base<Object*>(){}
			inline Array(int Length) : Array_T_Base<Object*>(Length){}
			inline Array(T* elements, int Length) : Array_T_Base<Object*>((Object**)(elements), Length){}
			
			inline void SetData(int index, T* element){
				Array_T_Base<Object*>::SetData(index, (Object*)element);
			}

			inline T* operator[](int index){
				return reinterpret_cast<T*>(Array_T_Base<Object*>::operator[](index));//CUIDADO EL CAST
			}

			inline T* GetData(int index){
				return reinterpret_cast<T*>(Array_T_Base<Object*>::GetData(index));//CUIDADO EL CAST
			}
		};
	}

	template<typename T>
	class Array : public __Internal__::Array<T, IsValueType(T)>{
	public:
		Array() : __Internal__::Array<T, IsValueType(T)>(){}
		Array(int Length) : __Internal__::Array<T, IsValueType(T)>(Length){}
		Array(T* elements, int Length) : __Internal__::Array<T, IsValueType(T)>(elements, Length){}	
	};
}
