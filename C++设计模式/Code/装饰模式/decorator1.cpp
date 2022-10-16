class Stream
{
public:
	virtual char Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {};
};

class FileStream : public Stream
{

};

class NetworkStream : public Stream
{

};

class MemoryStream : public Stream
{

};