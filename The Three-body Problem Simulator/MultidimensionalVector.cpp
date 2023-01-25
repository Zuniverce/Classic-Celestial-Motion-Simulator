#include "MultidimensionalVector.h"
#include "Global.h"

//int MultidimensionalVector::dimension = ZERO;

void MultidimensionalVector::setDimension() {
	while (dimension <= ZERO) {
		cout << "维度: " << endl;
		cin >> dimension;
	}
}

MultidimensionalVector::MultidimensionalVector(void) {
	/*this->x = ZERO;
	this->y = ZERO;
	this->z = ZERO;*/;
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(ZERO);
	}
}
MultidimensionalVector::MultidimensionalVector(const MultidimensionalVector& other) {
	/*this->x = other.x;
	this->y = other.y;
	this->z = other.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(other.coordinate[i]);
	}
}
MultidimensionalVector::MultidimensionalVector(const vector<double>&origin) {
	/*this->x = X;
	this->y = Y;
	this->z = Z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(origin[i]);
	}
}
MultidimensionalVector& MultidimensionalVector::setSpaceVector(const MultidimensionalVector& origin, const double& modulus) {
	MultidimensionalVector unitVector(origin.getUnitVector());
	/*this->x = modulus * unitVector.x;
	this->y = modulus * unitVector.y;
	this->z = modulus * unitVector.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] = (modulus * unitVector.coordinate[i]);
	}
	return *this;
}

MultidimensionalVector& MultidimensionalVector::operator=(const MultidimensionalVector& other) {
	/*this->x = other.x;
	this->y = other.y;
	this->z = other.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] = other.coordinate[i];
	}
	return *this;
}
MultidimensionalVector MultidimensionalVector::operator*(const double& scalarMultiplier)const {
	/*return MultidimensionalVector(
		this->x * scalarMultiplier,
		this->y * scalarMultiplier,
		this->z * scalarMultiplier
	);*/
	vector<double>product;
	for (int i = ZERO; i < dimension; i++) {
		product.push_back(this->coordinate[i] * scalarMultiplier);
	}
	return MultidimensionalVector(product);
}
MultidimensionalVector MultidimensionalVector::operator/(const double& scalarDivisor)const {
	/*return MultidimensionalVector(
		this->x / scalarDivisor,
		this->y / scalarDivisor,
		this->z / scalarDivisor
	);*/
	vector<double>quotient;
	for (int i = ZERO; i < dimension; i++) {
		quotient.push_back(this->coordinate[i] / scalarDivisor);
	}
	return MultidimensionalVector(quotient);
}
MultidimensionalVector MultidimensionalVector::operator+(const MultidimensionalVector& vectorAddend)const {
	/*return MultidimensionalVector(
		this->x + vectorAddend.x,
		this->y + vectorAddend.y,
		this->z + vectorAddend.z
	);*/
	vector<double>sum;
	for (int i = ZERO; i < dimension; i++) {
		sum.push_back(this->coordinate[i] + vectorAddend.coordinate[i]);
	}
	return MultidimensionalVector(sum);
}
MultidimensionalVector MultidimensionalVector::operator-(const MultidimensionalVector& vectorSubtrahend)const {
	/*return MultidimensionalVector(
		this->x - vectorSubtrahend.x,
		this->y - vectorSubtrahend.y,
		this->z - vectorSubtrahend.z
	);*/
	vector<double>difference;
	for (int i = ZERO; i < dimension; i++) {
		difference.push_back(this->coordinate[i] - vectorSubtrahend.coordinate[i]);
	}
	return MultidimensionalVector(difference);
}
//MultidimensionalVector MultidimensionalVector::operator/(const MultidimensionalVector& vectorDivisor)const {
//	return MultidimensionalVector(
//		this->x - vectorDivisor.x,
//		this->y - vectorDivisor.y,
//		this->z - vectorDivisor.z
//	);
//}
MultidimensionalVector& MultidimensionalVector::operator+=(const MultidimensionalVector& vectorAddend)
{
	/*this->x += vectorAddend.x;
	this->y += vectorAddend.y;
	this->z += vectorAddend.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] += vectorAddend.coordinate[i];
	}
	return *this;
}

double MultidimensionalVector::getModulus(void) const {
	/*return sqrt(
		SQR(this->x)
		+ SQR(this->y)
		+ SQR(this->z)
	);*/
	return sqrt(this->getSquareModulus());
}
double MultidimensionalVector::getSquareModulus(void) const {
	/*return SQR(this->x)
		+ SQR(this->y)
		+ SQR(this->z);*/
	double squareModulus = ZERO;
	for (int i = ZERO; i < dimension; i++) {
		squareModulus += SQR(this->coordinate[i]);
	}
	return squareModulus;
}
void MultidimensionalVector::print(void)
{
	/*cout << "("
		<< this->x << ", "
		<< this->y << ", "
		<< this->z << ")"
		<< endl;*/
	cout << "(";
	cout << this->coordinate[ZERO];
	for (int i = ONE; i < dimension; i++) {
		cout << ", " << this->coordinate[i];
	}
	cout << ")" << endl;
}
double MultidimensionalVector::getSquareModulus(const MultidimensionalVector& A, const MultidimensionalVector& B)
{
	return (A - B).getSquareModulus();
}
MultidimensionalVector MultidimensionalVector::getUnitVector(void) const
{
	/*double modulus = this->getModulus();
	return MultidimensionalVector(
		this->x / modulus,
		this->y / modulus,
		this->z / modulus);*/
	return *this / this->getModulus();
}
