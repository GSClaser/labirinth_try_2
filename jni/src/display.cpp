#include "display.h"

video_ok::video_ok():id(0),vertex{\
      "uniform mat4 scale;    \n"
      "uniform float u_cos; \n"
      "uniform float u_sin; \n"
      "attribute vec4 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "	  gl_Position = a_position; \n"
      "   v_texCoord = a_texCoord; \n"
      "}                            \n"
      },fragment{\
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
    
      "void main()                                         \n"
      "{                                                   \n"
      "vec4 color = texture2D(s_texture,v_texCoord);\n"

      "if (color.rgb==vec3(1.0,0.0,1.0))\n"
      "	 discard; \n"
      "  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
      "}                                                   \n"
      },texture_array{\
	0.0f,  0.0f,        // TexCoord 0
	0.0f,  1.0f,        // TexCoord 1
	1.0f,  1.0f,        // TexCoord 2
	1.0f,  0.0f         // TexCoord 3
      },indices{ 0, 1, 2, 0, 2, 3 }
{
  
}

bool video_ok::init()
{
  sdl_init();
  opengl_init();
  load_texture();
  if (!id)
    return false;
  return true;
}

void video_ok::sdl_init()
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_ES);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  window = SDL_CreateWindow("labirinth", 0, 0, set.get_x(), set.get_y(), SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  context = SDL_GL_CreateContext(window);
}

void video_ok::opengl_init()
{                     
  program_object_rotate = glCreateProgram();
  load_shader(program_object_rotate,GL_VERTEX_SHADER,vertex);
  load_shader(program_object_rotate,GL_FRAGMENT_SHADER,fragment);
  glLinkProgram(program_object_rotate);
  position = glGetAttribLocation(program_object_rotate,"a_position");
  texture_coord = glGetAttribLocation(program_object_rotate,"a_texCoord");
  sample_location = glGetUniformLocation(program_object_rotate,"s_texture");
  sample_location_2 = glGetUniformLocation(program_object_rotate,"s_texture_2");
  cos_result = glGetUniformLocation(program_object_rotate,"u_cos");
  sin_result = glGetUniformLocation(program_object_rotate,"u_sin");
  matrix_scale = glGetUniformLocation(program_object_rotate,"scale");
  
 
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glViewport(0,0,set.get_x(),set.get_y());
}

void video_ok::load_shader(GLuint program,GLenum type,const GLchar* shaderSrc)
{
  GLuint shader;
  shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderSrc, NULL);
  glCompileShader(shader);
  glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
  if ( !compiled ) 
   {
      GLint infoLen = 0;

      glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = new char[infoLen];
	 glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
	 printf("%s\n",infoLog);
	 delete [] infoLog;
      }
   }
  glAttachShader(program, shader);
}

void video_ok::load_texture()
{
  SDL_Surface* img = SDL_LoadBMP("data/face.bmp");
  glEnable(GL_TEXTURE_2D);
  glGenTextures(1, &id);

  glBindTexture(GL_TEXTURE_2D, id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, 
    GL_UNSIGNED_BYTE, img->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  img = SDL_LoadBMP("data/checker.bmp");

  glActiveTexture(GL_TEXTURE_2D);
  glGenTextures(2, &id2);

  glBindTexture(GL_TEXTURE_2D, id2);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, 
    GL_UNSIGNED_BYTE, img->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  img = SDL_LoadBMP("data/font.bmp");

  glActiveTexture(GL_TEXTURE_2D);
  glGenTextures(2, &id3);

  glBindTexture(GL_TEXTURE_2D, id3);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, 
    GL_UNSIGNED_BYTE, img->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  img = SDL_LoadBMP("data/wall.bmp");

  glActiveTexture(GL_TEXTURE_2D);
  glGenTextures(2, &id4);

  glBindTexture(GL_TEXTURE_2D, id4);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, 
    GL_UNSIGNED_BYTE, img->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  
  img = SDL_LoadBMP("data/keyboard.bmp");

  glActiveTexture(GL_TEXTURE_2D);
  glGenTextures(1, &id5);

  glBindTexture(GL_TEXTURE_2D, id5);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, 
    GL_UNSIGNED_BYTE, img->pixels);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  
}

void video_ok::face(float x,float y,float w,float h)
{
  float x2 = 2*x/set.get_x();
  float y2 = 2*y/set.get_y();
  float scale_w = set.get_x()/w;
  float scale_h = set.get_y()/h;

  /*
  float sample_matrix[] = {\
    1,0,
    0,1
  };
  */
  /*
  float vertex_array[] = {\
       -1/scale_w, 1/scale_h, 0.0f,  // Position 0
       -1/scale_w, -1/scale_h, 0.0f,  // Position 1
       1/scale_w, -1/scale_h, 0.0f,  // Position 2
       1/scale_w, 1/scale_h, 0.0f  // Position 3 
  };
  */
  float* vertex_array  = new float[12];
  vertex_array = matrix(0,x2,y2,scale_w,scale_h,0,0);
//  glClear(GL_COLOR_BUFFER_BIT);
//  glActiveTexture(GL_TEXTURE0);
  glUseProgram(program_object_rotate);
  glUniform1f(value_x,0);
  glUniform1f(value_y,0);
  glVertexAttribPointer(position,3,GL_FLOAT,false,\
    0,vertex_array);
  glVertexAttribPointer(texture_coord,2,GL_FLOAT,false,\
    0,texture_array);
  glEnableVertexAttribArray(position);
  glEnableVertexAttribArray(texture_coord);
  

//  glUniformMatrix2fv(matrix_scale,1,false,sample_matrix);

  glEnable(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D,id);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);

}

void video_ok::keyboard(float x,float y,float w,float h)
{
  float x2 = 2*x/set.get_x();
  float y2 = 2*y/set.get_y();
  float scale_w = set.get_x()/w;
  float scale_h = set.get_y()/h;

  /*
  float sample_matrix[] = {\
    1,0,
    0,1
  };
  */
  /*
  float vertex_array[] = {\
       -1/scale_w, 1/scale_h, 0.0f,  // Position 0
       -1/scale_w, -1/scale_h, 0.0f,  // Position 1
       1/scale_w, -1/scale_h, 0.0f,  // Position 2
       1/scale_w, 1/scale_h, 0.0f  // Position 3 
  };
  */
  float* vertex_array  = new float[12];
  vertex_array = matrix(0,x2,y2,scale_w,scale_h,0,0);
//  glClear(GL_COLOR_BUFFER_BIT);
//  glActiveTexture(GL_TEXTURE0);
  glUseProgram(program_object_rotate);
  glUniform1f(value_x,0);
  glUniform1f(value_y,0);
  glVertexAttribPointer(position,3,GL_FLOAT,false,\
    0,vertex_array);
  glVertexAttribPointer(texture_coord,2,GL_FLOAT,false,\
    0,texture_array);
  glEnableVertexAttribArray(position);
  glEnableVertexAttribArray(texture_coord);
  

//  glUniformMatrix2fv(matrix_scale,1,false,sample_matrix);

  glEnable(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D,id5);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);

}

float* video_ok::matrix(float angle,float x_offset,float y_offset,float scale_w,float scale_h,float move_x,float move_y)
{
  float x1 = -1/scale_w;
  float y1 = 1/scale_h;
  float x2 = -1/scale_w;
  float y2 = -1/scale_h;
  float x3 = 1/scale_w;
  float y3 = -1/scale_h;
  float x4 = 1/scale_w;
  float y4 = 1/scale_h;
  
  /*
  
  float _x1 = x1*c - y2*s;
  float _y1 = x1*s + y2*c;
  float _x2 = x1*c - y1*s;
  float _y2 = x1*s + y1*c;
  float _x3 = x2*c - y1*s;
  float _y3 = x2*s + y1*c;
  float _x4 = x2*c - y2*s;
  float _y4 = x2*s + y2*c;*/
  
  
  
  x1 += 1/scale_w-1+x_offset;
  y1 += -1/scale_h+1-y_offset;
  x2 += 1/scale_w-1+x_offset;
  y2 += -1/scale_h+1-y_offset;
  x3 += 1/scale_w-1+x_offset;
  y3 += -1/scale_h+1-y_offset;
  x4 += 1/scale_w-1+x_offset;
  y4 += -1/scale_h+1-y_offset;
  
  float s = (float)sin(3.1416*angle/180);
  float c = (float)cos(3.1416*angle/180);
  
  float _x1 = x1*c-y1*s;
  float _y1 = x1*s+y1*c;
  float _x2 = x2*c-y2*s;
  float _y2 = x2*s+y2*c;
  float _x3 = x3*c-y3*s;
  float _y3 = x3*s+y3*c;
  float _x4 = x4*c-y4*s;
  float _y4 = x4*s+y4*c;
  
  float __x1 = _x1-move_x;
  float __y1 = _y1-move_y;
  float __x2 = _x2-move_x;
  float __y2 = _y2-move_y;
  float __x3 = _x3-move_x;
  float __y3 = _y3-move_y;
  float __x4 = _x4-move_x;
  float __y4 = _y4-move_y;
  
//  printf("%f %f %f %f\n",x1,y1,x2,y2);
  float* matrix = new float[12];
  matrix[0] = __x1;
  matrix[1] = __y1;
  matrix[2] = 0.0f;
  matrix[3] = __x2;
  matrix[4] = __y2;
  matrix[5] = 0.0f;
  matrix[6] = __x3;
  matrix[7] = __y3;
  matrix[8] = 0.0f;
  matrix[9] = __x4;
  matrix[10] = __y4;
  matrix[11] = 0.0f;
  return matrix;
}

void video_ok::wall(float x,float y,float w,float h,float angle,float move_x,float move_y)
{
  float x2 = 2*x/set.get_x();
  float y2 = 2*y/set.get_y();
  float scale_w = set.get_x()/w;
  float scale_h = set.get_y()/h;
  /*
  float sample_matrix[] = {\
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  */
  glUseProgram(program_object_rotate);
//  glUniform1f(cos_result,cos(3.1416*angle/180));
//  glUniform1f(sin_result,sin(3.1416*angle/180));
  
  /*
  float vertex_array[] = {\
       -1/scale_w-1+1/scale_w+x2, 1/scale_h+1-1/scale_h-y2, 0.0f,  // Position 0
       -1/scale_w-1+1/scale_w+x2, -1/scale_h+1-1/scale_h-y2, 0.0f,  // Position 1
       1/scale_w-1+1/scale_w+x2, -1/scale_h+1-1/scale_h-y2, 0.0f,  // Position 2
       1/scale_w-1+1/scale_w+x2, 1/scale_h+1-1/scale_h-y2, 0.0f  // Position 3 
  };
  */
  float x3 = x2 + 100*move_x;
  float y3 = y2 + 100*move_y;
  float* vertex_array = new float[12];
  vertex_array = matrix(angle,x3,y3,scale_w,scale_h,move_x,move_y);
//  printf("%f %f \n",vertex_array[0],vertex_array[1]);
  /*
  float sample_matrix2[16];
  float modelview[16];

  rotate(angle,0,0,1,modelview);
  rotate(angle,0,0,1,sample_matrix);
  
  multiply(sample_matrix,modelview,modelview);
  modelview[14] -= 1;
  float scale[] = {\
    1/scale_w,0,0,0,
    0,1/scale_h,0,0,
    0,0,1,0,
    0,0,0,1
  };
  multiply(modelview,scale,modelview);
  float fovy = 45;
  float znear = 0.01f;
  float zfar = 100.0f;
  float aspect = set.get_x()/set.get_y();
  
  float a = 1/(tan(fovy*0.5)*aspect);
  float b = 1/tan(fovy*0.5);
  float c = (znear+zfar)/(znear-zfar);
  float d = (2.0f*znear*zfar)/(znear-zfar);
  
  float perspective[] = {\
    a,0,0,0,
    0,b,0,0,
    0,0,c,-1.0,
    0,0,d,0
  };
  
  float sample_matrix3[16];
  
  multiply(perspective,modelview,sample_matrix3);
  
  float sample_matrix4[16];
  for(int i = 0;i<16;i++)
    sample_matrix4[i] = sample_matrix3[i];
  
  sample_matrix4[12] = sample_matrix3[12] - 1 + 1/(sqrt(2)/2*scale_w)+x2;
  sample_matrix4[13] = sample_matrix3[13] + 1 - 1/(sqrt(2)/2*scale_h)+y2;
  */
  /*
  glUniform1f(offset_x,1);
  glUniform1f(offset_y,-1);
  */
//  glClear(GL_COLOR_BUFFER_BIT);
//  glActiveTexture(GL_TEXTURE0);
  glVertexAttribPointer(position,3,GL_FLOAT,false,\
    0,vertex_array);
  glVertexAttribPointer(texture_coord,2,GL_FLOAT,false,\
    0,texture_array);
  glEnableVertexAttribArray(position);
  glEnableVertexAttribArray(texture_coord);

  // glUniformMatrix4fv(matrix_scale,1,false,sample_matrix4);

  glEnable(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D,id4);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);

}

void video_ok::checker(float x,float y,float w,float h)
{
  float x2 = 2*x/set.get_x();
  float y2 = 2*y/set.get_y();
  float scale_w = set.get_x()/w;
  float scale_h = set.get_y()/h;

  float sample_matrix[] = {\
    1,0,
    0,1
  };
  float vertex_array[] = {\
       -1/scale_w, 1/scale_h, 0.0f,  // Position 0
       -1/scale_w, -1/scale_h, 0.0f,  // Position 1
       1/scale_w, -1/scale_h, 0.0f,  // Position 2
       1/scale_w, 1/scale_h, 0.0f  // Position 3 
  };
//  glClear(GL_COLOR_BUFFER_BIT);

  glVertexAttribPointer(position,3,GL_FLOAT,false,\
    0,vertex_array);
  glVertexAttribPointer(texture_coord,2,GL_FLOAT,false,\
    0,texture_array);
  glEnableVertexAttribArray(position);
  glEnableVertexAttribArray(texture_coord);
  glUniform1f(offset_x,x2+1/scale_w-1);
  glUniform1f(offset_y,-y2-1/scale_h+1);


  glUniformMatrix2fv(matrix_scale,1,false,sample_matrix);
  glEnable(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D,id2);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);

}

void video_ok::font(float x,float y,float w,float h,\
  int n,int upper)
{
  float x2 = 2*x/set.get_x();
  float y2 = 2*y/set.get_y();
  float scale_w = set.get_x()/w;
  float scale_h = set.get_y()/h;

  float texture_array2[] = {\
	0.0f+0.0267f*n,  0.0f+0.06f*upper,        // TexCoord 0
	0.0f+0.0267f*n,  0.05f+0.06f*upper,        // TexCoord 1
	0.025f+0.0267f*n,  0.05f+0.06f*upper,        // TexCoord 2
	0.025f+0.0267f*n,  0.0f+0.06f*upper         // TexCoord 3
      };
  
  float sample_matrix[] = {\
    1,0,
    0,1
  };
  float vertex_array[] = {\
       -1/scale_w, 1/scale_h, 0.0f,  // Position 0
       -1/scale_w, -1/scale_h, 0.0f,  // Position 1
       1/scale_w, -1/scale_h, 0.0f,  // Position 2
       1/scale_w, 1/scale_h, 0.0f  // Position 3 
  };
//  glClear(GL_COLOR_BUFFER_BIT);

  glVertexAttribPointer(position,3,GL_FLOAT,false,\
    0,vertex_array);
  glVertexAttribPointer(texture_coord,2,GL_FLOAT,false,\
    0,texture_array2);
  glEnableVertexAttribArray(position);
  glEnableVertexAttribArray(texture_coord);
  glUniform1f(offset_x,x2+1/scale_w-1);
  glUniform1f(offset_y,-y2-1/scale_h+1);


  glUniformMatrix2fv(matrix_scale,1,false,sample_matrix);
  glEnable(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D,id3);
  glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_SHORT,indices);

}

void video_ok::clear()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void video_ok::update()
{
  
  glFinish();
  SDL_GL_SwapWindow(window);
}