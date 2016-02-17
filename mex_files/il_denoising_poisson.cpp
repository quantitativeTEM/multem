/*
 * This file is part of MULTEM.
 * Copyright 2015 Ivan Lobato <Ivanlh20@gmail.com>
 *
 * MULTEM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MULTEM is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MULTEM. If not, see <http:// www.gnu.org/licenses/>.
 */

#include "types.cuh"
#include "matlab_types.cuh"
#include "stream.cuh"
#include "image_functions.cuh"

#include <mex.h>
#include "matlab_mex.cuh"

using multem::rmatrix_r;
using multem::rmatrix_c;
using multem::e_host;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[ ]) 
{
	auto Im = mx_get_matrix<rmatrix_r>(prhs[0]);
	auto nkr_w = mx_get_scalar<int>(prhs[1]);
	auto nkr_m = mx_get_scalar<int>(prhs[2]);

	auto Im_d = mx_create_matrix<rmatrix_r>(Im.rows, Im.cols, plhs[0]);

	multem::Stream<e_host> stream;
	stream.resize(4);
	multem::anscombe_forward(stream, Im, Im_d);
	multem::filter_wiener_2d(stream, Im_d.rows, Im_d.cols, Im_d, nkr_w, Im_d);
	if(nkr_m>0)
	{
		multem::filter_median_2d(stream, Im_d.rows, Im_d.cols, Im_d, nkr_m, Im_d);
	}
	multem::anscombe_inverse(stream, Im_d, Im_d);
}