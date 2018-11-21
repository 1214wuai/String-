#include"String.h"

bool posSize(size_t size, size_t pos)
{
	if (pos>size)
	{
		cout << "字符串长度没有" << pos << endl;
		return true;
	}
	return false;
}
size_t wg::String::Size() const
{
	return _size;
}

size_t wg::String::Capacity() const
{
	return _capacity;
}

void wg::String::PushBack(char ch)
{
	CheckCapacity(1);
	/**(_str + _size) = ch;
	++_size;
	*(_str + _size) = '\0';*/
	_str[_size++] = ch;
	_str[_size] = '\0';
}

void wg::String::Append(const char* str)
{

	if (str == NULL)
		return;
	int count = strlen(str);
	CheckCapacity(count);
	char* tmp = _str + _size;
	while (*str != '\0')
	{
		*tmp++ = *str++;
		++_size;
	}
	*(_str + _size) = '\0';
	return;
}

wg::String& wg::String::operator+=(char ch)
{
	CheckCapacity(1);

	*(_str + _size) = ch;
	++_size;
	*(_str + _size) = '\0';
	return *this;
}

wg::String& wg::String::operator+=(const char *str)
{
	if (str == NULL)
		return *this;
	int count = strlen(str);
	CheckCapacity(count);
	char* tmp = _str + _size;
	while (*str != '\0')
	{
		*tmp++ = *str++;
		++_size;
	}
	*(_str + _size) = '\0';
	return *this;
}

size_t wg::String::Find(char ch, size_t pos)
{
	if (pos>_size)
		return -1;
	char* tmp = _str + pos;
	int count = pos;
	while (*tmp != '\0')
	{
		//  int count = pos;
		if (*tmp == ch)
		{
			return count;
		}
		tmp++;
		count++;
	}
	return -1;
	/*while (pos > _size)
	{
		if (*(_str + pos) = ch)
			return pos;
		++pos;
	}
	return npos;*/
}

size_t wg::String::Find(const char* str, size_t pos)
{
	if (pos>_size)
		return -1;
	char* tmp = _str + pos;
	//char* start = tmp;
	size_t count = pos;
	while ((*tmp != '\0') && (*str != '\0'))
	{
		//size_t count = pos;
		char* start = tmp;
		const char *cur = str;
		while ((*cur != '\0') && (*start != '\0') && (*start == *cur))
		{
			cur++;
			start++;
		}
		if ((*cur != '\0') && (*start != '\0'))//*str!= *start都没到尾就退出了，tmp要++
		{
			tmp++;
			count++;
			if ((*cur != '\0') && (*tmp == '\0'))//找完，不匹配
				return -1;
		}
		if ((*cur == '\0'))//找完，匹配
			return count;
	}
	return -1;
}

void wg::String::Insert(size_t pos, char ch)
{
	if (posSize(_size, pos))
		return;
	CheckCapacity(1);
	char *cur = _str + pos;
	size_t N = _size + 1;
	size_t old = _size;
	for (size_t i = 0; i<_size - pos + 1; i++)
	{
		*(_str + N) = *(_str + old);
		--N;
		--old;
	}
	*(_str + pos) = ch;
	_size += 1;
	_capacity = 2 * _size;
	return;
}

void wg::String::Insert(size_t pos, const char* str)
{
	if (posSize(_size, pos))
		return;
	int count = strlen(str);
	CheckCapacity(count);
	size_t count2 = 0;
	const char*cur = str;
	while (*cur != '\0')
	{
		count2++;
		cur++;
	}
	size_t old = _size;
	size_t N = old + count2;
	for (size_t i = 0; i<_size - pos + 1; i++)
	{
		*(_str + N) = *(_str + old);
		--N;
		--old;
	}
	cur = str;
	char *In = _str + pos;
	while (*cur != '\0')
	{
		*In++ = *cur++;
	}
	_size += count2;
	_capacity = 2 * _size;
	return;
}

void wg::String::Erease(size_t pos, size_t len)
{
	if (pos + len>_size)
		return;
	char * prev = _str + pos;
	char * cur = prev + len;
	while (*cur != '\0')
	{
		*prev++ = *cur++;
	}
	*prev = '\0';
	_size -= len;
	_capacity = 2 * _size;
	//assert(pos < _size);
	//if (len == npos || pos + len >= _size)
	//{
	//	_str[pos] = '\0';
	//	_size = pos;
	//}
	//else
	//{
	//	for (size_t i = 0; i < len; i++)
	//	{
	//		_str[pos] = _str[pos + len];
	//		pos++;
	//	}
	//	_size -= pos;
	//	_str[_size] = '\0';
	//}
}

char& wg::String::operator[](size_t pos)
{
	//if(posSize(_size,pos))
	//  return 0;
	return *(_str + pos);
}

const char& wg::String::operator[](size_t pos) const
{
	//if(posSize(_size,pos))
	//  return 0;
	return *(_str + pos);
}
void wg::String::Resize(size_t n, char ch)
{
	
	CheckCapacity(n);
	size_t x = n;
	_capacity = 2 * n;
	if (_size>n)
	{
		char* cur = _str + n;
		*cur = '\0';
		_size = n;
	}
	else {
		*(_str + n) = '\0';
		--n;
		while (n >= _size)
		{
			*(_str + n) = ch;
			--n;
		}
		_size = x;
	}
}

void wg::String::Reserve(size_t n)
{
	char* tmp = new char[n+1];
	if (n > _capacity)
	{
		strcpy(tmp, _str);
		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
	else//新容量小于原来的容量
	{
		if (n >= _size)//新容量大于等于size
		{
			tmp[n] = '\0';
			strncpy(tmp, _str,n);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		else//n<size  新容量小于size
		{
			tmp[n] = '\0';
			strncpy(tmp, _str, n);
			delete[] _str;
			_str = tmp;
			_capacity = n;
			_size = n;
		}
	}
}

bool wg::String::operator<(const String& s)
{
	char* cur1 = _str;//s2
	char * cur2 = s._str;
	while (*cur1 && *cur2)
	{
		if (*cur1 == *cur2)
		{
			cur1++;
			cur2++;
		}
		else if (*cur1 > *cur2)
			return false;
		else
			return true;
	}
	if (*cur1 > *cur2)
		return false;
	else if (*cur1 == *cur2)
		return false;
	else
		return true;
	
}
bool wg::String::operator<=(const String& s)
{
	return ((_str < s._str) || (_str == s._str));
}
bool wg::String::operator>(const String& s)
{
	return !(_str <= s._str);
}
bool wg::String::operator>=(const String& s)
{
	return !(_str < s._str);
}
bool wg::String::operator==(const String& s)
{
	char *cur1 = _str;
	char *cur2 = s._str;
	while (*cur1&&
			*cur2&&
			*cur1++ == *cur2++)
	{
		;
	}
	if (*cur1 == *cur2)
		return true;
	else
		return false;
}

bool wg::String::operator!=(const String& s)
{
	return !(_str == s._str);
}

