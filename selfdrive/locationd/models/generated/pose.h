#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6331725736918116355);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7346919451959455956);
void pose_H_mod_fun(double *state, double *out_8304511961976193146);
void pose_f_fun(double *state, double dt, double *out_7307163557378829170);
void pose_F_fun(double *state, double dt, double *out_4516770154061261607);
void pose_h_4(double *state, double *unused, double *out_4815477108189616395);
void pose_H_4(double *state, double *unused, double *out_1404035879650369332);
void pose_h_10(double *state, double *unused, double *out_827736089587648090);
void pose_H_10(double *state, double *unused, double *out_2817413118959448550);
void pose_h_13(double *state, double *unused, double *out_8331916060804991687);
void pose_H_13(double *state, double *unused, double *out_6206595328666331597);
void pose_h_14(double *state, double *unused, double *out_4595084300967204941);
void pose_H_14(double *state, double *unused, double *out_4486824311945741628);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}