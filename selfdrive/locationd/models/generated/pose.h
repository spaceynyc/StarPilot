#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2987978520246878811);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7392740910229382527);
void pose_H_mod_fun(double *state, double *out_766595423579160181);
void pose_f_fun(double *state, double dt, double *out_422668654560890686);
void pose_F_fun(double *state, double dt, double *out_2475263657764665516);
void pose_h_4(double *state, double *unused, double *out_1835432060314574929);
void pose_H_4(double *state, double *unused, double *out_8177766242478661161);
void pose_h_10(double *state, double *unused, double *out_4694595839556490884);
void pose_H_10(double *state, double *unused, double *out_5779971349689640500);
void pose_h_13(double *state, double *unused, double *out_4377602138518793981);
void pose_H_13(double *state, double *unused, double *out_4965492417146328360);
void pose_h_14(double *state, double *unused, double *out_1646321224287546567);
void pose_H_14(double *state, double *unused, double *out_7186189398935518159);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}