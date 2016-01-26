use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;

module LeftSidePanel()
{
  difference()
  {
    XZPanel2D(box_config);
  }
}

LeftSidePanel();
