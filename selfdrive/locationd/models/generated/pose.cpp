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
void err_fun(double *nom_x, double *delta_x, double *out_5195610458540139902) {
   out_5195610458540139902[0] = delta_x[0] + nom_x[0];
   out_5195610458540139902[1] = delta_x[1] + nom_x[1];
   out_5195610458540139902[2] = delta_x[2] + nom_x[2];
   out_5195610458540139902[3] = delta_x[3] + nom_x[3];
   out_5195610458540139902[4] = delta_x[4] + nom_x[4];
   out_5195610458540139902[5] = delta_x[5] + nom_x[5];
   out_5195610458540139902[6] = delta_x[6] + nom_x[6];
   out_5195610458540139902[7] = delta_x[7] + nom_x[7];
   out_5195610458540139902[8] = delta_x[8] + nom_x[8];
   out_5195610458540139902[9] = delta_x[9] + nom_x[9];
   out_5195610458540139902[10] = delta_x[10] + nom_x[10];
   out_5195610458540139902[11] = delta_x[11] + nom_x[11];
   out_5195610458540139902[12] = delta_x[12] + nom_x[12];
   out_5195610458540139902[13] = delta_x[13] + nom_x[13];
   out_5195610458540139902[14] = delta_x[14] + nom_x[14];
   out_5195610458540139902[15] = delta_x[15] + nom_x[15];
   out_5195610458540139902[16] = delta_x[16] + nom_x[16];
   out_5195610458540139902[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7314439786479166241) {
   out_7314439786479166241[0] = -nom_x[0] + true_x[0];
   out_7314439786479166241[1] = -nom_x[1] + true_x[1];
   out_7314439786479166241[2] = -nom_x[2] + true_x[2];
   out_7314439786479166241[3] = -nom_x[3] + true_x[3];
   out_7314439786479166241[4] = -nom_x[4] + true_x[4];
   out_7314439786479166241[5] = -nom_x[5] + true_x[5];
   out_7314439786479166241[6] = -nom_x[6] + true_x[6];
   out_7314439786479166241[7] = -nom_x[7] + true_x[7];
   out_7314439786479166241[8] = -nom_x[8] + true_x[8];
   out_7314439786479166241[9] = -nom_x[9] + true_x[9];
   out_7314439786479166241[10] = -nom_x[10] + true_x[10];
   out_7314439786479166241[11] = -nom_x[11] + true_x[11];
   out_7314439786479166241[12] = -nom_x[12] + true_x[12];
   out_7314439786479166241[13] = -nom_x[13] + true_x[13];
   out_7314439786479166241[14] = -nom_x[14] + true_x[14];
   out_7314439786479166241[15] = -nom_x[15] + true_x[15];
   out_7314439786479166241[16] = -nom_x[16] + true_x[16];
   out_7314439786479166241[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8818080346799948532) {
   out_8818080346799948532[0] = 1.0;
   out_8818080346799948532[1] = 0.0;
   out_8818080346799948532[2] = 0.0;
   out_8818080346799948532[3] = 0.0;
   out_8818080346799948532[4] = 0.0;
   out_8818080346799948532[5] = 0.0;
   out_8818080346799948532[6] = 0.0;
   out_8818080346799948532[7] = 0.0;
   out_8818080346799948532[8] = 0.0;
   out_8818080346799948532[9] = 0.0;
   out_8818080346799948532[10] = 0.0;
   out_8818080346799948532[11] = 0.0;
   out_8818080346799948532[12] = 0.0;
   out_8818080346799948532[13] = 0.0;
   out_8818080346799948532[14] = 0.0;
   out_8818080346799948532[15] = 0.0;
   out_8818080346799948532[16] = 0.0;
   out_8818080346799948532[17] = 0.0;
   out_8818080346799948532[18] = 0.0;
   out_8818080346799948532[19] = 1.0;
   out_8818080346799948532[20] = 0.0;
   out_8818080346799948532[21] = 0.0;
   out_8818080346799948532[22] = 0.0;
   out_8818080346799948532[23] = 0.0;
   out_8818080346799948532[24] = 0.0;
   out_8818080346799948532[25] = 0.0;
   out_8818080346799948532[26] = 0.0;
   out_8818080346799948532[27] = 0.0;
   out_8818080346799948532[28] = 0.0;
   out_8818080346799948532[29] = 0.0;
   out_8818080346799948532[30] = 0.0;
   out_8818080346799948532[31] = 0.0;
   out_8818080346799948532[32] = 0.0;
   out_8818080346799948532[33] = 0.0;
   out_8818080346799948532[34] = 0.0;
   out_8818080346799948532[35] = 0.0;
   out_8818080346799948532[36] = 0.0;
   out_8818080346799948532[37] = 0.0;
   out_8818080346799948532[38] = 1.0;
   out_8818080346799948532[39] = 0.0;
   out_8818080346799948532[40] = 0.0;
   out_8818080346799948532[41] = 0.0;
   out_8818080346799948532[42] = 0.0;
   out_8818080346799948532[43] = 0.0;
   out_8818080346799948532[44] = 0.0;
   out_8818080346799948532[45] = 0.0;
   out_8818080346799948532[46] = 0.0;
   out_8818080346799948532[47] = 0.0;
   out_8818080346799948532[48] = 0.0;
   out_8818080346799948532[49] = 0.0;
   out_8818080346799948532[50] = 0.0;
   out_8818080346799948532[51] = 0.0;
   out_8818080346799948532[52] = 0.0;
   out_8818080346799948532[53] = 0.0;
   out_8818080346799948532[54] = 0.0;
   out_8818080346799948532[55] = 0.0;
   out_8818080346799948532[56] = 0.0;
   out_8818080346799948532[57] = 1.0;
   out_8818080346799948532[58] = 0.0;
   out_8818080346799948532[59] = 0.0;
   out_8818080346799948532[60] = 0.0;
   out_8818080346799948532[61] = 0.0;
   out_8818080346799948532[62] = 0.0;
   out_8818080346799948532[63] = 0.0;
   out_8818080346799948532[64] = 0.0;
   out_8818080346799948532[65] = 0.0;
   out_8818080346799948532[66] = 0.0;
   out_8818080346799948532[67] = 0.0;
   out_8818080346799948532[68] = 0.0;
   out_8818080346799948532[69] = 0.0;
   out_8818080346799948532[70] = 0.0;
   out_8818080346799948532[71] = 0.0;
   out_8818080346799948532[72] = 0.0;
   out_8818080346799948532[73] = 0.0;
   out_8818080346799948532[74] = 0.0;
   out_8818080346799948532[75] = 0.0;
   out_8818080346799948532[76] = 1.0;
   out_8818080346799948532[77] = 0.0;
   out_8818080346799948532[78] = 0.0;
   out_8818080346799948532[79] = 0.0;
   out_8818080346799948532[80] = 0.0;
   out_8818080346799948532[81] = 0.0;
   out_8818080346799948532[82] = 0.0;
   out_8818080346799948532[83] = 0.0;
   out_8818080346799948532[84] = 0.0;
   out_8818080346799948532[85] = 0.0;
   out_8818080346799948532[86] = 0.0;
   out_8818080346799948532[87] = 0.0;
   out_8818080346799948532[88] = 0.0;
   out_8818080346799948532[89] = 0.0;
   out_8818080346799948532[90] = 0.0;
   out_8818080346799948532[91] = 0.0;
   out_8818080346799948532[92] = 0.0;
   out_8818080346799948532[93] = 0.0;
   out_8818080346799948532[94] = 0.0;
   out_8818080346799948532[95] = 1.0;
   out_8818080346799948532[96] = 0.0;
   out_8818080346799948532[97] = 0.0;
   out_8818080346799948532[98] = 0.0;
   out_8818080346799948532[99] = 0.0;
   out_8818080346799948532[100] = 0.0;
   out_8818080346799948532[101] = 0.0;
   out_8818080346799948532[102] = 0.0;
   out_8818080346799948532[103] = 0.0;
   out_8818080346799948532[104] = 0.0;
   out_8818080346799948532[105] = 0.0;
   out_8818080346799948532[106] = 0.0;
   out_8818080346799948532[107] = 0.0;
   out_8818080346799948532[108] = 0.0;
   out_8818080346799948532[109] = 0.0;
   out_8818080346799948532[110] = 0.0;
   out_8818080346799948532[111] = 0.0;
   out_8818080346799948532[112] = 0.0;
   out_8818080346799948532[113] = 0.0;
   out_8818080346799948532[114] = 1.0;
   out_8818080346799948532[115] = 0.0;
   out_8818080346799948532[116] = 0.0;
   out_8818080346799948532[117] = 0.0;
   out_8818080346799948532[118] = 0.0;
   out_8818080346799948532[119] = 0.0;
   out_8818080346799948532[120] = 0.0;
   out_8818080346799948532[121] = 0.0;
   out_8818080346799948532[122] = 0.0;
   out_8818080346799948532[123] = 0.0;
   out_8818080346799948532[124] = 0.0;
   out_8818080346799948532[125] = 0.0;
   out_8818080346799948532[126] = 0.0;
   out_8818080346799948532[127] = 0.0;
   out_8818080346799948532[128] = 0.0;
   out_8818080346799948532[129] = 0.0;
   out_8818080346799948532[130] = 0.0;
   out_8818080346799948532[131] = 0.0;
   out_8818080346799948532[132] = 0.0;
   out_8818080346799948532[133] = 1.0;
   out_8818080346799948532[134] = 0.0;
   out_8818080346799948532[135] = 0.0;
   out_8818080346799948532[136] = 0.0;
   out_8818080346799948532[137] = 0.0;
   out_8818080346799948532[138] = 0.0;
   out_8818080346799948532[139] = 0.0;
   out_8818080346799948532[140] = 0.0;
   out_8818080346799948532[141] = 0.0;
   out_8818080346799948532[142] = 0.0;
   out_8818080346799948532[143] = 0.0;
   out_8818080346799948532[144] = 0.0;
   out_8818080346799948532[145] = 0.0;
   out_8818080346799948532[146] = 0.0;
   out_8818080346799948532[147] = 0.0;
   out_8818080346799948532[148] = 0.0;
   out_8818080346799948532[149] = 0.0;
   out_8818080346799948532[150] = 0.0;
   out_8818080346799948532[151] = 0.0;
   out_8818080346799948532[152] = 1.0;
   out_8818080346799948532[153] = 0.0;
   out_8818080346799948532[154] = 0.0;
   out_8818080346799948532[155] = 0.0;
   out_8818080346799948532[156] = 0.0;
   out_8818080346799948532[157] = 0.0;
   out_8818080346799948532[158] = 0.0;
   out_8818080346799948532[159] = 0.0;
   out_8818080346799948532[160] = 0.0;
   out_8818080346799948532[161] = 0.0;
   out_8818080346799948532[162] = 0.0;
   out_8818080346799948532[163] = 0.0;
   out_8818080346799948532[164] = 0.0;
   out_8818080346799948532[165] = 0.0;
   out_8818080346799948532[166] = 0.0;
   out_8818080346799948532[167] = 0.0;
   out_8818080346799948532[168] = 0.0;
   out_8818080346799948532[169] = 0.0;
   out_8818080346799948532[170] = 0.0;
   out_8818080346799948532[171] = 1.0;
   out_8818080346799948532[172] = 0.0;
   out_8818080346799948532[173] = 0.0;
   out_8818080346799948532[174] = 0.0;
   out_8818080346799948532[175] = 0.0;
   out_8818080346799948532[176] = 0.0;
   out_8818080346799948532[177] = 0.0;
   out_8818080346799948532[178] = 0.0;
   out_8818080346799948532[179] = 0.0;
   out_8818080346799948532[180] = 0.0;
   out_8818080346799948532[181] = 0.0;
   out_8818080346799948532[182] = 0.0;
   out_8818080346799948532[183] = 0.0;
   out_8818080346799948532[184] = 0.0;
   out_8818080346799948532[185] = 0.0;
   out_8818080346799948532[186] = 0.0;
   out_8818080346799948532[187] = 0.0;
   out_8818080346799948532[188] = 0.0;
   out_8818080346799948532[189] = 0.0;
   out_8818080346799948532[190] = 1.0;
   out_8818080346799948532[191] = 0.0;
   out_8818080346799948532[192] = 0.0;
   out_8818080346799948532[193] = 0.0;
   out_8818080346799948532[194] = 0.0;
   out_8818080346799948532[195] = 0.0;
   out_8818080346799948532[196] = 0.0;
   out_8818080346799948532[197] = 0.0;
   out_8818080346799948532[198] = 0.0;
   out_8818080346799948532[199] = 0.0;
   out_8818080346799948532[200] = 0.0;
   out_8818080346799948532[201] = 0.0;
   out_8818080346799948532[202] = 0.0;
   out_8818080346799948532[203] = 0.0;
   out_8818080346799948532[204] = 0.0;
   out_8818080346799948532[205] = 0.0;
   out_8818080346799948532[206] = 0.0;
   out_8818080346799948532[207] = 0.0;
   out_8818080346799948532[208] = 0.0;
   out_8818080346799948532[209] = 1.0;
   out_8818080346799948532[210] = 0.0;
   out_8818080346799948532[211] = 0.0;
   out_8818080346799948532[212] = 0.0;
   out_8818080346799948532[213] = 0.0;
   out_8818080346799948532[214] = 0.0;
   out_8818080346799948532[215] = 0.0;
   out_8818080346799948532[216] = 0.0;
   out_8818080346799948532[217] = 0.0;
   out_8818080346799948532[218] = 0.0;
   out_8818080346799948532[219] = 0.0;
   out_8818080346799948532[220] = 0.0;
   out_8818080346799948532[221] = 0.0;
   out_8818080346799948532[222] = 0.0;
   out_8818080346799948532[223] = 0.0;
   out_8818080346799948532[224] = 0.0;
   out_8818080346799948532[225] = 0.0;
   out_8818080346799948532[226] = 0.0;
   out_8818080346799948532[227] = 0.0;
   out_8818080346799948532[228] = 1.0;
   out_8818080346799948532[229] = 0.0;
   out_8818080346799948532[230] = 0.0;
   out_8818080346799948532[231] = 0.0;
   out_8818080346799948532[232] = 0.0;
   out_8818080346799948532[233] = 0.0;
   out_8818080346799948532[234] = 0.0;
   out_8818080346799948532[235] = 0.0;
   out_8818080346799948532[236] = 0.0;
   out_8818080346799948532[237] = 0.0;
   out_8818080346799948532[238] = 0.0;
   out_8818080346799948532[239] = 0.0;
   out_8818080346799948532[240] = 0.0;
   out_8818080346799948532[241] = 0.0;
   out_8818080346799948532[242] = 0.0;
   out_8818080346799948532[243] = 0.0;
   out_8818080346799948532[244] = 0.0;
   out_8818080346799948532[245] = 0.0;
   out_8818080346799948532[246] = 0.0;
   out_8818080346799948532[247] = 1.0;
   out_8818080346799948532[248] = 0.0;
   out_8818080346799948532[249] = 0.0;
   out_8818080346799948532[250] = 0.0;
   out_8818080346799948532[251] = 0.0;
   out_8818080346799948532[252] = 0.0;
   out_8818080346799948532[253] = 0.0;
   out_8818080346799948532[254] = 0.0;
   out_8818080346799948532[255] = 0.0;
   out_8818080346799948532[256] = 0.0;
   out_8818080346799948532[257] = 0.0;
   out_8818080346799948532[258] = 0.0;
   out_8818080346799948532[259] = 0.0;
   out_8818080346799948532[260] = 0.0;
   out_8818080346799948532[261] = 0.0;
   out_8818080346799948532[262] = 0.0;
   out_8818080346799948532[263] = 0.0;
   out_8818080346799948532[264] = 0.0;
   out_8818080346799948532[265] = 0.0;
   out_8818080346799948532[266] = 1.0;
   out_8818080346799948532[267] = 0.0;
   out_8818080346799948532[268] = 0.0;
   out_8818080346799948532[269] = 0.0;
   out_8818080346799948532[270] = 0.0;
   out_8818080346799948532[271] = 0.0;
   out_8818080346799948532[272] = 0.0;
   out_8818080346799948532[273] = 0.0;
   out_8818080346799948532[274] = 0.0;
   out_8818080346799948532[275] = 0.0;
   out_8818080346799948532[276] = 0.0;
   out_8818080346799948532[277] = 0.0;
   out_8818080346799948532[278] = 0.0;
   out_8818080346799948532[279] = 0.0;
   out_8818080346799948532[280] = 0.0;
   out_8818080346799948532[281] = 0.0;
   out_8818080346799948532[282] = 0.0;
   out_8818080346799948532[283] = 0.0;
   out_8818080346799948532[284] = 0.0;
   out_8818080346799948532[285] = 1.0;
   out_8818080346799948532[286] = 0.0;
   out_8818080346799948532[287] = 0.0;
   out_8818080346799948532[288] = 0.0;
   out_8818080346799948532[289] = 0.0;
   out_8818080346799948532[290] = 0.0;
   out_8818080346799948532[291] = 0.0;
   out_8818080346799948532[292] = 0.0;
   out_8818080346799948532[293] = 0.0;
   out_8818080346799948532[294] = 0.0;
   out_8818080346799948532[295] = 0.0;
   out_8818080346799948532[296] = 0.0;
   out_8818080346799948532[297] = 0.0;
   out_8818080346799948532[298] = 0.0;
   out_8818080346799948532[299] = 0.0;
   out_8818080346799948532[300] = 0.0;
   out_8818080346799948532[301] = 0.0;
   out_8818080346799948532[302] = 0.0;
   out_8818080346799948532[303] = 0.0;
   out_8818080346799948532[304] = 1.0;
   out_8818080346799948532[305] = 0.0;
   out_8818080346799948532[306] = 0.0;
   out_8818080346799948532[307] = 0.0;
   out_8818080346799948532[308] = 0.0;
   out_8818080346799948532[309] = 0.0;
   out_8818080346799948532[310] = 0.0;
   out_8818080346799948532[311] = 0.0;
   out_8818080346799948532[312] = 0.0;
   out_8818080346799948532[313] = 0.0;
   out_8818080346799948532[314] = 0.0;
   out_8818080346799948532[315] = 0.0;
   out_8818080346799948532[316] = 0.0;
   out_8818080346799948532[317] = 0.0;
   out_8818080346799948532[318] = 0.0;
   out_8818080346799948532[319] = 0.0;
   out_8818080346799948532[320] = 0.0;
   out_8818080346799948532[321] = 0.0;
   out_8818080346799948532[322] = 0.0;
   out_8818080346799948532[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4287776289429729412) {
   out_4287776289429729412[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4287776289429729412[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4287776289429729412[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4287776289429729412[3] = dt*state[12] + state[3];
   out_4287776289429729412[4] = dt*state[13] + state[4];
   out_4287776289429729412[5] = dt*state[14] + state[5];
   out_4287776289429729412[6] = state[6];
   out_4287776289429729412[7] = state[7];
   out_4287776289429729412[8] = state[8];
   out_4287776289429729412[9] = state[9];
   out_4287776289429729412[10] = state[10];
   out_4287776289429729412[11] = state[11];
   out_4287776289429729412[12] = state[12];
   out_4287776289429729412[13] = state[13];
   out_4287776289429729412[14] = state[14];
   out_4287776289429729412[15] = state[15];
   out_4287776289429729412[16] = state[16];
   out_4287776289429729412[17] = state[17];
}
void F_fun(double *state, double dt, double *out_4341253320848234007) {
   out_4341253320848234007[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4341253320848234007[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4341253320848234007[2] = 0;
   out_4341253320848234007[3] = 0;
   out_4341253320848234007[4] = 0;
   out_4341253320848234007[5] = 0;
   out_4341253320848234007[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4341253320848234007[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4341253320848234007[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_4341253320848234007[9] = 0;
   out_4341253320848234007[10] = 0;
   out_4341253320848234007[11] = 0;
   out_4341253320848234007[12] = 0;
   out_4341253320848234007[13] = 0;
   out_4341253320848234007[14] = 0;
   out_4341253320848234007[15] = 0;
   out_4341253320848234007[16] = 0;
   out_4341253320848234007[17] = 0;
   out_4341253320848234007[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4341253320848234007[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4341253320848234007[20] = 0;
   out_4341253320848234007[21] = 0;
   out_4341253320848234007[22] = 0;
   out_4341253320848234007[23] = 0;
   out_4341253320848234007[24] = 0;
   out_4341253320848234007[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4341253320848234007[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_4341253320848234007[27] = 0;
   out_4341253320848234007[28] = 0;
   out_4341253320848234007[29] = 0;
   out_4341253320848234007[30] = 0;
   out_4341253320848234007[31] = 0;
   out_4341253320848234007[32] = 0;
   out_4341253320848234007[33] = 0;
   out_4341253320848234007[34] = 0;
   out_4341253320848234007[35] = 0;
   out_4341253320848234007[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4341253320848234007[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4341253320848234007[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4341253320848234007[39] = 0;
   out_4341253320848234007[40] = 0;
   out_4341253320848234007[41] = 0;
   out_4341253320848234007[42] = 0;
   out_4341253320848234007[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4341253320848234007[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_4341253320848234007[45] = 0;
   out_4341253320848234007[46] = 0;
   out_4341253320848234007[47] = 0;
   out_4341253320848234007[48] = 0;
   out_4341253320848234007[49] = 0;
   out_4341253320848234007[50] = 0;
   out_4341253320848234007[51] = 0;
   out_4341253320848234007[52] = 0;
   out_4341253320848234007[53] = 0;
   out_4341253320848234007[54] = 0;
   out_4341253320848234007[55] = 0;
   out_4341253320848234007[56] = 0;
   out_4341253320848234007[57] = 1;
   out_4341253320848234007[58] = 0;
   out_4341253320848234007[59] = 0;
   out_4341253320848234007[60] = 0;
   out_4341253320848234007[61] = 0;
   out_4341253320848234007[62] = 0;
   out_4341253320848234007[63] = 0;
   out_4341253320848234007[64] = 0;
   out_4341253320848234007[65] = 0;
   out_4341253320848234007[66] = dt;
   out_4341253320848234007[67] = 0;
   out_4341253320848234007[68] = 0;
   out_4341253320848234007[69] = 0;
   out_4341253320848234007[70] = 0;
   out_4341253320848234007[71] = 0;
   out_4341253320848234007[72] = 0;
   out_4341253320848234007[73] = 0;
   out_4341253320848234007[74] = 0;
   out_4341253320848234007[75] = 0;
   out_4341253320848234007[76] = 1;
   out_4341253320848234007[77] = 0;
   out_4341253320848234007[78] = 0;
   out_4341253320848234007[79] = 0;
   out_4341253320848234007[80] = 0;
   out_4341253320848234007[81] = 0;
   out_4341253320848234007[82] = 0;
   out_4341253320848234007[83] = 0;
   out_4341253320848234007[84] = 0;
   out_4341253320848234007[85] = dt;
   out_4341253320848234007[86] = 0;
   out_4341253320848234007[87] = 0;
   out_4341253320848234007[88] = 0;
   out_4341253320848234007[89] = 0;
   out_4341253320848234007[90] = 0;
   out_4341253320848234007[91] = 0;
   out_4341253320848234007[92] = 0;
   out_4341253320848234007[93] = 0;
   out_4341253320848234007[94] = 0;
   out_4341253320848234007[95] = 1;
   out_4341253320848234007[96] = 0;
   out_4341253320848234007[97] = 0;
   out_4341253320848234007[98] = 0;
   out_4341253320848234007[99] = 0;
   out_4341253320848234007[100] = 0;
   out_4341253320848234007[101] = 0;
   out_4341253320848234007[102] = 0;
   out_4341253320848234007[103] = 0;
   out_4341253320848234007[104] = dt;
   out_4341253320848234007[105] = 0;
   out_4341253320848234007[106] = 0;
   out_4341253320848234007[107] = 0;
   out_4341253320848234007[108] = 0;
   out_4341253320848234007[109] = 0;
   out_4341253320848234007[110] = 0;
   out_4341253320848234007[111] = 0;
   out_4341253320848234007[112] = 0;
   out_4341253320848234007[113] = 0;
   out_4341253320848234007[114] = 1;
   out_4341253320848234007[115] = 0;
   out_4341253320848234007[116] = 0;
   out_4341253320848234007[117] = 0;
   out_4341253320848234007[118] = 0;
   out_4341253320848234007[119] = 0;
   out_4341253320848234007[120] = 0;
   out_4341253320848234007[121] = 0;
   out_4341253320848234007[122] = 0;
   out_4341253320848234007[123] = 0;
   out_4341253320848234007[124] = 0;
   out_4341253320848234007[125] = 0;
   out_4341253320848234007[126] = 0;
   out_4341253320848234007[127] = 0;
   out_4341253320848234007[128] = 0;
   out_4341253320848234007[129] = 0;
   out_4341253320848234007[130] = 0;
   out_4341253320848234007[131] = 0;
   out_4341253320848234007[132] = 0;
   out_4341253320848234007[133] = 1;
   out_4341253320848234007[134] = 0;
   out_4341253320848234007[135] = 0;
   out_4341253320848234007[136] = 0;
   out_4341253320848234007[137] = 0;
   out_4341253320848234007[138] = 0;
   out_4341253320848234007[139] = 0;
   out_4341253320848234007[140] = 0;
   out_4341253320848234007[141] = 0;
   out_4341253320848234007[142] = 0;
   out_4341253320848234007[143] = 0;
   out_4341253320848234007[144] = 0;
   out_4341253320848234007[145] = 0;
   out_4341253320848234007[146] = 0;
   out_4341253320848234007[147] = 0;
   out_4341253320848234007[148] = 0;
   out_4341253320848234007[149] = 0;
   out_4341253320848234007[150] = 0;
   out_4341253320848234007[151] = 0;
   out_4341253320848234007[152] = 1;
   out_4341253320848234007[153] = 0;
   out_4341253320848234007[154] = 0;
   out_4341253320848234007[155] = 0;
   out_4341253320848234007[156] = 0;
   out_4341253320848234007[157] = 0;
   out_4341253320848234007[158] = 0;
   out_4341253320848234007[159] = 0;
   out_4341253320848234007[160] = 0;
   out_4341253320848234007[161] = 0;
   out_4341253320848234007[162] = 0;
   out_4341253320848234007[163] = 0;
   out_4341253320848234007[164] = 0;
   out_4341253320848234007[165] = 0;
   out_4341253320848234007[166] = 0;
   out_4341253320848234007[167] = 0;
   out_4341253320848234007[168] = 0;
   out_4341253320848234007[169] = 0;
   out_4341253320848234007[170] = 0;
   out_4341253320848234007[171] = 1;
   out_4341253320848234007[172] = 0;
   out_4341253320848234007[173] = 0;
   out_4341253320848234007[174] = 0;
   out_4341253320848234007[175] = 0;
   out_4341253320848234007[176] = 0;
   out_4341253320848234007[177] = 0;
   out_4341253320848234007[178] = 0;
   out_4341253320848234007[179] = 0;
   out_4341253320848234007[180] = 0;
   out_4341253320848234007[181] = 0;
   out_4341253320848234007[182] = 0;
   out_4341253320848234007[183] = 0;
   out_4341253320848234007[184] = 0;
   out_4341253320848234007[185] = 0;
   out_4341253320848234007[186] = 0;
   out_4341253320848234007[187] = 0;
   out_4341253320848234007[188] = 0;
   out_4341253320848234007[189] = 0;
   out_4341253320848234007[190] = 1;
   out_4341253320848234007[191] = 0;
   out_4341253320848234007[192] = 0;
   out_4341253320848234007[193] = 0;
   out_4341253320848234007[194] = 0;
   out_4341253320848234007[195] = 0;
   out_4341253320848234007[196] = 0;
   out_4341253320848234007[197] = 0;
   out_4341253320848234007[198] = 0;
   out_4341253320848234007[199] = 0;
   out_4341253320848234007[200] = 0;
   out_4341253320848234007[201] = 0;
   out_4341253320848234007[202] = 0;
   out_4341253320848234007[203] = 0;
   out_4341253320848234007[204] = 0;
   out_4341253320848234007[205] = 0;
   out_4341253320848234007[206] = 0;
   out_4341253320848234007[207] = 0;
   out_4341253320848234007[208] = 0;
   out_4341253320848234007[209] = 1;
   out_4341253320848234007[210] = 0;
   out_4341253320848234007[211] = 0;
   out_4341253320848234007[212] = 0;
   out_4341253320848234007[213] = 0;
   out_4341253320848234007[214] = 0;
   out_4341253320848234007[215] = 0;
   out_4341253320848234007[216] = 0;
   out_4341253320848234007[217] = 0;
   out_4341253320848234007[218] = 0;
   out_4341253320848234007[219] = 0;
   out_4341253320848234007[220] = 0;
   out_4341253320848234007[221] = 0;
   out_4341253320848234007[222] = 0;
   out_4341253320848234007[223] = 0;
   out_4341253320848234007[224] = 0;
   out_4341253320848234007[225] = 0;
   out_4341253320848234007[226] = 0;
   out_4341253320848234007[227] = 0;
   out_4341253320848234007[228] = 1;
   out_4341253320848234007[229] = 0;
   out_4341253320848234007[230] = 0;
   out_4341253320848234007[231] = 0;
   out_4341253320848234007[232] = 0;
   out_4341253320848234007[233] = 0;
   out_4341253320848234007[234] = 0;
   out_4341253320848234007[235] = 0;
   out_4341253320848234007[236] = 0;
   out_4341253320848234007[237] = 0;
   out_4341253320848234007[238] = 0;
   out_4341253320848234007[239] = 0;
   out_4341253320848234007[240] = 0;
   out_4341253320848234007[241] = 0;
   out_4341253320848234007[242] = 0;
   out_4341253320848234007[243] = 0;
   out_4341253320848234007[244] = 0;
   out_4341253320848234007[245] = 0;
   out_4341253320848234007[246] = 0;
   out_4341253320848234007[247] = 1;
   out_4341253320848234007[248] = 0;
   out_4341253320848234007[249] = 0;
   out_4341253320848234007[250] = 0;
   out_4341253320848234007[251] = 0;
   out_4341253320848234007[252] = 0;
   out_4341253320848234007[253] = 0;
   out_4341253320848234007[254] = 0;
   out_4341253320848234007[255] = 0;
   out_4341253320848234007[256] = 0;
   out_4341253320848234007[257] = 0;
   out_4341253320848234007[258] = 0;
   out_4341253320848234007[259] = 0;
   out_4341253320848234007[260] = 0;
   out_4341253320848234007[261] = 0;
   out_4341253320848234007[262] = 0;
   out_4341253320848234007[263] = 0;
   out_4341253320848234007[264] = 0;
   out_4341253320848234007[265] = 0;
   out_4341253320848234007[266] = 1;
   out_4341253320848234007[267] = 0;
   out_4341253320848234007[268] = 0;
   out_4341253320848234007[269] = 0;
   out_4341253320848234007[270] = 0;
   out_4341253320848234007[271] = 0;
   out_4341253320848234007[272] = 0;
   out_4341253320848234007[273] = 0;
   out_4341253320848234007[274] = 0;
   out_4341253320848234007[275] = 0;
   out_4341253320848234007[276] = 0;
   out_4341253320848234007[277] = 0;
   out_4341253320848234007[278] = 0;
   out_4341253320848234007[279] = 0;
   out_4341253320848234007[280] = 0;
   out_4341253320848234007[281] = 0;
   out_4341253320848234007[282] = 0;
   out_4341253320848234007[283] = 0;
   out_4341253320848234007[284] = 0;
   out_4341253320848234007[285] = 1;
   out_4341253320848234007[286] = 0;
   out_4341253320848234007[287] = 0;
   out_4341253320848234007[288] = 0;
   out_4341253320848234007[289] = 0;
   out_4341253320848234007[290] = 0;
   out_4341253320848234007[291] = 0;
   out_4341253320848234007[292] = 0;
   out_4341253320848234007[293] = 0;
   out_4341253320848234007[294] = 0;
   out_4341253320848234007[295] = 0;
   out_4341253320848234007[296] = 0;
   out_4341253320848234007[297] = 0;
   out_4341253320848234007[298] = 0;
   out_4341253320848234007[299] = 0;
   out_4341253320848234007[300] = 0;
   out_4341253320848234007[301] = 0;
   out_4341253320848234007[302] = 0;
   out_4341253320848234007[303] = 0;
   out_4341253320848234007[304] = 1;
   out_4341253320848234007[305] = 0;
   out_4341253320848234007[306] = 0;
   out_4341253320848234007[307] = 0;
   out_4341253320848234007[308] = 0;
   out_4341253320848234007[309] = 0;
   out_4341253320848234007[310] = 0;
   out_4341253320848234007[311] = 0;
   out_4341253320848234007[312] = 0;
   out_4341253320848234007[313] = 0;
   out_4341253320848234007[314] = 0;
   out_4341253320848234007[315] = 0;
   out_4341253320848234007[316] = 0;
   out_4341253320848234007[317] = 0;
   out_4341253320848234007[318] = 0;
   out_4341253320848234007[319] = 0;
   out_4341253320848234007[320] = 0;
   out_4341253320848234007[321] = 0;
   out_4341253320848234007[322] = 0;
   out_4341253320848234007[323] = 1;
}
void h_4(double *state, double *unused, double *out_6128102438980532385) {
   out_6128102438980532385[0] = state[6] + state[9];
   out_6128102438980532385[1] = state[7] + state[10];
   out_6128102438980532385[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6428253825808133060) {
   out_6428253825808133060[0] = 0;
   out_6428253825808133060[1] = 0;
   out_6428253825808133060[2] = 0;
   out_6428253825808133060[3] = 0;
   out_6428253825808133060[4] = 0;
   out_6428253825808133060[5] = 0;
   out_6428253825808133060[6] = 1;
   out_6428253825808133060[7] = 0;
   out_6428253825808133060[8] = 0;
   out_6428253825808133060[9] = 1;
   out_6428253825808133060[10] = 0;
   out_6428253825808133060[11] = 0;
   out_6428253825808133060[12] = 0;
   out_6428253825808133060[13] = 0;
   out_6428253825808133060[14] = 0;
   out_6428253825808133060[15] = 0;
   out_6428253825808133060[16] = 0;
   out_6428253825808133060[17] = 0;
   out_6428253825808133060[18] = 0;
   out_6428253825808133060[19] = 0;
   out_6428253825808133060[20] = 0;
   out_6428253825808133060[21] = 0;
   out_6428253825808133060[22] = 0;
   out_6428253825808133060[23] = 0;
   out_6428253825808133060[24] = 0;
   out_6428253825808133060[25] = 1;
   out_6428253825808133060[26] = 0;
   out_6428253825808133060[27] = 0;
   out_6428253825808133060[28] = 1;
   out_6428253825808133060[29] = 0;
   out_6428253825808133060[30] = 0;
   out_6428253825808133060[31] = 0;
   out_6428253825808133060[32] = 0;
   out_6428253825808133060[33] = 0;
   out_6428253825808133060[34] = 0;
   out_6428253825808133060[35] = 0;
   out_6428253825808133060[36] = 0;
   out_6428253825808133060[37] = 0;
   out_6428253825808133060[38] = 0;
   out_6428253825808133060[39] = 0;
   out_6428253825808133060[40] = 0;
   out_6428253825808133060[41] = 0;
   out_6428253825808133060[42] = 0;
   out_6428253825808133060[43] = 0;
   out_6428253825808133060[44] = 1;
   out_6428253825808133060[45] = 0;
   out_6428253825808133060[46] = 0;
   out_6428253825808133060[47] = 1;
   out_6428253825808133060[48] = 0;
   out_6428253825808133060[49] = 0;
   out_6428253825808133060[50] = 0;
   out_6428253825808133060[51] = 0;
   out_6428253825808133060[52] = 0;
   out_6428253825808133060[53] = 0;
}
void h_10(double *state, double *unused, double *out_1886304758557187825) {
   out_1886304758557187825[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_1886304758557187825[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_1886304758557187825[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8187218168232665500) {
   out_8187218168232665500[0] = 0;
   out_8187218168232665500[1] = 9.8100000000000005*cos(state[1]);
   out_8187218168232665500[2] = 0;
   out_8187218168232665500[3] = 0;
   out_8187218168232665500[4] = -state[8];
   out_8187218168232665500[5] = state[7];
   out_8187218168232665500[6] = 0;
   out_8187218168232665500[7] = state[5];
   out_8187218168232665500[8] = -state[4];
   out_8187218168232665500[9] = 0;
   out_8187218168232665500[10] = 0;
   out_8187218168232665500[11] = 0;
   out_8187218168232665500[12] = 1;
   out_8187218168232665500[13] = 0;
   out_8187218168232665500[14] = 0;
   out_8187218168232665500[15] = 1;
   out_8187218168232665500[16] = 0;
   out_8187218168232665500[17] = 0;
   out_8187218168232665500[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8187218168232665500[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8187218168232665500[20] = 0;
   out_8187218168232665500[21] = state[8];
   out_8187218168232665500[22] = 0;
   out_8187218168232665500[23] = -state[6];
   out_8187218168232665500[24] = -state[5];
   out_8187218168232665500[25] = 0;
   out_8187218168232665500[26] = state[3];
   out_8187218168232665500[27] = 0;
   out_8187218168232665500[28] = 0;
   out_8187218168232665500[29] = 0;
   out_8187218168232665500[30] = 0;
   out_8187218168232665500[31] = 1;
   out_8187218168232665500[32] = 0;
   out_8187218168232665500[33] = 0;
   out_8187218168232665500[34] = 1;
   out_8187218168232665500[35] = 0;
   out_8187218168232665500[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8187218168232665500[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8187218168232665500[38] = 0;
   out_8187218168232665500[39] = -state[7];
   out_8187218168232665500[40] = state[6];
   out_8187218168232665500[41] = 0;
   out_8187218168232665500[42] = state[4];
   out_8187218168232665500[43] = -state[3];
   out_8187218168232665500[44] = 0;
   out_8187218168232665500[45] = 0;
   out_8187218168232665500[46] = 0;
   out_8187218168232665500[47] = 0;
   out_8187218168232665500[48] = 0;
   out_8187218168232665500[49] = 0;
   out_8187218168232665500[50] = 1;
   out_8187218168232665500[51] = 0;
   out_8187218168232665500[52] = 0;
   out_8187218168232665500[53] = 1;
}
void h_13(double *state, double *unused, double *out_1675328109498391522) {
   out_1675328109498391522[0] = state[3];
   out_1675328109498391522[1] = state[4];
   out_1675328109498391522[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4407859039584717627) {
   out_4407859039584717627[0] = 0;
   out_4407859039584717627[1] = 0;
   out_4407859039584717627[2] = 0;
   out_4407859039584717627[3] = 1;
   out_4407859039584717627[4] = 0;
   out_4407859039584717627[5] = 0;
   out_4407859039584717627[6] = 0;
   out_4407859039584717627[7] = 0;
   out_4407859039584717627[8] = 0;
   out_4407859039584717627[9] = 0;
   out_4407859039584717627[10] = 0;
   out_4407859039584717627[11] = 0;
   out_4407859039584717627[12] = 0;
   out_4407859039584717627[13] = 0;
   out_4407859039584717627[14] = 0;
   out_4407859039584717627[15] = 0;
   out_4407859039584717627[16] = 0;
   out_4407859039584717627[17] = 0;
   out_4407859039584717627[18] = 0;
   out_4407859039584717627[19] = 0;
   out_4407859039584717627[20] = 0;
   out_4407859039584717627[21] = 0;
   out_4407859039584717627[22] = 1;
   out_4407859039584717627[23] = 0;
   out_4407859039584717627[24] = 0;
   out_4407859039584717627[25] = 0;
   out_4407859039584717627[26] = 0;
   out_4407859039584717627[27] = 0;
   out_4407859039584717627[28] = 0;
   out_4407859039584717627[29] = 0;
   out_4407859039584717627[30] = 0;
   out_4407859039584717627[31] = 0;
   out_4407859039584717627[32] = 0;
   out_4407859039584717627[33] = 0;
   out_4407859039584717627[34] = 0;
   out_4407859039584717627[35] = 0;
   out_4407859039584717627[36] = 0;
   out_4407859039584717627[37] = 0;
   out_4407859039584717627[38] = 0;
   out_4407859039584717627[39] = 0;
   out_4407859039584717627[40] = 0;
   out_4407859039584717627[41] = 1;
   out_4407859039584717627[42] = 0;
   out_4407859039584717627[43] = 0;
   out_4407859039584717627[44] = 0;
   out_4407859039584717627[45] = 0;
   out_4407859039584717627[46] = 0;
   out_4407859039584717627[47] = 0;
   out_4407859039584717627[48] = 0;
   out_4407859039584717627[49] = 0;
   out_4407859039584717627[50] = 0;
   out_4407859039584717627[51] = 0;
   out_4407859039584717627[52] = 0;
   out_4407859039584717627[53] = 0;
}
void h_14(double *state, double *unused, double *out_6344247348281186472) {
   out_6344247348281186472[0] = state[6];
   out_6344247348281186472[1] = state[7];
   out_6344247348281186472[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3345465393512760764) {
   out_3345465393512760764[0] = 0;
   out_3345465393512760764[1] = 0;
   out_3345465393512760764[2] = 0;
   out_3345465393512760764[3] = 0;
   out_3345465393512760764[4] = 0;
   out_3345465393512760764[5] = 0;
   out_3345465393512760764[6] = 1;
   out_3345465393512760764[7] = 0;
   out_3345465393512760764[8] = 0;
   out_3345465393512760764[9] = 0;
   out_3345465393512760764[10] = 0;
   out_3345465393512760764[11] = 0;
   out_3345465393512760764[12] = 0;
   out_3345465393512760764[13] = 0;
   out_3345465393512760764[14] = 0;
   out_3345465393512760764[15] = 0;
   out_3345465393512760764[16] = 0;
   out_3345465393512760764[17] = 0;
   out_3345465393512760764[18] = 0;
   out_3345465393512760764[19] = 0;
   out_3345465393512760764[20] = 0;
   out_3345465393512760764[21] = 0;
   out_3345465393512760764[22] = 0;
   out_3345465393512760764[23] = 0;
   out_3345465393512760764[24] = 0;
   out_3345465393512760764[25] = 1;
   out_3345465393512760764[26] = 0;
   out_3345465393512760764[27] = 0;
   out_3345465393512760764[28] = 0;
   out_3345465393512760764[29] = 0;
   out_3345465393512760764[30] = 0;
   out_3345465393512760764[31] = 0;
   out_3345465393512760764[32] = 0;
   out_3345465393512760764[33] = 0;
   out_3345465393512760764[34] = 0;
   out_3345465393512760764[35] = 0;
   out_3345465393512760764[36] = 0;
   out_3345465393512760764[37] = 0;
   out_3345465393512760764[38] = 0;
   out_3345465393512760764[39] = 0;
   out_3345465393512760764[40] = 0;
   out_3345465393512760764[41] = 0;
   out_3345465393512760764[42] = 0;
   out_3345465393512760764[43] = 0;
   out_3345465393512760764[44] = 1;
   out_3345465393512760764[45] = 0;
   out_3345465393512760764[46] = 0;
   out_3345465393512760764[47] = 0;
   out_3345465393512760764[48] = 0;
   out_3345465393512760764[49] = 0;
   out_3345465393512760764[50] = 0;
   out_3345465393512760764[51] = 0;
   out_3345465393512760764[52] = 0;
   out_3345465393512760764[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5195610458540139902) {
  err_fun(nom_x, delta_x, out_5195610458540139902);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7314439786479166241) {
  inv_err_fun(nom_x, true_x, out_7314439786479166241);
}
void pose_H_mod_fun(double *state, double *out_8818080346799948532) {
  H_mod_fun(state, out_8818080346799948532);
}
void pose_f_fun(double *state, double dt, double *out_4287776289429729412) {
  f_fun(state,  dt, out_4287776289429729412);
}
void pose_F_fun(double *state, double dt, double *out_4341253320848234007) {
  F_fun(state,  dt, out_4341253320848234007);
}
void pose_h_4(double *state, double *unused, double *out_6128102438980532385) {
  h_4(state, unused, out_6128102438980532385);
}
void pose_H_4(double *state, double *unused, double *out_6428253825808133060) {
  H_4(state, unused, out_6428253825808133060);
}
void pose_h_10(double *state, double *unused, double *out_1886304758557187825) {
  h_10(state, unused, out_1886304758557187825);
}
void pose_H_10(double *state, double *unused, double *out_8187218168232665500) {
  H_10(state, unused, out_8187218168232665500);
}
void pose_h_13(double *state, double *unused, double *out_1675328109498391522) {
  h_13(state, unused, out_1675328109498391522);
}
void pose_H_13(double *state, double *unused, double *out_4407859039584717627) {
  H_13(state, unused, out_4407859039584717627);
}
void pose_h_14(double *state, double *unused, double *out_6344247348281186472) {
  h_14(state, unused, out_6344247348281186472);
}
void pose_H_14(double *state, double *unused, double *out_3345465393512760764) {
  H_14(state, unused, out_3345465393512760764);
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
