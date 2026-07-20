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
void err_fun(double *nom_x, double *delta_x, double *out_6331725736918116355) {
   out_6331725736918116355[0] = delta_x[0] + nom_x[0];
   out_6331725736918116355[1] = delta_x[1] + nom_x[1];
   out_6331725736918116355[2] = delta_x[2] + nom_x[2];
   out_6331725736918116355[3] = delta_x[3] + nom_x[3];
   out_6331725736918116355[4] = delta_x[4] + nom_x[4];
   out_6331725736918116355[5] = delta_x[5] + nom_x[5];
   out_6331725736918116355[6] = delta_x[6] + nom_x[6];
   out_6331725736918116355[7] = delta_x[7] + nom_x[7];
   out_6331725736918116355[8] = delta_x[8] + nom_x[8];
   out_6331725736918116355[9] = delta_x[9] + nom_x[9];
   out_6331725736918116355[10] = delta_x[10] + nom_x[10];
   out_6331725736918116355[11] = delta_x[11] + nom_x[11];
   out_6331725736918116355[12] = delta_x[12] + nom_x[12];
   out_6331725736918116355[13] = delta_x[13] + nom_x[13];
   out_6331725736918116355[14] = delta_x[14] + nom_x[14];
   out_6331725736918116355[15] = delta_x[15] + nom_x[15];
   out_6331725736918116355[16] = delta_x[16] + nom_x[16];
   out_6331725736918116355[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7346919451959455956) {
   out_7346919451959455956[0] = -nom_x[0] + true_x[0];
   out_7346919451959455956[1] = -nom_x[1] + true_x[1];
   out_7346919451959455956[2] = -nom_x[2] + true_x[2];
   out_7346919451959455956[3] = -nom_x[3] + true_x[3];
   out_7346919451959455956[4] = -nom_x[4] + true_x[4];
   out_7346919451959455956[5] = -nom_x[5] + true_x[5];
   out_7346919451959455956[6] = -nom_x[6] + true_x[6];
   out_7346919451959455956[7] = -nom_x[7] + true_x[7];
   out_7346919451959455956[8] = -nom_x[8] + true_x[8];
   out_7346919451959455956[9] = -nom_x[9] + true_x[9];
   out_7346919451959455956[10] = -nom_x[10] + true_x[10];
   out_7346919451959455956[11] = -nom_x[11] + true_x[11];
   out_7346919451959455956[12] = -nom_x[12] + true_x[12];
   out_7346919451959455956[13] = -nom_x[13] + true_x[13];
   out_7346919451959455956[14] = -nom_x[14] + true_x[14];
   out_7346919451959455956[15] = -nom_x[15] + true_x[15];
   out_7346919451959455956[16] = -nom_x[16] + true_x[16];
   out_7346919451959455956[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8304511961976193146) {
   out_8304511961976193146[0] = 1.0;
   out_8304511961976193146[1] = 0.0;
   out_8304511961976193146[2] = 0.0;
   out_8304511961976193146[3] = 0.0;
   out_8304511961976193146[4] = 0.0;
   out_8304511961976193146[5] = 0.0;
   out_8304511961976193146[6] = 0.0;
   out_8304511961976193146[7] = 0.0;
   out_8304511961976193146[8] = 0.0;
   out_8304511961976193146[9] = 0.0;
   out_8304511961976193146[10] = 0.0;
   out_8304511961976193146[11] = 0.0;
   out_8304511961976193146[12] = 0.0;
   out_8304511961976193146[13] = 0.0;
   out_8304511961976193146[14] = 0.0;
   out_8304511961976193146[15] = 0.0;
   out_8304511961976193146[16] = 0.0;
   out_8304511961976193146[17] = 0.0;
   out_8304511961976193146[18] = 0.0;
   out_8304511961976193146[19] = 1.0;
   out_8304511961976193146[20] = 0.0;
   out_8304511961976193146[21] = 0.0;
   out_8304511961976193146[22] = 0.0;
   out_8304511961976193146[23] = 0.0;
   out_8304511961976193146[24] = 0.0;
   out_8304511961976193146[25] = 0.0;
   out_8304511961976193146[26] = 0.0;
   out_8304511961976193146[27] = 0.0;
   out_8304511961976193146[28] = 0.0;
   out_8304511961976193146[29] = 0.0;
   out_8304511961976193146[30] = 0.0;
   out_8304511961976193146[31] = 0.0;
   out_8304511961976193146[32] = 0.0;
   out_8304511961976193146[33] = 0.0;
   out_8304511961976193146[34] = 0.0;
   out_8304511961976193146[35] = 0.0;
   out_8304511961976193146[36] = 0.0;
   out_8304511961976193146[37] = 0.0;
   out_8304511961976193146[38] = 1.0;
   out_8304511961976193146[39] = 0.0;
   out_8304511961976193146[40] = 0.0;
   out_8304511961976193146[41] = 0.0;
   out_8304511961976193146[42] = 0.0;
   out_8304511961976193146[43] = 0.0;
   out_8304511961976193146[44] = 0.0;
   out_8304511961976193146[45] = 0.0;
   out_8304511961976193146[46] = 0.0;
   out_8304511961976193146[47] = 0.0;
   out_8304511961976193146[48] = 0.0;
   out_8304511961976193146[49] = 0.0;
   out_8304511961976193146[50] = 0.0;
   out_8304511961976193146[51] = 0.0;
   out_8304511961976193146[52] = 0.0;
   out_8304511961976193146[53] = 0.0;
   out_8304511961976193146[54] = 0.0;
   out_8304511961976193146[55] = 0.0;
   out_8304511961976193146[56] = 0.0;
   out_8304511961976193146[57] = 1.0;
   out_8304511961976193146[58] = 0.0;
   out_8304511961976193146[59] = 0.0;
   out_8304511961976193146[60] = 0.0;
   out_8304511961976193146[61] = 0.0;
   out_8304511961976193146[62] = 0.0;
   out_8304511961976193146[63] = 0.0;
   out_8304511961976193146[64] = 0.0;
   out_8304511961976193146[65] = 0.0;
   out_8304511961976193146[66] = 0.0;
   out_8304511961976193146[67] = 0.0;
   out_8304511961976193146[68] = 0.0;
   out_8304511961976193146[69] = 0.0;
   out_8304511961976193146[70] = 0.0;
   out_8304511961976193146[71] = 0.0;
   out_8304511961976193146[72] = 0.0;
   out_8304511961976193146[73] = 0.0;
   out_8304511961976193146[74] = 0.0;
   out_8304511961976193146[75] = 0.0;
   out_8304511961976193146[76] = 1.0;
   out_8304511961976193146[77] = 0.0;
   out_8304511961976193146[78] = 0.0;
   out_8304511961976193146[79] = 0.0;
   out_8304511961976193146[80] = 0.0;
   out_8304511961976193146[81] = 0.0;
   out_8304511961976193146[82] = 0.0;
   out_8304511961976193146[83] = 0.0;
   out_8304511961976193146[84] = 0.0;
   out_8304511961976193146[85] = 0.0;
   out_8304511961976193146[86] = 0.0;
   out_8304511961976193146[87] = 0.0;
   out_8304511961976193146[88] = 0.0;
   out_8304511961976193146[89] = 0.0;
   out_8304511961976193146[90] = 0.0;
   out_8304511961976193146[91] = 0.0;
   out_8304511961976193146[92] = 0.0;
   out_8304511961976193146[93] = 0.0;
   out_8304511961976193146[94] = 0.0;
   out_8304511961976193146[95] = 1.0;
   out_8304511961976193146[96] = 0.0;
   out_8304511961976193146[97] = 0.0;
   out_8304511961976193146[98] = 0.0;
   out_8304511961976193146[99] = 0.0;
   out_8304511961976193146[100] = 0.0;
   out_8304511961976193146[101] = 0.0;
   out_8304511961976193146[102] = 0.0;
   out_8304511961976193146[103] = 0.0;
   out_8304511961976193146[104] = 0.0;
   out_8304511961976193146[105] = 0.0;
   out_8304511961976193146[106] = 0.0;
   out_8304511961976193146[107] = 0.0;
   out_8304511961976193146[108] = 0.0;
   out_8304511961976193146[109] = 0.0;
   out_8304511961976193146[110] = 0.0;
   out_8304511961976193146[111] = 0.0;
   out_8304511961976193146[112] = 0.0;
   out_8304511961976193146[113] = 0.0;
   out_8304511961976193146[114] = 1.0;
   out_8304511961976193146[115] = 0.0;
   out_8304511961976193146[116] = 0.0;
   out_8304511961976193146[117] = 0.0;
   out_8304511961976193146[118] = 0.0;
   out_8304511961976193146[119] = 0.0;
   out_8304511961976193146[120] = 0.0;
   out_8304511961976193146[121] = 0.0;
   out_8304511961976193146[122] = 0.0;
   out_8304511961976193146[123] = 0.0;
   out_8304511961976193146[124] = 0.0;
   out_8304511961976193146[125] = 0.0;
   out_8304511961976193146[126] = 0.0;
   out_8304511961976193146[127] = 0.0;
   out_8304511961976193146[128] = 0.0;
   out_8304511961976193146[129] = 0.0;
   out_8304511961976193146[130] = 0.0;
   out_8304511961976193146[131] = 0.0;
   out_8304511961976193146[132] = 0.0;
   out_8304511961976193146[133] = 1.0;
   out_8304511961976193146[134] = 0.0;
   out_8304511961976193146[135] = 0.0;
   out_8304511961976193146[136] = 0.0;
   out_8304511961976193146[137] = 0.0;
   out_8304511961976193146[138] = 0.0;
   out_8304511961976193146[139] = 0.0;
   out_8304511961976193146[140] = 0.0;
   out_8304511961976193146[141] = 0.0;
   out_8304511961976193146[142] = 0.0;
   out_8304511961976193146[143] = 0.0;
   out_8304511961976193146[144] = 0.0;
   out_8304511961976193146[145] = 0.0;
   out_8304511961976193146[146] = 0.0;
   out_8304511961976193146[147] = 0.0;
   out_8304511961976193146[148] = 0.0;
   out_8304511961976193146[149] = 0.0;
   out_8304511961976193146[150] = 0.0;
   out_8304511961976193146[151] = 0.0;
   out_8304511961976193146[152] = 1.0;
   out_8304511961976193146[153] = 0.0;
   out_8304511961976193146[154] = 0.0;
   out_8304511961976193146[155] = 0.0;
   out_8304511961976193146[156] = 0.0;
   out_8304511961976193146[157] = 0.0;
   out_8304511961976193146[158] = 0.0;
   out_8304511961976193146[159] = 0.0;
   out_8304511961976193146[160] = 0.0;
   out_8304511961976193146[161] = 0.0;
   out_8304511961976193146[162] = 0.0;
   out_8304511961976193146[163] = 0.0;
   out_8304511961976193146[164] = 0.0;
   out_8304511961976193146[165] = 0.0;
   out_8304511961976193146[166] = 0.0;
   out_8304511961976193146[167] = 0.0;
   out_8304511961976193146[168] = 0.0;
   out_8304511961976193146[169] = 0.0;
   out_8304511961976193146[170] = 0.0;
   out_8304511961976193146[171] = 1.0;
   out_8304511961976193146[172] = 0.0;
   out_8304511961976193146[173] = 0.0;
   out_8304511961976193146[174] = 0.0;
   out_8304511961976193146[175] = 0.0;
   out_8304511961976193146[176] = 0.0;
   out_8304511961976193146[177] = 0.0;
   out_8304511961976193146[178] = 0.0;
   out_8304511961976193146[179] = 0.0;
   out_8304511961976193146[180] = 0.0;
   out_8304511961976193146[181] = 0.0;
   out_8304511961976193146[182] = 0.0;
   out_8304511961976193146[183] = 0.0;
   out_8304511961976193146[184] = 0.0;
   out_8304511961976193146[185] = 0.0;
   out_8304511961976193146[186] = 0.0;
   out_8304511961976193146[187] = 0.0;
   out_8304511961976193146[188] = 0.0;
   out_8304511961976193146[189] = 0.0;
   out_8304511961976193146[190] = 1.0;
   out_8304511961976193146[191] = 0.0;
   out_8304511961976193146[192] = 0.0;
   out_8304511961976193146[193] = 0.0;
   out_8304511961976193146[194] = 0.0;
   out_8304511961976193146[195] = 0.0;
   out_8304511961976193146[196] = 0.0;
   out_8304511961976193146[197] = 0.0;
   out_8304511961976193146[198] = 0.0;
   out_8304511961976193146[199] = 0.0;
   out_8304511961976193146[200] = 0.0;
   out_8304511961976193146[201] = 0.0;
   out_8304511961976193146[202] = 0.0;
   out_8304511961976193146[203] = 0.0;
   out_8304511961976193146[204] = 0.0;
   out_8304511961976193146[205] = 0.0;
   out_8304511961976193146[206] = 0.0;
   out_8304511961976193146[207] = 0.0;
   out_8304511961976193146[208] = 0.0;
   out_8304511961976193146[209] = 1.0;
   out_8304511961976193146[210] = 0.0;
   out_8304511961976193146[211] = 0.0;
   out_8304511961976193146[212] = 0.0;
   out_8304511961976193146[213] = 0.0;
   out_8304511961976193146[214] = 0.0;
   out_8304511961976193146[215] = 0.0;
   out_8304511961976193146[216] = 0.0;
   out_8304511961976193146[217] = 0.0;
   out_8304511961976193146[218] = 0.0;
   out_8304511961976193146[219] = 0.0;
   out_8304511961976193146[220] = 0.0;
   out_8304511961976193146[221] = 0.0;
   out_8304511961976193146[222] = 0.0;
   out_8304511961976193146[223] = 0.0;
   out_8304511961976193146[224] = 0.0;
   out_8304511961976193146[225] = 0.0;
   out_8304511961976193146[226] = 0.0;
   out_8304511961976193146[227] = 0.0;
   out_8304511961976193146[228] = 1.0;
   out_8304511961976193146[229] = 0.0;
   out_8304511961976193146[230] = 0.0;
   out_8304511961976193146[231] = 0.0;
   out_8304511961976193146[232] = 0.0;
   out_8304511961976193146[233] = 0.0;
   out_8304511961976193146[234] = 0.0;
   out_8304511961976193146[235] = 0.0;
   out_8304511961976193146[236] = 0.0;
   out_8304511961976193146[237] = 0.0;
   out_8304511961976193146[238] = 0.0;
   out_8304511961976193146[239] = 0.0;
   out_8304511961976193146[240] = 0.0;
   out_8304511961976193146[241] = 0.0;
   out_8304511961976193146[242] = 0.0;
   out_8304511961976193146[243] = 0.0;
   out_8304511961976193146[244] = 0.0;
   out_8304511961976193146[245] = 0.0;
   out_8304511961976193146[246] = 0.0;
   out_8304511961976193146[247] = 1.0;
   out_8304511961976193146[248] = 0.0;
   out_8304511961976193146[249] = 0.0;
   out_8304511961976193146[250] = 0.0;
   out_8304511961976193146[251] = 0.0;
   out_8304511961976193146[252] = 0.0;
   out_8304511961976193146[253] = 0.0;
   out_8304511961976193146[254] = 0.0;
   out_8304511961976193146[255] = 0.0;
   out_8304511961976193146[256] = 0.0;
   out_8304511961976193146[257] = 0.0;
   out_8304511961976193146[258] = 0.0;
   out_8304511961976193146[259] = 0.0;
   out_8304511961976193146[260] = 0.0;
   out_8304511961976193146[261] = 0.0;
   out_8304511961976193146[262] = 0.0;
   out_8304511961976193146[263] = 0.0;
   out_8304511961976193146[264] = 0.0;
   out_8304511961976193146[265] = 0.0;
   out_8304511961976193146[266] = 1.0;
   out_8304511961976193146[267] = 0.0;
   out_8304511961976193146[268] = 0.0;
   out_8304511961976193146[269] = 0.0;
   out_8304511961976193146[270] = 0.0;
   out_8304511961976193146[271] = 0.0;
   out_8304511961976193146[272] = 0.0;
   out_8304511961976193146[273] = 0.0;
   out_8304511961976193146[274] = 0.0;
   out_8304511961976193146[275] = 0.0;
   out_8304511961976193146[276] = 0.0;
   out_8304511961976193146[277] = 0.0;
   out_8304511961976193146[278] = 0.0;
   out_8304511961976193146[279] = 0.0;
   out_8304511961976193146[280] = 0.0;
   out_8304511961976193146[281] = 0.0;
   out_8304511961976193146[282] = 0.0;
   out_8304511961976193146[283] = 0.0;
   out_8304511961976193146[284] = 0.0;
   out_8304511961976193146[285] = 1.0;
   out_8304511961976193146[286] = 0.0;
   out_8304511961976193146[287] = 0.0;
   out_8304511961976193146[288] = 0.0;
   out_8304511961976193146[289] = 0.0;
   out_8304511961976193146[290] = 0.0;
   out_8304511961976193146[291] = 0.0;
   out_8304511961976193146[292] = 0.0;
   out_8304511961976193146[293] = 0.0;
   out_8304511961976193146[294] = 0.0;
   out_8304511961976193146[295] = 0.0;
   out_8304511961976193146[296] = 0.0;
   out_8304511961976193146[297] = 0.0;
   out_8304511961976193146[298] = 0.0;
   out_8304511961976193146[299] = 0.0;
   out_8304511961976193146[300] = 0.0;
   out_8304511961976193146[301] = 0.0;
   out_8304511961976193146[302] = 0.0;
   out_8304511961976193146[303] = 0.0;
   out_8304511961976193146[304] = 1.0;
   out_8304511961976193146[305] = 0.0;
   out_8304511961976193146[306] = 0.0;
   out_8304511961976193146[307] = 0.0;
   out_8304511961976193146[308] = 0.0;
   out_8304511961976193146[309] = 0.0;
   out_8304511961976193146[310] = 0.0;
   out_8304511961976193146[311] = 0.0;
   out_8304511961976193146[312] = 0.0;
   out_8304511961976193146[313] = 0.0;
   out_8304511961976193146[314] = 0.0;
   out_8304511961976193146[315] = 0.0;
   out_8304511961976193146[316] = 0.0;
   out_8304511961976193146[317] = 0.0;
   out_8304511961976193146[318] = 0.0;
   out_8304511961976193146[319] = 0.0;
   out_8304511961976193146[320] = 0.0;
   out_8304511961976193146[321] = 0.0;
   out_8304511961976193146[322] = 0.0;
   out_8304511961976193146[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7307163557378829170) {
   out_7307163557378829170[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7307163557378829170[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7307163557378829170[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7307163557378829170[3] = dt*state[12] + state[3];
   out_7307163557378829170[4] = dt*state[13] + state[4];
   out_7307163557378829170[5] = dt*state[14] + state[5];
   out_7307163557378829170[6] = state[6];
   out_7307163557378829170[7] = state[7];
   out_7307163557378829170[8] = state[8];
   out_7307163557378829170[9] = state[9];
   out_7307163557378829170[10] = state[10];
   out_7307163557378829170[11] = state[11];
   out_7307163557378829170[12] = state[12];
   out_7307163557378829170[13] = state[13];
   out_7307163557378829170[14] = state[14];
   out_7307163557378829170[15] = state[15];
   out_7307163557378829170[16] = state[16];
   out_7307163557378829170[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4516770154061261607) {
   out_4516770154061261607[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4516770154061261607[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4516770154061261607[2] = 0;
   out_4516770154061261607[3] = 0;
   out_4516770154061261607[4] = 0;
   out_4516770154061261607[5] = 0;
   out_4516770154061261607[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4516770154061261607[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4516770154061261607[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4516770154061261607[9] = 0;
   out_4516770154061261607[10] = 0;
   out_4516770154061261607[11] = 0;
   out_4516770154061261607[12] = 0;
   out_4516770154061261607[13] = 0;
   out_4516770154061261607[14] = 0;
   out_4516770154061261607[15] = 0;
   out_4516770154061261607[16] = 0;
   out_4516770154061261607[17] = 0;
   out_4516770154061261607[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4516770154061261607[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4516770154061261607[20] = 0;
   out_4516770154061261607[21] = 0;
   out_4516770154061261607[22] = 0;
   out_4516770154061261607[23] = 0;
   out_4516770154061261607[24] = 0;
   out_4516770154061261607[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4516770154061261607[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4516770154061261607[27] = 0;
   out_4516770154061261607[28] = 0;
   out_4516770154061261607[29] = 0;
   out_4516770154061261607[30] = 0;
   out_4516770154061261607[31] = 0;
   out_4516770154061261607[32] = 0;
   out_4516770154061261607[33] = 0;
   out_4516770154061261607[34] = 0;
   out_4516770154061261607[35] = 0;
   out_4516770154061261607[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4516770154061261607[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4516770154061261607[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4516770154061261607[39] = 0;
   out_4516770154061261607[40] = 0;
   out_4516770154061261607[41] = 0;
   out_4516770154061261607[42] = 0;
   out_4516770154061261607[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4516770154061261607[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4516770154061261607[45] = 0;
   out_4516770154061261607[46] = 0;
   out_4516770154061261607[47] = 0;
   out_4516770154061261607[48] = 0;
   out_4516770154061261607[49] = 0;
   out_4516770154061261607[50] = 0;
   out_4516770154061261607[51] = 0;
   out_4516770154061261607[52] = 0;
   out_4516770154061261607[53] = 0;
   out_4516770154061261607[54] = 0;
   out_4516770154061261607[55] = 0;
   out_4516770154061261607[56] = 0;
   out_4516770154061261607[57] = 1;
   out_4516770154061261607[58] = 0;
   out_4516770154061261607[59] = 0;
   out_4516770154061261607[60] = 0;
   out_4516770154061261607[61] = 0;
   out_4516770154061261607[62] = 0;
   out_4516770154061261607[63] = 0;
   out_4516770154061261607[64] = 0;
   out_4516770154061261607[65] = 0;
   out_4516770154061261607[66] = dt;
   out_4516770154061261607[67] = 0;
   out_4516770154061261607[68] = 0;
   out_4516770154061261607[69] = 0;
   out_4516770154061261607[70] = 0;
   out_4516770154061261607[71] = 0;
   out_4516770154061261607[72] = 0;
   out_4516770154061261607[73] = 0;
   out_4516770154061261607[74] = 0;
   out_4516770154061261607[75] = 0;
   out_4516770154061261607[76] = 1;
   out_4516770154061261607[77] = 0;
   out_4516770154061261607[78] = 0;
   out_4516770154061261607[79] = 0;
   out_4516770154061261607[80] = 0;
   out_4516770154061261607[81] = 0;
   out_4516770154061261607[82] = 0;
   out_4516770154061261607[83] = 0;
   out_4516770154061261607[84] = 0;
   out_4516770154061261607[85] = dt;
   out_4516770154061261607[86] = 0;
   out_4516770154061261607[87] = 0;
   out_4516770154061261607[88] = 0;
   out_4516770154061261607[89] = 0;
   out_4516770154061261607[90] = 0;
   out_4516770154061261607[91] = 0;
   out_4516770154061261607[92] = 0;
   out_4516770154061261607[93] = 0;
   out_4516770154061261607[94] = 0;
   out_4516770154061261607[95] = 1;
   out_4516770154061261607[96] = 0;
   out_4516770154061261607[97] = 0;
   out_4516770154061261607[98] = 0;
   out_4516770154061261607[99] = 0;
   out_4516770154061261607[100] = 0;
   out_4516770154061261607[101] = 0;
   out_4516770154061261607[102] = 0;
   out_4516770154061261607[103] = 0;
   out_4516770154061261607[104] = dt;
   out_4516770154061261607[105] = 0;
   out_4516770154061261607[106] = 0;
   out_4516770154061261607[107] = 0;
   out_4516770154061261607[108] = 0;
   out_4516770154061261607[109] = 0;
   out_4516770154061261607[110] = 0;
   out_4516770154061261607[111] = 0;
   out_4516770154061261607[112] = 0;
   out_4516770154061261607[113] = 0;
   out_4516770154061261607[114] = 1;
   out_4516770154061261607[115] = 0;
   out_4516770154061261607[116] = 0;
   out_4516770154061261607[117] = 0;
   out_4516770154061261607[118] = 0;
   out_4516770154061261607[119] = 0;
   out_4516770154061261607[120] = 0;
   out_4516770154061261607[121] = 0;
   out_4516770154061261607[122] = 0;
   out_4516770154061261607[123] = 0;
   out_4516770154061261607[124] = 0;
   out_4516770154061261607[125] = 0;
   out_4516770154061261607[126] = 0;
   out_4516770154061261607[127] = 0;
   out_4516770154061261607[128] = 0;
   out_4516770154061261607[129] = 0;
   out_4516770154061261607[130] = 0;
   out_4516770154061261607[131] = 0;
   out_4516770154061261607[132] = 0;
   out_4516770154061261607[133] = 1;
   out_4516770154061261607[134] = 0;
   out_4516770154061261607[135] = 0;
   out_4516770154061261607[136] = 0;
   out_4516770154061261607[137] = 0;
   out_4516770154061261607[138] = 0;
   out_4516770154061261607[139] = 0;
   out_4516770154061261607[140] = 0;
   out_4516770154061261607[141] = 0;
   out_4516770154061261607[142] = 0;
   out_4516770154061261607[143] = 0;
   out_4516770154061261607[144] = 0;
   out_4516770154061261607[145] = 0;
   out_4516770154061261607[146] = 0;
   out_4516770154061261607[147] = 0;
   out_4516770154061261607[148] = 0;
   out_4516770154061261607[149] = 0;
   out_4516770154061261607[150] = 0;
   out_4516770154061261607[151] = 0;
   out_4516770154061261607[152] = 1;
   out_4516770154061261607[153] = 0;
   out_4516770154061261607[154] = 0;
   out_4516770154061261607[155] = 0;
   out_4516770154061261607[156] = 0;
   out_4516770154061261607[157] = 0;
   out_4516770154061261607[158] = 0;
   out_4516770154061261607[159] = 0;
   out_4516770154061261607[160] = 0;
   out_4516770154061261607[161] = 0;
   out_4516770154061261607[162] = 0;
   out_4516770154061261607[163] = 0;
   out_4516770154061261607[164] = 0;
   out_4516770154061261607[165] = 0;
   out_4516770154061261607[166] = 0;
   out_4516770154061261607[167] = 0;
   out_4516770154061261607[168] = 0;
   out_4516770154061261607[169] = 0;
   out_4516770154061261607[170] = 0;
   out_4516770154061261607[171] = 1;
   out_4516770154061261607[172] = 0;
   out_4516770154061261607[173] = 0;
   out_4516770154061261607[174] = 0;
   out_4516770154061261607[175] = 0;
   out_4516770154061261607[176] = 0;
   out_4516770154061261607[177] = 0;
   out_4516770154061261607[178] = 0;
   out_4516770154061261607[179] = 0;
   out_4516770154061261607[180] = 0;
   out_4516770154061261607[181] = 0;
   out_4516770154061261607[182] = 0;
   out_4516770154061261607[183] = 0;
   out_4516770154061261607[184] = 0;
   out_4516770154061261607[185] = 0;
   out_4516770154061261607[186] = 0;
   out_4516770154061261607[187] = 0;
   out_4516770154061261607[188] = 0;
   out_4516770154061261607[189] = 0;
   out_4516770154061261607[190] = 1;
   out_4516770154061261607[191] = 0;
   out_4516770154061261607[192] = 0;
   out_4516770154061261607[193] = 0;
   out_4516770154061261607[194] = 0;
   out_4516770154061261607[195] = 0;
   out_4516770154061261607[196] = 0;
   out_4516770154061261607[197] = 0;
   out_4516770154061261607[198] = 0;
   out_4516770154061261607[199] = 0;
   out_4516770154061261607[200] = 0;
   out_4516770154061261607[201] = 0;
   out_4516770154061261607[202] = 0;
   out_4516770154061261607[203] = 0;
   out_4516770154061261607[204] = 0;
   out_4516770154061261607[205] = 0;
   out_4516770154061261607[206] = 0;
   out_4516770154061261607[207] = 0;
   out_4516770154061261607[208] = 0;
   out_4516770154061261607[209] = 1;
   out_4516770154061261607[210] = 0;
   out_4516770154061261607[211] = 0;
   out_4516770154061261607[212] = 0;
   out_4516770154061261607[213] = 0;
   out_4516770154061261607[214] = 0;
   out_4516770154061261607[215] = 0;
   out_4516770154061261607[216] = 0;
   out_4516770154061261607[217] = 0;
   out_4516770154061261607[218] = 0;
   out_4516770154061261607[219] = 0;
   out_4516770154061261607[220] = 0;
   out_4516770154061261607[221] = 0;
   out_4516770154061261607[222] = 0;
   out_4516770154061261607[223] = 0;
   out_4516770154061261607[224] = 0;
   out_4516770154061261607[225] = 0;
   out_4516770154061261607[226] = 0;
   out_4516770154061261607[227] = 0;
   out_4516770154061261607[228] = 1;
   out_4516770154061261607[229] = 0;
   out_4516770154061261607[230] = 0;
   out_4516770154061261607[231] = 0;
   out_4516770154061261607[232] = 0;
   out_4516770154061261607[233] = 0;
   out_4516770154061261607[234] = 0;
   out_4516770154061261607[235] = 0;
   out_4516770154061261607[236] = 0;
   out_4516770154061261607[237] = 0;
   out_4516770154061261607[238] = 0;
   out_4516770154061261607[239] = 0;
   out_4516770154061261607[240] = 0;
   out_4516770154061261607[241] = 0;
   out_4516770154061261607[242] = 0;
   out_4516770154061261607[243] = 0;
   out_4516770154061261607[244] = 0;
   out_4516770154061261607[245] = 0;
   out_4516770154061261607[246] = 0;
   out_4516770154061261607[247] = 1;
   out_4516770154061261607[248] = 0;
   out_4516770154061261607[249] = 0;
   out_4516770154061261607[250] = 0;
   out_4516770154061261607[251] = 0;
   out_4516770154061261607[252] = 0;
   out_4516770154061261607[253] = 0;
   out_4516770154061261607[254] = 0;
   out_4516770154061261607[255] = 0;
   out_4516770154061261607[256] = 0;
   out_4516770154061261607[257] = 0;
   out_4516770154061261607[258] = 0;
   out_4516770154061261607[259] = 0;
   out_4516770154061261607[260] = 0;
   out_4516770154061261607[261] = 0;
   out_4516770154061261607[262] = 0;
   out_4516770154061261607[263] = 0;
   out_4516770154061261607[264] = 0;
   out_4516770154061261607[265] = 0;
   out_4516770154061261607[266] = 1;
   out_4516770154061261607[267] = 0;
   out_4516770154061261607[268] = 0;
   out_4516770154061261607[269] = 0;
   out_4516770154061261607[270] = 0;
   out_4516770154061261607[271] = 0;
   out_4516770154061261607[272] = 0;
   out_4516770154061261607[273] = 0;
   out_4516770154061261607[274] = 0;
   out_4516770154061261607[275] = 0;
   out_4516770154061261607[276] = 0;
   out_4516770154061261607[277] = 0;
   out_4516770154061261607[278] = 0;
   out_4516770154061261607[279] = 0;
   out_4516770154061261607[280] = 0;
   out_4516770154061261607[281] = 0;
   out_4516770154061261607[282] = 0;
   out_4516770154061261607[283] = 0;
   out_4516770154061261607[284] = 0;
   out_4516770154061261607[285] = 1;
   out_4516770154061261607[286] = 0;
   out_4516770154061261607[287] = 0;
   out_4516770154061261607[288] = 0;
   out_4516770154061261607[289] = 0;
   out_4516770154061261607[290] = 0;
   out_4516770154061261607[291] = 0;
   out_4516770154061261607[292] = 0;
   out_4516770154061261607[293] = 0;
   out_4516770154061261607[294] = 0;
   out_4516770154061261607[295] = 0;
   out_4516770154061261607[296] = 0;
   out_4516770154061261607[297] = 0;
   out_4516770154061261607[298] = 0;
   out_4516770154061261607[299] = 0;
   out_4516770154061261607[300] = 0;
   out_4516770154061261607[301] = 0;
   out_4516770154061261607[302] = 0;
   out_4516770154061261607[303] = 0;
   out_4516770154061261607[304] = 1;
   out_4516770154061261607[305] = 0;
   out_4516770154061261607[306] = 0;
   out_4516770154061261607[307] = 0;
   out_4516770154061261607[308] = 0;
   out_4516770154061261607[309] = 0;
   out_4516770154061261607[310] = 0;
   out_4516770154061261607[311] = 0;
   out_4516770154061261607[312] = 0;
   out_4516770154061261607[313] = 0;
   out_4516770154061261607[314] = 0;
   out_4516770154061261607[315] = 0;
   out_4516770154061261607[316] = 0;
   out_4516770154061261607[317] = 0;
   out_4516770154061261607[318] = 0;
   out_4516770154061261607[319] = 0;
   out_4516770154061261607[320] = 0;
   out_4516770154061261607[321] = 0;
   out_4516770154061261607[322] = 0;
   out_4516770154061261607[323] = 1;
}
void h_4(double *state, double *unused, double *out_4815477108189616395) {
   out_4815477108189616395[0] = state[6] + state[9];
   out_4815477108189616395[1] = state[7] + state[10];
   out_4815477108189616395[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_1404035879650369332) {
   out_1404035879650369332[0] = 0;
   out_1404035879650369332[1] = 0;
   out_1404035879650369332[2] = 0;
   out_1404035879650369332[3] = 0;
   out_1404035879650369332[4] = 0;
   out_1404035879650369332[5] = 0;
   out_1404035879650369332[6] = 1;
   out_1404035879650369332[7] = 0;
   out_1404035879650369332[8] = 0;
   out_1404035879650369332[9] = 1;
   out_1404035879650369332[10] = 0;
   out_1404035879650369332[11] = 0;
   out_1404035879650369332[12] = 0;
   out_1404035879650369332[13] = 0;
   out_1404035879650369332[14] = 0;
   out_1404035879650369332[15] = 0;
   out_1404035879650369332[16] = 0;
   out_1404035879650369332[17] = 0;
   out_1404035879650369332[18] = 0;
   out_1404035879650369332[19] = 0;
   out_1404035879650369332[20] = 0;
   out_1404035879650369332[21] = 0;
   out_1404035879650369332[22] = 0;
   out_1404035879650369332[23] = 0;
   out_1404035879650369332[24] = 0;
   out_1404035879650369332[25] = 1;
   out_1404035879650369332[26] = 0;
   out_1404035879650369332[27] = 0;
   out_1404035879650369332[28] = 1;
   out_1404035879650369332[29] = 0;
   out_1404035879650369332[30] = 0;
   out_1404035879650369332[31] = 0;
   out_1404035879650369332[32] = 0;
   out_1404035879650369332[33] = 0;
   out_1404035879650369332[34] = 0;
   out_1404035879650369332[35] = 0;
   out_1404035879650369332[36] = 0;
   out_1404035879650369332[37] = 0;
   out_1404035879650369332[38] = 0;
   out_1404035879650369332[39] = 0;
   out_1404035879650369332[40] = 0;
   out_1404035879650369332[41] = 0;
   out_1404035879650369332[42] = 0;
   out_1404035879650369332[43] = 0;
   out_1404035879650369332[44] = 1;
   out_1404035879650369332[45] = 0;
   out_1404035879650369332[46] = 0;
   out_1404035879650369332[47] = 1;
   out_1404035879650369332[48] = 0;
   out_1404035879650369332[49] = 0;
   out_1404035879650369332[50] = 0;
   out_1404035879650369332[51] = 0;
   out_1404035879650369332[52] = 0;
   out_1404035879650369332[53] = 0;
}
void h_10(double *state, double *unused, double *out_827736089587648090) {
   out_827736089587648090[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_827736089587648090[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_827736089587648090[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2817413118959448550) {
   out_2817413118959448550[0] = 0;
   out_2817413118959448550[1] = 9.8100000000000005*cos(state[1]);
   out_2817413118959448550[2] = 0;
   out_2817413118959448550[3] = 0;
   out_2817413118959448550[4] = -state[8];
   out_2817413118959448550[5] = state[7];
   out_2817413118959448550[6] = 0;
   out_2817413118959448550[7] = state[5];
   out_2817413118959448550[8] = -state[4];
   out_2817413118959448550[9] = 0;
   out_2817413118959448550[10] = 0;
   out_2817413118959448550[11] = 0;
   out_2817413118959448550[12] = 1;
   out_2817413118959448550[13] = 0;
   out_2817413118959448550[14] = 0;
   out_2817413118959448550[15] = 1;
   out_2817413118959448550[16] = 0;
   out_2817413118959448550[17] = 0;
   out_2817413118959448550[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2817413118959448550[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2817413118959448550[20] = 0;
   out_2817413118959448550[21] = state[8];
   out_2817413118959448550[22] = 0;
   out_2817413118959448550[23] = -state[6];
   out_2817413118959448550[24] = -state[5];
   out_2817413118959448550[25] = 0;
   out_2817413118959448550[26] = state[3];
   out_2817413118959448550[27] = 0;
   out_2817413118959448550[28] = 0;
   out_2817413118959448550[29] = 0;
   out_2817413118959448550[30] = 0;
   out_2817413118959448550[31] = 1;
   out_2817413118959448550[32] = 0;
   out_2817413118959448550[33] = 0;
   out_2817413118959448550[34] = 1;
   out_2817413118959448550[35] = 0;
   out_2817413118959448550[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2817413118959448550[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2817413118959448550[38] = 0;
   out_2817413118959448550[39] = -state[7];
   out_2817413118959448550[40] = state[6];
   out_2817413118959448550[41] = 0;
   out_2817413118959448550[42] = state[4];
   out_2817413118959448550[43] = -state[3];
   out_2817413118959448550[44] = 0;
   out_2817413118959448550[45] = 0;
   out_2817413118959448550[46] = 0;
   out_2817413118959448550[47] = 0;
   out_2817413118959448550[48] = 0;
   out_2817413118959448550[49] = 0;
   out_2817413118959448550[50] = 1;
   out_2817413118959448550[51] = 0;
   out_2817413118959448550[52] = 0;
   out_2817413118959448550[53] = 1;
}
void h_13(double *state, double *unused, double *out_8331916060804991687) {
   out_8331916060804991687[0] = state[3];
   out_8331916060804991687[1] = state[4];
   out_8331916060804991687[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6206595328666331597) {
   out_6206595328666331597[0] = 0;
   out_6206595328666331597[1] = 0;
   out_6206595328666331597[2] = 0;
   out_6206595328666331597[3] = 1;
   out_6206595328666331597[4] = 0;
   out_6206595328666331597[5] = 0;
   out_6206595328666331597[6] = 0;
   out_6206595328666331597[7] = 0;
   out_6206595328666331597[8] = 0;
   out_6206595328666331597[9] = 0;
   out_6206595328666331597[10] = 0;
   out_6206595328666331597[11] = 0;
   out_6206595328666331597[12] = 0;
   out_6206595328666331597[13] = 0;
   out_6206595328666331597[14] = 0;
   out_6206595328666331597[15] = 0;
   out_6206595328666331597[16] = 0;
   out_6206595328666331597[17] = 0;
   out_6206595328666331597[18] = 0;
   out_6206595328666331597[19] = 0;
   out_6206595328666331597[20] = 0;
   out_6206595328666331597[21] = 0;
   out_6206595328666331597[22] = 1;
   out_6206595328666331597[23] = 0;
   out_6206595328666331597[24] = 0;
   out_6206595328666331597[25] = 0;
   out_6206595328666331597[26] = 0;
   out_6206595328666331597[27] = 0;
   out_6206595328666331597[28] = 0;
   out_6206595328666331597[29] = 0;
   out_6206595328666331597[30] = 0;
   out_6206595328666331597[31] = 0;
   out_6206595328666331597[32] = 0;
   out_6206595328666331597[33] = 0;
   out_6206595328666331597[34] = 0;
   out_6206595328666331597[35] = 0;
   out_6206595328666331597[36] = 0;
   out_6206595328666331597[37] = 0;
   out_6206595328666331597[38] = 0;
   out_6206595328666331597[39] = 0;
   out_6206595328666331597[40] = 0;
   out_6206595328666331597[41] = 1;
   out_6206595328666331597[42] = 0;
   out_6206595328666331597[43] = 0;
   out_6206595328666331597[44] = 0;
   out_6206595328666331597[45] = 0;
   out_6206595328666331597[46] = 0;
   out_6206595328666331597[47] = 0;
   out_6206595328666331597[48] = 0;
   out_6206595328666331597[49] = 0;
   out_6206595328666331597[50] = 0;
   out_6206595328666331597[51] = 0;
   out_6206595328666331597[52] = 0;
   out_6206595328666331597[53] = 0;
}
void h_14(double *state, double *unused, double *out_4595084300967204941) {
   out_4595084300967204941[0] = state[6];
   out_4595084300967204941[1] = state[7];
   out_4595084300967204941[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4486824311945741628) {
   out_4486824311945741628[0] = 0;
   out_4486824311945741628[1] = 0;
   out_4486824311945741628[2] = 0;
   out_4486824311945741628[3] = 0;
   out_4486824311945741628[4] = 0;
   out_4486824311945741628[5] = 0;
   out_4486824311945741628[6] = 1;
   out_4486824311945741628[7] = 0;
   out_4486824311945741628[8] = 0;
   out_4486824311945741628[9] = 0;
   out_4486824311945741628[10] = 0;
   out_4486824311945741628[11] = 0;
   out_4486824311945741628[12] = 0;
   out_4486824311945741628[13] = 0;
   out_4486824311945741628[14] = 0;
   out_4486824311945741628[15] = 0;
   out_4486824311945741628[16] = 0;
   out_4486824311945741628[17] = 0;
   out_4486824311945741628[18] = 0;
   out_4486824311945741628[19] = 0;
   out_4486824311945741628[20] = 0;
   out_4486824311945741628[21] = 0;
   out_4486824311945741628[22] = 0;
   out_4486824311945741628[23] = 0;
   out_4486824311945741628[24] = 0;
   out_4486824311945741628[25] = 1;
   out_4486824311945741628[26] = 0;
   out_4486824311945741628[27] = 0;
   out_4486824311945741628[28] = 0;
   out_4486824311945741628[29] = 0;
   out_4486824311945741628[30] = 0;
   out_4486824311945741628[31] = 0;
   out_4486824311945741628[32] = 0;
   out_4486824311945741628[33] = 0;
   out_4486824311945741628[34] = 0;
   out_4486824311945741628[35] = 0;
   out_4486824311945741628[36] = 0;
   out_4486824311945741628[37] = 0;
   out_4486824311945741628[38] = 0;
   out_4486824311945741628[39] = 0;
   out_4486824311945741628[40] = 0;
   out_4486824311945741628[41] = 0;
   out_4486824311945741628[42] = 0;
   out_4486824311945741628[43] = 0;
   out_4486824311945741628[44] = 1;
   out_4486824311945741628[45] = 0;
   out_4486824311945741628[46] = 0;
   out_4486824311945741628[47] = 0;
   out_4486824311945741628[48] = 0;
   out_4486824311945741628[49] = 0;
   out_4486824311945741628[50] = 0;
   out_4486824311945741628[51] = 0;
   out_4486824311945741628[52] = 0;
   out_4486824311945741628[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_6331725736918116355) {
  err_fun(nom_x, delta_x, out_6331725736918116355);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7346919451959455956) {
  inv_err_fun(nom_x, true_x, out_7346919451959455956);
}
void pose_H_mod_fun(double *state, double *out_8304511961976193146) {
  H_mod_fun(state, out_8304511961976193146);
}
void pose_f_fun(double *state, double dt, double *out_7307163557378829170) {
  f_fun(state,  dt, out_7307163557378829170);
}
void pose_F_fun(double *state, double dt, double *out_4516770154061261607) {
  F_fun(state,  dt, out_4516770154061261607);
}
void pose_h_4(double *state, double *unused, double *out_4815477108189616395) {
  h_4(state, unused, out_4815477108189616395);
}
void pose_H_4(double *state, double *unused, double *out_1404035879650369332) {
  H_4(state, unused, out_1404035879650369332);
}
void pose_h_10(double *state, double *unused, double *out_827736089587648090) {
  h_10(state, unused, out_827736089587648090);
}
void pose_H_10(double *state, double *unused, double *out_2817413118959448550) {
  H_10(state, unused, out_2817413118959448550);
}
void pose_h_13(double *state, double *unused, double *out_8331916060804991687) {
  h_13(state, unused, out_8331916060804991687);
}
void pose_H_13(double *state, double *unused, double *out_6206595328666331597) {
  H_13(state, unused, out_6206595328666331597);
}
void pose_h_14(double *state, double *unused, double *out_4595084300967204941) {
  h_14(state, unused, out_4595084300967204941);
}
void pose_H_14(double *state, double *unused, double *out_4486824311945741628) {
  H_14(state, unused, out_4486824311945741628);
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
