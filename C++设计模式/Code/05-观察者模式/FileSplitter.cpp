#include <string>
#include <list>

class IProgress
{
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress() {}
};

class FileSplitter
{
	std::string m_filePath;
	int m_fileNumber;

	
	//ProgressBar* m_progressBar; // 通知控件
	std::list<IProgress*> m_ProgressList; // 抽象通知机制，支持多个观察者

public:
	FileSplitter(const std::string& filePath, int fileNumber) :
		m_filePath(filePath),
		m_fileNumber(fileNumber)
	{}

	void add_IProgress(IProgress* iProgress)
	{
		m_ProgressList.push_back(iProgress);
	}

	void remove_IProgress(IProgress* iProgress)
	{
		m_ProgressList.remove(iProgress);
	}

	void split() {
		// 1. 读取大文件
		// 2. 分批次向小文件中写入
		for (int i = 0; i <= m_fileNumber; ++i)
		{
			if (m_Progress != nullptr)
			{
				float progressValue;
				progressValue = (i + 1) / m_fileNumber;
				m_Progress->DoProgress(progressValue); // 更新进度条
			}
		}
	}
protected:
	virtual void onProgress(float value)
	{
		auto itor = m_ProgressList.begin();

		while (itor != m_ProgressList.end())
		{
			
			itor.operator++;
		}
	}
};
