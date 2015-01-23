#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
struct Vector {
	int size;
	double *value;
};
struct Matrix {
	int width;
	int height;
	Vector *vectors;
	
};
void initVector(Vector &v, int height);
string matrixToString(Matrix m);
void initMatrix(Matrix *m, int width, int height);
Matrix readMatrixFromFile(char *fileName, int maxMatrixSize);
int main(int argc, char* argv[]){
	Matrix matrix = readMatrixFromFile(argv[1], atoi(argv[2]));
	//initMatrix(&matrix1, 5, 4);
	cout << matrixToString(matrix) << endl;	
	return 0;
}


string matrixToString(Matrix m){
	ostringstream output;
	int vSize = m.vectors[0].size;
	for(int i =0; i < vSize; i++){
		for(int j =0; j < m.width; j++){
			output << m.vectors[j].value[i];
			if(j < (m.width - 1)){
				output <<", ";
			}
		}
		output << endl;
	}

	return output.str();
}

void initMatrix(Matrix *m, int width, int height){
	m->width = width;
	m->height = height;
	m->vectors = new Vector[width];
	cout << "Matrix Initialized with width of " << width << " and height of " << height << endl;
	for(int i =0; i < width; i++){
		initVector(m->vectors[i],height);	
	}

}
void initVector(Vector &v, int height){
	v.value = new double[height];
	v.size = height;		
	for(int i =0; i < height; i++){
			v.value[i] = i;	
	}
}

Matrix readMatrixFromFile(char *fileName,int maxMatrixSize){
	Matrix tempMatrix;
	initMatrix(tempMatrix, maxMatrixSize, maxMatrixSize);
	ifstream inStream;
	inStream.open(fileName);
	int height = 0;
	int width = 0;
	
	if(inStream.fail()){
		cerr << "Input file could not be opened!" << endl;
		exit(1);
	}
	string thisLine;
	getline(inStream, thisLine);
	istringstream iss;
	string value;	
	while(!inStream.eof() || !inStream.fail()){
		iss.str(thisLine);
		getline(iss, value, ',');
		height++;
		while(!iss.eof() || !iss.fail()){
			if(height == 1){
				width++;
			}
			getline(iss, value, ',');	
		}
		getline(inStream, thisLine);
		
	}
	cout << "The height is " << height << endl;
	return matrix;
	
}

