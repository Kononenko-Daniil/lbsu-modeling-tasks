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

double LGetLx(vector<double>& xValues, double x, double inum) {
    double res = 1, xi = xValues[inum];
    for(int i = 0; i < xValues.size(); i++) {
        if (inum != i) {
            res *= (x - xValues[i]) / (xi - xValues[i]);
        }
    }

    return res;
}

vector<Coord> LagrangeMethod (Data& data) {
    vector<Coord> res;
    for(int i = 0; i < data.desired_values.size(); i++) {
        double y = 0, x = data.desired_values[i];
        int n = data.x.size();
        for(int j = 0; j < n; j++) {
            y += data.y[j] * LGetLx(data.x, x, j);
        }

        Coord res_coord = { x, y };
        res.push_back(res_coord);
    }

    return res;
}

vector<Coord> NewtonMethod (Data& data) {
    vector<Coord> res;
    int n = data.x.size();
    for(int i = 0; i < data.desired_values.size(); i++) {
        double x = data.desired_values[i];
        vector<vector<double>> dy(n, vector<double>(n));

        for (int i = 0; i < n; i++) {
            dy[0][i] = data.y[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dy[i][j] = dy[i-1][j+1] - dy[i-1][j];
            }
        }

        double k = (x - data.x[0]) / 0.005, m = 1, f = 1;
        double y = data.y[0];
        for (int i = 1; i < n; i++) {
            f *= i;
            m *= (k - i + 1);
            y += m / f * dy[i][0];
        }

        Coord res_coord = { x, y };
        res.push_back(res_coord);
    }

    return res;
}

void PrintResults(vector<Coord>& result, string heading) {
    int n = result.size();

    cout << heading << endl;
    for(int i = 0; i < n; i++) {
        cout << "x: " << result[i].x << "; " << "y: " << result[i].y << endl;
    }
}

int main () {
    Data lagrange_data = GetDataFromFile(AlgorithmType::LAGRANGE);
    Data newton_data = GetDataFromFile(AlgorithmType::NEWTON);

    vector<Coord> lagrange_res = LagrangeMethod(lagrange_data);
    vector<Coord> newton_res = NewtonMethod(newton_data);

    PrintResults(lagrange_res, "Lagrange method");
    PrintResults(newton_res, "Newton method");

    return 0;
}
