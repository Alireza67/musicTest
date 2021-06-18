#include<iostream>
#include<windows.h>
#include<fstream>
#include <conio.h>
using namespace std;

int main()
{
	char audiofile_char[50];
	string audiofile_str;
	fstream fp;

	cout << "Enter the name of an audio file: ";
	cin >> audiofile_char;
	auto file_name = std::string(audiofile_char);
	string path = "..\\music\\";
	string extension = ".wav";
	auto full_path = path + file_name + extension;

	fp.open(full_path, ios::in);
	if (fp)
	{
		std::wstring stemp = std::wstring(full_path.begin(), full_path.end());
		LPCWSTR sw = stemp.c_str();
		auto result = PlaySound(sw, NULL, SND_ASYNC);
	}
	else
	{
		cout << "\nAudio file couldn't run..!!";
		cout <<
			"\nCheck the following things: \n 1. Your file is an original .wav audio file. \n 2. You have mentioned '.wav' extension in the name of file. \n 3. It is present in the folder where your program is saved.";
	}
	_getch();
	fp.close();

	return 0;
}
