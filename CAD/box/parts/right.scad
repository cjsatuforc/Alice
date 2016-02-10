use <Suwako/BoltAndTabBox.scad>
use <Suwako/Shapes.scad>
include <../config.scad>;
use <../alice.scad>;

module RightSidePanel()
{
  difference()
  {
    XZPanel2D(box_config);

    PositionAndLabel([-15, 0], "SD", 2.5, angle=270, text_offset=[0, 10])
      RoundedRectangle([15, 35], r=2.5, center=true);
  }
}

RightSidePanel();
