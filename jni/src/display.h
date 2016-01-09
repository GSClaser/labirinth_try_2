#ifndef DISPLAY_H
#define DISPLAY_H

#include "SDL.h"
#include "GLES2/gl2.h"
#include "string"
#include "settings.h"

using namespace std;

class video_ok
{
private:
  SDL_Window* window;
  SDL_GLContext context;
  unsigned int id;
  unsigned int id2;
  unsigned int id3;
  unsigned int id4;
  unsigned int id5;
  GLuint program_object_rotate;
  GLuint program_object_move;
  GLchar vertex[512];
  GLchar fragment[512];
  GLchar vertex2[512];
  GLchar fragment2[512];
  int position;
  int texture_coord;
  int sample_location;
  int sample_location_2;
  float vertex_array_2[12];
  float texture_array[8];
  GLushort indices[128];
  settings set;
  int compiled;
  float cos_result;
  float sin_result;
  float value_x;
  float value_y;
  int offset_x;
  int offset_y;
  int offset_z;
  int matrix_scale;
  void rotate(float,float,float,float,float*);
  void multiply(float*,float*,float*);
public:
  video_ok();
  bool init();
  void sdl_init();
  void opengl_init();
  void load_shader(GLuint,GLenum,const GLchar*);
  void load_texture();
  void face(float,float,float,float);
  void checker(float,float,float,float);
  void font(float,float,float,float,int,int);
  void wall(float,float,float,float,float,float,float);
  void keyboard(float,float,float,float);
  void update();
  void clear();
  float* matrix(float,float,float,float,float,float,float);
};

#endif