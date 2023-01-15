#include<iostream>
#include<math.h>
using namespace std;

class Sophuc{
	
	private:
		double real, img;
	
	public:
		friend istream& operator >> ( istream& in, Sophuc &a);
		friend ostream& operator << ( ostream& out, Sophuc a);
		Sophuc operator + ( Sophuc another );
		Sophuc operator - ( Sophuc another );
		Sophuc operator * ( Sophuc another );
		Sophuc operator / ( Sophuc another );
		bool operator == ( Sophuc another);
		void print(){
			cout << real << "+" << img <<"i" << endl;
		}
		
		double dodai();
};

	istream& operator >> ( istream& in, Sophuc &a){
		in >> a.real >> a.img;
		return in;
	}
	
	ostream& operator << ( ostream& out, Sophuc a){
		out << a.real << a.img ; 
	}
	
	double Sophuc :: dodai(){
		return sqrt( real * real + img * img);
	}
	
	Sophuc Sophuc :: operator + (Sophuc another){
		Sophuc tong;
		tong.real = this->real + another.real;
		tong.img = this-> img + another.img ; 
		return tong;
	}
	
	Sophuc Sophuc :: operator - (Sophuc another){
		Sophuc hieu;
		hieu.real = real - another.real;
		hieu.img = img - another.img ; 
		return hieu;
	}
	
	Sophuc Sophuc :: operator * (Sophuc another){
		Sophuc tich;
		tich.real = real * another.real - img * another.img;
		tich.img = real * another.img + img * another.real;
		return tich;
	}
	
	Sophuc Sophuc :: operator / (Sophuc another){
		Sophuc thuong;
		thuong.real = (real * another.real + img * another.img) / ( another.real *  another.real +   another.img *  another.img);
		thuong.img = (img * another.real - real * another.img) / ( another.real *  another.real +   another.img *  another.img);
		return thuong;
	}
	
	bool Sophuc :: operator == ( Sophuc another){
		return ( dodai() == another.dodai());
	}
	
int main(){
	Sophuc a,b;
	cout<< "nhap so phuc a: ";
	cin >> a;
	a.print();
	
	cout<< "nhap so phuc b: ";
	cin >> b;
	b.print();
	
	Sophuc tong = a + b;
	cout<< "tong hai so phuc la: ";
	tong.print();
	
	Sophuc hieu = a-b;
	cout<< "hieu hai so phuc la: ";
	hieu.print();
	
	Sophuc tich = a * b;
	cout<< "tich hai so phuc la: ";
	tich.print();
	
	Sophuc thuong = a / b;
	cout<< "thuong hai so phuc la: ";
	thuong.print();
	
	if( a == b) cout<< " a = b ";
	else cout << " a != b";
}