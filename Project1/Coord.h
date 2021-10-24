#pragma once

struct Coord {
   int row{};
   int col{};
};

struct Extent {
   int height{};
   int width{};
};

struct CoordRange : public Coord, public Extent
{
   CoordRange() : Coord{ 0, 0 }, Extent{0, 0}
   {}

   CoordRange(int _row, int _col, int _height, int _width) : Coord{_row, _col}, Extent{ _height, _width}
   {}

   CoordRange(const Coord& _coord, const Extent& _extent) : Coord{ _coord }, Extent{_extent}
   {}
};
