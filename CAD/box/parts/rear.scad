use <Suwako/BoltAndTabBox.scad>
use <../alice.scad>;
include <../config.scad>;

module RearPanel()
{
  difference()
  {
    YZPanel2D(box_config);

    translate([-85, -60])
      LogicBoard();

    translate([62, 0])
      SDCardBoard();
  }
}

RearPanel();
