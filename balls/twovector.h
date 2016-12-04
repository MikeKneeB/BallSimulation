#ifndef TWOVECTOR_H
#define TWOVECTOR_H

#include <string>

/**
 * @brief The TwoVector class
 *
 * @author Mike Knee
 * @date 04/11/2016
 *
 * The TwoVector class describes a two dimensional vector with double
 * components. It has basic vector operations along with other operators for
 * addition and scalar multiplication,
 */
class TwoVector
{
public:
    /**
     * @brief TwoVector empty constructor.
     *
     * Does not initiliase values.
     */
    TwoVector();
    /**
     * @brief TwoVector parameter constructor.
     *
     * Initialises vector with values x and y.
     *
     * @param x: double x component.
     * @param y: double y component.
     */
    TwoVector(double x, double y);
    /**
     * @brief Twovector destructor.
     *
     * Does nothing, as no heap memory used by this class.
     */
    ~TwoVector();

    /**
     * @brief Modulus
     *
     * Calculates the modulus of the vector.
     *
     * @return double this vector's modulus.
     */
    double Modulus();
    /**
     * @brief Argument
     *
     * Calculates the angle between the vector and x-axis.
     *
     * @return double this vector's argument.
     */
    double Argument();
    /**
     * @brief Dot
     *
     * Calculates the dot product of this vector with another vector.
     *
     * @param second: TwoVector to dot this with.
     * @return double dot product of this with second.
     */
    double Dot(TwoVector second);
    /**
     * @brief Rotate
     *
     * Returns this vector rotated around angle radians, anti-clockwise.
     *
     * @param radians: double angle in radians to rotate angle by.
     * @return TwoVector this rotated anti-clockwise by radians.
     */
    TwoVector Rotate(double radians);

    //Getters and setters.
    inline double GetX() const { return fX; }
    inline double GetY() const { return fY; }

    inline void SetX(double x) { fX = x; }
    inline void SetY(double y) { fY = y; }
    inline void SetBoth(double x, double y) { fX = x; fY = y; }

    //Operators for addition and scalar multiplication
    TwoVector operator+(const TwoVector& second);
    TwoVector operator-();
    TwoVector operator-(const TwoVector& second);
    TwoVector operator*(const double multiplier);
    TwoVector operator/(const double multiplier);

    //Debug print method.
    void Print();

private:
    double fX; //X component
    double fY; //Y component
};

#endif // TWOVECTOR_H
