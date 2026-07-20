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
void err_fun(double *nom_x, double *delta_x, double *out_5326449587047095854) {
   out_5326449587047095854[0] = delta_x[0] + nom_x[0];
   out_5326449587047095854[1] = delta_x[1] + nom_x[1];
   out_5326449587047095854[2] = delta_x[2] + nom_x[2];
   out_5326449587047095854[3] = delta_x[3] + nom_x[3];
   out_5326449587047095854[4] = delta_x[4] + nom_x[4];
   out_5326449587047095854[5] = delta_x[5] + nom_x[5];
   out_5326449587047095854[6] = delta_x[6] + nom_x[6];
   out_5326449587047095854[7] = delta_x[7] + nom_x[7];
   out_5326449587047095854[8] = delta_x[8] + nom_x[8];
   out_5326449587047095854[9] = delta_x[9] + nom_x[9];
   out_5326449587047095854[10] = delta_x[10] + nom_x[10];
   out_5326449587047095854[11] = delta_x[11] + nom_x[11];
   out_5326449587047095854[12] = delta_x[12] + nom_x[12];
   out_5326449587047095854[13] = delta_x[13] + nom_x[13];
   out_5326449587047095854[14] = delta_x[14] + nom_x[14];
   out_5326449587047095854[15] = delta_x[15] + nom_x[15];
   out_5326449587047095854[16] = delta_x[16] + nom_x[16];
   out_5326449587047095854[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_808033856261158562) {
   out_808033856261158562[0] = -nom_x[0] + true_x[0];
   out_808033856261158562[1] = -nom_x[1] + true_x[1];
   out_808033856261158562[2] = -nom_x[2] + true_x[2];
   out_808033856261158562[3] = -nom_x[3] + true_x[3];
   out_808033856261158562[4] = -nom_x[4] + true_x[4];
   out_808033856261158562[5] = -nom_x[5] + true_x[5];
   out_808033856261158562[6] = -nom_x[6] + true_x[6];
   out_808033856261158562[7] = -nom_x[7] + true_x[7];
   out_808033856261158562[8] = -nom_x[8] + true_x[8];
   out_808033856261158562[9] = -nom_x[9] + true_x[9];
   out_808033856261158562[10] = -nom_x[10] + true_x[10];
   out_808033856261158562[11] = -nom_x[11] + true_x[11];
   out_808033856261158562[12] = -nom_x[12] + true_x[12];
   out_808033856261158562[13] = -nom_x[13] + true_x[13];
   out_808033856261158562[14] = -nom_x[14] + true_x[14];
   out_808033856261158562[15] = -nom_x[15] + true_x[15];
   out_808033856261158562[16] = -nom_x[16] + true_x[16];
   out_808033856261158562[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_4598941152447404033) {
   out_4598941152447404033[0] = 1.0;
   out_4598941152447404033[1] = 0.0;
   out_4598941152447404033[2] = 0.0;
   out_4598941152447404033[3] = 0.0;
   out_4598941152447404033[4] = 0.0;
   out_4598941152447404033[5] = 0.0;
   out_4598941152447404033[6] = 0.0;
   out_4598941152447404033[7] = 0.0;
   out_4598941152447404033[8] = 0.0;
   out_4598941152447404033[9] = 0.0;
   out_4598941152447404033[10] = 0.0;
   out_4598941152447404033[11] = 0.0;
   out_4598941152447404033[12] = 0.0;
   out_4598941152447404033[13] = 0.0;
   out_4598941152447404033[14] = 0.0;
   out_4598941152447404033[15] = 0.0;
   out_4598941152447404033[16] = 0.0;
   out_4598941152447404033[17] = 0.0;
   out_4598941152447404033[18] = 0.0;
   out_4598941152447404033[19] = 1.0;
   out_4598941152447404033[20] = 0.0;
   out_4598941152447404033[21] = 0.0;
   out_4598941152447404033[22] = 0.0;
   out_4598941152447404033[23] = 0.0;
   out_4598941152447404033[24] = 0.0;
   out_4598941152447404033[25] = 0.0;
   out_4598941152447404033[26] = 0.0;
   out_4598941152447404033[27] = 0.0;
   out_4598941152447404033[28] = 0.0;
   out_4598941152447404033[29] = 0.0;
   out_4598941152447404033[30] = 0.0;
   out_4598941152447404033[31] = 0.0;
   out_4598941152447404033[32] = 0.0;
   out_4598941152447404033[33] = 0.0;
   out_4598941152447404033[34] = 0.0;
   out_4598941152447404033[35] = 0.0;
   out_4598941152447404033[36] = 0.0;
   out_4598941152447404033[37] = 0.0;
   out_4598941152447404033[38] = 1.0;
   out_4598941152447404033[39] = 0.0;
   out_4598941152447404033[40] = 0.0;
   out_4598941152447404033[41] = 0.0;
   out_4598941152447404033[42] = 0.0;
   out_4598941152447404033[43] = 0.0;
   out_4598941152447404033[44] = 0.0;
   out_4598941152447404033[45] = 0.0;
   out_4598941152447404033[46] = 0.0;
   out_4598941152447404033[47] = 0.0;
   out_4598941152447404033[48] = 0.0;
   out_4598941152447404033[49] = 0.0;
   out_4598941152447404033[50] = 0.0;
   out_4598941152447404033[51] = 0.0;
   out_4598941152447404033[52] = 0.0;
   out_4598941152447404033[53] = 0.0;
   out_4598941152447404033[54] = 0.0;
   out_4598941152447404033[55] = 0.0;
   out_4598941152447404033[56] = 0.0;
   out_4598941152447404033[57] = 1.0;
   out_4598941152447404033[58] = 0.0;
   out_4598941152447404033[59] = 0.0;
   out_4598941152447404033[60] = 0.0;
   out_4598941152447404033[61] = 0.0;
   out_4598941152447404033[62] = 0.0;
   out_4598941152447404033[63] = 0.0;
   out_4598941152447404033[64] = 0.0;
   out_4598941152447404033[65] = 0.0;
   out_4598941152447404033[66] = 0.0;
   out_4598941152447404033[67] = 0.0;
   out_4598941152447404033[68] = 0.0;
   out_4598941152447404033[69] = 0.0;
   out_4598941152447404033[70] = 0.0;
   out_4598941152447404033[71] = 0.0;
   out_4598941152447404033[72] = 0.0;
   out_4598941152447404033[73] = 0.0;
   out_4598941152447404033[74] = 0.0;
   out_4598941152447404033[75] = 0.0;
   out_4598941152447404033[76] = 1.0;
   out_4598941152447404033[77] = 0.0;
   out_4598941152447404033[78] = 0.0;
   out_4598941152447404033[79] = 0.0;
   out_4598941152447404033[80] = 0.0;
   out_4598941152447404033[81] = 0.0;
   out_4598941152447404033[82] = 0.0;
   out_4598941152447404033[83] = 0.0;
   out_4598941152447404033[84] = 0.0;
   out_4598941152447404033[85] = 0.0;
   out_4598941152447404033[86] = 0.0;
   out_4598941152447404033[87] = 0.0;
   out_4598941152447404033[88] = 0.0;
   out_4598941152447404033[89] = 0.0;
   out_4598941152447404033[90] = 0.0;
   out_4598941152447404033[91] = 0.0;
   out_4598941152447404033[92] = 0.0;
   out_4598941152447404033[93] = 0.0;
   out_4598941152447404033[94] = 0.0;
   out_4598941152447404033[95] = 1.0;
   out_4598941152447404033[96] = 0.0;
   out_4598941152447404033[97] = 0.0;
   out_4598941152447404033[98] = 0.0;
   out_4598941152447404033[99] = 0.0;
   out_4598941152447404033[100] = 0.0;
   out_4598941152447404033[101] = 0.0;
   out_4598941152447404033[102] = 0.0;
   out_4598941152447404033[103] = 0.0;
   out_4598941152447404033[104] = 0.0;
   out_4598941152447404033[105] = 0.0;
   out_4598941152447404033[106] = 0.0;
   out_4598941152447404033[107] = 0.0;
   out_4598941152447404033[108] = 0.0;
   out_4598941152447404033[109] = 0.0;
   out_4598941152447404033[110] = 0.0;
   out_4598941152447404033[111] = 0.0;
   out_4598941152447404033[112] = 0.0;
   out_4598941152447404033[113] = 0.0;
   out_4598941152447404033[114] = 1.0;
   out_4598941152447404033[115] = 0.0;
   out_4598941152447404033[116] = 0.0;
   out_4598941152447404033[117] = 0.0;
   out_4598941152447404033[118] = 0.0;
   out_4598941152447404033[119] = 0.0;
   out_4598941152447404033[120] = 0.0;
   out_4598941152447404033[121] = 0.0;
   out_4598941152447404033[122] = 0.0;
   out_4598941152447404033[123] = 0.0;
   out_4598941152447404033[124] = 0.0;
   out_4598941152447404033[125] = 0.0;
   out_4598941152447404033[126] = 0.0;
   out_4598941152447404033[127] = 0.0;
   out_4598941152447404033[128] = 0.0;
   out_4598941152447404033[129] = 0.0;
   out_4598941152447404033[130] = 0.0;
   out_4598941152447404033[131] = 0.0;
   out_4598941152447404033[132] = 0.0;
   out_4598941152447404033[133] = 1.0;
   out_4598941152447404033[134] = 0.0;
   out_4598941152447404033[135] = 0.0;
   out_4598941152447404033[136] = 0.0;
   out_4598941152447404033[137] = 0.0;
   out_4598941152447404033[138] = 0.0;
   out_4598941152447404033[139] = 0.0;
   out_4598941152447404033[140] = 0.0;
   out_4598941152447404033[141] = 0.0;
   out_4598941152447404033[142] = 0.0;
   out_4598941152447404033[143] = 0.0;
   out_4598941152447404033[144] = 0.0;
   out_4598941152447404033[145] = 0.0;
   out_4598941152447404033[146] = 0.0;
   out_4598941152447404033[147] = 0.0;
   out_4598941152447404033[148] = 0.0;
   out_4598941152447404033[149] = 0.0;
   out_4598941152447404033[150] = 0.0;
   out_4598941152447404033[151] = 0.0;
   out_4598941152447404033[152] = 1.0;
   out_4598941152447404033[153] = 0.0;
   out_4598941152447404033[154] = 0.0;
   out_4598941152447404033[155] = 0.0;
   out_4598941152447404033[156] = 0.0;
   out_4598941152447404033[157] = 0.0;
   out_4598941152447404033[158] = 0.0;
   out_4598941152447404033[159] = 0.0;
   out_4598941152447404033[160] = 0.0;
   out_4598941152447404033[161] = 0.0;
   out_4598941152447404033[162] = 0.0;
   out_4598941152447404033[163] = 0.0;
   out_4598941152447404033[164] = 0.0;
   out_4598941152447404033[165] = 0.0;
   out_4598941152447404033[166] = 0.0;
   out_4598941152447404033[167] = 0.0;
   out_4598941152447404033[168] = 0.0;
   out_4598941152447404033[169] = 0.0;
   out_4598941152447404033[170] = 0.0;
   out_4598941152447404033[171] = 1.0;
   out_4598941152447404033[172] = 0.0;
   out_4598941152447404033[173] = 0.0;
   out_4598941152447404033[174] = 0.0;
   out_4598941152447404033[175] = 0.0;
   out_4598941152447404033[176] = 0.0;
   out_4598941152447404033[177] = 0.0;
   out_4598941152447404033[178] = 0.0;
   out_4598941152447404033[179] = 0.0;
   out_4598941152447404033[180] = 0.0;
   out_4598941152447404033[181] = 0.0;
   out_4598941152447404033[182] = 0.0;
   out_4598941152447404033[183] = 0.0;
   out_4598941152447404033[184] = 0.0;
   out_4598941152447404033[185] = 0.0;
   out_4598941152447404033[186] = 0.0;
   out_4598941152447404033[187] = 0.0;
   out_4598941152447404033[188] = 0.0;
   out_4598941152447404033[189] = 0.0;
   out_4598941152447404033[190] = 1.0;
   out_4598941152447404033[191] = 0.0;
   out_4598941152447404033[192] = 0.0;
   out_4598941152447404033[193] = 0.0;
   out_4598941152447404033[194] = 0.0;
   out_4598941152447404033[195] = 0.0;
   out_4598941152447404033[196] = 0.0;
   out_4598941152447404033[197] = 0.0;
   out_4598941152447404033[198] = 0.0;
   out_4598941152447404033[199] = 0.0;
   out_4598941152447404033[200] = 0.0;
   out_4598941152447404033[201] = 0.0;
   out_4598941152447404033[202] = 0.0;
   out_4598941152447404033[203] = 0.0;
   out_4598941152447404033[204] = 0.0;
   out_4598941152447404033[205] = 0.0;
   out_4598941152447404033[206] = 0.0;
   out_4598941152447404033[207] = 0.0;
   out_4598941152447404033[208] = 0.0;
   out_4598941152447404033[209] = 1.0;
   out_4598941152447404033[210] = 0.0;
   out_4598941152447404033[211] = 0.0;
   out_4598941152447404033[212] = 0.0;
   out_4598941152447404033[213] = 0.0;
   out_4598941152447404033[214] = 0.0;
   out_4598941152447404033[215] = 0.0;
   out_4598941152447404033[216] = 0.0;
   out_4598941152447404033[217] = 0.0;
   out_4598941152447404033[218] = 0.0;
   out_4598941152447404033[219] = 0.0;
   out_4598941152447404033[220] = 0.0;
   out_4598941152447404033[221] = 0.0;
   out_4598941152447404033[222] = 0.0;
   out_4598941152447404033[223] = 0.0;
   out_4598941152447404033[224] = 0.0;
   out_4598941152447404033[225] = 0.0;
   out_4598941152447404033[226] = 0.0;
   out_4598941152447404033[227] = 0.0;
   out_4598941152447404033[228] = 1.0;
   out_4598941152447404033[229] = 0.0;
   out_4598941152447404033[230] = 0.0;
   out_4598941152447404033[231] = 0.0;
   out_4598941152447404033[232] = 0.0;
   out_4598941152447404033[233] = 0.0;
   out_4598941152447404033[234] = 0.0;
   out_4598941152447404033[235] = 0.0;
   out_4598941152447404033[236] = 0.0;
   out_4598941152447404033[237] = 0.0;
   out_4598941152447404033[238] = 0.0;
   out_4598941152447404033[239] = 0.0;
   out_4598941152447404033[240] = 0.0;
   out_4598941152447404033[241] = 0.0;
   out_4598941152447404033[242] = 0.0;
   out_4598941152447404033[243] = 0.0;
   out_4598941152447404033[244] = 0.0;
   out_4598941152447404033[245] = 0.0;
   out_4598941152447404033[246] = 0.0;
   out_4598941152447404033[247] = 1.0;
   out_4598941152447404033[248] = 0.0;
   out_4598941152447404033[249] = 0.0;
   out_4598941152447404033[250] = 0.0;
   out_4598941152447404033[251] = 0.0;
   out_4598941152447404033[252] = 0.0;
   out_4598941152447404033[253] = 0.0;
   out_4598941152447404033[254] = 0.0;
   out_4598941152447404033[255] = 0.0;
   out_4598941152447404033[256] = 0.0;
   out_4598941152447404033[257] = 0.0;
   out_4598941152447404033[258] = 0.0;
   out_4598941152447404033[259] = 0.0;
   out_4598941152447404033[260] = 0.0;
   out_4598941152447404033[261] = 0.0;
   out_4598941152447404033[262] = 0.0;
   out_4598941152447404033[263] = 0.0;
   out_4598941152447404033[264] = 0.0;
   out_4598941152447404033[265] = 0.0;
   out_4598941152447404033[266] = 1.0;
   out_4598941152447404033[267] = 0.0;
   out_4598941152447404033[268] = 0.0;
   out_4598941152447404033[269] = 0.0;
   out_4598941152447404033[270] = 0.0;
   out_4598941152447404033[271] = 0.0;
   out_4598941152447404033[272] = 0.0;
   out_4598941152447404033[273] = 0.0;
   out_4598941152447404033[274] = 0.0;
   out_4598941152447404033[275] = 0.0;
   out_4598941152447404033[276] = 0.0;
   out_4598941152447404033[277] = 0.0;
   out_4598941152447404033[278] = 0.0;
   out_4598941152447404033[279] = 0.0;
   out_4598941152447404033[280] = 0.0;
   out_4598941152447404033[281] = 0.0;
   out_4598941152447404033[282] = 0.0;
   out_4598941152447404033[283] = 0.0;
   out_4598941152447404033[284] = 0.0;
   out_4598941152447404033[285] = 1.0;
   out_4598941152447404033[286] = 0.0;
   out_4598941152447404033[287] = 0.0;
   out_4598941152447404033[288] = 0.0;
   out_4598941152447404033[289] = 0.0;
   out_4598941152447404033[290] = 0.0;
   out_4598941152447404033[291] = 0.0;
   out_4598941152447404033[292] = 0.0;
   out_4598941152447404033[293] = 0.0;
   out_4598941152447404033[294] = 0.0;
   out_4598941152447404033[295] = 0.0;
   out_4598941152447404033[296] = 0.0;
   out_4598941152447404033[297] = 0.0;
   out_4598941152447404033[298] = 0.0;
   out_4598941152447404033[299] = 0.0;
   out_4598941152447404033[300] = 0.0;
   out_4598941152447404033[301] = 0.0;
   out_4598941152447404033[302] = 0.0;
   out_4598941152447404033[303] = 0.0;
   out_4598941152447404033[304] = 1.0;
   out_4598941152447404033[305] = 0.0;
   out_4598941152447404033[306] = 0.0;
   out_4598941152447404033[307] = 0.0;
   out_4598941152447404033[308] = 0.0;
   out_4598941152447404033[309] = 0.0;
   out_4598941152447404033[310] = 0.0;
   out_4598941152447404033[311] = 0.0;
   out_4598941152447404033[312] = 0.0;
   out_4598941152447404033[313] = 0.0;
   out_4598941152447404033[314] = 0.0;
   out_4598941152447404033[315] = 0.0;
   out_4598941152447404033[316] = 0.0;
   out_4598941152447404033[317] = 0.0;
   out_4598941152447404033[318] = 0.0;
   out_4598941152447404033[319] = 0.0;
   out_4598941152447404033[320] = 0.0;
   out_4598941152447404033[321] = 0.0;
   out_4598941152447404033[322] = 0.0;
   out_4598941152447404033[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7845712062767557446) {
   out_7845712062767557446[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7845712062767557446[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7845712062767557446[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7845712062767557446[3] = dt*state[12] + state[3];
   out_7845712062767557446[4] = dt*state[13] + state[4];
   out_7845712062767557446[5] = dt*state[14] + state[5];
   out_7845712062767557446[6] = state[6];
   out_7845712062767557446[7] = state[7];
   out_7845712062767557446[8] = state[8];
   out_7845712062767557446[9] = state[9];
   out_7845712062767557446[10] = state[10];
   out_7845712062767557446[11] = state[11];
   out_7845712062767557446[12] = state[12];
   out_7845712062767557446[13] = state[13];
   out_7845712062767557446[14] = state[14];
   out_7845712062767557446[15] = state[15];
   out_7845712062767557446[16] = state[16];
   out_7845712062767557446[17] = state[17];
}
void F_fun(double *state, double dt, double *out_879909740565667902) {
   out_879909740565667902[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_879909740565667902[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_879909740565667902[2] = 0;
   out_879909740565667902[3] = 0;
   out_879909740565667902[4] = 0;
   out_879909740565667902[5] = 0;
   out_879909740565667902[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_879909740565667902[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_879909740565667902[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_879909740565667902[9] = 0;
   out_879909740565667902[10] = 0;
   out_879909740565667902[11] = 0;
   out_879909740565667902[12] = 0;
   out_879909740565667902[13] = 0;
   out_879909740565667902[14] = 0;
   out_879909740565667902[15] = 0;
   out_879909740565667902[16] = 0;
   out_879909740565667902[17] = 0;
   out_879909740565667902[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_879909740565667902[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_879909740565667902[20] = 0;
   out_879909740565667902[21] = 0;
   out_879909740565667902[22] = 0;
   out_879909740565667902[23] = 0;
   out_879909740565667902[24] = 0;
   out_879909740565667902[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_879909740565667902[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_879909740565667902[27] = 0;
   out_879909740565667902[28] = 0;
   out_879909740565667902[29] = 0;
   out_879909740565667902[30] = 0;
   out_879909740565667902[31] = 0;
   out_879909740565667902[32] = 0;
   out_879909740565667902[33] = 0;
   out_879909740565667902[34] = 0;
   out_879909740565667902[35] = 0;
   out_879909740565667902[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_879909740565667902[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_879909740565667902[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_879909740565667902[39] = 0;
   out_879909740565667902[40] = 0;
   out_879909740565667902[41] = 0;
   out_879909740565667902[42] = 0;
   out_879909740565667902[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_879909740565667902[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_879909740565667902[45] = 0;
   out_879909740565667902[46] = 0;
   out_879909740565667902[47] = 0;
   out_879909740565667902[48] = 0;
   out_879909740565667902[49] = 0;
   out_879909740565667902[50] = 0;
   out_879909740565667902[51] = 0;
   out_879909740565667902[52] = 0;
   out_879909740565667902[53] = 0;
   out_879909740565667902[54] = 0;
   out_879909740565667902[55] = 0;
   out_879909740565667902[56] = 0;
   out_879909740565667902[57] = 1;
   out_879909740565667902[58] = 0;
   out_879909740565667902[59] = 0;
   out_879909740565667902[60] = 0;
   out_879909740565667902[61] = 0;
   out_879909740565667902[62] = 0;
   out_879909740565667902[63] = 0;
   out_879909740565667902[64] = 0;
   out_879909740565667902[65] = 0;
   out_879909740565667902[66] = dt;
   out_879909740565667902[67] = 0;
   out_879909740565667902[68] = 0;
   out_879909740565667902[69] = 0;
   out_879909740565667902[70] = 0;
   out_879909740565667902[71] = 0;
   out_879909740565667902[72] = 0;
   out_879909740565667902[73] = 0;
   out_879909740565667902[74] = 0;
   out_879909740565667902[75] = 0;
   out_879909740565667902[76] = 1;
   out_879909740565667902[77] = 0;
   out_879909740565667902[78] = 0;
   out_879909740565667902[79] = 0;
   out_879909740565667902[80] = 0;
   out_879909740565667902[81] = 0;
   out_879909740565667902[82] = 0;
   out_879909740565667902[83] = 0;
   out_879909740565667902[84] = 0;
   out_879909740565667902[85] = dt;
   out_879909740565667902[86] = 0;
   out_879909740565667902[87] = 0;
   out_879909740565667902[88] = 0;
   out_879909740565667902[89] = 0;
   out_879909740565667902[90] = 0;
   out_879909740565667902[91] = 0;
   out_879909740565667902[92] = 0;
   out_879909740565667902[93] = 0;
   out_879909740565667902[94] = 0;
   out_879909740565667902[95] = 1;
   out_879909740565667902[96] = 0;
   out_879909740565667902[97] = 0;
   out_879909740565667902[98] = 0;
   out_879909740565667902[99] = 0;
   out_879909740565667902[100] = 0;
   out_879909740565667902[101] = 0;
   out_879909740565667902[102] = 0;
   out_879909740565667902[103] = 0;
   out_879909740565667902[104] = dt;
   out_879909740565667902[105] = 0;
   out_879909740565667902[106] = 0;
   out_879909740565667902[107] = 0;
   out_879909740565667902[108] = 0;
   out_879909740565667902[109] = 0;
   out_879909740565667902[110] = 0;
   out_879909740565667902[111] = 0;
   out_879909740565667902[112] = 0;
   out_879909740565667902[113] = 0;
   out_879909740565667902[114] = 1;
   out_879909740565667902[115] = 0;
   out_879909740565667902[116] = 0;
   out_879909740565667902[117] = 0;
   out_879909740565667902[118] = 0;
   out_879909740565667902[119] = 0;
   out_879909740565667902[120] = 0;
   out_879909740565667902[121] = 0;
   out_879909740565667902[122] = 0;
   out_879909740565667902[123] = 0;
   out_879909740565667902[124] = 0;
   out_879909740565667902[125] = 0;
   out_879909740565667902[126] = 0;
   out_879909740565667902[127] = 0;
   out_879909740565667902[128] = 0;
   out_879909740565667902[129] = 0;
   out_879909740565667902[130] = 0;
   out_879909740565667902[131] = 0;
   out_879909740565667902[132] = 0;
   out_879909740565667902[133] = 1;
   out_879909740565667902[134] = 0;
   out_879909740565667902[135] = 0;
   out_879909740565667902[136] = 0;
   out_879909740565667902[137] = 0;
   out_879909740565667902[138] = 0;
   out_879909740565667902[139] = 0;
   out_879909740565667902[140] = 0;
   out_879909740565667902[141] = 0;
   out_879909740565667902[142] = 0;
   out_879909740565667902[143] = 0;
   out_879909740565667902[144] = 0;
   out_879909740565667902[145] = 0;
   out_879909740565667902[146] = 0;
   out_879909740565667902[147] = 0;
   out_879909740565667902[148] = 0;
   out_879909740565667902[149] = 0;
   out_879909740565667902[150] = 0;
   out_879909740565667902[151] = 0;
   out_879909740565667902[152] = 1;
   out_879909740565667902[153] = 0;
   out_879909740565667902[154] = 0;
   out_879909740565667902[155] = 0;
   out_879909740565667902[156] = 0;
   out_879909740565667902[157] = 0;
   out_879909740565667902[158] = 0;
   out_879909740565667902[159] = 0;
   out_879909740565667902[160] = 0;
   out_879909740565667902[161] = 0;
   out_879909740565667902[162] = 0;
   out_879909740565667902[163] = 0;
   out_879909740565667902[164] = 0;
   out_879909740565667902[165] = 0;
   out_879909740565667902[166] = 0;
   out_879909740565667902[167] = 0;
   out_879909740565667902[168] = 0;
   out_879909740565667902[169] = 0;
   out_879909740565667902[170] = 0;
   out_879909740565667902[171] = 1;
   out_879909740565667902[172] = 0;
   out_879909740565667902[173] = 0;
   out_879909740565667902[174] = 0;
   out_879909740565667902[175] = 0;
   out_879909740565667902[176] = 0;
   out_879909740565667902[177] = 0;
   out_879909740565667902[178] = 0;
   out_879909740565667902[179] = 0;
   out_879909740565667902[180] = 0;
   out_879909740565667902[181] = 0;
   out_879909740565667902[182] = 0;
   out_879909740565667902[183] = 0;
   out_879909740565667902[184] = 0;
   out_879909740565667902[185] = 0;
   out_879909740565667902[186] = 0;
   out_879909740565667902[187] = 0;
   out_879909740565667902[188] = 0;
   out_879909740565667902[189] = 0;
   out_879909740565667902[190] = 1;
   out_879909740565667902[191] = 0;
   out_879909740565667902[192] = 0;
   out_879909740565667902[193] = 0;
   out_879909740565667902[194] = 0;
   out_879909740565667902[195] = 0;
   out_879909740565667902[196] = 0;
   out_879909740565667902[197] = 0;
   out_879909740565667902[198] = 0;
   out_879909740565667902[199] = 0;
   out_879909740565667902[200] = 0;
   out_879909740565667902[201] = 0;
   out_879909740565667902[202] = 0;
   out_879909740565667902[203] = 0;
   out_879909740565667902[204] = 0;
   out_879909740565667902[205] = 0;
   out_879909740565667902[206] = 0;
   out_879909740565667902[207] = 0;
   out_879909740565667902[208] = 0;
   out_879909740565667902[209] = 1;
   out_879909740565667902[210] = 0;
   out_879909740565667902[211] = 0;
   out_879909740565667902[212] = 0;
   out_879909740565667902[213] = 0;
   out_879909740565667902[214] = 0;
   out_879909740565667902[215] = 0;
   out_879909740565667902[216] = 0;
   out_879909740565667902[217] = 0;
   out_879909740565667902[218] = 0;
   out_879909740565667902[219] = 0;
   out_879909740565667902[220] = 0;
   out_879909740565667902[221] = 0;
   out_879909740565667902[222] = 0;
   out_879909740565667902[223] = 0;
   out_879909740565667902[224] = 0;
   out_879909740565667902[225] = 0;
   out_879909740565667902[226] = 0;
   out_879909740565667902[227] = 0;
   out_879909740565667902[228] = 1;
   out_879909740565667902[229] = 0;
   out_879909740565667902[230] = 0;
   out_879909740565667902[231] = 0;
   out_879909740565667902[232] = 0;
   out_879909740565667902[233] = 0;
   out_879909740565667902[234] = 0;
   out_879909740565667902[235] = 0;
   out_879909740565667902[236] = 0;
   out_879909740565667902[237] = 0;
   out_879909740565667902[238] = 0;
   out_879909740565667902[239] = 0;
   out_879909740565667902[240] = 0;
   out_879909740565667902[241] = 0;
   out_879909740565667902[242] = 0;
   out_879909740565667902[243] = 0;
   out_879909740565667902[244] = 0;
   out_879909740565667902[245] = 0;
   out_879909740565667902[246] = 0;
   out_879909740565667902[247] = 1;
   out_879909740565667902[248] = 0;
   out_879909740565667902[249] = 0;
   out_879909740565667902[250] = 0;
   out_879909740565667902[251] = 0;
   out_879909740565667902[252] = 0;
   out_879909740565667902[253] = 0;
   out_879909740565667902[254] = 0;
   out_879909740565667902[255] = 0;
   out_879909740565667902[256] = 0;
   out_879909740565667902[257] = 0;
   out_879909740565667902[258] = 0;
   out_879909740565667902[259] = 0;
   out_879909740565667902[260] = 0;
   out_879909740565667902[261] = 0;
   out_879909740565667902[262] = 0;
   out_879909740565667902[263] = 0;
   out_879909740565667902[264] = 0;
   out_879909740565667902[265] = 0;
   out_879909740565667902[266] = 1;
   out_879909740565667902[267] = 0;
   out_879909740565667902[268] = 0;
   out_879909740565667902[269] = 0;
   out_879909740565667902[270] = 0;
   out_879909740565667902[271] = 0;
   out_879909740565667902[272] = 0;
   out_879909740565667902[273] = 0;
   out_879909740565667902[274] = 0;
   out_879909740565667902[275] = 0;
   out_879909740565667902[276] = 0;
   out_879909740565667902[277] = 0;
   out_879909740565667902[278] = 0;
   out_879909740565667902[279] = 0;
   out_879909740565667902[280] = 0;
   out_879909740565667902[281] = 0;
   out_879909740565667902[282] = 0;
   out_879909740565667902[283] = 0;
   out_879909740565667902[284] = 0;
   out_879909740565667902[285] = 1;
   out_879909740565667902[286] = 0;
   out_879909740565667902[287] = 0;
   out_879909740565667902[288] = 0;
   out_879909740565667902[289] = 0;
   out_879909740565667902[290] = 0;
   out_879909740565667902[291] = 0;
   out_879909740565667902[292] = 0;
   out_879909740565667902[293] = 0;
   out_879909740565667902[294] = 0;
   out_879909740565667902[295] = 0;
   out_879909740565667902[296] = 0;
   out_879909740565667902[297] = 0;
   out_879909740565667902[298] = 0;
   out_879909740565667902[299] = 0;
   out_879909740565667902[300] = 0;
   out_879909740565667902[301] = 0;
   out_879909740565667902[302] = 0;
   out_879909740565667902[303] = 0;
   out_879909740565667902[304] = 1;
   out_879909740565667902[305] = 0;
   out_879909740565667902[306] = 0;
   out_879909740565667902[307] = 0;
   out_879909740565667902[308] = 0;
   out_879909740565667902[309] = 0;
   out_879909740565667902[310] = 0;
   out_879909740565667902[311] = 0;
   out_879909740565667902[312] = 0;
   out_879909740565667902[313] = 0;
   out_879909740565667902[314] = 0;
   out_879909740565667902[315] = 0;
   out_879909740565667902[316] = 0;
   out_879909740565667902[317] = 0;
   out_879909740565667902[318] = 0;
   out_879909740565667902[319] = 0;
   out_879909740565667902[320] = 0;
   out_879909740565667902[321] = 0;
   out_879909740565667902[322] = 0;
   out_879909740565667902[323] = 1;
}
void h_4(double *state, double *unused, double *out_431308798891505486) {
   out_431308798891505486[0] = state[6] + state[9];
   out_431308798891505486[1] = state[7] + state[10];
   out_431308798891505486[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_15685884481912331) {
   out_15685884481912331[0] = 0;
   out_15685884481912331[1] = 0;
   out_15685884481912331[2] = 0;
   out_15685884481912331[3] = 0;
   out_15685884481912331[4] = 0;
   out_15685884481912331[5] = 0;
   out_15685884481912331[6] = 1;
   out_15685884481912331[7] = 0;
   out_15685884481912331[8] = 0;
   out_15685884481912331[9] = 1;
   out_15685884481912331[10] = 0;
   out_15685884481912331[11] = 0;
   out_15685884481912331[12] = 0;
   out_15685884481912331[13] = 0;
   out_15685884481912331[14] = 0;
   out_15685884481912331[15] = 0;
   out_15685884481912331[16] = 0;
   out_15685884481912331[17] = 0;
   out_15685884481912331[18] = 0;
   out_15685884481912331[19] = 0;
   out_15685884481912331[20] = 0;
   out_15685884481912331[21] = 0;
   out_15685884481912331[22] = 0;
   out_15685884481912331[23] = 0;
   out_15685884481912331[24] = 0;
   out_15685884481912331[25] = 1;
   out_15685884481912331[26] = 0;
   out_15685884481912331[27] = 0;
   out_15685884481912331[28] = 1;
   out_15685884481912331[29] = 0;
   out_15685884481912331[30] = 0;
   out_15685884481912331[31] = 0;
   out_15685884481912331[32] = 0;
   out_15685884481912331[33] = 0;
   out_15685884481912331[34] = 0;
   out_15685884481912331[35] = 0;
   out_15685884481912331[36] = 0;
   out_15685884481912331[37] = 0;
   out_15685884481912331[38] = 0;
   out_15685884481912331[39] = 0;
   out_15685884481912331[40] = 0;
   out_15685884481912331[41] = 0;
   out_15685884481912331[42] = 0;
   out_15685884481912331[43] = 0;
   out_15685884481912331[44] = 1;
   out_15685884481912331[45] = 0;
   out_15685884481912331[46] = 0;
   out_15685884481912331[47] = 1;
   out_15685884481912331[48] = 0;
   out_15685884481912331[49] = 0;
   out_15685884481912331[50] = 0;
   out_15685884481912331[51] = 0;
   out_15685884481912331[52] = 0;
   out_15685884481912331[53] = 0;
}
void h_10(double *state, double *unused, double *out_4633038553577825716) {
   out_4633038553577825716[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4633038553577825716[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4633038553577825716[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_5370661049739372457) {
   out_5370661049739372457[0] = 0;
   out_5370661049739372457[1] = 9.8100000000000005*cos(state[1]);
   out_5370661049739372457[2] = 0;
   out_5370661049739372457[3] = 0;
   out_5370661049739372457[4] = -state[8];
   out_5370661049739372457[5] = state[7];
   out_5370661049739372457[6] = 0;
   out_5370661049739372457[7] = state[5];
   out_5370661049739372457[8] = -state[4];
   out_5370661049739372457[9] = 0;
   out_5370661049739372457[10] = 0;
   out_5370661049739372457[11] = 0;
   out_5370661049739372457[12] = 1;
   out_5370661049739372457[13] = 0;
   out_5370661049739372457[14] = 0;
   out_5370661049739372457[15] = 1;
   out_5370661049739372457[16] = 0;
   out_5370661049739372457[17] = 0;
   out_5370661049739372457[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_5370661049739372457[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_5370661049739372457[20] = 0;
   out_5370661049739372457[21] = state[8];
   out_5370661049739372457[22] = 0;
   out_5370661049739372457[23] = -state[6];
   out_5370661049739372457[24] = -state[5];
   out_5370661049739372457[25] = 0;
   out_5370661049739372457[26] = state[3];
   out_5370661049739372457[27] = 0;
   out_5370661049739372457[28] = 0;
   out_5370661049739372457[29] = 0;
   out_5370661049739372457[30] = 0;
   out_5370661049739372457[31] = 1;
   out_5370661049739372457[32] = 0;
   out_5370661049739372457[33] = 0;
   out_5370661049739372457[34] = 1;
   out_5370661049739372457[35] = 0;
   out_5370661049739372457[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_5370661049739372457[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_5370661049739372457[38] = 0;
   out_5370661049739372457[39] = -state[7];
   out_5370661049739372457[40] = state[6];
   out_5370661049739372457[41] = 0;
   out_5370661049739372457[42] = state[4];
   out_5370661049739372457[43] = -state[3];
   out_5370661049739372457[44] = 0;
   out_5370661049739372457[45] = 0;
   out_5370661049739372457[46] = 0;
   out_5370661049739372457[47] = 0;
   out_5370661049739372457[48] = 0;
   out_5370661049739372457[49] = 0;
   out_5370661049739372457[50] = 1;
   out_5370661049739372457[51] = 0;
   out_5370661049739372457[52] = 0;
   out_5370661049739372457[53] = 1;
}
void h_13(double *state, double *unused, double *out_8528016009163002346) {
   out_8528016009163002346[0] = state[3];
   out_8528016009163002346[1] = state[4];
   out_8528016009163002346[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3227959709814245132) {
   out_3227959709814245132[0] = 0;
   out_3227959709814245132[1] = 0;
   out_3227959709814245132[2] = 0;
   out_3227959709814245132[3] = 1;
   out_3227959709814245132[4] = 0;
   out_3227959709814245132[5] = 0;
   out_3227959709814245132[6] = 0;
   out_3227959709814245132[7] = 0;
   out_3227959709814245132[8] = 0;
   out_3227959709814245132[9] = 0;
   out_3227959709814245132[10] = 0;
   out_3227959709814245132[11] = 0;
   out_3227959709814245132[12] = 0;
   out_3227959709814245132[13] = 0;
   out_3227959709814245132[14] = 0;
   out_3227959709814245132[15] = 0;
   out_3227959709814245132[16] = 0;
   out_3227959709814245132[17] = 0;
   out_3227959709814245132[18] = 0;
   out_3227959709814245132[19] = 0;
   out_3227959709814245132[20] = 0;
   out_3227959709814245132[21] = 0;
   out_3227959709814245132[22] = 1;
   out_3227959709814245132[23] = 0;
   out_3227959709814245132[24] = 0;
   out_3227959709814245132[25] = 0;
   out_3227959709814245132[26] = 0;
   out_3227959709814245132[27] = 0;
   out_3227959709814245132[28] = 0;
   out_3227959709814245132[29] = 0;
   out_3227959709814245132[30] = 0;
   out_3227959709814245132[31] = 0;
   out_3227959709814245132[32] = 0;
   out_3227959709814245132[33] = 0;
   out_3227959709814245132[34] = 0;
   out_3227959709814245132[35] = 0;
   out_3227959709814245132[36] = 0;
   out_3227959709814245132[37] = 0;
   out_3227959709814245132[38] = 0;
   out_3227959709814245132[39] = 0;
   out_3227959709814245132[40] = 0;
   out_3227959709814245132[41] = 1;
   out_3227959709814245132[42] = 0;
   out_3227959709814245132[43] = 0;
   out_3227959709814245132[44] = 0;
   out_3227959709814245132[45] = 0;
   out_3227959709814245132[46] = 0;
   out_3227959709814245132[47] = 0;
   out_3227959709814245132[48] = 0;
   out_3227959709814245132[49] = 0;
   out_3227959709814245132[50] = 0;
   out_3227959709814245132[51] = 0;
   out_3227959709814245132[52] = 0;
   out_3227959709814245132[53] = 0;
}
void h_14(double *state, double *unused, double *out_4581007164984635004) {
   out_4581007164984635004[0] = state[6];
   out_4581007164984635004[1] = state[7];
   out_4581007164984635004[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3978926740821396860) {
   out_3978926740821396860[0] = 0;
   out_3978926740821396860[1] = 0;
   out_3978926740821396860[2] = 0;
   out_3978926740821396860[3] = 0;
   out_3978926740821396860[4] = 0;
   out_3978926740821396860[5] = 0;
   out_3978926740821396860[6] = 1;
   out_3978926740821396860[7] = 0;
   out_3978926740821396860[8] = 0;
   out_3978926740821396860[9] = 0;
   out_3978926740821396860[10] = 0;
   out_3978926740821396860[11] = 0;
   out_3978926740821396860[12] = 0;
   out_3978926740821396860[13] = 0;
   out_3978926740821396860[14] = 0;
   out_3978926740821396860[15] = 0;
   out_3978926740821396860[16] = 0;
   out_3978926740821396860[17] = 0;
   out_3978926740821396860[18] = 0;
   out_3978926740821396860[19] = 0;
   out_3978926740821396860[20] = 0;
   out_3978926740821396860[21] = 0;
   out_3978926740821396860[22] = 0;
   out_3978926740821396860[23] = 0;
   out_3978926740821396860[24] = 0;
   out_3978926740821396860[25] = 1;
   out_3978926740821396860[26] = 0;
   out_3978926740821396860[27] = 0;
   out_3978926740821396860[28] = 0;
   out_3978926740821396860[29] = 0;
   out_3978926740821396860[30] = 0;
   out_3978926740821396860[31] = 0;
   out_3978926740821396860[32] = 0;
   out_3978926740821396860[33] = 0;
   out_3978926740821396860[34] = 0;
   out_3978926740821396860[35] = 0;
   out_3978926740821396860[36] = 0;
   out_3978926740821396860[37] = 0;
   out_3978926740821396860[38] = 0;
   out_3978926740821396860[39] = 0;
   out_3978926740821396860[40] = 0;
   out_3978926740821396860[41] = 0;
   out_3978926740821396860[42] = 0;
   out_3978926740821396860[43] = 0;
   out_3978926740821396860[44] = 1;
   out_3978926740821396860[45] = 0;
   out_3978926740821396860[46] = 0;
   out_3978926740821396860[47] = 0;
   out_3978926740821396860[48] = 0;
   out_3978926740821396860[49] = 0;
   out_3978926740821396860[50] = 0;
   out_3978926740821396860[51] = 0;
   out_3978926740821396860[52] = 0;
   out_3978926740821396860[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5326449587047095854) {
  err_fun(nom_x, delta_x, out_5326449587047095854);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_808033856261158562) {
  inv_err_fun(nom_x, true_x, out_808033856261158562);
}
void pose_H_mod_fun(double *state, double *out_4598941152447404033) {
  H_mod_fun(state, out_4598941152447404033);
}
void pose_f_fun(double *state, double dt, double *out_7845712062767557446) {
  f_fun(state,  dt, out_7845712062767557446);
}
void pose_F_fun(double *state, double dt, double *out_879909740565667902) {
  F_fun(state,  dt, out_879909740565667902);
}
void pose_h_4(double *state, double *unused, double *out_431308798891505486) {
  h_4(state, unused, out_431308798891505486);
}
void pose_H_4(double *state, double *unused, double *out_15685884481912331) {
  H_4(state, unused, out_15685884481912331);
}
void pose_h_10(double *state, double *unused, double *out_4633038553577825716) {
  h_10(state, unused, out_4633038553577825716);
}
void pose_H_10(double *state, double *unused, double *out_5370661049739372457) {
  H_10(state, unused, out_5370661049739372457);
}
void pose_h_13(double *state, double *unused, double *out_8528016009163002346) {
  h_13(state, unused, out_8528016009163002346);
}
void pose_H_13(double *state, double *unused, double *out_3227959709814245132) {
  H_13(state, unused, out_3227959709814245132);
}
void pose_h_14(double *state, double *unused, double *out_4581007164984635004) {
  h_14(state, unused, out_4581007164984635004);
}
void pose_H_14(double *state, double *unused, double *out_3978926740821396860) {
  H_14(state, unused, out_3978926740821396860);
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
