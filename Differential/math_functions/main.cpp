#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

struct MathResult {
    double x;
    double myRes;
    double cmathRes;
};

enum class Func {
    SQRT,
    CBRT,
    LN,
    SIN,
    COS
};

MathResult mySqrt(double n) {
    double x = 7.86 + 1.27 * n;
    double x0 = 7.92;

    double dx0 = 1 / (2 * sqrt(x0));
    double fx0 = sqrt(x0);

    double myRes = fx0 + dx0 * (x-x0);
    double cmathRes = sqrt(x);

    MathResult result = {x, myRes, cmathRes};

    return result;
}

MathResult myCbrt(double n) {
    double x = 11.352 + 0.343 * n;
    double x0 = 11.3;

    double dx0 = 1 / (3 * cbrt(x0*x0));
    double fx0 = cbrt(x0);

    double myRes = fx0 + dx0 * (x-x0);
    double cmathRes = cbrt(x);

    MathResult result = {x, myRes, cmathRes};

    return result;
}

MathResult myLn(double n) {
    double x = 2.716 + 0.043 * n;
    double x0 = 2.7;

    double dx0 = 1 / x0;
    double fx0 = log(x0);

    double myRes = fx0 + dx0 * (x-x0);
    double cmathRes = log(x);

    MathResult result = {x, myRes, cmathRes};

    return result;
}

MathResult mySin(double n) {
    double x = 0.232 + 0.012 * n;
    double x0 = 0.23;

    double dx0 = cos(x0);
    double fx0 = sin(x0);

    double myRes = fx0 + dx0 * (x-x0);
    double cmathRes = sin(x);

    MathResult result = {x, myRes, cmathRes};

    return result;
}

MathResult myCos(double n) {
    double x = 0.232 + 0.012 * n;
    double x0 = 0.23;

    double dx0 = -sin(x0);
    double fx0 = cos(x0);

    double myRes = fx0 + dx0 * (x-x0);
    double cmathRes = cos(x);

    MathResult result = {x, myRes, cmathRes};

    return result;
}

MathResult ExecuteMathFunction(Func functionType, double n) {
    MathResult result;
    switch (functionType) {
        case Func::SQRT: result = mySqrt(n); break;
        case Func::CBRT: result = myCbrt(n); break;
        case Func::LN: result = myLn(n); break;
        case Func::SIN: result = mySin(n); break;
        case Func::COS: result = myCos(n); break;
    }

    return result;
}

string GetFuncOutputPath(Func functionType) {
    string result = "sqrt.txt";
    switch (functionType) {
        case Func::SQRT: result = "sqrt.txt"; break;
        case Func::CBRT: result = "cbrt.txt"; break;
        case Func::LN: result = "ln.txt"; break;
        case Func::SIN: result = "sin.txt"; break;
        case Func::COS: result = "cos.txt"; break;
    }

    return result;
}



void PrintResult (MathResult& result, int index, Func& functionType, ofstream& fout) {


    double x = result.x;
    double myRes = result.myRes;
    double cmathRes = result.cmathRes;

    fout << fixed;
    fout.precision(0);
    fout << index << "\t";
    fout.precision(6);
    fout << x << "\t" << myRes << "\t" << cmathRes << endl;
}



int main()
{
    double k = 6;
    Func functionType = Func::SQRT;
    ofstream fout(GetFuncOutputPath(functionType));

    for(int i = 0; i <= 9; i++) {
        double n = i * (0.001 + k * 0.001);
        MathResult result = ExecuteMathFunction(functionType, n);

        PrintResult(result, i, functionType, fout);
    }

    return 0;
}
