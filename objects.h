typedef struct{
  int type; // 0 = camera, 1 = sphere, 2 = plane
  double color[3], position[3], normal[3];
  union {
    struct {
      double width;
      double height;
    } camera;
    struct {
        double* color;
      double* position;
      double radius;
    } sphere;
    struct {
        double* color;
      double* position;
      double* normal;
    } plane;
  };
} Object;
