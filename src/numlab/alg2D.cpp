#include "numlab/alg2D.h"

namespace nl {
  namespace alg2D {
    auto tools::add::in(mut<data> a0, view<data> a1) -> void
    {
      a0.values[0] += a1.values[0];
      a0.values[1] += a1.values[1];
    }
  }
}
