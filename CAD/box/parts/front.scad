use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;
use <../alice.scad>

module FrontPanel()
{
  difference()
  {
    YZPanel2D(box_config);

    // Display
    translate([-3, -45])
      Display();

    // Joysticks
    translate([0, 20])
    {
      translate([-50, 0])
        Joystick();
      translate([50, 0])
        Joystick();
    }

    // Switches
    PositionAndLabel([-80, 60], "SW1") circle(d=switch_hole_diameter);
    PositionAndLabel([-60, 60], "SW2") circle(d=switch_hole_diameter);
    PositionAndLabel([ 60, 60], "SW3") circle(d=switch_hole_diameter);
    PositionAndLabel([ 80, 60], "SW4") circle(d=switch_hole_diameter);

    // Potentiometers
    PositionAndLabel([-20, 60], "P1") circle(d=potentiometer_hole_diameter);
    PositionAndLabel([  0, 60], "P2") circle(d=potentiometer_hole_diameter);
    PositionAndLabel([ 20, 60], "P3") circle(d=potentiometer_hole_diameter);
  }
}

FrontPanel();
