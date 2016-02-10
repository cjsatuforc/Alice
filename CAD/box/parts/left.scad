use <Suwako/BoltAndTabBox.scad>
use <Suwako/Shapes.scad>
include <../config.scad>;
use <../alice.scad>;

module LeftSidePanel()
{
  difference()
  {
    XZPanel2D(box_config);

    PositionAndLabel([-15, -22], "USB", 2.5, angle=270, text_offset=[0, 10])
      RoundedRectangle([15, 15], r=2.5, center=true);
  }
}

LeftSidePanel();
