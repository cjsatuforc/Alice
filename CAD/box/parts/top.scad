include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;
include <../config.scad>;
use <../alice.scad>;

module TopPanel()
{
  difference()
  {
    XYPanel2D();

    rotate([0, 0, 90])
    {
      // Switches
      PositionAndLabel([-80, -20], "SW5") circle(d=switch_hole_diameter);
      PositionAndLabel([ 80, -20], "SW6") circle(d=switch_hole_diameter);
      PositionAndLabel([-80,   5], "SW7") circle(d=switch_hole_diameter);
      PositionAndLabel([ 80,   5], "SW8") circle(d=switch_hole_diameter);

      // DSM moudule
      PositionAndLabel([-10,  10], "DSMII/X",     2.5) circle(d=6.5);
      PositionAndLabel([ 20,  10], "DSM BIND",    2.5) circle(d=8);
      PositionAndLabel([ 20, -10], "DSM STATUS",  2.5) circle(d=4); //TODO

      // JR trainer port
      PositionAndLabel([-40, 10], "PPM (JR)", 2.5) circle(d=5); //TODO
    }
  }
}

TopPanel();
