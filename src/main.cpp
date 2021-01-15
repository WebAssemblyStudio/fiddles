#define WASM_EXPORT __attribute__((visibility("default")))
#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <numeric>
#include <cmath>

WASM_EXPORT

int main() {
  return 42;
}

using ll=long long int;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class Fraction {
public:
  int numer;
  int denom;

  Fraction(const int numer_ = 0, const int denom_ = 1, const bool isNormalize = true) {
    numer = numer_;
    denom = denom_;
    if(isNormalize) normalize();
  }
  
  Fraction operator+(const Fraction &r) const {
    int denomGcd = std::gcd(denom, r.denom);
    int newNumer = numer * (r.denom / denomGcd) + r.numer * (denom / denomGcd);
    int newDenom = denom / denomGcd * r.denom;
    
    return Fraction(newNumer, newDenom, false);
  }
  
  Fraction operator-(const Fraction &r) const {
    return (*this) + (-r);
  }
  
  Fraction operator*(const Fraction &r) const {
    Fraction a(numer, r.denom);
    Fraction b(r.numer, denom);
    return Fraction(a.numer * b.numer, a.denom * b.denom, false);
  }
  
  Fraction operator/(const Fraction &r) const {
    return (*this) * (~r);
  }
  
  Fraction operator+() const {
    return Fraction(numer, denom, false);
  }
  
  Fraction operator-() const {
    return Fraction(-numer, denom, false);
  }
  
  Fraction operator~() const {
    return Fraction(denom, numer, false);
  }
  
  void normalize() {
    int numerSgn = sgn(numer) * sgn(denom);
    int numerAbs = std::abs(numer);
    int denomAbs = std::abs(denom);
    int gcd = std::gcd(numerAbs, denomAbs);
    
    numer = numerAbs / gcd * numerSgn;
    denom = denomAbs / gcd;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const Fraction& p);
};

std::ostream& operator<<(std::ostream& os, const Fraction& p) {
  os << p.numer << "/" << p.denom;
  return os;
}

using Coeffs=std::deque<Fraction>;

class Polynominal {
public:
  Coeffs coeffs;
  
  Polynominal() {
    coeffs.push_back(Fraction());
    coeffs.push_back(Fraction(1));
  }
  
  Polynominal(const Coeffs coeffs_) {
    coeffs = coeffs_;
  }
  
  Polynominal operator*(const Fraction& r) const {
    int largestDegree = getLargestDegree();
    Coeffs newCoeffs(largestDegree + 1);
    
    for(int degree = 0; degree <= largestDegree; ++degree) {
      newCoeffs[degree] = coeffs[degree] * r;
    }
    
    return Polynominal(newCoeffs);
  }
  
  Polynominal integerate() const {
    int largestDegree = getLargestDegree();
    Coeffs newCoeffs(largestDegree + 2);
    
    for(int degree = 0; degree <= largestDegree; ++degree) {
      newCoeffs[degree + 1] = coeffs[degree] * Fraction(1, degree + 1);
    }
    
    return Polynominal(newCoeffs);
  }
  
  int getLargestDegree() const {
    return coeffs.size() - 1;
  }
  
  Fraction getCoeffsSum() const {
    int largestDegree = getLargestDegree();
    Fraction sum;
    
    for(int degree = 0; degree <= largestDegree; ++degree) {
      sum = sum + coeffs[degree];
    }
    
    return sum;
  }
  
  std::string toString() {
    const int largestDegree = getLargestDegree();
    
    std::string ret = "";
    
    for(int degree = largestDegree; degree >= 0; --degree) {
      const Fraction coeff = coeffs[degree];
      const int numerSgn = sgn(coeff.numer);
      const int numerAbs = std::abs(coeff.numer);
      const int denom = coeff.denom;
      
      if(numerAbs == 0) continue;
      
      if(numerSgn < 0) ret += "-";
      else if(degree < largestDegree) ret += "+";
      
      if(denom != 1) ret += std::to_string(numerAbs) + "/" + std::to_string(denom);
      else if(numerAbs != 1 || degree == 0) ret += std::to_string(numerAbs);
      
      if(degree > 0) ret += "x";
      
      if(degree > 1) ret += "^" + std::to_string(degree);
    }
    
    return ret;
  }
  
  std::string toMathString() {
    const int largestDegree = getLargestDegree();
    
    std::string ret = "";
    
    for(int degree = largestDegree; degree >= 0; --degree) {
      const Fraction coeff = coeffs[degree];
      const int numerSgn = sgn(coeff.numer);
      const int numerAbs = std::abs(coeff.numer);
      const int denom = coeff.denom;
      
      if(numerAbs == 0) continue;
      
      if(numerSgn < 0) ret += "-";
      else if(degree < largestDegree) ret += "+";
      
      if(denom != 1) ret += "\\frac{" + std::to_string(numerAbs) + "}{" + std::to_string(denom) + "}";
      else if(numerAbs != 1 || degree == 0) ret += std::to_string(numerAbs);
      
      if(degree > 0) ret += "x";
      
      if(degree > 1) ret += "^{" + std::to_string(degree) + "}";
    }
    
    return ret;
  }
};

int getExponent(const Polynominal &polynominal) {
  return polynominal.getLargestDegree() - 1;
}

Polynominal increaseExponent(const Polynominal &originalPolynominal) {
  Polynominal newPolynominal = originalPolynominal.integerate() * Fraction(getExponent(originalPolynominal) + 1);
  newPolynominal.coeffs[1] = Fraction(1) - newPolynominal.getCoeffsSum();
  return newPolynominal;
}


// int main(){
//   Polynominal p;
//   std::cout<<getExponent(p)<<": "<<p.toString()<<std::endl;
  
//   for(int i = 0; i < 10; ++i) {
//     p = increaseExponent(p);
//     std::cout<<getExponent(p)<<": "<<p.toMathString()<<std::endl;
//   }
// }
