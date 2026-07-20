#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_987182458906470159) {
   out_987182458906470159[0] = delta_x[0] + nom_x[0];
   out_987182458906470159[1] = delta_x[1] + nom_x[1];
   out_987182458906470159[2] = delta_x[2] + nom_x[2];
   out_987182458906470159[3] = delta_x[3] + nom_x[3];
   out_987182458906470159[4] = delta_x[4] + nom_x[4];
   out_987182458906470159[5] = delta_x[5] + nom_x[5];
   out_987182458906470159[6] = delta_x[6] + nom_x[6];
   out_987182458906470159[7] = delta_x[7] + nom_x[7];
   out_987182458906470159[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4004973593439921273) {
   out_4004973593439921273[0] = -nom_x[0] + true_x[0];
   out_4004973593439921273[1] = -nom_x[1] + true_x[1];
   out_4004973593439921273[2] = -nom_x[2] + true_x[2];
   out_4004973593439921273[3] = -nom_x[3] + true_x[3];
   out_4004973593439921273[4] = -nom_x[4] + true_x[4];
   out_4004973593439921273[5] = -nom_x[5] + true_x[5];
   out_4004973593439921273[6] = -nom_x[6] + true_x[6];
   out_4004973593439921273[7] = -nom_x[7] + true_x[7];
   out_4004973593439921273[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4046416566086051984) {
   out_4046416566086051984[0] = 1.0;
   out_4046416566086051984[1] = 0.0;
   out_4046416566086051984[2] = 0.0;
   out_4046416566086051984[3] = 0.0;
   out_4046416566086051984[4] = 0.0;
   out_4046416566086051984[5] = 0.0;
   out_4046416566086051984[6] = 0.0;
   out_4046416566086051984[7] = 0.0;
   out_4046416566086051984[8] = 0.0;
   out_4046416566086051984[9] = 0.0;
   out_4046416566086051984[10] = 1.0;
   out_4046416566086051984[11] = 0.0;
   out_4046416566086051984[12] = 0.0;
   out_4046416566086051984[13] = 0.0;
   out_4046416566086051984[14] = 0.0;
   out_4046416566086051984[15] = 0.0;
   out_4046416566086051984[16] = 0.0;
   out_4046416566086051984[17] = 0.0;
   out_4046416566086051984[18] = 0.0;
   out_4046416566086051984[19] = 0.0;
   out_4046416566086051984[20] = 1.0;
   out_4046416566086051984[21] = 0.0;
   out_4046416566086051984[22] = 0.0;
   out_4046416566086051984[23] = 0.0;
   out_4046416566086051984[24] = 0.0;
   out_4046416566086051984[25] = 0.0;
   out_4046416566086051984[26] = 0.0;
   out_4046416566086051984[27] = 0.0;
   out_4046416566086051984[28] = 0.0;
   out_4046416566086051984[29] = 0.0;
   out_4046416566086051984[30] = 1.0;
   out_4046416566086051984[31] = 0.0;
   out_4046416566086051984[32] = 0.0;
   out_4046416566086051984[33] = 0.0;
   out_4046416566086051984[34] = 0.0;
   out_4046416566086051984[35] = 0.0;
   out_4046416566086051984[36] = 0.0;
   out_4046416566086051984[37] = 0.0;
   out_4046416566086051984[38] = 0.0;
   out_4046416566086051984[39] = 0.0;
   out_4046416566086051984[40] = 1.0;
   out_4046416566086051984[41] = 0.0;
   out_4046416566086051984[42] = 0.0;
   out_4046416566086051984[43] = 0.0;
   out_4046416566086051984[44] = 0.0;
   out_4046416566086051984[45] = 0.0;
   out_4046416566086051984[46] = 0.0;
   out_4046416566086051984[47] = 0.0;
   out_4046416566086051984[48] = 0.0;
   out_4046416566086051984[49] = 0.0;
   out_4046416566086051984[50] = 1.0;
   out_4046416566086051984[51] = 0.0;
   out_4046416566086051984[52] = 0.0;
   out_4046416566086051984[53] = 0.0;
   out_4046416566086051984[54] = 0.0;
   out_4046416566086051984[55] = 0.0;
   out_4046416566086051984[56] = 0.0;
   out_4046416566086051984[57] = 0.0;
   out_4046416566086051984[58] = 0.0;
   out_4046416566086051984[59] = 0.0;
   out_4046416566086051984[60] = 1.0;
   out_4046416566086051984[61] = 0.0;
   out_4046416566086051984[62] = 0.0;
   out_4046416566086051984[63] = 0.0;
   out_4046416566086051984[64] = 0.0;
   out_4046416566086051984[65] = 0.0;
   out_4046416566086051984[66] = 0.0;
   out_4046416566086051984[67] = 0.0;
   out_4046416566086051984[68] = 0.0;
   out_4046416566086051984[69] = 0.0;
   out_4046416566086051984[70] = 1.0;
   out_4046416566086051984[71] = 0.0;
   out_4046416566086051984[72] = 0.0;
   out_4046416566086051984[73] = 0.0;
   out_4046416566086051984[74] = 0.0;
   out_4046416566086051984[75] = 0.0;
   out_4046416566086051984[76] = 0.0;
   out_4046416566086051984[77] = 0.0;
   out_4046416566086051984[78] = 0.0;
   out_4046416566086051984[79] = 0.0;
   out_4046416566086051984[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1503157798377366230) {
   out_1503157798377366230[0] = state[0];
   out_1503157798377366230[1] = state[1];
   out_1503157798377366230[2] = state[2];
   out_1503157798377366230[3] = state[3];
   out_1503157798377366230[4] = state[4];
   out_1503157798377366230[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1503157798377366230[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1503157798377366230[7] = state[7];
   out_1503157798377366230[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7239643626706973401) {
   out_7239643626706973401[0] = 1;
   out_7239643626706973401[1] = 0;
   out_7239643626706973401[2] = 0;
   out_7239643626706973401[3] = 0;
   out_7239643626706973401[4] = 0;
   out_7239643626706973401[5] = 0;
   out_7239643626706973401[6] = 0;
   out_7239643626706973401[7] = 0;
   out_7239643626706973401[8] = 0;
   out_7239643626706973401[9] = 0;
   out_7239643626706973401[10] = 1;
   out_7239643626706973401[11] = 0;
   out_7239643626706973401[12] = 0;
   out_7239643626706973401[13] = 0;
   out_7239643626706973401[14] = 0;
   out_7239643626706973401[15] = 0;
   out_7239643626706973401[16] = 0;
   out_7239643626706973401[17] = 0;
   out_7239643626706973401[18] = 0;
   out_7239643626706973401[19] = 0;
   out_7239643626706973401[20] = 1;
   out_7239643626706973401[21] = 0;
   out_7239643626706973401[22] = 0;
   out_7239643626706973401[23] = 0;
   out_7239643626706973401[24] = 0;
   out_7239643626706973401[25] = 0;
   out_7239643626706973401[26] = 0;
   out_7239643626706973401[27] = 0;
   out_7239643626706973401[28] = 0;
   out_7239643626706973401[29] = 0;
   out_7239643626706973401[30] = 1;
   out_7239643626706973401[31] = 0;
   out_7239643626706973401[32] = 0;
   out_7239643626706973401[33] = 0;
   out_7239643626706973401[34] = 0;
   out_7239643626706973401[35] = 0;
   out_7239643626706973401[36] = 0;
   out_7239643626706973401[37] = 0;
   out_7239643626706973401[38] = 0;
   out_7239643626706973401[39] = 0;
   out_7239643626706973401[40] = 1;
   out_7239643626706973401[41] = 0;
   out_7239643626706973401[42] = 0;
   out_7239643626706973401[43] = 0;
   out_7239643626706973401[44] = 0;
   out_7239643626706973401[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7239643626706973401[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7239643626706973401[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7239643626706973401[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7239643626706973401[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7239643626706973401[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7239643626706973401[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7239643626706973401[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7239643626706973401[53] = -9.8100000000000005*dt;
   out_7239643626706973401[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7239643626706973401[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7239643626706973401[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7239643626706973401[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7239643626706973401[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7239643626706973401[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7239643626706973401[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7239643626706973401[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7239643626706973401[62] = 0;
   out_7239643626706973401[63] = 0;
   out_7239643626706973401[64] = 0;
   out_7239643626706973401[65] = 0;
   out_7239643626706973401[66] = 0;
   out_7239643626706973401[67] = 0;
   out_7239643626706973401[68] = 0;
   out_7239643626706973401[69] = 0;
   out_7239643626706973401[70] = 1;
   out_7239643626706973401[71] = 0;
   out_7239643626706973401[72] = 0;
   out_7239643626706973401[73] = 0;
   out_7239643626706973401[74] = 0;
   out_7239643626706973401[75] = 0;
   out_7239643626706973401[76] = 0;
   out_7239643626706973401[77] = 0;
   out_7239643626706973401[78] = 0;
   out_7239643626706973401[79] = 0;
   out_7239643626706973401[80] = 1;
}
void h_25(double *state, double *unused, double *out_167771431089955529) {
   out_167771431089955529[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3279968804003844735) {
   out_3279968804003844735[0] = 0;
   out_3279968804003844735[1] = 0;
   out_3279968804003844735[2] = 0;
   out_3279968804003844735[3] = 0;
   out_3279968804003844735[4] = 0;
   out_3279968804003844735[5] = 0;
   out_3279968804003844735[6] = 1;
   out_3279968804003844735[7] = 0;
   out_3279968804003844735[8] = 0;
}
void h_24(double *state, double *unused, double *out_9045104448804658027) {
   out_9045104448804658027[0] = state[4];
   out_9045104448804658027[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7319421258831684819) {
   out_7319421258831684819[0] = 0;
   out_7319421258831684819[1] = 0;
   out_7319421258831684819[2] = 0;
   out_7319421258831684819[3] = 0;
   out_7319421258831684819[4] = 1;
   out_7319421258831684819[5] = 0;
   out_7319421258831684819[6] = 0;
   out_7319421258831684819[7] = 0;
   out_7319421258831684819[8] = 0;
   out_7319421258831684819[9] = 0;
   out_7319421258831684819[10] = 0;
   out_7319421258831684819[11] = 0;
   out_7319421258831684819[12] = 0;
   out_7319421258831684819[13] = 0;
   out_7319421258831684819[14] = 1;
   out_7319421258831684819[15] = 0;
   out_7319421258831684819[16] = 0;
   out_7319421258831684819[17] = 0;
}
void h_30(double *state, double *unused, double *out_7931036687910627970) {
   out_7931036687910627970[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1247727526123763463) {
   out_1247727526123763463[0] = 0;
   out_1247727526123763463[1] = 0;
   out_1247727526123763463[2] = 0;
   out_1247727526123763463[3] = 0;
   out_1247727526123763463[4] = 1;
   out_1247727526123763463[5] = 0;
   out_1247727526123763463[6] = 0;
   out_1247727526123763463[7] = 0;
   out_1247727526123763463[8] = 0;
}
void h_26(double *state, double *unused, double *out_5449289867080580923) {
   out_5449289867080580923[0] = state[7];
}
void H_26(double *state, double *unused, double *out_461534514870211489) {
   out_461534514870211489[0] = 0;
   out_461534514870211489[1] = 0;
   out_461534514870211489[2] = 0;
   out_461534514870211489[3] = 0;
   out_461534514870211489[4] = 0;
   out_461534514870211489[5] = 0;
   out_461534514870211489[6] = 0;
   out_461534514870211489[7] = 1;
   out_461534514870211489[8] = 0;
}
void h_27(double *state, double *unused, double *out_2772176751898653180) {
   out_2772176751898653180[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3422490837924188374) {
   out_3422490837924188374[0] = 0;
   out_3422490837924188374[1] = 0;
   out_3422490837924188374[2] = 0;
   out_3422490837924188374[3] = 1;
   out_3422490837924188374[4] = 0;
   out_3422490837924188374[5] = 0;
   out_3422490837924188374[6] = 0;
   out_3422490837924188374[7] = 0;
   out_3422490837924188374[8] = 0;
}
void h_29(double *state, double *unused, double *out_2929363420249782325) {
   out_2929363420249782325[0] = state[1];
}
void H_29(double *state, double *unused, double *out_737496181809371279) {
   out_737496181809371279[0] = 0;
   out_737496181809371279[1] = 1;
   out_737496181809371279[2] = 0;
   out_737496181809371279[3] = 0;
   out_737496181809371279[4] = 0;
   out_737496181809371279[5] = 0;
   out_737496181809371279[6] = 0;
   out_737496181809371279[7] = 0;
   out_737496181809371279[8] = 0;
}
void h_28(double *state, double *unused, double *out_5808962803342985865) {
   out_5808962803342985865[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1226134089755954972) {
   out_1226134089755954972[0] = 1;
   out_1226134089755954972[1] = 0;
   out_1226134089755954972[2] = 0;
   out_1226134089755954972[3] = 0;
   out_1226134089755954972[4] = 0;
   out_1226134089755954972[5] = 0;
   out_1226134089755954972[6] = 0;
   out_1226134089755954972[7] = 0;
   out_1226134089755954972[8] = 0;
}
void h_31(double *state, double *unused, double *out_6323218626930615658) {
   out_6323218626930615658[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1087742617103562965) {
   out_1087742617103562965[0] = 0;
   out_1087742617103562965[1] = 0;
   out_1087742617103562965[2] = 0;
   out_1087742617103562965[3] = 0;
   out_1087742617103562965[4] = 0;
   out_1087742617103562965[5] = 0;
   out_1087742617103562965[6] = 0;
   out_1087742617103562965[7] = 0;
   out_1087742617103562965[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_987182458906470159) {
  err_fun(nom_x, delta_x, out_987182458906470159);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4004973593439921273) {
  inv_err_fun(nom_x, true_x, out_4004973593439921273);
}
void car_H_mod_fun(double *state, double *out_4046416566086051984) {
  H_mod_fun(state, out_4046416566086051984);
}
void car_f_fun(double *state, double dt, double *out_1503157798377366230) {
  f_fun(state,  dt, out_1503157798377366230);
}
void car_F_fun(double *state, double dt, double *out_7239643626706973401) {
  F_fun(state,  dt, out_7239643626706973401);
}
void car_h_25(double *state, double *unused, double *out_167771431089955529) {
  h_25(state, unused, out_167771431089955529);
}
void car_H_25(double *state, double *unused, double *out_3279968804003844735) {
  H_25(state, unused, out_3279968804003844735);
}
void car_h_24(double *state, double *unused, double *out_9045104448804658027) {
  h_24(state, unused, out_9045104448804658027);
}
void car_H_24(double *state, double *unused, double *out_7319421258831684819) {
  H_24(state, unused, out_7319421258831684819);
}
void car_h_30(double *state, double *unused, double *out_7931036687910627970) {
  h_30(state, unused, out_7931036687910627970);
}
void car_H_30(double *state, double *unused, double *out_1247727526123763463) {
  H_30(state, unused, out_1247727526123763463);
}
void car_h_26(double *state, double *unused, double *out_5449289867080580923) {
  h_26(state, unused, out_5449289867080580923);
}
void car_H_26(double *state, double *unused, double *out_461534514870211489) {
  H_26(state, unused, out_461534514870211489);
}
void car_h_27(double *state, double *unused, double *out_2772176751898653180) {
  h_27(state, unused, out_2772176751898653180);
}
void car_H_27(double *state, double *unused, double *out_3422490837924188374) {
  H_27(state, unused, out_3422490837924188374);
}
void car_h_29(double *state, double *unused, double *out_2929363420249782325) {
  h_29(state, unused, out_2929363420249782325);
}
void car_H_29(double *state, double *unused, double *out_737496181809371279) {
  H_29(state, unused, out_737496181809371279);
}
void car_h_28(double *state, double *unused, double *out_5808962803342985865) {
  h_28(state, unused, out_5808962803342985865);
}
void car_H_28(double *state, double *unused, double *out_1226134089755954972) {
  H_28(state, unused, out_1226134089755954972);
}
void car_h_31(double *state, double *unused, double *out_6323218626930615658) {
  h_31(state, unused, out_6323218626930615658);
}
void car_H_31(double *state, double *unused, double *out_1087742617103562965) {
  H_31(state, unused, out_1087742617103562965);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
