#include "game.h"

game::game(video_ok& vok,keyboard_out& kot,mouse_out& mot):\
  vin(vok),kin(kot),min(mot),i(0),j(0),x(0),y(0),wall{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
  }
{
}

void game::run()
{
  if(kin.key_a())
    i-=1;
  if(kin.key_d())
    i+=1;
  if(kin.key_w())
  {
    x = x + 0.0001*cos(3.1416*i/180);
    y = y - 0.0001*sin(3.1416*i/180);
  }
  if(kin.key_s())
  {
    x = x - 0.0001*cos(3.1416*i/180);
    y = y + 0.0001*sin(3.1416*i/180);
  }
    
/*  for(int y = 0;y<set.get_y_visual();y++)
  {
    for(int x = 0;x<set.get_x_visual();x++)   
      vin.draw_pixel(x,y,rand()%255,rand()%255,rand()%255);
  }
*/  
    //  vin.run(i,j);
  //vin.update();
//  s2d.run();
//  p3d.run();
//  vin.face(i,j,60,60);
  vin.clear();

//  vin.update();
//  vin.font(10,100,100,100,0,1);
//  vin.checker(i,j,60,60);
  
  for(int k = 0;k<32*32;k++)
    if(wall[k] == 1)
      vin.wall(set.get_x()/32*(k%32),set.get_y()/24*(k/32),set.get_x()/32,set.get_y()/24,i,y,x);
  
  vin.face(set.get_x()/2-set.get_x()/32,set.get_y()/2-set.get_y()/24,set.get_x()/16,set.get_y()/12);
  vin.keyboard(set.get_min()-3*set.get_min()/16,set.get_min()-2*set.get_min()/16,3*set.get_min()/16,2*set.get_min()/16);
  if(min.click_read() == 1&&
    min.mouse_x()>set.get_min()-set.get_min()/16&&
    min.mouse_x()<set.get_min()&&
    min.mouse_y()>set.get_min()-set.get_min()/16&&
    min.mouse_y()<set.get_min())
    i+=1;
  if(min.click_read() == 1&&
    min.mouse_x()>set.get_min()-3*set.get_min()/16&&
    min.mouse_x()<set.get_min()-2*set.get_min()/16&&
    min.mouse_y()>set.get_min()-set.get_min()/16&&
    min.mouse_y()<set.get_min())
    i-=1;
  if(min.click_read() == 1&&
    min.mouse_x()>set.get_min()-2*set.get_min()/16&&
    min.mouse_x()<set.get_min()-set.get_min()/16&&
    min.mouse_y()>set.get_min()-set.get_min()/16&&
    min.mouse_y()<set.get_min())
  {
    x = x - 0.0001*cos(3.1416*i/180);
    y = y + 0.0001*sin(3.1416*i/180);
  }
  if(min.click_read() == 1&&
    min.mouse_x()>set.get_min()-2*set.get_min()/16&&
    min.mouse_x()<set.get_min()-set.get_min()/16&&
    min.mouse_y()>set.get_min()-2*set.get_min()/16&&
    min.mouse_y()<set.get_min()-set.get_min()/16)
  {
    x = x + 0.0001*cos(3.1416*i/180);
    y = y - 0.0001*sin(3.1416*i/180);
  }
//  vin.wall(0,0,40,40,i);
  vin.update();
  if(kin.key_esc())
    exit(1);
}