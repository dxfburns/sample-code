#include "stdafx.h"
#include <iostream>
using namespace std;

namespace DesignPattern_Adapter {
	class Adaptee {
	public:
		void SpecialRequest() { printf("Run SpecialRequest in Adaptee\n"); }
	};

	class Target {
	public:
		virtual void Request() = 0;
	};

	class Adapter : public Target, private Adaptee {
	public:
		virtual void Request() { SpecialRequest(); }
	};

	class AnotherAdapter : public Adapter {
	public:
		void Request() {printf("Run SpecialRequest in AnotherAdapter\n");}
		void Special_Request() { Adapter::Request();}
	};
}

namespace DesignPattern_AbstractFactory {
	class AbstractProductA{
	};
	class ProductA1 :  public AbstractProductA {
	};
	class ProductA2 :  public AbstractProductA {
	};

	class AbstractProductB{
	};
	class ProductB1 :  public AbstractProductB {
	};
	class ProductB2 :  public AbstractProductB {
	};

	class AbstractFactory {
	public:
		virtual AbstractProductA* CreateProductA() = 0;
		virtual AbstractProductB* CreateProductB() = 0;
	};

	class ConcreteFactory1:public AbstractFactory {
	public:
		virtual AbstractProductA* CreateProductA() {
			return new ProductA1;
		}
		virtual AbstractProductB* CreateProductB() {
			return new ProductB1;
		}

		static ConcreteFactory1* Instance() {
			static ConcreteFactory1 instance;
			return &instance;
		}

		ConcreteFactory1() {}
	private:
		ConcreteFactory1(const ConcreteFactory1&);
		ConcreteFactory1& operator = (const ConcreteFactory1&);
	};

	class ConcreteFactory2:public AbstractFactory {
	public:
		virtual AbstractProductA* CreateProductA() {
			return new ProductA2;
		}
		virtual AbstractProductB* CreateProductB() {
			return new ProductB2;
		}

		static ConcreteFactory2* Instance() {
			static ConcreteFactory2 instance;
			return &instance;
		}

		ConcreteFactory2() {}
	private:
		ConcreteFactory2(const ConcreteFactory2&);
		ConcreteFactory2& operator = (const ConcreteFactory2&);
	};
}

void run_design_pattern() {
	using namespace DesignPattern_Adapter;
	Target* p = new Adapter;
	p->Request();

	Adapter* ap = new AnotherAdapter();
	ap->Request();

	using namespace DesignPattern_AbstractFactory;
	AbstractFactory* p_factory = ConcreteFactory1::Instance();
	AbstractProductA* p_productA = p_factory->CreateProductA();
	AbstractProductB* p_productB = p_factory->CreateProductB();

	p_factory = ConcreteFactory2::Instance();
	p_productA = p_factory->CreateProductA();
	p_productB = p_factory->CreateProductB();
}