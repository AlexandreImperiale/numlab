#include "numlab/geom/base.h"

namespace nl {
  namespace geom {
    namespace base {
      auto dir2D::tools::make(real x, real, y) -> data
      {
        data d;
        d.coords = {{ x, y }};
        return d;
      }
    }
  }
}
