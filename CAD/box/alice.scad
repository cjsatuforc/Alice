use <Suwako/DXFImport.scad>;

module PositionAndLabel(pos, t, text_size=4, text_offset=[0, -8])
{
  translate(pos)
  {
    children();
    translate(text_offset)
      text(t, text_size, halign="center", valign="center");
  }
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
