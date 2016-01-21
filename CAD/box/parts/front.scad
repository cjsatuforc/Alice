use <CAD-Library/dxf_import.scad>;

include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;
include <../config.scad>;

potentiometer_positions = [[-20, 60], [0, 60], [20, 60]];
switch_positions = [[-75, 60], [-60, 60], [60, 60], [75, 60]];

module Joystick()
{
  projection()
  DXFImport("/home/dan/git_repos/CAD-Library/DXF/Switches/ParallaxJoystick27808.dxf",
            subtraction_layers=["Joystick_Cutout", "Joystick_MountingHoles"]);
}

module LCD()
{
  //TODO
}

module FrontPanel()
{
  difference()
  {
    projection()
      YZPanel();

    // Joysticks
    translate([0, 20])
    {
      translate([-50, 0])
        Joystick();
      translate([50, 0])
        Joystick();
    }

    // Switches
    for (sw_pos = switch_positions)
    {
      translate(sw_pos)
        circle(d=switch_hole_diameter);
    }

    // Switches
    for (pot_pos = potentiometer_positions)
    {
      translate(pot_pos)
        circle(d=potentiometer_hole_diameter);
    }
  }
}

FrontPanel();
