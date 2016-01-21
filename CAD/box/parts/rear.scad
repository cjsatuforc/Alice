include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;
include <../config.scad>;

module RearPanel()
{
  difference()
  {
    YZPanel();
  }
}

projection()
  RearPanel();
