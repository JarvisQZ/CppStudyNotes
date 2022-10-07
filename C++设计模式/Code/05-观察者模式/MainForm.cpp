#include <string>
#include <iostream>
class MainForm : public Form
{
	TextBox* textFilePath;
	TextBox* textFileNumber;

	ProgressBar* progressBar;
public:
	void Button1_Click()
	{
		std::string filePath = textFilePath->getText();
		int number = atoi(textFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number, progressBar);

		splitter.split();
	}
};

class ConsoleNotier : public IProgress
{

public:
	virtual void DoProgress(float value) override
	{
		std::cout << ".";
	}
};