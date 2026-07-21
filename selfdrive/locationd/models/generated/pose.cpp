#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2987978520246878811) {
   out_2987978520246878811[0] = delta_x[0] + nom_x[0];
   out_2987978520246878811[1] = delta_x[1] + nom_x[1];
   out_2987978520246878811[2] = delta_x[2] + nom_x[2];
   out_2987978520246878811[3] = delta_x[3] + nom_x[3];
   out_2987978520246878811[4] = delta_x[4] + nom_x[4];
   out_2987978520246878811[5] = delta_x[5] + nom_x[5];
   out_2987978520246878811[6] = delta_x[6] + nom_x[6];
   out_2987978520246878811[7] = delta_x[7] + nom_x[7];
   out_2987978520246878811[8] = delta_x[8] + nom_x[8];
   out_2987978520246878811[9] = delta_x[9] + nom_x[9];
   out_2987978520246878811[10] = delta_x[10] + nom_x[10];
   out_2987978520246878811[11] = delta_x[11] + nom_x[11];
   out_2987978520246878811[12] = delta_x[12] + nom_x[12];
   out_2987978520246878811[13] = delta_x[13] + nom_x[13];
   out_2987978520246878811[14] = delta_x[14] + nom_x[14];
   out_2987978520246878811[15] = delta_x[15] + nom_x[15];
   out_2987978520246878811[16] = delta_x[16] + nom_x[16];
   out_2987978520246878811[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7392740910229382527) {
   out_7392740910229382527[0] = -nom_x[0] + true_x[0];
   out_7392740910229382527[1] = -nom_x[1] + true_x[1];
   out_7392740910229382527[2] = -nom_x[2] + true_x[2];
   out_7392740910229382527[3] = -nom_x[3] + true_x[3];
   out_7392740910229382527[4] = -nom_x[4] + true_x[4];
   out_7392740910229382527[5] = -nom_x[5] + true_x[5];
   out_7392740910229382527[6] = -nom_x[6] + true_x[6];
   out_7392740910229382527[7] = -nom_x[7] + true_x[7];
   out_7392740910229382527[8] = -nom_x[8] + true_x[8];
   out_7392740910229382527[9] = -nom_x[9] + true_x[9];
   out_7392740910229382527[10] = -nom_x[10] + true_x[10];
   out_7392740910229382527[11] = -nom_x[11] + true_x[11];
   out_7392740910229382527[12] = -nom_x[12] + true_x[12];
   out_7392740910229382527[13] = -nom_x[13] + true_x[13];
   out_7392740910229382527[14] = -nom_x[14] + true_x[14];
   out_7392740910229382527[15] = -nom_x[15] + true_x[15];
   out_7392740910229382527[16] = -nom_x[16] + true_x[16];
   out_7392740910229382527[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_766595423579160181) {
   out_766595423579160181[0] = 1.0;
   out_766595423579160181[1] = 0.0;
   out_766595423579160181[2] = 0.0;
   out_766595423579160181[3] = 0.0;
   out_766595423579160181[4] = 0.0;
   out_766595423579160181[5] = 0.0;
   out_766595423579160181[6] = 0.0;
   out_766595423579160181[7] = 0.0;
   out_766595423579160181[8] = 0.0;
   out_766595423579160181[9] = 0.0;
   out_766595423579160181[10] = 0.0;
   out_766595423579160181[11] = 0.0;
   out_766595423579160181[12] = 0.0;
   out_766595423579160181[13] = 0.0;
   out_766595423579160181[14] = 0.0;
   out_766595423579160181[15] = 0.0;
   out_766595423579160181[16] = 0.0;
   out_766595423579160181[17] = 0.0;
   out_766595423579160181[18] = 0.0;
   out_766595423579160181[19] = 1.0;
   out_766595423579160181[20] = 0.0;
   out_766595423579160181[21] = 0.0;
   out_766595423579160181[22] = 0.0;
   out_766595423579160181[23] = 0.0;
   out_766595423579160181[24] = 0.0;
   out_766595423579160181[25] = 0.0;
   out_766595423579160181[26] = 0.0;
   out_766595423579160181[27] = 0.0;
   out_766595423579160181[28] = 0.0;
   out_766595423579160181[29] = 0.0;
   out_766595423579160181[30] = 0.0;
   out_766595423579160181[31] = 0.0;
   out_766595423579160181[32] = 0.0;
   out_766595423579160181[33] = 0.0;
   out_766595423579160181[34] = 0.0;
   out_766595423579160181[35] = 0.0;
   out_766595423579160181[36] = 0.0;
   out_766595423579160181[37] = 0.0;
   out_766595423579160181[38] = 1.0;
   out_766595423579160181[39] = 0.0;
   out_766595423579160181[40] = 0.0;
   out_766595423579160181[41] = 0.0;
   out_766595423579160181[42] = 0.0;
   out_766595423579160181[43] = 0.0;
   out_766595423579160181[44] = 0.0;
   out_766595423579160181[45] = 0.0;
   out_766595423579160181[46] = 0.0;
   out_766595423579160181[47] = 0.0;
   out_766595423579160181[48] = 0.0;
   out_766595423579160181[49] = 0.0;
   out_766595423579160181[50] = 0.0;
   out_766595423579160181[51] = 0.0;
   out_766595423579160181[52] = 0.0;
   out_766595423579160181[53] = 0.0;
   out_766595423579160181[54] = 0.0;
   out_766595423579160181[55] = 0.0;
   out_766595423579160181[56] = 0.0;
   out_766595423579160181[57] = 1.0;
   out_766595423579160181[58] = 0.0;
   out_766595423579160181[59] = 0.0;
   out_766595423579160181[60] = 0.0;
   out_766595423579160181[61] = 0.0;
   out_766595423579160181[62] = 0.0;
   out_766595423579160181[63] = 0.0;
   out_766595423579160181[64] = 0.0;
   out_766595423579160181[65] = 0.0;
   out_766595423579160181[66] = 0.0;
   out_766595423579160181[67] = 0.0;
   out_766595423579160181[68] = 0.0;
   out_766595423579160181[69] = 0.0;
   out_766595423579160181[70] = 0.0;
   out_766595423579160181[71] = 0.0;
   out_766595423579160181[72] = 0.0;
   out_766595423579160181[73] = 0.0;
   out_766595423579160181[74] = 0.0;
   out_766595423579160181[75] = 0.0;
   out_766595423579160181[76] = 1.0;
   out_766595423579160181[77] = 0.0;
   out_766595423579160181[78] = 0.0;
   out_766595423579160181[79] = 0.0;
   out_766595423579160181[80] = 0.0;
   out_766595423579160181[81] = 0.0;
   out_766595423579160181[82] = 0.0;
   out_766595423579160181[83] = 0.0;
   out_766595423579160181[84] = 0.0;
   out_766595423579160181[85] = 0.0;
   out_766595423579160181[86] = 0.0;
   out_766595423579160181[87] = 0.0;
   out_766595423579160181[88] = 0.0;
   out_766595423579160181[89] = 0.0;
   out_766595423579160181[90] = 0.0;
   out_766595423579160181[91] = 0.0;
   out_766595423579160181[92] = 0.0;
   out_766595423579160181[93] = 0.0;
   out_766595423579160181[94] = 0.0;
   out_766595423579160181[95] = 1.0;
   out_766595423579160181[96] = 0.0;
   out_766595423579160181[97] = 0.0;
   out_766595423579160181[98] = 0.0;
   out_766595423579160181[99] = 0.0;
   out_766595423579160181[100] = 0.0;
   out_766595423579160181[101] = 0.0;
   out_766595423579160181[102] = 0.0;
   out_766595423579160181[103] = 0.0;
   out_766595423579160181[104] = 0.0;
   out_766595423579160181[105] = 0.0;
   out_766595423579160181[106] = 0.0;
   out_766595423579160181[107] = 0.0;
   out_766595423579160181[108] = 0.0;
   out_766595423579160181[109] = 0.0;
   out_766595423579160181[110] = 0.0;
   out_766595423579160181[111] = 0.0;
   out_766595423579160181[112] = 0.0;
   out_766595423579160181[113] = 0.0;
   out_766595423579160181[114] = 1.0;
   out_766595423579160181[115] = 0.0;
   out_766595423579160181[116] = 0.0;
   out_766595423579160181[117] = 0.0;
   out_766595423579160181[118] = 0.0;
   out_766595423579160181[119] = 0.0;
   out_766595423579160181[120] = 0.0;
   out_766595423579160181[121] = 0.0;
   out_766595423579160181[122] = 0.0;
   out_766595423579160181[123] = 0.0;
   out_766595423579160181[124] = 0.0;
   out_766595423579160181[125] = 0.0;
   out_766595423579160181[126] = 0.0;
   out_766595423579160181[127] = 0.0;
   out_766595423579160181[128] = 0.0;
   out_766595423579160181[129] = 0.0;
   out_766595423579160181[130] = 0.0;
   out_766595423579160181[131] = 0.0;
   out_766595423579160181[132] = 0.0;
   out_766595423579160181[133] = 1.0;
   out_766595423579160181[134] = 0.0;
   out_766595423579160181[135] = 0.0;
   out_766595423579160181[136] = 0.0;
   out_766595423579160181[137] = 0.0;
   out_766595423579160181[138] = 0.0;
   out_766595423579160181[139] = 0.0;
   out_766595423579160181[140] = 0.0;
   out_766595423579160181[141] = 0.0;
   out_766595423579160181[142] = 0.0;
   out_766595423579160181[143] = 0.0;
   out_766595423579160181[144] = 0.0;
   out_766595423579160181[145] = 0.0;
   out_766595423579160181[146] = 0.0;
   out_766595423579160181[147] = 0.0;
   out_766595423579160181[148] = 0.0;
   out_766595423579160181[149] = 0.0;
   out_766595423579160181[150] = 0.0;
   out_766595423579160181[151] = 0.0;
   out_766595423579160181[152] = 1.0;
   out_766595423579160181[153] = 0.0;
   out_766595423579160181[154] = 0.0;
   out_766595423579160181[155] = 0.0;
   out_766595423579160181[156] = 0.0;
   out_766595423579160181[157] = 0.0;
   out_766595423579160181[158] = 0.0;
   out_766595423579160181[159] = 0.0;
   out_766595423579160181[160] = 0.0;
   out_766595423579160181[161] = 0.0;
   out_766595423579160181[162] = 0.0;
   out_766595423579160181[163] = 0.0;
   out_766595423579160181[164] = 0.0;
   out_766595423579160181[165] = 0.0;
   out_766595423579160181[166] = 0.0;
   out_766595423579160181[167] = 0.0;
   out_766595423579160181[168] = 0.0;
   out_766595423579160181[169] = 0.0;
   out_766595423579160181[170] = 0.0;
   out_766595423579160181[171] = 1.0;
   out_766595423579160181[172] = 0.0;
   out_766595423579160181[173] = 0.0;
   out_766595423579160181[174] = 0.0;
   out_766595423579160181[175] = 0.0;
   out_766595423579160181[176] = 0.0;
   out_766595423579160181[177] = 0.0;
   out_766595423579160181[178] = 0.0;
   out_766595423579160181[179] = 0.0;
   out_766595423579160181[180] = 0.0;
   out_766595423579160181[181] = 0.0;
   out_766595423579160181[182] = 0.0;
   out_766595423579160181[183] = 0.0;
   out_766595423579160181[184] = 0.0;
   out_766595423579160181[185] = 0.0;
   out_766595423579160181[186] = 0.0;
   out_766595423579160181[187] = 0.0;
   out_766595423579160181[188] = 0.0;
   out_766595423579160181[189] = 0.0;
   out_766595423579160181[190] = 1.0;
   out_766595423579160181[191] = 0.0;
   out_766595423579160181[192] = 0.0;
   out_766595423579160181[193] = 0.0;
   out_766595423579160181[194] = 0.0;
   out_766595423579160181[195] = 0.0;
   out_766595423579160181[196] = 0.0;
   out_766595423579160181[197] = 0.0;
   out_766595423579160181[198] = 0.0;
   out_766595423579160181[199] = 0.0;
   out_766595423579160181[200] = 0.0;
   out_766595423579160181[201] = 0.0;
   out_766595423579160181[202] = 0.0;
   out_766595423579160181[203] = 0.0;
   out_766595423579160181[204] = 0.0;
   out_766595423579160181[205] = 0.0;
   out_766595423579160181[206] = 0.0;
   out_766595423579160181[207] = 0.0;
   out_766595423579160181[208] = 0.0;
   out_766595423579160181[209] = 1.0;
   out_766595423579160181[210] = 0.0;
   out_766595423579160181[211] = 0.0;
   out_766595423579160181[212] = 0.0;
   out_766595423579160181[213] = 0.0;
   out_766595423579160181[214] = 0.0;
   out_766595423579160181[215] = 0.0;
   out_766595423579160181[216] = 0.0;
   out_766595423579160181[217] = 0.0;
   out_766595423579160181[218] = 0.0;
   out_766595423579160181[219] = 0.0;
   out_766595423579160181[220] = 0.0;
   out_766595423579160181[221] = 0.0;
   out_766595423579160181[222] = 0.0;
   out_766595423579160181[223] = 0.0;
   out_766595423579160181[224] = 0.0;
   out_766595423579160181[225] = 0.0;
   out_766595423579160181[226] = 0.0;
   out_766595423579160181[227] = 0.0;
   out_766595423579160181[228] = 1.0;
   out_766595423579160181[229] = 0.0;
   out_766595423579160181[230] = 0.0;
   out_766595423579160181[231] = 0.0;
   out_766595423579160181[232] = 0.0;
   out_766595423579160181[233] = 0.0;
   out_766595423579160181[234] = 0.0;
   out_766595423579160181[235] = 0.0;
   out_766595423579160181[236] = 0.0;
   out_766595423579160181[237] = 0.0;
   out_766595423579160181[238] = 0.0;
   out_766595423579160181[239] = 0.0;
   out_766595423579160181[240] = 0.0;
   out_766595423579160181[241] = 0.0;
   out_766595423579160181[242] = 0.0;
   out_766595423579160181[243] = 0.0;
   out_766595423579160181[244] = 0.0;
   out_766595423579160181[245] = 0.0;
   out_766595423579160181[246] = 0.0;
   out_766595423579160181[247] = 1.0;
   out_766595423579160181[248] = 0.0;
   out_766595423579160181[249] = 0.0;
   out_766595423579160181[250] = 0.0;
   out_766595423579160181[251] = 0.0;
   out_766595423579160181[252] = 0.0;
   out_766595423579160181[253] = 0.0;
   out_766595423579160181[254] = 0.0;
   out_766595423579160181[255] = 0.0;
   out_766595423579160181[256] = 0.0;
   out_766595423579160181[257] = 0.0;
   out_766595423579160181[258] = 0.0;
   out_766595423579160181[259] = 0.0;
   out_766595423579160181[260] = 0.0;
   out_766595423579160181[261] = 0.0;
   out_766595423579160181[262] = 0.0;
   out_766595423579160181[263] = 0.0;
   out_766595423579160181[264] = 0.0;
   out_766595423579160181[265] = 0.0;
   out_766595423579160181[266] = 1.0;
   out_766595423579160181[267] = 0.0;
   out_766595423579160181[268] = 0.0;
   out_766595423579160181[269] = 0.0;
   out_766595423579160181[270] = 0.0;
   out_766595423579160181[271] = 0.0;
   out_766595423579160181[272] = 0.0;
   out_766595423579160181[273] = 0.0;
   out_766595423579160181[274] = 0.0;
   out_766595423579160181[275] = 0.0;
   out_766595423579160181[276] = 0.0;
   out_766595423579160181[277] = 0.0;
   out_766595423579160181[278] = 0.0;
   out_766595423579160181[279] = 0.0;
   out_766595423579160181[280] = 0.0;
   out_766595423579160181[281] = 0.0;
   out_766595423579160181[282] = 0.0;
   out_766595423579160181[283] = 0.0;
   out_766595423579160181[284] = 0.0;
   out_766595423579160181[285] = 1.0;
   out_766595423579160181[286] = 0.0;
   out_766595423579160181[287] = 0.0;
   out_766595423579160181[288] = 0.0;
   out_766595423579160181[289] = 0.0;
   out_766595423579160181[290] = 0.0;
   out_766595423579160181[291] = 0.0;
   out_766595423579160181[292] = 0.0;
   out_766595423579160181[293] = 0.0;
   out_766595423579160181[294] = 0.0;
   out_766595423579160181[295] = 0.0;
   out_766595423579160181[296] = 0.0;
   out_766595423579160181[297] = 0.0;
   out_766595423579160181[298] = 0.0;
   out_766595423579160181[299] = 0.0;
   out_766595423579160181[300] = 0.0;
   out_766595423579160181[301] = 0.0;
   out_766595423579160181[302] = 0.0;
   out_766595423579160181[303] = 0.0;
   out_766595423579160181[304] = 1.0;
   out_766595423579160181[305] = 0.0;
   out_766595423579160181[306] = 0.0;
   out_766595423579160181[307] = 0.0;
   out_766595423579160181[308] = 0.0;
   out_766595423579160181[309] = 0.0;
   out_766595423579160181[310] = 0.0;
   out_766595423579160181[311] = 0.0;
   out_766595423579160181[312] = 0.0;
   out_766595423579160181[313] = 0.0;
   out_766595423579160181[314] = 0.0;
   out_766595423579160181[315] = 0.0;
   out_766595423579160181[316] = 0.0;
   out_766595423579160181[317] = 0.0;
   out_766595423579160181[318] = 0.0;
   out_766595423579160181[319] = 0.0;
   out_766595423579160181[320] = 0.0;
   out_766595423579160181[321] = 0.0;
   out_766595423579160181[322] = 0.0;
   out_766595423579160181[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_422668654560890686) {
   out_422668654560890686[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_422668654560890686[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_422668654560890686[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_422668654560890686[3] = dt*state[12] + state[3];
   out_422668654560890686[4] = dt*state[13] + state[4];
   out_422668654560890686[5] = dt*state[14] + state[5];
   out_422668654560890686[6] = state[6];
   out_422668654560890686[7] = state[7];
   out_422668654560890686[8] = state[8];
   out_422668654560890686[9] = state[9];
   out_422668654560890686[10] = state[10];
   out_422668654560890686[11] = state[11];
   out_422668654560890686[12] = state[12];
   out_422668654560890686[13] = state[13];
   out_422668654560890686[14] = state[14];
   out_422668654560890686[15] = state[15];
   out_422668654560890686[16] = state[16];
   out_422668654560890686[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2475263657764665516) {
   out_2475263657764665516[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2475263657764665516[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2475263657764665516[2] = 0;
   out_2475263657764665516[3] = 0;
   out_2475263657764665516[4] = 0;
   out_2475263657764665516[5] = 0;
   out_2475263657764665516[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2475263657764665516[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2475263657764665516[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2475263657764665516[9] = 0;
   out_2475263657764665516[10] = 0;
   out_2475263657764665516[11] = 0;
   out_2475263657764665516[12] = 0;
   out_2475263657764665516[13] = 0;
   out_2475263657764665516[14] = 0;
   out_2475263657764665516[15] = 0;
   out_2475263657764665516[16] = 0;
   out_2475263657764665516[17] = 0;
   out_2475263657764665516[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2475263657764665516[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2475263657764665516[20] = 0;
   out_2475263657764665516[21] = 0;
   out_2475263657764665516[22] = 0;
   out_2475263657764665516[23] = 0;
   out_2475263657764665516[24] = 0;
   out_2475263657764665516[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2475263657764665516[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2475263657764665516[27] = 0;
   out_2475263657764665516[28] = 0;
   out_2475263657764665516[29] = 0;
   out_2475263657764665516[30] = 0;
   out_2475263657764665516[31] = 0;
   out_2475263657764665516[32] = 0;
   out_2475263657764665516[33] = 0;
   out_2475263657764665516[34] = 0;
   out_2475263657764665516[35] = 0;
   out_2475263657764665516[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2475263657764665516[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2475263657764665516[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2475263657764665516[39] = 0;
   out_2475263657764665516[40] = 0;
   out_2475263657764665516[41] = 0;
   out_2475263657764665516[42] = 0;
   out_2475263657764665516[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2475263657764665516[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2475263657764665516[45] = 0;
   out_2475263657764665516[46] = 0;
   out_2475263657764665516[47] = 0;
   out_2475263657764665516[48] = 0;
   out_2475263657764665516[49] = 0;
   out_2475263657764665516[50] = 0;
   out_2475263657764665516[51] = 0;
   out_2475263657764665516[52] = 0;
   out_2475263657764665516[53] = 0;
   out_2475263657764665516[54] = 0;
   out_2475263657764665516[55] = 0;
   out_2475263657764665516[56] = 0;
   out_2475263657764665516[57] = 1;
   out_2475263657764665516[58] = 0;
   out_2475263657764665516[59] = 0;
   out_2475263657764665516[60] = 0;
   out_2475263657764665516[61] = 0;
   out_2475263657764665516[62] = 0;
   out_2475263657764665516[63] = 0;
   out_2475263657764665516[64] = 0;
   out_2475263657764665516[65] = 0;
   out_2475263657764665516[66] = dt;
   out_2475263657764665516[67] = 0;
   out_2475263657764665516[68] = 0;
   out_2475263657764665516[69] = 0;
   out_2475263657764665516[70] = 0;
   out_2475263657764665516[71] = 0;
   out_2475263657764665516[72] = 0;
   out_2475263657764665516[73] = 0;
   out_2475263657764665516[74] = 0;
   out_2475263657764665516[75] = 0;
   out_2475263657764665516[76] = 1;
   out_2475263657764665516[77] = 0;
   out_2475263657764665516[78] = 0;
   out_2475263657764665516[79] = 0;
   out_2475263657764665516[80] = 0;
   out_2475263657764665516[81] = 0;
   out_2475263657764665516[82] = 0;
   out_2475263657764665516[83] = 0;
   out_2475263657764665516[84] = 0;
   out_2475263657764665516[85] = dt;
   out_2475263657764665516[86] = 0;
   out_2475263657764665516[87] = 0;
   out_2475263657764665516[88] = 0;
   out_2475263657764665516[89] = 0;
   out_2475263657764665516[90] = 0;
   out_2475263657764665516[91] = 0;
   out_2475263657764665516[92] = 0;
   out_2475263657764665516[93] = 0;
   out_2475263657764665516[94] = 0;
   out_2475263657764665516[95] = 1;
   out_2475263657764665516[96] = 0;
   out_2475263657764665516[97] = 0;
   out_2475263657764665516[98] = 0;
   out_2475263657764665516[99] = 0;
   out_2475263657764665516[100] = 0;
   out_2475263657764665516[101] = 0;
   out_2475263657764665516[102] = 0;
   out_2475263657764665516[103] = 0;
   out_2475263657764665516[104] = dt;
   out_2475263657764665516[105] = 0;
   out_2475263657764665516[106] = 0;
   out_2475263657764665516[107] = 0;
   out_2475263657764665516[108] = 0;
   out_2475263657764665516[109] = 0;
   out_2475263657764665516[110] = 0;
   out_2475263657764665516[111] = 0;
   out_2475263657764665516[112] = 0;
   out_2475263657764665516[113] = 0;
   out_2475263657764665516[114] = 1;
   out_2475263657764665516[115] = 0;
   out_2475263657764665516[116] = 0;
   out_2475263657764665516[117] = 0;
   out_2475263657764665516[118] = 0;
   out_2475263657764665516[119] = 0;
   out_2475263657764665516[120] = 0;
   out_2475263657764665516[121] = 0;
   out_2475263657764665516[122] = 0;
   out_2475263657764665516[123] = 0;
   out_2475263657764665516[124] = 0;
   out_2475263657764665516[125] = 0;
   out_2475263657764665516[126] = 0;
   out_2475263657764665516[127] = 0;
   out_2475263657764665516[128] = 0;
   out_2475263657764665516[129] = 0;
   out_2475263657764665516[130] = 0;
   out_2475263657764665516[131] = 0;
   out_2475263657764665516[132] = 0;
   out_2475263657764665516[133] = 1;
   out_2475263657764665516[134] = 0;
   out_2475263657764665516[135] = 0;
   out_2475263657764665516[136] = 0;
   out_2475263657764665516[137] = 0;
   out_2475263657764665516[138] = 0;
   out_2475263657764665516[139] = 0;
   out_2475263657764665516[140] = 0;
   out_2475263657764665516[141] = 0;
   out_2475263657764665516[142] = 0;
   out_2475263657764665516[143] = 0;
   out_2475263657764665516[144] = 0;
   out_2475263657764665516[145] = 0;
   out_2475263657764665516[146] = 0;
   out_2475263657764665516[147] = 0;
   out_2475263657764665516[148] = 0;
   out_2475263657764665516[149] = 0;
   out_2475263657764665516[150] = 0;
   out_2475263657764665516[151] = 0;
   out_2475263657764665516[152] = 1;
   out_2475263657764665516[153] = 0;
   out_2475263657764665516[154] = 0;
   out_2475263657764665516[155] = 0;
   out_2475263657764665516[156] = 0;
   out_2475263657764665516[157] = 0;
   out_2475263657764665516[158] = 0;
   out_2475263657764665516[159] = 0;
   out_2475263657764665516[160] = 0;
   out_2475263657764665516[161] = 0;
   out_2475263657764665516[162] = 0;
   out_2475263657764665516[163] = 0;
   out_2475263657764665516[164] = 0;
   out_2475263657764665516[165] = 0;
   out_2475263657764665516[166] = 0;
   out_2475263657764665516[167] = 0;
   out_2475263657764665516[168] = 0;
   out_2475263657764665516[169] = 0;
   out_2475263657764665516[170] = 0;
   out_2475263657764665516[171] = 1;
   out_2475263657764665516[172] = 0;
   out_2475263657764665516[173] = 0;
   out_2475263657764665516[174] = 0;
   out_2475263657764665516[175] = 0;
   out_2475263657764665516[176] = 0;
   out_2475263657764665516[177] = 0;
   out_2475263657764665516[178] = 0;
   out_2475263657764665516[179] = 0;
   out_2475263657764665516[180] = 0;
   out_2475263657764665516[181] = 0;
   out_2475263657764665516[182] = 0;
   out_2475263657764665516[183] = 0;
   out_2475263657764665516[184] = 0;
   out_2475263657764665516[185] = 0;
   out_2475263657764665516[186] = 0;
   out_2475263657764665516[187] = 0;
   out_2475263657764665516[188] = 0;
   out_2475263657764665516[189] = 0;
   out_2475263657764665516[190] = 1;
   out_2475263657764665516[191] = 0;
   out_2475263657764665516[192] = 0;
   out_2475263657764665516[193] = 0;
   out_2475263657764665516[194] = 0;
   out_2475263657764665516[195] = 0;
   out_2475263657764665516[196] = 0;
   out_2475263657764665516[197] = 0;
   out_2475263657764665516[198] = 0;
   out_2475263657764665516[199] = 0;
   out_2475263657764665516[200] = 0;
   out_2475263657764665516[201] = 0;
   out_2475263657764665516[202] = 0;
   out_2475263657764665516[203] = 0;
   out_2475263657764665516[204] = 0;
   out_2475263657764665516[205] = 0;
   out_2475263657764665516[206] = 0;
   out_2475263657764665516[207] = 0;
   out_2475263657764665516[208] = 0;
   out_2475263657764665516[209] = 1;
   out_2475263657764665516[210] = 0;
   out_2475263657764665516[211] = 0;
   out_2475263657764665516[212] = 0;
   out_2475263657764665516[213] = 0;
   out_2475263657764665516[214] = 0;
   out_2475263657764665516[215] = 0;
   out_2475263657764665516[216] = 0;
   out_2475263657764665516[217] = 0;
   out_2475263657764665516[218] = 0;
   out_2475263657764665516[219] = 0;
   out_2475263657764665516[220] = 0;
   out_2475263657764665516[221] = 0;
   out_2475263657764665516[222] = 0;
   out_2475263657764665516[223] = 0;
   out_2475263657764665516[224] = 0;
   out_2475263657764665516[225] = 0;
   out_2475263657764665516[226] = 0;
   out_2475263657764665516[227] = 0;
   out_2475263657764665516[228] = 1;
   out_2475263657764665516[229] = 0;
   out_2475263657764665516[230] = 0;
   out_2475263657764665516[231] = 0;
   out_2475263657764665516[232] = 0;
   out_2475263657764665516[233] = 0;
   out_2475263657764665516[234] = 0;
   out_2475263657764665516[235] = 0;
   out_2475263657764665516[236] = 0;
   out_2475263657764665516[237] = 0;
   out_2475263657764665516[238] = 0;
   out_2475263657764665516[239] = 0;
   out_2475263657764665516[240] = 0;
   out_2475263657764665516[241] = 0;
   out_2475263657764665516[242] = 0;
   out_2475263657764665516[243] = 0;
   out_2475263657764665516[244] = 0;
   out_2475263657764665516[245] = 0;
   out_2475263657764665516[246] = 0;
   out_2475263657764665516[247] = 1;
   out_2475263657764665516[248] = 0;
   out_2475263657764665516[249] = 0;
   out_2475263657764665516[250] = 0;
   out_2475263657764665516[251] = 0;
   out_2475263657764665516[252] = 0;
   out_2475263657764665516[253] = 0;
   out_2475263657764665516[254] = 0;
   out_2475263657764665516[255] = 0;
   out_2475263657764665516[256] = 0;
   out_2475263657764665516[257] = 0;
   out_2475263657764665516[258] = 0;
   out_2475263657764665516[259] = 0;
   out_2475263657764665516[260] = 0;
   out_2475263657764665516[261] = 0;
   out_2475263657764665516[262] = 0;
   out_2475263657764665516[263] = 0;
   out_2475263657764665516[264] = 0;
   out_2475263657764665516[265] = 0;
   out_2475263657764665516[266] = 1;
   out_2475263657764665516[267] = 0;
   out_2475263657764665516[268] = 0;
   out_2475263657764665516[269] = 0;
   out_2475263657764665516[270] = 0;
   out_2475263657764665516[271] = 0;
   out_2475263657764665516[272] = 0;
   out_2475263657764665516[273] = 0;
   out_2475263657764665516[274] = 0;
   out_2475263657764665516[275] = 0;
   out_2475263657764665516[276] = 0;
   out_2475263657764665516[277] = 0;
   out_2475263657764665516[278] = 0;
   out_2475263657764665516[279] = 0;
   out_2475263657764665516[280] = 0;
   out_2475263657764665516[281] = 0;
   out_2475263657764665516[282] = 0;
   out_2475263657764665516[283] = 0;
   out_2475263657764665516[284] = 0;
   out_2475263657764665516[285] = 1;
   out_2475263657764665516[286] = 0;
   out_2475263657764665516[287] = 0;
   out_2475263657764665516[288] = 0;
   out_2475263657764665516[289] = 0;
   out_2475263657764665516[290] = 0;
   out_2475263657764665516[291] = 0;
   out_2475263657764665516[292] = 0;
   out_2475263657764665516[293] = 0;
   out_2475263657764665516[294] = 0;
   out_2475263657764665516[295] = 0;
   out_2475263657764665516[296] = 0;
   out_2475263657764665516[297] = 0;
   out_2475263657764665516[298] = 0;
   out_2475263657764665516[299] = 0;
   out_2475263657764665516[300] = 0;
   out_2475263657764665516[301] = 0;
   out_2475263657764665516[302] = 0;
   out_2475263657764665516[303] = 0;
   out_2475263657764665516[304] = 1;
   out_2475263657764665516[305] = 0;
   out_2475263657764665516[306] = 0;
   out_2475263657764665516[307] = 0;
   out_2475263657764665516[308] = 0;
   out_2475263657764665516[309] = 0;
   out_2475263657764665516[310] = 0;
   out_2475263657764665516[311] = 0;
   out_2475263657764665516[312] = 0;
   out_2475263657764665516[313] = 0;
   out_2475263657764665516[314] = 0;
   out_2475263657764665516[315] = 0;
   out_2475263657764665516[316] = 0;
   out_2475263657764665516[317] = 0;
   out_2475263657764665516[318] = 0;
   out_2475263657764665516[319] = 0;
   out_2475263657764665516[320] = 0;
   out_2475263657764665516[321] = 0;
   out_2475263657764665516[322] = 0;
   out_2475263657764665516[323] = 1;
}
void h_4(double *state, double *unused, double *out_1835432060314574929) {
   out_1835432060314574929[0] = state[6] + state[9];
   out_1835432060314574929[1] = state[7] + state[10];
   out_1835432060314574929[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8177766242478661161) {
   out_8177766242478661161[0] = 0;
   out_8177766242478661161[1] = 0;
   out_8177766242478661161[2] = 0;
   out_8177766242478661161[3] = 0;
   out_8177766242478661161[4] = 0;
   out_8177766242478661161[5] = 0;
   out_8177766242478661161[6] = 1;
   out_8177766242478661161[7] = 0;
   out_8177766242478661161[8] = 0;
   out_8177766242478661161[9] = 1;
   out_8177766242478661161[10] = 0;
   out_8177766242478661161[11] = 0;
   out_8177766242478661161[12] = 0;
   out_8177766242478661161[13] = 0;
   out_8177766242478661161[14] = 0;
   out_8177766242478661161[15] = 0;
   out_8177766242478661161[16] = 0;
   out_8177766242478661161[17] = 0;
   out_8177766242478661161[18] = 0;
   out_8177766242478661161[19] = 0;
   out_8177766242478661161[20] = 0;
   out_8177766242478661161[21] = 0;
   out_8177766242478661161[22] = 0;
   out_8177766242478661161[23] = 0;
   out_8177766242478661161[24] = 0;
   out_8177766242478661161[25] = 1;
   out_8177766242478661161[26] = 0;
   out_8177766242478661161[27] = 0;
   out_8177766242478661161[28] = 1;
   out_8177766242478661161[29] = 0;
   out_8177766242478661161[30] = 0;
   out_8177766242478661161[31] = 0;
   out_8177766242478661161[32] = 0;
   out_8177766242478661161[33] = 0;
   out_8177766242478661161[34] = 0;
   out_8177766242478661161[35] = 0;
   out_8177766242478661161[36] = 0;
   out_8177766242478661161[37] = 0;
   out_8177766242478661161[38] = 0;
   out_8177766242478661161[39] = 0;
   out_8177766242478661161[40] = 0;
   out_8177766242478661161[41] = 0;
   out_8177766242478661161[42] = 0;
   out_8177766242478661161[43] = 0;
   out_8177766242478661161[44] = 1;
   out_8177766242478661161[45] = 0;
   out_8177766242478661161[46] = 0;
   out_8177766242478661161[47] = 1;
   out_8177766242478661161[48] = 0;
   out_8177766242478661161[49] = 0;
   out_8177766242478661161[50] = 0;
   out_8177766242478661161[51] = 0;
   out_8177766242478661161[52] = 0;
   out_8177766242478661161[53] = 0;
}
void h_10(double *state, double *unused, double *out_4694595839556490884) {
   out_4694595839556490884[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4694595839556490884[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4694595839556490884[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5779971349689640500) {
   out_5779971349689640500[0] = 0;
   out_5779971349689640500[1] = 9.8100000000000005*cos(state[1]);
   out_5779971349689640500[2] = 0;
   out_5779971349689640500[3] = 0;
   out_5779971349689640500[4] = -state[8];
   out_5779971349689640500[5] = state[7];
   out_5779971349689640500[6] = 0;
   out_5779971349689640500[7] = state[5];
   out_5779971349689640500[8] = -state[4];
   out_5779971349689640500[9] = 0;
   out_5779971349689640500[10] = 0;
   out_5779971349689640500[11] = 0;
   out_5779971349689640500[12] = 1;
   out_5779971349689640500[13] = 0;
   out_5779971349689640500[14] = 0;
   out_5779971349689640500[15] = 1;
   out_5779971349689640500[16] = 0;
   out_5779971349689640500[17] = 0;
   out_5779971349689640500[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5779971349689640500[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5779971349689640500[20] = 0;
   out_5779971349689640500[21] = state[8];
   out_5779971349689640500[22] = 0;
   out_5779971349689640500[23] = -state[6];
   out_5779971349689640500[24] = -state[5];
   out_5779971349689640500[25] = 0;
   out_5779971349689640500[26] = state[3];
   out_5779971349689640500[27] = 0;
   out_5779971349689640500[28] = 0;
   out_5779971349689640500[29] = 0;
   out_5779971349689640500[30] = 0;
   out_5779971349689640500[31] = 1;
   out_5779971349689640500[32] = 0;
   out_5779971349689640500[33] = 0;
   out_5779971349689640500[34] = 1;
   out_5779971349689640500[35] = 0;
   out_5779971349689640500[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5779971349689640500[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5779971349689640500[38] = 0;
   out_5779971349689640500[39] = -state[7];
   out_5779971349689640500[40] = state[6];
   out_5779971349689640500[41] = 0;
   out_5779971349689640500[42] = state[4];
   out_5779971349689640500[43] = -state[3];
   out_5779971349689640500[44] = 0;
   out_5779971349689640500[45] = 0;
   out_5779971349689640500[46] = 0;
   out_5779971349689640500[47] = 0;
   out_5779971349689640500[48] = 0;
   out_5779971349689640500[49] = 0;
   out_5779971349689640500[50] = 1;
   out_5779971349689640500[51] = 0;
   out_5779971349689640500[52] = 0;
   out_5779971349689640500[53] = 1;
}
void h_13(double *state, double *unused, double *out_4377602138518793981) {
   out_4377602138518793981[0] = state[3];
   out_4377602138518793981[1] = state[4];
   out_4377602138518793981[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4965492417146328360) {
   out_4965492417146328360[0] = 0;
   out_4965492417146328360[1] = 0;
   out_4965492417146328360[2] = 0;
   out_4965492417146328360[3] = 1;
   out_4965492417146328360[4] = 0;
   out_4965492417146328360[5] = 0;
   out_4965492417146328360[6] = 0;
   out_4965492417146328360[7] = 0;
   out_4965492417146328360[8] = 0;
   out_4965492417146328360[9] = 0;
   out_4965492417146328360[10] = 0;
   out_4965492417146328360[11] = 0;
   out_4965492417146328360[12] = 0;
   out_4965492417146328360[13] = 0;
   out_4965492417146328360[14] = 0;
   out_4965492417146328360[15] = 0;
   out_4965492417146328360[16] = 0;
   out_4965492417146328360[17] = 0;
   out_4965492417146328360[18] = 0;
   out_4965492417146328360[19] = 0;
   out_4965492417146328360[20] = 0;
   out_4965492417146328360[21] = 0;
   out_4965492417146328360[22] = 1;
   out_4965492417146328360[23] = 0;
   out_4965492417146328360[24] = 0;
   out_4965492417146328360[25] = 0;
   out_4965492417146328360[26] = 0;
   out_4965492417146328360[27] = 0;
   out_4965492417146328360[28] = 0;
   out_4965492417146328360[29] = 0;
   out_4965492417146328360[30] = 0;
   out_4965492417146328360[31] = 0;
   out_4965492417146328360[32] = 0;
   out_4965492417146328360[33] = 0;
   out_4965492417146328360[34] = 0;
   out_4965492417146328360[35] = 0;
   out_4965492417146328360[36] = 0;
   out_4965492417146328360[37] = 0;
   out_4965492417146328360[38] = 0;
   out_4965492417146328360[39] = 0;
   out_4965492417146328360[40] = 0;
   out_4965492417146328360[41] = 1;
   out_4965492417146328360[42] = 0;
   out_4965492417146328360[43] = 0;
   out_4965492417146328360[44] = 0;
   out_4965492417146328360[45] = 0;
   out_4965492417146328360[46] = 0;
   out_4965492417146328360[47] = 0;
   out_4965492417146328360[48] = 0;
   out_4965492417146328360[49] = 0;
   out_4965492417146328360[50] = 0;
   out_4965492417146328360[51] = 0;
   out_4965492417146328360[52] = 0;
   out_4965492417146328360[53] = 0;
}
void h_14(double *state, double *unused, double *out_1646321224287546567) {
   out_1646321224287546567[0] = state[6];
   out_1646321224287546567[1] = state[7];
   out_1646321224287546567[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7186189398935518159) {
   out_7186189398935518159[0] = 0;
   out_7186189398935518159[1] = 0;
   out_7186189398935518159[2] = 0;
   out_7186189398935518159[3] = 0;
   out_7186189398935518159[4] = 0;
   out_7186189398935518159[5] = 0;
   out_7186189398935518159[6] = 1;
   out_7186189398935518159[7] = 0;
   out_7186189398935518159[8] = 0;
   out_7186189398935518159[9] = 0;
   out_7186189398935518159[10] = 0;
   out_7186189398935518159[11] = 0;
   out_7186189398935518159[12] = 0;
   out_7186189398935518159[13] = 0;
   out_7186189398935518159[14] = 0;
   out_7186189398935518159[15] = 0;
   out_7186189398935518159[16] = 0;
   out_7186189398935518159[17] = 0;
   out_7186189398935518159[18] = 0;
   out_7186189398935518159[19] = 0;
   out_7186189398935518159[20] = 0;
   out_7186189398935518159[21] = 0;
   out_7186189398935518159[22] = 0;
   out_7186189398935518159[23] = 0;
   out_7186189398935518159[24] = 0;
   out_7186189398935518159[25] = 1;
   out_7186189398935518159[26] = 0;
   out_7186189398935518159[27] = 0;
   out_7186189398935518159[28] = 0;
   out_7186189398935518159[29] = 0;
   out_7186189398935518159[30] = 0;
   out_7186189398935518159[31] = 0;
   out_7186189398935518159[32] = 0;
   out_7186189398935518159[33] = 0;
   out_7186189398935518159[34] = 0;
   out_7186189398935518159[35] = 0;
   out_7186189398935518159[36] = 0;
   out_7186189398935518159[37] = 0;
   out_7186189398935518159[38] = 0;
   out_7186189398935518159[39] = 0;
   out_7186189398935518159[40] = 0;
   out_7186189398935518159[41] = 0;
   out_7186189398935518159[42] = 0;
   out_7186189398935518159[43] = 0;
   out_7186189398935518159[44] = 1;
   out_7186189398935518159[45] = 0;
   out_7186189398935518159[46] = 0;
   out_7186189398935518159[47] = 0;
   out_7186189398935518159[48] = 0;
   out_7186189398935518159[49] = 0;
   out_7186189398935518159[50] = 0;
   out_7186189398935518159[51] = 0;
   out_7186189398935518159[52] = 0;
   out_7186189398935518159[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_2987978520246878811) {
  err_fun(nom_x, delta_x, out_2987978520246878811);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7392740910229382527) {
  inv_err_fun(nom_x, true_x, out_7392740910229382527);
}
void pose_H_mod_fun(double *state, double *out_766595423579160181) {
  H_mod_fun(state, out_766595423579160181);
}
void pose_f_fun(double *state, double dt, double *out_422668654560890686) {
  f_fun(state,  dt, out_422668654560890686);
}
void pose_F_fun(double *state, double dt, double *out_2475263657764665516) {
  F_fun(state,  dt, out_2475263657764665516);
}
void pose_h_4(double *state, double *unused, double *out_1835432060314574929) {
  h_4(state, unused, out_1835432060314574929);
}
void pose_H_4(double *state, double *unused, double *out_8177766242478661161) {
  H_4(state, unused, out_8177766242478661161);
}
void pose_h_10(double *state, double *unused, double *out_4694595839556490884) {
  h_10(state, unused, out_4694595839556490884);
}
void pose_H_10(double *state, double *unused, double *out_5779971349689640500) {
  H_10(state, unused, out_5779971349689640500);
}
void pose_h_13(double *state, double *unused, double *out_4377602138518793981) {
  h_13(state, unused, out_4377602138518793981);
}
void pose_H_13(double *state, double *unused, double *out_4965492417146328360) {
  H_13(state, unused, out_4965492417146328360);
}
void pose_h_14(double *state, double *unused, double *out_1646321224287546567) {
  h_14(state, unused, out_1646321224287546567);
}
void pose_H_14(double *state, double *unused, double *out_7186189398935518159) {
  H_14(state, unused, out_7186189398935518159);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
