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
void car_err_fun(double *nom_x, double *delta_x, double *out_6228234881733864934);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4987639609546586613);
void car_H_mod_fun(double *state, double *out_7231986235693649664);
void car_f_fun(double *state, double dt, double *out_230288838788838657);
void car_F_fun(double *state, double dt, double *out_6053955851441441421);
void car_h_25(double *state, double *unused, double *out_6486517394319225831);
void car_H_25(double *state, double *unused, double *out_2437155392765780555);
void car_h_24(double *state, double *unused, double *out_2812983764171647921);
void car_H_24(double *state, double *unused, double *out_264505793760280989);
void car_h_30(double *state, double *unused, double *out_1276747862501446610);
void car_H_30(double *state, double *unused, double *out_4955488351273029182);
void car_h_26(double *state, double *unused, double *out_1327657458307251041);
void car_H_26(double *state, double *unused, double *out_1304347926108275669);
void car_h_27(double *state, double *unused, double *out_7037025956126784954);
void car_H_27(double *state, double *unused, double *out_2780725039472604271);
void car_h_29(double *state, double *unused, double *out_3096869935300978488);
void car_H_29(double *state, double *unused, double *out_5465719695587421366);
void car_h_28(double *state, double *unused, double *out_1892135893011137417);
void car_H_28(double *state, double *unused, double *out_383320678517890792);
void car_h_31(double *state, double *unused, double *out_4499667915141437460);
void car_H_31(double *state, double *unused, double *out_1930556028341627145);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}