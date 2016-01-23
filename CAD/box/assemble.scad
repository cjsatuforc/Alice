include <CAD-Library/parametric_enclosures/basic_bolt_jointed/basic_bolt_jointed.scad>;

use <parts/front.scad>;
use <parts/rear.scad>;
use <parts/top.scad>;
use <parts/bottom.scad>;
use <parts/left.scad>;
use <parts/right.scad>;

include <config.scad>;


$fn = 16;

explode = 0;
side_explode = 0;

half_thick = material_thickness / 2;
x = (internal_x / 2) + half_thick + explode + side_explode;
y = (internal_y / 2) + half_thick + explode;
z = (internal_z / 2) + half_thick + explode;

translate([0, 0, z])
  color("cyan")
    linear_extrude(height=3, center=true)
      TopPanel();

translate([0, 0, -z])
  color("green")
    BottomPanel();

rotate([90, 0, 0])
{
  translate([0, 0, y])
    color("blue")
      LeftSidePanel();

  translate([0, 0, -y])
    color("red")
      RightSidePanel();
}

rotate([90, 0, 90])
{
  translate([0, 0, x])
    color("silver")
      linear_extrude(height=3, center=true)
        FrontPanel();

  translate([0, 0, -x])
    color("purple")
      RearPanel();
}
