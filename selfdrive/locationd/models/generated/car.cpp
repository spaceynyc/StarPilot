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
void err_fun(double *nom_x, double *delta_x, double *out_1609199203824105809) {
   out_1609199203824105809[0] = delta_x[0] + nom_x[0];
   out_1609199203824105809[1] = delta_x[1] + nom_x[1];
   out_1609199203824105809[2] = delta_x[2] + nom_x[2];
   out_1609199203824105809[3] = delta_x[3] + nom_x[3];
   out_1609199203824105809[4] = delta_x[4] + nom_x[4];
   out_1609199203824105809[5] = delta_x[5] + nom_x[5];
   out_1609199203824105809[6] = delta_x[6] + nom_x[6];
   out_1609199203824105809[7] = delta_x[7] + nom_x[7];
   out_1609199203824105809[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5316743831523255011) {
   out_5316743831523255011[0] = -nom_x[0] + true_x[0];
   out_5316743831523255011[1] = -nom_x[1] + true_x[1];
   out_5316743831523255011[2] = -nom_x[2] + true_x[2];
   out_5316743831523255011[3] = -nom_x[3] + true_x[3];
   out_5316743831523255011[4] = -nom_x[4] + true_x[4];
   out_5316743831523255011[5] = -nom_x[5] + true_x[5];
   out_5316743831523255011[6] = -nom_x[6] + true_x[6];
   out_5316743831523255011[7] = -nom_x[7] + true_x[7];
   out_5316743831523255011[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6016963909732254518) {
   out_6016963909732254518[0] = 1.0;
   out_6016963909732254518[1] = 0.0;
   out_6016963909732254518[2] = 0.0;
   out_6016963909732254518[3] = 0.0;
   out_6016963909732254518[4] = 0.0;
   out_6016963909732254518[5] = 0.0;
   out_6016963909732254518[6] = 0.0;
   out_6016963909732254518[7] = 0.0;
   out_6016963909732254518[8] = 0.0;
   out_6016963909732254518[9] = 0.0;
   out_6016963909732254518[10] = 1.0;
   out_6016963909732254518[11] = 0.0;
   out_6016963909732254518[12] = 0.0;
   out_6016963909732254518[13] = 0.0;
   out_6016963909732254518[14] = 0.0;
   out_6016963909732254518[15] = 0.0;
   out_6016963909732254518[16] = 0.0;
   out_6016963909732254518[17] = 0.0;
   out_6016963909732254518[18] = 0.0;
   out_6016963909732254518[19] = 0.0;
   out_6016963909732254518[20] = 1.0;
   out_6016963909732254518[21] = 0.0;
   out_6016963909732254518[22] = 0.0;
   out_6016963909732254518[23] = 0.0;
   out_6016963909732254518[24] = 0.0;
   out_6016963909732254518[25] = 0.0;
   out_6016963909732254518[26] = 0.0;
   out_6016963909732254518[27] = 0.0;
   out_6016963909732254518[28] = 0.0;
   out_6016963909732254518[29] = 0.0;
   out_6016963909732254518[30] = 1.0;
   out_6016963909732254518[31] = 0.0;
   out_6016963909732254518[32] = 0.0;
   out_6016963909732254518[33] = 0.0;
   out_6016963909732254518[34] = 0.0;
   out_6016963909732254518[35] = 0.0;
   out_6016963909732254518[36] = 0.0;
   out_6016963909732254518[37] = 0.0;
   out_6016963909732254518[38] = 0.0;
   out_6016963909732254518[39] = 0.0;
   out_6016963909732254518[40] = 1.0;
   out_6016963909732254518[41] = 0.0;
   out_6016963909732254518[42] = 0.0;
   out_6016963909732254518[43] = 0.0;
   out_6016963909732254518[44] = 0.0;
   out_6016963909732254518[45] = 0.0;
   out_6016963909732254518[46] = 0.0;
   out_6016963909732254518[47] = 0.0;
   out_6016963909732254518[48] = 0.0;
   out_6016963909732254518[49] = 0.0;
   out_6016963909732254518[50] = 1.0;
   out_6016963909732254518[51] = 0.0;
   out_6016963909732254518[52] = 0.0;
   out_6016963909732254518[53] = 0.0;
   out_6016963909732254518[54] = 0.0;
   out_6016963909732254518[55] = 0.0;
   out_6016963909732254518[56] = 0.0;
   out_6016963909732254518[57] = 0.0;
   out_6016963909732254518[58] = 0.0;
   out_6016963909732254518[59] = 0.0;
   out_6016963909732254518[60] = 1.0;
   out_6016963909732254518[61] = 0.0;
   out_6016963909732254518[62] = 0.0;
   out_6016963909732254518[63] = 0.0;
   out_6016963909732254518[64] = 0.0;
   out_6016963909732254518[65] = 0.0;
   out_6016963909732254518[66] = 0.0;
   out_6016963909732254518[67] = 0.0;
   out_6016963909732254518[68] = 0.0;
   out_6016963909732254518[69] = 0.0;
   out_6016963909732254518[70] = 1.0;
   out_6016963909732254518[71] = 0.0;
   out_6016963909732254518[72] = 0.0;
   out_6016963909732254518[73] = 0.0;
   out_6016963909732254518[74] = 0.0;
   out_6016963909732254518[75] = 0.0;
   out_6016963909732254518[76] = 0.0;
   out_6016963909732254518[77] = 0.0;
   out_6016963909732254518[78] = 0.0;
   out_6016963909732254518[79] = 0.0;
   out_6016963909732254518[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8201144188883655273) {
   out_8201144188883655273[0] = state[0];
   out_8201144188883655273[1] = state[1];
   out_8201144188883655273[2] = state[2];
   out_8201144188883655273[3] = state[3];
   out_8201144188883655273[4] = state[4];
   out_8201144188883655273[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8201144188883655273[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8201144188883655273[7] = state[7];
   out_8201144188883655273[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3307293311797318081) {
   out_3307293311797318081[0] = 1;
   out_3307293311797318081[1] = 0;
   out_3307293311797318081[2] = 0;
   out_3307293311797318081[3] = 0;
   out_3307293311797318081[4] = 0;
   out_3307293311797318081[5] = 0;
   out_3307293311797318081[6] = 0;
   out_3307293311797318081[7] = 0;
   out_3307293311797318081[8] = 0;
   out_3307293311797318081[9] = 0;
   out_3307293311797318081[10] = 1;
   out_3307293311797318081[11] = 0;
   out_3307293311797318081[12] = 0;
   out_3307293311797318081[13] = 0;
   out_3307293311797318081[14] = 0;
   out_3307293311797318081[15] = 0;
   out_3307293311797318081[16] = 0;
   out_3307293311797318081[17] = 0;
   out_3307293311797318081[18] = 0;
   out_3307293311797318081[19] = 0;
   out_3307293311797318081[20] = 1;
   out_3307293311797318081[21] = 0;
   out_3307293311797318081[22] = 0;
   out_3307293311797318081[23] = 0;
   out_3307293311797318081[24] = 0;
   out_3307293311797318081[25] = 0;
   out_3307293311797318081[26] = 0;
   out_3307293311797318081[27] = 0;
   out_3307293311797318081[28] = 0;
   out_3307293311797318081[29] = 0;
   out_3307293311797318081[30] = 1;
   out_3307293311797318081[31] = 0;
   out_3307293311797318081[32] = 0;
   out_3307293311797318081[33] = 0;
   out_3307293311797318081[34] = 0;
   out_3307293311797318081[35] = 0;
   out_3307293311797318081[36] = 0;
   out_3307293311797318081[37] = 0;
   out_3307293311797318081[38] = 0;
   out_3307293311797318081[39] = 0;
   out_3307293311797318081[40] = 1;
   out_3307293311797318081[41] = 0;
   out_3307293311797318081[42] = 0;
   out_3307293311797318081[43] = 0;
   out_3307293311797318081[44] = 0;
   out_3307293311797318081[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3307293311797318081[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3307293311797318081[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3307293311797318081[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3307293311797318081[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3307293311797318081[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3307293311797318081[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3307293311797318081[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3307293311797318081[53] = -9.8100000000000005*dt;
   out_3307293311797318081[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3307293311797318081[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3307293311797318081[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3307293311797318081[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3307293311797318081[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3307293311797318081[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3307293311797318081[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3307293311797318081[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3307293311797318081[62] = 0;
   out_3307293311797318081[63] = 0;
   out_3307293311797318081[64] = 0;
   out_3307293311797318081[65] = 0;
   out_3307293311797318081[66] = 0;
   out_3307293311797318081[67] = 0;
   out_3307293311797318081[68] = 0;
   out_3307293311797318081[69] = 0;
   out_3307293311797318081[70] = 1;
   out_3307293311797318081[71] = 0;
   out_3307293311797318081[72] = 0;
   out_3307293311797318081[73] = 0;
   out_3307293311797318081[74] = 0;
   out_3307293311797318081[75] = 0;
   out_3307293311797318081[76] = 0;
   out_3307293311797318081[77] = 0;
   out_3307293311797318081[78] = 0;
   out_3307293311797318081[79] = 0;
   out_3307293311797318081[80] = 1;
}
void h_25(double *state, double *unused, double *out_3698742398836886851) {
   out_3698742398836886851[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8906799513987805421) {
   out_8906799513987805421[0] = 0;
   out_8906799513987805421[1] = 0;
   out_8906799513987805421[2] = 0;
   out_8906799513987805421[3] = 0;
   out_8906799513987805421[4] = 0;
   out_8906799513987805421[5] = 0;
   out_8906799513987805421[6] = 1;
   out_8906799513987805421[7] = 0;
   out_8906799513987805421[8] = 0;
}
void h_24(double *state, double *unused, double *out_6071423034488633953) {
   out_6071423034488633953[0] = state[4];
   out_6071423034488633953[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3477981141928203038) {
   out_3477981141928203038[0] = 0;
   out_3477981141928203038[1] = 0;
   out_3477981141928203038[2] = 0;
   out_3477981141928203038[3] = 0;
   out_3477981141928203038[4] = 1;
   out_3477981141928203038[5] = 0;
   out_3477981141928203038[6] = 0;
   out_3477981141928203038[7] = 0;
   out_3477981141928203038[8] = 0;
   out_3477981141928203038[9] = 0;
   out_3477981141928203038[10] = 0;
   out_3477981141928203038[11] = 0;
   out_3477981141928203038[12] = 0;
   out_3477981141928203038[13] = 0;
   out_3477981141928203038[14] = 1;
   out_3477981141928203038[15] = 0;
   out_3477981141928203038[16] = 0;
   out_3477981141928203038[17] = 0;
}
void h_30(double *state, double *unused, double *out_8592554479032004636) {
   out_8592554479032004636[0] = state[4];
}
void H_30(double *state, double *unused, double *out_9036138461131045491) {
   out_9036138461131045491[0] = 0;
   out_9036138461131045491[1] = 0;
   out_9036138461131045491[2] = 0;
   out_9036138461131045491[3] = 0;
   out_9036138461131045491[4] = 1;
   out_9036138461131045491[5] = 0;
   out_9036138461131045491[6] = 0;
   out_9036138461131045491[7] = 0;
   out_9036138461131045491[8] = 0;
}
void h_26(double *state, double *unused, double *out_4787772075959204257) {
   out_4787772075959204257[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5798441240847689971) {
   out_5798441240847689971[0] = 0;
   out_5798441240847689971[1] = 0;
   out_5798441240847689971[2] = 0;
   out_5798441240847689971[3] = 0;
   out_5798441240847689971[4] = 0;
   out_5798441240847689971[5] = 0;
   out_5798441240847689971[6] = 0;
   out_5798441240847689971[7] = 1;
   out_5798441240847689971[8] = 0;
}
void h_27(double *state, double *unused, double *out_661956347392554166) {
   out_661956347392554166[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7235842300778081214) {
   out_7235842300778081214[0] = 0;
   out_7235842300778081214[1] = 0;
   out_7235842300778081214[2] = 0;
   out_7235842300778081214[3] = 1;
   out_7235842300778081214[4] = 0;
   out_7235842300778081214[5] = 0;
   out_7235842300778081214[6] = 0;
   out_7235842300778081214[7] = 0;
   out_7235842300778081214[8] = 0;
}
void h_29(double *state, double *unused, double *out_3590881211371158991) {
   out_3590881211371158991[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5522479573908530181) {
   out_5522479573908530181[0] = 0;
   out_5522479573908530181[1] = 1;
   out_5522479573908530181[2] = 0;
   out_5522479573908530181[3] = 0;
   out_5522479573908530181[4] = 0;
   out_5522479573908530181[5] = 0;
   out_5522479573908530181[6] = 0;
   out_5522479573908530181[7] = 0;
   out_5522479573908530181[8] = 0;
}
void h_28(double *state, double *unused, double *out_1265272232069031683) {
   out_1265272232069031683[0] = state[0];
}
void H_28(double *state, double *unused, double *out_440080556838999607) {
   out_440080556838999607[0] = 1;
   out_440080556838999607[1] = 0;
   out_440080556838999607[2] = 0;
   out_440080556838999607[3] = 0;
   out_440080556838999607[4] = 0;
   out_440080556838999607[5] = 0;
   out_440080556838999607[6] = 0;
   out_440080556838999607[7] = 0;
   out_440080556838999607[8] = 0;
}
void h_31(double *state, double *unused, double *out_3423548336552380962) {
   out_3423548336552380962[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8876153552110844993) {
   out_8876153552110844993[0] = 0;
   out_8876153552110844993[1] = 0;
   out_8876153552110844993[2] = 0;
   out_8876153552110844993[3] = 0;
   out_8876153552110844993[4] = 0;
   out_8876153552110844993[5] = 0;
   out_8876153552110844993[6] = 0;
   out_8876153552110844993[7] = 0;
   out_8876153552110844993[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1609199203824105809) {
  err_fun(nom_x, delta_x, out_1609199203824105809);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5316743831523255011) {
  inv_err_fun(nom_x, true_x, out_5316743831523255011);
}
void car_H_mod_fun(double *state, double *out_6016963909732254518) {
  H_mod_fun(state, out_6016963909732254518);
}
void car_f_fun(double *state, double dt, double *out_8201144188883655273) {
  f_fun(state,  dt, out_8201144188883655273);
}
void car_F_fun(double *state, double dt, double *out_3307293311797318081) {
  F_fun(state,  dt, out_3307293311797318081);
}
void car_h_25(double *state, double *unused, double *out_3698742398836886851) {
  h_25(state, unused, out_3698742398836886851);
}
void car_H_25(double *state, double *unused, double *out_8906799513987805421) {
  H_25(state, unused, out_8906799513987805421);
}
void car_h_24(double *state, double *unused, double *out_6071423034488633953) {
  h_24(state, unused, out_6071423034488633953);
}
void car_H_24(double *state, double *unused, double *out_3477981141928203038) {
  H_24(state, unused, out_3477981141928203038);
}
void car_h_30(double *state, double *unused, double *out_8592554479032004636) {
  h_30(state, unused, out_8592554479032004636);
}
void car_H_30(double *state, double *unused, double *out_9036138461131045491) {
  H_30(state, unused, out_9036138461131045491);
}
void car_h_26(double *state, double *unused, double *out_4787772075959204257) {
  h_26(state, unused, out_4787772075959204257);
}
void car_H_26(double *state, double *unused, double *out_5798441240847689971) {
  H_26(state, unused, out_5798441240847689971);
}
void car_h_27(double *state, double *unused, double *out_661956347392554166) {
  h_27(state, unused, out_661956347392554166);
}
void car_H_27(double *state, double *unused, double *out_7235842300778081214) {
  H_27(state, unused, out_7235842300778081214);
}
void car_h_29(double *state, double *unused, double *out_3590881211371158991) {
  h_29(state, unused, out_3590881211371158991);
}
void car_H_29(double *state, double *unused, double *out_5522479573908530181) {
  H_29(state, unused, out_5522479573908530181);
}
void car_h_28(double *state, double *unused, double *out_1265272232069031683) {
  h_28(state, unused, out_1265272232069031683);
}
void car_H_28(double *state, double *unused, double *out_440080556838999607) {
  H_28(state, unused, out_440080556838999607);
}
void car_h_31(double *state, double *unused, double *out_3423548336552380962) {
  h_31(state, unused, out_3423548336552380962);
}
void car_H_31(double *state, double *unused, double *out_8876153552110844993) {
  H_31(state, unused, out_8876153552110844993);
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
