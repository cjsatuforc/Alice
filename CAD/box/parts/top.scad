include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;
include <../config.scad>;
use <../alice.scad>;

module TopPanel()
{
  difference()
  {
    projection()
      XYPanel();

    rotate([0, 0, 90])
    {
      // Switches
      PositionAndLabel([-80, -20], "SW5") circle(d=switch_hole_diameter);
      PositionAndLabel([ 80, -20], "SW6") circle(d=switch_hole_diameter);
      PositionAndLabel([-80,   5], "SW7") circle(d=switch_hole_diameter);
      PositionAndLabel([ 80,   5], "SW8") circle(d=switch_hole_diameter);
    }
  }
}

TopPanel();
