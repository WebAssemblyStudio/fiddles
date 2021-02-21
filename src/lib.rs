// Current prelude for using `wasm_bindgen`, and this'll get smaller over time!
#![feature(proc_macro, wasm_custom_section, wasm_import_module)]
extern crate wasm_bindgen;
use wasm_bindgen::prelude::*;

/*
 * A speed-improved simplex noise algorithm for 2D, 3D and 4D in Java.
 *
 * Based on example code by Stefan Gustavson (stegu@itn.liu.se).
 * Optimisations by Peter Eastman (peastman@drizzle.stanford.edu).
 * Better rank ordering method for 4D by Stefan Gustavson in 2012.
 *
 * This could be speeded up even further, but it's useful as it is.
 *
 * Version 2012-03-09
 *
 * This code was placed in the public domain by its original author,
 * Stefan Gustavson. You may use it as you see fit, but
 * attribution is appreciated.
 *
 */

// Simplex noise in 2D, 3D and 4D
	fn tesseract(
		x: f64
	) -> f64 {
    let x = x * x;

		x * x
	}

	// Gradient tuple: (x, y, z, w)
	type Grad = (i8, i8, i8, i8);

	const grad3: [Grad; 12] = [
		( 1,  1,  0,  0),
		(-1,  1,  0,  0),
		( 1, -1,  0,  0),
		(-1, -1,  0,  0),
		( 1,  0,  1,  0),
		(-1,  0,  1,  0),
		( 1,  0, -1,  0),
		(-1,  0, -1,  0),
		( 0,  1,  1,  0),
		( 0, -1,  1,  0),
		( 0,  1, -1,  0),
		( 0, -1, -1,  0)
	];

	const grad4: [Grad; 32] = [
		( 0,  1,  1,  1),
		( 0,  1,  1, -1),
		( 0,  1, -1,  1),
		( 0,  1, -1, -1),
		( 0, -1,  1,  1),
		( 0, -1,  1, -1),
		( 0, -1, -1,  1),
		( 0, -1, -1, -1),
		( 1,  0,  1,  1),
		( 1,  0,  1, -1),
		( 1,  0, -1,  1),
		( 1,  0, -1, -1),
		(-1,  0,  1,  1),
		(-1,  0,  1, -1),
		(-1,  0, -1,  1),
		(-1,  0, -1, -1),
		( 1,  1,  0,  1),
		( 1,  1,  0, -1),
		( 1, -1,  0,  1),
		( 1, -1,  0, -1),
		(-1,  1,  0,  1),
		(-1,  1,  0, -1),
		(-1, -1,  0,  1),
		(-1, -1,  0, -1),
		( 1,  1,  1,  0),
		( 1,  1, -1,  0),
		( 1, -1,  1,  0),
		( 1, -1, -1,  0),
		(-1,  1,  1,  0),
		(-1,  1, -1,  0),
		(-1, -1,  1,  0),
		(-1, -1, -1,  0)
	];

	// temporary lookup table
	const p: [u8; 0x100] = [
		0x97, 0xA0, 0x89, 0x5B, 0x5A, 0x0F, 0x83, 0x0D,
		0xC9, 0x5F, 0x60, 0x35, 0xC2, 0xE9, 0x07, 0xE1,
		0x8C, 0x24, 0x67, 0x1E, 0x45, 0x8E, 0x08, 0x63,
		0x25, 0xF0, 0x15, 0x0A, 0x17, 0xBE, 0x06, 0x94,
		0xF7, 0x78, 0xEA, 0x4B, 0x00, 0x1A, 0xC5, 0x3E,
		0x5E, 0xFC, 0xDB, 0xCB, 0x75, 0x23, 0x0B, 0x20,
		0x39, 0xB1, 0x21, 0x58, 0xED, 0x95, 0x38, 0x57,
		0xAE, 0x14, 0x7D, 0x88, 0xAB, 0xA8, 0x44, 0xAF,
		0x4A, 0xA5, 0x47, 0x86, 0x8B, 0x30, 0x1B, 0xA6,
		0x4D, 0x92, 0x9E, 0xE7, 0x53, 0x6F, 0xE5, 0x7A,
		0x3C, 0xD3, 0x85, 0xE6, 0xDC, 0x69, 0x5C, 0x29,
		0x37, 0x2E, 0xF5, 0x28, 0xF4, 0x66, 0x8F, 0x36,
		0x41, 0x19, 0x3F, 0xA1, 0x01, 0xD8, 0x50, 0x49,
		0xD1, 0x4C, 0x84, 0xBB, 0xD0, 0x59, 0x12, 0xA9,
		0xC8, 0xC4, 0x87, 0x82, 0x74, 0xBC, 0x9F, 0x56,
		0xA4, 0x64, 0x6D, 0xC6, 0xAD, 0xBA, 0x03, 0x40,
		0x34, 0xD9, 0xE2, 0xFA, 0x7C, 0x7B, 0x05, 0xCA,
		0x26, 0x93, 0x76, 0x7E, 0xFF, 0x52, 0x55, 0xD4,
		0xCF, 0xCE, 0x3B, 0xE3, 0x2F, 0x10, 0x3A, 0x11,
		0xB6, 0xBD, 0x1C, 0x2A, 0xDF, 0xB7, 0xAA, 0xD5,
		0x77, 0xF8, 0x98, 0x02, 0x2C, 0x9A, 0xA3, 0x46,
		0xDD, 0x99, 0x65, 0x9B, 0xA7, 0x2B, 0xAC, 0x09,
		0x81, 0x16, 0x27, 0xFD, 0x13, 0x62, 0x6C, 0x6E,
		0x4F, 0x71, 0xE0, 0xE8, 0xB2, 0xB9, 0x70, 0x68,
		0xDA, 0xF6, 0x61, 0xE4, 0xFB, 0x22, 0xF2, 0xC1,
		0xEE, 0xD2, 0x90, 0x0C, 0xBF, 0xB3, 0xA2, 0xF1,
		0x51, 0x33, 0x91, 0xEB, 0xF9, 0x0E, 0xEF, 0x6B,
		0x31, 0xC0, 0xD6, 0x1F, 0xB5, 0xC7, 0x6A, 0x9D,
		0xB8, 0x54, 0xCC, 0xB0, 0x73, 0x79, 0x32, 0x2D,
		0x7F, 0x04, 0x96, 0xFE, 0x8A, 0xEC, 0xCD, 0x5D,
		0xDE, 0x72, 0x43, 0x1D, 0x18, 0x48, 0xF3, 0x8D,
		0x80, 0xC3, 0x4E, 0x42, 0xD7, 0x3D, 0x9C, 0xB4
	];

	// To remove the need for index wrapping, double the permutation table length
	static mut perm: [u8; 0x200] = [0; 0x200];
	static mut permMod12: [u8; 0x200] = [0; 0x200];

	// Skewing and unskewing factors for 2, 3, and 4 dimensions
	static mut F2: f64 = 0.0;
	static mut G2: f64 = 0.0;
	static mut F3: f64 = 0.0;
	static mut G3: f64 = 0.0;
	static mut F4: f64 = 0.0;
	static mut G4: f64 = 0.0;

	pub unsafe fn init() {
		F2 = (f64::sqrt(3.0) - 1.0) / 2.0;
		G2 = (3.0 - f64::sqrt(3.0)) / 6.0;
		F3 = 1.0 / 3.0;
		G3 = 1.0 / 6.0;
		F4 = (f64::sqrt(5.0) - 1.0) / 4.0;
		G4 = (5.0 - f64::sqrt(5.0)) / 20.0;

		// copy p[] into first and second half of perm
		for i in 0x0_usize..0x200 {
			let temp = p[i & 0xFF]; // wrap back to start of `p`
			perm[i] = temp;
			permMod12[i] = temp % 12;
		}
	}

	// This method is a *lot* faster than using (int)Math.floor(x)
	fn fastfloor(
		x: f64
	) -> i32 {
		let xi: i32 = x as i32;

		xi - (x < xi as f64) as i32
	}

	fn dot_2D(
		// grad_2
		g: &Grad,
		x: f64,
		y: f64
	) -> f64 {
		g.0 as f64 * x + g.1 as f64 * y
	}

	fn dot_3D(
		// grad_3
		g: &Grad,
		x: f64,
		y: f64,
		z: f64
	) -> f64 {
		g.0 as f64 * x + g.1 as f64 * y + g.2 as f64 * z
	}

	fn dot_4D(
		// grad_4
		g: &Grad,
		x: f64,
		y: f64,
		z: f64,
		w: f64
	) -> f64 {
		g.0 as f64 * x + g.1 as f64 * y + g.2 as f64 * z + g.3 as f64 * w
	}

	// 2D simplex noise
	#[wasm_bindgen]
  pub fn noise_2D(
		xin: f64,
		yin: f64
	) -> f64 {
		unsafe {
    // Skew the input space to determine which simplex cell we're in
		let (i, j): (i32, i32) = {
			let s: f64 = (xin + yin) * F2; // Hairy factor for 2D

			(fastfloor(xin + s), fastfloor(yin + s))
		};

		let (X0, Y0): (f64, f64) = {
			let t: f64 = (i + j) as f64 * G2;

			// Unskew the cell origin back to (x, y) space
			(i as f64 - t, j as f64 - t)
		};

		let x0: f64 = xin - X0; // The x, y distances from the cell origin
		let y0: f64 = yin - Y0;
		// For the 2D case, the simplex shape is an equilateral triangle.
		// Determine which simplex we are in.

		// A step of (1, 0) in (i, j) means a step of (1 - c, -c) in (x, y), and
		// a step of (0, 1) in (i, j) means a step of (-c, 1 - c) in (x, y), where
		// c = (3 - sqrt(3)) / 6

		// Work out the hashed gradient indices of the three simplex corners
		let ii: u8 = (i & 0xFF) as u8;
		let jj: u8 = (j & 0xFF) as u8;
		// Calculate the contribution from the three corners

		// Noise contributions from the three corners, n0..n2

		let n0: f64 = {
			let t0: f64 = 0.5 - x0 * x0 - y0 * y0;

			if t0 < 0.0 {
				0.0
			} else {
				let gi0: u8 = permMod12[ii as usize + perm[jj as usize] as usize];

				tesseract(t0) * dot_2D(&grad3[gi0 as usize], x0, y0) // (x, y) of grad3 used for 2D gradient
			}
		};

		let n1: f64 = {
			// Offsets for second (middle) corner of simplex in (i, j) coords

			let (i1, j1): (u8, u8) =
			if x0 > y0 {
				// lower triangle, XY order: (0, 0)->(1, 0)->(1, 1)
				(1, 0)
			} else {
				// upper triangle, YX order: (0, 0)->(0, 1)->(1, 1)
				(0, 1)
			};

			let x1: f64 = x0 - i1 as f64 + G2; // Offsets for middle corner in (x, y) unskewed coords
			let y1: f64 = y0 - j1 as f64 + G2;

			let t1: f64 = 0.5 - x1 * x1 - y1 * y1;

			if t1 < 0.0 {
				0.0
			} else {
				let gi1: u8 = permMod12[ii as usize + i1 as usize + perm[jj as usize + j1 as usize] as usize];

				tesseract(t1) * dot_2D(&grad3[gi1 as usize], x1, y1)
			}
		};

		let n2: f64 = {
			let x2: f64 = x0 - 1.0 + 2.0 * G2; // Offsets for last corner in (x, y) unskewed coords
			let y2: f64 = y0 - 1.0 + 2.0 * G2;
			let t2: f64 = 0.5 - x2 * x2 - y2 * y2;

			if t2 < 0.0 {
				0.0
			} else {
				let gi2: u8 = permMod12[ii as usize + 1 + perm[jj as usize + 1] as usize];

				tesseract(t2) * dot_2D(&grad3[gi2 as usize], x2, y2)
			}
		};

		// Add contributions from each corner to get the final noise value.
		// The result is scaled to return values in the i32erval [-1, 1].
		70.0 * (n0 + n1 + n2)
    }
	}

	// 3D simplex noise
	#[wasm_bindgen]
  pub fn noise_3D(
		xin: f64,
		yin: f64,
		zin: f64
	) -> f64 {
    unsafe {
		// Skew the input space to determine which simplex cell we're in
		let (i, j, k): (i32, i32, i32) = {
			let s: f64 = (xin + yin + zin) * F3; // Very nice and simple skew factor for 3D

			(fastfloor(xin + s), fastfloor(yin + s), fastfloor(zin + s))
		};

		let (X0, Y0, Z0): (f64, f64, f64) = {
			let t: f64 = (i + j + k) as f64 * G3;

			// Unskew the cell origin back to (x, y, z) space
			(i as f64 - t, j as f64 - t, k as f64 - t)
		};

		let x0: f64 = xin - X0; // The x, y, z distances from the cell origin
		let y0: f64 = yin - Y0;
		let z0: f64 = zin - Z0;
		// For the 3D case, the simplex shape is a slightly irregular tetrahedron.
		// Determine which simplex we are in.

		// (i1, j1, k1): Offsets for second corner of simplex in (i, j, k) coords
		// (i2, j2, k2): Offsets for third corner of simplex in (i, j, k) coords

		let (i1, j1, k1, i2, j2, k2): (u8, u8, u8, u8, u8, u8) =
		if x0 >= y0 {
			if y0 >= z0 {
				// X Y Z order
				(1, 0, 0, 1, 1, 0)
			} else if x0 >= z0 {
				// X Z Y order
				(1, 0, 0, 1, 0, 1)
			} else {
				// Z X Y order
				(0, 0, 1, 1, 0, 1)
			}
		} else {
			// x0 < y0
			if y0 < z0 {
				// Z Y X order
				(0, 0, 1, 0, 1, 1)
			} else if x0 < z0 {
				// Y Z X order
				(0, 1, 0, 0, 1, 1)
			} else {
				// Y X Z order
				(0, 1, 0, 1, 1, 0)
			}
		};

		// A step of (1, 0, 0) in (i, j, k) means a step of (1 - c,    -c,    -c) in (x, y, z),
		// a step of (0, 1, 0) in (i, j, k) means a step of (   -c, 1 - c,    -c) in (x, y, z), and
		// a step of (0, 0, 1) in (i, j, k) means a step of (   -c,    -c, 1 - c) in (x, y, z), where
		// c = 1 / 6.

		// Work out the hashed gradient indices of the four simplex corners
		let ii: u8 = (i & 0xFF) as u8;
		let jj: u8 = (j & 0xFF) as u8;
		let kk: u8 = (k & 0xFF) as u8;

		// Calculate the contribution from the four corners

		let n0: f64 = {
			let t0: f64 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0;

			if t0 < 0.0 {
				0.0
			} else {
				let gi0: u8 = permMod12[ii as usize + perm[jj as usize + perm[kk as usize] as usize] as usize];

				tesseract(t0) * dot_3D(&grad3[gi0 as usize], x0, y0, z0)
			}
		};

		let n1: f64 = {
			let x1: f64 = x0 - i1 as f64 + G3; // Offsets for second corner in (x, y, z) coords
			let y1: f64 = y0 - j1 as f64 + G3;
			let z1: f64 = z0 - k1 as f64 + G3;

			let t1: f64 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1;

			if t1 < 0.0 {
				0.0
			} else {
				let gi1: u8 = permMod12[ii as usize + i1 as usize + perm[jj as usize + j1 as usize + perm[kk as usize + k1 as usize] as usize] as usize];

				tesseract(t1) * dot_3D(&grad3[gi1 as usize], x1, y1, z1)
			}
		};

		let n2: f64 = {
			let x2: f64 = x0 - i2 as f64 + 2.0 * G3; // Offsets for third corner in (x, y, z) coords
			let y2: f64 = y0 - j2 as f64 + 2.0 * G3;
			let z2: f64 = z0 - k2 as f64 + 2.0 * G3;

			let t2: f64 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2;

			if t2 < 0.0 {
				0.0
			} else {
				let gi2: u8 = permMod12[ii as usize + i2 as usize + perm[jj as usize + j2 as usize + perm[kk as usize + k2 as usize] as usize] as usize];

				tesseract(t2) * dot_3D(&grad3[gi2 as usize], x2, y2, z2)
			}
		};

		let n3: f64 = {
			let x3: f64 = x0 - 1.0 + 3.0 * G3; // Offsets for last corner in (x, y, z) coords
			let y3: f64 = y0 - 1.0 + 3.0 * G3;
			let z3: f64 = z0 - 1.0 + 3.0 * G3;

			let t3: f64 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3;

			if t3 < 0.0 {
				0.0
			} else {
				let gi3: u8 = permMod12[ii as usize + 1 + perm[jj as usize + 1 + perm[kk as usize + 1] as usize] as usize];

				tesseract(t3) * dot_3D(&grad3[gi3 as usize], x3, y3, z3)
			}
		};

		// Add contributions from each corner to get the final noise value.
		// The result is scaled to stay just inside [-1, 1]
		32.0 * (n0 + n1 + n2 + n3)
    }
	}

	// 4D simplex noise, better simplex rank ordering method 2012-03-09
	#[wasm_bindgen]
  pub fn noise_4D(
		x: f64,
		y: f64,
		z: f64,
		w: f64
	) -> f64 {
    unsafe {
		// Skew the (x, y, z, w) space to determine which cell of 24 simplices we're in
		let (i, j, k, l): (i32, i32, i32, i32) = {
			let s: f64 = (x + y + z + w) * F4; // Factor for 4D skewing

			(fastfloor(x + s), fastfloor(y + s), fastfloor(z + s), fastfloor(w + s))
		};

		let (W0, Z0, Y0, X0): (f64, f64, f64, f64) = {
			let t: f64 = (i + j + k + l) as f64 * G4; // Factor for 4D unskewing

			// Unskew the cell origin back to (x, y, z, w) space
			(i as f64 - t, j as f64 - t, k as f64 - t, l as f64 - t)
		};

		let x0: f64 = x - X0; // The x, y, z, w distances from the cell origin
		let y0: f64 = y - Y0;
		let z0: f64 = z - Z0;
		let w0: f64 = w - W0;

		let (i1, j1, k1, l1, i2, j2, k2, l2, i3, j3, k3, l3): (u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8) = {
			// For the 4D case, the simplex is a 4D shape I won't even try to describe.
			// To find out which of the 24 possible simplices we're in, we need to
			// determine the magnitude ordering of x0, y0, z0 and w0.
			// Six pair-wise comparisons are performed between each possible pair
			// of the four coordinates, and the results are used to rank the numbers.
			let mut rankx: u8 = 0;
			let mut ranky: u8 = 0;
			let mut rankz: u8 = 0;
			let mut rankw: u8 = 0;

			*if x0 > y0 { &mut rankx } else { &mut ranky } += 1;
			*if x0 > z0 { &mut rankx } else { &mut rankz } += 1;
			*if x0 > w0 { &mut rankx } else { &mut rankw } += 1;
			*if y0 > z0 { &mut ranky } else { &mut rankz } += 1;
			*if y0 > w0 { &mut ranky } else { &mut rankw } += 1;
			*if z0 > w0 { &mut rankz } else { &mut rankw } += 1;

			// [rankx, ranky, rankz, rankw] is a 4-vector with the numbers 0, 1, 2 and 3
			// in some order. We use a thresholding to set the coordinates in turn.
			// The integer offsets for the second simplex corner
			// Rank 3 denotes the largest coordinate.
			(
				(rankx >= 3) as u8,
				(ranky >= 3) as u8,
				(rankz >= 3) as u8,
				(rankw >= 3) as u8,
				// The integer offsets for the third simplex corner
				// Rank 2 denotes the second largest coordinate.
				(rankx >= 2) as u8,
				(ranky >= 2) as u8,
				(rankz >= 2) as u8,
				(rankw >= 2) as u8,
				// The integer offsets for the fourth simplex corner
				// Rank 1 denotes the second smallest coordinate.
				(rankx >= 1) as u8,
				(ranky >= 1) as u8,
				(rankz >= 1) as u8,
				(rankw >= 1) as u8
			)
		};
		// The fifth corner has all coordinate offsets = 1, so no need to compute that.

		// Work out the hashed gradient indices of the five simplex corners
		let ii: u8 = (i & 0xFF) as u8;
		let jj: u8 = (j & 0xFF) as u8;
		let kk: u8 = (k & 0xFF) as u8;
		let ll: u8 = (l & 0xFF) as u8;

		// Calculate the contribution from the five corners
		let n0: f64 = {
			let t0: f64 = 0.6 - x0 * x0 - y0 * y0 - z0 * z0 - w0 * w0;

			if t0 < 0.0 {
				0.0
			} else {
				let gi0: u8 = perm[ii as usize + perm[jj as usize + perm[kk as usize + perm[ll as usize] as usize] as usize] as usize] % 32;

				tesseract(t0) * dot_4D(&grad4[gi0 as usize], x0, y0, z0, w0)
			}
		};

		let n1: f64 = {
			let x1: f64 = x0 - i1 as f64 + G4; // Offsets for second corner in (x, y, z, w) coords
			let y1: f64 = y0 - j1 as f64 + G4;
			let z1: f64 = z0 - k1 as f64 + G4;
			let w1: f64 = w0 - l1 as f64 + G4;

			let t1: f64 = 0.6 - x1 * x1 - y1 * y1 - z1 * z1 - w1 * w1;

			if t1 < 0.0 {
				0.0
			} else {
				let gi1: u8 = perm[ii as usize + i1 as usize + perm[jj as usize + j1 as usize + perm[kk as usize + k1 as usize + perm[ll as usize + l1 as usize] as usize] as usize] as usize] % 32;

				tesseract(t1) * dot_4D(&grad4[gi1 as usize], x1, y1, z1, w1)
			}
		};

		let n2: f64 = {
			let x2: f64 = x0 - i2 as f64 + 2.0 * G4; // Offsets for third corner in (x, y, z, w) coords
			let y2: f64 = y0 - j2 as f64 + 2.0 * G4;
			let z2: f64 = z0 - k2 as f64 + 2.0 * G4;
			let w2: f64 = w0 - l2 as f64 + 2.0 * G4;

			let t2: f64 = 0.6 - x2 * x2 - y2 * y2 - z2 * z2 - w2 * w2;

			if t2 < 0.0 {
				0.0
			} else {
				let gi2: u8 = perm[ii as usize + i2 as usize + perm[jj as usize + j2 as usize + perm[kk as usize + k2 as usize + perm[ll as usize + l2 as usize] as usize] as usize] as usize] % 32;

				tesseract(t2) * dot_4D(&grad4[gi2 as usize], x2, y2, z2, w2)
			}
		};

		let n3: f64 = {
			let x3: f64 = x0 - i3 as f64 + 3.0 * G4; // Offsets for fourth corner in (x, y, z, w) coords
			let y3: f64 = y0 - j3 as f64 + 3.0 * G4;
			let z3: f64 = z0 - k3 as f64 + 3.0 * G4;
			let w3: f64 = w0 - l3 as f64 + 3.0 * G4;

			let t3: f64 = 0.6 - x3 * x3 - y3 * y3 - z3 * z3 - w3 * w3;

			if t3 < 0.0 {
				0.0
			} else {
				let gi3: u8 = perm[ii as usize + i3 as usize + perm[jj as usize + j3 as usize + perm[kk as usize + k3 as usize + perm[ll as usize + l3 as usize] as usize] as usize] as usize] % 32;

				tesseract(t3) * dot_4D(&grad4[gi3 as usize], x3, y3, z3, w3)
			}
		};

		let n4: f64 = {
			let x4: f64 = x0 - 1.0 + 4.0 * G4; // Offsets for last corner in (x, y, z, w) coords
			let y4: f64 = y0 - 1.0 + 4.0 * G4;
			let z4: f64 = z0 - 1.0 + 4.0 * G4;
			let w4: f64 = w0 - 1.0 + 4.0 * G4;

			let t4: f64 = 0.6 - x4 * x4 - y4 * y4 - z4 * z4 - w4 * w4;

			if t4 < 0.0 {
				0.0
			} else {
				let gi4: u8 = perm[ii as usize + 1 + perm[jj as usize + 1 + perm[kk as usize + 1 + perm[ll as usize + 1] as usize] as usize] as usize] % 32;

				tesseract(t4) * dot_4D(&grad4[gi4 as usize], x4, y4, z4, w4)
			}
		};

		// Sum up and scale the result to cover the range [-1, 1]
		27.0 * (n0 + n1 + n2 + n3 + n4)
    }
	}

#[wasm_bindgen]
pub fn main() {
  unsafe {
    init();
  }
}
