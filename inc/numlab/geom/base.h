#include "numlab/core.h"
#include "numlab/alg2D.h"

namespace nl {
  namespace geom {
      namespace base {

        struct dir2D : no_constructor
        {

          class Data : move_only
          {
            alg2D::array::data coords;
            friend struct Tools;
          };

          struct tools : no_constructor
          {
            static auto make(real x, real, y) -> data;

            struct get : no_constructor
            {
              static auto coords(view<data> d) -> view<alg2D::array::data>;
              static auto norm(view<data> d) -> real;
              // .... put here every getters...
            }

            struct add : no_constructor
            {
              static auto in(mut<data> d0, view<data> d1) -> void;
              static auto out(view<data> d0, view<data> d1) -> Data;
            };
          };
        };

      }
    }
  }
}
