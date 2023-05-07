#include <vector>

using namespace std;

double largange(double x, int n, double arrayX[], double arrayY[]) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        double t = 1;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                t = t * (x - arrayX[j]) / (arrayX[i] - arrayX[j]);
            }
        }
        res += arrayY[i] * t;
    }
    return res;
}

double newton(double x, int n, double arrayX[], double arrayY[]) {
    vector<vector<double>> delta_y(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        delta_y[0][i] = arrayY[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            delta_y[i][j] = delta_y[i-1][j+1] - delta_y[i-1][j];
        }
    }

    double mu = (x - arrayX[0]) / 0.005;
    double res = arrayY[0];

    double u = 1;
    double factorial = 1;

    for (int i = 1; i < n; i++) {
        factorial *= i;
        u *= (mu - i + 1);

        res += u * delta_y[i][0] / factorial;
    }

    return res;
}
