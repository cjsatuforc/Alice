use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;
use <../alice.scad>

module FrontPanel()
{
  difference()
  {
    YZPanel2D(box_config);

    // Power switch
    PositionAndLabel([0, 10], "PWR", text_offset=[0, -15])
      PowerSwitch();

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
    sw_label_offset = [0, -10];
    PositionAndLabel([-80, 62.5], "SW1", text_offset=sw_label_offset)
      circle(d=switch_hole_diameter);
    PositionAndLabel([-60, 62.5], "SW2", text_offset=sw_label_offset)
      circle(d=switch_hole_diameter);
    PositionAndLabel([ 60, 62.5], "SW3", text_offset=sw_label_offset)
      circle(d=switch_hole_diameter);
    PositionAndLabel([ 80, 62.5], "SW4", text_offset=sw_label_offset)
      circle(d=switch_hole_diameter);

    // Potentiometers
    pot_label_offset = [0, -12];
    PositionAndLabel([-20, 60], "P1", text_offset=pot_label_offset)
      circle(d=potentiometer_hole_diameter);
    PositionAndLabel([  0, 60], "P2", text_offset=pot_label_offset)
      circle(d=potentiometer_hole_diameter);
    PositionAndLabel([ 20, 60], "P3", text_offset=pot_label_offset)
      circle(d=potentiometer_hole_diameter);
  }
}

FrontPanel();
