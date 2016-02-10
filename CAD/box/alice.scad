use <Suwako/DXFImport.scad>;
use <Suwako/Label.scad>;

module PositionAndLabel(pos, t, text_size=4, text_offset=[0, -8], angle=0)
{
  translate(pos)
    Label(t, text_size, text_offset, angle=angle)
      children();
}

module Joystick()
{
  projection()
    DXFImport("../Kanako/Switches/ParallaxJoystick27808.dxf",
              subtraction_layers=["Joystick_Cutout", "Joystick_MountingHoles"]);
}

module Display()
{
  projection()
    DXFImport("../Kanako/Displays/NX4024T032.dxf",
              subtraction_layers=["NX4024T032_DisplayArea", "NX4024T032_MountingHoles"]);
}

module PowerSwitch()
{
  rotate([0, 0, 90])
    projection()
      DXFImport("../Kanako/Switches/RapidDPDTSwitch.dxf",
                subtraction_layers=["RapidDPDTSw_Switch", "RapidDPDTSw_MountingHoles"]);
}

module LogicBoard()
{
  projection()
    DXFImport("../Kanako/DevBoards/ArduinoMega.dxf",
              subtraction_layers=["ArduinoMega_MountingHoles"]);
}

module SDCardBoard()
{
  rotate([0, 0, 90])
    projection()
      DXFImport("../Kanako/Modules/ITEAD_SDCard_Board.dxf",
                subtraction_layers=["SD_MountingHoles"]);
}
