#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void PrintFileContacte(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read mod

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
	}
	MyFile.close();
}

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}
		MyFile.close();
	}
}

void SaveDataFromVectorToFile(string FileName, vector <string> vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//write Mode
	if (MyFile.is_open())
	{
		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

void DeleteDataFromVectorToFile(string FileName, string Record)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Record == Line)
		{
			Line = "";
		}
	}
	SaveDataFromVectorToFile(FileName, vFileContent);
}

void UpdateDataFromVectorToFile(string FileName, string Record, string UpdateTo)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Record == Line)
		{
			Line = UpdateTo;
		}
	}
	SaveDataFromVectorToFile(FileName, vFileContent);
}

int main()
{
	
	cout << "File Content Before Delete.\n";
	PrintFileContacte("myhamood.txt");
	DeleteDataFromVectorToFile("myhamood.txt", "Ali");

	cout << "\n\nFile Content After Delete.\n";
	PrintFileContacte("myhamood.txt");

	UpdateDataFromVectorToFile("myhamood.txt", "Fadi", "Hamood");
	cout << "\n\nFile Content After Update.\n";
	PrintFileContacte("myhamood.txt");
}