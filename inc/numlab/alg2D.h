#include "numlab/core.h"
#include <array>

namespace nl {
  namespace alg2D {

    struct array : no_constructor {

      struct data : move_only
      {
        std::array<nl::Real, 2> values;
      };

      struct tools : no_constructor
      {
        struct add : no_constructor
        {
          static auto in(mut<data> a0, view<data> a1) -> void;
          static auto out(view<data> d0, view<data> d1) -> data;
        };
      };
    };
  }
}
