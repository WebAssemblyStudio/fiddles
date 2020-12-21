declare function sayHello(): void;

sayHello();

export function calculateChar(script: string, cap: string, char: string, size: number): string {
  if (script !== 'normal') {
    // super, sub etc.
    size *= 0.5;
  } else if (!script || script === 'normal') {
    // normal with special cases
    if (cap === 'lowercase') {
      char = char.toLowerCase();
    } else if (cap === 'uppercase') {
      char = char.toUpperCase();
    } else if (cap === 'smallcase') {
      const upperCase = char.toUpperCase();
      if (upperCase !== char) {
        char = upperCase;
        size *= 0.7;
      }
    }
  }

  return char;
}

export function calculateSize(script: string, cap: string, char: string, size: number): f64 {
  if (script !== 'normal') {
    // super, sub etc.
    size *= 0.5;
  } else if (!script || script === 'normal') {
    // normal with special cases
    if (cap === 'lowercase') {
      char = char.toLowerCase();
    } else if (cap === 'uppercase') {
      char = char.toUpperCase();
    } else if (cap === 'smallcase') {
      const upperCase = char.toUpperCase();
      if (upperCase !== char) {
        char = upperCase;
        size *= 0.7;
      }
    }
  }

  return size;
}
