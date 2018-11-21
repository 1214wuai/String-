#include"String.h"
void TestString()
{
	wg::String s1;
	s1.Print();
	wg::String s2("Hello");
	//s2.Print();
	//wg::String s3(s2);
	//s3.Print();
	//s2.Print();
	s1 = s2;
	s1.Print();
	s2.Print();
}

void TestSizeCa()
{
	wg::String s1("good job!!!");
	cout << s1.Capacity() << endl;
	cout << s1.Size() << endl;
}

void TestPush()
{
	wg::String s1("hello");
	s1.PushBack('k');
	s1.Print();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Append("word");
	s1.Print();
	s1 += ('!');
	s1.Print();
}

void Testadd()
{
	wg::String s1("Hello");
	s1.operator+=('x');
	s1.Print();
}

void TestFind()
{
	wg::String s1("good job!");
	cout << s1.Find('d', 0) << endl;
	cout << s1.Find('d', 5) << endl;
	cout << s1.Find('x', 0) << endl;
	cout << s1.Find("od", 1) << endl;
	cout << s1.Find("od ", 1) << endl;
	cout << s1.Find("odx", 2) << endl;
	cout << s1.Find("xx", 5) << endl;
	cout << s1.Size() << endl;
}

void TestInsert()
{
	wg::String s1("god");
	s1.Insert(1, 'o');
	cout << s1.Size() << endl;
	s1.Print();//good
	s1.Insert(5, " job");
	cout << s1.Size() << endl;
	s1.Print();
}

void TestErease()
{
	wg::String s1("hello word");
	s1.Erease(8, 10);
	s1.Print();
}

void TestXiabiao()
{
	wg::String s1("hello");
	s1[0] = 'H';
	cout << s1[0] << endl;
	const char s = s1[1];
	// s = 'E';
	cout << s << endl;
}

void TestResize()
{
	wg::String s1("hello");
	s1.Resize(8, 'x');
	s1.Print();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Resize(3, 'x');
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Print();
}

void TestReserve()
{
	wg::String s1("hello");
	s1.Reserve(20);
	s1.Print();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Reserve(5);
	s1.Print();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Reserve(4);
	s1.Print();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	s1.Reserve(20);
	s1.Print();
	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
}

void TestCompare()
{
	wg::String s1("wor");
	wg::String s2("word");
	wg::String s3("a");
	wg::String s4("b");

	//cout << (s1 == s1) << endl;
	//cout << (s2 != s2) << endl;
	//cout << (s3 < s4) << endl;
	//cout << (s2 <= s2) << endl;
	//cout << (s4 > s3) << endl;
	cout << (s3 >= s4) << endl;


}
int main()
{
	//TestResize();
	//Testadd();
	//TestInsert();
	//TestPush();
	//TestReserve();

	//TestString();
	//TestSizeCa();
	//TestFind();
	//TestErease();
	//TestXiabiao();
	TestCompare();
	system("pause");
	return 0;
}
