#include<iostream>
using namespace std;

class complex {
	float real, img;

	public:
	complex() {
		real = img = 0;
	}		
	complex(float x) {
		real = img = x;
	}
	complex(float x, float y) {
		real = x;
		img = y;
	}
	
	void add(complex, complex);
	void divide(complex, complex);
	void multiply(complex, complex);
	void show();
};

void complex::add(complex x, complex y) {
	
	real = x.real + y.real;
	img = x.img + y.img;	
}
void complex::divide(complex x, complex y) {
	
	float denominator = ((y.real * y.real) + (y.img * y.img));
	real = ((x.real * y.real) + (x.img * y.img))/denominator;
	img = ((y.real * x.img) - (x.real * y.img))/denominator;
}
void complex::multiply(complex x, complex y) {
	real = ((x.real * y.real) - (x.img * y.img));
	img = ((x.real * y.img) + (y.real * x.img));
}
void complex::show() {
	if(img > 0) cout<< " "<< real << " + " << img << "i \n";
	else cout<< " "<< real << img << "i \n";
}
int main() {                               
	complex A(2.0, 2.3), B(9.1), C, D, E;
	cout<< " A is: \n";
	A.show();
	cout<< " B is: \n";
	B.show();
	cout<< "\n Adding A & B : \n";
	C.add(A, B);
	C.show();
	cout<< "\n Dividing A with B : \n";
	D.divide(A, B);
	D.show();
	cout<< "\n Multiplying A with B : \n";
	E.multiply(A, B);
	E.show();
	return 0;
}
