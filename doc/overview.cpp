
////////////////////////////////////////////////////////////////////////////////
// Core
////////////////////////////////////////////////////////////////////////////////
#include <array>
#include <vector>

namespace nl {

  // Real and complex type.
  using Real = double;
  using Complex = std::array<nl::Real, 2>;

  namespace core {

    // View, Mut and Data struct.
    template<typename T> using View = const T&;
    template<typename T> using Mut = T&;
    struct Data {
      Data() = default;
      Data(const Data&) = delete;
      Data& operator=(const Data&) = delete;
    };

  }
}

////////////////////////////////////////////////////////////////////////////////
// Lin. alg.
////////////////////////////////////////////////////////////////////////////////
namespace nl {
  namespace linAlg {

    // Tools on vectors.
    struct Vector {
      struct Data : nl::core::Data { std::vector<nl::Real> values; };.
      struct Tools {
        //
        struct Rand {
          static auto in(Mut<Reals> u, size_t size) -> void;
          static auto out(size_t size) -> Reals;
        };
        //
        struct Add {
          static auto in(Mut<Reals> u, View<Reals> v) -> void;
          static auto out(View<Reals> u, View<Reals> v) -> Reals;
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

    // Base elements.
    namespace base {
      struct Dir2D {
        struct Data : nl::core::Data { std::array<nl::Real, 2> coords; };
        struct Tools { /* Nothing done yet. */ };
      };

      struct Pnt2D {
        struct Data : nl::core::Data { std::array<nl::Real, 2> coords; };
        struct Tools { /* Nothing done yet. */ };
      };

      struct Vec2D {
        struct Data : nl::core::Data { std::array<nl::Real, 2> coords; };
        struct Tools { /* Nothing done yet. */ };
      };

    }

    // Meshes.
    namespace mesh {

      class Regular1D {
      public:

        class Data : nl::core::Data {
          nl::Real a_, b_; size_t ne_;
          friend struct Impl;
         };

         struct Tools {
           static auto getNElement(View<Data> mesh) -> size_t;
           static auto getNPnt(View<Data> mesh) -> size_t;
           static auto getPntCoords(View<Data> mesh, size_t i) -> nl::Real;
           static auto make(nl::Real a, nl::Real b, size_t ne) -> Data;
         };

       private:

         struct Impl {
           static auto rightOriented(View<Data> d) -> bool;
         };
      };

      struct PieceWise1D { };

      struct Irregular1D { };
    }
}

////////////////////////////////////////////////////////////////////////////////
// Num. Int.
////////////////////////////////////////////////////////////////////////////////
namespace nl {
  namespace numInt {

  }
}

////////////////////////////////////////////////////////////////////////////////
// Sig. Proc.
////////////////////////////////////////////////////////////////////////////////
namespace nl {
  namespace sigProc {

  }
}

////////////////////////////////////////////////////////////////////////////////
// main.
////////////////////////////////////////////////////////////////////////////////
int main()
{
  // Example of nl::linAlg L0.
  {
    using Vector = nl::linAlg::Vector;
    Vector::Data u;
    Vector::Tools::Rand::in(u, 10);
    const auto v = Vector::Tools::Rand::out(10);
    const auto w = Vector::Tools::Add::out(u, v);
  }

  // Example of nl::mesh L0.
  {
    using Mesh = nl::geom::mesh::Regular1D;
    const auto mesh = Mesh::Tools::make(0.0, 1.0, 10);
  }

  


}
