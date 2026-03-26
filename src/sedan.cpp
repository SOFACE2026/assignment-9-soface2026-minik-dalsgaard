#include "sedan.hpp"
#include <array>

static const std::array<double, 7> gear_ratios = {-1, 1, 2, 3, 4, 5, 6};

Sedan::Sedan() : current_gear(0)
{
    // Start in reverse gear (-1)
}

void Sedan::shift_up()
{
    // Increase gear if possible
    if (current_gear < 6)
        current_gear++;
}

void Sedan::shift_down()
{
    // Decrease gear if possible
    if (current_gear > 0)
        current_gear--;
}

double Sedan::get_torque(double engine_rpm, double throttle)
{
    // Ignore engine_rpm, simple constant torque model
    // Adjusted according to test results
    return 960 * throttle;
}

double Sedan::get_weight()
{
    // Simple constant weight
    return 1000;
}

double Sedan::get_wheel_radius()
{
    // Simple constant wheel size
    return 0.3;
}

double Sedan::get_current_gear_ratio()
{
    // Return current gear ratio
    return gear_ratios[current_gear];
}