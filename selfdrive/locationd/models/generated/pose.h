#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5195610458540139902);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7314439786479166241);
void pose_H_mod_fun(double *state, double *out_8818080346799948532);
void pose_f_fun(double *state, double dt, double *out_4287776289429729412);
void pose_F_fun(double *state, double dt, double *out_4341253320848234007);
void pose_h_4(double *state, double *unused, double *out_6128102438980532385);
void pose_H_4(double *state, double *unused, double *out_6428253825808133060);
void pose_h_10(double *state, double *unused, double *out_1886304758557187825);
void pose_H_10(double *state, double *unused, double *out_8187218168232665500);
void pose_h_13(double *state, double *unused, double *out_1675328109498391522);
void pose_H_13(double *state, double *unused, double *out_4407859039584717627);
void pose_h_14(double *state, double *unused, double *out_6344247348281186472);
void pose_H_14(double *state, double *unused, double *out_3345465393512760764);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}