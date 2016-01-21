use <CAD-Library/dxf_import.scad>;

include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;
include <../config.scad>;
use <../alice.scad>

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
