use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;

module BottomPanel()
{
  difference()
  {
    XYPanel2D(box_config);
  }
}

BottomPanel();
