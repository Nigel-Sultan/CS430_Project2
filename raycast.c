#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "parser.c"

// Polymorphism in C

typedef struct Pixel{unsigned int r;    //create a pixel struct like discussed in class
unsigned int g;
unsigned int b;
}Pixel;

typedef struct Image{   //image struct that keeps track of the data in the input file
    int width;
    int height;
    int color;
    unsigned char *data;
} Image;


static inline double sqr(double v) {
  return v*v;
}


static inline void normalize(double* v) {
  double len = sqrt(sqr(v[0]) + sqr(v[1]) + sqr(v[2]));
  v[0] /= len;
  v[1] /= len;
  v[2] /= len;
}


double sphere_intersection(double* Ro, double* Rd, double* Center, double r){
    double a = sqr(Rd[0]) + sqr(Rd[1]) + sqr(Rd[2]);
    double b = 2 * ((Ro[0] * Rd[0]) + (Ro[1] * Rd[1]) + (Ro[2] * Rd[2]));
    double c = sqr(Ro[0]) + sqr(Ro[1]) + sqr(Ro[2]) + sqr(Center[0]) + sqr(Center[1]) + sqr(Center[2]) - 2*(Ro[0]*Center[0] + Rd[0]*Center[0] + Ro[1]*Center[1] + Rd[1]*Center[1] + Ro[2]*Center[2] + Rd[2]*Center[2]) - sqr(r);
    double d = sqr(b) - 4*a*c;
    if(d < 0){
        fprintf(stderr, "Error: No imaginary numbers!\n");
        return -1;
    }
    d = sqrt(d);
    double t = (-b - d) / (2 * a);
    if(t > 0){
        return t;
    }
    t = (-b + d) / (2 * a);
    if(t > 0){
        return t;
    }
    fprintf(stderr, "Error: Can't have 0 or negative distance!\n");
    return -1;
}

double planeIntersection(double* Ro, double* Rd, double* position, double* normal){
    double t = - (normal[0]*Ro[0] + normal[1]*Ro[1] + normal[2]*Ro[2] - normal[0]*position[0]
                - normal[1]*position[1] - normal[2]*position[2]) / (normal[0]*Rd[0]
                + normal[1]*Rd[1] + normal[2]*Rd[2]);

    if (t > 0){
        return t;
    }
    fprintf(stderr, "Error: Can't have 0 or negative distance!\n");
    return -1;
}

void writeData(char* filename){
    Object** objects = malloc(sizeof(Object*)*2);
}

int main(int argc, char **argv) {
    if(argc > 4){
        fprintf(stderr, "Error: Too many arguments!\n");
        return(1);
    }

    char* width = argv[1];
    char* height = argv[2];
    char *inputFilename = argv[3];
    char *outputFilename = argv[4];

    read_scene(inputFilename);
    writeData(outputFilename);
  return 0;
}
