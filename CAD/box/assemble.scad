include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;

use <front.scad>;
use <rear.scad>;
use <top.scad>;
use <bottom.scad>;
use <left.scad>;
use <right.scad>;

include <config.scad>;


$fn = 16;

explode = 0;
side_explode = 0;

half_thick = material_thickness / 2;
x = (internal_x / 2) + half_thick + explode + side_explode;
y = (internal_y / 2) + half_thick + explode;
z = (internal_z / 2) + half_thick + explode;

color("red")
{
  translate([0, 0, z])
    TopPanel();

  translate([0, 0, -z])
    BottomPanel();
}

color("green")
{
  rotate([90, 0, 0])
  {
    translate([0, 0, y])
      LeftSidePanel();

    translate([0, 0, -y])
      RightSidePanel();
  }
}

color("blue")
{
  rotate([90, 0, 90])
  {
    translate([0, 0, x])
      FrontPanel();

    translate([0, 0, -x])
      RearPanel();
  }
}
