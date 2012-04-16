/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Feb 21 19:00:14 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 7 -name n1fv_7 -include n1f.h */

/*
 * This function contains 30 FP additions, 24 FP multiplications,
 * (or, 9 additions, 3 multiplications, 21 fused multiply/add),
 * 37 stack variables, 6 constants, and 14 memory accesses
 */
#include "n1f.h"

static void n1fv_7(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DVK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP356895867, +0.356895867892209443894399510021300583399127187);
     DVK(KP554958132, +0.554958132087371191422194871006410481067288862);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T1, T2, T3, T8, T9, T5, T6;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T3 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
	       T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       T9 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       T5 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T6 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       {
		    V Te, T4, Tf, Ta, Tg, T7;
		    Te = VSUB(T3, T2);
		    T4 = VADD(T2, T3);
		    Tf = VSUB(T9, T8);
		    Ta = VADD(T8, T9);
		    Tg = VSUB(T6, T5);
		    T7 = VADD(T5, T6);
		    {
			 V Tm, Tb, Tr, Th, Tj, To;
			 Tm = VFMA(LDK(KP554958132), Tf, Te);
			 Tb = VFNMS(LDK(KP356895867), T4, Ta);
			 Tr = VFNMS(LDK(KP554958132), Te, Tg);
			 Th = VFMA(LDK(KP554958132), Tg, Tf);
			 ST(&(xo[0]), VADD(T1, VADD(T4, VADD(T7, Ta))), ovs, &(xo[0]));
			 Tj = VFNMS(LDK(KP356895867), T7, T4);
			 To = VFNMS(LDK(KP356895867), Ta, T7);
			 {
			      V Tn, Tc, Ts, Ti;
			      Tn = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), Tm, Tg));
			      Tc = VFNMS(LDK(KP692021471), Tb, T7);
			      Ts = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tr, Tf));
			      Ti = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Th, Te));
			      {
				   V Tk, Tp, Td, Tl, Tq;
				   Tk = VFNMS(LDK(KP692021471), Tj, Ta);
				   Tp = VFNMS(LDK(KP692021471), To, T4);
				   Td = VFNMS(LDK(KP900968867), Tc, T1);
				   Tl = VFNMS(LDK(KP900968867), Tk, T1);
				   Tq = VFNMS(LDK(KP900968867), Tp, T1);
				   ST(&(xo[WS(os, 2)]), VFMAI(Ti, Td), ovs, &(xo[0]));
				   ST(&(xo[WS(os, 5)]), VFNMSI(Ti, Td), ovs, &(xo[WS(os, 1)]));
				   ST(&(xo[WS(os, 1)]), VFMAI(Tn, Tl), ovs, &(xo[WS(os, 1)]));
				   ST(&(xo[WS(os, 6)]), VFNMSI(Tn, Tl), ovs, &(xo[0]));
				   ST(&(xo[WS(os, 3)]), VFMAI(Ts, Tq), ovs, &(xo[WS(os, 1)]));
				   ST(&(xo[WS(os, 4)]), VFNMSI(Ts, Tq), ovs, &(xo[0]));
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 7, XSIMD_STRING("n1fv_7"), {9, 3, 21, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_7) (planner *p) {
     X(kdft_register) (p, n1fv_7, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 7 -name n1fv_7 -include n1f.h */

/*
 * This function contains 30 FP additions, 18 FP multiplications,
 * (or, 18 additions, 6 multiplications, 12 fused multiply/add),
 * 24 stack variables, 6 constants, and 14 memory accesses
 */
#include "n1f.h"

static void n1fv_7(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DVK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DVK(KP781831482, +0.781831482468029808708444526674057750232334519);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP433883739, +0.433883739117558120475768332848358754609990728);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T1, Ta, Td, T4, Tc, T7, Te, T8, T9, Tj, Ti;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       T9 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       Ta = VADD(T8, T9);
	       Td = VSUB(T9, T8);
	       {
		    V T2, T3, T5, T6;
		    T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T3 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    T4 = VADD(T2, T3);
		    Tc = VSUB(T3, T2);
		    T5 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T6 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    T7 = VADD(T5, T6);
		    Te = VSUB(T6, T5);
	       }
	       ST(&(xo[0]), VADD(T1, VADD(T4, VADD(T7, Ta))), ovs, &(xo[0]));
	       Tj = VBYI(VFMA(LDK(KP433883739), Tc, VFNMS(LDK(KP781831482), Te, VMUL(LDK(KP974927912), Td))));
	       Ti = VFMA(LDK(KP623489801), T7, VFNMS(LDK(KP222520933), Ta, VFNMS(LDK(KP900968867), T4, T1)));
	       ST(&(xo[WS(os, 4)]), VSUB(Ti, Tj), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 3)]), VADD(Ti, Tj), ovs, &(xo[WS(os, 1)]));
	       {
		    V Tf, Tb, Th, Tg;
		    Tf = VBYI(VFNMS(LDK(KP781831482), Td, VFNMS(LDK(KP433883739), Te, VMUL(LDK(KP974927912), Tc))));
		    Tb = VFMA(LDK(KP623489801), Ta, VFNMS(LDK(KP900968867), T7, VFNMS(LDK(KP222520933), T4, T1)));
		    ST(&(xo[WS(os, 5)]), VSUB(Tb, Tf), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 2)]), VADD(Tb, Tf), ovs, &(xo[0]));
		    Th = VBYI(VFMA(LDK(KP781831482), Tc, VFMA(LDK(KP974927912), Te, VMUL(LDK(KP433883739), Td))));
		    Tg = VFMA(LDK(KP623489801), T4, VFNMS(LDK(KP900968867), Ta, VFNMS(LDK(KP222520933), T7, T1)));
		    ST(&(xo[WS(os, 6)]), VSUB(Tg, Th), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 1)]), VADD(Tg, Th), ovs, &(xo[WS(os, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 7, XSIMD_STRING("n1fv_7"), {18, 6, 12, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_7) (planner *p) {
     X(kdft_register) (p, n1fv_7, &desc);
}

#endif				/* HAVE_FMA */
