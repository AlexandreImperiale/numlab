namespace nl {

  using real = double;

  using complex = std::array<nl::Real, 2>;

  template<typename T> using view = const T&;

  template<typename T> using mut = T&;

  struct move_only {
    move_only() = default;
    move_only(const move_only&) = delete;
    move_only& operator=(const move_only&) = delete;
  };

  struct no_constructor {
    no_constructor() = delete;
    no_constructor(const no_constructor&) = delete;
  };
}
