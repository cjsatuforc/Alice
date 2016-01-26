use <Suwako/BoltAndTabBox.scad>
include <../config.scad>;

module RearPanel()
{
  difference()
  {
    YZPanel2D(box_config);
  }
}

RearPanel();
