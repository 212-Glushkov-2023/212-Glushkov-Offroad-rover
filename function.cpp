#include "includes.h"


Hill::Hill(double size_x, double size_y)
{
  x = random() / double(RAND_MAX) * size_x - size_x/2;
  y = random() / double(RAND_MAX) * size_y - size_y/2;
  sigma = random() / double(RAND_MAX) * 1.9 + 0.1;
  hight = random() / double(RAND_MAX) * 10 - 5;
}

Stoun::Stoun(double size_x, double size_y)
{
  x = random() / double(RAND_MAX) * size_x - size_x/2;
  y = random() / double(RAND_MAX) * size_y - size_y/2;
  r = random() / double(RAND_MAX) * 1 + 0.5;
}

Log::Log(double size_x, double size_y)
{
  x1 = random() / double(RAND_MAX) * size_x - size_x/2;
  y1 = random() / double(RAND_MAX) * size_y - size_y/2;
  r = random() / double(RAND_MAX) * 1 + 0.5;
  double lenght = (random() / double(RAND_MAX) * 3 + 1) * r;
  double direction = random() / double(RAND_MAX) * 2;
  x2 = x1 + lenght * cos(direction * M_PI);
  y2 = y1 + lenght * sin(direction * M_PI);
}

NoWay::NoWay(double x, double y, int count_hills, 
             int count_stouns, int count_logs): 
             size_x(x), size_y(y), count_hills(count_hills), 
             count_stouns(count_stouns), count_logs(count_logs)
{
  if (x <= 0 || y <= 0) throw 1;
  for(int i = 0; i < count_hills; i++)
  {
    hills.push_back(Hill(x, y));
  }
  for(int i = 0; i < count_stouns; i++)
  {
    stouns.push_back(Stoun(x, y));
  }
  for(int i = 0; i < count_logs; i++)
  {
    logs.push_back(Log(x, y));
  }
}


double Hill::Gauss(double x0, double y0) const
{
  double e = exp(-((x - x0) * (x - x0) + (y - y0) * (y - y0)) / 2 * sigma * sigma);
  return (hight * e) / (sigma * sqrt(2 * M_PI));
}

void NoWay::print(std::ofstream &file1, std::ofstream &file2, 
                  std::ofstream &file3) const
{
  double z;
  for (double i = -size_x/2; i <= size_x/2; i+=size_x/40)
  {
    for (double j = -size_y/2; j <= size_y/2; j+=size_y/40)
    {
      z = 0;
      for (int k = 0; k < count_hills; k++)
      {
        z+=hills[k].Gauss(i, j);
      }
      file1 << i << " " << j << " " << z << "\n";
    }
    file1 << "\n";
  }

  
  for (int k = 0; k < count_stouns; k++)
  {
    z = 0;
    for (int m = 0; m < count_hills; m++)
    {
      z+=hills[m].Gauss(stouns[k].get_x(), stouns[k].get_y());
    }
    for (double i = stouns[k].get_r(); i > 0; i-=stouns[k].get_r()/5)
    {
      for (double j = 0; j <= 2.1; j+=0.1)
      {
        file2 << stouns[k].get_x() + i * cos(j * M_PI) << 
          " " << stouns[k].get_y() + i * sin(j * M_PI) << 
          " " << sqrt(stouns[k].get_r() * stouns[k].get_r() - i * i) + z << "\n";
      }
      file2 << "\n";
    }
    file2 << "\n";
  }
  double z1, z2, a, b, l;
  for (int k = 0; k < count_logs; k++)
  {
    z1 = 0; 
    z2 = 0;
    for (int m = 0; m < count_hills; m++)
    {
      z1+=hills[m].Gauss(logs[k].get_x1(), logs[k].get_y1());
      z2+=hills[m].Gauss(logs[k].get_x2(), logs[k].get_y2());
    }
    a = logs[k].get_y1() - logs[k].get_y2();
    b = logs[k].get_x2() - logs[k].get_x1();
    l = sqrt(a * a + b * b);
    for (double i = -logs[k].get_r(); i <= logs[k].get_r(); i+=logs[k].get_r()/10)
    {
      for (double d = 0; d <= 1; d += 0.25) {
        file3 << logs[k].get_x1() + a * i / l << 
          " " << logs[k].get_y1() + b * i / l << 
          " " << (sqrt(logs[k].get_r() * logs[k].get_r() - i * i) + z1) * d << "\n";
      }
      for (double j = 0; j <= 1; j+=0.05)
      {
        file3 << logs[k].get_x1() + a * i / l + b * j << 
          " " << logs[k].get_y1() + b * i / l - a * j << 
          " " << sqrt(logs[k].get_r() * logs[k].get_r() - i * i) + (z2 - z1) * j << "\n";
      }
      for (double d = 1; d >= 0; d -= 0.25) {
        file3 << logs[k].get_x2() + a * i / l << 
          " " << logs[k].get_y2() + b * i / l << 
          " " << (sqrt(logs[k].get_r() * logs[k].get_r() - i * i) + z2) * d << "\n";
      }
      file3 << "\n";
    }
    file3 << "\n";
  }
}

