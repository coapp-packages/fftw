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
/* Generated on Tue Feb 21 19:00:19 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 6 -name n1bv_6 -include n1b.h */

/*
 * This function contains 18 FP additions, 8 FP multiplications,
 * (or, 12 additions, 2 multiplications, 6 fused multiply/add),
 * 23 stack variables, 2 constants, and 12 memory accesses
 */
#include "n1b.h"

static void n1bv_6(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T1, T2, T4, T5, T7, T8;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T5 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       T7 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       T8 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       {
		    V T3, Td, T6, Te, T9, Tf;
		    T3 = VSUB(T1, T2);
		    Td = VADD(T1, T2);
		    T6 = VSUB(T4, T5);
		    Te = VADD(T4, T5);
		    T9 = VSUB(T7, T8);
		    Tf = VADD(T7, T8);
		    {
			 V Tg, Ti, Ta, Tc, Th, Tb;
			 Tg = VADD(Te, Tf);
			 Ti = VMUL(LDK(KP866025403), VSUB(Te, Tf));
			 Ta = VADD(T6, T9);
			 Tc = VMUL(LDK(KP866025403), VSUB(T6, T9));
			 Th = VFNMS(LDK(KP500000000), Tg, Td);
			 ST(&(xo[0]), VADD(Td, Tg), ovs, &(xo[0]));
			 Tb = VFNMS(LDK(KP500000000), Ta, T3);
			 ST(&(xo[WS(os, 3)]), VADD(T3, Ta), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 4)]), VFMAI(Ti, Th), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 2)]), VFNMSI(Ti, Th), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 5)]), VFNMSI(Tc, Tb), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 1)]), VFMAI(Tc, Tb), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 6, XSIMD_STRING("n1bv_6"), {12, 2, 6, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_6) (planner *p) {
     X(kdft_register) (p, n1bv_6, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 6 -name n1bv_6 -include n1b.h */

/*
 * This function contains 18 FP additions, 4 FP multiplications,
 * (or, 16 additions, 2 multiplications, 2 fused multiply/add),
 * 19 stack variables, 2 constants, and 12 memory accesses
 */
#include "n1b.h"

static void n1bv_6(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V Ta, Td, T3, Te, T6, Tf, Tb, Tg, T8, T9;
	       T8 = LD(&(xi[0]), ivs, &(xi[0]));
	       T9 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       Ta = VSUB(T8, T9);
	       Td = VADD(T8, T9);
	       {
		    V T1, T2, T4, T5;
		    T1 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    T3 = VSUB(T1, T2);
		    Te = VADD(T1, T2);
		    T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T6 = VSUB(T4, T5);
		    Tf = VADD(T4, T5);
	       }
	       Tb = VADD(T3, T6);
	       Tg = VADD(Te, Tf);
	       ST(&(xo[WS(os, 3)]), VADD(Ta, Tb), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[0]), VADD(Td, Tg), ovs, &(xo[0]));
	       {
		    V T7, Tc, Th, Ti;
		    T7 = VBYI(VMUL(LDK(KP866025403), VSUB(T3, T6)));
		    Tc = VFNMS(LDK(KP500000000), Tb, Ta);
		    ST(&(xo[WS(os, 1)]), VADD(T7, Tc), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 5)]), VSUB(Tc, T7), ovs, &(xo[WS(os, 1)]));
		    Th = VFNMS(LDK(KP500000000), Tg, Td);
		    Ti = VBYI(VMUL(LDK(KP866025403), VSUB(Te, Tf)));
		    ST(&(xo[WS(os, 2)]), VSUB(Th, Ti), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 4)]), VADD(Ti, Th), ovs, &(xo[0]));
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 6, XSIMD_STRING("n1bv_6"), {16, 2, 2, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_6) (planner *p) {
     X(kdft_register) (p, n1bv_6, &desc);
}

#endif				/* HAVE_FMA */
