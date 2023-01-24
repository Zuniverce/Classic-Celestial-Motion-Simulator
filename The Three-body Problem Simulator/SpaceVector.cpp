#include "SpaceVector.h"
#include "Global.h"

int SpaceVector::dimension = ZERO;

void SpaceVector::setDimension() {
	while (dimension <= ZERO) {
		cout << "维度: " << endl;
		cin >> dimension;
	}
}

SpaceVector::SpaceVector(void) {
	/*this->x = ZERO;
	this->y = ZERO;
	this->z = ZERO;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(ZERO);
	}
}
SpaceVector::SpaceVector(const SpaceVector& other) {
	/*this->x = other.x;
	this->y = other.y;
	this->z = other.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(other.coordinate[i]);
	}
}
SpaceVector::SpaceVector(const vector<double>& origin) {
	/*this->x = X;
	this->y = Y;
	this->z = Z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(origin[i]);
	}
}
SpaceVector& SpaceVector::setSpaceVector(const SpaceVector& origin, const double& modulus) {
	SpaceVector unitVector(origin.getUnitVector());/*
	this->x = modulus * unitVector.x;
	this->y = modulus * unitVector.y;
	this->z = modulus * unitVector.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(modulus * unitVector.coordinate[i]);
	}
	return *this;
}

SpaceVector& SpaceVector::operator=(const SpaceVector& other) {
	/*this->x = other.x;
	this->y = other.y;
	this->z = other.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(other.coordinate[i]);
	}
	return *this;
}
SpaceVector SpaceVector::operator*(const double& scalarMultiplier)const {
	/*return SpaceVector(
		this->x * scalarMultiplier,
		this->y * scalarMultiplier,
		this->z * scalarMultiplier
	);*/
	vector<double>product;
	for (int i = ZERO; i < dimension; i++) {
		product.push_back(this->coordinate[i] * scalarMultiplier);
	}
	return SpaceVector(product);
}
SpaceVector SpaceVector::operator/(const double& scalarDivisor)const {
	/*return SpaceVector(
		this->x / scalarDivisor,
		this->y / scalarDivisor,
		this->z / scalarDivisor
	);*/
	vector<double>quotient;
	for (int i = ZERO; i < dimension; i++) {
		quotient.push_back(this->coordinate[i] / scalarDivisor);
	}
	return SpaceVector(quotient);
}
SpaceVector SpaceVector::operator+(const SpaceVector& vectorAddend)const {
	/*return SpaceVector(
		this->x + vectorAddend.x,
		this->y + vectorAddend.y,
		this->z + vectorAddend.z
	);*/
	vector<double>sum;
	for (int i = ZERO; i < dimension; i++) {
		sum.push_back(this->coordinate[i] + vectorAddend.coordinate[i]);
	}
	return SpaceVector(sum);
}
SpaceVector SpaceVector::operator-(const SpaceVector& vectorSubtrahend)const {
	/*return SpaceVector(
		this->x - vectorSubtrahend.x,
		this->y - vectorSubtrahend.y,
		this->z - vectorSubtrahend.z
	);*/
	vector<double>difference;
	for (int i = ZERO; i < dimension; i++) {
		difference.push_back(this->coordinate[i] - vectorSubtrahend.coordinate[i]);
	}
	return SpaceVector(difference);
}
//SpaceVector SpaceVector::operator/(const SpaceVector& vectorDivisor)const {
//	return SpaceVector(
//		this->x - vectorDivisor.x,
//		this->y - vectorDivisor.y,
//		this->z - vectorDivisor.z
//	);
//}
SpaceVector& SpaceVector::operator+=(const SpaceVector& vectorAddend)
{
	/*this->x += vectorAddend.x;
	this->y += vectorAddend.y;
	this->z += vectorAddend.z;*/
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] += vectorAddend.coordinate[i];
	}
	return *this;
}

double SpaceVector::getModulus(void) const {
	/*return sqrt(
		SQR(this->x)
		+ SQR(this->y)
		+ SQR(this->z)
	);*/
	return sqrt(this->getSquareModulus());
}
double SpaceVector::getSquareModulus(void) const {
	/*return SQR(this->x)
		+ SQR(this->y)
		+ SQR(this->z);*/
	int squareModulus = ZERO;
	for (int i = ZERO; i < dimension; i++) {
		squareModulus += SQR(this->coordinate[i]);
	}
	return squareModulus;
}
void SpaceVector::print(void)
{
	/*cout << "("
		<< this->x << ", "
		<< this->y << ", "
		<< this->z << ")"
		<< endl;*/
	cout << "(";
	cout << this->coordinate[ZERO];
	for (int i = ONE; i < dimension; i++) {
		cout << this->coordinate[i] << ", ";
	}
	cout << ")" << endl;
}
double SpaceVector::getSquareModulus(const SpaceVector& A, const SpaceVector& B)
{
	return (A - B).getSquareModulus();
}
SpaceVector SpaceVector::getUnitVector(void) const
{
	/*double modulus = this->getModulus();
	return SpaceVector(
		this->x / modulus,
		this->y / modulus,
		this->z / modulus);*/
	return *this / this->getModulus();
}
