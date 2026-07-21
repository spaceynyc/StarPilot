#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6808268772409694941);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9195646178207841001);
void car_H_mod_fun(double *state, double *out_3291093270527205778);
void car_f_fun(double *state, double dt, double *out_8991480621967120037);
void car_F_fun(double *state, double dt, double *out_7174174378897740995);
void car_h_25(double *state, double *unused, double *out_3544192021598640535);
void car_H_25(double *state, double *unused, double *out_6814073920516697455);
void car_h_24(double *state, double *unused, double *out_4495363720374893534);
void car_H_24(double *state, double *unused, double *out_9039781704495566017);
void car_h_30(double *state, double *unused, double *out_3701378689949769680);
void car_H_30(double *state, double *unused, double *out_4715979811701237406);
void car_h_26(double *state, double *unused, double *out_4304694574626247197);
void car_H_26(double *state, double *unused, double *out_3072570601642641231);
void car_h_27(double *state, double *unused, double *out_4920082605135938004);
void car_H_27(double *state, double *unused, double *out_6890743123501662317);
void car_h_29(double *state, double *unused, double *out_4644888542851432115);
void car_H_29(double *state, double *unused, double *out_4205748467386845222);
void car_h_28(double *state, double *unused, double *out_7524487925944635655);
void car_H_28(double *state, double *unused, double *out_9158596589253175820);
void car_h_31(double *state, double *unused, double *out_2369541005072107838);
void car_H_31(double *state, double *unused, double *out_6844719882393657883);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}