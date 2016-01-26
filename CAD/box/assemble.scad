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
x = (internal[0] / 2) + half_thick + explode + side_explode;
y = (internal[1] / 2) + half_thick + explode;
z = (internal[2] / 2) + half_thick + explode;

translate([0, 0, z])
  color("cyan")
    linear_extrude(height=material_thickness, center=true)
      TopPanel();

translate([0, 0, -z])
  color("green")
    linear_extrude(height=material_thickness, center=true)
      BottomPanel();

rotate([90, 0, 0])
{
  translate([0, 0, y])
    color("blue")
      linear_extrude(height=material_thickness, center=true)
        LeftSidePanel();

  translate([0, 0, -y])
    color("red")
      linear_extrude(height=material_thickness, center=true)
        RightSidePanel();
}

rotate([90, 0, 90])
{
  translate([0, 0, x])
    color("silver")
      linear_extrude(height=material_thickness, center=true)
        FrontPanel();

  translate([0, 0, -x])
    color("purple")
      linear_extrude(height=material_thickness, center=true)
        RearPanel();
}
