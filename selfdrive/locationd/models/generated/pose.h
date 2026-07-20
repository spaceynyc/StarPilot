#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5326449587047095854);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_808033856261158562);
void pose_H_mod_fun(double *state, double *out_4598941152447404033);
void pose_f_fun(double *state, double dt, double *out_7845712062767557446);
void pose_F_fun(double *state, double dt, double *out_879909740565667902);
void pose_h_4(double *state, double *unused, double *out_431308798891505486);
void pose_H_4(double *state, double *unused, double *out_15685884481912331);
void pose_h_10(double *state, double *unused, double *out_4633038553577825716);
void pose_H_10(double *state, double *unused, double *out_5370661049739372457);
void pose_h_13(double *state, double *unused, double *out_8528016009163002346);
void pose_H_13(double *state, double *unused, double *out_3227959709814245132);
void pose_h_14(double *state, double *unused, double *out_4581007164984635004);
void pose_H_14(double *state, double *unused, double *out_3978926740821396860);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}