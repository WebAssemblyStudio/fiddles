/**
	@struct A fast, deterministic, seedable random number generator.
	@description Unlike the native random number generator built into most browsers, this one is deterministic, and so it will produce the same sequence of outputs each time it is given the same seed. It is based on George Marsaglia's MWC algorithm from the v8 Javascript engine. 
*/
pub struct SeedableRandom {
    x: i32,
    y: i32,
}

impl SeedableRandom {
    pub fn new() -> SeedableRandom {
        SeedableRandom {
            x: 0,
		    y: 0,
        }
    }

    /**
		Get the next random number between 0 and 1 in the current sequence.
	*/
    pub fn next(&mut self) -> f64 {
        if self.x == 0 {
            self.x = (0xFFFFFFFF as u32) as i32;
        } 

        if self.y == 0 {
            self.y = (0xFFFFFFFF as u32) as i32;
        } 
            
		self.x = self.next_x();
		self.y = self.next_y();

		((((self.x << 16) + (self.y as u32 & 0xFFFF) as i32) as f64 / (0xFFFFFFFF as u32) as f64)) + 0.5
    }

    /**
		Get the next random integer in the current sequence.
		@param a The lower bound of integers (inclusive).
		@param b The upper bound of integers (exclusive).
	*/
    pub fn next_int(&mut self, a: i32, b: i32) -> i32 {
        let mut a = a;
        let mut b = b;
        if b == 0 {
            a = 0;
            b = (0xFFFFFFFF as u32) as i32;
        }
        
        // fetch an integer between a and b inclusive
        (self.next() * (b - a) as f64) as i32 + a
    }

    /**
		Seed the random number generator. The same seed will always yield the same sequence. Seed with the current time if you want it to vary each time.
		@param x The seed.
	*/
    pub fn seed(&mut self, x: i32) {
        self.x = x * 3253;
		self.y = self.next_x();
    }

    /**
		Seed the random number generator with a two dimensional seed.
		@param x First seed.
		@param y Second seed.
	*/
	pub fn seed_2d(&mut self, x: i32, y: i32) {
		self.x = x * 2549 + y * 3571;
		self.y = y * 2549 + x * 3571;
	}
	
	/**
		Seed the random number generator with a three dimensional seed.
		@param x First seed.
		@param y Second seed.
		@param z Third seed.
	*/
	pub fn seed_3d(&mut self, x: i32, y: i32, z: i32) {
		self.x = x * 2549 + y * 3571 + z * 3253;
		self.y = x * 3253 + y * 2549 + z * 3571;
	}

    fn next_x(&self) -> i32 {
        (36969 * (self.x as u32 & 0xFFFF)) as i32 + (self.x >> 16)
    }

    fn next_y(&self) -> i32 {
        (18273 * (self.y as u32 & 0xFFFF)) as i32 + (self.y >> 16)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_random_with_seed() {
        let mut rand_gen = SeedableRandom::new();
        rand_gen.seed(123456);
        println!("--> {}", rand_gen.next_int(101, 200));
        println!("--> {}", rand_gen.next_int(101, 200));
        println!("--> {}", rand_gen.next_int(101, 200));
        println!("--> {}", rand_gen.next_int(101, 200));
        println!("--> {}", rand_gen.next_int(101, 200));
    }
}