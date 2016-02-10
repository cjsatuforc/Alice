use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;
use <../alice.scad>;

module TopPanel()
{
  difference()
  {
    XYPanel2D(box_config);

    rotate([0, 0, 90])
    {
      // Switches
      PositionAndLabel([-80,  -5], "SW5") circle(d=switch_hole_diameter);
      PositionAndLabel([ 80,  -5], "SW6") circle(d=switch_hole_diameter);
      PositionAndLabel([-80,  15], "SW7") circle(d=switch_hole_diameter);
      PositionAndLabel([ 80,  15], "SW8") circle(d=switch_hole_diameter);

      // JR PPM port
      PositionAndLabel([-30, 15], "PPM (JR)", 2.5) circle(d=6); //TODO

      // DSM
      PositionAndLabel([-5,  15], "DSM",      2.5) circle(d=6.5);
      PositionAndLabel([-5, -12], "DSM BIND", 2.5) circle(d=8);
      PositionAndLabel([10,   0], "DSM",      2.5, text_offset=[0, -15]) PowerSwitch();
      translate([-5,  0]) circle(d=3.2);

      // Hubsan
      PositionAndLabel([30, 0], "HUBSAN", 2.5, text_offset=[0, -15]) PowerSwitch();
    }
  }
}

TopPanel();
