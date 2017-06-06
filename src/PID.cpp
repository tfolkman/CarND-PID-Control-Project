#include <cmath>
#include "PID.h"
#include <uWS/uWS.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;
    i_error = 0;
    n = 0;
    total_error = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    n++;
    total_error += pow(cte, 2);
}

double PID::TotalError() {
    return total_error / n;
}
