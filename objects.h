#ifndef OBJECTS_H_
#define OBJECTS_H_

typedef struct{
  int type; // 0 = camera, 1 = sphere, 2 = plane
  double color[3];
  union {
    struct {
      double width;
      double height;
    } camera;
    struct {
      double position[3];
      double radius;
    } sphere;
    struct {
      double position[3];
      double normal[3];
    } plane;
  };
} Object;

void read_scene(char*, Object**);
void skip_ws(FILE*);
void expect_c(FILE*, int);
char* next_string(FILE*);
int next_c(FILE*);
double next_number(FILE*);
double* next_vector(FILE*);

#endif // OBJECTS_H_



