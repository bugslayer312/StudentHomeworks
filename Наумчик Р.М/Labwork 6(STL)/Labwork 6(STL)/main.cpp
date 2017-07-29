
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
//#include <exception> // библеотека ошибак
#include <algorithm> // работает со всеми контенерами
#include <functional>

std::vector<std::string> ReadFile(const char* readFile,
                                  std::vector<std::string>& vec) {
	std::ifstream filein;
	filein.open(readFile, std::ios_base::in);
	if (!filein.is_open())
	{
		std::cout << "File NOT found !!!" << std::endl;
		return vec;
	}
	// чтение в файл
	for (std::string value; filein >> value;)
	{
		vec.push_back(value);
	}
	filein.close();
	return vec;
}



//Task 2
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// удоление слов снеподходящей окончанием
class DeleteStringEnd{
	std::string ending_1, ending_2, ending_3;
public:
	DeleteStringEnd(std::string newEnding_1,
		            std::string newEnding_2,
		            std::string newEnding_3)
		            : ending_1(newEnding_1),
		              ending_2(newEnding_2),
		              ending_3(newEnding_3) {};
	bool operator()(const std::string& string) const {
		// остовляет слова с определенным окончанием
		return  string.compare(string.size() - ending_1.size(), ending_1.size(), ending_1) != 0 &&
			    string.compare(string.size() - ending_2.size(), ending_2.size(), ending_2) != 0 &&
			    string.compare(string.size() - ending_3.size(), ending_3.size(), ending_3) != 0;
	}
	~DeleteStringEnd(){};
};
// удоление слов или начало слов совпадающими с шаблоном
class DeleteString{
	 std::string string_1, string_2, string_3;
public:
	DeleteString(std::string newString_1,
		         std::string newString_2,
		         std::string newString_3)
		          : string_1(newString_1),
		            string_2(newString_2),
		            string_3(newString_3) {};
	bool operator()(const std::string& string) const {
		// удаляет определенные слова
		return  string.compare(string.size() - string.size(), string_1.size(), string_1) == 0 ||
			    string.compare(string.size() - string.size(), string_2.size(), string_2) == 0 ||
			    string.compare(string.size() - string.size(), string_3.size(), string_3) == 0;
	}
	~DeleteString(){};
};

// удоление слов снеподходящей длинной
class DeleteStringSize {
	 size_t sizeSuitable;
public:
	DeleteStringSize(size_t newsizeSuitable)
		            : sizeSuitable(newsizeSuitable) {};

	bool operator()(const std::string& string) const {
		return string.size() != sizeSuitable;
	}
	~DeleteStringSize(){};
};



std::vector<std::string> fooFileReadWrite(const char* readFile,
	                                      const char* writeFile,
	                                      std::vector<std::string>& myVec){
	ReadFile(readFile, myVec);

	std::ofstream fileout;
	fileout.open(writeFile, std::ios_base::out);
	if (!fileout.is_open())
	{
		std::cout << "File NOT found !!!" << std::endl;
		return myVec;
	}
	fileout << myVec.size();
	
	// удаляем строки не подходящай длинны
	myVec.erase((std::remove_if(myVec.begin(), myVec.end(),
		                DeleteStringSize(7))), myVec.end());
	
	// запись в файл
	for (size_t i(0); i < myVec.size(); ++i)   
	{
		fileout << "\n" << myVec.at(i);
	}
	fileout.close();
	return myVec;
}



// удаляет три определенных слова
std::vector<std::string> deleteString(const char* string_1,
	                                  const char* string_2,
	                                  const char* string_3,
	                                  std::vector<std::string>& myVec){
	myVec.erase((std::remove_if(myVec.begin(), myVec.end(),
		DeleteString(string_1, string_2, string_3))), myVec.end());
	return myVec;
}


void fooFileWrite(const char* writeFile,
	                          std::vector<std::string> myVec){
	//оставляем строки c подходящим окончанием
	myVec.erase((std::remove_if(myVec.begin(), myVec.end(),
		    DeleteStringEnd("ти","ть","чь"))), myVec.end());
	
	std::ofstream fileout;
	fileout.open(writeFile, std::ios_base::out);
	if (!fileout.is_open())
	{
		std::cout << "File NOT found !!!" << std::endl;
		return;
	}
	fileout << myVec.size();
	// запись в файл
	for (size_t i(0); i < myVec.size(); ++i)
	{
		fileout << " " << myVec.at(i);
	}
	fileout.close();
	// удалить из контенера первые два слова
	myVec.erase(myVec.begin(), myVec.begin() + 2);

	// удалить из контенера первые два слова
	std::vector	<size_t> numberSuitable = { 9, 17, 35, 40,
		                                   41, 42, 46, 51 };
	for (size_t i(0); i < numberSuitable.size(); ++i)
	{
		myVec.erase(myVec.begin() + numberSuitable.at(i));
	}
	//удалить определенные слова
	deleteString("полночь", "прихоть", "страсть", myVec);
	deleteString("рад", "роб", "сов", myVec);
	deleteString("рад", "роб", "сов", myVec);
	//вставляем элемент в начало 
	myVec.insert(myVec.begin(), "акать");
	//вставляем элемент в канец
	myVec.push_back("якать");
    //вставляем элемент перед определенного словом
	myVec.insert((std::find(myVec.begin(), myVec.end(), "обедать")) , "начать");
	
	fileout.open(writeFile, std::ios_base::out | std::ios_base::trunc);
	if (!fileout.is_open())
	{
		std::cout << "File NOT found !!!" << std::endl;
		return;
	}
	// запись в файл
	for (size_t i(0); i < myVec.size(); ++i)
	{
		fileout << " " << myVec.at(i);
	}
	fileout.close();
}


void testTurgenew()
{
	std::vector	<std::string> myVec;
	fooFileReadWrite("turgenev.txt", "turgenev_output.txt", myVec);
	fooFileWrite("Inf.txt", myVec);
}
//Task 3
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void testInput()
{
	std::vector	<std::string> myVec_1;
	std::vector	<std::string> myVec_2;
	std::vector	<std::string> vecOutput_1;
	std::vector	<size_t>      vecOutput_2;
	ReadFile("input.txt", myVec_1);
	ReadFile("test.txt", myVec_2);
	
	for (auto& elem : myVec_1) {
		size_t count = std::count(myVec_2.begin(), myVec_2.end(), elem);
		if (count) {
			vecOutput_1.push_back("YES");
		}
		else {
			vecOutput_1.push_back("NO ");
		}
		vecOutput_2.push_back(count);
	}
	std::ofstream fileout;
	fileout.open("Output.txt", std::ios_base::out | std::ios_base::trunc);
	if (!fileout.is_open())
	{
		std::cout << "File NOT found !!!" << std::endl;
		return;
	}
	// запись в файл
	for (size_t i(0); i < vecOutput_1.size(); ++i)
	{
		fileout << "\n" << vecOutput_1.at(i);
		fileout << "     " << vecOutput_2.at(i);
	}
	fileout.close();
}



void main()
{
	
 	testTurgenew(); // Task 2
	testInput();    // Task 3
	
	system("pause");
}