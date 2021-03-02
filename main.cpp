//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Put the assignment code here

class Quaternion {
  public:
    Quaternion(){
      coefficient1_ = 0.0;
      coefficient2_ = 0.0;
      coefficient3_ = 0.0;
      coefficient4_ = 0.0;
    };

    Quaternion(double coefficient1, double coefficient2, double coefficient3, double coefficient4){
      coefficient1_ = coefficient1;
      coefficient2_ = coefficient2;
      coefficient3_ = coefficient3;
      coefficient4_ = coefficient4;
    };
    
    double getCoefficient1() const {
      return coefficient1_;
    }

    double getCoefficient2() const {
      return coefficient2_;
    }

    double getCoefficient3() const {
      return coefficient3_;
    }

    double getCoefficient4() const {
      return coefficient4_;
    }

    bool operator== (const Quaternion& rhs) const { 
      return coefficient1_ == rhs.getCoefficient1() && 
             coefficient2_ == rhs.getCoefficient2() &&
             coefficient3_ == rhs.getCoefficient3() &&
             coefficient4_ == rhs.getCoefficient4();
    }

    Quaternion operator+ (const Quaternion& rhs) const {
      Quaternion q(coefficient1_ + rhs.getCoefficient1(), 
                   coefficient2_ + rhs.getCoefficient2(), 
                   coefficient3_ + rhs.getCoefficient3(), 
                   coefficient4_ + rhs.getCoefficient4());
      return q;
    }

    Quaternion operator- (const Quaternion& rhs) const {
      Quaternion p(coefficient1_ - rhs.getCoefficient1(), 
                   coefficient2_ - rhs.getCoefficient2(), 
                   coefficient3_ - rhs.getCoefficient3(), 
                   coefficient4_ - rhs.getCoefficient4());
      return p;
    }

    Quaternion operator* (const double& y) const {
      Quaternion t(coefficient1_ * y, 
                   coefficient2_ * y, 
                   coefficient3_ * y, 
                   coefficient4_ * y);
      return t;
    }
    
  private:
    double coefficient1_;
    double coefficient2_; 
    double coefficient3_;
    double coefficient4_;
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "q1" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        REQUIRE( q == p );
    }
    SECTION( "q2" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q + p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{0.0, 0.0, 0.0, 0.0};
        REQUIRE( (q - p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q * 2.0) == r );
    }
}
//------------------------------
