#include <iostream>

using namespace std;

class Caixa{
	protected:
	   	double largura;	
};

class SmallBox:Caixa{ //SmallBox é derivada da classe Caixa (child classes or derived classes)
	public:
		void setSmallBoxLargura(double larg);
		double getSmallBoxLargura(void);
};

// Member function da classe 'child'
void SmallBox::setSmallBoxLargura(double larg){
	largura = larg;
}
double SmallBox::getSmallBoxLargura(void){
	return largura;
}

int main() {
	SmallBox caixinha;
	
	// Set 'caixinha' usando Member Function
	caixinha.setSmallBoxLargura(5);
	cout<<"A largura da caixinha eh: "<<caixinha.getSmallBoxLargura()<<endl;
	return 0;
	
}