use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;

module RightSidePanel()
{
  difference()
  {
    XZPanel2D(box_config);
  }
}

RightSidePanel();
