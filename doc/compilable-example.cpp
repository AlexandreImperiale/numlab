
////////////////////////////////////////////////////////////////////////////////
// Core
////////////////////////////////////////////////////////////////////////////////
#include <array>
#include <vector>

namespace nl {

  // Real and complex type.
  using Real = double;
  using Complex = std::array<nl::Real, 2>;

  template<typename T> using View = const T&;

  template<typename T> using Mut = T&;

  struct MoveOnly {
    MoveOnly() = default;
    MoveOnly(const MoveOnly&) = delete;
    MoveOnly& operator=(const MoveOnly&) = delete;
  };

  class NoConstructor {
  public:
    Component() = delete;
    Component(const Component&) = delete;
  };
}

////////////////////////////////////////////////////////////////////////////////
// Lin. alg.
////////////////////////////////////////////////////////////////////////////////
namespace nl {
  namespace alg2D {

    struct Array : nl::NoConstructor {

      struct Data : nl::MoveOnly {
        std::array<nl::Real, 2> values;
      };

      struct Tools : nl::NoConstructor {
        struct Add : nl::NoConstructor {
          static auto In(Mut<Data> a0, View<Data> a1) -> void
          {
            a0.values[0] += a1.values[0];
            a0.values[1] += a1.values[1];
          }
        };
      };
    };
  }
}

////////////////////////////////////////////////////////////////////////////////
// Geom.
////////////////////////////////////////////////////////////////////////////////
namespace nl {
  namespace geom {
      namespace base {

        struct Dir2D : nl::NoConstructor
        {
          
          struct Data : nl::MoveOnly
          {
            nl::alg2D::Array::Data coords;
          };

          struct Tools : nl::NoConstructor
          {
            struct Add : nl::NoConstructor
            {
              static auto In(Mut<Data> d0, View<Data> d1) -> void
              {
                nl::alg2D::Array::Tools::Add::In(d0.coords, d1.coords);
                nl::alg2D::Array::Tools::Normalize::In(d0.coords);
              }
          };

        };
      };
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
// main.
////////////////////////////////////////////////////////////////////////////////
int main()
{
  using Dir2D = nl::geom::base::Dir2D;

  Dir2D::Data d0, d1;
  Dir2D::Tools::Add::In(d0, d1);
}
