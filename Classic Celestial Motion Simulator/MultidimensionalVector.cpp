#include "MultidimensionalVector.h"
#include "Global.h"
#include "Engine.h"
void MultidimensionalVector::setDimension() {
	while (dimension <= ZERO) {
		cout << "维度: " << endl;
		cin >> dimension;
	}
}
MultidimensionalVector::MultidimensionalVector(void) {
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(ZERO);
	}
}
MultidimensionalVector::MultidimensionalVector(const MultidimensionalVector& other) {
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(other.coordinate[i]);
	}
}
MultidimensionalVector::MultidimensionalVector(const vector<double>& origin) {
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate.push_back(origin[i]);
	}
}
MultidimensionalVector& MultidimensionalVector::setSpaceVector(const MultidimensionalVector& origin, const double& modulus) {
	MultidimensionalVector unitVector(origin.getUnitVector());
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] = (modulus * unitVector.coordinate[i]);
	}
	return *this;
}
MultidimensionalVector& MultidimensionalVector::operator=(const MultidimensionalVector& other) {
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] = other.coordinate[i];
	}
	return *this;
}
MultidimensionalVector MultidimensionalVector::operator*(const double& scalarMultiplier)const {
	vector<double>product;
	for (int i = ZERO; i < dimension; i++) {
		product.push_back(this->coordinate[i] * scalarMultiplier);
	}
	return MultidimensionalVector(product);
}
MultidimensionalVector MultidimensionalVector::operator/(const double& scalarDivisor)const {
	vector<double>quotient;
	for (int i = ZERO; i < dimension; i++) {
		quotient.push_back(this->coordinate[i] / scalarDivisor);
	}
	return MultidimensionalVector(quotient);
}
MultidimensionalVector MultidimensionalVector::operator+(const MultidimensionalVector& vectorAddend)const {
	vector<double>sum;
	for (int i = ZERO; i < dimension; i++) {
		sum.push_back(this->coordinate[i] + vectorAddend.coordinate[i]);
	}
	return MultidimensionalVector(sum);
}
MultidimensionalVector MultidimensionalVector::operator-(const MultidimensionalVector& vectorSubtrahend)const {
	vector<double>difference;
	for (int i = ZERO; i < dimension; i++) {
		difference.push_back(this->coordinate[i] - vectorSubtrahend.coordinate[i]);
	}
	return MultidimensionalVector(difference);
}
MultidimensionalVector& MultidimensionalVector::operator+=(const MultidimensionalVector& vectorAddend) {
	for (int i = ZERO; i < dimension; i++) {
		this->coordinate[i] += vectorAddend.coordinate[i];
	}
	return *this;
}
double MultidimensionalVector::getModulus(void) const {
	return sqrt(this->getSquareModulus());
}
double MultidimensionalVector::getSquareModulus(void) const {
	double squareModulus = ZERO;
	for (int i = ZERO; i < dimension; i++) {
		squareModulus += SQR(this->coordinate[i]);
	}
	return squareModulus;
}
void MultidimensionalVector::print(void) {
	fileOperatorInstance.fout << "(";
	fileOperatorInstance.fout << this->coordinate[ZERO];
	for (int i = ONE; i < dimension; i++) {
		fileOperatorInstance.fout << ", " << this->coordinate[i];
	}
	fileOperatorInstance.fout << ")";
}
double MultidimensionalVector::getSquareModulus(const MultidimensionalVector& A, const MultidimensionalVector& B) {
	return (A - B).getSquareModulus();
}
double MultidimensionalVector::getInvolutionalModulus(const double& involution) const
{
	double modulus = this->getModulus();
	double InvolutionalModulus = ONE;
	for (int i = ZERO; i < involution; i++)
	{
		InvolutionalModulus *= modulus;
	}
	return InvolutionalModulus;
}
MultidimensionalVector MultidimensionalVector::getUnitVector(void) const {
	return *this / this->getModulus();
}