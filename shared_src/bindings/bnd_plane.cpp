#include "bindings.h"

BND_Plane BND_Plane::FromOnPlane(const ON_Plane& plane)
{
  BND_Plane wasmPlane;
  wasmPlane.m_origin = plane.origin;
  wasmPlane.m_xaxis = plane.xaxis;
  wasmPlane.m_yaxis = plane.yaxis;
  wasmPlane.m_zaxis = plane.zaxis;
  return wasmPlane;
}

ON_Plane BND_Plane::ToOnPlane() const
{
  ON_Plane plane;
  plane.origin = m_origin;
  plane.xaxis = m_xaxis;
  plane.yaxis = m_yaxis;
  plane.zaxis = m_zaxis;
  plane.UpdateEquation();
  return plane;
}


BND_Plane BND_Plane::WorldXY()
{
  BND_Plane rc = FromOnPlane(ON_Plane::World_xy);
  return rc;
}

#if defined ON_WASM_COMPILE
using namespace emscripten;

void initPlaneBindings()
{
  value_object<BND_Plane>("Plane")
    .field("origin", &BND_Plane::m_origin)
    .field("xAxis", &BND_Plane::m_xaxis)
    .field("yAxis", &BND_Plane::m_yaxis)
    .field("zAxis", &BND_Plane::m_zaxis);
}
#endif
