#include <functional>
#include <iostream>
class MyTest {
public:
	MyTest() = default;
	void doCalc() {
		// 干其他事
		// 执行回调
		if (myCallBack != nullptr)
		{
			myCallBack(1, 2);
		}
	}

	using callback_t = std::function<void(const int& a, const int& b)>;

	// 注册回调
	void setCallBackHandler(const callback_t& cb) {
		myCallBack = cb;
	}

private:
	// 定义回调
	callback_t myCallBack;
};

// 回调函数
void handleCallBack(const int& a, const int& b) {
	std::cout << "this is from callback handleCallBack" << std::endl;
}

int main() {
	MyTest t;

	MyTest* t1 = nullptr;
	t1 = new MyTest;

	if (t1)
	{
		std::cout << "t1" << std::endl;
	}

	// 回调函数
	auto f = [](const int&a, const int& b) {
		std::cout << "this is from callback f" << std::endl;
	};

	// 注册回调
	// 写法一
	//t.setCallBackHandler(f);

	// 写法二
	//t.setCallBackHandler([&f](auto &&a, auto &&b) {
	//	f(std::forward<decltype(a)>(a), std::forward<decltype(b)>(b));
	//	});

	// 写法三
	t.setCallBackHandler([](auto &&a, auto &&b) {
		handleCallBack(std::forward<decltype(a)>(a), std::forward<decltype(b)>(b));
		});

	t.doCalc();
}