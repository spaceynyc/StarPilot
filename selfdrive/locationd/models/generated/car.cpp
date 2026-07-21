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
void err_fun(double *nom_x, double *delta_x, double *out_6808268772409694941) {
   out_6808268772409694941[0] = delta_x[0] + nom_x[0];
   out_6808268772409694941[1] = delta_x[1] + nom_x[1];
   out_6808268772409694941[2] = delta_x[2] + nom_x[2];
   out_6808268772409694941[3] = delta_x[3] + nom_x[3];
   out_6808268772409694941[4] = delta_x[4] + nom_x[4];
   out_6808268772409694941[5] = delta_x[5] + nom_x[5];
   out_6808268772409694941[6] = delta_x[6] + nom_x[6];
   out_6808268772409694941[7] = delta_x[7] + nom_x[7];
   out_6808268772409694941[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9195646178207841001) {
   out_9195646178207841001[0] = -nom_x[0] + true_x[0];
   out_9195646178207841001[1] = -nom_x[1] + true_x[1];
   out_9195646178207841001[2] = -nom_x[2] + true_x[2];
   out_9195646178207841001[3] = -nom_x[3] + true_x[3];
   out_9195646178207841001[4] = -nom_x[4] + true_x[4];
   out_9195646178207841001[5] = -nom_x[5] + true_x[5];
   out_9195646178207841001[6] = -nom_x[6] + true_x[6];
   out_9195646178207841001[7] = -nom_x[7] + true_x[7];
   out_9195646178207841001[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3291093270527205778) {
   out_3291093270527205778[0] = 1.0;
   out_3291093270527205778[1] = 0.0;
   out_3291093270527205778[2] = 0.0;
   out_3291093270527205778[3] = 0.0;
   out_3291093270527205778[4] = 0.0;
   out_3291093270527205778[5] = 0.0;
   out_3291093270527205778[6] = 0.0;
   out_3291093270527205778[7] = 0.0;
   out_3291093270527205778[8] = 0.0;
   out_3291093270527205778[9] = 0.0;
   out_3291093270527205778[10] = 1.0;
   out_3291093270527205778[11] = 0.0;
   out_3291093270527205778[12] = 0.0;
   out_3291093270527205778[13] = 0.0;
   out_3291093270527205778[14] = 0.0;
   out_3291093270527205778[15] = 0.0;
   out_3291093270527205778[16] = 0.0;
   out_3291093270527205778[17] = 0.0;
   out_3291093270527205778[18] = 0.0;
   out_3291093270527205778[19] = 0.0;
   out_3291093270527205778[20] = 1.0;
   out_3291093270527205778[21] = 0.0;
   out_3291093270527205778[22] = 0.0;
   out_3291093270527205778[23] = 0.0;
   out_3291093270527205778[24] = 0.0;
   out_3291093270527205778[25] = 0.0;
   out_3291093270527205778[26] = 0.0;
   out_3291093270527205778[27] = 0.0;
   out_3291093270527205778[28] = 0.0;
   out_3291093270527205778[29] = 0.0;
   out_3291093270527205778[30] = 1.0;
   out_3291093270527205778[31] = 0.0;
   out_3291093270527205778[32] = 0.0;
   out_3291093270527205778[33] = 0.0;
   out_3291093270527205778[34] = 0.0;
   out_3291093270527205778[35] = 0.0;
   out_3291093270527205778[36] = 0.0;
   out_3291093270527205778[37] = 0.0;
   out_3291093270527205778[38] = 0.0;
   out_3291093270527205778[39] = 0.0;
   out_3291093270527205778[40] = 1.0;
   out_3291093270527205778[41] = 0.0;
   out_3291093270527205778[42] = 0.0;
   out_3291093270527205778[43] = 0.0;
   out_3291093270527205778[44] = 0.0;
   out_3291093270527205778[45] = 0.0;
   out_3291093270527205778[46] = 0.0;
   out_3291093270527205778[47] = 0.0;
   out_3291093270527205778[48] = 0.0;
   out_3291093270527205778[49] = 0.0;
   out_3291093270527205778[50] = 1.0;
   out_3291093270527205778[51] = 0.0;
   out_3291093270527205778[52] = 0.0;
   out_3291093270527205778[53] = 0.0;
   out_3291093270527205778[54] = 0.0;
   out_3291093270527205778[55] = 0.0;
   out_3291093270527205778[56] = 0.0;
   out_3291093270527205778[57] = 0.0;
   out_3291093270527205778[58] = 0.0;
   out_3291093270527205778[59] = 0.0;
   out_3291093270527205778[60] = 1.0;
   out_3291093270527205778[61] = 0.0;
   out_3291093270527205778[62] = 0.0;
   out_3291093270527205778[63] = 0.0;
   out_3291093270527205778[64] = 0.0;
   out_3291093270527205778[65] = 0.0;
   out_3291093270527205778[66] = 0.0;
   out_3291093270527205778[67] = 0.0;
   out_3291093270527205778[68] = 0.0;
   out_3291093270527205778[69] = 0.0;
   out_3291093270527205778[70] = 1.0;
   out_3291093270527205778[71] = 0.0;
   out_3291093270527205778[72] = 0.0;
   out_3291093270527205778[73] = 0.0;
   out_3291093270527205778[74] = 0.0;
   out_3291093270527205778[75] = 0.0;
   out_3291093270527205778[76] = 0.0;
   out_3291093270527205778[77] = 0.0;
   out_3291093270527205778[78] = 0.0;
   out_3291093270527205778[79] = 0.0;
   out_3291093270527205778[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8991480621967120037) {
   out_8991480621967120037[0] = state[0];
   out_8991480621967120037[1] = state[1];
   out_8991480621967120037[2] = state[2];
   out_8991480621967120037[3] = state[3];
   out_8991480621967120037[4] = state[4];
   out_8991480621967120037[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8991480621967120037[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8991480621967120037[7] = state[7];
   out_8991480621967120037[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7174174378897740995) {
   out_7174174378897740995[0] = 1;
   out_7174174378897740995[1] = 0;
   out_7174174378897740995[2] = 0;
   out_7174174378897740995[3] = 0;
   out_7174174378897740995[4] = 0;
   out_7174174378897740995[5] = 0;
   out_7174174378897740995[6] = 0;
   out_7174174378897740995[7] = 0;
   out_7174174378897740995[8] = 0;
   out_7174174378897740995[9] = 0;
   out_7174174378897740995[10] = 1;
   out_7174174378897740995[11] = 0;
   out_7174174378897740995[12] = 0;
   out_7174174378897740995[13] = 0;
   out_7174174378897740995[14] = 0;
   out_7174174378897740995[15] = 0;
   out_7174174378897740995[16] = 0;
   out_7174174378897740995[17] = 0;
   out_7174174378897740995[18] = 0;
   out_7174174378897740995[19] = 0;
   out_7174174378897740995[20] = 1;
   out_7174174378897740995[21] = 0;
   out_7174174378897740995[22] = 0;
   out_7174174378897740995[23] = 0;
   out_7174174378897740995[24] = 0;
   out_7174174378897740995[25] = 0;
   out_7174174378897740995[26] = 0;
   out_7174174378897740995[27] = 0;
   out_7174174378897740995[28] = 0;
   out_7174174378897740995[29] = 0;
   out_7174174378897740995[30] = 1;
   out_7174174378897740995[31] = 0;
   out_7174174378897740995[32] = 0;
   out_7174174378897740995[33] = 0;
   out_7174174378897740995[34] = 0;
   out_7174174378897740995[35] = 0;
   out_7174174378897740995[36] = 0;
   out_7174174378897740995[37] = 0;
   out_7174174378897740995[38] = 0;
   out_7174174378897740995[39] = 0;
   out_7174174378897740995[40] = 1;
   out_7174174378897740995[41] = 0;
   out_7174174378897740995[42] = 0;
   out_7174174378897740995[43] = 0;
   out_7174174378897740995[44] = 0;
   out_7174174378897740995[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7174174378897740995[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7174174378897740995[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7174174378897740995[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7174174378897740995[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7174174378897740995[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7174174378897740995[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7174174378897740995[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7174174378897740995[53] = -9.8100000000000005*dt;
   out_7174174378897740995[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7174174378897740995[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7174174378897740995[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7174174378897740995[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7174174378897740995[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7174174378897740995[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7174174378897740995[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7174174378897740995[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7174174378897740995[62] = 0;
   out_7174174378897740995[63] = 0;
   out_7174174378897740995[64] = 0;
   out_7174174378897740995[65] = 0;
   out_7174174378897740995[66] = 0;
   out_7174174378897740995[67] = 0;
   out_7174174378897740995[68] = 0;
   out_7174174378897740995[69] = 0;
   out_7174174378897740995[70] = 1;
   out_7174174378897740995[71] = 0;
   out_7174174378897740995[72] = 0;
   out_7174174378897740995[73] = 0;
   out_7174174378897740995[74] = 0;
   out_7174174378897740995[75] = 0;
   out_7174174378897740995[76] = 0;
   out_7174174378897740995[77] = 0;
   out_7174174378897740995[78] = 0;
   out_7174174378897740995[79] = 0;
   out_7174174378897740995[80] = 1;
}
void h_25(double *state, double *unused, double *out_3544192021598640535) {
   out_3544192021598640535[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6814073920516697455) {
   out_6814073920516697455[0] = 0;
   out_6814073920516697455[1] = 0;
   out_6814073920516697455[2] = 0;
   out_6814073920516697455[3] = 0;
   out_6814073920516697455[4] = 0;
   out_6814073920516697455[5] = 0;
   out_6814073920516697455[6] = 1;
   out_6814073920516697455[7] = 0;
   out_6814073920516697455[8] = 0;
}
void h_24(double *state, double *unused, double *out_4495363720374893534) {
   out_4495363720374893534[0] = state[4];
   out_4495363720374893534[1] = state[5];
}
void H_24(double *state, double *unused, double *out_9039781704495566017) {
   out_9039781704495566017[0] = 0;
   out_9039781704495566017[1] = 0;
   out_9039781704495566017[2] = 0;
   out_9039781704495566017[3] = 0;
   out_9039781704495566017[4] = 1;
   out_9039781704495566017[5] = 0;
   out_9039781704495566017[6] = 0;
   out_9039781704495566017[7] = 0;
   out_9039781704495566017[8] = 0;
   out_9039781704495566017[9] = 0;
   out_9039781704495566017[10] = 0;
   out_9039781704495566017[11] = 0;
   out_9039781704495566017[12] = 0;
   out_9039781704495566017[13] = 0;
   out_9039781704495566017[14] = 1;
   out_9039781704495566017[15] = 0;
   out_9039781704495566017[16] = 0;
   out_9039781704495566017[17] = 0;
}
void h_30(double *state, double *unused, double *out_3701378689949769680) {
   out_3701378689949769680[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4715979811701237406) {
   out_4715979811701237406[0] = 0;
   out_4715979811701237406[1] = 0;
   out_4715979811701237406[2] = 0;
   out_4715979811701237406[3] = 0;
   out_4715979811701237406[4] = 1;
   out_4715979811701237406[5] = 0;
   out_4715979811701237406[6] = 0;
   out_4715979811701237406[7] = 0;
   out_4715979811701237406[8] = 0;
}
void h_26(double *state, double *unused, double *out_4304694574626247197) {
   out_4304694574626247197[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3072570601642641231) {
   out_3072570601642641231[0] = 0;
   out_3072570601642641231[1] = 0;
   out_3072570601642641231[2] = 0;
   out_3072570601642641231[3] = 0;
   out_3072570601642641231[4] = 0;
   out_3072570601642641231[5] = 0;
   out_3072570601642641231[6] = 0;
   out_3072570601642641231[7] = 1;
   out_3072570601642641231[8] = 0;
}
void h_27(double *state, double *unused, double *out_4920082605135938004) {
   out_4920082605135938004[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6890743123501662317) {
   out_6890743123501662317[0] = 0;
   out_6890743123501662317[1] = 0;
   out_6890743123501662317[2] = 0;
   out_6890743123501662317[3] = 1;
   out_6890743123501662317[4] = 0;
   out_6890743123501662317[5] = 0;
   out_6890743123501662317[6] = 0;
   out_6890743123501662317[7] = 0;
   out_6890743123501662317[8] = 0;
}
void h_29(double *state, double *unused, double *out_4644888542851432115) {
   out_4644888542851432115[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4205748467386845222) {
   out_4205748467386845222[0] = 0;
   out_4205748467386845222[1] = 1;
   out_4205748467386845222[2] = 0;
   out_4205748467386845222[3] = 0;
   out_4205748467386845222[4] = 0;
   out_4205748467386845222[5] = 0;
   out_4205748467386845222[6] = 0;
   out_4205748467386845222[7] = 0;
   out_4205748467386845222[8] = 0;
}
void h_28(double *state, double *unused, double *out_7524487925944635655) {
   out_7524487925944635655[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9158596589253175820) {
   out_9158596589253175820[0] = 1;
   out_9158596589253175820[1] = 0;
   out_9158596589253175820[2] = 0;
   out_9158596589253175820[3] = 0;
   out_9158596589253175820[4] = 0;
   out_9158596589253175820[5] = 0;
   out_9158596589253175820[6] = 0;
   out_9158596589253175820[7] = 0;
   out_9158596589253175820[8] = 0;
}
void h_31(double *state, double *unused, double *out_2369541005072107838) {
   out_2369541005072107838[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6844719882393657883) {
   out_6844719882393657883[0] = 0;
   out_6844719882393657883[1] = 0;
   out_6844719882393657883[2] = 0;
   out_6844719882393657883[3] = 0;
   out_6844719882393657883[4] = 0;
   out_6844719882393657883[5] = 0;
   out_6844719882393657883[6] = 0;
   out_6844719882393657883[7] = 0;
   out_6844719882393657883[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6808268772409694941) {
  err_fun(nom_x, delta_x, out_6808268772409694941);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9195646178207841001) {
  inv_err_fun(nom_x, true_x, out_9195646178207841001);
}
void car_H_mod_fun(double *state, double *out_3291093270527205778) {
  H_mod_fun(state, out_3291093270527205778);
}
void car_f_fun(double *state, double dt, double *out_8991480621967120037) {
  f_fun(state,  dt, out_8991480621967120037);
}
void car_F_fun(double *state, double dt, double *out_7174174378897740995) {
  F_fun(state,  dt, out_7174174378897740995);
}
void car_h_25(double *state, double *unused, double *out_3544192021598640535) {
  h_25(state, unused, out_3544192021598640535);
}
void car_H_25(double *state, double *unused, double *out_6814073920516697455) {
  H_25(state, unused, out_6814073920516697455);
}
void car_h_24(double *state, double *unused, double *out_4495363720374893534) {
  h_24(state, unused, out_4495363720374893534);
}
void car_H_24(double *state, double *unused, double *out_9039781704495566017) {
  H_24(state, unused, out_9039781704495566017);
}
void car_h_30(double *state, double *unused, double *out_3701378689949769680) {
  h_30(state, unused, out_3701378689949769680);
}
void car_H_30(double *state, double *unused, double *out_4715979811701237406) {
  H_30(state, unused, out_4715979811701237406);
}
void car_h_26(double *state, double *unused, double *out_4304694574626247197) {
  h_26(state, unused, out_4304694574626247197);
}
void car_H_26(double *state, double *unused, double *out_3072570601642641231) {
  H_26(state, unused, out_3072570601642641231);
}
void car_h_27(double *state, double *unused, double *out_4920082605135938004) {
  h_27(state, unused, out_4920082605135938004);
}
void car_H_27(double *state, double *unused, double *out_6890743123501662317) {
  H_27(state, unused, out_6890743123501662317);
}
void car_h_29(double *state, double *unused, double *out_4644888542851432115) {
  h_29(state, unused, out_4644888542851432115);
}
void car_H_29(double *state, double *unused, double *out_4205748467386845222) {
  H_29(state, unused, out_4205748467386845222);
}
void car_h_28(double *state, double *unused, double *out_7524487925944635655) {
  h_28(state, unused, out_7524487925944635655);
}
void car_H_28(double *state, double *unused, double *out_9158596589253175820) {
  H_28(state, unused, out_9158596589253175820);
}
void car_h_31(double *state, double *unused, double *out_2369541005072107838) {
  h_31(state, unused, out_2369541005072107838);
}
void car_H_31(double *state, double *unused, double *out_6844719882393657883) {
  H_31(state, unused, out_6844719882393657883);
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
