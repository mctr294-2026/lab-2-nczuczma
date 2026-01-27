#include "roots.hpp" // Ensure this matches the actual name of your header file
#include <iostream>
// 1. Bisection Method Stub
bool bisection(std::function<double(double)> f, double a, double b, double *root) {
    for(int i = 0; i < 1e6; i++){

        double midpoint = (a + b)/2;
        double yValue = f(midpoint);

        if (std::abs(yValue) < 1e-6){
            *root = midpoint;
            return true;
        }

        if (f(a) * yValue > 0){
            a = midpoint;
        }
        else{
            b = midpoint;
            }
    }
    return false; 
}

// 2. Regula Falsi Method Stub
bool regula_falsi(std::function<double(double)> f, double a, double b, double *root) {
    for(int i = 0; i < 1e6; i++){
        double midpoint = a - (f(a)*(b - a))/(f(b) - f(a));
        double yValue = f(midpoint);

        if (std::abs(yValue) < 1e-6){
            *root = midpoint;
            return true;
        }

        if (f(a) * yValue < 0){
            b = midpoint;
        }
        else{
            a = midpoint;
            }
    }
    return false; 
}

// 3. Newton-Raphson Method Stub
bool newton_raphson(std::function<double(double)> f, 
                    std::function<double(double)> g, 
                    double a, double b, double c, 
                    double *root) {

    double x_n = c;

    for(int i = 0; i < 1e6; i++){
        double yValue = f(x_n);
        double dyValue = g(x_n);

        if (std::abs(yValue) < 1e-6){
            *root = x_n;
            return true;
        }
        if(std::abs(dyValue) < 1e-6){
            return false;
        }

        if (x_n < a || x_n > b){  //Guess is outside of boundaries
            return false;
        }

        x_n = x_n - (f(x_n)/g(x_n));
    }

    return false; 
}

// 4. Secant Method Stub
bool secant(std::function<double(double)> f, double a, double b, double c, double *root) {

    return false; 
}