#include "state.hpp"
#include <cmath>
namespace Engine{

    void State::copy(const State *state){

    }
    void State::resize(int bodyCount, int constraintCount){
        n = bodyCount;
        n_c = constraintCount;

        destroy();
        
        a_theta = new double[n];
        v_theta = new double[n];
        theta = new double[n];

        a_x = new double[n];
        a_y = new double[n];
        v_x = new double[n];
        v_y = new double[n];
        p_x = new double[n];
        p_y = new double[n];

        f_x = new double[n];
        f_y = new double[n];
        t = new double[n];

        r_x = new double[n];
        r_y = new double[n];
        r_t = new double[n];

        m = new double[n];
    }
    void State::destroy(){

    }

    void State::relativeToWorld(double x, double y, double *x_t, double *y_t, int body){
        const double x0 = p_x[body];
        const double y0 = p_y[body];
        const double theta = this->theta[body];

        const double cos_theta = std::cos(theta);
        const double sin_theta = std::sin(theta);

        *x_t = cos_theta * x - sin_theta * y + x0;
        *y_t = sin_theta * x + cos_theta * y + y0;
    }
    void State::velocityAtPoint(double x, double y, double *v_x, double *v_y, int body){
        double w_x, w_y;
        relativeToWorld(x, y, &w_x, &w_y, body);

        const double v_theta = this->v_theta[body];
        const double angularToLinear_x = -v_theta * (w_y - this->p_y[body]);
        const double angularToLinear_y = v_theta * (w_x - this->p_x[body]);

        *v_x = this->v_x[body] + angularToLinear_x;
        *v_y = this->v_y[body] + angularToLinear_y;

    }
    void State::applyForce(double x_l, double y_l, double f_x, double f_y, int body){
        double w_x, w_y;
        relativeToWorld(x_l, y_l, &w_x, &w_y, body);

        this->f_x[body] += f_x;
        this->f_y[body] += f_y;

        this->t[body] +=
            (w_y - this->p_y[body]) * -f_x +
            (w_x - this->p_x[body]) * f_y;
    }
}