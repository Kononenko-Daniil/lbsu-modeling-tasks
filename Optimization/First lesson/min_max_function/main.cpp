#include <iostream>
#include <cmath>

using namespace std;
const double alpha = (1 + sqrt(5)) / 2;

struct XYPair {
    double x, y;
};

enum FuncType {
    MIN,
    MAX
};

double FunctionY(double x) {
    double cbrX = x*x*x;
    double sqrX = x*x;
    double result = cbrX + 2*sqrX - 8*x + 1 + 12*sin(x) - 8*cos(x);

    return result;
}

XYPair FindMinMax(double a, double b, double accuracy, FuncType type) {
    double c, d;
    double k = a, h =b;

	while (fabs(b - a) >= accuracy) {
        c = b - (b - a) / alpha;
        d = a + (b - a) / alpha;

        if (type == FuncType::MIN)
            if (FunctionY(c) > FunctionY(d)) { a = c; } else { b = d; }
        else
            if (FunctionY(c) < FunctionY(d)) { a = c; } else { b = d; }
	}

	double x = (a + b) / 2;
	double y = FunctionY(x);
	XYPair result = {x, y};

	return result;
}

int main()
{
    double aMin = -2, bMin = 0;
    double aMax = -4, bMax = -2;
	double accuracy = 0.0001;

    XYPair funcMin = FindMinMax(aMin, bMin, accuracy, FuncType::MIN);
    XYPair funcMax = FindMinMax(aMax, bMax, accuracy, FuncType::MAX);

	cout << "Minimum - x: " << funcMin.x << "; y: " << funcMin.y << ";" << endl;
	cout << "Maximum - x: " << funcMax.x << "; y: " << funcMax.y << ";" << endl;


	return 0;
}
