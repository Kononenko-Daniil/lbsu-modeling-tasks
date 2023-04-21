#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Data {
    vector<double> desired_values, x, y;
};

struct Coord {
    double x, y;
};

enum AlgorithmType {
    LAGRANGE,
    NEWTON
};

string GetFilePath (AlgorithmType type) {
    string result;
    switch(type) {
        case AlgorithmType::LAGRANGE: result = "lagrange_data.txt"; break;
        case AlgorithmType::NEWTON: result = "newton_data.txt"; break;
    }

    return result;
}

Data GetDataFromFile (AlgorithmType type) {
    string data_path = GetFilePath(type);
    ifstream fin(data_path);

    int desired_values_number, train_data_number;
    fin >> desired_values_number >> train_data_number;
    vector <double> desired_values(desired_values_number),
                    train_data_X(train_data_number),
                    train_data_Y(train_data_number);

    for(int i = 0; i < desired_values_number; i++) {
        fin >> desired_values[i];
    }
    for(int i = 0; i < train_data_number; i++) {
        fin >> train_data_X[i] >> train_data_Y[i];
    }

    Data result = {desired_values, train_data_X, train_data_Y};

    return result;
}

vector<Coord>& LagrangeMethod (Data& data) {

}

vector<Coord>& NewtonMethod (Data& data) {

}

void PrintResults(vector<Coord>& result) {

}

int main () {
    Data lagrange_data = GetDataFromFile(AlgorithmType::LAGRANGE);
    Data newton_data = GetDataFromFile(AlgorithmType::NEWTON);

    vector<Coord> lagrange_res = LagrangeMethod(lagrange_data);
    vector<Coord> newton_res = NewtonMethod(newton_data);


    return 0;
}
