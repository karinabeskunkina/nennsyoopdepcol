

#include <iostream>
using namespace std;



class Dol {
	string Valute;
	float prozent;
public:
	Dol() {
		Valute = "";
		prozent = 0;
	}
	Dol(string Valute, float prozent) {
		this->prozent = prozent;
		this->Valute = Valute;
	}
	float Get() {
		return prozent;
	}
	~Dol() {

	}
};

class Dep : public Dol{
	float summDep;
	int mont;
public:
	Dep(): Dol(){
		summDep = 0;
		mont = 0;
	}
	Dep(string Valute , float prozent, float summDep, int mont) : Dol(Valute, prozent) {
		this->mont = mont;
		this->summDep = summDep;
	}
	float Depoz();

	~Dep() {

	}
};

float Dep::Depoz() {
	while (mont > 0) {
		this->summDep = (this->summDep * (this->Get() / 100) / 365 * 30) + this->summDep;
		mont--;
	}
	return summDep;
}
int main()
{
	cout << "Summ_Dep: " << endl;
	float b;
	cin >> b;

	cout << "Mont: " << endl;
	int d;
	cin >> d;
	Dep a("$", 5, b, d);
	cout << a.Depoz();
}

