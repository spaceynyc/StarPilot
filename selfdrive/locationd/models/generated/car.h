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
void car_err_fun(double *nom_x, double *delta_x, double *out_1609199203824105809);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5316743831523255011);
void car_H_mod_fun(double *state, double *out_6016963909732254518);
void car_f_fun(double *state, double dt, double *out_8201144188883655273);
void car_F_fun(double *state, double dt, double *out_3307293311797318081);
void car_h_25(double *state, double *unused, double *out_3698742398836886851);
void car_H_25(double *state, double *unused, double *out_8906799513987805421);
void car_h_24(double *state, double *unused, double *out_6071423034488633953);
void car_H_24(double *state, double *unused, double *out_3477981141928203038);
void car_h_30(double *state, double *unused, double *out_8592554479032004636);
void car_H_30(double *state, double *unused, double *out_9036138461131045491);
void car_h_26(double *state, double *unused, double *out_4787772075959204257);
void car_H_26(double *state, double *unused, double *out_5798441240847689971);
void car_h_27(double *state, double *unused, double *out_661956347392554166);
void car_H_27(double *state, double *unused, double *out_7235842300778081214);
void car_h_29(double *state, double *unused, double *out_3590881211371158991);
void car_H_29(double *state, double *unused, double *out_5522479573908530181);
void car_h_28(double *state, double *unused, double *out_1265272232069031683);
void car_H_28(double *state, double *unused, double *out_440080556838999607);
void car_h_31(double *state, double *unused, double *out_3423548336552380962);
void car_H_31(double *state, double *unused, double *out_8876153552110844993);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}