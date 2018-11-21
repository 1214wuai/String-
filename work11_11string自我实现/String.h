#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _STRING_H_
#define _STRING_H_ 
#include<string.h>
#include<iostream>
#include<assert.h>

using namespace std;
namespace wg {
	class String {
	public:
		//static size_t npos;
		typedef char* Iterator;
		String(const char* str = "")
			:_str(new char[2*strlen(str) + 1])
		{
			_size = strlen(str);
			_capacity = 2 * _size;
			//_str = new char[_size + 1];
			strcpy(_str, str);

		}
		
		void Swap(String& s1)
		{
			char *tmp = s1._str;
			s1._str = _str;
			_str = tmp;
			size_t tmpsize = s1._size;
			s1._size = _size;
			_size = tmpsize;
			size_t tmpCa = s1._capacity;
			s1._capacity = _capacity;
			_capacity = tmpCa;
		}
		//S2(s1)
		String(const String& s)
			:_str(NULL)
		{
			String tmp(s._str);
			this->Swap(tmp);//调完之后tmp自动销毁
		}
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}
		//////////////////////////////////////////////////
		/*String(const char* str = "")
		{
			if (str == NULL)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = 2 * _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}
		
		String(const String& s)
			:_str(new char[s._size+1])
			,_size(s._size)
			,_capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}

		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char*pStr = new char[s._capacity + 1];
			}
		}*/
		////////////////////////////////////////////////////
		Iterator Begin()
		{
			return _str;
		}
		Iterator End()
		{
			return _str + _size;
		}
		~String()
		{
			if(_str!=NULL)
				delete[] _str;
			_str = NULL;
			_size = 0;
			_capacity = 0;
		}
		//
		void PushBack(char ch);
		void Append(const char* str);
		String& operator+=(char ch);
		String& operator+=(const char *str);
		size_t Find(char ch, size_t pos = 0);
		size_t Find(const char* str, size_t pos = 0);
		void Insert(size_t pos, char ch);
		void Insert(size_t pos, const char* str);
		void Erease(size_t pos, size_t len = 0);
		//
		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;
		size_t Size() const;
		size_t Capacity()const;
		void Reserve(size_t n);
		void Resize(size_t n, char ch = '\0');


		bool operator<(const String& s);
		bool operator<=(const String& s);
		bool operator>(const String& s);
		bool operator>=(const String& s);
		bool operator==(const String& s);
		bool operator!=(const String& s);
		//void Clear();
		//void Swap();
		//const char* C_Str()const;
		//bool Empty();

		void Print()
		{
			cout << _str << endl;
		}
		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		void CheckCapacity(int count)
		{
			if (_size + count > _capacity )
			{
				size_t newCapacity = 2 * _capacity > (_capacity + count) ? 2 * _capacity : (_capacity + count);
				char* tmp = new char[newCapacity];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newCapacity;
			}
		}
	};

}

#endif
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		size_t i = 0;
//		int value = 0;
//		for (; i<nums.size(); i++)
//		{
//			value ^= nums[i];
//		}
//		return value;
//	}
//};
//
//
//class Solution {
//public:
//	string NumsToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//
//	void _letterCombinations(const string& digits, size_t i, const string& s2, vector<string>& s1)
//	{
//		if (i == digits.size())
//		{
//			s1.push_back(s2);
//			return;
//		}
//		string letters = NumsToStr[digits[i] - '0'];//获取对应数字的字符数组
//		for (size_t j = 0; j<letters.size(); j++)
//		{
//			_letterCombinations(digits, i + 1, s2 + letters[j], s1);
//		}
//	}
//	vector<string> letterCombinations(string digits) {
//
//		vector<string> s1;
//		if (digits.empty())
//			return s1;
//		string s2;
//
//		size_t i = 0;
//		_letterCombinations(digits, i, s2, s1);
//		return s1;
//	}
//};
