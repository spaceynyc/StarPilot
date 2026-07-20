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
void car_err_fun(double *nom_x, double *delta_x, double *out_987182458906470159);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4004973593439921273);
void car_H_mod_fun(double *state, double *out_4046416566086051984);
void car_f_fun(double *state, double dt, double *out_1503157798377366230);
void car_F_fun(double *state, double dt, double *out_7239643626706973401);
void car_h_25(double *state, double *unused, double *out_167771431089955529);
void car_H_25(double *state, double *unused, double *out_3279968804003844735);
void car_h_24(double *state, double *unused, double *out_9045104448804658027);
void car_H_24(double *state, double *unused, double *out_7319421258831684819);
void car_h_30(double *state, double *unused, double *out_7931036687910627970);
void car_H_30(double *state, double *unused, double *out_1247727526123763463);
void car_h_26(double *state, double *unused, double *out_5449289867080580923);
void car_H_26(double *state, double *unused, double *out_461534514870211489);
void car_h_27(double *state, double *unused, double *out_2772176751898653180);
void car_H_27(double *state, double *unused, double *out_3422490837924188374);
void car_h_29(double *state, double *unused, double *out_2929363420249782325);
void car_H_29(double *state, double *unused, double *out_737496181809371279);
void car_h_28(double *state, double *unused, double *out_5808962803342985865);
void car_H_28(double *state, double *unused, double *out_1226134089755954972);
void car_h_31(double *state, double *unused, double *out_6323218626930615658);
void car_H_31(double *state, double *unused, double *out_1087742617103562965);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}