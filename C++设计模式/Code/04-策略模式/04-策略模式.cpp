#include <stdexcept>
enum class TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax,		// 更改
};

class SalseOrder {
	TaxBase tax;
public:
	double CalculateTax()
	{
		///...
		if (tax == TaxBase::CN_Tax)
		{
			///...
		}
		else if (tax == TaxBase::US_Tax)
		{
			///...
		}
		else if (tax == TaxBase::DE_Tax)
		{
			///...
		}
		else if (tax == TaxBase::FR_Tax)	// 更改
		{
			/// ...
		}
	}
};

class TaxStrategy {
public:
	virtual double Calculate(const Context& context) = 0;
	virtual ~TaxStrategy() {}
};

class CNTax : public TaxStrategy {
public:
	virtual double Calculate(const Context& context) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
};

class USTax : public TaxStrategy {
public:
	virtual double Calculate(const Context& context) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
};

class DETax : public TaxStrategy {
public:
	virtual double Calculate(const Context& context) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
};

class FRTax : public TaxStrategy {
public:
	virtual double Calculate(const Context& context) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
};

class SalseOrder1 {
private:
	TaxStrategy* strategy;

public:
	SalseOrder1(StrategyFactory* strategyFactory) {
		this->strategy = strategyFactory->NewStrategy();
	}
	~SalseOrder1() {
		delete this->strategy;
	}

	double CalculateTax() {
		///...
		Contex contex();

		double val = strategy->Calculate(contex); //多态调用
		///...
	}
};