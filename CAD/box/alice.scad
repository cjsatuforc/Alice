module PositionAndLabel(pos, t, text_size=4, text_offset=[0, -8])
{
  translate(pos)
  {
    children();
    translate(text_offset)
      text(t, text_size, halign="center", valign="center");
  }
}
